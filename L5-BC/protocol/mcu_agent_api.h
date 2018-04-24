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
  *  @brief  MCU  ������Ϣʶ���붨��
  */
typedef enum {
    MCU_MSG_RET_MB_VERSION = 0x03,      /**< ��������汾��Ϣ���������ݲο�struct MB_VERSION_INFO ��ض��塣@see MB_VERSION_INFO*/  
    MCU_MSG_RET_HARD_KEY = 0x04,        /**< ���ذ�����Ϣ���������ݲο�enum  HARD_KEY_ID ��ض��塣@see  HARD_KEY_ID*/ 
    MCU_MSG_SET_TOUCH = 0x05,           /**< ������Ļ����������Ϣ���������ݲο�struct TOUCH_INFO ��ض��塣@see TOUCH_INFO*/ 
    MCU_MSG_SET_ENGINEER_MODE = 0x06,   /**< ���ù������ģʽ������˳����������ݲο�enum ENGINEER_MODE_ID ��ض��塣@see ENGINEER_MODE_ID*/ 
    MCU_MSG_RET_POWEROFF_TIMER_DISP_STATUS = 0x08,  /**< ���عػ�ʱ��ʱ����ʾ״̬���������ݲο�enum DISP_STATUS_ID ��ض��塣@see DISP_STATUS_ID */
    MCU_MSG_RET_SCREEN_SAVE_MODE = 0x09,            /**< ����ʡ��ģʽʱ��Ļ����״̬���������ݲο�enum SCREEN_SAVE_MODE_ID ��ض��塣@see SCREEN_SAVE_MODE_ID*/
    MCU_MSG_RET_ALINE = 0x0E,                       /**< ����������Ӧ���޷������ݡ�*/
    MCU_MSG_GET_VERSION_INFO = 0x0F,                /**< ��ȡHMI/BT �İ汾��Ϣ���������ݲο�enum VERSION_TYPE_ID ��ض��塣@see VERSION_TYPE_ID*/
    MCU_MSG_RET_CUR_AUDIO_POWER_STATUS = 0x11,      /**< �������忪�ػ�״̬���������ݲο�struct POWER_INFO ��ض��塣@see POWER_INFO*/
    MCU_MSG_RET_RTC_CLOCK_INFO = 0x13,              /**< ����RTC ʱ����Ϣ���������ݲο�struct RTC_MSG ��ض��塣@see RTC_MSG*/
    MCU_MSG_RET_GPS_CLOCK_INFO = 0x15,              /**< ����GPS ʱ����Ϣ���������ݲο�struct CLOCK_MSG ��ض��塣@see CLOCK_MSG*/
    MCU_MSG_RET_SETUP_PARAM_INFO = 0x1F,            /**< �������ò˵��е���ز�����Ϣ���������ݲο�struct SETUP_PARAM_INFO ��ض��塣@see SETUP_PARAM_INFO*/
    
    MCU_MSG_RET_CUR_AUDIO_SOURCE = 0x21,            /**< ������ƵԴ���������ݲο�enum AUDIO_SOURCE_ID ��ض��塣@see AUDIO_SOURCE_ID*/
    MCU_MSG_RET_AUDIO_SETTING_INFO = 0x23,          /**< ������Ƶ����������Ϣ���������ݲο�struct AUDIO_SETTING_INFO ��ض��塣@see AUDIO_SETTING_INFO*/
    MCU_MSG_RET_AUDIO_AUX_GAIN_MODE = 0x25,	        /**< ����AUX ��������������������ݲο�enum AUDIO_AUX_GAIN_ID ��ض��塣@see AUDIO_AUX_GAIN_ID*/
    MCU_MSG_RET_AUDIO_BEEP_STATUS = 0x27,           /**< ����Beep����״̬���������ݲο�enum BEEP_STATUS_ID ��ض��塣@see BEEP_STATUS_ID*/
    MCU_MSG_RET_AUDIO_SPEED_VOLUME_MODE = 0x29,     /**< ���س������������������������ݲο�enum AUDIO_SPEED_VOLUME_ID  ��ض��塣@see AUDIO_SPEED_VOLUME_ID*/
    MCU_MSG_RET_AUDIO_SPEED = 0x2A,                 /**< ���س����ٶȣ���������Ϊunsigned short ��*/

    MCU_MSG_RET_AUDIO_DEVICE_PLUG_STATUS = 0x30,    /**< ��������״̬���������ݲο�enum DEVICE_PLUG_STATUS_ID  ��ض��塣@see DEVICE_PLUG_STATUS_ID*/
    MCU_MSG_RET_AUDIO_VOLUME_INFO = 0x31,           /**< ����������Ϣ���������ݲο�struct AUDIO_VOLUME_INFO  ��ض��塣@see AUDIO_VOLUME_INFO*/
    MCU_MSG_RET_AUDIO_POPUP_INFO = 0x32,            /**< ����DISK/AUX������Ϣ���������ݲο�enum POPUP_INFO_ID  ��ض��塣@see POPUP_INFO_ID*/

    MCU_MSG_RET_RADIO_COLLECTED_INFO = 0x4C,        /**< �����ղص�̨��Ϣ���������ݲο�struct RADIO_COLLECTED_INFO ��ض��塣@see RADIO_COLLECTED_INFO*/
    MCU_MSG_RET_RADIO_NOTIFY = 0x50,                /**< ���ص�ǰ���Ρ�״̬��Ԥ��̨��Ƶ����Ϣ���������ݲο�struct RADIO_NOTIFY  ��ض��塣@see RADIO_NOTIFY*/
    MCU_MSG_RET_RADIO_PRESET_INFO = 0x51,           /**< ���ز��ζ�ӦԤ���̨��Ϣ���������ݲο�struct RADIO_PRESET_INFO  ��ض��塣@see RADIO_PRESET_INFO*/

	MCU_MSG_RET_IGN_ON_OFF_STATUS = 0x7F,           /**< ����IGN_ON_OF״̬���������ݲο�struct IGN_ON_OFF_INFO ��ض��塣@see IGN_ON_OFF_INFO*/
	
    MCU_MSG_RET_COREBOARD_RESUME_INFO = 0x81,       /**< ���غ��İ�ָ�����״̬��Ϣ���������ݲο�struct COREBOARD_RESUME_INFO  ��ض��塣@see COREBOARD_RESUME_INFO*/
    MCU_MSG_RET_BLUETOOTH_STATUS = 0x90,            /**< ���ص�ǰ����״̬���������ݲο�struct BLUETOOTH_STATUS_INFO  ��ض��塣@see BLUETOOTH_STATUS_INFO*/

    MCU_MSG_RET_TFT_VIDEO_SOURCE = 0xA1,            /**< ������Ƶ�����ź�Դ���������ݲο�struct VIDEO_SOURCE_INFO  ��ض��塣@see VIDEO_SOURCE_INFO*/
    MCU_MSG_RET_TFT_LANGUAGE = 0xA3,                /**< ���ص�ǰ����״̬���������ݲο�enum LANGUAGE_ID  ��ض��塣@see LANGUAGE_ID*/
    MCU_MSG_RET_TFT_ILL_MODE = 0xA5,                /**< ���ذ����ҹ���ģʽ���������ݲο�enum ILL_MODE_ID  ��ض��塣@see ILL_MODE_ID*/
    MCU_MSG_RET_TFT_BACKLIGHT_STATUS = 0xA7,        /**< ���ر��⿪��״̬���������ݲο�enum BACKLIGHT_STATUS_ID  ��ض��塣@see BACKLIGHT_STATUS_ID*/
    MCU_MSG_RET_TFT_BRIGHTNESS_STATUS = 0xA9,       /**< ��������ֵ����������Ϊunsigned char ��*/
    MCU_MSG_RET_TFT_CONTRAST_STATUS = 0xAB,         /**< ���ضԱȶ�ֵ����������Ϊunsigned char ��*/
    
    MCU_MSG_RET_AVM_SETTING_INFO = 0xB2,            /**< ����AVM���ò�����Ϣ���������ݲο�struct AVM_SETTING_INFO  ��ض��塣@see AVM_SETTING_INFO*/
    MCU_MSG_RET_MHL_SIGNAL_DET = 0xC0,              /**< �����ֻ�����״̬���������ݲο�enum MHL_SIGNAL_STATUS_ID  ��ض��塣@see MHL_SIGNAL_STATUS_ID*/

    MCU_MSG_RET_AVM_DATA_INFO = 0xF0,               /**< ���ؽ��յ���AVM���ݣ��������ݲο�struct AVM_DATA_INFO  ��ض��塣@see AVM_DATA_INFO*/

    MCU_MSG_RET_ENHOST_CAN = 0xF6,                  /**< ����L5��ĿCAN�����Ϣ,��Ϊ����L5���� */
    MCU_MSG_RET_FCC_CAN = 0xF7,                     /**< ����L5��ĿFCC CAN�����Ϣ,��Ϊ����L5���� */
    MCU_MSG_RET_RCC_CAN = 0xF8,                     /**< ����L5��ĿRCC CAN�����Ϣ,��Ϊ����L5���� */
    
    MCU_MSG_RET_MCAN_INFO = 0xFD,                   /**< ����MCAN ��Ϣ���������ݲο�struct MCAN_INFO  ��ض��塣@see MCAN_INFO*/
    MCU_MSG_RET_HVAC_INFO = 0xFA,                 /**< ���ؿյ�״̬��Ϣ���������ݲο�struct HVAC_INFO ��ض��塣@see HVAC_INFO*/
    MCU_MSG_RET_HVAC_DIAG_INFO = 0xFB,              /**< ���ؿյ������Ϣ���������ݲο�struct HVAC_DIAG_INFO  ��ض��塣@see HVAC_DIAG_INFO*/
    MCU_MSG_RET_IT_COMMANDER_INFO = 0xFC,           /**< ���ض๦����ť������Ϣ���������ݲο�struct IT_COMMANDER_INFO  ��ض��塣@see IT_COMMANDER_INFO*/
    MCU_MSG_MAX_ID = 0xFF,
}MCU_MSG_ID;

