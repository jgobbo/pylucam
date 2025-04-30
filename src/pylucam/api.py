from cffi import FFI
from pathlib import Path
from enum import IntEnum
from typing import Union, TYPE_CHECKING

if TYPE_CHECKING:
    from .camera import LucamCamera

__all__ = ["LUCAM_API", "LUCAM_LIB", "LUCAM_FFI", "LucamError"]


class API:
    ffi = FFI()

    def __init__(self):
        self.lib = self.ffi.dlopen("lucamapi.dll")
        self.load_header()

    def load_header(self) -> None:
        """
        Parse the modified header file.

        The API normally has nultiple header files which are loaded dynamically. CFFI
        doesn't support the dynamic options, so the files were combined and trimmed.
        """
        header_path = Path(__file__).parent.parent / "lucamapi.h"
        with open(header_path, "r") as f:
            lines = f.readlines()
            for i, line in enumerate(lines):
                if "Function Definitions" in line:
                    function_start = i

            string = "\n".join(lines[:function_start])
            self.ffi.cdef(string)

            for line in lines[function_start:]:
                if "LUCAM_API" in line:
                    line = line[10:].replace("LUCAM_EXPORT", "__stdcall")
                self.ffi.cdef(line)


LUCAM_API = API()
LUCAM_LIB = LUCAM_API.lib
LUCAM_FFI = LUCAM_API.ffi


