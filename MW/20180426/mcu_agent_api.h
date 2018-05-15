/**
  *  Copyright (C), 2015, HASE. All rights reserved.
  *  @file    mcu_agent_api.h
  *  @brief  MCU agent API 
  *  @author  LI J Z
  *  @version 1.6
  *  @date    2015-08-21
  *  @history 
  */

#ifndef _MCU_AGENT_API_H_
#define _MCU_AGENT_API_H_

 
#define MCU_SEND_START_BYTE     0xE0
#define MCU_RECV_START_BYTE     0x24


/**
  * @addtogroup  Mcu_Agent_MSG
  * @{
  */
  
/** 
  *  @enums 
  *  @brief  MCU  返回信息识别码定义
  */
typedef enum {
    MCU_MSG_RET_MB_VERSION = 0x03,      /**< 返回主板版本信息，返回数据参考struct MB_VERSION_INFO 相关定义。@see MB_VERSION_INFO*/  
    MCU_MSG_RET_HARD_KEY = 0x04,        /**< 返回按键信息，返回数据参考enum  HARD_KEY_ID 相关定义。@see  HARD_KEY_ID*/ 
    MCU_MSG_SET_TOUCH = 0x05,           /**< 返回屏幕触摸坐标信息，返回数据参考struct TOUCH_INFO 相关定义。@see TOUCH_INFO*/ 
    MCU_MSG_SET_ENGINEER_MODE = 0x06,   /**< 设置工程诊断模式进入或退出，返回数据参考enum ENGINEER_MODE_ID 相关定义。@see ENGINEER_MODE_ID*/ 
    MCU_MSG_RET_POWEROFF_TIMER_DISP_STATUS = 0x08,  /**< 返回关机时，时钟显示状态，返回数据参考enum DISP_STATUS_ID 相关定义。@see DISP_STATUS_ID */
    MCU_MSG_RET_SCREEN_SAVE_MODE = 0x09,            /**< 返回省电模式时屏幕保存状态，返回数据参考enum SCREEN_SAVE_MODE_ID 相关定义。@see SCREEN_SAVE_MODE_ID*/
    MCU_MSG_RET_ALINE = 0x0E,                       /**< 返回心跳回应，无返回数据。*/
    MCU_MSG_GET_VERSION_INFO = 0x0F,                /**< 获取HMI/BT 的版本信息，返回数据参考enum VERSION_TYPE_ID 相关定义。@see VERSION_TYPE_ID*/
    MCU_MSG_RET_CUR_AUDIO_POWER_STATUS = 0x11,      /**< 返回主板开关机状态，返回数据参考struct POWER_INFO 相关定义。@see POWER_INFO*/
    MCU_MSG_RET_RTC_CLOCK_INFO = 0x13,              /**< 返回RTC 时间信息，返回数据参考struct RTC_MSG 相关定义。@see RTC_MSG*/
    MCU_MSG_RET_GPS_CLOCK_INFO = 0x15,              /**< 返回GPS 时间信息，返回数据参考struct CLOCK_MSG 相关定义。@see CLOCK_MSG*/
    MCU_MSG_RET_SETUP_PARAM_INFO = 0x1F,            /**< 返回设置菜单中的相关参数信息，返回数据参考struct SETUP_PARAM_INFO 相关定义。@see SETUP_PARAM_INFO*/
    
    MCU_MSG_RET_CUR_AUDIO_SOURCE = 0x21,            /**< 返回音频源，返回数据参考enum AUDIO_SOURCE_ID 相关定义。@see AUDIO_SOURCE_ID*/
    MCU_MSG_RET_AUDIO_SETTING_INFO = 0x23,          /**< 返回音频参数设置信息，返回数据参考struct AUDIO_SETTING_INFO 相关定义。@see AUDIO_SETTING_INFO*/
    MCU_MSG_RET_AUDIO_AUX_GAIN_MODE = 0x25,	        /**< 返回AUX 输入增益参数，返回数据参考enum AUDIO_AUX_GAIN_ID 相关定义。@see AUDIO_AUX_GAIN_ID*/
    MCU_MSG_RET_AUDIO_BEEP_STATUS = 0x27,           /**< 返回Beep开关状态，返回数据参考enum BEEP_STATUS_ID 相关定义。@see BEEP_STATUS_ID*/
    MCU_MSG_RET_AUDIO_SPEED_VOLUME_MODE = 0x29,     /**< 返回车速音量连动参数，返回数据参考enum AUDIO_SPEED_VOLUME_ID  相关定义。@see AUDIO_SPEED_VOLUME_ID*/
    MCU_MSG_RET_AUDIO_SPEED = 0x2A,                 /**< 返回车辆速度，返回数据为unsigned short 。*/

    MCU_MSG_RET_AUDIO_DEVICE_PLUG_STATUS = 0x30,    /**< 返回外设状态，返回数据参考enum DEVICE_PLUG_STATUS_ID  相关定义。@see DEVICE_PLUG_STATUS_ID*/
    MCU_MSG_RET_AUDIO_VOLUME_INFO = 0x31,           /**< 返回音量信息，返回数据参考struct AUDIO_VOLUME_INFO  相关定义。@see AUDIO_VOLUME_INFO*/
    MCU_MSG_RET_AUDIO_POPUP_INFO = 0x32,            /**< 返回DISK/AUX弹出信息，返回数据参考enum POPUP_INFO_ID  相关定义。@see POPUP_INFO_ID*/

    MCU_MSG_RET_RADIO_COLLECTED_INFO = 0x4C,        /**< 返回收藏电台信息，返回数据参考struct RADIO_COLLECTED_INFO 相关定义。@see RADIO_COLLECTED_INFO*/
    MCU_MSG_RET_RADIO_NOTIFY = 0x50,                /**< 返回当前波段、状态、预置台、频率信息，返回数据参考struct RADIO_NOTIFY  相关定义。@see RADIO_NOTIFY*/
    MCU_MSG_RET_RADIO_PRESET_INFO = 0x51,           /**< 返回波段对应预存电台信息，返回数据参考struct RADIO_PRESET_INFO  相关定义。@see RADIO_PRESET_INFO*/

	MCU_MSG_RET_IGN_ON_OFF_STATUS = 0x7F,           /**< 返回IGN_ON_OF状态，返回数据参考struct IGN_ON_OFF_INFO 相关定义。@see IGN_ON_OFF_INFO*/
	
    MCU_MSG_RET_COREBOARD_RESUME_INFO = 0x81,       /**< 返回核心板恢复保存状态信息，返回数据参考struct COREBOARD_RESUME_INFO  相关定义。@see COREBOARD_RESUME_INFO*/
    MCU_MSG_RET_BLUETOOTH_STATUS = 0x90,            /**< 返回当前蓝牙状态，返回数据参考struct BLUETOOTH_STATUS_INFO  相关定义。@see BLUETOOTH_STATUS_INFO*/

    MCU_MSG_RET_TFT_VIDEO_SOURCE = 0xA1,            /**< 返回视频输入信号源，返回数据参考struct VIDEO_SOURCE_INFO  相关定义。@see VIDEO_SOURCE_INFO*/
    MCU_MSG_RET_TFT_LANGUAGE = 0xA3,                /**< 返回当前语言状态，返回数据参考enum LANGUAGE_ID  相关定义。@see LANGUAGE_ID*/
    MCU_MSG_RET_TFT_ILL_MODE = 0xA5,                /**< 返回白天黑夜检测模式，返回数据参考enum ILL_MODE_ID  相关定义。@see ILL_MODE_ID*/
    MCU_MSG_RET_TFT_BACKLIGHT_STATUS = 0xA7,        /**< 返回背光开关状态，返回数据参考enum BACKLIGHT_STATUS_ID  相关定义。@see BACKLIGHT_STATUS_ID*/
    MCU_MSG_RET_TFT_BRIGHTNESS_STATUS = 0xA9,       /**< 返回亮度值，返回数据为unsigned char 。*/
    MCU_MSG_RET_TFT_CONTRAST_STATUS = 0xAB,         /**< 返回对比度值，返回数据为unsigned char 。*/
    
    MCU_MSG_RET_AVM_SETTING_INFO = 0xB2,            /**< 返回AVM设置参数信息，返回数据参考struct AVM_SETTING_INFO  相关定义。@see AVM_SETTING_INFO*/
    MCU_MSG_RET_MHL_SIGNAL_DET = 0xC0,              /**< 返回手机连接状态，返回数据参考enum MHL_SIGNAL_STATUS_ID  相关定义。@see MHL_SIGNAL_STATUS_ID*/

    MCU_MSG_RET_AVM_DATA_INFO = 0xF0,               /**< 返回接收到的AVM数据，返回数据参考struct AVM_DATA_INFO  相关定义。@see AVM_DATA_INFO*/

    MCU_MSG_RET_ENHOST_CAN = 0xF6,                  /**< 返回L5项目CAN相关信息,仅为红旗L5增加 */
    MCU_MSG_RET_FCC_CAN = 0xF7,                     /**< 返回L5项目FCC CAN相关信息,仅为红旗L5增加 */
    MCU_MSG_RET_RCC_CAN = 0xF8,                     /**< 返回L5项目RCC CAN相关信息,仅为红旗L5增加 */
    
    MCU_MSG_RET_MCAN_INFO = 0xFD,                   /**< 返回MCAN 信息，返回数据参考struct MCAN_INFO  相关定义。@see MCAN_INFO*/
    MCU_MSG_RET_HVAC_INFO = 0xFA,                 /**< 返回空调状态信息，返回数据参考struct HVAC_INFO 相关定义。@see HVAC_INFO*/
    MCU_MSG_RET_HVAC_DIAG_INFO = 0xFB,              /**< 返回空调诊断信息，返回数据参考struct HVAC_DIAG_INFO  相关定义。@see HVAC_DIAG_INFO*/
    MCU_MSG_RET_IT_COMMANDER_INFO = 0xFC,           /**< 返回多功能旋钮按键信息，返回数据参考struct IT_COMMANDER_INFO  相关定义。@see IT_COMMANDER_INFO*/
    MCU_MSG_MAX_ID = 0xFF,
}MCU_MSG_ID;

