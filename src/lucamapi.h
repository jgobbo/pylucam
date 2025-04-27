#define TRUE    1
#define FALSE   0

//****************************************************************************************************************
//  Type Definitions
//****************************************************************************************************************

typedef uint8_t         BYTE;
typedef char            CHAR;
typedef unsigned char   UCHAR;
typedef wchar_t         WCHAR;
typedef int16_t         SHORT;
typedef uint16_t        USHORT;
typedef uint16_t        WORD;
typedef uint32_t        DWORD;
typedef int32_t         INT;
typedef BOOL            BOOLEAN;
typedef int64_t         LONGLONG;
typedef uint64_t        ULONGLONG;

typedef float           FLOAT;
typedef void            VOID, *PVOID;
typedef void*           HANDLE;
typedef void*           HWND;
typedef void*           HMENU;
typedef const char*     LPCSTR;
typedef const wchar_t*  LPCWSTR;
//****************************************************************************************************************

//****************************************************************************************************************
//  Properties
//****************************************************************************************************************
#define LUCAM_PROP_BRIGHTNESS                                       0
#define LUCAM_PROP_CONTRAST                                         1
#define LUCAM_PROP_HUE                                              2
#define LUCAM_PROP_SATURATION                                       3
#define LUCAM_PROP_GAMMA                                            5
#define LUCAM_PROP_EXPOSURE                                         20
#define LUCAM_PROP_IRIS                                             21
#define LUCAM_PROP_FOCUS                                            22
#define LUCAM_PROP_GAIN                                             40
#define LUCAM_PROP_GAIN_RED                                         41
#define LUCAM_PROP_GAIN_BLUE                                        42
#define LUCAM_PROP_GAIN_GREEN1                                      43
#define LUCAM_PROP_GAIN_GREEN2                                      44

// PROP_STILL_*
#define LUCAM_PROP_STILL_EXPOSURE                                   50
#define LUCAM_PROP_STILL_GAIN                                       51
#define LUCAM_PROP_STILL_GAIN_RED                                   52
#define LUCAM_PROP_STILL_GAIN_GREEN1                                53
#define LUCAM_PROP_STILL_GAIN_GREEN2                                54
#define LUCAM_PROP_STILL_GAIN_BLUE                                  55
#define LUCAM_PROP_STILL_STROBE_DELAY                               56

#define LUCAM_PROP_DEMOSAICING_METHOD                               64
#define LUCAM_PROP_CORRECTION_MATRIX                                65
#define LUCAM_PROP_FLIPPING                                         66

// all PROP_DIGITAL_*
#define LUCAM_PROP_DIGITAL_SATURATION                               67 // factor of 1.0
#define LUCAM_PROP_DIGITAL_HUE                                      68 // from -180 to +180
#define LUCAM_PROP_DIGITAL_WHITEBALANCE_U                           69 // from -100 to 100
#define LUCAM_PROP_DIGITAL_WHITEBALANCE_V                           70 // from -100 to 100
#define LUCAM_PROP_DIGITAL_GAIN                                     71 // from 0 to 2, 1 means a gain of 1.0
#define LUCAM_PROP_DIGITAL_GAIN_RED                                 72 // from 0 to 2.5, 1 means a gain of 1.0. Relates to GAIN_Y and WHITEBALANCE. SATURATION must not be low.
#define LUCAM_PROP_DIGITAL_GAIN_GREEN                               73 // from 0 to 2.5, 1 means a gain of 1.0. Relates to GAIN_Y and WHITEBALANCE. SATURATION must not be low.
#define LUCAM_PROP_DIGITAL_GAIN_BLUE                                74 // from 0 to 2.5, 1 means a gain of 1.0. Relates to GAIN_Y and WHITEBALANCE. SATURATION must not be low.
#define LUCAM_PROP_COLOR_FORMAT                                     80 // Read-only
#define LUCAM_PROP_MAX_WIDTH                                        81 // Read-only
#define LUCAM_PROP_MAX_HEIGHT                                       82 // Read-only
#define LUCAM_PROP_UNIT_WIDTH                                       83 // Read-only
#define LUCAM_PROP_UNIT_HEIGHT                                      84 // Read-only
#define LUCAM_PROP_ABS_FOCUS                                        85 // Requires the auto lens to be initialized
#define LUCAM_PROP_BLACK_LEVEL                                      86
#define LUCAM_PROP_KNEE1_EXPOSURE                                   96
#define LUCAM_PROP_STILL_KNEE1_EXPOSURE                             96
#define LUCAM_PROP_KNEE2_EXPOSURE                                   97
#define LUCAM_PROP_STILL_KNEE2_EXPOSURE                             97
#define LUCAM_PROP_STILL_KNEE3_EXPOSURE                             98
#define LUCAM_PROP_VIDEO_KNEE                                       99
#define LUCAM_PROP_KNEE1_LEVEL                                      99
#define LUCAM_PROP_STILL_EXPOSURE_DELAY                             100
#define LUCAM_PROP_THRESHOLD                                        101
#define LUCAM_PROP_AUTO_EXP_TARGET                                  103
#define LUCAM_PROP_TIMESTAMPS                                       105
#define LUCAM_PROP_SNAPSHOT_CLOCK_SPEED                             106 // 0 is the fastest
#define LUCAM_PROP_AUTO_EXP_MAXIMUM                                 107
#define LUCAM_PROP_TEMPERATURE                                      108
#define LUCAM_PROP_TRIGGER                                          110
#define LUCAM_PROP_TRIGGER_PIN                                      110 // Alias
#define LUCAM_PROP_EXPOSURE_INTERVAL                                113
#define LUCAM_PROP_STILL_STROBE_DURATION                            116
#define LUCAM_PROP_SNAPSHOT_COUNT                                   120
#define LUCAM_PROP_AUTO_IRIS_MAX                                    123 // N/A for linux
#define LUCAM_PROP_VIDEO_CLOCK_SPEED                                126 // 0 is the fastest. Check for read-only flag
#define LUCAM_PROP_KNEE2_LEVEL                                      163
#define LUCAM_PROP_STROBE_PIN                                       172
#define LUCAM_PROP_TAP_CONFIGURATION                                176
#define LUCAM_PROP_STILL_TAP_CONFIGURATION                          177
#define LUCAM_PROP_JPEG_QUALITY                                     256 // N/A for linux
//****************************************************************************************************************

//****************************************************************************************************************
//  Property Flags
//****************************************************************************************************************
#define LUCAM_PROP_FLAG_USE                                         0x80000000
#define LUCAM_PROP_FLAG_AUTO                                        0x40000000
#define LUCAM_PROP_FLAG_STROBE_FROM_START_OF_EXPOSURE               0x20000000
#define LUCAM_PROP_FLAG_POLARITY                                    0x10000000
#define LUCAM_PROP_FLAG_BUSY                                        0x00100000
#define LUCAM_PROP_FLAG_ALTERNATE                                   0x00080000
#define LUCAM_PROP_FLAG_UNKNOWN_MAXIMUM                             0x00020000
#define LUCAM_PROP_FLAG_UNKNOWN_MINIMUM                             0x00010000
//****************************************************************************************************************

//****************************************************************************************************************
//  Property-Specific Flags
//****************************************************************************************************************
#define LUCAM_PROP_FLAG_LITTLE_ENDIAN                               0x80000000 // for LUCAM_PROP_COLOR_FORMAT
#define LUCAM_PROP_FLAG_MASTER                                      0x40000000 // for LUCAM_PROP_SYNC_MODE
#define LUCAM_PROP_FLAG_BACKLASH_COMPENSATION                       0x20000000 // for LUCAM_PROP_IRIS and LUCAM_PROP_FOCUS
#define LUCAM_PROP_FLAG_MEMORY_READBACK                             0x08000000 // for LUCAM_PROP_MEMORY
#define LUCAM_PROP_FLAG_USE_FOR_SNAPSHOTS                           0x04000000 // for LUCAM_PROP_IRIS
#define LUCAM_PROP_FLAG_READONLY                                    0x00010000 // for flags param of GetPropertyRange
//****************************************************************************************************************

//****************************************************************************************************************
//  Camera-Specific Flags
//****************************************************************************************************************
// These flags can be used with  LUCAM_PROP_GAMMA, LUCAM_PROP_BRIGHTNESS, and LUCAM_PROP_CONTRAST
// They are available on specific cameras only.
#define LUCAM_PROP_FLAG_RED                                         0x00000001
#define LUCAM_PROP_FLAG_GREEN1                                      0x00000002
#define LUCAM_PROP_FLAG_GREEN2                                      0x00000004
#define LUCAM_PROP_FLAG_BLUE                                        0x00000008
//****************************************************************************************************************

//****************************************************************************************************************
//  Pixel Formats
//****************************************************************************************************************
#define LUCAM_PF_8                                                  0
#define LUCAM_PF_16                                                 1
#define LUCAM_PF_24                                                 2
#define LUCAM_PF_32                                                 6
#define LUCAM_PF_48                                                 7
#define LUCAM_PF_COUNT                                              4
#define LUCAM_PF_FILTER                                             5
#define LUCAM_PF_12_PACKED                                          12
//****************************************************************************************************************

//****************************************************************************************************************
//  Color Patterns
//****************************************************************************************************************
// For the LUCAM_PROP_COLOR_FORMAT property
#define LUCAM_CF_MONO                                               0
#define LUCAM_CF_BAYER_RGGB                                         8
#define LUCAM_CF_BAYER_GRBG                                         9
#define LUCAM_CF_BAYER_GBRG                                         10
#define LUCAM_CF_BAYER_BGGR                                         11
//****************************************************************************************************************

//****************************************************************************************************************
//  Flipping Directions
//****************************************************************************************************************
// For the LUCAM_PROP_FLIPPING property
#define LUCAM_PROP_FLIPPING_NONE                                    0
#define LUCAM_PROP_FLIPPING_X                                       1
#define LUCAM_PROP_FLIPPING_Y                                       2
#define LUCAM_PROP_FLIPPING_XY                                      3
//****************************************************************************************************************

//****************************************************************************************************************
//  Tap Configurations
//****************************************************************************************************************
// For LUCAM_PROP_TAP_CONFIGURATION and LUCAM_PROP_STILL_TAP_CONFIGURATION
#define TAP_CONFIGURATION_1X1                                       0
#define TAP_CONFIGURATION_2X1                                       1
#define TAP_CONFIGURATION_1X2                                       2
#define TAP_CONFIGURATION_2X2                                       4
#define TAP_CONFIGURATION_SINGLE                                    0
#define TAP_CONFIGURATION_DUAL                                      1
#define TAP_CONFIGURATION_QUAD                                      4
//****************************************************************************************************************