/** 
  *  @struct PACKET_MSG
  *  @brief �������ݰ���Ϣ
  */ 
typedef struct {
    MCU_MSG_ID mcu_msg_id;      /**< MCU ��Ϣʶ���룬�ο�MCU_MSG_ID  ��ض��塣@:: MCU_MSG_ID*/
    unsigned char size;         /**< ���ݰ�����data ��Ч�ֽڴ�С*/
    unsigned char data[256];    /**< ���ݰ�����*/
}PACKET_MSG;
/**@}*/
  
/**
  * @addtogroup  Mcu_Agent_Typedef
  * @{
  */
  
/** 
  *  @struct MB_VERSION_INFO
  *  @brief ����汾��Ϣ
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
  *  @brief ������Ϣ����
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
  *  @brief �������Ͷ���
  */
typedef enum {
    TOUCH_TYPE_DOWN = 0x00,
    TOUCH_TYPE_UP,
    TOUCH_TYPE_MAX_ID,
}TOUCH_TYPE_ID;

/** 
  *  @struct TOUCH_INFO
  *  @brief ��Ļ����������Ϣ
  */
typedef struct {
    unsigned short x;
    unsigned short y;
    TOUCH_TYPE_ID type;
}TOUCH_INFO;

/** 
  *  @enums
  *  @brief �������ģʽ����
  */
typedef enum {
    ENGINEER_MODE_EXIT = 0x00,
    ENGINEER_MODE_ENTRY,
    ENGINEER_MODE_MAX_ID,
}ENGINEER_MODE_ID;

/** 
  *  @enums
  *  @brief  beep ������״̬����
  */
typedef enum {
    BEEP_TONE_NORMAL = 0x00,
    BEEP_TONE_WARNING,
    BEEP_TONE_ERROR,
    BEEP_TONE_MAX_ID,
}BEEP_TONE_ID;

/** 
  *  @enums
  *  @brief  �ػ�ʱ��ʱ����ʾ״̬����
  */