/** 
  *  @struct PACKET_MSG
  *  @brief 接收数据包信息
  */ 
typedef struct {
    MCU_MSG_ID mcu_msg_id;      /**< MCU 消息识别码，参考MCU_MSG_ID  相关定义。@:: MCU_MSG_ID*/
    unsigned char size;         /**< 数据包内容data 有效字节大小*/
    unsigned char data[256];    /**< 数据包内容*/
}PACKET_MSG;
/**@}*/
  
/**
  * @addtogroup  Mcu_Agent_Typedef
  * @{
  */
  
/** 
  *  @struct MB_VERSION_INFO
  *  @brief 主板版本信息
  */ 
typedef struct {
    unsigned short MB_version;
    unsigned short MB_checksum;
    char CD_version[6];
    unsigned long AVM_version;
    unsigned char AVM_Vin[6];
}MB_VERSION_INFO;

/** 
  *  @enums
  *  @brief 按键信息定义
  */
typedef enum {
    HARD_KEY_SWC_VOL_UP = 0x01,
    HARD_KEY_SWC_VOL_DOWN = 0x02,
    HARD_KEY_SWC_PREVIOUS =0x03,
    HARD_KEY_SWC_NEXT = 0x04,
    HARD_KEY_SWC_SOURCE = 0x05,
    HARD_KEY_SWC_ANSWER = 0x06,
    HARD_KEY_SWC_HANGUP = 0x07,
    HARD_KEY_SWC_ENTER = 0x08,
    HARD_KEY_SWC_BACK = 0x09,
    HARD_KEY_ROT_VOL_UP = 0x10,
    HARD_KEY_ROT_VOL_DOWN = 0x11,
    HARD_KEY_POWER = 0x12,
    HARD_KEY_TUNE_UP = 0x13,
    HARD_KEY_TUNE_DOWN = 0x14,
    HARD_KEY_TUNE_PUSH = 015,
    HARD_KEY_CAMERA = 0x16,
    HARD_KEY_AUDIO = 0x17,
    HARD_KEY_CD_AUX = 0x18,
    HARD_KEY_FM_AM = 0x19,
    HARD_KEY_USB = 0x1A,
    HARD_KEY_PHONE = 0x1B,
    HARD_KEY_PRESET1 = 0x1C,
    HARD_KEY_PRESET2 = 0x1D,
    HARD_KEY_PRESET3 = 0x1E,
    HARD_KEY_PRESET4 = 0x1F,
    HARD_KEY_PRESET5 = 0x20,
    HARD_KEY_PRESET6 = 0x21,
    HARD_KEY_SCAN = 0x30,
    HARD_KEY_MENU = 0x31,
    HARD_KEY_BACK = 0x32,
    HARD_KEY_SEEK_UP = 0x33,
    HARD_KEY_SEEK_DOWN = 0x34,
    HARD_KEY_HOME = 0x35,
    HARD_KEY_EJECT = 0x40,
    HARD_KEY_PURPOSE_AUDIO = 0x50,
    HARD_KEY_PURPOSE_USB = 0x51,
    HARD_KEY_PURPOSE_PHONE = 0x52,
}HARD_KEY_ID;

/** 
  *  @enums
  *  @brief 触摸类型定义
  */
typedef enum {
    TOUCH_TYPE_DOWN = 0x00,
    TOUCH_TYPE_UP,
    TOUCH_TYPE_MAX_ID,
}TOUCH_TYPE_ID;

/** 
  *  @struct TOUCH_INFO
  *  @brief 屏幕触摸坐标信息
  */
typedef struct {
    unsigned short x;
    unsigned short y;
    TOUCH_TYPE_ID type;
}TOUCH_INFO;

/** 
  *  @enums
  *  @brief 工程诊断模式定义
  */
typedef enum {
    ENGINEER_MODE_EXIT = 0x00,
    ENGINEER_MODE_ENTRY,
    ENGINEER_MODE_MAX_ID,
}ENGINEER_MODE_ID;

/** 
  *  @enums
  *  @brief  beep 声音调状态定义
  */
typedef enum {
    BEEP_TONE_NORMAL = 0x00,
    BEEP_TONE_WARNING,
    BEEP_TONE_ERROR,
    BEEP_TONE_MAX_ID,
}BEEP_TONE_ID;

/** 
  *  @enums
  *  @brief  关机时，时钟显示状态定义
  */
typedef enum {
    DISP_STATUS_OFF = 0x00,
    DISP_STATUS_ON,
    DISP_STATUS_MAX_ID,
}DISP_STATUS_ID;

/** 
  *  @enums
  *  @brief  省电模式时屏幕保存状态定义
  */
typedef enum {
    SCREEN_SAVE_MODE_MAX_ID,
}SCREEN_SAVE_MODE_ID;

/** 
  *  @enums
  *  @brief  获取版本类型定义
  */
typedef enum {
    VERSION_TYPE_HMI = 0x00,
    VERSION_TYPE_BT,
}VERSION_TYPE_ID;

/** 
  *  @struct VERSION_INFO
  *  @brief HMI/BT版本信息
  */
typedef struct {
    VERSION_TYPE_ID type;
    char version_buffer[64];
    unsigned char size;
}VERSION_INFO;

/** 
  *  @enums
  *  @brief  主板开关机状态定义
  */
typedef enum {
    POWER_STATUS_OFF = 0x00,
    POWER_STATUS_ON,
    POWER_STATUS_MAX_ID,
}POWER_STATUS_ID;

/** 
  *  @enums
  *  @brief  开关机状态模式定义
  */