//****************************************************************************************************************
//  Video Streaming Modes
//****************************************************************************************************************
#define STOP_STREAMING                                              0
#define START_STREAMING                                             1
#define START_DISPLAY                                               2
#define PAUSE_STREAM                                                3
#define START_RGBSTREAM                                             6
//****************************************************************************************************************

//****************************************************************************************************************
//  Demosaicing Methods
//****************************************************************************************************************
#define LUCAM_DM_NONE                                               0
#define LUCAM_DM_FAST                                               1
#define LUCAM_DM_HIGH_QUALITY                                       2
#define LUCAM_DM_HIGHER_QUALITY                                     3
#define LUCAM_DM_SIMPLE                                             8
//****************************************************************************************************************

//****************************************************************************************************************
//  Color Correction Matrices
//****************************************************************************************************************
#define LUCAM_CM_NONE                                               0
#define LUCAM_CM_FLUORESCENT                                        1
#define LUCAM_CM_DAYLIGHT                                           2
#define LUCAM_CM_INCANDESCENT                                       3
#define LUCAM_CM_XENON_FLASH                                        4
#define LUCAM_CM_HALOGEN                                            5
#define LUCAM_CM_LED                                                6
#define LUCAM_CM_DAYLIGHT_H_AND_E                                   7
#define LUCAM_CM_LED_H_AND_E                                        8
#define LUCAM_CM_IDENTITY                                           14
#define LUCAM_CM_CUSTOM                                             15
//****************************************************************************************************************

//****************************************************************************************************************
//  Shutter Types
//****************************************************************************************************************
#define LUCAM_SHUTTER_TYPE_GLOBAL                                   0
#define LUCAM_SHUTTER_TYPE_ROLLING                                  1
//****************************************************************************************************************

//****************************************************************************************************************
//  External Interfaces
//****************************************************************************************************************
// See QueryExternInterface, and SelectExternInterface
#define LUCAM_EXTERN_INTERFACE_USB1                                 1
#define LUCAM_EXTERN_INTERFACE_USB2                                 2
#define LUCAM_EXTERN_INTERFACE_USB3                                 3
#define LUCAM_EXTERN_INTERFACE_GIGEVISION                           4
//****************************************************************************************************************

//****************************************************************************************************************
//  Frame Format Flag(s)
//****************************************************************************************************************
#define LUCAM_FRAME_FORMAT_FLAGS_BINNING                            0x0001

//****************************************************************************************************************
//  Device Notifications
//****************************************************************************************************************
// For use with LucamRegisterEventNotification via callbacks
#define LUCAM_EVENT_START_OF_READOUT                                2
#define LUCAM_EVENT_DEVICE_SURPRISE_REMOVAL                         32
//****************************************************************************************************************


//****************************************************************************************************************
//  Image Formats
//****************************************************************************************************************
// The RGB format for images produced by functions such as
// AddRgbPreviewCallback and ConvertFrameToRgb24
#define LUCAM_RGB_FORMAT_RGB                                        0    // Standard R,G,B
#define LUCAM_RGB_FORMAT_BMP                                        1    // B,G,R, row-inverted, in the format of a Windows BMP.
//****************************************************************************************************************
#define LUCAM_PROP_LSC_X                                            121
#define LUCAM_PROP_LSC_Y                                            122

#define LUCAM_PROP_AUTO_GAIN_MAXIMUM                                170

#define LUCAM_PROP_TRIGGER_MODE                                     173 // See TRIGGER_MODE_* below
#define LUCAM_PROP_FOCAL_LENGTH                                     174
#define LUCAM_PROP_MAX_FRAME_RATE                                   184
#define LUCAM_PROP_AUTO_GAIN_MINIMUM                                186

#define LUCAM_PROP_IRIS_STEPS_COUNT                                 188
#define LUCAM_PROP_GAINHDR                                          189
#define LUCAM_PROP_STILL_GAINHDR                                    190
//****************************************************************************************************************


//****************************************************************************************************************
//  Property Flags
//****************************************************************************************************************
#define LUCAM_PROP_FLAG_SEQUENCABLE                                 0x08000000
//****************************************************************************************************************







//****************************************************************************************************************
//  Trigger Modes
//****************************************************************************************************************
// For the LUCAM_PROP_TRIGGER_MODE property.
#define TRIGGER_MODE_NORMAL                                         0
#define TRIGGER_MODE_BULB                                           1
//****************************************************************************************************************




//****************************************************************************************************************
//  Metadata Flags
//****************************************************************************************************************
// For use with LucamGetMetadata
// Metadata that may be embedded within an image.
// Capabilities vary from model to model.
#define LUCAM_METADATA_FRAME_COUNTER                                1
#define LUCAM_METADATA_TIMESTAMP                                    2
//****************************************************************************************************************

//****************************************************************************************************************
//  HDR Modes
//****************************************************************************************************************
#define HDR_DISABLED                                                0
#define HDR_ENABLED_PRIMARY_IMAGE                                   1
#define HDR_ENABLED_SECONDARY_IMAGE                                 2
#define HDR_ENABLED_MERGED_IMAGE                                    3
#define HDR_ENABLED_AVERAGED_IMAGE                                  4 // not supported
#define HDR_PIECEWISE_LINEAR_RESPONSE                               5
//****************************************************************************************************************

#define LUCAM_API_RGB24_FORMAT                                      1
#define LUCAM_API_RGB32_FORMAT                                      1
#define LUCAM_API_RGB48_FORMAT                                      1
//****************************************************************************************************************

//****************************************************************************************************************

//****************************************************************************************************************
//  Algorithms
//****************************************************************************************************************
// For LUCAM_PROP_HOST_AUTO_WB_ALGORITHM and LUCAM_PROP_HOST_AUTO_EX_ALGORITHM
#define AUTO_ALGORITHM_SIMPLE_AVERAGING                             0
#define AUTO_ALGORITHM_HISTOGRAM                                    1
#define AUTO_ALGORITHM_MACROBLOCKS                                  2
//****************************************************************************************************************

//****************************************************************************************************************
//  AVI Streaming Modes
//****************************************************************************************************************
#define STOP_AVI                                                    0
#define START_AVI                                                   1
#define PAUSE_AVI                                                   2
//****************************************************************************************************************

//****************************************************************************************************************
//  AVI Types
//****************************************************************************************************************
#define AVI_RAW_LUMENERA                                            0
#define AVI_STANDARD_24                                             1
#define AVI_STANDARD_32                                             2
#define AVI_XVID_24                                                 3
#define AVI_STANDARD_8                                              4 // For monochrome only
//****************************************************************************************************************

//****************************************************************************************************************
//  Device Notifications - for Lgcam only
//****************************************************************************************************************
// For use with LucamRegisterEventNotification via callbacks
#define LUCAM_EVENT_GPI1_CHANGED                                    4
#define LUCAM_EVENT_GPI2_CHANGED                                    5
#define LUCAM_EVENT_GPI3_CHANGED                                    6
#define LUCAM_EVENT_GPI4_CHANGED                                    7
//****************************************************************************************************************

//****************************************************************************************************************
//  Property-Specific Flags
//****************************************************************************************************************
#define LUCAM_PROP_FLAG_HW_ENABLE                                   0x40000000 // for VIDEO_TRIGGER (also uses LUCAM_PROP_FLAG_USE)
#define LUCAM_PROP_FLAG_SW_TRIGGER                                  0x00200000 // for VIDEO_TRIGGER (also uses LUCAM_PROP_FLAG_USE) // Self-cleared
//****************************************************************************************************************

//****************************************************************************************************************
//  Pixel Formats
//****************************************************************************************************************
#define LUCAM_PF_YUV422                                             3
//****************************************************************************************************************

//****************************************************************************************************************
//  Color Patterns
//****************************************************************************************************************
// For the LUCAM_PROP_COLOR_FORMAT property
#define LUCAM_CF_BAYER_CYYM                                         16
#define LUCAM_CF_BAYER_YCMY                                         17
#define LUCAM_CF_BAYER_YMCY                                         18
#define LUCAM_CF_BAYER_MYYC                                         19
//****************************************************************************************************************

//****************************************************************************************************************
//  Color Correction Matrices
//****************************************************************************************************************
#define LUCAM_CM_LED                                                6
//****************************************************************************************************************

//****************************************************************************************************************
//  Structures
//****************************************************************************************************************
//****************************************************************************************************************

// Version Information
//----------------------------------------------------------------------------------------------------------------
// Version Information: Camera and Host
// For use with QueryVersion and EnumCameras
typedef struct LUCAM_VERSION {
    ULONG firmware;     // Camera firmware version.      Not available with LucamEnumCameras
    ULONG fpga;         // Camera FPGA version.          Not available with LucamEnumCameras
    ULONG api;          // API version (lucamapi.dll, lucamapi.so.*)
    ULONG driver;       // Device driver version.        Not available with LucamEnumCameras
    ULONG serialnumber; // Unique serial number of a camera.
    ULONG cameraid;     // Also known as camera model id.
} LUCAM_VERSION;
//----------------------------------------------------------------------------------------------------------------

// Frame Format
//----------------------------------------------------------------------------------------------------------------
typedef struct LUCAM_FRAME_FORMAT {
    ULONG xOffset;         // X coordinate on imager of top left corner of subwindow, in pixels
    ULONG yOffset;         // Y coordinate on imager of top left corner of subwindow, in pixels
    ULONG width;           // Width  of subwindow, in pixels
    ULONG height;          // Height of subwindow, in pixls
    ULONG pixelFormat;     // Pixel format LUCAM_PF
    union {
        USHORT subSampleX; // Sub-sample ratio in x direction, in pixels (x:1)
        USHORT binningX;   // Binning ratio in x direction, in pixels (x:1
    };
    USHORT flagsX;         // LUCAM_FRAME_FORMAT_FLAGS_*
    union {
        USHORT subSampleY; // Sub-sample ratio in y direction, in pixels (y:1)
        USHORT binningY;   // Binning ratio in y direction, in pixels (y:1)
    };
    USHORT flagsY;         // LUCAM_FRAME_FORMAT_FLAGS_*
} LUCAM_FRAME_FORMAT;
//----------------------------------------------------------------------------------------------------------------