typedef enum {
    DISP_STATUS_OFF = 0x00,
    DISP_STATUS_ON,
    DISP_STATUS_MAX_ID,
}DISP_STATUS_ID;

/** 
  *  @enums
  *  @brief  ʡ��ģʽʱ��Ļ����״̬����
  */
typedef enum {
    SCREEN_SAVE_MODE_MAX_ID,
}SCREEN_SAVE_MODE_ID;

/** 
  *  @enums
  *  @brief  ��ȡ�汾���Ͷ���
  */
typedef enum {
    VERSION_TYPE_HMI = 0x00,
    VERSION_TYPE_BT,
}VERSION_TYPE_ID;

/** 
  *  @struct VERSION_INFO
  *  @brief HMI/BT�汾��Ϣ
  */
typedef struct {
    VERSION_TYPE_ID type;
    char version_buffer[64];
    unsigned char size;
}VERSION_INFO;

/** 
  *  @enums
  *  @brief  ���忪�ػ�״̬����
  */
typedef enum {
    POWER_STATUS_OFF = 0x00,
    POWER_STATUS_ON,
    POWER_STATUS_MAX_ID,
}POWER_STATUS_ID;

/** 
  *  @enums
  *  @brief  ���ػ�״̬ģʽ����
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
  *  @brief ���ػ�״̬��Ϣ
  */
typedef struct {
    POWER_STATUS_ID power_status;
    POWER_MODE_ID power_mode;
}POWER_INFO;

/** 
  *  @enums
  *  @brief  RTC ģʽ���Ͷ���
  */
typedef enum {
    RTC_MODE_12HOURS = 0x00,
    RTC_MODE_24HOURS,
    RTC_MODE_SET_CLOCK,
    RTC_MODE_MAX_ID,
}RTC_MODE_ID;

/** 
  *  @struct CLOCK_MSG
  *  @brief ʱ����Ϣ
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
  *  @brief RTC ʱ����Ϣ
  */
typedef struct {
    RTC_MODE_ID rtc_mode;
    CLOCK_MSG clock_msg;
}RTC_MSG;

/** 
  *  @struct SETUP_PARAM_INFO
  *  @brief ���ò�����Ϣ
  */
typedef struct {
    unsigned char size;
    unsigned char param_info[255];
}SETUP_PARAM_INFO;

/** 
  *  @enums
  *  @brief ��Ƶ�ź�Դ����
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
  *  @brief ��Ƶ�������Ͷ���
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
  *  @brief ��Ƶ����������Ϣ
  */
typedef struct {
    AUDIO_SETTING_TYPE_ID type;
    unsigned char value;
}AUDIO_SETTING_TYPE_INFO;

/** 
  *  @struct AUDIO_SETTING_INFO
  *  @brief ��Ƶ������Ϣ
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
  *  @brief AUX���������������
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
  *  @brief beep ����״̬����
  */
typedef enum {
    BEEP_STATUS_OFF = 0x00,
    BEEP_STATUS_ON,
    BEEP_STATUS_MAX_ID,
}BEEP_STATUS_ID;

/** 
  *  @enums
  *  @brief ��������������������
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
  *  @brief ������������״̬����
  */
typedef enum {
    NAVI_MIX_STATUS_START = 0x00,   
    NAVI_MIX_STATUS_END = 0x01,
    
    NAVI_MIX_STATUS_MAX_ID, 
}NAVI_MIX_STATUS_ID;

/** 
  *  @enums
  *  @brief ����״̬����
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
  *  @brief ����������������
  */
typedef enum {
    ADJUST_VOLUME_DOWN = 0x00,
    ADJUST_VOLUME_UP,
    ADJUST_VOLUME_MAX_ID,
}ADJUST_VOLUME_ID;

/** 
  *  @enums
  *  @brief ������Ϣ���Ͷ���
  */
typedef enum {
    AUDIO_VOLUME_INFO_TYPE_CUR_VOL = 0x00,
    AUDIO_VOLUME_INFO_TYPE_ON,
    AUDIO_VOLUME_INFO_TYPE_OFF,
}AUDIO_VOLUME_INFO_TYPE_ID;

/** 
  *  @struct AUDIO_VOLUME_INFO
  *  @brief ������Ϣ
  */
typedef struct {
    AUDIO_VOLUME_INFO_TYPE_ID type;
    unsigned char values;
}AUDIO_VOLUME_INFO;

/** 
  *  @enums
  *  @brief DISK/AUX������Ϣ����
  */
typedef enum {
    POPUP_INFO_NO_DISK = 0x00,
    POPUP_INFO_NO_AUX,
}POPUP_INFO_ID;

/** 
  *  @enums
  *  @brief Radio ����APS��SCAN �������ƶ���
  */
typedef enum {
    RADIO_CTRL_APS = 0x00,
    RADIO_CTRL_SCAN,
    RADIO_CTRL_MAX_ID,
}RADIO_CTRL_ID;

/** 
  *  @enums
  *  @brief Radio ���ζ���
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
  *  @brief Radio ��ǰ״̬����
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
  *  @brief Radio ��ǰ���Ρ�״̬��Ԥ��̨��Ƶ����Ϣ
  */
typedef struct {
    RADIO_BAND_ID band;
    unsigned char preset_num;
    RADIO_STATUS_ID status;
    unsigned long cur_freq;
}RADIO_NOTIFY;

/** 
  *  @struct RADIO_PRESET_INFO
  *  @brief ���ζ�ӦԤ���̨��Ϣ
  */
typedef struct {
    RADIO_BAND_ID band;
    unsigned long preset_freq[7];
    unsigned char preset_num;
}RADIO_PRESET_INFO;

/** 
  *  @struct RADIO_COLLECTED_INFO
  *  @brief �ղص�̨��Ϣ
  */
typedef struct {
    unsigned char size;
    unsigned char content[64];
}RADIO_COLLECTED_INFO;

/** 
  *  @enums
  *  @brief IGN ��ǰ״̬����
  */
typedef enum
{
    IGN_STATUS_OFF = 0x00,
    IGN_STATUS_ON = 0X01,
}IGN_STATUS;