typedef enum {
    POWER_MODE_SLEEP_OFF = 0x00,
    POWER_MODE_TEMP_OFF,
    POWER_MODE_USER_OFF,
    POWER_MODE_USER_ON,
    POWER_MODE_MAX_ID,
}POWER_MODE_ID;

/** 
  *  @struct POWER_INFO
  *  @brief 开关机状态信息
  */
typedef struct {
    POWER_STATUS_ID power_status;
    POWER_MODE_ID power_mode;
}POWER_INFO;

/** 
  *  @enums
  *  @brief  RTC 模式类型定义
  */
typedef enum {
    RTC_MODE_12HOURS = 0x00,
    RTC_MODE_24HOURS,
    RTC_MODE_SET_CLOCK,
    RTC_MODE_MAX_ID,
}RTC_MODE_ID;

/** 
  *  @struct CLOCK_MSG
  *  @brief 时钟信息
  */
typedef struct {
    unsigned char hours;
    unsigned char minutes;
    unsigned char seconds;
    unsigned short year;
    unsigned char month;
    unsigned char date;
}CLOCK_MSG;

/** 
  *  @struct RTC_MSG
  *  @brief RTC 时钟信息
  */
typedef struct {
    RTC_MODE_ID rtc_mode;
    CLOCK_MSG clock_msg;
}RTC_MSG;

/** 
  *  @struct SETUP_PARAM_INFO
  *  @brief 设置参数信息
  */
typedef struct {
    unsigned char size;
    unsigned char param_info[255];
}SETUP_PARAM_INFO;

/** 
  *  @enums
  *  @brief 音频信号源定义
  */
typedef enum {
	AUDIO_SOURCE_FM1=0x00,
	AUDIO_SOURCE_FM2,
	AUDIO_SOURCE_FM3,
	AUDIO_SOURCE_FM4,
	AUDIO_SOURCE_AM1,
	AUDIO_SOURCE_AM2,
	AUDIO_SOURCE_AM3,
	AUDIO_SOURCE_TUNER,
	AUDIO_SOURCE_CD,
	AUDIO_SOURCE_AUX,
	AUDIO_SOURCE_AUDIO_PLAYER,
	AUDIO_SOURCE_VIDEO_PLAYER,
	AUDIO_SOURCE_IPOD_CARPLAY,
	AUDIO_SOURCE_BT_HFP,
	AUDIO_SOURCE_BT_AUDIO,
	AUDIO_SOURCE_SMARTPHONE,
	AUDIO_SOURCE_IPOD,
	
	AUDIO_SOURCE_MAX_ID,
}AUDIO_SOURCE_ID;

/** 
  *  @enums
  *  @brief 音频设置类型定义
  */
typedef enum {
    AUDIO_SETTING_VOLUME = 0x00,
    AUDIO_SETTING_BAS,
    AUDIO_SETTING_TRE,
    AUDIO_SETTING_BAL,
    AUDIO_SETTING_FAD,
    AUDIO_SETTING_EQ,
    
    AUDIO_SETTING_MAX_ID, 
}AUDIO_SETTING_TYPE_ID;

/** 
  *  @struct AUDIO_SETTING_TYPE_INFO
  *  @brief 音频设置类型信息
  */
typedef struct {
    AUDIO_SETTING_TYPE_ID type;
    unsigned char value;
}AUDIO_SETTING_TYPE_INFO;

/** 
  *  @struct AUDIO_SETTING_INFO
  *  @brief 音频设置信息
  */
typedef struct {
    unsigned char volume;
    unsigned char bass;
    unsigned char treble;
    unsigned char bal;
    unsigned char fader;
    unsigned char EQ;
    unsigned char TBD;
}AUDIO_SETTING_INFO;

/** 
  *  @enums
  *  @brief AUX输入增益参数定义
  */
typedef enum {
    AUDIO_AUX_GAIN_OFF = 0x00,
    AUDIO_AUX_GAIN_LOW,
    AUDIO_AUX_GAIN_MID,
    AUDIO_AUX_GAIN_HIGH,
    
    AUDIO_AUX_GAIN_MAX_ID, 
}AUDIO_AUX_GAIN_ID;

/** 
  *  @enums
  *  @brief beep 开关状态定义
  */
typedef enum {
    BEEP_STATUS_OFF = 0x00,
    BEEP_STATUS_ON,
    BEEP_STATUS_MAX_ID,
}BEEP_STATUS_ID;

/** 
  *  @enums
  *  @brief 车速音量连动参数定义
  */
typedef enum {
    AUDIO_SPEED_VOLUME_OFF = 0x00,   
    AUDIO_SPEED_VOLUME_LEVEL1 = 0x01,
    AUDIO_SPEED_VOLUME_LEVEL2 = 0x02,
    AUDIO_SPEED_VOLUME_LEVEL3 = 0x03,
    AUDIO_SPEED_VOLUME_LEVEL4 = 0x04,
    AUDIO_SPEED_VOLUME_LEVEL5 = 0x05,
    
    AUDIO_SPEED_VOLUME_MAX_ID, 
}AUDIO_SPEED_VOLUME_ID;

/** 
  *  @enums
  *  @brief 导航混音开关状态定义
  */
typedef enum {
    NAVI_MIX_STATUS_START = 0x00,   
    NAVI_MIX_STATUS_END = 0x01,
    
    NAVI_MIX_STATUS_MAX_ID, 
}NAVI_MIX_STATUS_ID;

/** 
  *  @enums
  *  @brief 外设状态定义
  */
typedef enum {
    DEVICE_PLUG_STATUS_AUX_OUT = 0x00,
    DEVICE_PLUG_STATUS_AUX_IN = 0x01,
    DEVICE_PLUG_STATUS_TEL_OFF = 0x10,
    DEVICE_PLUG_STATUS_TEL_ON = 0x11,
    DEVICE_PLUG_STATUS_PARK_ON = 0x20,
    DEVICE_PLUG_STATUS_PARK_OFF = 0x21,
    DEVICE_PLUG_STATUS_REVERSE_OFF = 0x30,
    DEVICE_PLUG_STATUS_REVERSE_ON = 0x31,
    DEVICE_PLUG_STATUS_DISK_OUT = 0x40,
    DEVICE_PLUG_STATUS_DISK_IN = 0x41,
    DEVICE_PLUG_STATUS_ILL_DAY = 0x50,
    DEVICE_PLUG_STATUS_ILL_NIGHT = 0x51,
}DEVICE_PLUG_STATUS_ID;

/** 
  *  @enums
  *  @brief 音量调整参数定义
  */
typedef enum {
    ADJUST_VOLUME_DOWN = 0x00,
    ADJUST_VOLUME_UP,
    ADJUST_VOLUME_MAX_ID,
}ADJUST_VOLUME_ID;

/** 
  *  @enums
  *  @brief 音量信息类型定义
  */
typedef enum {
    AUDIO_VOLUME_INFO_TYPE_CUR_VOL = 0x00,
    AUDIO_VOLUME_INFO_TYPE_ON,
    AUDIO_VOLUME_INFO_TYPE_OFF,
}AUDIO_VOLUME_INFO_TYPE_ID;

/** 
  *  @struct AUDIO_VOLUME_INFO
  *  @brief 音量信息
  */
typedef struct {
    AUDIO_VOLUME_INFO_TYPE_ID type;
    unsigned char values;
}AUDIO_VOLUME_INFO;

/** 
  *  @enums
  *  @brief DISK/AUX弹出信息定义
  */
typedef enum {
    POPUP_INFO_NO_DISK = 0x00,
    POPUP_INFO_NO_AUX,
}POPUP_INFO_ID;

/** 
  *  @enums
  *  @brief Radio 进行APS、SCAN 操作控制定义
  */
typedef enum {
    RADIO_CTRL_APS = 0x00,
    RADIO_CTRL_SCAN,
    RADIO_CTRL_MAX_ID,
}RADIO_CTRL_ID;