class LucamError(Exception):
    """
    CODES copied from https://github.com/cgohlke/lucam
    """

    CODES = {
        0: """NoError
            Initialization value in the API.""",
        1: """NoSuchIndex
            The index passed to LucamCameraOpen was 0. It must be >= 1.""",
        2: """SnapshotNotSupported
            The camera does not support snapshots or fast frames.""",
        3: """InvalidPixelFormat
            The pixel format parameter passed to the function is invalid.""",
        4: """SubsamplingZero
            A subsampling of zero was passed to a function.""",
        5: """Busy
            The function is unavailable because the camera is busy with
            streaming or capturing fast frames.""",
        6: """FailedToSetSubsampling
            The API failed to set the requested subsampling. This can be due
            to the camera being disconnected. It can also be due to a filter
            not being there.""",
        7: """FailedToSetStartPosition
            The API failed to set the requested subsampling. This can be due
            to the camera being disconnected.""",
        8: """PixelFormatNotSupported
            The camera does not support the pixel format passed to the
            function.""",
        9: """InvalidFrameFormat
            The format passed to the function does not pass the camera
            requirements. Verify that (xOffset + width) is not greater than
            the camera's maximum width. Verify that (width / subSamplingX)
            is a multiple of some 'nice' value. Do the same for the y.""",
        10: """PreparationFailed
            The API failed to prepare the camera for streaming or snapshot.
            This can due to the camera being disconnected. If START_STREAMING
            succeeds and START_DISPLAY fails with this error, this can be due
            to a filter not being there or registered.""",
        11: """CannotRun
            The API failed to get the camera running. This can be due to
            a bandwidth problem.""",
        12: """NoTriggerControl
            Contact Lumenera.""",
        13: """NoPin
            Contact Lumenera.""",
        14: """NotRunning
            The function failed because it requires the camera to be running,
            and it is not.""",
        15: """TriggerFailed
            Contact Lumenera.""",
        16: """CannotSetupFrameFormat
            The camera does not support that its frame format get setup.
            This will happen if your camera is plugged to a USB 1 port and
            it does not support it. LucamCameraOpen will still succeeds,
            but if a call to LucamGetLastError will return this value.""",
        17: """DirectShowInitError
            Direct Show initialization error. This may happen if you run the
            API before having installed a DS compatible camera ever before.
            The Lumenera camera is DS compatible.""",
        18: """CameraNotFound
            The function LucamCameraOpen did not find the camera # index.""",
        19: """Timeout
            The function timed out.""",
        20: """PropertyUnknown
            The API does not know the property passed to LucamGetProperty,
            LucamSetProperty or LucamGetPropertyRange. You may be using an
            old DLL.""",
        21: """PropertyUnsupported
            The camera does not support that property.""",
        22: """PropertyAccessFailed
            The API failed to access the property. Most likely, the reason
            is that the camera does not support that property.""",
        23: """LucustomNotFound
            The lucustom.ax filter was not found.""",
        24: """PreviewNotRunning
            The function failed because preview is not running.""",
        25: """LutfNotLoaded
            The function failed because lutf.ax is not loaded.""",
        26: """DirectShowError
            An error related to the operation of DirectShow occured.""",
        27: """NoMoreCallbacks
            The function LucamAddStreamingCallback failed because the API
            cannot support any more callbacks.""",
        28: """UndeterminedFrameFormat
            The API does not know what is the frame format of the camera.""",
        29: """InvalidParameter
            An parameter has an obviously wrong value.""",
        30: """NotEnoughResources
            Resource allocation failed.""",
        31: """NoSuchConversion
            One of the members of the LUCAM_CONVERSION structure passed is
            either unknown or inappropriate.""",
        32: """ParameterNotWithinBoundaries
            A parameter representing a quantity is outside the allowed
            boundaries.""",
        33: """BadFileIo
            An error occured creating a file or writing to it. Verify that
            the path exists.""",
        34: """GdiplusNotFound
            gdiplus.dll is needed and was not found.""",
        35: """GdiplusError
            gdiplus.dll reported an error. This may happen if there is a file
            IO error.""",
        36: """UnknownFormatType
            Contact Lumenera.""",
        37: """FailedCreateDisplay
            The API failed to create the display window. The reason could be
            unsufficient resources.""",
        38: """DpLibNotFound
            deltapolation.dll is needed and was not found.""",
        39: """DpCmdNotSupported
            The deltapolation command is not supported by the delta
            polation library.""",
        40: """DpCmdUnknown
            The deltapolation command is unknown or invalid.""",
        41: """NotWhilePaused
            The function cannot be performed when the camera is in
            paused state.""",
        42: """CaptureFailed
            Contact Lumenera.""",
        43: """DpError
            Contact Lumenera.""",
        44: """NoSuchFrameRate
            Contact Lumenera.""",
        45: """InvalidTarget
            One of the target parameters is wrong. This error code is used
            when startX + width > (frameFormat.width / frameFormat.subSampleX)
            or startY + height > (frameFormat.height / frameFormat.subSampleY)
            if any of those parameter is odd (not a multiple of 2) or
            or if width or height is 0.""",
        46: """FrameTooDark
            The frame is too dark to perform white balance.""",
        47: """KsPropertySetNotFound
            A DirectShow interface necessary to carry out the operation
            was not found.""",
        48: """Cancelled
            The user cancelled the operation.""",
        49: """KsControlNotSupported
            The DirectShow IKsControl interface is not supported (did you
            unplug the camera?).""",
        50: """EventNotSupported
            Some module attempted to register an unsupported event.""",
        51: """NoPreview
            The function failed because preview was not setup.""",
        52: """SetPositionFailed
            A function setting window position failed (invalid parameters).""",
        53: """NoFrameRateList
            The frame rate list is not available.""",
        54: """FrameRateInconsistent
            There was an error building the frame rate list.""",
        55: """CameraNotConfiguredForCmd
            The camera does not support that particular command.""",
        56: """GraphNotReady
            The graph is not ready.""",
        57: """CallbackSetupError
            Contact Lumenera.""",
        58: """InvalidTriggerMode
            You cannot cause a soft trigger when hw trigger is enabled.""",
        59: """NotFound
            The API was asked to return soomething that is not there.""",
        60: """EepromTooSmall
            The onboard EEPROM is too small.""",
        61: """EepromWriteFailed
            The API failed to write to the onboard eeprom.""",
        62: """UnknownFileType
            The API failed because it failed to recognize the file type of
            a file name passed to it.""",
        63: """EventIdNotSupported
            LucamRegisterEventNotification failed because the event
            is not supported.""",
        64: """EepromCorrupted
            The API found that the EEPROM was corrupted.""",
        65: """SectionTooBig
            The VPD section to write to the eeprom is too big.""",
        66: """FrameTooBright
            The frame is too bright to perform white balance.""",
        67: """NoCorrectionMatrix
            The camera is configured to have no correction matrix
            (PROPERTY_CORRECTION_MATRIX is LUCAM_CM_NONE).""",
        68: """UnknownCameraModel
            The API failed because it needs to know the camera model and it
            is not available.""",
        69: """ApiTooOld
            The API failed because it needs to be upgraded to access a
            feature of the camera.""",
        70: """SaturationZero
            The API failed because the saturation is currently 0.""",
        71: """AlreadyInitialised
            The API failed because the object was already initialised.""",
        72: """SameInputAndOutputFile
            The API failed because the object was already initialised.""",
        73: """FileConversionFailed
            The API failed because the file conversion was not completed.""",
        74: """FileAlreadyConverted
            The API failed because the file is already converted in the
            desired format.""",
        75: """PropertyPageNotSupported
            The API failed to display the property page.""",
        76: """PropertyPageCreationFailed
            The API failed to create the property page.""",
        77: """DirectShowFilterNotInstalled
            The API did not find the required direct show filter.""",
        78: """IndividualLutNotAvailable
            The camera does not support that different LUTs are applied
            to each color.""",
        79: """UnexpectedError
            Contact Lumenera.""",
        80: """StreamingStopped
            LucamTakeFastFrame or LucamTakeVideo failed because another thread
            interrupted the streaming by a call to LucamDisableFastFrames or
            LucamStreamVideoControl.""",
        81: """MustBeInSwTriggerMode
            LucamForceTakeFastFrame was called while the camera is in hardware
            trigger still mode and the camera does not support taking a sw
            trigger snapshot while in that state.""",
        82: """TargetFlaky
            The target is too flaky to perform auto focus.""",
        83: """AutoLensUninitialized
            The auto lens needs to be initialized before the function
            is used.""",
        84: """LensNotInstalled
            The function failed because the lens were not installed correctly.
            Verify that changing the focus has any effect.""",
        85: """UnknownError
            The function failed because of an unknoen error.
            Contact Lumenera.""",
        86: """FocusNoFeedbackError
            There is no feedback available for focus.""",
        87: """LutfTooOld
            LuTF.ax is too old for this feature.""",
        88: """UnknownAviFormat
            Unknown or invalid AVI format for input file.""",
        89: """UnknownAviType
            Unknown AVI type. Verify the AVI type parameter.""",
        90: """InvalidAviConversion
            The AVI conversion is invalid.""",
        91: """SeekFailed
            The seeking operation failed.""",
        92: """AviRunning
            The function cannot be performed while an AVI is being
            captured.""",
        93: """CameraAlreadyOpened
            An attempt was made to open a camera for streaming-related
            reasons while it is already opened for such.""",
        94: """NoSubsampledHighRes
            The API cannot take a high resolution image in subsampled mode
            or binning mode.""",
        95: """OnlyOnMonochrome
            The API function is only available on monochrome cameras.""",
        96: """No8bppTo48bpp
            Building a 48 bpp image from an 8 bpp image is invalid.""",
        97: """Lut8Obsolete
            Use 12 bits LUT instead.""",
        98: """FunctionNotSupported
            That functionnality is not supported.""",
        99: """RetryLimitReached
            Property access failed due to a retry limit.""",
    }

    def __init__(self, arg: Union["LucamCamera", int, None] = None):
        if arg is None:
            self.value = LUCAM_LIB.LucamGetLastError()
        elif isinstance(arg, int):
            self.value = arg
        else:
            self.value = arg.get_last_error()

    def __str__(self):
        return self.CODES[self.value]