/** 
  *  @struct IGN_ON_IFF_INFO
  *  @brief IGN״̬��Ϣ
  */
typedef struct {
    IGN_STATUS ign_status;
}IGN_ON_OFF_INFO;


/** 
  *  @struct COREBOARD_RESUME_INFO
  *  @brief ���İ�ָ�����״̬��Ϣ
  */
typedef struct {
   unsigned short address_offset;
   unsigned short length;
   unsigned char data[128];
}COREBOARD_RESUME_INFO;

/** 
  *  @enums
  *  @brief ��ǰ����״̬���Ͷ���
  */
typedef enum {
    BLUETOOTH_TYPE_HFP = 0x00,
    BLUETOOTH_TYPE_HID_SPP,
    BLUETOOTH_TYPE_POWER_SETUP,
}BLUETOOTH_TYPE_ID;

/** 
  *  @enums
  *  @brief ��ǰ����״̬����
  */
typedef enum {
    BLUETOOTH_STATUS_OFF = 0x00,
    BLUETOOTH_STATUS_ON,
}BLUETOOTH_STATUS_ID;

/** 
  *  @struct BLUETOOTH_STATUS_INFO
  *  @brief ��ǰ����״̬��Ϣ
  */
typedef struct {
    BLUETOOTH_TYPE_ID type;
    BLUETOOTH_STATUS_ID status;
}BLUETOOTH_STATUS_INFO;

/** 
  *  @enums
  *  @brief ��Ƶ�����ź�Դ����
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
  *  @brief ��Ƶ�����ź�Դ���͸�ʽ����
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
  *  @brief  ��Ƶ�����ź�Դ��Ϣ
  */
typedef struct {
    VIDEO_SOURCE_ID video_source;
    VIDEO_TYPE_ID video_type;
}VIDEO_SOURCE_INFO;

/** 
  *  @struct AVM_DATA_INFO
  *  @brief �洢AVM����
  */
typedef struct {
    unsigned char size;
    unsigned char content[128];
}AVM_DATA_INFO;


/** 
  *  @enums
  *  @brief ��ǰ�������Ͷ���
  */
typedef enum {
    LANGUAGE_CHINESE = 0x00,
    LANGUAGE_ENGLISH,
    LANGUAGE_MAX_ID,
}LANGUAGE_ID;

/** 
  *  @enums
  *  @brief TFT �����ҹ���ģʽ����
  */
typedef enum {
    ILL_MODE_AUTO = 0x00,
    ILL_MODE_FORCE_DAY,
    ILL_MODE_FORCE_NIGHT,
    ILL_MODE_MAX_ID,
}ILL_MODE_ID;

/** 
  *  @enums
  *  @brief TFT ����״̬����
  */
typedef enum {
    BACKLIGHT_STATUS_OFF = 0x00,
    BACKLIGHT_STATUS_ON,
    BACKLIGHT_STATUS_MAX_ID,
}BACKLIGHT_STATUS_ID;

/** 
  *  @enums
  *  @brief AVM �������Ͷ���
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
  *  @brief AVM ģ����ɫ����
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
  *  @brief  AVM ����������Ϣ
  */
typedef struct {
    AVM_SETTING_TYPE_ID type;
    unsigned char value;
}AVM_SETTING_TYPE_INFO;

/** 
  *  @struct AVM_SETTING_INFO
  *  @brief  AVM ������Ϣ
  */
typedef struct {
    unsigned char hw_version;
    unsigned char sw_version_h;
    unsigned char sw_version_l;
    unsigned char wheelpath;
    unsigned char frist_drive_auto_setup;
    unsigned char boot_animation;
    unsigned char model_color;      /**< AVM ģ����ɫ���ο�AVM_MODEL_COLOR_ID*/
    unsigned char brightness;
    unsigned char contrast;
    unsigned char chromatic;    
}AVM_SETTING_INFO;

/** 
  *  @enums
  *  @brief �ֻ����ӵ��������Ͷ���
  */
typedef enum {
    MHL_POP_TYPE_MIRROR_BOX = 0x00,
    MHL_POP_TYPE_INTELLIGENT_BOX, 
}MHL_POP_TYPE_ID;

/** 
  *  @enums
  *  @brief �ֻ������ź�״̬����
  */
typedef enum {
   MHL_SIGNAL_NO_DETECTED = 0x00,
   MHL_SIGNAL_DETECTED,
}MHL_SIGNAL_STATUS_ID;

/** 
  *  @enums
  *  @brief ���¹̼����Ͷ���
  */
typedef enum {
    UPDATE_TYPE_OSD = 0x01,
    UPDATE_TYPE_MD = 0xAA,
}UPDATE_TYPE_ID;

/** 
  *  @enums
  *  @brief �԰����������� ����
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
  *  @brief  MCAN ��Ϣ����
  */
typedef struct {
    char *data;
}MCAN_INFO;

/** 
  *  @enums
  *  @brief �յ�ģʽ����
  */
typedef enum {
    HVAC_MODE_NO_DISPLAY = 0x00,    /**< ����ʾ */
    HVAC_MODE_BLOW_FACE,            /**< ����ģʽ */
    HVAC_MODE_BLOW_FACE_FEET,       /**< ����/����ģʽ */
    HVAC_MODE_BLOW_FEET,            /**< ����ģʽ */
    HVAC_MODE_BLOW_FEET_DEFROST,    /**< ���ų�˪ģʽ */
    HVAC_MODE_MAX_ID,
}HVAC_MODE_ID;

/** 
  *  @struct HVAC_INFO
  *  @brief  �յ�����״̬��Ϣ����
  */