/** 
  *  @enums
  *  @brief Radio 波段定义
  */
typedef enum {
    RADIO_BAND_FM1 = 0x00,
    RADIO_BAND_FM2,
    RADIO_BAND_FM3,
    RADIO_BAND_FM4,
    RADIO_BAND_AM1,
    RADIO_BAND_AM2,
    RADIO_BAND_AM3,
    RADIO_BAND_AM4,

    RADIO_BAND_MAX_ID,
}RADIO_BAND_ID;

/** 
  *  @enums
  *  @brief Radio 当前状态定义
  */
typedef enum
{
  RADIO_STATUS_NORMAL = 0x00,
  RADIO_STATUS_SEEK_UP,
  RADIO_STATUS_SEEK_DN,
  RADIO_STATUS_SCAN,
  RADIO_STATUS_APS,
  
  RADIO_STATUS_MAX_ID,
}RADIO_STATUS_ID;

/** 
  *  @struct RADIO_NOTIFY
  *  @brief Radio 当前波段、状态、预置台、频率信息
  */
typedef struct {
    RADIO_BAND_ID band;
    unsigned char preset_num;
    RADIO_STATUS_ID status;
    unsigned long cur_freq;
}RADIO_NOTIFY;

/** 
  *  @struct RADIO_PRESET_INFO
  *  @brief 波段对应预存电台信息
  */
typedef struct {
    RADIO_BAND_ID band;
    unsigned long preset_freq[7];
    unsigned char preset_num;
}RADIO_PRESET_INFO;

/** 
  *  @struct RADIO_COLLECTED_INFO
  *  @brief 收藏电台信息
  */
typedef struct {
    unsigned char size;
    unsigned char content[64];
}RADIO_COLLECTED_INFO;

/** 
  *  @enums
  *  @brief IGN 当前状态定义
  */
typedef enum
{
    IGN_STATUS_OFF = 0x00,
    IGN_STATUS_ON = 0X01,
}IGN_STATUS;

/** 
  *  @struct IGN_ON_IFF_INFO
  *  @brief IGN状态信息
  */
typedef struct {
    IGN_STATUS ign_status;
}IGN_ON_OFF_INFO;


/** 
  *  @struct COREBOARD_RESUME_INFO
  *  @brief 核心板恢复保存状态信息
  */
typedef struct {
   unsigned short address_offset;
   unsigned short length;
   unsigned char data[128];
}COREBOARD_RESUME_INFO;

/** 
  *  @enums
  *  @brief 当前蓝牙状态类型定义
  */
typedef enum {
    BLUETOOTH_TYPE_HFP = 0x00,
    BLUETOOTH_TYPE_HID_SPP,
    BLUETOOTH_TYPE_POWER_SETUP,
}BLUETOOTH_TYPE_ID;

/** 
  *  @enums
  *  @brief 当前蓝牙状态定义
  */
typedef enum {
    BLUETOOTH_STATUS_OFF = 0x00,
    BLUETOOTH_STATUS_ON,
}BLUETOOTH_STATUS_ID;

/** 
  *  @struct BLUETOOTH_STATUS_INFO
  *  @brief 当前蓝牙状态信息
  */
typedef struct {
    BLUETOOTH_TYPE_ID type;
    BLUETOOTH_STATUS_ID status;
}BLUETOOTH_STATUS_INFO;

/** 
  *  @enums
  *  @brief 视频输入信号源定义
  */
typedef enum {
    VIDEO_SOURCE_NAVI = 0x00,
    VIDEO_SOURCE_CAMERA = 0x01,
    VIDEO_SOURCE_MHL = 0x02,
    VIDEO_SOURCE_AVM_MENU_PAGE = 0x10,
    
    VIDEO_SOURCE_MAX_ID,
}VIDEO_SOURCE_ID;

/** 
  *  @enums
  *  @brief 视频输入信号源类型格式定义
  */
typedef enum {
    VIDEO_TYPE_480P = 0x00,
    VIDEO_TYPE_720P = 0x01,
    VIDEO_TYPE_720I = 0x02,
    VIDEO_TYPE_1080P = 0x03,
    VIDEO_TYPE_1080I = 0x04,
    VIDEO_TYPE_IPHONE4 = 0x10,
    VIDEO_TYPE_IPHONE4S = 0x11,
    VIDEO_TYPE_IPHONE5 = 0x12,
    VIDEO_TYPE_IPHONE5S = 0x13,
    
    VIDEO_TYPE_MAX_ID,
}VIDEO_TYPE_ID;

/** 
  *  @struct VIDEO_SOURCE_INFO
  *  @brief  视频输入信号源信息
  */
typedef struct {
    VIDEO_SOURCE_ID video_source;
    VIDEO_TYPE_ID video_type;
}VIDEO_SOURCE_INFO;

/** 
  *  @struct AVM_DATA_INFO
  *  @brief 存储AVM数据
  */
typedef struct {
    unsigned char size;
    unsigned char content[128];
}AVM_DATA_INFO;


/** 
  *  @enums
  *  @brief 当前语言类型定义
  */
typedef enum {
    LANGUAGE_CHINESE = 0x00,
    LANGUAGE_ENGLISH,
    LANGUAGE_MAX_ID,
}LANGUAGE_ID;

/** 
  *  @enums
  *  @brief TFT 白天黑夜检测模式定义
  */
typedef enum {
    ILL_MODE_AUTO = 0x00,
    ILL_MODE_FORCE_DAY,
    ILL_MODE_FORCE_NIGHT,
    ILL_MODE_MAX_ID,
}ILL_MODE_ID;

/** 
  *  @enums
  *  @brief TFT 背光状态定义
  */
typedef enum {
    BACKLIGHT_STATUS_OFF = 0x00,
    BACKLIGHT_STATUS_ON,
    BACKLIGHT_STATUS_MAX_ID,
}BACKLIGHT_STATUS_ID;

/** 
  *  @enums
  *  @brief AVM 设置类型定义
  */
typedef enum{
    AVM_SETTING_TYPE_WHEELPATH_SETUP = 0x00,
    AVM_SETTING_TYPE_FRIST_DRIVE_AUTO_SETUP,
    AVM_SETTING_TYPE_BOOT_ANIMATION_SETUP,
    AVM_SETTING_TYPE_MODEL_COLOR_SETUP,
    AVM_SETTING_TYPE_BRIGHTNESS,
    AVM_SETTING_TYPE_CONTRAST,
    AVM_SETTING_TYPE_CHROMATIC,
    
    AVM_SETTING_TYPE_MAX_ID,
}AVM_SETTING_TYPE_ID;

/** 
  *  @enums
  *  @brief AVM 模型颜色定义
  */
typedef enum{
    AVM_MODEL_COLOR_RED = 0x00,
    AVM_MODEL_COLOR_BLACK,
    AVM_MODEL_COLOR_YELLOW,
    AVM_MODEL_COLOR_GRAY,
    AVM_MODEL_COLOR_BROWN,
    AVM_MODEL_COLOR_BLUE,
    
    AVM_MODEL_COLOR_MAX_ID,
}AVM_MODEL_COLOR_ID;

/** 
  *  @struct AVM_SETTING_TYPE_INFO
  *  @brief  AVM 设置类型信息
  */
typedef struct {
    AVM_SETTING_TYPE_ID type;
    unsigned char value;
}AVM_SETTING_TYPE_INFO;

/** 
  *  @struct AVM_SETTING_INFO
  *  @brief  AVM 设置信息
  */
typedef struct {
    unsigned char hw_version;
    unsigned char sw_version_h;
    unsigned char sw_version_l;
    unsigned char wheelpath;
    unsigned char frist_drive_auto_setup;
    unsigned char boot_animation;
    unsigned char model_color;      /**< AVM 模型颜色，参考AVM_MODEL_COLOR_ID*/
    unsigned char brightness;
    unsigned char contrast;
    unsigned char chromatic;    
}AVM_SETTING_INFO;

