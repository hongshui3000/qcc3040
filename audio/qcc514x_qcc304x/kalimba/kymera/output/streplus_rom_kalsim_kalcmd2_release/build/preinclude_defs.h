#define AACDEC_ADTS_FILE_TYPE_SUPPORTED
#define AACDEC_LATM_FILE_TYPE_SUPPORTED
#define ADDR_PER_WORD 4
#define AMBER_STYLE_INT_CTRL
#define APTXA_DYNAMIC_MEMORY
#define APTX_ENABLE_MERGED_HD
#define APTX_LOW_RAM
#define APTX_USE_EXTERNAL_MEMORY
#define AUDIO_LOG_BUF_SIZE 512
#define AUDIO_SOURCE_ENABLE_TOA_METADATA_BY_DEFAULT
#define BAC32
#define BAC_REMOTE_WINDOW_SIZE 0x100000
#define BAC_REMOTE_WINDOW_START_ADDR 0x800000
#define BASE_REGISTER_MODE
#define BIGINT_64BIT_EXTERNALLY_DEFINED
#define BIGINT_64BIT_INTRINSIC
#define BIGINT_64BIT_LITTLE_ENDIAN
#define BLD_PRIVATE
#define BROKEN_SUBWORD_WRITE_IN_BAC_WINDOW
#define CAP_DOWNLOAD_DEBUG_VERSION 1
#define CBOPS_DEBUG
#define CBUFFER_RW_ADDR_DEBUG
#define CCP_DONT_INCLUDE_TIMED_EVENT_TIMED_EVENT_H
#define CHECK_SP_FOR_UNEXPECTED_RESTART
#define CHIP_STREPLUS
#define CHIP_BASE_CRESCENDO
#define CHIP_BASE_HYDRA
#define CHIP_BUILD_VER CHIP_MINOR_VERSION_d00
#define CHIP_BUILD_VER_LATEST CHIP_MINOR_VERSION_d01
#define CHIP_HAS_AUX_PLL_V3
#define CHIP_HAS_BANKED_BUS_INTERRUPTS 0
#define CHIP_HAS_BIGENDIAN_TX_BUS 0
#define CHIP_HAS_BUS_INTERRUPT_GENERATE_HW 1
#define CHIP_HAS_BUS_MESSAGE_STATUS_REGISTER 1
#define CHIP_HAS_CSR_BT 0
#define CHIP_HAS_DDS_DIVIDER_ENABLE_WITH_BANK 1
#define CHIP_HAS_DEDICATED_APPS_QSPI_TRB_QUEUE 1
#define CHIP_HAS_EXCEPTION_PC 1
#define CHIP_HAS_EXTENDED_BAC_VALIDITY_WINDOW 1
#define CHIP_HAS_HIFI_ADC_ON_KCODEC_CHANNELS12 1
#define CHIP_HAS_MPU_KEYHOLE
#define CHIP_HAS_PCM_INTERNAL_CLK_MODE_CONFIG
#define CHIP_HAS_PCM_PIO_SEL 1
#define CHIP_HAS_RAM_DS_CONTROLS 1
#define CHIP_HAS_SEPARATE_DDS_DOMAIN
#define CHIP_HAS_SEPARATE_INTERRUPT_ENABLE_AND_PRIO_REGS 1
#define CHIP_HAS_SEPARATE_PCM_I2S_CLKGEN_ENABLES 1
#define CHIP_HAS_SHALLOW_SLEEP_CLOCK_CONT_SLOWING 0
#define CHIP_HAS_SHALLOW_SLEEP_REGISTERS 1
#define CHIP_HAS_SINGLE_AUDIO_SAMPLE_FORMAT_REGISTER
#define CHIP_HAS_SWITCHABLE_NVMEM
#define CHIP_MAX_CLOCK 120
#define CHIP_MINOR_VERSION_d00 0
#define CHIP_MINOR_VERSION_d01 2
#define CHIP_MINOR_VERSION_dev CHIP_MINOR_VERSION_d01
#define CHIP_MINOR_VERSION_v01 CHIP_MINOR_VERSION_d00
#define CHIP_MINOR_VERSION_v02 CHIP_MINOR_VERSION_d01
#define CHIP_NEEDS_RATE_CHANGE_ON_KCODEC_CLK
#define CHIP_NUMBER_OF_BUS_INTERRUPTS 8
#define CHIP_NUM_CORES 2
#define CHIP_SPDIF_RX_CLK_DIV_RATIO 1
#define CLK_MGR_CARES_ABOUT_DEEP_SLEEP
#define CLK_MGR_CLK_CAN_BE_MAPPED
#define CVC_FBC_FILTER_LENGTH_MAX 0.008
#define CVC_FBC_REFDLY_MAX 64
#define CVC_LOW_RESOURCE_MODE
#define CVSD_CODEC_SOFTWARE
#define DATAFORMAT_32
#define DAWTH 32
#define DAWTH_MASK 0xFFFFFFFF
#define DEBUG_STACK_OVERFLOW
#define DEFAULT_TAG_ALLOC_THRESHOLD 150
#define DETAILED_PROFILER_ON
#define DM2_RAM_BASE 0xFFF00000u
#define DM_NVMEM_WINDOW_SIZE 0x800000
#define DM_NVMEM_WINDOW_START 0xF8000000U
#define DM_RAM_BANK_SIZE 0x8000
#define DM_ROM_WINDOW_START 0xF8000000
#define DONT_GENERATE_MCLK_OUTPUT_FROM_SUBSYSTEM_ROOT_CLOCK
#define DORM_MODULE_PRESENT
#define DSP_ID 0x4B
#define DUALCORE_EXTMEM_UNSUPPORTED
#define ENABLE_FLUSH_WRITE_POINTER_FOR_SPDIF_RX
#define ENABLE_FORCE_ENACTING_BY_AEC_REFERENCE
#define ENABLE_SPEECH
#define ESCO_SUPPORT_ERRORMASK
#define EXTERNAL_FFT_SCRATCH_MEMORY
#define EXTERNAL_MCLK_IN_PIO 31
#define EXT_RAM_READ_WINDOW 3
#define EXT_RAM_WRITE_WINDOW 4
#define FILESERV_MMU_BUFFER_SIZE 256
#define FILESERV_MODULE_PRESENT
#define FILE_MGR_MAX_NUMBER_OF_FILES 2
#define FIRMWARE_BUILD_SHARE_TABLES_APTX_APTXHD
#define FIRMWARE_TALKING_TO_KALCMD
#define FORCE_STACK_SIZE_WORDS 0x3C0
#define HAVE_15BIT_BAC_SHIFT
#define HAVE_24BIT_AUDIO
#define HAVE_ADAPTIVE_ROUTING
#define HAVE_AUDIO_MMU_POINTERS_WRITEBACK_FIX
#define HAVE_CACHE_EXECUTE_EXCEPTION
#define HAVE_CLOCK_STOP_WIND_DOWN_SEQUENCE
#define HAVE_CONTINUOUS_BUFFERING
#define HAVE_CRESCENDO_AUDIO
#define HAVE_CRESCENDO_AUDIO_MUX
#define HAVE_CRESCENDO_STREAM_MONITOR
#define HAVE_DMIC_LOWPOWER_MODE_CLK
#define HAVE_HW_MEMORY_EXCEPTIONS
#define HAVE_MIC_BIAS_0
#define HAVE_MIC_BIAS_CONTROL
#define HAVE_MIC_BIAS_HARDWARE
#define HAVE_PCM_DDS_GENERATED_CLK_GATED_BY_AUDIO_ENABLES
#define HAVE_SIDE_TONE_HARDWARE
#define HAVE_SPDIF_INDEPENDENT_OF_PCM_I2S
#define HEAP_DEBUG
#define HEAP_MAX_BOUNDARY_GUARD 0x40
#define HYDRA_SSSM_IS_A_SCHEDULER_TASK
#define HYDRA_SW_PATCH_SIMPLE
#define INCLUDE_PATCHES
#define INSTALL_24_BIT_CODEC
#define INSTALL_24_BIT_DMIC
#define INSTALL_24_BIT_I2S
#define INSTALL_24_BIT_PCM
#define INSTALL_24_BIT_SPDIF
#define INSTALL_32BIT_SLOT
#define INSTALL_A2DP
#define INSTALL_ADC
#define INSTALL_AEC_REFERENCE_SPKR_TTP
#define INSTALL_AUDIO_ADC_IIR_FILTER
#define INSTALL_AUDIO_DATA_SERVICE
#define INSTALL_AUDIO_DATA_SERVICE_TESTER
#define INSTALL_AUDIO_INTERFACE_I2S
#define INSTALL_AUDIO_INTERFACE_PCM
#define INSTALL_AUDIO_INTERFACE_SPDIF
#define INSTALL_AUDIO_LOG
#define INSTALL_AUDIO_MODULE
#define INSTALL_BORROWED_CLOCK_MODE_SUPPORT
#define INSTALL_CAP_DOWNLOAD_MGR
#define INSTALL_CBUFFER_EX
#define INSTALL_CLK_MGR
#define INSTALL_CODEC
#define INSTALL_CVC_RECEIVE_SUPPORT_METADATA
#define INSTALL_DAC
#define INSTALL_DELEGATE_RATE_ADJUST_SUPPORT
#define INSTALL_DIGITAL_MIC
#define INSTALL_DIRECT_FLASH_ACCESS
#define INSTALL_DM_MEMORY_PROFILING
#define INSTALL_EXTERNAL_MEM
#define INSTALL_FILE
#define INSTALL_FILE_MGR
#define INSTALL_HYDRA
#define INSTALL_HYDRA_TXBUS_RD_TIMING
#define INSTALL_I2S_AUTO_CROP
#define INSTALL_ISO_CHANNELS
#define INSTALL_LINKER_GENERATES_CHECKSUM
#define INSTALL_MCLK_SUPPORT
#define INSTALL_METADATA
#define INSTALL_MIB
#define INSTALL_OBPM_ADAPTOR
#define INSTALL_OPERATOR_RATE_ADJUST
#define INSTALL_OP_CLIENT
#define INSTALL_OP_CLIENT_ADAPTOR
#define INSTALL_PLC100
#define INSTALL_PM_HEAP_SHARE
#define INSTALL_PS_FOR_ACCMD
#define INSTALL_SCO
#define INSTALL_SCO_APTX
#define INSTALL_SCO_RX_TOA_METADATA_GENERATE
#define INSTALL_SPDIF
#define INSTALL_SPDIF_HW_RATE_DETECT
#define INSTALL_SPDIF_RATE_DETECT
#define INSTALL_SPDIF_RX_CHNL_STS_SUPPORT
#define INSTALL_SPI_INTERFACE
#define INSTALL_SUBSERV_STATUS
#define INSTALL_TIMESTAMPED_ENDPOINT
#define INSTALL_TTP
#define INSTALL_UNCONDITIONAL_LOG_LEVEL_1
#define INSTALL_UNCONDITIONAL_LOG_LEVEL_2
#define INSTALL_USB_AUDIO
#define INTERRUPT_PROFILER_ON
#define IO_DEBUG
#define K32
#define KALASM3
#define KALIMBA_BUILD
#define KALIMBA_OPT
#define KAL_ARCH4
#define KICK_KEEP_BUFFERS_FULL
#define KYMERA
#define LOG2_ADDR_PER_WORD 2
#define LOG2_PC_PER_INSTRUCTION 2
#define MATH_FAST_PM PM_KEEP
#define MATH_OPTIONAL_FAST_PM PM_KEEP
#define MATH_PM PM_KEEP
#define MAXINT 0x7FFFFFFF
#define MAX_POOL_BLOCKS_PER_INSTANCE 128
#define METADATA_DEBUG_TRANSPORT 2
#define METADATA_DEBUG_TRANSPORT_FAULT
#define METADATA_USE_PMALLOC
#define MININT 0x80000000
#define NONPERIODIC_LICENCE_CHECKS
#define NONSECURE_PROCESSING
#define NO_ZEAGLE_RX
#define NUMBER_BAC_STREAM_MONITORS 8
#define NUMBER_CODEC_INSTANCES 1
#define NUMBER_DIGITAL_MICS 6
#define NUMBER_DM_BANKS 14
#define NUMBER_HW_PATCHES 32
#define NUMBER_I2S_INSTANCES 4
#define NUMBER_INTERRUPT_SOURCES 32
#define NUMBER_OF_PIOS 72
#define NUMBER_PCM_INSTANCES 4
#define NUMBER_PM_BANKS 14
#define NUMBER_SPDIF_INSTANCES 2
#define NUMBER_VOICE_SLOTS 8
#define NUM_INT_SOURCES_PER_PRIORITY 32
#define NUM_USED_INTERRUPT_LEVELS 3
#define NUM_USED_TASK_PRIORITIES 1
#define OPMGR_SYNC_KICKED_IMPLEMENTATION OPMGR_SYNC_KICKED_BASIC
#define OPMGR_SYNC_STRICT_TIMER_IMPLEMENTATION OPMGR_SYNC_STRICT_TIMER_LEGACY
#define OS_OXYGOS
#define P0 0
#define PATCH_ADDR_MAX 0x0400bfff
#define PATCH_LIBS
#define PCM_DISABLE_INTERNAL_CLK_MODE
#define PCM_INTERNAL_CLK_CNT_LIMIT 1250
#define PCM_INTERNAL_CLK_HIGH_LIMIT 20
#define PC_PER_INSTRUCTION 4
#define PMALLOC_DYNAMIC_POOLS
#define PM_DOWNLOAD_START_VIRTUAL_ADDR 0x4200000UL
#define PM_DOWNLOAD_VIRTUAL_ADDR_MASK 0x7FFFFFFUL
#define PM_RAM_CACHE_BANK_SIZE_WORDS 0x200
#define PM_RAM_END_ADDRESS 0x0401C000
#define PM_RAM_FREE_END 0x0401B7FF
#define PM_RAM_FREE_START 0x04000800
#define PM_RAM_P1_CACHE_START_ADDRESS 0x0401B800
#define PM_RAM_SIZE_WORDS 0x7000
#define PM_RAM_START_ADDRESS 0x04000000
#define PM_RAM_WINDOW 0x00100000
#define PM_RAM_WINDOW_CACHE_START_ADDRESS_OFFSET 0x0
#define PM_ROM_WINDOW_START 0x00000000
#define POOL_OVERFLOW_TO_HEAP
#define PRESERVED_MODULE_PRESENT
#define PRESERVE_BLOCK_WORDS 9
#define PROFILER_ON
#define PROFILE_ENABLED_AT_STARTUP
#define RATE_MATCH_ADAPT_DEFAULT_NONE
#define RESERVED_STATIC_BLOCK_SIZE 20
#define RUNNING_ON_KALSIM
#define SCHEDULER_WITHOUT_RUNLEVELS
#define SCHED_NO_EXTERNAL_MSG_SUPPORT
#define SCO_DEBUG
#define SCO_DEBUG_STATUS_COUNTERS
#define SINK_WRAP_POST_MORTEM
#define SLOW_BLOCK_SIZE_DETECTION
#define SRA_HIGH_QUALITY_COEFFS
#define STREAM_CONNECT_FAULT_CODE
#define SUBMSG_LOCAL_DELIVERY
#define SUBMSG_PANIC_ON_FAILURE
#define SUBSYSTEM_AUDIO
#define SUPPORT_TRB_LOG_MESSAGE
#define SYNCED_SOURCES_CHECK_SPACE
#define THIRD_PARTY_SECURITY_SUPPORT
#define TIMED_PLAYBACK_MODE
#define TODO_AEC_REFERENCE_TTP
#define TODO_CRESCENDO
#define TODO_CRESCENDO_A2DP_RM_TUNING
#define TODO_CRESCENDO_CHIPVER_CHECKING
#define TODO_CRESCENDO_CVC_TEST
#define TODO_CRESCENDO_D01_AUDIO
#define TODO_CRESCENDO_D01_CLKGEN
#define TODO_CRESCENDO_PS_KEYS
#define TODO_CRESCENDO_STREAMS_SAMPLE_SIZE_SUPPORT
#define TODO_MITIGATE_CBOPS_DRIFT_IN_NON_TTP_USE_CASE
#define TTP_GEN_DEBUG
#define TTP_PLOTTER
#define USE_ACCMD
#define USE_CMFB
#define USE_KAL_INTRINSICS
#define USE_PACKER_CFG0
#define USE_PACKER_ESCO
#define USE_PLC_MSBC
#define USE_SHARE_MEM
#define USE_UNPACKER_CFG0
#define USE_UNPACKER_ESCO
#define VOLUME_CONTROL_AUX_TTP_SUPPORT
#define WBS_DECOUPLED
#define WORD_ADDRESS_MASK 0xFFFFFFFC
#define __KALIMBA32__
#define __KALIMBA__
#define INSTALL_OPERATOR_AAC_DECODE
#define INSTALL_OPERATOR_AEC_REFERENCE
#define INSTALL_OPERATOR_APTX_ADAPTIVE_DECODE
#define INSTALL_OPERATOR_APTX_ADAPTIVE_DEMUX
#define INSTALL_OPERATOR_APTX_CLASSIC_DECODE
#define INSTALL_OPERATOR_APTX_CLASSIC_DEMUX
#define INSTALL_OPERATOR_APTX_CLASSIC_MONO_DECODER
#define INSTALL_OPERATOR_APTX_CLASSIC_MONO_DECODER_NO_AUTOSYNC
#define INSTALL_OPERATOR_APTXHD_DECODE
#define INSTALL_OPERATOR_APTXHD_MONO_DECODER
#define INSTALL_OPERATOR_APTXHD_MONO_DECODER_NO_AUTOSYNC
#define INSTALL_OPERATOR_APTX_LOW_LATENCY_DECODE
#define INSTALL_OPERATOR_ASYNC_WBS_DEC
#define INSTALL_OPERATOR_ASYNC_WBS_ENC
#define INSTALL_OPERATOR_BASIC_PASS
#define INSTALL_OPERATOR_CHANNEL_MIXER
#define INSTALL_OPERATOR_COMPANDER
#define INSTALL_OPERATOR_CONVERT_FROM_AUDIO
#define INSTALL_OPERATOR_CONVERT_TO_AUDIO
#define INSTALL_OPERATOR_CVC_FBC
#define INSTALL_OPERATOR_CVC_HEADSET_BINAURAL
#define INSTALL_OPERATOR_CVC_HEADSET_1MIC
#define INSTALL_OPERATOR_CVC_HEADSET_2MIC_MONO
#define INSTALL_OPERATOR_CVC_HEADSET_2MIC_MONO_VA_BARGEIN
#define INSTALL_OPERATOR_CVC_HEADSET_2MIC_MONO_VA_WAKEON
#define INSTALL_OPERATOR_CVC_32K
#define INSTALL_OPERATOR_CVC_RECEIVE
#define INSTALL_OPERATOR_CVC_SPEAKER_1MIC
#define INSTALL_OPERATOR_CVC_SPEAKER_2MIC
#define INSTALL_OPERATOR_DBE
#define INSTALL_OPERATOR_IIR_RESAMPLER
#define INSTALL_OPERATOR_MIXER
#define INSTALL_OPERATOR_OPUS_CELT_ENCODE
#define INSTALL_OPERATOR_PEQ
#define INSTALL_OPERATOR_QVA
#define INSTALL_OPERATOR_RATE_ADJUST
#define INSTALL_OPERATOR_RESAMPLER
#define INSTALL_OPERATOR_RINGTONE_GENERATOR
#define INSTALL_OPERATOR_RTP_DECODE
#define INSTALL_OPERATOR_SBC_DECODE
#define INSTALL_OPERATOR_SBC_ENCODE
#define INSTALL_OPERATOR_SCO_RCV
#define INSTALL_OPERATOR_SCO_SEND
#define INSTALL_OPERATOR_SOURCE_SYNC
#define INSTALL_OPERATOR_SPLITTER
#define INSTALL_OPERATOR_SWBS_DEC
#define INSTALL_OPERATOR_SWBS_ENC
#define INSTALL_OPERATOR_SWITCHED_PASSTHROUGH_CONSUMER
#define INSTALL_OPERATOR_TTP_PASS
#define INSTALL_OPERATOR_USB_AUDIO
#define INSTALL_OPERATOR_VAD
#define INSTALL_OPERATOR_VA_GRAPH_MANAGER
#define INSTALL_OPERATOR_VOLUME
#define INSTALL_OPERATOR_VSE
#define INSTALL_OPERATOR_WBS_DEC
#define INSTALL_OPERATOR_WBS_ENC
#define INSTALL_OPERATOR_XOVER