typedef struct {
    unsigned char maxAC_on_off;         /**< MAX AC ����״̬��1 ������0 �ر� */
    unsigned char AC_on_off;            /**< AC  ����״̬��1 ������0 �ر� */
    unsigned char recirc_on_off;        /**< ��ѭ�� ����״̬��1 ������0 �ر� */
    unsigned char fresh_on_off;         /**< ��ѭ������״̬��1 ������0 �ر� */
    unsigned char dual_on_off;          /**< ˫��ģʽ����״̬��1 ������0 �ر� */ 
    unsigned char ACT_on_off;           /**< �Ŵ��� ����״̬��1 ������0 �ر� */
    unsigned char redefrost_on_off;     /**< ���˪����״̬��1 ������0 �ر� */
    unsigned char defrost_on_off;       /**< ǰ��˪����״̬��1 ������0 �ر� */
    unsigned char display_on_off;       /**< ��ʾ ����״̬��1 ������0 �ر� */
    unsigned char blower_level;         /**< �ķ��������0-8, 0��ʾ�ر� */
    unsigned char left_temp;            /**< �����¶ȣ�0-16, 0��ʾ����ʾ */
    unsigned char right_temp;           /**< �����¶ȣ�0-16, 0��ʾ����ʾ */
    HVAC_MODE_ID hvac_mode;             /**< �յ�ģʽ,�ο�HVAC_MODE_ID ���� */
}HVAC_INFO;

/** 
  *  @enums
  *  @brief �յ�����״̬����
  */
typedef enum {
    HVAC_KEY_STATUS_DOWN = 0x00,    /**< �������� */
    HVAC_KEY_STATUS_UP,             /**< ����̧�� */
    
    HVAC_KEY_STATUS_MAX_ID,
}HVAC_KEY_STATUS_ID;

/** 
  *  @struct HVAC_STATUS
  *  @brief  �յ�����״̬��Ϣ����
  */
typedef struct {
    HVAC_KEY_STATUS_ID maxAC;                           /**< MAX AC ����״̬*/
    HVAC_KEY_STATUS_ID AC;                              /**< AC ����״̬*/
    HVAC_KEY_STATUS_ID recirc;                          /**< ��ѭ������״̬*/
    HVAC_KEY_STATUS_ID fresh;                           /**< ��ѭ������״̬*/
    HVAC_KEY_STATUS_ID defrost;                         /**< ǰ��˪����״̬*/
    HVAC_KEY_STATUS_ID mode;                            /**< ģʽ����״̬*/
    HVAC_KEY_STATUS_ID front_panel_left_temp_minus;     /**< ǰ��������¶ȼ�����״̬*/
    HVAC_KEY_STATUS_ID front_panel_letf_tmep_plus;      /**< ǰ��������¶ȼӰ���״̬*/
    
    HVAC_KEY_STATUS_ID front_panel_blower_minus;        /**< ǰ������������״̬*/
    HVAC_KEY_STATUS_ID front_panel_blower_plus;         /**< ǰ�������Ӱ���״̬*/
    HVAC_KEY_STATUS_ID touch_panel_blower_minus;        /**< ����������������״̬*/
    HVAC_KEY_STATUS_ID touch_panel_blower_plus;         /**< �����������Ӱ���״̬*/
    unsigned char target_blower_level;                  /**< Ŀ�������0-8��0��ʾ�޴���������*/

    HVAC_KEY_STATUS_ID dual;                            /**< ˫�������ܰ���״̬*/
    HVAC_KEY_STATUS_ID on_off;                          /**< On/Off ���ܰ���״̬*/
    HVAC_KEY_STATUS_ID redefrost;                       /**< ���˪����״̬*/
    HVAC_KEY_STATUS_ID front_panel_right_temp_minus;    /**< ǰ��������¶ȼ�����״̬*/
    HVAC_KEY_STATUS_ID front_panel_right_tmep_plus;     /**< ǰ��������¶ȼӰ���״̬*/
    
    HVAC_KEY_STATUS_ID touch_panel_left_temp_minus;     /**< �����������¶ȼ�����״̬*/
    HVAC_KEY_STATUS_ID touch_panel_letf_tmep_plus;      /**< �����������¶ȼӰ���״̬*/
    unsigned char touch_panel_target_letf_tmep;         /**< ����������Ŀ���¶ȣ�0-16��0��ʾ�޴���������*/
    HVAC_KEY_STATUS_ID touch_panel_right_temp_minus;    /**< �����������¶ȼ�����״̬*/
    HVAC_KEY_STATUS_ID touch_panel_right_tmep_plus;     /**< �����������¶ȼӰ���״̬*/
    unsigned char touch_panel_target_right_tmep;        /**< ����������Ŀ���¶ȣ�0-16��0��ʾ�޴���������*/
}HVAC_STATUS;

/** 
  *  @enums 
  *  @brief  �յ���Ͽ��ƶ�����
  */
typedef enum {
 HAVC_DIAG_CTRL_OBJ_BLOWER_SYS = 0x01,                      /**< �ķ��ϵͳ*/
 HAVC_DIAG_CTRL_OBJ_MODE_DAMPER_MOTER = 0x02,               /**< ģʽ�������*/
 HAVC_DIAG_CTRL_OBJ_INSIDE_OUTSIDE_DAMPER_MOTER = 0x03,     /**< �������������*/
 HAVC_DIAG_CTRL_OBJ_MIXED_DAMPER_MOTER_LEFT = 0x04,         /**< ��Ϸ��������*/
 HAVC_DIAG_CTRL_OBJ_MIXED_DAMPER_MOTER_RIGHT = 0x05,        /**< ��Ϸ��������*/
 HAVC_DIAG_CTRL_OBJ_EVAPORATOR_TEMPERATURE_SENSOR = 0x06,   /**< �������¶ȴ�����*/
 HAVC_DIAG_CTRL_OBJ_INDICATOR_LIGHT_CHECK = 0x07,           /**< ָʾ�Ƽ��*/
 HAVC_DIAG_CTRL_OBJ_KEY_VALUE = 0x08,                       /**< �յ��������*/
}HVAC_DIAG_CTRL_OBJ_ID;

/** 
  *  @enums 
  *  @brief �յ���� �����Ԫ�������ģʽ����
  */