/** 
  *  @enums
  *  @brief 手机连接弹出框类型定义
  */
typedef enum {
    MHL_POP_TYPE_MIRROR_BOX = 0x00,
    MHL_POP_TYPE_INTELLIGENT_BOX, 
}MHL_POP_TYPE_ID;

/** 
  *  @enums
  *  @brief 手机连接信号状态定义
  */
typedef enum {
   MHL_SIGNAL_NO_DETECTED = 0x00,
   MHL_SIGNAL_DETECTED,
}MHL_SIGNAL_STATUS_ID;

/** 
  *  @enums
  *  @brief 更新固件类型定义
  */
typedef enum {
    UPDATE_TYPE_OSD = 0x01,
    UPDATE_TYPE_MD = 0xAA,
}UPDATE_TYPE_ID;

/** 
  *  @enums
  *  @brief 嗽叭诊断输出声音 定义
  */
typedef enum {
	SPEAKER_FL_3K = 0x00,   /**< speaker front left 3KHZ */
	SPEAKER_FR_3K,          /**< speaker front right 3KHZ */
	SPEAKER_RL_3K,          /**< speaker rear left 3KHZ */
	SPEAKER_RR_3K,          /**< speaker rear right 3KHZ */
	SPEAKER_FL_3H,          /**< speaker front left 300HZ */
	SPEAKER_FR_3H,          /**< speaker front right 300HZ */
	SPEAKER_RL_3H,          /**< speaker rear left 300HZ */
	SPEAKER_RR_3H,          /**< speaker rear right 300HZ */
	SPEAKER_STOP=0xFF,      /**< speaker stop */
}SPEAKER_FREQ_ID;

/** 
  *  @struct MCAN_INFO
  *  @brief  MCAN 信息定义
  */
typedef struct {
    char *data;
}MCAN_INFO;

/** 
  *  @enums
  *  @brief 空调模式定义
  */
typedef enum {
    HVAC_MODE_NO_DISPLAY = 0x00,    /**< 不显示 */
    HVAC_MODE_BLOW_FACE,            /**< 吹脸模式 */
    HVAC_MODE_BLOW_FACE_FEET,       /**< 吹脸/吹脚模式 */
    HVAC_MODE_BLOW_FEET,            /**< 吹脚模式 */
    HVAC_MODE_BLOW_FEET_DEFROST,    /**< 吹脚除霜模式 */
    HVAC_MODE_MAX_ID,
}HVAC_MODE_ID;

/** 
  *  @struct HVAC_INFO
  *  @brief  空调返回状态信息定义
  */
typedef struct {
    unsigned char maxAC_on_off;         /**< MAX AC 开关状态；1 开启，0 关闭 */
    unsigned char AC_on_off;            /**< AC  开关状态；1 开启，0 关闭 */
    unsigned char recirc_on_off;        /**< 内循环 开关状态；1 开启，0 关闭 */
    unsigned char fresh_on_off;         /**< 外循环开关状态；1 开启，0 关闭 */
    unsigned char dual_on_off;          /**< 双区模式开关状态；1 开启，0 关闭 */ 
    unsigned char ACT_on_off;           /**< 放大器 开关状态；1 开启，0 关闭 */
    unsigned char redefrost_on_off;     /**< 后除霜开关状态；1 开启，0 关闭 */
    unsigned char defrost_on_off;       /**< 前除霜开关状态；1 开启，0 关闭 */
    unsigned char display_on_off;       /**< 显示 开关状态；1 开启，0 关闭 */
    unsigned char blower_level;         /**< 鼓风机风量；0-8, 0表示关闭 */
    unsigned char left_temp;            /**< 左区温度；0-16, 0表示不显示 */
    unsigned char right_temp;           /**< 右区温度；0-16, 0表示不显示 */
    HVAC_MODE_ID hvac_mode;             /**< 空调模式,参考HVAC_MODE_ID 定义 */
}HVAC_INFO;

/** 
  *  @enums
  *  @brief 空调按键状态定义
  */
typedef enum {
    HVAC_KEY_STATUS_DOWN = 0x00,    /**< 按键按下 */
    HVAC_KEY_STATUS_UP,             /**< 按键抬起 */
    
    HVAC_KEY_STATUS_MAX_ID,
}HVAC_KEY_STATUS_ID;

/** 
  *  @struct HVAC_STATUS
  *  @brief  空调发送状态信息定义
  */
typedef struct {
    HVAC_KEY_STATUS_ID maxAC;                           /**< MAX AC 按键状态*/
    HVAC_KEY_STATUS_ID AC;                              /**< AC 按键状态*/
    HVAC_KEY_STATUS_ID recirc;                          /**< 内循环按键状态*/
    HVAC_KEY_STATUS_ID fresh;                           /**< 外循环按键状态*/
    HVAC_KEY_STATUS_ID defrost;                         /**< 前除霜按键状态*/
    HVAC_KEY_STATUS_ID mode;                            /**< 模式按键状态*/
    HVAC_KEY_STATUS_ID front_panel_left_temp_minus;     /**< 前面板左区温度减按键状态*/
    HVAC_KEY_STATUS_ID front_panel_letf_tmep_plus;      /**< 前面板左区温度加按键状态*/
    
    HVAC_KEY_STATUS_ID front_panel_blower_minus;        /**< 前面板风量减按键状态*/
    HVAC_KEY_STATUS_ID front_panel_blower_plus;         /**< 前面板风量加按键状态*/
    HVAC_KEY_STATUS_ID touch_panel_blower_minus;        /**< 触摸屏风量减按键状态*/
    HVAC_KEY_STATUS_ID touch_panel_blower_plus;         /**< 触摸屏风量加按键状态*/
    unsigned char target_blower_level;                  /**< 目标风量，0-8，0表示无触摸屏操作*/

    HVAC_KEY_STATUS_ID dual;                            /**< 双温区功能按键状态*/
    HVAC_KEY_STATUS_ID on_off;                          /**< On/Off 功能按键状态*/
    HVAC_KEY_STATUS_ID redefrost;                       /**< 后除霜按键状态*/
    HVAC_KEY_STATUS_ID front_panel_right_temp_minus;    /**< 前面板右区温度减按键状态*/
    HVAC_KEY_STATUS_ID front_panel_right_tmep_plus;     /**< 前面板右区温度加按键状态*/
    
    HVAC_KEY_STATUS_ID touch_panel_left_temp_minus;     /**< 触摸屏左区温度减按键状态*/
    HVAC_KEY_STATUS_ID touch_panel_letf_tmep_plus;      /**< 触摸屏左区温度加按键状态*/
    unsigned char touch_panel_target_letf_tmep;         /**< 触摸屏左区目标温度，0-16，0表示无触摸屏操作*/
    HVAC_KEY_STATUS_ID touch_panel_right_temp_minus;    /**< 触摸屏右区温度减按键状态*/
    HVAC_KEY_STATUS_ID touch_panel_right_tmep_plus;     /**< 触摸屏右区温度加按键状态*/
    unsigned char touch_panel_target_right_tmep;        /**< 触摸屏右区目标温度，0-16，0表示无触摸屏操作*/
}HVAC_STATUS;

/** 
  *  @enums 
  *  @brief  空调诊断控制对象定义
  */