// Snapshot Settings
//----------------------------------------------------------------------------------------------------------------
// See TakeSnapshot, EnableFastFrames, and EnableSynchronousSnapshots.
typedef struct LUCAM_SNAPSHOT {
    FLOAT exposure;            // Exposure in milliseconds
    FLOAT gain;                // Overall gain as a multiplicative factor
    union {
        struct {
            FLOAT gainRed;     // Gain for Red pixels as multiplicative factor
            FLOAT gainBlue;    // Gain for Blue pixels as multiplicative factor
            FLOAT gainGrn1;    // Gain for Green pixels on Red rows as multiplicative factor
            FLOAT gainGrn2;    // Gain for Green pixels on Blue rows as multiplicative factor
         };
         struct {
             FLOAT gainMag;    // Gain for Magenta pixels as multiplicative factor
             FLOAT gainCyan;   // Gain for Cyan pixels as multiplicative factor
             FLOAT gainYel1;   // Gain for Yellow pixels on Magenta rows as multiplicative factor
             FLOAT gainYel2;   // Gain for Yellow pixels on Cyan rows as multiplicative factor
         };
    };
    union {
        BOOL  useStrobe;       // For backward compatibility
        ULONG strobeFlags;     // Use LUCAM_PROP_FLAG_USE and/or LUCAM_PROP_FLAG_STROBE_FROM_START_OF_EXPOSURE
    };
    FLOAT strobeDelay;         // Time interval from when exposure starts to time the flash is fired in milliseconds
    BOOL  useHwTrigger;        // Wait for hardware trigger
    FLOAT timeout;             // Maximum time to wait for hardware trigger prior to returning from function in milliseconds
    LUCAM_FRAME_FORMAT format; // Frame format for data
    ULONG shutterType;
    FLOAT exposureDelay;
    union {
        BOOL  bufferlastframe; // Set to TRUE if you want TakeFastFrame to return an already received frame.
        ULONG ulReserved1;
    };
    ULONG ulReserved2;         // Must be set to 0
    FLOAT flReserved1;         // Must be set to 0
    FLOAT flReserved2;         // Must be set to 0
} LUCAM_SNAPSHOT;
//----------------------------------------------------------------------------------------------------------------

// Conversion Settings
//----------------------------------------------------------------------------------------------------------------
// For use with LucamConvertFrame*
typedef struct LUCAM_CONVERSION {
    ULONG DemosaicMethod;     // LUCAM_DM_*
    ULONG CorrectionMatrix;   // LUCAM_CM_*
} LUCAM_CONVERSION;
//----------------------------------------------------------------------------------------------------------------

// Conversion Parameters
//----------------------------------------------------------------------------------------------------------------
// For the ConvertFrameTo*Ex functions
typedef struct LUCAM_CONVERSION_PARAMS {
    ULONG Size;               // Must be set to sizeof this struct
    ULONG DemosaicMethod;     // LUCAM_DM_*
    ULONG CorrectionMatrix;   // LUCAM_CM_*
    BOOL  FlipX;
    BOOL  FlipY;
    FLOAT Hue;
    FLOAT Saturation;
    BOOL  UseColorGainsOverWb;
    union {
        struct {
            FLOAT DigitalGain;
            FLOAT DigitalWhiteBalanceU;
            FLOAT DigitalWhiteBalanceV;
        };
        struct {
            FLOAT DigitalGainRed;
            FLOAT DigitalGainGreen;
            FLOAT DigitalGainBlue;
        };
    };
} LUCAM_CONVERSION_PARAMS, *PLUCAM_CONVERSION_PARAMS;
//----------------------------------------------------------------------------------------------------------------

// Image Format
//----------------------------------------------------------------------------------------------------------------
typedef struct LUCAM_IMAGE_FORMAT {
    ULONG Size;         // Must be set to sizeof this struct
    ULONG Width;
    ULONG Height;
    ULONG PixelFormat;  // LUCAM_PF_*
    ULONG ImageSize;

    ULONG LucamReserved[8];

} LUCAM_IMAGE_FORMAT, *PLUCAM_IMAGE_FORMAT;
//----------------------------------------------------------------------------------------------------------------

//******************************************************************************
// Stream Statistics
//******************************************************************************
typedef struct _LUCAM_STREAM_STATS
{
    ULONG FramesCompleted;
    ULONG FramesDropped;
    ULONG ActualFramesDropped;
    union
    {
        struct
        {
            ULONG ShortErrors;
            ULONG XactErrors;
            ULONG BabbleErrors;
            ULONG OtherErrors;
        }USB;
        struct
        {
            ULONG ShortErrors;
            ULONG XactErrors;
            ULONG BabbleErrors;
            ULONG OtherErrors;


            ULONG TransfersOutOfOrderErrors;
            ULONG PendingFrames;
            ULONG PendingUsbTransfers;
        }USB2; // Version 2 of this.
        struct
        {
            ULONG ExpectedResend;
            ULONG LostPacket;
            ULONG DataOverrun;
            ULONG PartialLineMissing;
            ULONG FullLineMissing;
            ULONG OtherErrors;

            ULONG ExpectedSingleResend;
            ULONG UnexpectedResend;
            ULONG ResendGroupRequested;
            ULONG ResendPacketRequested;
            ULONG IgnoredPacket;
            ULONG RedundantPacket;
            ULONG PacketOutOfOrder;
            ULONG BlocksDropped;
            ULONG BlockIDsMissing;
            struct
            {
                ULONG ImageError;
                ULONG MissingPackets;
                ULONG StateError;
                ULONG TooManyResends;
                ULONG TooManyConsecutiveResends;
                ULONG ResendsFailure;
            }Result;
        }GEV;
        struct
        {
            ULONG InputBufferAcqSuccess;
            ULONG InputBufferAcqFailures; // Same as FramesDropped and ActualFramesDropped
            ULONG FramesCompletedSuccess; // Same as FramesCompleted
            ULONG FramesCompletedError;

            ULONG PktReceived;
            ULONG PktInLastBlockError;
            ULONG PktInNextBlockError;
            ULONG BlockIdWayAheadError;
            ULONG NonSeqJumpAhead;
            ULONG NonSeqJumpBack;
            ULONG SegmentOverflowError;
            ULONG SegmentCreatedOnDesynch;
            ULONG PktOnlyPrecedingSegment;
            ULONG ResendOnSkip;
            ULONG ResendOnCountdown;
            ULONG PktAlreadyReceived;
            ULONG DesynchFixed;
            ULONG PktDroppedForAcqFailureCur;
            ULONG PktDroppedForAcqFailureNext;
            ULONG PktDiscardedForPreviousFailure;
            ULONG InvalidGvspHeader;
            ULONG InvalidPayloadSize;
            ULONG GvspStatusError;
            ULONG GvspStatusWarning;
            ULONG GvspLeaderReceived;
            ULONG GvspTrailerReceived;
            ULONG GvspPayloadReceived;
        }LSGEV;
    };
} LUCAM_STREAM_STATS, *PLUCAM_STREAM_STATS;
//----------------------------------------------------------------------------------------------------------------

// Subsampling and Binning Description - Used for WINDOWS or MAC
//----------------------------------------------------------------------------------------------------------------
typedef struct _LUCAM_SS_BIN_DESC
{
   UCHAR flags ; // 0x80: X and Y settings must be the same
   UCHAR reserved ;
   UCHAR ssNot1Count ;
   UCHAR binNot1Count ;
   UCHAR ssFormatsNot1[8] ; //
   UCHAR binFormatsNot1[8] ;//
}LUCAM_SS_BIN_DESC, *PLUCAM_SS_BIN_DESC ;
//----------------------------------------------------------------------------------------------------------------

// IP Configuration - Used for WINDOWS only
//----------------------------------------------------------------------------------------------------------------
typedef struct LGCAM_IP_CONFIGURATION {
    ULONG IPAddress;
    ULONG SubnetMask;
    ULONG DefaultGateway;
} LGCAM_IP_CONFIGURATION;
typedef LGCAM_IP_CONFIGURATION *PLGCAM_IP_CONFIGURATION;
//----------------------------------------------------------------------------------------------------------------
//****************************************************************************************************************
//****************************************************************************************************************
//****************************************************************************************************************
//****************************************************************************************************************

//-----------------------------------------------------------------------------
// Id: LucamNoError
//
// Meaning:
// Initialization value in the API.
//
#define LucamNoError                      0

//-----------------------------------------------------------------------------
// Id: LucamNoSuchIndex
//
// Meaning:
// The index passed to LucamCameraOpen was 0. It must be >= 1.
//
#define LucamNoSuchIndex                  1

//-----------------------------------------------------------------------------
// Id: LucamSnapshotNotSupported
//
// Meaning:
// The camera does not support snapshots or fast frames.
//
#define LucamSnapshotNotSupported         2

//-----------------------------------------------------------------------------
// Id: LucamInvalidPixelFormat
//
// Meaning:
// The pixel format parameter passed to the function is invalid
//
#define LucamInvalidPixelFormat           3

//-----------------------------------------------------------------------------
// Id: LucamSubsamplingZero
//
// Meaning:
// A subsampling of zero was passed to a function.
//
#define LucamSubsamplingZero              4

//-----------------------------------------------------------------------------
// Id: LucamBusy
//
// Meaning:
// The function is unavailable because the camera is busy with streaming or
// capturing fast frames.
//
#define LucamBusy                         5

//-----------------------------------------------------------------------------
// Id: LucamFailedToSetSubsampling
//
// Meaning:
// The API failed to set the requested subsampling. This can be due to
// the camera being disconnected. It can also be due to a filter
// not being there.
//
#define LucamFailedToSetSubsampling       6

//-----------------------------------------------------------------------------
// Id: LucamFailedToSetStartPosition
//
// Meaning:
// The API failed to set the requested subsampling. This can be due to
// the camera being disconnected.
//
#define LucamFailedToSetStartPosition     7

//-----------------------------------------------------------------------------
// Id: LucamPixelFormatNotSupported
//
// Meaning:
// The camera does not support the pixel format passed to the function.
//
#define LucamPixelFormatNotSupported      8

//-----------------------------------------------------------------------------
// Id: LucamInvalidFrameFormat
//
// Meaning:
// The format passed to the function does not pass the camera requirements.
// Verify that (xOffset + width) is not greater than the camera's maximum
// width. Verify that (width / subSamplingX) is a multiple of some 'nice'
// value. Do the same for the y.
//
#define LucamInvalidFrameFormat           9

//-----------------------------------------------------------------------------
// Id: LucamPreparationFailed
//
// Meaning:
// The API failed to prepare the camera for streaming or snapshot. This can
// due to the camera being disconnected. If START_STREAMING succeeds and
// START_DISPLAY fails with this error, this can be due to a filter not
// being there or registered.
//
#define LucamPreparationFailed            10

//-----------------------------------------------------------------------------
// Id: LucamCannotRun
//
// Meaning:
// The API failed to get the camera running. This can be due to a bandwidth
// problem.
//
#define LucamCannotRun                    11

//-----------------------------------------------------------------------------
// Id: LucamNoTriggerControl
//
// Meaning:
// Contact Lumenera.
//
#define LucamNoTriggerControl             12

//-----------------------------------------------------------------------------
// Id: LucamNoPin
//
// Meaning:
// Contact Lumenera.
//
#define LucamNoPin                        13