typedef enum {
    HVAC_DIAG_CTRL_MODE1 = 0x01,    /**< ģʽ1������-����ȫ��-�һ��ȫ��-��ѭ��-����7��*/
    HVAC_DIAG_CTRL_MODE2,           /**< ģʽ2������-����ȫ��-�һ��ȫ��-��ѭ��-����1��*/
    HVAC_DIAG_CTRL_MODE3,           /**< ģʽ3����˪-�����м�-�һ���м�-��ѭ��-����4��*/
}HVAC_DIAG_CTRL_UT_MODE_ID;

/** 
  *  @struct HVAC_INFO
  *  @brief  �յ���Ͽ�����Ϣ����
  */
typedef struct {
    HVAC_DIAG_CTRL_OBJ_ID obj;  /**< �յ���Ͽ��ƶ��󣬲ο�enum HVAC_DIAG_CTRL_OBJ_ID ��ض���*/
    unsigned char light_status; /**< ָʾ�Ƽ��״̬(0x01��/0x00��) */
    unsigned char reserver[2];  /**< Ԥ���ֽ� */
}HVAC_DIAG_CTRL_INFO;

/** 
  *  @enums 
  *  @brief �յ���� ״̬����
  */
typedef enum {
    HVAC_DIAG_STATUS_NON_EXECUTION = 0x40,  /**< δִ����Ͽ��� */
    HVAC_DIAG_STATUS_APPLY_SUCCESS = 0x41,  /**< �������ɹ� */
    HVAC_DIAG_STATUS_DOING_EXECUTION = 0x42, /**< ������ڽ����� */
    HVAC_DIAG_STATUS_DONE_EXECUTION = 0x43, /**< �����ɣ����Զ�ȡ������ֽڵĴ����� */
}HVAC_DIAG_STATUS_ID;

/** 
  *  @enums 
  *  @brief �յ���� �����붨��
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
  *  @brief �յ���Ͻ����Ϣ����
  */
typedef struct {
    HVAC_DIAG_STATUS_ID status;
    HVAC_DIAG_CTRL_OBJ_ID obj;
    HVAC_DIAG_FAULT_CODE_ID code;
}HVAC_DIAG_INFO;

/** 
  *  @enums 
  *  @brief �๦����ťencoder ��Ϣ����
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
  *  @brief �๦����ťdirections ��Ϣ����
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
  *  @brief  �๦����ť������Ϣ����
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
  *  @brief  MCU Agent API ��Ա�ṹ��
  */ 