typedef enum {
 HAVC_DIAG_CTRL_OBJ_BLOWER_SYS = 0x01,                      /**< 鼓风机系统*/
 HAVC_DIAG_CTRL_OBJ_MODE_DAMPER_MOTER = 0x02,               /**< 模式风门马达*/
 HAVC_DIAG_CTRL_OBJ_INSIDE_OUTSIDE_DAMPER_MOTER = 0x03,     /**< 内外气风门马达*/
 HAVC_DIAG_CTRL_OBJ_MIXED_DAMPER_MOTER_LEFT = 0x04,         /**< 混合风门马达左*/
 HAVC_DIAG_CTRL_OBJ_MIXED_DAMPER_MOTER_RIGHT = 0x05,        /**< 混合风门马达右*/
 HAVC_DIAG_CTRL_OBJ_EVAPORATOR_TEMPERATURE_SENSOR = 0x06,   /**< 蒸发器温度传感器*/
 HAVC_DIAG_CTRL_OBJ_INDICATOR_LIGHT_CHECK = 0x07,           /**< 指示灯检测*/
 HAVC_DIAG_CTRL_OBJ_KEY_VALUE = 0x08,                       /**< 空调按键诊断*/
}HVAC_DIAG_CTRL_OBJ_ID;

/** 
  *  @enums 
  *  @brief 空调诊断 输出单元操作检查模式定义
  */
typedef enum {
    HVAC_DIAG_CTRL_MODE1 = 0x01,    /**< 模式1，吹面-左混合全冷-右混合全热-内循环-风速7档*/
    HVAC_DIAG_CTRL_MODE2,           /**< 模式2，吹脚-左混合全热-右混合全冷-外循环-风速1档*/
    HVAC_DIAG_CTRL_MODE3,           /**< 模式3，除霜-左混合中间-右混合中间-外循环-风速4档*/
}HVAC_DIAG_CTRL_UT_MODE_ID;

/** 
  *  @struct HVAC_INFO
  *  @brief  空调诊断控制信息定义
  */
typedef struct {
    HVAC_DIAG_CTRL_OBJ_ID obj;  /**< 空调诊断控制对象，参考enum HVAC_DIAG_CTRL_OBJ_ID 相关定义*/
    unsigned char light_status; /**< 指示灯检测状态(0x01开/0x00关) */
    unsigned char reserver[2];  /**< 预留字节 */
}HVAC_DIAG_CTRL_INFO;

/** 
  *  @enums 
  *  @brief 空调诊断 状态定义
  */
typedef enum {
    HVAC_DIAG_STATUS_NON_EXECUTION = 0x40,  /**< 未执行诊断控制 */
    HVAC_DIAG_STATUS_APPLY_SUCCESS = 0x41,  /**< 诊断申请成功 */
    HVAC_DIAG_STATUS_DOING_EXECUTION = 0x42, /**< 诊断正在进行中 */
    HVAC_DIAG_STATUS_DONE_EXECUTION = 0x43, /**< 诊断完成，可以读取第五个字节的错误码 */
}HVAC_DIAG_STATUS_ID;

/** 
  *  @enums 
  *  @brief 空调诊断 错误码定义
  */
typedef enum {
    BLOWER_SYS_NO_ERROR = 0x0100,
    BLOWER_SYS_ERROR = 0x0101,
    MODE_DAMPER_MOTER_NO_ERROR = 0x0200,
    MODE_DAMPER_MOTER_SHORT_CIRCUIT_GND = 0x0201,
    MODE_DAMPER_MOTER_SHORT_CIRCUIT_POWER = 0x0202,
    MODE_DAMPER_MOTER_STALLING = 0x0203,
    INSIDE_OUTSIDE_DAMPER_MOTER_NO_ERROR = 0x0300,
    INSIDE_OUTSIDE_DAMPER_MOTER_SHORT_CIRCUIT_GND = 0x0301,
    INSIDE_OUTSIDE_DAMPER_MOTER_SHORT_CIRCUIT_POWER = 0x0302,
    INSIDE_OUTSIDE_DAMPER_MOTER_STALLING = 0x0303,
    MIXED_DAMPER_MOTER_LEFT_NO_ERROR = 0x0400,
    MIXED_DAMPER_MOTER_LEFT_SHORT_CIRCUIT_GND = 0x0401,
    MIXED_DAMPER_MOTER_LEFT_SHORT_CIRCUIT_POWER = 0x0402,
    MIXED_DAMPER_MOTER_LEFT_STALLING = 0x0403,
    MIXED_DAMPER_MOTER_RIGHT_NO_ERROR = 0x0500,
    MIXED_DAMPER_MOTER_RIGHT_SHORT_CIRCUIT_GND = 0x0501,
    MIXED_DAMPER_MOTER_RIGHT_SHORT_CIRCUIT_POWER = 0x0502,
    MIXED_DAMPER_MOTER_RIGHT_STALLING = 0x0503,
    EVAPORATOR_TEMPERATURE_SENSOR_NO_ERROR = 0x0600,
    EVAPORATOR_TEMPERATURE_SENSOR_SHORT_CIRCUIT_GND = 0x0601,
    EVAPORATOR_TEMPERATURE_SENSOR_SHORT_CIRCUIT_POWER = 0x0602,

    KEY_DEFROST_RELEASE = 0x0800,
    KEY_REDEFROST_RELEASE = 0x0801,
    KEY_L_UP_RELEASE = 0x0802,
    KEY_L_DOWN_RELEASE = 0x0803,
    KEY_ON_OFF_RELEASE = 0x0804,
    KEY_RECIRC_RELEASE = 0x0805,
    KEY_FRESH_RELEASE = 0x0806,
    KEY_MAX_AC_RELEASE = 0x0807,
    KEY_DUAL_RELEASE = 0x0808,
    KEY_BLOWER_P_RELEASE = 0x0809,
    KEY_R_UP_RELEASE = 0x080A,
    KEY_R_DOWN_RELEASE = 0x080B,
    KEY_MODE_RELEASE = 0x080C,
    KEY_AC_ON_RELEASE = 0x080D,
    KEY_BLOWER_M_RELEASE = 0x080E,
    KEY_MENU_RELEASE = 0x0831,
    KEY_BACK_RELEASE = 0x0832,
    KEY_HOME_RELEASE = 0x0835,
    KEY_MEDIA_RELEASE = 0x0836,
    KEY_POWER_RELEASE = 0x0812,
    
    KEY_DEFROST_PRESS = 0x0880,
    KEY_REDEFROST_PRESS = 0x0881,
    KEY_L_UP_PRESS = 0x0882,
    KEY_L_DOWN_PRESS = 0x0883,
    KEY_ON_OFF_PRESS = 0x0884,
    KEY_RECIRC_PRESS = 0x0885,
    KEY_FRESH_PRESS = 0x0886,
    KEY_MAX_AC_PRESS = 0x0887,
    KEY_DUAL_PRESS = 0x0888,
    KEY_BLOWER_P_PRESS = 0x0889,
    KEY_R_UP_PRESS = 0x088A,
    KEY_R_DOWN_PRESS = 0x088B,
    KEY_MODE_PRESS = 0x088C,
    KEY_AC_ON_PRESS = 0x088D,
    KEY_BLOWER_M_PRESS = 0x088E,
    KEY_MENU_PRESS = 0x08B1,
    KEY_BACK_PRESS = 0x08B2,
    KEY_HOME_PRESS = 0x08B5,
    KEY_MEDIA_PRESS = 0x08B6,
    KEY_POWER_PRESS = 0x0892,
}HVAC_DIAG_FAULT_CODE_ID;

/** 
  *  @struct HVAC_DIAG_INFO
  *  @brief 空调诊断结果信息定义
  */
typedef struct {
    HVAC_DIAG_STATUS_ID status;
    HVAC_DIAG_CTRL_OBJ_ID obj;
    HVAC_DIAG_FAULT_CODE_ID code;
}HVAC_DIAG_INFO;

/** 
  *  @enums 
  *  @brief 多功能旋钮encoder 信息定义
  */
typedef enum {
    ENCODER_OFF = 0x00,
    ENCODER_CW_1PULSE = 0x01,
    ENCODER_CW_2PULSE = 0x02,
    ENCODER_CW_3PULSE = 0x03,
    ENCODER_CCW_1PULSE = 0x05,
    ENCODER_CCW_2PULSE = 0x06,
    ENCODER_CCW_3PULSE = 0x07,
}IT_COMMANDER_ENCODER_ID;