//-----------------------------------------------------------------------------
// Id: LucamNotRunning
//
// Meaning:
// The function failed because it requires the camera to be running, and it
// is not.
//
#define LucamNotRunning                   14

//-----------------------------------------------------------------------------
// Id: LucamTriggerFailed
//
// Meaning:
// Contact Lumenera.
//
#define LucamTriggerFailed                15

//-----------------------------------------------------------------------------
// Id: LucamCannotSetupFrameFormat
//
// Meaning:
// The camera does not support that its frame format get setup. This will
// happen if your camera is plugged to a USB 1 port and it does not
// support it. LucamCameraOpen will still succeeds, but if a call to
// LucamGetLastError will return this value.
//
#define LucamCannotSetupFrameFormat       16

//-----------------------------------------------------------------------------
// Id: LucamDirectShowInitError
//
// Meaning:
// Direct Show initialization error. This may happen if you run the API
// before having installed a DS compatible camera ever before. The
// Lumenera camera is DS compatible.
//
#define LucamDirectShowInitError          17

//-----------------------------------------------------------------------------
// Id: LucamCameraNotFound
//
// Meaning:
// The function LucamCameraOpen did not find the camera # index.
//
#define LucamCameraNotFound               18

//-----------------------------------------------------------------------------
// Id: LucamTimeout
//
// Meaning:
// The function timed out.
//
#define LucamTimeout                      19

//-----------------------------------------------------------------------------
// Id: LucamPropertyUnknown
//
// Meaning:
// The API does not know the property passed to LucamGetProperty,
// LucamSetProperty or LucamGetPropertyRange. You may be using an old dll.
//
#define LucamPropertyUnknown              20

//-----------------------------------------------------------------------------
// Id: LucamPropertyUnsupported
//
// Meaning:
// The camera does not support that property.
//
#define LucamPropertyUnsupported          21

//-----------------------------------------------------------------------------
// Id: LucamPropertyAccessFailed
//
// Meaning:
// The API failed to access the property. Most likely, the reason is that the
// camera does not support that property.
//
#define LucamPropertyAccessFailed         22

//-----------------------------------------------------------------------------
// Id: LucamLucustomNotFound
//
// Meaning:
// The lucustom.ax filter was not found.
//
#define LucamLucustomNotFound             23

//-----------------------------------------------------------------------------
// Id: LucamPreviewNotRunning
//
// Meaning:
// The function failed because preview is not running.
//
#define LucamPreviewNotRunning            24

//-----------------------------------------------------------------------------
// Id: LucamLutfNotLoaded
//
// Meaning:
// The function failed because lutf.ax is not loaded.
//
#define LucamLutfNotLoaded                25

//-----------------------------------------------------------------------------
// Id: LucamDirectShowError
//
// Meaning:
// An error related to the operation of DirectShow occured.
//
#define LucamDirectShowError              26

//-----------------------------------------------------------------------------
// Id: LucamNoMoreCallbacks
//
// Meaning:
// The function LucamAddStreamingCallback failed because the API cannot
// support any more callbacks
//
#define LucamNoMoreCallbacks              27

//-----------------------------------------------------------------------------
// Id: LucamUndeterminedFrameFormat
//
// Meaning:
// The API does not know what is the frame format of the camera.
//
#define LucamUndeterminedFrameFormat      28

//-----------------------------------------------------------------------------
// Id: LucamInvalidParameter
//
// Meaning:
// An parameter has an obviously wrong value.
//
#define LucamInvalidParameter             29

//-----------------------------------------------------------------------------
// Id: LucamNotEnoughResources
//
// Meaning:
// Resource allocation failed.
//
#define LucamNotEnoughResources           30

//-----------------------------------------------------------------------------
// Id: LucamNoSuchConversion
//
// Meaning:
// One of the members of the LUCAM_CONVERSION structure passed is either
// unknown or inappropriate
//
#define LucamNoSuchConversion             31

//-----------------------------------------------------------------------------
// Id: LucamParameterNotWithinBoundaries
//
// Meaning:
// A parameter representing a quantity is outside the allowed boundaries.
//
#define LucamParameterNotWithinBoundaries 32

//-----------------------------------------------------------------------------
// Id: LucamBadFileIo
//
// Meaning:
// An error occured creating a file or writing to it. Verify that the
// path exists.
//
#define LucamBadFileIo                    33

//-----------------------------------------------------------------------------
// Id: LucamGdiplusNotFound
//
// Meaning:
// gdiplus.dll is needed and was not found.
//
#define LucamGdiplusNotFound              34

//-----------------------------------------------------------------------------
// Id: LucamGdiplusError
//
// Meaning:
// gdiplus.dll reported an error. This may happen if there is a file io error.
//
#define LucamGdiplusError                 35

//-----------------------------------------------------------------------------
// Id: LucamUnknownFormatType
//
// Meaning:
// Contact Lumenera.
//
#define LucamUnknownFormatType            36

//-----------------------------------------------------------------------------
// Id: LucamFailedCreateDisplay
//
// Meaning:
// The API failed to create the display window. The reason could be
// unsufficient resources.
//
#define LucamFailedCreateDisplay          37

//-----------------------------------------------------------------------------
// Id: LucamDpLibNotFound
//
// Meaning:
// deltapolation.dll is needed and was not found.
//
#define LucamDpLibNotFound                38

//-----------------------------------------------------------------------------
// Id: LucamDpCmdNotSupported
//
// Meaning:
// The deltapolation command is not supported by the delta polation library.
//
#define LucamDpCmdNotSupported            39

//-----------------------------------------------------------------------------
// Id: LucamDpCmdUnknown
//
// Meaning:
// The deltapolation command is unknown or invalid.
//
#define LucamDpCmdUnknown                 40

//-----------------------------------------------------------------------------
// Id: LucamNotWhilePaused
//
// Meaning:
// The function cannot be performed when the camera is in paused state.
//
#define LucamNotWhilePaused               41

//-----------------------------------------------------------------------------
// Id: LucamCaptureFailed
//
// Meaning:
// Contact Lumenera.
//
#define LucamCaptureFailed                42

//-----------------------------------------------------------------------------
// Id: LucamDpError
//
// Meaning:
// Contact Lumenera.
//
#define LucamDpError                      43

//-----------------------------------------------------------------------------
// Id: LucamNoSuchFrameRate
//
// Meaning:
// Contact Lumenera.
//
#define LucamNoSuchFrameRate              44

//-----------------------------------------------------------------------------
// Id: LucamInvalidTarget
//
// Meaning:
// One of the target parameters is wrong. This error code is used when
// startX + width > (frameFormat.width / frameFormat.subSampleX) or
// startY + height > (frameFormat.height / frameFormat.subSampleY) or
// if any of those parameter is odd (not a multiple of 2) or
// if width or height is 0.
//
#define LucamInvalidTarget                45

//-----------------------------------------------------------------------------
// Id: LucamFrameTooDark
//
// Meaning:
// The frame is too dark to perform white balance.
//
#define LucamFrameTooDark                 46

//-----------------------------------------------------------------------------
// Id: LucamKsPropertySetNotFound
//
// Meaning:
// A DirectShow interface necessary to carry out the operation was not found.
//
#define LucamKsPropertySetNotFound        47

//-----------------------------------------------------------------------------
// Id: LucamCancelled
//
// Meaning:
// The user cancelled the operation.
//
#define LucamCancelled                    48

//-----------------------------------------------------------------------------
// Id: LucamKsControlNotSupported
//
// Meaning:
// The DirectShow IKsControl interface is not supported (did you unplugged the camera?).
//
#define LucamKsControlNotSupported        49

//-----------------------------------------------------------------------------
// Id: LucamEventNotSupported
//
// Meaning:
// Some module attempted to register an unsupported event.
//
#define LucamEventNotSupported            50

//-----------------------------------------------------------------------------
// Id: LucamNoPreview
//
// Meaning:
// The function failed because preview was not setup.
//
#define LucamNoPreview                    51

//-----------------------------------------------------------------------------
// Id: LucamSetPositionFailed
//
// Meaning:
// A function setting window position failed (invalid parameters??).
//
#define LucamSetPositionFailed            52

//-----------------------------------------------------------------------------
// Id: LucamNoFrameRateList
//
// Meaning:
// The frame rate list is not available.
//
#define LucamNoFrameRateList              53

//-----------------------------------------------------------------------------
// Id: LucamFrameRateInconsistent
//
// Meaning:
// There was an error building the frame rate list.
//
#define LucamFrameRateInconsistent        54

//-----------------------------------------------------------------------------
// Id: LucamCameraNotConfiguredForCmd
//
// Meaning:
// The camera does not support that particular command.
//
#define LucamCameraNotConfiguredForCmd    55

//----------------------------------------------------------------------------
// Id: LucamGraphNotReady
//
// Meaning:
// The graph is not ready.
//
#define LucamGraphNotReady                56

//----------------------------------------------------------------------------
// Id: LucamCallbackSetupError
//
// Meaning:
// Contact Lumenera.
//
#define LucamCallbackSetupError           57

//----------------------------------------------------------------------------
// Id: LucamInvalidTriggerMode
//
// Meaning:
// You cannot cause a soft trigger when hw trigger is enabled.
//
#define LucamInvalidTriggerMode           58

//----------------------------------------------------------------------------
// Id: LucamNotFound
//
// Meaning:
// The API was asked to return soomething that is not there.
//
#define LucamNotFound                     59

//----------------------------------------------------------------------------
// Id: LucamPermanentBufferNotSupported
//
// Meaning:
// The onboard EEPROM is too small.
//
#define LucamPermanentBufferNotSupported  60

//----------------------------------------------------------------------------
// Id: LucamEepromWriteFailed
//
// Meaning:
// The API failed to write to the onboard eeprom.
//
#define LucamEepromWriteFailed            61

//----------------------------------------------------------------------------
// Id: LucamUnknownFileType
//
// Meaning:
// The API failed because it failed to recognize the file type of a
// file name passed to it..
//
#define LucamUnknownFileType              62

//----------------------------------------------------------------------------
// Id: LucamEventIdNotSupported
//
// Meaning:
// LucamRegisterEventNotification failed because the event is not supported.
//
#define LucamEventIdNotSupported          63

//----------------------------------------------------------------------------
// Id: LucamEepromCorrupted
//
// Meaning:
// The API found that the EEPROM was corrupted.
//
#define LucamEepromCorrupted              64

//----------------------------------------------------------------------------
// Id: LucamSectionTooBig
//
// Meaning:
// The VPD section to write to the eeprom is too big.
//
#define LucamSectionTooBig                65

//-----------------------------------------------------------------------------
// Id: LucamFrameTooBright
//
// Meaning:
// The frame is too bright to perform white balance.
//
#define LucamFrameTooBright               66