typedef struct {

/**
  * @brief      HMIӦ�������ɹ��󣬷��ʹ���Ϣ֪ͨ���塣 
  * @param    void  ��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*hmi_startup)(void);

/**
  * @brief      NAVIӦ�������ɹ��󣬷��ʹ���Ϣ֪ͨ���塣
  * @param    void  ��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*navi_startup)(void);

/**
  * @brief      �����巢������ͬ�����ݣ������ѵ�ǰ�������ݷ��͸����İ塣
  * @param    void  ��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_sync_info)(void);

/**
  * @brief      ��ȡ����ϵͳ�İ汾��Ϣ��
  * @param    void  ��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_mainboard_version_info)(void);

/**
  * @brief     ����ģ�ⰴ�������塣
  * @param    key ģ�ⰴ��ID���ο�KEY_ID��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_hard_key)(HARD_KEY_ID key);

/**
  * @brief      ���ʹ�����������塣
  * @param    info ����������Ϣ���ο�TOUCH_INFO��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_touch)(TOUCH_INFO *info);

/**
  * @brief      ������˳��������ģʽ��
  * @param    status ������˳�״̬,�ο�ENGINEER_MODE_ID.
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_engineer_mode)(ENGINEER_MODE_ID status);

/**
  * @brief      �������巢��beep ����������
  * @param    status ����״̬���ο�BEEP_TONE_ID��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*beep_tone)(BEEP_TONE_ID status);

/**
  * @brief      ���ùػ�ʱ��ʱ����ʾ�Ŀ���״̬��
  * @param    status ʱ����ʾ״̬, �ο�DISP_STATUS_ID��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*poweroff_timer_disp)(DISP_STATUS_ID status);

/**
  * @brief      ���͵�ǰ��Ļ����ģʽ;ʡ��ģʽ
  * @param    mode ��ǰ��Ļ���淽ʽ, �ο�SCREEN_SAVE_MODE_ID��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_screen_save_mode)(SCREEN_SAVE_MODE_ID mode);

/**
  * @brief      ����������Ӧ������
  * @param    void �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*send_alive)(void);

/**
  * @brief      ����HMI ��BT �İ汾��Ϣ�����塣
  * @param    info �汾��Ϣ,�ο�VERSION_INFO��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*send_version_info)(VERSION_INFO *info);

/**
  * @brief      �������忪�ػ�״̬��
  * @param    status ���ػ�״̬, �ο�POWER_STATUS_ID��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_audio_power)(POWER_STATUS_ID status);

/**
  * @brief      ��ȡ���忪�ػ�״̬��
  * @param    void   ��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_audio_power)(void);

/**
  * @brief      ����RTC ʱ����ʾģʽ��
  * @param    mode ʱ����ʾģʽ(12Сʱ��/24Сʱ��)���ο�RTC_MODE_ID��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_rtc_mode)(RTC_MODE_ID mode);

/**
  * @brief      ����RTC ʱ�䡣
  * @param    clock_msg  ����RTC ��ʱ�䣬�ο�CLOCK_MSG��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_rct_clock)(CLOCK_MSG *clock_msg);

/**
  * @brief      ��ȡRTC  ʱ�䡣
  * @param    void  �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_rct_clock)(void);

/**
  * @brief      ����GPS ʱ�䡣
  * @param    clock_msg  ����GPS ��ʱ�䣬�ο�CLOCK_MSG��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_gps_clock)(CLOCK_MSG *clock_msg);

/**
  * @brief      ��ȡGPS  ʱ�䡣
  * @param    void  �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_gps_clock)(void);
/**
  * @brief      �������ò˵�������Ϣ��
  * @param    info  ���ò˵�������Ϣ, �ο�SETUP_PARAM_INFO��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_setup_param_info) (SETUP_PARAM_INFO *info);
    
/**
  * @brief      �����������ƵԴ��
  * @param    audio_source ��ƵԴ���ο�AUDIO_SOURCE_ID ��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_audio_source)(AUDIO_SOURCE_ID audio_source);

/**
  * @brief      ��ȡ�������ƵԴ��
  * @param    void  �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_audio_source)(void);

/**
  * @brief      �����������Ƶ������Ϣ��
  * @param    info ��ƵԴ������Ϣ���ο�AUDIO_SETTING_TYPE_INFO ��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_audio_setting_info)(AUDIO_SETTING_TYPE_INFO *info);

/**
  * @brief      ��ȡ�������Ƶ������Ϣ��
  * @param    void  �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_audio_setting_info)(void);

/**
  * @brief      ���������AUX �������������
  * @param    level AUX �����������,�ο�AUDIO_AUX_GAIN_ID ��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_audio_aux_gain)(AUDIO_AUX_GAIN_ID level);

/**
  * @brief      ��ȡ�����AUX �������������
  * @param    void  �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_audio_aux_gain)(void);

/**
  * @brief      ���������beep ����״̬��
  * @param    status beep����״̬���ο�BEEP_STATUS_ID ��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_audio_beep)(BEEP_STATUS_ID status);

/**
  * @brief      ��ȡ�����beep ����״̬��
  * @param    void  �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_audio_beep)(void);

/**
  * @brief      ��������ĳ�����������������
  * @param    level  �������������������ο�AUDIO_SPEED_VOLUME_ID��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_audio_speed_volume)(AUDIO_SPEED_VOLUME_ID level);

/**
  * @brief      ��ȡ����ĳ�����������������
  * @param    void  �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_audio_speed_volume)(void);
  
/**
  * @brief      ��ȡ����ĳ��١�
  * @param    void  �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_audio_speed)(void);

/**
  * @brief      �������嵼����������״̬��
  * @param    status  ������������״̬���ο�NAVI_MIX_STATUS_ID��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
  
    int (*set_audio_navi_mix_status) (NAVI_MIX_STATUS_ID status);
    
/**
  * @brief      ��ȡAUX�ӿڵİγ������״̬��
  * @param    void  �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_aux_plug_status)(void);
 
/**
  * @brief      ��������������Ӽ���
  * @param    status �����Ӽ�״̬���ο�ADJUST_VOLUME_ID��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_adjust_volume)(ADJUST_VOLUME_ID status);

/**
  * @brief      ���õ�ǰ����Ƶ�ʲ�����
  * @param    freq Ƶ�ʲ��� ��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_radio_freq)(unsigned short freq);
    
/**
  * @brief     ���õ�ǰ�����Զ�������̨��
  * @param    void  �� ��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_radio_seek_up)(void);

/**
  * @brief     ���õ�ǰ�����Զ�������̨��
  * @param    void  �� ��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_radio_seek_down)(void);

/**
  * @brief     ���õ�ǰ�������ϵ���΢����
  * @param    void  �� ��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_radio_manual_up)(void);

/**
  * @brief     ���õ�ǰ�������µ���΢��
  * @param    void  �� ��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_radio_manual_down)(void);

/**
  * @brief      ���ƽ���APS��SCAN����
  * @param    status APS,SCAN ����״̬���ο�RADIO_CTRL_ID��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_radio_ctrl)(RADIO_CTRL_ID status);

/**
  * @brief      ����Ԥ���̨
  * @param    preset_num Ԥ���̨���1~6��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*call_radio_preset_num)(unsigned char preset_num);

/**
  * @brief      ����Ԥ���̨
  * @param    preset_num Ԥ���̨���1~6��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*save_radio_preset_num)(unsigned char preset_num);

/**
  * @brief      ����ת��
  * @param    void �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*change_radio_band)(void);

/**
  * @brief	    ��������
  * @param	  void �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*radio_fastseek_up)(void);

/**
  * @brief		��������
  * @param	  void �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*radio_fastseek_down)(void);

/**
  * @brief      �����ղص�̨��Ϣ
  * @param    info �ղص�̨��Ϣ,�ο�RADIO_COLLECTED_INFO��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*save_radio_collected_info)(RADIO_COLLECTED_INFO *info);

    
/**
  * @brief      ��ȡ��ǰ���Ρ�״̬��Ԥ��̨��Ƶ����Ϣ
  * @param    void �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_radio_notify)(void);

/**
  * @brief      ��ȡ���ζ�ӦԤ���̨��Ϣ
  * @param    band ����ID���ο�RADIO_BAND_ID��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_radio_preset_info)(RADIO_BAND_ID band);

/**
  * @brief      ��ȡIGN ON_OFF״̬��Ϣ(CMF-B);
  * @param    void �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_ign_on_off_status)(void);


/**
  * @brief      ���ͺ��İ�ָ�����״̬��Ϣ;
  * @param    info  ���İ�ָ�����״̬��Ϣ,�ο�COREBOARD_RESUME_INFO��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_coreboard_resume_info)(COREBOARD_RESUME_INFO *info);

/**
  * @brief     ��ȡ���İ�ָ�����״̬��Ϣ;
  * @param    address_offset  ��ʼ��ַƫ������
  * @param    length  ״̬��Ϣ���ݳ��ȡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_coreboard_resume_info)(unsigned short address_offset, unsigned short length);

/**
  * @brief      ���͵�ǰ����״̬
  * @param    info  ����״̬���ο�BLUETOOTH_STATUS_INFO��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*send_bluetooth_status)(BLUETOOTH_STATUS_INFO *info);

/**
  * @brief      �趨��Ƶ�����ź�Դ
  * @param    info ��Ƶ�����ź�Դ���ο�VIDEO_SOURCE_INFO ��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_video_source)(VIDEO_SOURCE_INFO *info);

/**
  * @brief     ��ȡ��Ƶ�����ź�Դ
  * @param    void  �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_video_source)(void);

/**
  * @brief     �趨����״̬��
  * @param    languege_id  ����״̬ID ���ο�LANGUAGE_ID��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_language)(LANGUAGE_ID languege_id);

/**
  * @brief     ��ȡ��ǰ����״̬��
  * @param    void  �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_language)(void);

/**
  * @brief      �趨�����ҹ���ģʽ
  * @param    mode  �����ҹ���ģʽ���ο�IIL_MODE_ID��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_ILL_mode)(ILL_MODE_ID mode);

/**
  * @brief     ��ȡ�����ҹ���ģʽ��
  * @param    void  �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_ILL_mode)(void);

/**
  * @brief      �趨���⿪��״̬
  * @param    status  ���⿪��״̬���ο�BACKLIGHT_STATUS_ID��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_backlight_status)(BACKLIGHT_STATUS_ID status);
 
/**
  * @brief     ��ȡ���⿪��״̬
  * @param    void  �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_backlight_status)(void);
  
/**
  * @brief      �趨����ֵ
  * @param    value  ����ֵ0~100
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_brightness)(unsigned char value);

/**
  * @brief     ��ȡ����ֵ��
  * @param    void  �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_brightness)(void);
 
/**
  * @brief     �趨�Աȶ�ֵ
  * @param    value  �Աȶ�ֵ0~100
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_contrast)(unsigned char value);
 
/**
  * @brief     ��ȡ�Աȶ�ֵ��
  * @param    void  �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_contrast)(void);

/**
  * @brief      �˳�AVM���ò˵���
  * @param    void  �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*send_AVM_setting_menu_exit)(void);
 
/**
  * @brief      ����AVM���ò�����Ϣ
  * @param    info  AVM���ò�����Ϣ���ο�AVM_SETTING_INFO��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_AVM_setting_info)(AVM_SETTING_TYPE_INFO *info);
 
/**
  * @brief     ��ȡAVM���ò�����Ϣ
  * @param    void  �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*get_AVM_setting_info)(void);
 
/**
  * @brief      ����AVM�ָ�Ĭ������
  * @param    void  �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_AVM_default_setting)(void);

/**
  * @brief      �趨�ֻ����ӵ���������
  * @param    type  �ֻ����ӵ��������ͣ��ο�MHL_POP_TYPE_ID ��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_MHL_pop_type)(MHL_POP_TYPE_ID type);

/**
  * @brief      ��������̼� 
  * @param    type  ���¹̼����ͣ��ο�UPDATE_TYPE_ID��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*update_mainboard_firmware)(UPDATE_TYPE_ID type);

/**
  * @brief      ��������ָ�����Ĭ������
  * @param    void  �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_mainboard_default_setting)(void);

/**
  * @brief      �����԰����������� 
  * @param    freq �����������Ƶ�ʱ仯ID���ο�SPEAKER_FREQ_ID��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*set_speaker_diag)(SPEAKER_FREQ_ID freq);

/**
  * @brief		�����̨��Ϣ
  * @param	  info ������յ��ĵ�̨��Ϣ,�ο�AVM_DATA_INFO��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*save_avm_data_info)(AVM_DATA_INFO *info);

/**
  * @brief      ����MCAN ��Ϣ
  * @param    mcan_info��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*send_mcan_info)(MCAN_INFO *mcan_info);

/**
  * @brief      ���Ϳյ�״̬ ��Ϣ
  * @param    hvac_status �յ�״̬ ��Ϣ, �ο�HVAC_STATUS��
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*send_hvac_status)(HVAC_STATUS *hvac_status);

/**
  * @brief      ��������յ���Ͽ�����Ϣ
  * @param    info �յ���Ͽ�����Ϣ, �ο�HVAC_DIAG_CTRL_INFO����
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*send_hvac_diag_entry)(HVAC_DIAG_CTRL_INFO *info);

/**
  * @brief      ���Ͷ�ȡ�յ���Ͽ��ƶ���״̬��Ϣ
  * @param    info �յ���Ͽ�����Ϣ, �ο�HVAC_DIAG_CTRL_INFO����
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*send_hvac_diag_read_status) (HVAC_DIAG_CTRL_INFO *info);

/**
  * @brief      ����ȡ���յ���Ͽ�����Ϣ
  * @param    void  �ޡ�
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*send_hvac_diag_exit) (void);

/**
  * @brief      ���ͽ��������Ԫ���������Ϣ
  * @param    mode �����Ԫ�������ģʽ, �ο�HVAC_DIAG_CTRL_UT_MODE_ID����
  * @returns  �ɹ����ط������ݰ���С��ʧ�ܷ���С��0 ��
  */
    int (*send_hvac_diag_unit_test_mode) (HVAC_DIAG_CTRL_UT_MODE_ID mode);
}MCU_AGENT_API;