/** 
  *  @enums 
  *  @brief 多功能旋钮directions 信息定义
  */
typedef enum {
    DIRECTIONS_OFF = 0x00,
    DIRECTIONS_UP = 0x01,
    DIRECTIONS_UP_RIGHT = 0x02,
    DIRECTIONS_RIGHT = 0x03,
    DIRECTIONS_RIGHT_DOWN = 0x04,
    DIRECTIONS_DOWN = 0x05,
    DIRECTIONS_LEFT_DOWN = 0x06,
    DIRECTIONS_LEFT = 0x07,
    DIRECTIONS_UP_LEFT = 0x08,
}IT_COMMANDER_DIRECTIONS_ID;

/** 
  *  @struct IT_COMMANDER_INFO
  *  @brief  多功能旋钮按键信息定义
  */
typedef struct {
    unsigned char sw;                       /**< Bit0:SW1-OK;Bit1:SW2-Menu;Bit2:SW3-Back;Bit3:SW4-Home;Bit4:SW5-Media; (0-OFF;1-ON) */
    IT_COMMANDER_ENCODER_ID encoder;        /**< encoder data ,@see IT_COMMANDER_ENCODER_ID */
    IT_COMMANDER_DIRECTIONS_ID directions;  /**< 8-directions data ,@see IT_COMMANDER_DIRECTIONS_ID */
}IT_COMMANDER_INFO;

/**@}*/


/**
  * @addtogroup  Mcu_Agent_API
  * @{
  */

/** 
  *  @struct MCU_AGENT_API
  *  @brief  MCU Agent API 成员结构体
  */ 