class LucamErrorCode(IntEnum):
    NoError = 0
    NoSuchIndex = 1
    SnapshotNotSupported = 2
    InvalidPixelFormat = 3
    SubsamplingZero = 4
    Busy = 5
    FailedToSetSubsampling = 6
    FailedToSetStartPosition = 7
    PixelFormatNotSupported = 8
    InvalidFrameFormat = 9
    PreparationFailed = 10
    CannotRun = 11
    NoTriggerControl = 12
    NoPin = 13
    NotRunning = 14
    TriggerFailed = 15
    CannotSetupFrameFormat = 16
    DirectShowInitError = 17
    CameraNotFound = 18
    Timeout = 19
    PropertyUnknown = 20
    PropertyUnsupported = 21
    PropertyAccessFailed = 22
    LucustomNotFound = 23
    PreviewNotRunning = 24
    LutfNotLoaded = 25
    DirectShowError = 26
    NoMoreCallbacks = 27
    UndeterminedFrameFormat = 28
    InvalidParameter = 29
    NotEnoughResources = 30
    NoSuchConversion = 31
    ParameterNotWithinBoundaries = 32
    BadFileIo = 33
    GdiplusNotFound = 34
    GdiplusError = 35
    UnknownFormatType = 36
    FailedCreateDisplay = 37
    DpLibNotFound = 38
    DpCmdNotSupported = 39
    DpCmdUnknown = 40
    NotWhilePaused = 41
    CaptureFailed = 42
    DpError = 43
    NoSuchFrameRate = 44
    InvalidTarget = 45
    FrameTooDark = 46
    KsPropertySetNotFound = 47
    Cancelled = 48
    KsControlNotSupported = 49
    EventNotSupported = 50
    NoPreview = 51
    SetPositionFailed = 52
    NoFrameRateList = 53
    FrameRateInconsistent = 54
    CameraNotConfiguredForCmd = 55
    GraphNotReady = 56
    CallbackSetupError = 57
    InvalidTriggerMode = 58
    NotFound = 59
    EepromTooSmall = 60
    EepromWriteFailed = 61
    UnknownFileType = 62
    EventIdNotSupported = 63
    EepromCorrupted = 64
    SectionTooBig = 65
    FrameTooBright = 66
    NoCorrectionMatrix = 67
    UnknownCameraModel = 68
    ApiTooOld = 69
    SaturationZero = 70
    AlreadyInitialised = 71
    SameInputAndOutputFile = 72
    FileConversionFailed = 73
    FileAlreadyConverted = 74
    PropertyPageNotSupported = 75
    PropertyPageCreationFailed = 76
    DirectShowFilterNotInstalled = 77
    IndividualLutNotAvailable = 78
    UnexpectedError = 79
    StreamingStopped = 80
    MustBeInSwTriggerMode = 81
    TargetFlaky = 82
    AutoLensUninitialized = 83
    LensNotInstalled = 84
    UnknownError = 85
    FocusNoFeedbackError = 86
    LutfTooOld = 87
    UnknownAviFormat = 88
    UnknownAviType = 89
    InvalidAviConversion = 90
    SeekFailed = 91
    AviRunning = 92
    CameraAlreadyOpened = 93
    NoSubsampledHighRes = 94
    OnlyOnMonochrome = 95
    No8bppTo48bpp = 96
    Lut8Obsolete = 97
    FunctionNotSupported = 98
    RetryLimitReached = 99