//-----------------------------------------------------------------------------
// Id: LucamNoCorrectionMatrix
//
// Meaning:
// The camera is configured to have no correction matrix (LUCAM_PROP_CORRECTION_MATRIX
// is LUCAM_CM_NONE).
//
#define LucamNoCorrectionMatrix           67

//-----------------------------------------------------------------------------
// Id: LucamUnknownCameraModel
//
// Meaning:
// The API failed because it needs to know the camera model and it is not available.
//
#define LucamUnknownCameraModel           68

//-----------------------------------------------------------------------------
// Id: LucamApiTooOld
//
// Meaning:
// The API failed because it needs to be upgraded to access a feature of the camera.
//
#define LucamApiTooOld                    69

//-----------------------------------------------------------------------------
// Id: LucamSaturationZero
//
// Meaning:
// The API failed because the saturation is currently 0.
//
#define LucamSaturationZero					70

//-----------------------------------------------------------------------------
// Id: LucamAlreadyInitialised
//
// Meaning:
// The API failed because the object was already initialised.
//
#define LucamAlreadyInitialised				71

//-----------------------------------------------------------------------------
// Id: LucamSameInputAndOutputFile
//
// Meaning:
// The API failed because the object was already initialised.
//
#define LucamSameInputAndOutputFile			72

//-----------------------------------------------------------------------------
// Id: LucamFileConversionFailed
//
// Meaning:
// The API failed because the file conversion was not completed.
//
#define LucamFileConversionFailed			73

//-----------------------------------------------------------------------------
// Id: LucamFileAlreadyConverted
//
// Meaning:
// The API failed because the file is already converted in the desired format.
//
#define LucamFileAlreadyConverted			74

//-----------------------------------------------------------------------------
// Id: LucamPropertyPageNotSupported
//
// Meaning:
// The API failed to display the property page.
//
#define LucamPropertyPageNotSupported     75

//-----------------------------------------------------------------------------
// Id: LucamPropertyPageCreationFailed
//
// Meaning:
// The API failed to create the property page.
//
#define LucamPropertyPageCreationFailed   76

//-----------------------------------------------------------------------------
// Id: LucamDirectShowFilterNotInstalled
//
// Meaning:
// The API did not find the required direct show filter.
//
#define LucamDirectShowFilterNotInstalled 77

//-----------------------------------------------------------------------------
// Id: LucamIndividualLutNotAvailable
//
// Meaning:
// The camera does not support that different LUTs are applied to each color.
//
#define LucamIndividualLutNotAvailable    78

//-----------------------------------------------------------------------------
// Id: LucamUnexpectedError
//
// Meaning:
// Contact Lumenera.
//
#define LucamUnexpectedError              79

//-----------------------------------------------------------------------------
// Id: LucamStreamingStopped
//
// Meaning:
// LucamTakeFastFrame or LucamTakeVideo failed because another thread interrupted
// the streaming by a call to LucamDisableFastFrames or LucamStreamVideoControl.
//
#define LucamStreamingStopped             80

//-----------------------------------------------------------------------------
// Id: LucamMustBeInSwTriggerMode
//
// Meaning:
// LucamForceTakeFastFrame was called while the camera is in hardware trigger
// still mode and the camera does not support taking a sw trigger snapshot while
// in that state.
//
#define LucamMustBeInSwTriggerMode        81

//-----------------------------------------------------------------------------
// Id: LucamTargetFlaky
//
// Meaning:
// The target is too flaky to perform auto focus.
//
#define LucamTargetFlaky                  82

//-----------------------------------------------------------------------------
// Id: LucamAutoLensUninitialized
//
// Meaning:
// The auto lens needs to be initialized before the function is used.
//
#define LucamAutoLensUninitialized        83

//-----------------------------------------------------------------------------
// Id: LucamLensNotInstalled
//
// Meaning:
// The function failed because the lens were not installed correctly. Verify
// that changing the focus has any effect.
//
#define LucamLensNotInstalled             84

//-----------------------------------------------------------------------------
// Id: LucamUnknownError
//
// Meaning:
// The function failed because of an unknown error. Contact Lumenera.
//
#define LucamUnknownError                 85

//-----------------------------------------------------------------------------
// Id: LucamFocusNoFeedbackError
//
// Meaning:
// There is no feedback available for focus.
//
#define LucamFocusNoFeedbackError         86

//-----------------------------------------------------------------------------
// Id: LucamLutfTooOld
//
// Meaning:
// LuTF.ax is too old for this feature.
//
#define LucamLutfTooOld                   87

//-----------------------------------------------------------------------------
// Id: LucamUnknownAviFormat
//
// Meaning:
// Unknown or invalid AVI format for input file.
//
#define LucamUnknownAviFormat             88

//-----------------------------------------------------------------------------
// Id: LucamUnknownAviType
//
// Meaning:
// Unknown AVI type. Verify the AVI type parameter.
//
#define LucamUnknownAviType               89

//-----------------------------------------------------------------------------
// Id: LucamInvalidAviConversion
//
// Meaning:
// The AVI conversion is invalid.
//
#define LucamInvalidAviConversion         90

//-----------------------------------------------------------------------------
// Id: LucamSeekFailed
//
// Meaning:
// The seeking operation failed.
//
#define LucamSeekFailed                   91

//-----------------------------------------------------------------------------
// Id: LucamAviRunning
//
// Meaning:
// The function cannot be performed while an AVI is being captured.
//
#define LucamAviRunning                   92

//-----------------------------------------------------------------------------
// Id: LucamCameraAlreadyOpened
//
// Meaning:
// An attempt was made to open a camera for streaming-related reasons while
// it is already opened for such.
//
#define LucamCameraAlreadyOpened          93

//-----------------------------------------------------------------------------
// Id: LucamNoSubsampledHighRes
//
// Meaning:
// The API cannot take a high resolution image in subsampled mode or binning mode.
//
#define LucamNoSubsampledHighRes          94

//-----------------------------------------------------------------------------
// Id: LucamOnlyOnMonochrome
//
// Meaning:
// The API function is only available on monochrome cameras.
//
#define LucamOnlyOnMonochrome             95

//-----------------------------------------------------------------------------
// Id: LucamNo8bppTo48bpp
//
// Meaning:
// Building a 48 bpp image from an 8 bpp image is invalid.
//
#define LucamNo8bppTo48bpp                96

//-----------------------------------------------------------------------------
// Id: LucamLut8Obsolete
//
// Meaning:
// Use 12 bits lut instead.
//
#define LucamLut8Obsolete                 97

//-----------------------------------------------------------------------------
// Id: LucamFunctionNotSupported
//
// Meaning:
// That functionnality is not supported.
//
#define LucamFunctionNotSupported         98

//-----------------------------------------------------------------------------
// Id: LucamRetryLimitReached
//
// Meaning:
// Property access failed due to a retry limit.
//
#define LucamRetryLimitReached            99

//-----------------------------------------------------------------------------
// Id: LucamLgDeviceError
//
// Meaning:
// An IO operation to the camera failed.
//
#define LucamLgDeviceError                100

//-----------------------------------------------------------------------------
// Id: LucamInvalidIpConfiguration
//
// Meaning:
// The Lg camera has an invalid IP configuration.
#define LucamInvalidIpConfiguration       101

//-----------------------------------------------------------------------------
// Id: LucamInvalidLicense
//
// Meaning:
// The license to operate the camera is invalid
#define LucamInvalidLicense               102

//-----------------------------------------------------------------------------
// Id: LucamNoSystemEnumerator
//
// Meaning:
// Camera enumeration is impossible due to a software installation error.
#define LucamNoSystemEnumerator           103

//-----------------------------------------------------------------------------
// Id: LucamBusEnumeratorNotInstalled
//
// Meaning:
// Camera enumeration is impossible due to a software installation error.
#define LucamBusEnumeratorNotInstalled    104

//-----------------------------------------------------------------------------
// Id: LucamUnknownExternInterface
//
// Meaning:
// Unknown external interface.
#define LucamUnknownExternInterface       105

//-----------------------------------------------------------------------------
// Id: LucamInterfaceDriverNotInstalled
//
// Meaning:
// Incomplete or incorrect software installation prevents streaming from the
// camera.
#define LucamInterfaceDriverNotInstalled  106

//-----------------------------------------------------------------------------
// Id: LucamCameraDriverNotInstalled
//
// Meaning:
// Incomplete or incorrect software installation prevents streaming from the
// camera.
// Opening the device manager and updating the drivers on the relevant device
// may fix the issue.
#define LucamCameraDriverNotInstalled     107

//-----------------------------------------------------------------------------
// Id: LucamCameraDriverInstallInProgress
//
// Meaning:
// Incomplete or incorrect software installation prevents streaming from the
// camera.
// Opening the device manager and updating the drivers on the relevant device
// may fix the issue.
#define LucamCameraDriverInstallInProgress 108

//-----------------------------------------------------------------------------
// Id: LucamLucamapiDotDllNotFound
//
// Meaning:
// Lucamapi.dll is not found.
//
#define LucamLucamapiDotDllNotFound       109

//-----------------------------------------------------------------------------
// Id: LucamLucamapiProcedureNotFound
//
// Meaning:
// A procedure in Lucamapi.dll was not found.
//
#define LucamLucamapiProcedureNotFound    110

//-----------------------------------------------------------------------------
// Id: LucamPropertyNotEnumeratable
//
// Meaning:
// The property cannot be accessed via LucamEnumProperty.
#define LucamPropertyNotEnumeratable      111

//-----------------------------------------------------------------------------
// Id: LucamPropertyNotBufferable
//
// Meaning:
// The property cannot be accessed via LucamPropertyGetBuffer.
#define LucamPropertyNotBufferable        112

//-----------------------------------------------------------------------------
// Id: LucamSingleTapImage
//
// Meaning:
// The API cannot perform multi tap correction on a single tap image.
#define LucamSingleTapImage               113

//-----------------------------------------------------------------------------
// Id: LucamUnknownTapConfiguration
//
// Meaning:
// The API is too old and does not know the tap configuration of the image..
#define LucamUnknownTapConfiguration      114

//-----------------------------------------------------------------------------
// Id: LucamBufferTooSmall
//
// Meaning:
// A buffer supplied to the API is too small.
#define LucamBufferTooSmall               115

//-----------------------------------------------------------------------------
// Id: LucamInCallbackOnly
//
// Meaning:
// A function that can only be called within a callback was called elsewhere.
#define LucamInCallbackOnly               116

//-----------------------------------------------------------------------------
// Id: LucamPropertyUnavailable
//
// Meaning:
// The property is not available at this moment.
//
#define LucamPropertyUnavailable          117

//-----------------------------------------------------------------------------
// Id: LucamTimestampNotEnabled
//
// Meaning:
// The API cannot extract timestamp from the image buffer because feature
// was not enabled.
//
#define LucamTimestampNotEnabled          118

