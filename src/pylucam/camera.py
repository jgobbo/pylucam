import re
from enum import IntEnum
from dataclasses import dataclass
from logging import warning

import numpy as np
from cv2 import (
    cvtColor,
    COLOR_BAYER_RGGB2RGB,
    COLOR_BAYER_GRBG2RGB,
    COLOR_BAYER_GBRG2RGB,
    COLOR_BAYER_BGGR2RGB,
)

from .api import LUCAM_FFI, LUCAM_LIB, LucamError, LucamErrorCode

__all__ = ["LucamCamera", "LucamProperty"]


class LucamProperty(IntEnum):
    gain = LUCAM_LIB.LUCAM_PROP_GAIN
    gain_red = LUCAM_LIB.LUCAM_PROP_GAIN_RED
    gain_blue = LUCAM_LIB.LUCAM_PROP_GAIN_BLUE
    gain_green1 = LUCAM_LIB.LUCAM_PROP_GAIN_GREEN1
    gain_green2 = LUCAM_LIB.LUCAM_PROP_GAIN_GREEN2

    color_format = LUCAM_LIB.LUCAM_PROP_COLOR_FORMAT


class ColorFormat(IntEnum):
    MONO = LUCAM_LIB.LUCAM_CF_MONO
    RGGB = LUCAM_LIB.LUCAM_CF_BAYER_RGGB
    GRBG = LUCAM_LIB.LUCAM_CF_BAYER_GRBG
    GBRG = LUCAM_LIB.LUCAM_CF_BAYER_GBRG
    BGGR = LUCAM_LIB.LUCAM_CF_BAYER_BGGR


@dataclass
class Format:
    xOffset: int
    yOffset: int
    width: int
    height: int
    pixelFormat: int
    subSampleX: int
    binningX: int
    flagsX: int
    subSampleY: int
    binningY: int
    flagsY: int

    @classmethod
    def from_lucam(cls, lucam_frame_format):
        kwargs = {}
        for attr in cls.__annotations__:
            kwargs[attr] = getattr(lucam_frame_format, attr)

        return cls(**kwargs)

    def as_lucam(self):
        """Create and populate a LUCAM_FRAME_FORMAT from self"""
        lucam_frame_format = LUCAM_FFI.new("LUCAM_FRAME_FORMAT *")

        for attr in self.__annotations__:
            setattr(lucam_frame_format, attr, getattr(self, attr))

        return lucam_frame_format


@dataclass
class Snapshot:
    exposure: float
    gain: float
    gainRed: float
    gainBlue: float
    gainGrn1: float
    gainGrn2: float
    timeout: float
    format: Format

    @classmethod
    def from_lucam(cls, lucam_snapshot):
        kwargs = {}
        for attr in cls.__annotations__:
            value = getattr(lucam_snapshot, attr)
            if attr == "format":
                value = Format.from_lucam(value)
            kwargs[attr] = value
        return cls(**kwargs)

    def as_lucam(self):
        """Create and populate a LUCAM_SNAPSHOT from self"""
        lucam_snapshot = LUCAM_FFI.new("LUCAM_SNAPSHOT *")
        for attr in self.__annotations__:
            value = getattr(self, attr)
            if attr == "format":
                value: Format
                value = value.as_lucam()[0]
            setattr(lucam_snapshot, attr, value)

        return lucam_snapshot