typedef struct {

/**
  * @brief      HMI应用启动成功后，发送此信息通知主板。 
  * @param    void  无
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*hmi_startup)(void);

/**
  * @brief      NAVI应用启动成功后，发送此信息通知主板。
  * @param    void  无
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*navi_startup)(void);

/**
  * @brief      向主板发送请求同步数据，主板会把当前所有数据发送给核心板。
  * @param    void  无
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_sync_info)(void);

/**
  * @brief      获取主板系统的版本信息。
  * @param    void  无
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_mainboard_version_info)(void);

/**
  * @brief     发送模拟按键给主板。
  * @param    key 模拟按键ID，参考KEY_ID。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_hard_key)(HARD_KEY_ID key);

/**
  * @brief      发送触摸坐标给主板。
  * @param    info 触摸坐标信息，参考TOUCH_INFO。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_touch)(TOUCH_INFO *info);

/**
  * @brief      进入或退出工程诊断模式。
  * @param    status 进入或退出状态,参考ENGINEER_MODE_ID.
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_engineer_mode)(ENGINEER_MODE_ID status);

/**
  * @brief      控制主板发出beep 声的音调。
  * @param    status 音调状态，参考BEEP_TONE_ID。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*beep_tone)(BEEP_TONE_ID status);

/**
  * @brief      设置关机时，时钟显示的开关状态。
  * @param    status 时钟显示状态, 参考DISP_STATUS_ID。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*poweroff_timer_disp)(DISP_STATUS_ID status);

/**
  * @brief      发送当前屏幕保存模式;省电模式
  * @param    mode 当前屏幕保存方式, 参考SCREEN_SAVE_MODE_ID。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_screen_save_mode)(SCREEN_SAVE_MODE_ID mode);

/**
  * @brief      发送心跳回应给主板
  * @param    void 无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*send_alive)(void);

/**
  * @brief      发送HMI 或BT 的版本信息给主板。
  * @param    info 版本信息,参考VERSION_INFO。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*send_version_info)(VERSION_INFO *info);

/**
  * @brief      设置主板开关机状态。
  * @param    status 开关机状态, 参考POWER_STATUS_ID。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_audio_power)(POWER_STATUS_ID status);

/**
  * @brief      获取主板开关机状态。
  * @param    void   无
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_audio_power)(void);

/**
  * @brief      设置RTC 时间显示模式。
  * @param    mode 时间显示模式(12小时制/24小时制)，参考RTC_MODE_ID。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_rtc_mode)(RTC_MODE_ID mode);

/**
  * @brief      设置RTC 时间。
  * @param    clock_msg  设置RTC 的时间，参考CLOCK_MSG。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_rct_clock)(CLOCK_MSG *clock_msg);

/**
  * @brief      获取RTC  时间。
  * @param    void  无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_rct_clock)(void);

/**
  * @brief      设置GPS 时间。
  * @param    clock_msg  设置GPS 的时间，参考CLOCK_MSG。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_gps_clock)(CLOCK_MSG *clock_msg);

/**
  * @brief      获取GPS  时间。
  * @param    void  无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_gps_clock)(void);
/**
  * @brief      设置设置菜单参数信息。
  * @param    info  设置菜单参数信息, 参考SETUP_PARAM_INFO。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_setup_param_info) (SETUP_PARAM_INFO *info);
    
/**
  * @brief      设置主板的音频源。
  * @param    audio_source 音频源，参考AUDIO_SOURCE_ID 。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_audio_source)(AUDIO_SOURCE_ID audio_source);

/**
  * @brief      获取主板的音频源。
  * @param    void  无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_audio_source)(void);

/**
  * @brief      设置主板的音频参数信息。
  * @param    info 音频源参数信息，参考AUDIO_SETTING_TYPE_INFO 。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_audio_setting_info)(AUDIO_SETTING_TYPE_INFO *info);

/**
  * @brief      获取主板的音频参数信息。
  * @param    void  无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_audio_setting_info)(void);

/**
  * @brief      设置主板的AUX 输入增益参数。
  * @param    level AUX 输入增益参数,参考AUDIO_AUX_GAIN_ID 。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_audio_aux_gain)(AUDIO_AUX_GAIN_ID level);

/**
  * @brief      获取主板的AUX 输入增益参数。
  * @param    void  无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_audio_aux_gain)(void);

/**
  * @brief      设置主板的beep 开关状态。
  * @param    status beep开关状态，参考BEEP_STATUS_ID 。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_audio_beep)(BEEP_STATUS_ID status);

/**
  * @brief      获取主板的beep 开关状态。
  * @param    void  无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_audio_beep)(void);

/**
  * @brief      设置主板的车速音量连动参数。
  * @param    level  车速音量连动参数，参考AUDIO_SPEED_VOLUME_ID。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_audio_speed_volume)(AUDIO_SPEED_VOLUME_ID level);

/**
  * @brief      获取主板的车速音量连动参数。
  * @param    void  无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_audio_speed_volume)(void);
  
/**
  * @brief      获取主板的车速。
  * @param    void  无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_audio_speed)(void);

/**
  * @brief      设置主板导航混音开关状态。
  * @param    status  导航混音开关状态，参考NAVI_MIX_STATUS_ID。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
  
    int (*set_audio_navi_mix_status) (NAVI_MIX_STATUS_ID status);
    
/**
  * @brief      获取AUX接口的拔出或插入状态。
  * @param    void  无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_aux_plug_status)(void);
 
/**
  * @brief      设置主板的音量加减。
  * @param    status 音量加减状态，参考ADJUST_VOLUME_ID。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_adjust_volume)(ADJUST_VOLUME_ID status);

/**
  * @brief      设置当前波段频率参数。
  * @param    freq 频率参数 。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_radio_freq)(unsigned short freq);
    
/**
  * @brief     设置当前波段自动向上搜台。
  * @param    void  无 。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_radio_seek_up)(void);

/**
  * @brief     设置当前波段自动向下搜台。
  * @param    void  无 。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_radio_seek_down)(void);

/**
  * @brief     设置当前波段向上单步微调。
  * @param    void  无 。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_radio_manual_up)(void);

/**
  * @brief     设置当前波段向下单步微调
  * @param    void  无 。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_radio_manual_down)(void);

/**
  * @brief      控制进行APS、SCAN操作
  * @param    status APS,SCAN 操作状态，参考RADIO_CTRL_ID。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_radio_ctrl)(RADIO_CTRL_ID status);

/**
  * @brief      调用预存电台
  * @param    preset_num 预存电台编号1~6。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*call_radio_preset_num)(unsigned char preset_num);

/**
  * @brief      保存预设电台
  * @param    preset_num 预存电台编号1~6。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*save_radio_preset_num)(unsigned char preset_num);

/**
  * @brief      波段转换
  * @param    void 无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*change_radio_band)(void);

/**
  * @brief	    向上搜索
  * @param	  void 无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*radio_fastseek_up)(void);

/**
  * @brief		向下搜索
  * @param	  void 无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*radio_fastseek_down)(void);

/**
  * @brief      保存收藏电台信息
  * @param    info 收藏电台信息,参考RADIO_COLLECTED_INFO。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*save_radio_collected_info)(RADIO_COLLECTED_INFO *info);

    
/**
  * @brief      获取当前波段、状态、预置台、频率信息
  * @param    void 无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_radio_notify)(void);

/**
  * @brief      获取波段对应预存电台信息
  * @param    band 波段ID，参考RADIO_BAND_ID。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_radio_preset_info)(RADIO_BAND_ID band);

/**
  * @brief      获取IGN ON_OFF状态信息(CMF-B);
  * @param    void 无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_ign_on_off_status)(void);


/**
  * @brief      发送核心板恢复保存状态信息;
  * @param    info  核心板恢复播放状态信息,参考COREBOARD_RESUME_INFO。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_coreboard_resume_info)(COREBOARD_RESUME_INFO *info);

/**
  * @brief     获取核心板恢复保存状态信息;
  * @param    address_offset  起始地址偏移量。
  * @param    length  状态信息内容长度。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_coreboard_resume_info)(unsigned short address_offset, unsigned short length);

/**
  * @brief      发送当前蓝牙状态
  * @param    info  蓝牙状态，参考BLUETOOTH_STATUS_INFO。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*send_bluetooth_status)(BLUETOOTH_STATUS_INFO *info);

/**
  * @brief      设定视频输入信号源
  * @param    info 视频输入信号源，参考VIDEO_SOURCE_INFO 。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_video_source)(VIDEO_SOURCE_INFO *info);

/**
  * @brief     获取视频输入信号源
  * @param    void  无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_video_source)(void);

/**
  * @brief     设定语言状态。
  * @param    languege_id  语言状态ID ，参考LANGUAGE_ID。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_language)(LANGUAGE_ID languege_id);

/**
  * @brief     获取当前语言状态。
  * @param    void  无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_language)(void);

/**
  * @brief      设定白天黑夜检测模式
  * @param    mode  白天黑夜检测模式，参考IIL_MODE_ID。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_ILL_mode)(ILL_MODE_ID mode);

/**
  * @brief     获取白天黑夜检测模式。
  * @param    void  无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_ILL_mode)(void);

/**
  * @brief      设定背光开关状态
  * @param    status  背光开关状态，参考BACKLIGHT_STATUS_ID。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_backlight_status)(BACKLIGHT_STATUS_ID status);
 
/**
  * @brief     获取背光开关状态
  * @param    void  无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_backlight_status)(void);
  
/**
  * @brief      设定亮度值
  * @param    value  亮度值0~100
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_brightness)(unsigned char value);

/**
  * @brief     获取亮度值。
  * @param    void  无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_brightness)(void);
 
/**
  * @brief     设定对比度值
  * @param    value  对比度值0~100
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_contrast)(unsigned char value);
 
/**
  * @brief     获取对比度值。
  * @param    void  无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_contrast)(void);

/**
  * @brief      退出AVM设置菜单。
  * @param    void  无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*send_AVM_setting_menu_exit)(void);
 
/**
  * @brief      发送AVM设置参数信息
  * @param    info  AVM设置参数信息，参考AVM_SETTING_INFO。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_AVM_setting_info)(AVM_SETTING_TYPE_INFO *info);
 
/**
  * @brief     获取AVM设置参数信息
  * @param    void  无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*get_AVM_setting_info)(void);
 
/**
  * @brief      设置AVM恢复默认设置
  * @param    void  无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_AVM_default_setting)(void);

/**
  * @brief      设定手机连接弹出框类型
  * @param    type  手机连接弹出框类型，参考MHL_POP_TYPE_ID 。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_MHL_pop_type)(MHL_POP_TYPE_ID type);

/**
  * @brief      更新主板固件 
  * @param    type  更新固件类型，参考UPDATE_TYPE_ID。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*update_mainboard_firmware)(UPDATE_TYPE_ID type);

/**
  * @brief      设置主板恢复工厂默认设置
  * @param    void  无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_mainboard_default_setting)(void);

/**
  * @brief      设置嗽叭诊断输出声音 
  * @param    freq 喇叭输出声音频率变化ID，参考SPEAKER_FREQ_ID。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*set_speaker_diag)(SPEAKER_FREQ_ID freq);

/**
  * @brief		保存电台信息
  * @param	  info 保存接收到的电台信息,参考AVM_DATA_INFO。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*save_avm_data_info)(AVM_DATA_INFO *info);

/**
  * @brief      发送MCAN 消息
  * @param    mcan_info。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*send_mcan_info)(MCAN_INFO *mcan_info);

/**
  * @brief      发送空调状态 消息
  * @param    hvac_status 空调状态 消息, 参考HVAC_STATUS。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*send_hvac_status)(HVAC_STATUS *hvac_status);

/**
  * @brief      发送申请空调诊断控制信息
  * @param    info 空调诊断控制信息, 参考HVAC_DIAG_CTRL_INFO。。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*send_hvac_diag_entry)(HVAC_DIAG_CTRL_INFO *info);

/**
  * @brief      发送读取空调诊断控制对象状态信息
  * @param    info 空调诊断控制信息, 参考HVAC_DIAG_CTRL_INFO。。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*send_hvac_diag_read_status) (HVAC_DIAG_CTRL_INFO *info);

/**
  * @brief      发送取消空调诊断控制信息
  * @param    void  无。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*send_hvac_diag_exit) (void);

/**
  * @brief      发送进入输出单元操作检测信息
  * @param    mode 输出单元操作检测模式, 参考HVAC_DIAG_CTRL_UT_MODE_ID。。
  * @returns  成功返回发送数据包大小，失败返回小于0 。
  */
    int (*send_hvac_diag_unit_test_mode) (HVAC_DIAG_CTRL_UT_MODE_ID mode);
}MCU_AGENT_API;

/**
  * @addtogroup  Client_Init
  * @{
  */

/** 
  *  @struct MCU_MSG_HANDLE_REGISTER
  *  @brief  MCU 消息识别码处理函数注册
  */ 
typedef struct {
    MCU_MSG_ID mcu_msg_id;                    /**< MCU 消息识别码，参考MCU_MSG_ID  相关定义。@see MCU_MSG_ID*/
    void (*mcu_msg_callback)(PACKET_MSG *);   /**< MCU 消息识别码对应的处理回调函数*/  
}MCU_MSG_HANDLE_REGISTER;
     
/**
  * @brief      McuAgent客户端初始化；
  *               与服务端建立连接，并对每个MCU 消息识别码进行处理回调函数注册。
  * @param    mcu_msg_handle_register   MCU 消息识别码处理函数注册信息。
  * @returns  成功返回MCU_AGENT_API 指针，失败返回NULL。
  */
MCU_AGENT_API *McuAgent_client_init(MCU_MSG_HANDLE_REGISTER *mcu_msg_handle_register);

/**
  * @brief      获取Mcu Agent API 指针。
  * @param    无。
  * @returns  成功返回MCU_AGENT_API 指针，失败返回NULL。
  */
MCU_AGENT_API *McuAgent_get_api_handle(void);
/**@}*/

/**@}*/
#endif