//-----------------------------------------------------------------------------
// Id: LucamFramecounterNotEnabled
//
// Meaning:
// The API cannot extract frame counter from the image buffer because feature
// was not enabled.
//
#define LucamFramecounterNotEnabled       119

//-----------------------------------------------------------------------------
// Id: LucamNoStatsWhenNotStreaming
//
// Meaning:
// LucamQueryStats was called but the camera is not streaming.
#define LucamNoStatsWhenNotStreaming      120

//-----------------------------------------------------------------------------
// Id: LucamFrameCapturePending
//
// Meaning:
// LucamTakeVideo or LucamTakeFastFrame or one of its variant was called from
// multiple threads. This is bad practice.
#define LucamFrameCapturePending          121

//-----------------------------------------------------------------------------
// Id: LucamSequencingNotEnabled
//
// Meaning:
// An API failed because sequencing was not enabled.
//
#define LucamSequencingNotEnabled         122

//-----------------------------------------------------------------------------
// Id: LucamFeatureNotSequencable
//
// Meaning:
// Sequencing was attempted on a non-sequencable feature/property.
//
#define LucamFeatureNotSequencable        123

//-----------------------------------------------------------------------------
// Id: LucamSequencingUnknownFeatureType
//
// Meaning:
// Only the property feature type is supported for sequencing.
//
#define LucamSequencingUnknownFeatureType 124

//-----------------------------------------------------------------------------
// Id: LucamSequencingIndexOutOfSequence
//
// Meaning:
// Sequence capture failed because a received frame is out of sequence
//
#define LucamSequencingIndexOutOfSequence 125

//-----------------------------------------------------------------------------
// Id: LucamSequencingBadFrameNumber
//
// Meaning:
// Sequence setup failed because a setting's frame number was invalid.
//
#define LucamSequencingBadFrameNumber     126

//-----------------------------------------------------------------------------
// Id: LucamInformationNotAvailable
//
// Meaning:
// Supported binning and subsampling information is not available.
//
#define LucamInformationNotAvailable      127

//-----------------------------------------------------------------------------
// Id: LucamSequencingBadSetting
//
// Meaning:
// Sequence setup failed because a setting's size is invalid.
//
#define LucamSequencingBadSetting         128

//-----------------------------------------------------------------------------
// Id: LucamAutoFocusNeverStarted
//
// Meaning:
// LucamAutoFocusWait was called but auto focus was never started.
//
#define LucamAutoFocusNeverStarted        129

//-----------------------------------------------------------------------------
// Id: LucamAutoFocusNotRunning
//
// Meaning:
// LucamAutoFocusStop was called but auto focus is not running.
//
#define LucamAutoFocusNotRunning          130

/***********************************************************************************
* Codes 1121 - 1131 are linux specific and are returned only by Lucam API for Linux  *
************************************************************************************/

//-----------------------------------------------------------------------------
// Id: LucamCameraNotOpenable
//
// Meaning:
// The camera cannot be opened.
#define LucamCameraNotOpenable            1121
//-----------------------------------------------------------------------------
// Id: LucamCameraNotSupported
//
// Meaning:
// The camera is not supported by the lucamapi.
#define LucamCameraNotSupported           1122

//-----------------------------------------------------------------------------
// Id: LucamMmapFailed
//
// Meaning:
// An internal operation failed.
#define LucamMmapFailed                   1123

//-----------------------------------------------------------------------------
// Id: LucamNotWhileStreaming
//
// Meaning:
// The API cannot work while streaming is enabled.
#define LucamNotWhileStreaming            1124

//-----------------------------------------------------------------------------
// Id: LucamNoStreamingRights
//
// Meaning:
// The camera was opened without streaming rights enabled.
#define LucamNoStreamingRights            1125

//-----------------------------------------------------------------------------
// Id: LucamCameraInitializationError
//
// Meaning:
// Unspecified camera initialization error.
#define LucamCameraInitializationError    1126

//-----------------------------------------------------------------------------
// Id: LucamCannotVerifyPixelFormat
//
// Meaning:
// The API cannot verify the pixel format with the camera.
#define LucamCannotVerifyPixelFormat      1127

//-----------------------------------------------------------------------------
// Id: LucamCannotVerifyStartPosition
//
// Meaning:
// The API cannot verify the start position with the camera.
#define LucamCannotVerifyStartPosition    1128

//-----------------------------------------------------------------------------
// Id: LucamOsError
//
// Meaning:
// An OS service failed, possibly due to an application kill.
#define LucamOsError                      1129

//-----------------------------------------------------------------------------
// Id: LucamBufferNotAvailable
//
// Meaning:
// The frame buffer is not available for capturing a frame.
#define LucamBufferNotAvailable           1130

//-----------------------------------------------------------------------------
// Id: LucamQueuingFailed
//
// Meaning:
// Cannot queue buffer for capturing a frame.
#define LucamQueuingFailed                1131

//****************************************************************************************************************
//  Function Definitions 
//****************************************************************************************************************

//****************************************************************************************************************
//****************************************************************************************************************
//****************************************************************************************************************
//  COMMON Section
//****************************************************************************************************************
//****************************************************************************************************************
//****************************************************************************************************************
LUCAM_API LONG   LUCAM_EXPORT LucamNumCameras                               (VOID);

LUCAM_API LONG   LUCAM_EXPORT LucamEnumCameras                              (LUCAM_VERSION *pVersionsArray, ULONG arrayCount);
LUCAM_API HANDLE LUCAM_EXPORT LucamCameraOpen                               (ULONG index);
LUCAM_API BOOL   LUCAM_EXPORT LucamCameraClose                              (HANDLE hCamera);
LUCAM_API BOOL   LUCAM_EXPORT LucamCameraReset                              (HANDLE hCamera);

// Querying error information
LUCAM_API ULONG  LUCAM_EXPORT LucamGetLastError                             (VOID);
LUCAM_API ULONG  LUCAM_EXPORT LucamGetLastErrorForCamera                    (HANDLE hCamera);

LUCAM_API BOOL   LUCAM_EXPORT LucamQueryVersion                             (HANDLE hCamera, LUCAM_VERSION *pVersion);
LUCAM_API BOOL   LUCAM_EXPORT LucamQueryExternInterface                     (HANDLE hCamera, ULONG *pExternInterface);
LUCAM_API BOOL   LUCAM_EXPORT LucamGetCameraId                              (HANDLE hCamera, ULONG *pId);
LUCAM_API BOOL   LUCAM_EXPORT LucamGetHardwareRevision                      (HANDLE hCamera, ULONG *pRevision);

LUCAM_API BOOL   LUCAM_EXPORT LucamGetProperty                              (HANDLE hCamera, ULONG propertyId, FLOAT *pValue, LONG *pFlags);
LUCAM_API BOOL   LUCAM_EXPORT LucamSetProperty                              (HANDLE hCamera, ULONG propertyId, FLOAT   value, LONG   flags);
LUCAM_API BOOL   LUCAM_EXPORT LucamPropertyRange                            (HANDLE hCamera, ULONG propertyId, FLOAT *pMin, FLOAT *pMax, FLOAT *pDefault, LONG *pFlags);

LUCAM_API BOOL   LUCAM_EXPORT LucamSetFormat                                (HANDLE hCamera, LUCAM_FRAME_FORMAT *pFormat, FLOAT   frameRate);
LUCAM_API BOOL   LUCAM_EXPORT LucamGetFormat                                (HANDLE hCamera, LUCAM_FRAME_FORMAT *pFormat, FLOAT *pFrameRate);

LUCAM_API ULONG  LUCAM_EXPORT LucamEnumAvailableFrameRates                  (HANDLE hCamera, ULONG entryCount, FLOAT *pAvailableFrameRates);

LUCAM_API BOOL   LUCAM_EXPORT LucamStreamVideoControl                       (HANDLE hCamera, ULONG controlType, HWND hWnd);

LUCAM_API BOOL   LUCAM_EXPORT LucamTakeVideo                                (HANDLE hCamera, LONG numFrames, BYTE *pData);
LUCAM_API BOOL   LUCAM_EXPORT LucamTakeVideoEx                              (HANDLE hCamera, BYTE *pData, ULONG *pLength, ULONG timeout);
LUCAM_API BOOL   LUCAM_EXPORT LucamCancelTakeVideo                          (HANDLE hCamera);

//
// TakeSnapshot is a convenience function, wrapping the following sequence:
//   BOOL rc = LucamEnableFastFrames(hCamera, pSettings);
//   if (FALSE == rc) { return rc; }
//   rc = LucamTakeFastFrame(hCamera, pData);
//   LucamDisableFastFrames(hCamera);
//   return rc;
//
LUCAM_API BOOL   LUCAM_EXPORT LucamTakeSnapshot                             (HANDLE hCamera, LUCAM_SNAPSHOT *pSettings, BYTE *pData);


LUCAM_API LONG   LUCAM_EXPORT LucamAddStreamingCallback                     (HANDLE hCamera, VOID (LUCAM_EXPORT *VideoFilter)(VOID *pContext, BYTE *pData, ULONG dataLength), VOID *pCBContext);
LUCAM_API BOOL   LUCAM_EXPORT LucamRemoveStreamingCallback                  (HANDLE hCamera, LONG callbackId);

LUCAM_API LONG   LUCAM_EXPORT LucamAddRgbPreviewCallback                    (HANDLE hCamera, VOID (LUCAM_EXPORT *RgbVideoFilter)(VOID *pContext, BYTE *pData, ULONG dataLength, ULONG unused), VOID *pContext, ULONG rgbPixelFormat);
LUCAM_API BOOL   LUCAM_EXPORT LucamRemoveRgbPreviewCallback                 (HANDLE hCamera, LONG callbackId);
LUCAM_API BOOL   LUCAM_EXPORT LucamQueryRgbPreviewPixelFormat               (HANDLE hCamera, ULONG *pRgbPixelFormat);

LUCAM_API LONG   LUCAM_EXPORT LucamAddSnapshotCallback                      (HANDLE hCamera, VOID (LUCAM_EXPORT *SnapshotCallback)(VOID *pContext, BYTE *pData, ULONG dataLength), VOID *pCBContext);
LUCAM_API BOOL   LUCAM_EXPORT LucamRemoveSnapshotCallback                   (HANDLE hCamera, LONG callbackId);

LUCAM_API BOOL   LUCAM_EXPORT LucamConvertFrameToGreyscale8Ex               (HANDLE hCamera, BYTE   *pDest, const BYTE   *pSrc, LUCAM_IMAGE_FORMAT *pImageFormat, LUCAM_CONVERSION_PARAMS *pParams);
LUCAM_API BOOL   LUCAM_EXPORT LucamConvertFrameToGreyscale16Ex              (HANDLE hCamera, USHORT *pDest, const USHORT *pSrc, LUCAM_IMAGE_FORMAT *pImageFormat, LUCAM_CONVERSION_PARAMS *pParams);