class LucamCamera:
    format: Format
    snapshot: Snapshot

    framerate: float = 30
    fast_frames_enabled: bool = False

    lib = LUCAM_LIB
    ffi = LUCAM_FFI

    def __init__(self, number: int = 1):
        self._handle = self.lib.LucamCameraOpen(number)
        if self._handle == self.ffi.NULL:
            raise ConnectionError(f"Lucam camera number {number} failed to open.")

        self.get_format()
        self.get_default_snapshot()

        color_format = self.get_property(LucamProperty.color_format)
        self.color_conversion_code = {
            ColorFormat.MONO: None,
            ColorFormat.RGGB: COLOR_BAYER_RGGB2RGB,
            ColorFormat.GRBG: COLOR_BAYER_GRBG2RGB,
            ColorFormat.GBRG: COLOR_BAYER_GBRG2RGB,
            ColorFormat.BGGR: COLOR_BAYER_BGGR2RGB,
        }[color_format]

    def __del__(self):
        self.lib.LucamCameraClose(self._handle)

    def get_last_error(self):
        return self.lib.LucamGetLastErrorForCamera(self._handle)

    def _property_value(self, property: LucamProperty | int | str) -> int:
        """
        Generate the corresponding integer for the provided Lucam property.

        If a string is provided, it must match the name of a property following
        `LUCAM_PROP_` but isn't case sensitive.
        """
        if isinstance(property, str):
            if "_" not in property:
                property = "_".join(re.sub(r"([A-Z])", r" \1", property).split())
            property = getattr(self.lib, f"LUCAM_PROP_{property.upper()}")
        assert isinstance(property, int)

        return property

    def get_property(self, property: LucamProperty | int | str) -> float:
        value = self.ffi.new("FLOAT *")
        flags = self.ffi.new("LONG *")

        if not self.lib.LucamGetProperty(
            self._handle, self._property_value(property), value, flags
        ):
            raise LucamError(self)
        return value[0]

    def set_property(self, property: LucamProperty | int | str, value: float) -> None:
        if not self.lib.LucamSetProperty(
            self._handle, self._property_value(property), value, 0x0
        ):
            raise LucamError(self)

    def get_format(self) -> Format:
        lucam_format = self.ffi.new("LUCAM_FRAME_FORMAT *")
        framerate = self.ffi.new("FLOAT *")

        if not self.lib.LucamGetFormat(self._handle, lucam_format, framerate):
            raise LucamError(self)

        format = Format.from_lucam(lucam_format)
        self.format = format
        self.framerate = framerate[0]
        self.width = format.width
        self.height = format.height
        return format

    def get_default_snapshot(self) -> Snapshot:
        kwargs = {}
        for property in Snapshot.__annotations__:
            if property == "format":
                value = self.get_format()
            elif property == "timeout":
                value = 150
            elif "Grn" in property:
                value = self.get_property(property.replace("Grn", "Green"))
            else:
                value = self.get_property(property)

            kwargs[property] = value
        self.snapshot = Snapshot(**kwargs)
        return self.snapshot

    def enable_fast_frames(self, snapshot: Snapshot = None) -> None:
        snapshot = self.snapshot if snapshot is None else snapshot
        if not self.lib.LucamEnableFastFrames(self._handle, snapshot.as_lucam()):
            raise LucamError(self)
        self.fast_frames_enabled = True

    def disable_fast_frames(self) -> None:
        if not self.lib.LucamDisableFastFrames(self._handle):
            raise LucamError(self)
        self.fast_frames_enabled = False

    def reset_fast_frames(self) -> None:
        """Disable and re-enable fast frames to reset the active snapshot."""
        self.disable_fast_frames()
        self.enable_fast_frames()

    def take_fast_frame(self) -> np.ndarray:
        frame = np.ndarray((self.height, self.width), dtype=np.uint8)
        frame = np.ascontiguousarray(frame)
        if not self.lib.LucamTakeFastFrame(self._handle, self.ffi.from_buffer(frame)):
            raise LucamError(self)
        return frame

    def convert_frame_to_rgb(self, frame: np.ndarray) -> np.ndarray:
        """
        Use opencv to demosaic the Bayer filtered frame.

        I couldn't get the api `ConvertFrameToRgb24` to work.
        """
        return cvtColor(frame, self.color_conversion_code)

    def take_fast_frame_rgb(self) -> np.ndarray:
        return self.convert_frame_to_rgb(self.take_fast_frame())

    def white_balance(
        self,
        start_x: int = 0,
        start_y: int = 0,
        width: int = None,
        height: int = None,
        red_over_green: float = 1.0,
        blue_over_green: float = 1.0,
    ) -> None:
        width = self.width if width is None else width
        height = self.height if height is None else height

        snapshot = self.snapshot.as_lucam()
        frame = self.take_fast_frame()
        if not self.lib.LucamAdjustWhiteBalanceFromSnapshot(
            self._handle,
            snapshot,
            self.ffi.from_buffer(frame),
            red_over_green,
            blue_over_green,
            start_x,
            start_y,
            width,
            height,
        ):
            error_code = self.get_last_error()
            if error_code == LucamErrorCode.FrameTooDark:
                warning("Whitebalance failed because the image is too dark.")
            elif error_code == LucamErrorCode.FrameTooBright:
                warning("Whitebalance failed because the image is too bright")
            else:
                raise LucamError(error_code)
        else:
            self.snapshot = Snapshot.from_lucam(snapshot)

    def camera_close(self):
        if not self.lib.LucamCameraClose(self._handle):
            raise LucamError(self)