/**
  * @addtogroup  Client_Init
  * @{
  */

/** 
  *  @struct MCU_MSG_HANDLE_REGISTER
  *  @brief  MCU ��Ϣʶ���봦����ע��
  */ 
typedef struct {
    MCU_MSG_ID mcu_msg_id;                    /**< MCU ��Ϣʶ���룬�ο�MCU_MSG_ID  ��ض��塣@see MCU_MSG_ID*/
    void (*mcu_msg_callback)(PACKET_MSG *);   /**< MCU ��Ϣʶ�����Ӧ�Ĵ���ص�����*/  
}MCU_MSG_HANDLE_REGISTER;
     
/**
  * @brief      McuAgent�ͻ��˳�ʼ����
  *               �����˽������ӣ�����ÿ��MCU ��Ϣʶ������д���ص�����ע�ᡣ
  * @param    mcu_msg_handle_register   MCU ��Ϣʶ���봦����ע����Ϣ��
  * @returns  �ɹ�����MCU_AGENT_API ָ�룬ʧ�ܷ���NULL��
  */
MCU_AGENT_API *McuAgent_client_init(MCU_MSG_HANDLE_REGISTER *mcu_msg_handle_register);

/**
  * @brief      ��ȡMcu Agent API ָ�롣
  * @param    �ޡ�
  * @returns  �ɹ�����MCU_AGENT_API ָ�룬ʧ�ܷ���NULL��
  */
MCU_AGENT_API *McuAgent_get_api_handle(void);
/**@}*/

/**@}*/
#endif