LUCAM_API BOOL   LUCAM_EXPORT LucamConvertFrameToRgb24                      (HANDLE hCamera, BYTE   *pDest, BYTE   *pSrc, ULONG width, ULONG height, ULONG pixelFormat, LUCAM_CONVERSION *pParams);
LUCAM_API BOOL   LUCAM_EXPORT LucamConvertFrameToRgb32                      (HANDLE hCamera, BYTE   *pDest, BYTE   *pSrc, ULONG width, ULONG height, ULONG pixelFormat, LUCAM_CONVERSION *pParams);
LUCAM_API BOOL   LUCAM_EXPORT LucamConvertFrameToRgb48                      (HANDLE hCamera, USHORT *pDest, USHORT *pSrc, ULONG width, ULONG height, ULONG pixelFormat, LUCAM_CONVERSION *pParams);
LUCAM_API BOOL   LUCAM_EXPORT LucamConvertFrameToRgb24Ex                    (HANDLE hCamera, BYTE   *pDest, const BYTE   *pSrc, const LUCAM_IMAGE_FORMAT *pImageFormat, const LUCAM_CONVERSION_PARAMS *pParams);
LUCAM_API BOOL   LUCAM_EXPORT LucamConvertFrameToRgb32Ex                    (HANDLE hCamera, BYTE   *pDest, const BYTE   *pSrc, const LUCAM_IMAGE_FORMAT *pImageFormat, const LUCAM_CONVERSION_PARAMS *pParams);
LUCAM_API BOOL   LUCAM_EXPORT LucamConvertFrameToRgb48Ex                    (HANDLE hCamera, USHORT *pDest, const USHORT *pSrc, const LUCAM_IMAGE_FORMAT *pImageFormat, const LUCAM_CONVERSION_PARAMS *pParams);

LUCAM_API BOOL   LUCAM_EXPORT LucamSetupCustomMatrix                        (HANDLE hCamera, FLOAT *pMatrix);
LUCAM_API BOOL   LUCAM_EXPORT LucamGetCurrentMatrix                         (HANDLE hCamera, FLOAT *pMatrix);

LUCAM_API BOOL   LUCAM_EXPORT LucamEnableFastFrames                         (HANDLE hCamera, LUCAM_SNAPSHOT *pSettings);
LUCAM_API BOOL   LUCAM_EXPORT LucamTakeFastFrame                            (HANDLE hCamera, BYTE *pData);
LUCAM_API BOOL   LUCAM_EXPORT LucamForceTakeFastFrame                       (HANDLE hCamera, BYTE *pData);
LUCAM_API BOOL   LUCAM_EXPORT LucamTakeFastFrameNoTrigger                   (HANDLE hCamera, BYTE *pData);
LUCAM_API BOOL   LUCAM_EXPORT LucamDisableFastFrames                        (HANDLE hCamera);
LUCAM_API BOOL   LUCAM_EXPORT LucamTriggerFastFrame                         (HANDLE hCamera);

LUCAM_API BOOL   LUCAM_EXPORT LucamSetTriggerMode                           (HANDLE hCamera, BOOL useHwTrigger);
LUCAM_API BOOL   LUCAM_EXPORT LucamCancelTakeFastFrame                      (HANDLE hCamera);


LUCAM_API BOOL   LUCAM_EXPORT LucamGetTruePixelDepth                        (HANDLE hCamera, ULONG *pCount);

LUCAM_API BOOL   LUCAM_EXPORT LucamGpioRead                                 (HANDLE hCamera, BYTE *pGpoValues, BYTE *pGpiValues);
LUCAM_API BOOL   LUCAM_EXPORT LucamGpioWrite                                (HANDLE hCamera, BYTE   gpoValues);
LUCAM_API BOOL   LUCAM_EXPORT LucamGpoSelect                                (HANDLE hCamera, BYTE gpoEnable);    // Selects between GPO output or alternate function
LUCAM_API BOOL   LUCAM_EXPORT LucamGpioConfigure                            (HANDLE hCamera, BYTE enableOutput); // Enables output drive on a pin.

LUCAM_API BOOL   LUCAM_EXPORT LucamOneShotAutoExposure                      (HANDLE hCamera, UCHAR target, ULONG startX, ULONG startY, ULONG width, ULONG height);
LUCAM_API BOOL   LUCAM_EXPORT LucamOneShotAutoGain                          (HANDLE hCamera, UCHAR target, ULONG startX, ULONG startY, ULONG width, ULONG height);
LUCAM_API BOOL   LUCAM_EXPORT LucamOneShotAutoWhiteBalance                  (HANDLE hCamera,               ULONG startX, ULONG startY, ULONG width, ULONG height);
LUCAM_API BOOL   LUCAM_EXPORT LucamDigitalWhiteBalance                      (HANDLE hCamera,               ULONG startX, ULONG startY, ULONG width, ULONG height);
LUCAM_API BOOL   LUCAM_EXPORT LucamOneShotAutoWhiteBalanceEx                (HANDLE hCamera, FLOAT redOverGreen, FLOAT blueOverGreen, ULONG startX, ULONG startY, ULONG width, ULONG height);

LUCAM_API BOOL   LUCAM_EXPORT LucamGetVideoImageFormat                      (HANDLE hCamera, LUCAM_IMAGE_FORMAT *pImageFormat);
LUCAM_API BOOL   LUCAM_EXPORT LucamGetStillImageFormat                      (HANDLE hCamera, LUCAM_IMAGE_FORMAT *pImageFormat);

// On-host Tap Correction
LUCAM_API BOOL   LUCAM_EXPORT LucamPerformDualTapCorrection                 (HANDLE hCamera, BYTE *pFrame, const LUCAM_IMAGE_FORMAT *pImageFormat);
LUCAM_API BOOL   LUCAM_EXPORT LucamPerformMultiTapCorrection                (HANDLE hCamera, BYTE *pFrame, const LUCAM_IMAGE_FORMAT *pImageFormat);


LUCAM_API BOOL   LUCAM_EXPORT LucamSaveImageEx                              (HANDLE hCamera, ULONG width, ULONG height, ULONG pixelFormat, BYTE *pData, const CHAR  *pFilename);
LUCAM_API BOOL   LUCAM_EXPORT LucamSaveImageWEx                             (HANDLE hCamera, ULONG width, ULONG height, ULONG pixelFormat, BYTE *pData, const WCHAR *pFilename);
LUCAM_API BOOL   LUCAM_EXPORT LucamGetSubsampleBinDescription               (HANDLE hCamera, LUCAM_SS_BIN_DESC *pDesc) ;

//****************************************************************************************************************
//****************************************************************************************************************
//****************************************************************************************************************
//****************************************************************************************************************
//****************************************************************************************************************
//****************************************************************************************************************
//****************************************************************************************************************
//****************************************************************************************************************


//****************************************************************************************************************
//****************************************************************************************************************
//****************************************************************************************************************
//  WINDOWS Section
//****************************************************************************************************************
//****************************************************************************************************************
//****************************************************************************************************************
LUCAM_API ULONG  LUCAM_EXPORT LucamQueryStats                               (HANDLE hCamera, BOOL stillStream, LUCAM_STREAM_STATS *pStats, ULONG sizeofStats);

LUCAM_API BOOL   LUCAM_EXPORT LucamDisplayPropertyPage                      (HANDLE hCamera, HWND hParentWnd);
LUCAM_API BOOL   LUCAM_EXPORT LucamDisplayVideoFormatPage                   (HANDLE hCamera, HWND hParentWnd);

LUCAM_API BOOL   LUCAM_EXPORT LucamQueryDisplayFrameRate                    (HANDLE hCamera, FLOAT *pValue);

LUCAM_API BOOL   LUCAM_EXPORT LucamCreateDisplayWindow                      (HANDLE hCamera, LPCSTR lpTitle, DWORD dwStyle, int x, int y, int width, int height, HWND hParent, HMENU childId);
LUCAM_API BOOL   LUCAM_EXPORT LucamAdjustDisplayWindow                      (HANDLE hCamera, LPCSTR lpTitle, int x, int y, int width, int height);
LUCAM_API BOOL   LUCAM_EXPORT LucamDestroyDisplayWindow                     (HANDLE hCamera);

LUCAM_API BOOL   LUCAM_EXPORT LucamReadRegister                             (HANDLE hCamera, LONG address, LONG numReg, LONG *pValue);
LUCAM_API BOOL   LUCAM_EXPORT LucamWriteRegister                            (HANDLE hCamera, LONG address, LONG numReg, LONG *pValue);

LUCAM_API BOOL   LUCAM_EXPORT LucamConvertFrameToGreyscale8                 (HANDLE hCamera, BYTE   *pDest, BYTE   *pSrc, ULONG width, ULONG height, ULONG pixelFormat, LUCAM_CONVERSION *pParams);
LUCAM_API BOOL   LUCAM_EXPORT LucamConvertFrameToGreyscale16                (HANDLE hCamera, USHORT *pDest, USHORT *pSrc, ULONG width, ULONG height, ULONG pixelFormat, LUCAM_CONVERSION *pParams);
LUCAM_API VOID   LUCAM_EXPORT LucamConvertBmp24ToRgb24                      (UCHAR *pFrame, ULONG width, ULONG height);

LUCAM_API BOOL   LUCAM_EXPORT LucamStreamVideoControlAVI                    (HANDLE hCamera, ULONG controlType, LPCWSTR pFileName, HWND hWnd);
LUCAM_API BOOL   LUCAM_EXPORT LucamConvertRawAVIToStdVideo                  (HANDLE hCamera, const WCHAR *pOutputFileName, const WCHAR *pInputFileName, ULONG outputType);

LUCAM_API HANDLE LUCAM_EXPORT LucamPreviewAVIOpen                           (const WCHAR *pFileName);
LUCAM_API BOOL   LUCAM_EXPORT LucamPreviewAVIClose                          (HANDLE hAVI);
LUCAM_API BOOL   LUCAM_EXPORT LucamPreviewAVIControl                        (HANDLE hAVI, ULONG previewControlType, HWND previewWindow);
LUCAM_API BOOL   LUCAM_EXPORT LucamPreviewAVIGetDuration                    (HANDLE hAVI, LONGLONG *pDurationMinutes, LONGLONG *pDurationSeconds, LONGLONG *pDurationMilliseconds, LONGLONG *pDurationMicroSeconds);
LUCAM_API BOOL   LUCAM_EXPORT LucamPreviewAVIGetFrameCount                  (HANDLE hAVI, LONGLONG *pFrameCount);
LUCAM_API BOOL   LUCAM_EXPORT LucamPreviewAVIGetFrameRate                   (HANDLE hAVI, FLOAT *pFrameRate);
LUCAM_API BOOL   LUCAM_EXPORT LucamPreviewAVISetPositionFrame               (HANDLE hAVI, LONGLONG  pPositionFrame);
LUCAM_API BOOL   LUCAM_EXPORT LucamPreviewAVIGetPositionFrame               (HANDLE hAVI, LONGLONG *pPositionFrame);
LUCAM_API BOOL   LUCAM_EXPORT LucamPreviewAVISetPositionTime                (HANDLE hAVI, LONGLONG   positionMinutes, LONGLONG   positionSeconds, LONGLONG   positionMilliSeconds, LONGLONG   positionMicroSeconds);
LUCAM_API BOOL   LUCAM_EXPORT LucamPreviewAVIGetPositionTime                (HANDLE hAVI, LONGLONG *pPositionMinutes, LONGLONG *pPositionSeconds, LONGLONG *pPositionMilliSeconds, LONGLONG *pPositionMicroSeconds);
LUCAM_API BOOL   LUCAM_EXPORT LucamPreviewAVIGetFormat                      (HANDLE hAVI, LONG *width, LONG *height, LONG *fileType, LONG *bitDepth);

LUCAM_API HANDLE LUCAM_EXPORT LucamEnableSynchronousSnapshots               (ULONG numberOfCameras, HANDLE *phCameras, LUCAM_SNAPSHOT **ppSettings);
LUCAM_API BOOL   LUCAM_EXPORT LucamTakeSynchronousSnapshots                 (HANDLE syncSnapsHandle, BYTE **ppBuffers);
LUCAM_API BOOL   LUCAM_EXPORT LucamDisableSynchronousSnapshots              (HANDLE syncSnapsHandle);

LUCAM_API BOOL   LUCAM_EXPORT LucamLedSet                                   (HANDLE hCamera, ULONG led);

LUCAM_API BOOL   LUCAM_EXPORT LucamOneShotAutoExposureEx                    (HANDLE hCamera, UCHAR target, ULONG startX, ULONG startY, ULONG width, ULONG height, FLOAT lightingPeriod /* ms, should be 8.333 in North America*/);

LUCAM_API BOOL   LUCAM_EXPORT LucamDigitalWhiteBalanceEx                    (HANDLE hCamera, FLOAT redOverGreen, FLOAT blueOverGreen, ULONG startX, ULONG startY, ULONG width, ULONG height);
LUCAM_API BOOL   LUCAM_EXPORT LucamAdjustWhiteBalanceFromSnapshot           (HANDLE hCamera, LUCAM_SNAPSHOT *pSettings, BYTE *pData, FLOAT redOverGreen, FLOAT blueOverGreen, ULONG startX, ULONG startY, ULONG width, ULONG height);
LUCAM_API BOOL   LUCAM_EXPORT LucamOneShotAutoIris                          (HANDLE hCamera, UCHAR target, ULONG startX, ULONG startY, ULONG width, ULONG height);
LUCAM_API BOOL   LUCAM_EXPORT LucamContinuousAutoExposureEnable             (HANDLE hCamera, UCHAR target, ULONG startX, ULONG startY, ULONG width, ULONG height, FLOAT lightingPeriod /* ms, should be 8.333 in North America */);
LUCAM_API BOOL   LUCAM_EXPORT LucamContinuousAutoExposureDisable            (HANDLE hCamera);

LUCAM_API BOOL   LUCAM_EXPORT LucamAutoFocusStart                           (HANDLE hCamera, ULONG startX, ULONG startY, ULONG width, ULONG height, FLOAT putZeroThere1, FLOAT putZeroThere2, FLOAT putZeroThere3, BOOL (LUCAM_EXPORT * ProgressCallback)(VOID *context, FLOAT percentageCompleted), VOID *contextForCallback);
LUCAM_API BOOL   LUCAM_EXPORT LucamAutoFocusWait                            (HANDLE hCamera, DWORD timeout);
LUCAM_API BOOL   LUCAM_EXPORT LucamAutoFocusStop                            (HANDLE hCamera);
LUCAM_API BOOL   LUCAM_EXPORT LucamAutoFocusQueryProgress                   (HANDLE hCamera, FLOAT *pPercentageCompleted);
LUCAM_API BOOL   LUCAM_EXPORT LucamInitAutoLens                             (HANDLE hCamera, BOOL force);

// Lookup table
LUCAM_API BOOL   LUCAM_EXPORT LucamSetup8bitsLUT                            (HANDLE hCamera, UCHAR *pLut, ULONG length);   // Length must be 0 or 256
LUCAM_API BOOL   LUCAM_EXPORT LucamSetup8bitsColorLUT                       (HANDLE hCamera, UCHAR *pLut, ULONG length, BOOL applyOnRed, BOOL applyOnGreen1, BOOL applyOnGreen2 , BOOL applyOnBlue);   // Length must be 0 or 256

// RS-232
LUCAM_API int    LUCAM_EXPORT LucamRs232Transmit                            (HANDLE hCamera, CHAR *pData, int length);
LUCAM_API int    LUCAM_EXPORT LucamRs232Receive                             (HANDLE hCamera, CHAR *pData, int maxLength);
LUCAM_API BOOL   LUCAM_EXPORT LucamAddRs232Callback                         (HANDLE hCamera, VOID (LUCAM_EXPORT * callback)(VOID *), VOID *context);
LUCAM_API VOID   LUCAM_EXPORT LucamRemoveRs232Callback                      (HANDLE hCamera);

// In-camera persistent buffers
LUCAM_API BOOL   LUCAM_EXPORT LucamPermanentBufferRead                      (HANDLE hCamera, UCHAR *pBuf, ULONG offset, ULONG length);
LUCAM_API BOOL   LUCAM_EXPORT LucamPermanentBufferWrite                     (HANDLE hCamera, UCHAR *pBuf, ULONG offset, ULONG length);

LUCAM_API BOOL   LUCAM_EXPORT LucamSetTimeout                               (HANDLE hCamera, BOOL still, FLOAT timeout);

LUCAM_API BOOL   LUCAM_EXPORT LucamGetTimestampFrequency                    (HANDLE hCamera, ULONGLONG* pTimestampTickFrequency);
LUCAM_API BOOL   LUCAM_EXPORT LucamGetTimestamp                             (HANDLE hCamera, ULONGLONG* pTimestamp);
LUCAM_API BOOL   LUCAM_EXPORT LucamSetTimestamp                             (HANDLE hCamera, ULONGLONG   timestamp);
LUCAM_API BOOL   LUCAM_EXPORT LucamEnableTimestamp                          (HANDLE hCamera, BOOL     enable);
LUCAM_API BOOL   LUCAM_EXPORT LucamIsTimestampEnabled                       (HANDLE hCamera, BOOL* pIsEnabled);
LUCAM_API BOOL   LUCAM_EXPORT LucamGetMetadata                              (HANDLE hCamera, BYTE* pImageBuffer, LUCAM_IMAGE_FORMAT* pFormat, ULONG metaDataIndex, ULONGLONG* pMetaData);
LUCAM_API BOOL   LUCAM_EXPORT LucamGetDualGainFactor                        (HANDLE hCamera, BYTE *pValue);
LUCAM_API BOOL   LUCAM_EXPORT LucamSetDualGainFactor                        (HANDLE hCamera, BYTE value);
LUCAM_API BOOL   LUCAM_EXPORT LucamGetPiecewiseLinearResponseParameters     (HANDLE hCamera, BYTE *pKneepoint, ULONG *pGainDivider);
LUCAM_API BOOL   LUCAM_EXPORT LucamSetPiecewiseLinearResponseParameters     (HANDLE hCamera, BYTE kneepoint, ULONG gainDivider);
LUCAM_API BOOL   LUCAM_EXPORT LucamGetHdrMode                               (HANDLE hCamera, BYTE *pValue);
LUCAM_API BOOL   LUCAM_EXPORT LucamSetHdrMode                               (HANDLE hCamera, BYTE value);

LUCAM_API PVOID  LUCAM_EXPORT LucamRegisterEventNotification                (HANDLE hCamera, DWORD eventId, HANDLE hEvent);
LUCAM_API BOOL   LUCAM_EXPORT LucamUnregisterEventNotification              (HANDLE hCamera, PVOID pEventInformation);

// On-host Tap Correction
LUCAM_API BOOL   LUCAM_EXPORT LucamPerformMonoGridCorrection                (HANDLE hCamera, BYTE *pFrame, const LUCAM_IMAGE_FORMAT *pImageFormat);

LUCAM_API BOOL   LUCAM_EXPORT LucamGetImageIntensity                        (HANDLE hCamera, BYTE *pFrame, LUCAM_IMAGE_FORMAT *pImageFormat , ULONG startX, ULONG startY, ULONG width, ULONG height, FLOAT *pIntensity, FLOAT *pRedIntensity, FLOAT *pGreen1Intensity, FLOAT *pGreen2Intensity, FLOAT *pBlueIntensity);
LUCAM_API BOOL   LUCAM_EXPORT LucamAutoRoiGet                               (HANDLE hCamera, LONG *pStartX, LONG *pStartY, LONG *pWidth, LONG *pHeight);
LUCAM_API BOOL   LUCAM_EXPORT LucamAutoRoiSet                               (HANDLE hCamera, LONG   startX, LONG   startY, LONG   width, LONG   height);
LUCAM_API BOOL   LUCAM_EXPORT LucamDataLsbAlign                             (HANDLE hCamera, LUCAM_IMAGE_FORMAT *pLif, UCHAR *pData);
LUCAM_API BOOL   LUCAM_EXPORT LucamEnableInterfacePowerSpecViolation        (HANDLE hCamera, BOOL     enable);
LUCAM_API BOOL   LUCAM_EXPORT LucamIsInterfacePowerSpecViolationEnabled     (HANDLE hCamera, BOOL* pIsEnabled);
LUCAM_API BOOL   LUCAM_EXPORT LucamSelectExternInterface                    (ULONG externInterface); // The API defaults to USB

LUCAM_API BOOL   LUCAM_EXPORT LgcamGetIPConfiguration                       (ULONG index, UCHAR cameraMac[6], LGCAM_IP_CONFIGURATION *pCameraConfiguration, UCHAR hostMac[6], LGCAM_IP_CONFIGURATION *pHostConfiguration);
LUCAM_API BOOL   LUCAM_EXPORT LgcamSetIPConfiguration                       (ULONG index, LGCAM_IP_CONFIGURATION *pCameraConfiguration);


//****************************************************************************************************************
//****************************************************************************************************************
//****************************************************************************************************************
//****************************************************************************************************************
//****************************************************************************************************************
//****************************************************************************************************************
//****************************************************************************************************************