#include "TheMcuAgent.h"


#if 0
MCU_MSG_HANDLE_REGISTER g_mcu_msg_handle_register[] = {{MCU_MSG_RET_MB_VERSION, TheXMCUAGT::McuMsgHandle_RetMBVersion}, \
                                                       {MCU_MSG_RET_RTC_CLOCK_INFO,TheXMCUAGT::McuMsgHandle_RetRTCTimeInfo},\
                                                       {MCU_MSG_RET_RADIO_PRESET_INFO,TheXMCUAGT::McuMsgHandle_RetRadioPresetInfo},\
                                                       {MCU_MSG_RET_CUR_AUDIO_SOURCE,TheXMCUAGT::McuMsgHandle_RetCurSourceId},\
                                                       {MCU_MSG_RET_AUDIO_SETTING_INFO,TheXMCUAGT::McuMsgHandle_RetAudioSettingInfo},\
                                                       /*{MCU_MSG_RET_RADIO_STATION_LIST_INFO,TheXMCUAGT::McuMsgHandle_RetRadioStationList},*/\
                                                       {MCU_MSG_RET_AUDIO_SPEED,TheXMCUAGT::McuMsgHandle_RetAudioSpeed},\
                                                       {MCU_MSG_RET_AUDIO_VOLUME_INFO,TheXMCUAGT::McuMsgHandle_RetAudioVolumeInfo},\
                                                       {MCU_MSG_RET_TFT_LANGUAGE,TheXMCUAGT::McuMsgHandle_RetTFTLanguage},\
                                                       {MCU_MSG_RET_AUDIO_BEEP_STATUS,TheXMCUAGT::McuMsgHandle_RetBeepStatus},\
                                                       {MCU_MSG_RET_HARD_KEY,TheXMCUAGT::McuMsgHandle_RetHardkeyInfo},\
                                                       {MCU_MSG_RET_AUDIO_SPEED_VOLUME_MODE,TheXMCUAGT::McuMsgHandle_RetSpeedVolumeMode},\
                                                       {MCU_MSG_RET_AUDIO_DEVICE_PLUG_STATUS,TheXMCUAGT::McuMsgHandle_RetDevicePlugStatus},\
                                                       {MCU_MSG_RET_CUR_AUDIO_POWER_STATUS,TheXMCUAGT::McuMsgHandle_RetPowerStatus},\
													   {MCU_MSG_RET_TFT_BACKLIGHT_STATUS,TheXMCUAGT::McuMsgHandle_RetTFTBackLightStatus},\
                                                       /*{MCU_MSG_RET_POWER_KEY,TheXMCUAGT::McuMsgHandle_RetPowerKeyStatus},*/\
                                                       {MCU_MSG_RET_AUDIO_AUX_GAIN_MODE,TheXMCUAGT::McuMsgHandle_RetAuxGainMode},\
                                                       {MCU_MSG_RET_SETUP_PARAM_INFO,TheXMCUAGT::McuMsgHandle_RetSetupParamInfo},\
                                                       /*{MCU_MSG_RET_TFT_DAYNIGHT_MODE_INFO,TheXMCUAGT::McuMsgHandle_RetDayNightModeInfo},*/\
                                                       /*{MCU_MSG_RET_RADIO_FM_PARAMETER_INFO,TheXMCUAGT::McuMsgHandle_RetFmParamInfo},\
                                                       {MCU_MSG_RET_RADIO_AM_PARAMETER_INFO,TheXMCUAGT::McuMsgHandle_RetAmParamInfo},\
                                                       {MCU_MSG_RET_ARKAMYS_FUNC_SW,TheXMCUAGT::McuMsgHandle_RetFlatModeInfo},\*/
                                                       {MCU_MSG_RET_MCAN_INFO,TheXMCUAGT::McuMsgHandle_RetMcanInfo},\
                                                       /*{MCU_MSG_RET_BUTTON_LIGHT_PWM,TheXMCUAGT::McuMsgHandle_RetButtonLightInfo},*/\
                                                       {MCU_MSG_RET_COREBOARD_RESUME_INFO,TheXMCUAGT::McuMsgHandle_RetCoreBoardResumeInfo},\
                                                       {MCU_MSG_MAX_ID,NULL}};

#endif
MCU_MSG_HANDLE_REGISTER g_mcu_msg_handle_register[] = {{MCU_MSG_RET_RTC_CLOCK_INFO,(&TheXMCUAGT::McuMsgHandle_RetRTCTimeInfo)},\
                                                       {MCU_MSG_RET_MB_VERSION, TheXMCUAGT::McuMsgHandle_RetMBVersion},};

MCU_AGENT_API* mcu_agent_api = NULL;

TheXMCUAGT* TheXMCUAGT::pInstance = nullptr;

static void * pvHandle = NULL;


RTC_MSG timeInfo = {RTC_MODE_12HOURS,{12,0,0,15,12,1}};

bool bHMIReady = false;

int g_CurSourceId = AUDIO_SOURCE_AM1;

SETTINGS_SAVE_INFO settingsSaveInfo = {'0','0','0','0','0','0','0','0'};

int brightlevel[11] = {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40};
unsigned int contrastlevel[11] ={ 88, 84, 80, 76, 72, 68, 64, 60, 56, 52, 50};
unsigned int grayscalelevel[11] = {56, 49, 44, 38, 33, 27, 22, 16, 11, 5, 0};

//CAMERAPARAM cameraParamInfo = {0,0,0,0,0,0};


TheXMCUAGT::TheXMCUAGT(QObject *parent) : QObject(parent)
{
    qDebug("TheXMCUAGT start up...");
    pInstance = this;
    revOpenFlag = false;
#if 0
    if(mcu_agent_api == NULL)
    {
        qInfo("\n [TheXMCUAGT]------------ init -------\n");
        mcu_agent_api = McuAgent_client_init(g_mcu_msg_handle_register);
        mcu_agent_api->get_sync_info();
        mcuagtInit();
    }
#endif
}

TheXMCUAGT::~TheXMCUAGT(void) /*! release resources. */
{
    qDebug("\n [TheXMCUAGT]------------ ~TheXMCUAGT -------\n");

}

// below for qml get (sync)

int TheXMCUAGT::getRadioBand() const
{
    return _radioBand;
}

double TheXMCUAGT::getFrequency() const
{
    return _frequency;
}

QJsonArray TheXMCUAGT::getAmpresetList() const
{
    return _ampresetList;
}


QJsonArray TheXMCUAGT::getFmpresetList() const
{
    return _fmpresetList;
}

int TheXMCUAGT::getPresetID() const
{
    return _presetID;
}

int TheXMCUAGT::getRadioState() const
{
    return _radioState;
}

QJsonArray TheXMCUAGT::getValueList()
{
    return _valueList;
}

int TheXMCUAGT::getYear() const
{
    return _year;
}

int TheXMCUAGT::getMonth() const
{
    return _month;
}

int TheXMCUAGT::getDay() const
{
    return _day;
}

int TheXMCUAGT::getHour() const
{
    return _hour;
}

int TheXMCUAGT::getMinutes() const
{
    return _minutes;
}

int TheXMCUAGT::getSecond() const
{
    return _second;
}

bool TheXMCUAGT::getHours24state() const
{
    return _hours24state;
}

bool TheXMCUAGT::getBacklight() const
{
    return _backlight;
}

int TheXMCUAGT::getBrightness() const
{
    return _brightness;
}

int TheXMCUAGT::getDayOrnight() const
{
    return _dayOrnight;
}

bool TheXMCUAGT::getShowtimesw() const
{
    return _showtimesw;
}

int TheXMCUAGT::getLanguage() const
{
    return _language;
}

bool TheXMCUAGT::getInitialize() const
{
    return _initialize;
}

QString TheXMCUAGT::getVersion() const
{
    return _version;
}

int TheXMCUAGT::getContrast() const
{
    return _contrast;
}

int TheXMCUAGT::getGrayscale() const
{
    return _grayScale;
}

bool TheXMCUAGT::getBeepSwitch() const
{
    return _beepSwitch;
}

QJsonArray TheXMCUAGT::getAmValueList() const
{
    return _amValueList;
}

QJsonArray TheXMCUAGT::getFmValueList() const
{
    return _fmValueList;
}

int TheXMCUAGT::getAudioParamBass() const
{
    return _audioParamBass;
}

int TheXMCUAGT::getAudioParamTreble() const
{
    return _audioParamTreble;
}

int TheXMCUAGT::getAudioParamXFiled() const
{
    return _audioParamXFiled;
}

int TheXMCUAGT::getAudioParamYFiled() const
{
    return _audioParamYFiled;
}

int TheXMCUAGT::getAudioParamALCLevel() const
{
    return _audioParamALCLevel;
}

int TheXMCUAGT::getRingVolume() const
{
    return _ringVolume;
}

bool TheXMCUAGT::getPowerStatus() const
{
    return _powerStatus;
}

int TheXMCUAGT::getPowerMode() const
{
    return _powerMode;
}

bool TheXMCUAGT::getPowerKeyStatus() const
{
    return _powerKeyStatus;
}

int TheXMCUAGT::getPowerKeyMode() const
{
    return _powerKeyMode;
}

int TheXMCUAGT::getMediaVolume() const
{
    return _mediaVolume;
}

int TheXMCUAGT::getBluetoothVolume() const
{
    return _bluetoothVolume;
}

int TheXMCUAGT::getAudioSource() const
{
    return _audioSource;
}

bool TheXMCUAGT::getAuxReady() const
{
    return _auxReady;
}

int TheXMCUAGT::getGainState() const
{
    return _gainState;
}

double TheXMCUAGT::getFmFrequency() const
{
    return _fmFrequency;
}

int TheXMCUAGT::getAmFrequency() const
{
    return _amFrequency;
}

QString TheXMCUAGT::getAppVerInfo() const
{
    return _appVerInfo;
}

bool TheXMCUAGT::getShowPhoneInfoOnMeterSW() const
{
    return _showPhoneInfoOnMeterSW;
}

bool TheXMCUAGT::getringtongSW() const
{
    return _ringtongSW;
}

bool TheXMCUAGT::getAutoAudioSwitch() const
{
    return _autoAudioSwitch;
}


QString TheXMCUAGT::getMBVerInfo() const
{
    return _mbVerInfo;
}

QString TheXMCUAGT::getMBChecksumInfo() const
{
    return _mbChecksumInfo;
}

QString TheXMCUAGT::getBtVerInfo() const
{
    return _btVerInfo;
}

QString TheXMCUAGT::getBtMac() const
{
    return _btMac;
}
int TheXMCUAGT::getCarSpeed() const
{
    return _carSpeed;
}

void TheXMCUAGT::notifyMCUSound()
{
    mcu_agent_api->navi_startup();
}

bool TheXMCUAGT::getILLlightState() const
{
    return _iLLlightState;
}

int TheXMCUAGT::getEqPinValue() const
{
    return _eqPinValue;
}

bool TheXMCUAGT::getrevStatus() const
{
    return _revStatus;
}

QJsonObject TheXMCUAGT::getRadioAMDiagnoseParam() const
{
    return _radioAMDiagnoseParam;
}

QJsonObject TheXMCUAGT::getRadioFMDiagnoseParam() const
{
    return _radioFMDiagnoseParam;
}

int TheXMCUAGT::getDutyCycle() const
{
    return _dutyCycle;
}

int TheXMCUAGT::getLeftRightRoll() const
{
    return _leftRightRoll;
}

int TheXMCUAGT::getLeftRightShift() const
{
    return _leftRightShift;
}

int TheXMCUAGT::getUpDownShift() const
{
    return _upDownShift;
}

int TheXMCUAGT::getFlatMode() const
{
    return _flatMode;
}

QJsonObject TheXMCUAGT::getAvCommInfo() const
{
    return _avCommInfo;
}

QJsonObject TheXMCUAGT::getMeterInfo() const
{
    return _meterInfo;
}

bool TheXMCUAGT::getDelErrorHistory() const
{
    return _delErrorHistory;
}

QJsonArray TheXMCUAGT::getErrorHistory() const
{
    return _errorHistory;
}

QJsonArray TheXMCUAGT::getMeterVersion() const
{
    return _meterVersion;
}

void TheXMCUAGT::setUsbACCSaveInfo(USB_ACC_SAVE_INFO *usbSaveInfo)
{
//    qInfo("[TheXMCUAGT]---setUsbACCSaveInfo");
    m_usbAccSaveInfo.trackID = usbSaveInfo->trackID;
    m_usbAccSaveInfo.playlistType = usbSaveInfo->playlistType;
    m_usbAccSaveInfo.position = usbSaveInfo->position;
    m_usbAccSaveInfo.folderID= usbSaveInfo->folderID;
    m_usbAccSaveInfo.usb_folderNum = usbSaveInfo->usb_folderNum;
    m_usbAccSaveInfo.playRangen = usbSaveInfo->playRangen;
    m_usbAccSaveInfo.playRandomEx = usbSaveInfo->playRandomEx;
    m_usbAccSaveInfo.usb_MusicNum = usbSaveInfo->usb_MusicNum;
    setCoreboardResumeInfo();
}

void TheXMCUAGT::setHMIReady()
{
    qWarning("[TheXMCUAGT]---setHMIReady");
    bHMIReady = true;
    getSaveSettingsInfo();
}

void TheXMCUAGT::mcuagtInit()
{
    qInfo("[TheXMCUAGT]---mcuagtInit");
    getCoreboardResumeInfo();
    _year = 2018;       //Settings
    _month = 1;
    _day   = 1;
    _hour  = 0  ;
    _minutes = 0;
    _second = 0;
    _hours24state = 0;
    _backlight = 0;
    _brightness = 8;
    _dayOrnight = 1;
    _showtimesw = 1;
    _language = 0;
    _initialize = 0;
    _contrast = 5;
    _grayScale = 5;
    _audioParamBass = 5;
    _audioParamTreble = 5;
    _audioParamXFiled = 5;
    _audioParamYFiled = 5;
    _audioParamALCLevel = 0;
    _ringVolume = 0;
    _hasCamera = false;
    _revStatus = false;
    _powerStatus = 0;
    _powerMode = 0;
    _powerKeyStatus = 0;
    _powerKeyMode = 0 ;
    _mediaVolume = 0;
    _audioSource = 4;
    _cameraBrightness = 5;
    _cameraContrast = 5 ;
    _cameraGrayScale = 5;
    _appVerInfo = "V1.0.0";
    _showPhoneInfoOnMeterSW = false;
    _ringtongSW = true;
    _autoAudioSwitch = true;
    _mbVerInfo = "0100";
    _mbChecksumInfo ="0800";
    _btVerInfo = "1.0.0";
    _btMac = "001122334455";
    m_settingsSaveInfo = {'0','0','0','0','0','0','0','0'};
    m_usbAccSaveInfo = {0,0,0,0,0,0,0,0};
    m_amValueListNum = 0;
    m_fmValueListNum = 0;
    m_bRadioInited = false;



    _radioBand = 0;
    _frequency = 531;
    _ampresetList = {531,603,999,1404,1602,1602};
    _fmpresetList = {87.0,90.1,98.1,106.1,108.0,108.0,108.0,108.0,108.0,108.0,108.0,108.0};
    _presetID = 0;
    _radioState = 0;
    _valueList = {};
    _amValueList = {};
    _fmValueList = {};
    _amFrequency = 531;
    _fmFrequency = 87.0;
    m_radioInfo.band = RADIO_BAND_MAX_ID;
    m_radioInfo.cur_freq = -1;
    m_radioInfo.preset_num = -1;
    m_radioInfo.status = RADIO_STATUS_MAX_ID;


     _auxReady = false;     //Aux
     _gainState = 1;


     _iLLlightState = 0;       //Diag
     _eqPinValue = 0;
     _dutyCycle = 0;
     _leftRightRoll = 0;
     _leftRightShift = 0;
     _upDownShift = 0;
     _flatMode = 0;
     _action = 0;
     _delErrorHistory = 0;
     _errorHistory = {};

      revOpenFlag = 0;
      m_colorkey_enable = 0;
      m_color_key = 0;
      m_alpha_val = 0;

      bHardKeyTestFlag = false;
      timeStampStart = 0;
      timeStampEnd = 0;

    timeInfo.clock_msg.year = 18;
    timeInfo.clock_msg.month = 1;
    timeInfo.clock_msg.date =1;
    timeInfo.clock_msg.hours = 0;
    timeInfo.clock_msg.minutes = 0;
    timeInfo.clock_msg.seconds =0;
    timeInfo.rtc_mode = RTC_MODE_12HOURS;

    qDebug("[TheXMCUAGT]------------ init m_bRadioInited = %d",m_bRadioInited);
}

int TheXMCUAGT::getCameraBrightness() const
{
    return _cameraBrightness;
}

int TheXMCUAGT::getCameraContrast() const
{
    return _cameraContrast;
}

int TheXMCUAGT::getCameraGrayScale() const
{
    return _cameraGrayScale;
}

void TheXMCUAGT::startCamera(bool state, bool auxState)
{
    qDebug("[TheXMCUAGT] ----- startCamera: %d ,revOpenFlag: %d ",state,revOpenFlag);
#if 0
    //取消倒车辅助线开关
    auxState = true;
    if(state)
    {
        if(auxState)
        {
            if(!revOpenFlag)
            {
                cameraHandle(FAST_REVERSE_IOCTL_START_AUX_ON);
                TrajGenOpen(&pvHandle);
                revOpenFlag = true;
            }
        }
        else
        {
            if(!revOpenFlag)
            {
                cameraHandle(FAST_REVERSE_IOCTL_START_AUX_OFF);
                TrajGenOpen(&pvHandle);
                revOpenFlag = true;
            }
        }
    }
    else
    {
        cameraHandle(FAST_REVERSE_IOCTL_STOP);
        if(revOpenFlag){
            TrajGenClose(pvHandle);
            revOpenFlag = false;
        }
    }
#endif
    emit mcuStatusChanged(6);
}

void TheXMCUAGT::setSettingOverlayer(QJsonArray data)
{
    m_colorkey_enable = data[0].toDouble();
    m_color_key = data[1].toDouble();
    m_alpha_val = data[2].toDouble();
    setOverlay(m_colorkey_enable,m_color_key,m_alpha_val);
}

void TheXMCUAGT::startCameraWithoutSetFB1(bool state, bool auxState)
{
#if 0
    if(state)
    {
        if(auxState)
        {
            if(!revOpenFlag)
            {
                //                cameraHandle(FAST_REVERSE_IOCTL_START_AUX_ON);
                //                cameraHandle(FAST_REVERSE_IOCTL_START_WITHOUT_SET_FB1);
                //直接给ioc发指令
                int fbfd=open(RESERVE_CAMERA,O_RDWR);
                //                int fbfd=open(RESERVE_CAMERA,O_RDONLY); //HJ 2017.11.23 for read only file system
                if(!fbfd)
                {
                    qCritical("[TheXMCUAGT] -----auxState Error:cannot open the framebuffer device!\n");
                    close(fbfd);
                    return;
                }
                if(ioctl(fbfd,FAST_REVERSE_IOCTL_START_WITHOUT_SET_FB1,NULL))
                {
                    qCritical("[TheXMCUAGT] -----auxState Error reading variable information\n");
                    close(fbfd);
                    return;
                }
                qDebug("[TheXMCUAGT] -----auxState startCameraWithoutSetFB1!");
                TrajGenOpen(&pvHandle);
                revOpenFlag = true;
                close(fbfd);
            }
        }
        else
        {
            cameraHandle(FAST_REVERSE_IOCTL_START_WITHOUT_SET_FB1_AND_TRAJ);
            if(!revOpenFlag)
            {
                //                cameraHandle(FAST_REVERSE_IOCTL_START_AUX_OFF);
                //                cameraHandle(FAST_REVERSE_IOCTL_START_WITHOUT_SET_FB1);
#ifdef  READ_ONLY_FILESYS
                int fbfd=open(RESERVE_CAMERA,O_RDONLY); //HJ 2017.11.23 for read only file system
#else
                int fbfd=open(RESERVE_CAMERA,O_RDWR);
#endif
                if(!fbfd)
                {
                    qCritical("[TheXMCUAGT] -----!auxState Error:cannot open the framebuffer device!\n");
                    close(fbfd);
                    return;
                }
                if(ioctl(fbfd,FAST_REVERSE_IOCTL_START_WITHOUT_SET_FB1,NULL))
                {
                    qCritical("[TheXMCUAGT] -----!auxState Error reading variable information\n");
                    close(fbfd);
                    return;
                }
                qDebug("[TheXMCUAGT] -----!auxState startCameraWithoutSetFB1!");
                TrajGenOpen(&pvHandle);
                revOpenFlag = true;
                close(fbfd);
            }
        }
    }
    else
    {
        cameraHandle(FAST_REVERSE_IOCTL_STOP);
        if(revOpenFlag){
            TrajGenClose(pvHandle);
            revOpenFlag = false;
            //cameraHandle(FAST_REVERSE_IOCTL_STOP);
        }
    }

#endif
}

void TheXMCUAGT::setVideoSource(int source, int resolution)
{
    qDebug("[TheXMCUAGT] ----- startCamera-source= %d ,resolution = %d",source,resolution);
    VIDEO_SOURCE_INFO video_source_info = {VIDEO_SOURCE_CAMERA,VIDEO_TYPE_480P};
    if (source == 0)
        video_source_info.video_source = VIDEO_SOURCE_NAVI;
    mcu_agent_api->set_video_source(&video_source_info);

}

void TheXMCUAGT::setBlackfb()
{
    //cleanScreen();
}



void TheXMCUAGT::setOverlay(unsigned int enable, unsigned int color_key, unsigned int alpha_val)
{
#if 0
    FB_CMD fbCmd;
    if(enable){
        hs_init_cmd(&fbCmd);
        fbCmd.mode = FB_CMD_MODE_GBL_ALPHA;
        fbCmd.u.gbl_alpha.enable = 1;
        fbCmd.u.gbl_alpha.alpha = alpha_val;
        hs_set_overlay(&fbCmd, NULL);
        fbCmd.mode = FB_CMD_MODE_COLOR_KEY;
        fbCmd.u.color_key.color_key = color_key;
        fbCmd.u.gbl_alpha.enable = 1;
        hs_set_overlay(&fbCmd, NULL);
    }
    else {
        hs_init_cmd(&fbCmd);
        fbCmd.mode = FB_CMD_MODE_GBL_ALPHA;
        fbCmd.u.gbl_alpha.enable = 0;
        hs_set_overlay(&fbCmd, NULL);
        fbCmd.mode = FB_CMD_MODE_COLOR_KEY;
        fbCmd.u.gbl_alpha.enable = 0;
        hs_set_overlay(&fbCmd, NULL);
    }
#endif
}


void TheXMCUAGT::mcuAgtAPITest(void)

{

//    char *testVar = getenv("MCU_AGENT_LOG_LEVEL");
//    qDebug("[TheXMCUAGT]-----> MCU_AGENT_LOG_LEVEL = %s",*testVar);


}

/* --------------------------------------------------------
 *      APIs for qml below
 */



//******************************** System ***********************************

void TheXMCUAGT::setVolumeUp(void)
{
    mcu_agent_api->set_adjust_volume(ADJUST_VOLUME_UP);

}

void TheXMCUAGT::setVolumeDown(void)
{
    mcu_agent_api->set_adjust_volume(ADJUST_VOLUME_DOWN);
}

void TheXMCUAGT::setAudioSource(int SourceId)
{
    qInfo("[TheXMCUAGT] ----- setAudioSource :%d",SourceId);
    mcu_agent_api->set_audio_source((AUDIO_SOURCE_ID)SourceId);
}

void TheXMCUAGT::startUpdataCore()
{
     mcu_agent_api->update_mainboard_firmware(UPDATE_TYPE_MD);
}

void TheXMCUAGT::restartCore()
{
    qInfo("[TheXMCUAGT] ----- restartCore \n");
    //mcu_agent_api->update_mainboard_firmware(RESTART_CORE_ID);
}


void TheXMCUAGT::beep(int beepType)
{
    mcu_agent_api->beep_tone((BEEP_TONE_ID)beepType);
}

bool TheXMCUAGT::gethasCamera()
{
    return _hasCamera;
}

bool TheXMCUAGT::getrevStatus()
{
    return _revStatus;
}

void TheXMCUAGT::setUsbPower(int time)
{
     qInfo("[TheXMCUAGT] ----- setUsbPower :%d",time);
     //mcu_agent_api->set_usb_power(time);
}

void TheXMCUAGT::setAudioPower(bool powerStatus)
{
    qInfo("[TheXMCUAGT] ----- setAudioPower :%d",powerStatus);
    mcu_agent_api->set_audio_power((POWER_STATUS_ID)powerStatus);
}

void TheXMCUAGT::setBluetoothVolume(int btVolume)
{
    qInfo("[TheXMCUAGT] ----- setBluetoothVolume:%d ",btVolume);
    //ABSOLUTELY_VOLUME absVolume = {SET_BTHFP_VOLUME,(unsigned char)btVolume};
    //mcu_agent_api->set_absolutely_volume(&absVolume);
}

void TheXMCUAGT::setEngineerMode(int engineerModeId)
{
    mcu_agent_api->set_engineer_mode((ENGINEER_MODE_ID)engineerModeId);
}

void TheXMCUAGT::setSaveSettingsInfo()
{
    qInfo("[TheXMCUAGT] ----- setSaveSettingsInfo ");
    SETUP_PARAM_INFO setupParamInfo = {0,{0}};

    SETTINGS_SAVE_INFO saveInfo = {'0','0','0','0','0','0','0','0'};

    saveInfo.settingsCamBrightnessInfo = m_settingsSaveInfo.settingsCamBrightnessInfo;
    saveInfo.settingsCamContrastInfo = m_settingsSaveInfo.settingsCamContrastInfo;
    saveInfo.settingsCamGrayscaleInfo = m_settingsSaveInfo.settingsCamGrayscaleInfo;
    saveInfo.settingsContrastInfo = m_settingsSaveInfo.settingsContrastInfo;
    saveInfo.settingsGrayscaleInfo = m_settingsSaveInfo.settingsGrayscaleInfo;
    saveInfo.settingsAutoAudioSwitch = m_settingsSaveInfo.settingsAutoAudioSwitch;
    saveInfo.settingsPhoneInfoMeterShowSwitch = m_settingsSaveInfo.settingsPhoneInfoMeterShowSwitch;
    saveInfo.settingsRingtongSwitch = m_settingsSaveInfo.settingsRingtongSwitch;

    setupParamInfo.size = 20;
    memcpy(setupParamInfo.param_info, &saveInfo, setupParamInfo.size);



    mcu_agent_api->set_setup_param_info(&setupParamInfo);

}

void TheXMCUAGT::getSaveSettingsInfo()
{
    qDebug("[TheXMCUAGT] ----- getSaveSettingsInfo ");
    //mcu_agent_api->get_setup_param_info();
}

void TheXMCUAGT::setBeepSwitch(bool beepSwitch)
{
    qDebug("[TheXMCUAGT] ----- setBeepSwitch :%d ",beepSwitch);
    _beepSwitch = beepSwitch;
    emit beepSwitchChanged(_beepSwitch);
    if(beepSwitch)
        mcu_agent_api->set_audio_beep(BEEP_STATUS_ON);
    else
        mcu_agent_api->set_audio_beep(BEEP_STATUS_OFF);
    mcu_agent_api->get_audio_beep();
}



void TheXMCUAGT::setCameraBrightness(int brightness)
{
#if 0
    cameraParaSet(V4L2_CID_BRIGHTNESS,brightlevel[brightness]);
    cameraParamInfo.brightness_enable = 1;
    cameraParamInfo.brightness_value = brightlevel[brightness];
    if(saveCameraParam() == -1)
    {
         qCritical("[TheXMCUAGT] ----- saveCameraBrightness failed!!!");
         return;
    }
    _cameraBrightness = brightness;
    emit cameraBrightnessChanged(_cameraBrightness);
    qDebug("[TheXMCUAGT] --emit _cameraBrightness: %d",_cameraBrightness);
    m_settingsSaveInfo.settingsCamBrightnessInfo = _cameraBrightness;
    setSaveSettingsInfo();
#endif
}

void TheXMCUAGT::setCameraContrast(int contrast)
{
#if 0
    cameraParaSet(V4L2_CID_CONTRAST,contrastlevel[(int)contrast]);
    cameraParamInfo.contrast_enable = 1;
    cameraParamInfo.contrast_value = contrastlevel[(int)contrast];
     if(saveCameraParam() == -1)
    {
        qCritical("[TheXMCUAGT] ----- saveCameraContrast failed!!!");
        return;
    }
    _cameraContrast = contrast;
    emit cameraContrastChanged(_cameraContrast);
    qDebug("[TheXMCUAGT] --emit _cameraContrast: %d",_cameraContrast);
    m_settingsSaveInfo.settingsCamContrastInfo = _cameraContrast;
    setSaveSettingsInfo();
#endif
}

void TheXMCUAGT::setCameraGrayScale(int greyscale)
{
#if 0
    cameraParaSet(V4L2_CID_HUE,grayscalelevel[(int)greyscale]);
    cameraParamInfo.hue_enable = 1;
    cameraParamInfo.hue_value = grayscalelevel[(int)greyscale];
    if(saveCameraParam() == -1)
    {
        qCritical("[TheXMCUAGT] ----- saveCameraGrayScale failed!!!");
        return;
    }
    _cameraGrayScale= greyscale;
    emit cameraGrayScaleChanged(_cameraGrayScale);
    qDebug("[TheXMCUAGT] --emit _cameraGrayScale: %d",_cameraGrayScale);
    m_settingsSaveInfo.settingsCamGrayscaleInfo = _cameraGrayScale;
    setSaveSettingsInfo();
#endif
}


void TheXMCUAGT::reqAppVersionInfo(void)
{
    QString fileName = "/usr/app/data/version";
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        _appVerInfo = "---";
    }
    QTextStream in(&file);
    _appVerInfo=in.readLine();
    file.close();
    emit appVerInfoChanged(_appVerInfo);
}

void TheXMCUAGT::sendMcanInfo(char *data, int size)
{
#if 0
    if(data == NULL)
        return;
    MCAN_DATA_INFO mcanDataInfo = {0,{0}};
    mcanDataInfo.size = size;
    qDebug("[TheXMCUAGT] ----- mcanDataInfo.size = %d",mcanDataInfo.size);
    int i = 0;
    for (i=0;i<mcanDataInfo.size;i++)
    {
       mcanDataInfo.data[i] = data[i];
       //qDebug()<<"[TheXMCUAGT] ----- mcanDataInfo.data["<<i<<"] = %02x"<<mcanDataInfo.data[i];
    }
    mcu_agent_api->send_mcan_info(&mcanDataInfo);
#endif
}


void TheXMCUAGT::reqMBInfo()
{
    mcu_agent_api->get_mainboard_version_info();
}

void TheXMCUAGT::setReverseline(bool bShowReverseLine)
{
    qDebug("[TheXMCUAGT] ----- setReverseline:%d ",bShowReverseLine);
#if 0
    int identify;
#ifdef READ_ONLY_FILESYS
    identify = open("/dev/fastcamera0", O_RDONLY, 0); //HJ 2017.11.23 for read only file system
#else
    identify = open("/dev/fastcamera0", O_RDWR, 0);
#endif
    if(identify < 0)
    {
        qCritical("[TheXMCUAGT] -----open fastcamera0 failed!!! ");
        return;
    }
    if (bShowReverseLine)
    {
        ioctl(identify, FAST_REVERSE_IOCTL_SET_TRAJ_ON, 0 );
    }
    else
    {
        ioctl(identify, FAST_REVERSE_IOCTL_SET_TRAJ_OFF, 0);
    }
    close(identify);
#endif
}

void TheXMCUAGT::setReverseLanguage(bool language)
{
    qDebug("[TheXMCUAGT] ----- setReverseLanguage: %d ",language);
#if 0
    if(language == 0)
        cameraHandle(FAST_REVERSE_IOCTL_LANGUAGE_SWITCH_CHINESE);
    else
        cameraHandle(FAST_REVERSE_IOCTL_LANGUAGE_SWITCH_ENGLISH);
#endif
}

void TheXMCUAGT::setCoreboardResumeInfo()
{
//    qInfo("[TheXMCUAGT] ----- setCoreboardResumeInfo ");

    COREBOARD_RESUME_INFO core_board_resume_info = {0,0,{0}};
    USB_ACC_SAVE_INFO usb_acc_save_info = {0,0,0,0,0,0,0,0};

//    qDebug("[TheXMCUAGT] ----- duration :%d",m_usbAccSaveInfo.duration);
//    qDebug("[TheXMCUAGT] ----- playlistType :%d ",m_usbAccSaveInfo.playlistType);
//    qDebug("[TheXMCUAGT] ----- playRandomEx :%d",m_usbAccSaveInfo.playRandomEx);
//    qDebug("[TheXMCUAGT] ----- playRangen :%d",m_usbAccSaveInfo.playRangen);
//    qDebug("[TheXMCUAGT] ----- playState :%d",m_usbAccSaveInfo.playState);
//    qDebug("[TheXMCUAGT] ----- position :%d",m_usbAccSaveInfo.position);
//    qDebug("[TheXMCUAGT] ----- trackID :%d",m_usbAccSaveInfo.trackID);
//    qDebug("[TheXMCUAGT] ----- usb_MusicNum :%d",m_usbAccSaveInfo.usb_MusicNum);

    usb_acc_save_info.trackID = m_usbAccSaveInfo.trackID;
    usb_acc_save_info.playlistType = m_usbAccSaveInfo.playlistType;
    usb_acc_save_info.position = m_usbAccSaveInfo.position;
    usb_acc_save_info.folderID = m_usbAccSaveInfo.folderID;
    usb_acc_save_info.usb_folderNum = m_usbAccSaveInfo.usb_folderNum;
    usb_acc_save_info.playRandomEx = m_usbAccSaveInfo.playRandomEx;
    usb_acc_save_info.playRangen = m_usbAccSaveInfo.playRangen;
    usb_acc_save_info.usb_MusicNum = m_usbAccSaveInfo.usb_MusicNum;

    core_board_resume_info.address_offset = 0;
    core_board_resume_info.length = sizeof(usb_acc_save_info);
    memcpy(core_board_resume_info.data, &usb_acc_save_info, core_board_resume_info.length);

    mcu_agent_api->set_coreboard_resume_info(&core_board_resume_info);
}

void TheXMCUAGT::getCoreboardResumeInfo()
{
    qInfo("[TheXMCUAGT] ----- getCoreboardResumeInfo ");
    mcu_agent_api->get_coreboard_resume_info(0,sizeof(USB_ACC_SAVE_INFO));

}

USB_ACC_SAVE_INFO *TheXMCUAGT::getUsbACCSaveInfo()
{
    qInfo("[TheXMCUAGT] ----- getUsbACCSaveInfo ");
    USB_ACC_SAVE_INFO *usb_acc_save_info = &m_usbAccSaveInfo;
    return usb_acc_save_info;

}

void TheXMCUAGT::reqBtVerInfo()
{
    //_btVerInfo = btControl->getBtVersion();
    emit btVerInfoChanged(_btVerInfo);

}

void TheXMCUAGT::reqBtMac()
{
    //_btMac = btControl->getBtMacAddress();
    emit btMacChanged(_btMac);
}


//******************************** Settings ***********************************


void TheXMCUAGT::setRTCMode(int modeId)
{
    mcu_agent_api->set_rtc_mode((RTC_MODE_ID)modeId);
}

void TheXMCUAGT::setRTCTime(CLOCK_MSG *clock_msg)
{

    mcu_agent_api->set_rct_clock(clock_msg);
}

void TheXMCUAGT::setDateAndTime(int year, int month, int day, int hour, int minutes)
{
//    qDebug()<<"[TheXMCUAGT] year:"<<year<<"month"<<month<<"day"<<day<<"hour"<<hour<<"min"<<minutes<<endl;
    RTC_MSG rtc_time_info = {RTC_MODE_MAX_ID,{12,0,0,18,1,1}};
    rtc_time_info.clock_msg.year = year-2000;
    rtc_time_info.clock_msg.month = month;
    rtc_time_info.clock_msg.date = day;
    rtc_time_info.clock_msg.hours = hour;
    rtc_time_info.clock_msg.minutes = minutes;
    rtc_time_info.clock_msg.seconds = 0;
    setRTCTime(&rtc_time_info.clock_msg);
}


void TheXMCUAGT::getTime()
{
    mcu_agent_api->get_rct_clock();
}

void TheXMCUAGT:: requestCarSpeed(void)
{
    mcu_agent_api->get_audio_speed();
}
void TheXMCUAGT::setShowtimesw(bool showtimesw)
{
    _showtimesw = showtimesw;
    emit showtimeswChanged(_showtimesw);
    if(showtimesw)
        mcu_agent_api->poweroff_timer_disp(DISP_STATUS_ON);
    else
        mcu_agent_api->poweroff_timer_disp(DISP_STATUS_OFF);
}

void TheXMCUAGT::setHours24state(bool hours24state)
{
    _hours24state = hours24state;
    if(hours24state)
        mcu_agent_api->set_rtc_mode(RTC_MODE_24HOURS);
    else
        mcu_agent_api->set_rtc_mode(RTC_MODE_12HOURS);

}

void TheXMCUAGT::setBacklight(bool backlight)
{
    _backlight = backlight;
    if(backlight)
        mcu_agent_api->set_backlight_status(BACKLIGHT_STATUS_ON);
    else
        mcu_agent_api->set_backlight_status(BACKLIGHT_STATUS_OFF);
}

void TheXMCUAGT::setBrightness(int brightness)
{
#if 0
    _brightness = brightness;
    DAYNIGHT_MODE_INFO dayNightINfo = {SET_CUR_MODE_LEVEL,(unsigned char)brightness};
    mcu_agent_api->set_TFT_daynight_mode_info(&dayNightINfo);
#endif
}

void TheXMCUAGT::setDayOrnight(int dayOrnight)
{
#if 0
    _dayOrnight = dayOrnight;
    DAYNIGHT_MODE_INFO dayOrnightInfo = {SET_CUR_MODE_LEVEL,(unsigned char)dayOrnight};
    mcu_agent_api->set_TFT_daynight_mode_info(&dayOrnightInfo);
#endif
}

void TheXMCUAGT::setLanguage(int language)
{
    _language = language;
    setReverseLanguage(_language);                          //set the reverse hint language
    if(language == 0)
        mcu_agent_api->set_language(LANGUAGE_CHINESE);
    else if(language == 1)
        mcu_agent_api->set_language(LANGUAGE_ENGLISH);
//    mcu_agent_api->get_language();

}

void TheXMCUAGT::setInitialize(int initialize)
{
    qDebug("[TheXMCUAGT] ----- setInitialize:");
    _initialize = initialize;
    mcu_agent_api->set_mainboard_default_setting();
    m_settingsSaveInfo.settingsAutoAudioSwitch = 1;
    m_settingsSaveInfo.settingsCamBrightnessInfo = 5;
    m_settingsSaveInfo.settingsCamContrastInfo = 5;
    m_settingsSaveInfo.settingsCamGrayscaleInfo = 5;
    m_settingsSaveInfo.settingsGrayscaleInfo =8;
    m_settingsSaveInfo.settingsContrastInfo =8;
    m_settingsSaveInfo.settingsPhoneInfoMeterShowSwitch = 0;
    m_settingsSaveInfo.settingsRingtongSwitch =1;
}

void TheXMCUAGT::setContrast(int contrast)
{
//    mcu_agent_api->set_contrast((unsigned char)contrast);
#if 0
    m_settingsSaveInfo.settingsContrastInfo = contrast;
    setSaveSettingsInfo();
    _contrast = contrast;
     emit contrastChanged(_contrast);
    int fd_fb0 = ::open("/dev/fb0", O_RDWR, 0);
    fb_test_gamma(fd_fb0,contrast);
    ::close(fd_fb0);
#endif
}

void TheXMCUAGT::setGrayScale(int greyscale)
{
#if 0
    m_settingsSaveInfo.settingsGrayscaleInfo = greyscale;
    setSaveSettingsInfo();
    _grayScale = greyscale;
    emit grayscaleChanged(_grayScale);
	int fd_fb0 = ::open("/dev/fb0", O_RDWR, 0);
    fb_test_gamma(fd_fb0,greyscale);
    ::close(fd_fb0);
#endif
}


void TheXMCUAGT::setRingVolume(int ringvolume)
{
     qInfo("[TheXMCUAGT] ----- setRingVolume: %d",ringvolume);
     //ABSOLUTELY_VOLUME absolutely_volume = {SET_SMARTPHONE_VOLUME,(unsigned char)ringvolume};
     //mcu_agent_api->set_absolutely_volume(&absolutely_volume);
}

void TheXMCUAGT::setAudioParamBass(int audioParamBass)
{
    AUDIO_SETTING_TYPE_INFO audio_setting_type_info = {AUDIO_SETTING_BAS,(unsigned char)audioParamBass};
    mcu_agent_api->set_audio_setting_info(&audio_setting_type_info);

}

void TheXMCUAGT::setAudioParamTreble(int audioParamTreble)
{
    AUDIO_SETTING_TYPE_INFO audio_setting_type_info = {AUDIO_SETTING_TRE,(unsigned char)audioParamTreble};
    mcu_agent_api->set_audio_setting_info(&audio_setting_type_info);
}


void TheXMCUAGT::setAudioParamXFiled(int audioParamXFiled)
{
    AUDIO_SETTING_TYPE_INFO audio_setting_type_info = {AUDIO_SETTING_BAL,(unsigned char)audioParamXFiled};
    mcu_agent_api->set_audio_setting_info(&audio_setting_type_info);
}

void TheXMCUAGT::setAudioParamYFiled(int audioParamYFiled)
{
    AUDIO_SETTING_TYPE_INFO audio_setting_type_info = {AUDIO_SETTING_FAD,(unsigned char)audioParamYFiled};
    mcu_agent_api->set_audio_setting_info(&audio_setting_type_info);
}

void TheXMCUAGT::setAudioParamALCLevel(int audioParamALCLevel)
{
    mcu_agent_api->set_audio_speed_volume((AUDIO_SPEED_VOLUME_ID)audioParamALCLevel);
}

void TheXMCUAGT::setShowPhoneInfoOnMeterSW(bool showPhoneInfoOnMeterSW)
{
    qInfo("[TheXMCUAGT] ----- setShowPhoneInfoOnMeterSW: %d",showPhoneInfoOnMeterSW);
    m_settingsSaveInfo.settingsPhoneInfoMeterShowSwitch = showPhoneInfoOnMeterSW;
//    _showPhoneInfoOnMeterSW = showPhoneInfoOnMeterSW;
    setSaveSettingsInfo();
}

void TheXMCUAGT::setringtongSW(bool ringtongSW)
{
    qInfo("[TheXMCUAGT] ----- setringtongSW: %d",ringtongSW);
    m_settingsSaveInfo.settingsRingtongSwitch = ringtongSW;
//    _ringtongSW = ringtongSW;
    setSaveSettingsInfo();
}

void TheXMCUAGT::setAutoAudioSwitch(bool autoAudioSwitch)
{
    qInfo("[TheXMCUAGT] ----- setAutoAudioSwitch:%d",autoAudioSwitch);
    m_settingsSaveInfo.settingsAutoAudioSwitch = autoAudioSwitch;
//    _autoAudioSwitch = autoAudioSwitch;
    setSaveSettingsInfo();
}

void TheXMCUAGT::mute(int time)
{
    qInfo("[TheXMCUAGT] ----- mute: %d",time);
}



//******************************** Radio ***********************************

void TheXMCUAGT::radioInit()
{
#if 0
     if(m_bRadioInited)
     {
         return;
     }

    mcu_agent_api->radio_list_update(GET_FM1_STATION_LIST);
    mcu_agent_api->radio_list_update(GET_AM1_STATION_LIST);

    m_bRadioInited = true;
#endif
}


void TheXMCUAGT::radioScan()
{
    mcu_agent_api->set_radio_ctrl(RADIO_CTRL_SCAN);

}


void TheXMCUAGT::setFrequency(double frequency)
{
    mcu_agent_api->set_radio_freq(frequency);
}

void TheXMCUAGT::setTuneUp()
{
    mcu_agent_api->set_radio_manual_up();
}

void TheXMCUAGT::setTuneDown()
{
    mcu_agent_api->set_radio_manual_down();
}

void TheXMCUAGT::radioSeekUp()
{
    mcu_agent_api->set_radio_seek_up();
}

void TheXMCUAGT::radioSeekDown()
{
    mcu_agent_api->set_radio_seek_down();
}

void TheXMCUAGT::savePreset(int index)
{
    mcu_agent_api->save_radio_preset_num(index);
    mcu_agent_api->get_radio_preset_info((RADIO_BAND_ID)0x07);    //0x07 :wait for mw to update protocol
}

void TheXMCUAGT::recallPreset(int index)
{
    mcu_agent_api->call_radio_preset_num(index);
    radioInfoUpdate();
}

void TheXMCUAGT::radioInfoUpdate()
{
    mcu_agent_api->get_radio_notify();
}



void TheXMCUAGT::getValueStationList(int band)
{
    if(band == 4)
    {
        emit pInstance->amValueListChanged(pInstance->_amValueList);
//         qDebug()<<"[TheXMCUAGT] _amValueList  == "<<pInstance->_amValueList;
//        qInfo("[TheXMCUAGT]-----emit _amValueList");
    }

    else if(band == 0)
    {
        emit pInstance->fmValueListChanged(pInstance->_fmValueList);
//         qDebug()<<"[TheXMCUAGT] _fmValueList  == "<<pInstance->_fmValueList;
//        qInfo("[TheXMCUAGT]-----emit _fmValueList");

    }
    radioInfoUpdate();
}

void TheXMCUAGT::updateValueStationList()
{
    qInfo("[TheXMCUAGT] ----- cancelupdateValueStationList:");
}

void TheXMCUAGT::cancelupdateValueStationList()
{
    qInfo("[TheXMCUAGT] ----- cancelupdateValueStationList:");

}


void TheXMCUAGT::getPresetList()
{
    mcu_agent_api->get_radio_preset_info((RADIO_BAND_ID)0x07);  //0x07 :wait for mw to update protocol

}






//******************************** Aux ***********************************


void TheXMCUAGT::setGainState(int index)
{
    qInfo( "[TheXMCUAGT] ----- setGainState: %d",index);
    mcu_agent_api->set_audio_aux_gain((AUDIO_AUX_GAIN_ID)index);
}


//******************************** Diag ***********************************



void TheXMCUAGT::setILLlightState(bool illLightState)
{
    mcu_agent_api->set_ILL_mode((ILL_MODE_ID)illLightState);

}

void TheXMCUAGT::reqIlllightState(void)
{
    emit iLLlightStateChanged(_iLLlightState);
}

void TheXMCUAGT::reqEqPinValue(void)
{
    qInfo("[TheXMCUAGT] ----- reqEqPinValue: %d",_eqPinValue);
    emit eqPinValueChanged(_eqPinValue);
}

void TheXMCUAGT::setRadioDiagStatus(int status)
{
    qInfo("[TheXMCUAGT] ----- setRadioDiagStatus: %d",status);
#if 0
    if(status == 1)
        mcu_agent_api->set_radio_diagnose_info(ENTER_RADIO_DIAGNOSE);
    else if(status == 2)
        mcu_agent_api->set_radio_diagnose_info(EXIT_RADIO_DIAGNOSE);
#endif
}

void TheXMCUAGT::setDutyCycleDiagInfo(int infoType, int infoVal)
{
    qInfo("[TheXMCUAGT] ----- setDutyCycleDiagInfo:infoType:%d ,infoval:%d",infoType,infoVal);
#if 0
    BUTTON_DUTY_INFO buttonDutyInfo = {SET_DUTY_CYCLE,BUTTON_ADD};
    if(infoVal == 1)
    buttonDutyInfo.value = BUTTON_MINUS;
    mcu_agent_api->set_button_backlight_duty_cycle(&buttonDutyInfo);
#endif
}

void TheXMCUAGT::saveReverseDiag(bool saveRevDiag)
{
    qDebug("[TheXMCUAGT] ----- saveReverseDiag: %d",saveRevDiag);
#if 0
    if(saveRevDiag)
    {
        TrajGenCtl(pvHandle, TRAJ_SAVE);
        cameraHandle(FAST_REVERSE_IOCTL_SAVE_PARA);
    }
#endif
}

void TheXMCUAGT::setReverseDiag(int btn)
{
    qDebug("[TheXMCUAGT] ----- setReverseDiag: %d",btn);
#if 0
    switch(btn)
    {
    case 1:   //left roll adjust
        TrajGenCtl(pvHandle, TRAJ_LEFT_ROLL);
        cameraHandle(FAST_REVERSE_IOCTL_DIAGNASTIC_REVERSE);
        TrajGenGetStatus(pvHandle, &ptTrajGenState);
        _leftRightRoll = ptTrajGenState.l32RotOffset;
        emit leftRightRollChanged(_leftRightRoll);
        qDebug( "[TheXMCUAGT] -----left-->_leftRightRoll :%d",_leftRightRoll);
        break;
    case 2:   //right roll adjust
        TrajGenCtl(pvHandle, TRAJ_RIGHT_ROLL);
        cameraHandle(FAST_REVERSE_IOCTL_DIAGNASTIC_REVERSE);
        TrajGenGetStatus(pvHandle, &ptTrajGenState);
        _leftRightRoll = ptTrajGenState.l32RotOffset;
        emit leftRightRollChanged(_leftRightRoll);
        qDebug( "[TheXMCUAGT] -----right-->_leftRightRoll :%d",_leftRightRoll);
        break;
    case 3: //up shift
        TrajGenCtl(pvHandle, TRAJ_UP_SHIFT);
        cameraHandle(FAST_REVERSE_IOCTL_DIAGNASTIC_REVERSE);
        TrajGenGetStatus(pvHandle, &ptTrajGenState);
        _upDownShift = ptTrajGenState.l32VerOffset;
        emit upDownShiftChanged(_upDownShift);
        qDebug( "[TheXMCUAGT] -----up-->_upDownShift :%d",_upDownShift);
        break;
    case 4:    //down shift
        TrajGenCtl(pvHandle, TRAJ_DOWN_SHIFT);
        cameraHandle(FAST_REVERSE_IOCTL_DIAGNASTIC_REVERSE);
        TrajGenGetStatus(pvHandle, &ptTrajGenState);
        _upDownShift = ptTrajGenState.l32VerOffset;
        emit upDownShiftChanged(_upDownShift);
        qDebug( "[TheXMCUAGT] -----down-->_upDownShift :%d",_upDownShift);
        break;
    case 5:  //left shift
        TrajGenCtl(pvHandle, TRAJ_LEFT_SHIFT);
        cameraHandle(FAST_REVERSE_IOCTL_DIAGNASTIC_REVERSE);
        TrajGenGetStatus(pvHandle, &ptTrajGenState);
        _leftRightShift = ptTrajGenState.l32HorOffset;
        emit leftRightShiftChanged(_leftRightShift);
        qDebug( "[TheXMCUAGT] -----left-->_leftRightShift  :%d",_leftRightShift);
        break;
    case 6:  //right shift
        TrajGenCtl(pvHandle, TRAJ_RIGHT_SHIFT);
        cameraHandle(FAST_REVERSE_IOCTL_DIAGNASTIC_REVERSE);
        TrajGenGetStatus(pvHandle, &ptTrajGenState);
        _leftRightShift = ptTrajGenState.l32HorOffset;
        emit leftRightShiftChanged(_leftRightShift);
        qDebug( "[TheXMCUAGT] -----right-->_leftRightShift :%d",_leftRightShift);
        break;
    }
#endif
}

void TheXMCUAGT::playRecordFileInDiag(int status)
{
    qDebug( "[TheXMCUAGT] -----playRecordFileInDiag :%d",status);
#if 0
    if(status)                                                  //need mw update
        mcu_agent_api->set_record_play_state(RECORD_START);
    else
        mcu_agent_api->set_record_play_state(RECORD_END);
#endif
}

void TheXMCUAGT::setFlatMode(int status)
{
    qDebug( "[TheXMCUAGT] -----setFlatMode :%d",status);
#if 0
    if(status)
        mcu_agent_api->set_audio_function_switch(FLAT_ON);
    else
        mcu_agent_api->set_audio_function_switch(FLAT_OFF);
#endif
}

void TheXMCUAGT::reqFlatMode()
{
    qInfo("[TheXMCUAGT] -----reqFlatMode");
    //mcu_agent_api->get_audio_function_switch();
}

void TheXMCUAGT::setAudioSpeakerDiag(int value)
{
    qDebug( "[TheXMCUAGT] -----setAudioSpeakerDiag :%d",value);
    mcu_agent_api->set_speaker_diag((SPEAKER_FREQ_ID)value);
}

void TheXMCUAGT::setRadioStopConditions(int item, int operate)
{
    qDebug( "[TheXMCUAGT] -----setRadioStopConditions item:%d operate:%d",item,operate);
#if 0
    RADIO_STOP_CONDITIONS_INFO radioStopConditionsInfo = {(CMD_INFO)item,(OPTION_INFO)operate};
    mcu_agent_api->set_radio_stop_conditions_info(&radioStopConditionsInfo);
#endif
}

void TheXMCUAGT::getCamDiagInfo()
{
    qInfo("[TheXMCUAGT] -----getCamDiagInfo");
#if 0
    cameraHandle(FAST_REVERSE_IOCTL_DIAGNASTIC_REVERSE);
    TrajGenOpen(&pvHandle);
    TrajGenGetStatus(pvHandle, &ptTrajGenState);
    TrajGenClose(pvHandle);
    _leftRightRoll = ptTrajGenState.l32RotOffset;
    _leftRightShift = ptTrajGenState.l32HorOffset;
    _upDownShift = ptTrajGenState.l32VerOffset;
    emit leftRightRollChanged(_leftRightRoll);
    emit leftRightShiftChanged(_leftRightShift);
    emit upDownShiftChanged(_upDownShift);
#endif
}






/* --------------------------------------------------------
 *      Callbacks below for MW
 */



void TheXMCUAGT::McuMsgHandle_RetMBVersion(PACKET_MSG *packet_msg)
{

    MB_VERSION_INFO *mb_version_info = (MB_VERSION_INFO *)packet_msg->data;
    char mbVer[10] = {0};
    sprintf(mbVer,"%04X",mb_version_info->MB_version);
    char mvChksum[10] = {0};
    sprintf(mvChksum,"%04X",mb_version_info->MB_checksum);
    pInstance->_mbVerInfo = QString::fromUtf8(mbVer);
    pInstance->_mbChecksumInfo = QString::fromUtf8(mvChksum);
    if (bHMIReady)
    {
        emit pInstance->mbVerInfoChanged(pInstance->_mbVerInfo);
        emit pInstance->mbChecksumInfoChanged(pInstance->_mbChecksumInfo);
    }
}

void TheXMCUAGT::McuMsgHandle_RetRTCTimeInfo(PACKET_MSG *packet_msg)
{

      RTC_MSG *pTimeInfo = (RTC_MSG *)packet_msg->data;
      if (pTimeInfo->rtc_mode != timeInfo.rtc_mode)
      {
          timeInfo.rtc_mode = pTimeInfo->rtc_mode;
           pInstance->_hours24state = (bool)timeInfo.rtc_mode;
          emit pInstance->hours24stateChanged(pInstance->_hours24state);
          qDebug("[TheXMCUAGT] _hours24state  = %d ",pInstance->_hours24state);
      }
      if (pTimeInfo->clock_msg.year != timeInfo.clock_msg.year)
      {
          if(pTimeInfo->clock_msg.year > 37 )                 //过滤时间大于2038年时无法设置系统时间
          {
               pInstance->_year = 2001;
               pInstance->_month = 1;
               pInstance->_day = 1;
               emit pInstance->yearChanged(pInstance->_year);
               emit pInstance->monthChanged(pInstance->_month);
               emit pInstance->dayChanged(pInstance->_day);
               qDebug("[TheXMCUAGT] _year > 2038 reset date to 2001 ");
               pInstance->setDateAndTime(2001,1,1,pTimeInfo->clock_msg.hours,pTimeInfo->clock_msg.minutes);
               return;
          }
          timeInfo.clock_msg.year = pTimeInfo->clock_msg.year;
           pInstance->_year = (int)timeInfo.clock_msg.year+2000;
          emit pInstance->yearChanged(pInstance->_year);
      }
      if (pTimeInfo->clock_msg.month != timeInfo.clock_msg.month)
      {
          timeInfo.clock_msg.month = pTimeInfo->clock_msg.month;
           pInstance->_month = (int)timeInfo.clock_msg.month;
          emit pInstance->monthChanged(pInstance->_month);
      }
      if (pTimeInfo->clock_msg.date != timeInfo.clock_msg.date)
      {
          timeInfo.clock_msg.date = pTimeInfo->clock_msg.date;
           pInstance->_day = (int)timeInfo.clock_msg.date;
          emit pInstance->dayChanged(pInstance->_day);
      }
      if (pTimeInfo->clock_msg.hours != timeInfo.clock_msg.hours)
      {
          timeInfo.clock_msg.hours = pTimeInfo->clock_msg.hours;
           pInstance->_hour = (int)timeInfo.clock_msg.hours;
          emit pInstance->hourChanged(pInstance->_hour);
      }
      if (pTimeInfo->clock_msg.minutes != timeInfo.clock_msg.minutes)
      {
          timeInfo.clock_msg.minutes = pTimeInfo->clock_msg.minutes;
           pInstance->_minutes = (int)timeInfo.clock_msg.minutes;
          emit pInstance->minutesChanged(pInstance->_minutes);
      }
      struct timeval tv;
      struct tm currenttime;
      time_t timep;
      currenttime.tm_hour = timeInfo.clock_msg.hours;
      currenttime.tm_min = timeInfo.clock_msg.minutes;
      currenttime.tm_sec = timeInfo.clock_msg.seconds;
      currenttime.tm_mday = timeInfo.clock_msg.date;
      currenttime.tm_mon = timeInfo.clock_msg.month -1;
      currenttime.tm_year = timeInfo.clock_msg.year + 2000 - 1900;
      timep = mktime(&currenttime);
      tv.tv_sec = timep;
      tv.tv_usec = 0;
      if(settimeofday(&tv, (struct timezone *) 0) < 0)
      {
          qCritical("[TheXMCUAGT] ----- time set fail") ;
      }
}



void TheXMCUAGT::McuMsgHandle_RetCurSourceId(PACKET_MSG *packet_msg)
{
    AUDIO_SOURCE_ID AudioSourceId = *((AUDIO_SOURCE_ID *)packet_msg->data);
    g_CurSourceId = AudioSourceId;
    emit pInstance->mcuStatusChanged(1);
    qDebug("[TheXMCUAGT] -----  g_CurSourceId Id = [%d]",g_CurSourceId);
    pInstance->_audioSource = g_CurSourceId;
    emit pInstance->audioSourceChanged(pInstance->_audioSource);
}



void TheXMCUAGT::McuMsgHandle_RetRadioStationList(PACKET_MSG *packet_msg)
{
#if 0
    RADIO_STATION_LIST_INFO *pRadioSLInfo = (RADIO_STATION_LIST_INFO *)packet_msg->data;
    bool isAm = ((pRadioSLInfo->band_type == 5) ? true:false);
    int size =pRadioSLInfo->station_num;
    int i = 0 ,j = 0,k = 0,q = 0;
    if (isAm)
    {
        for (i=0;i<pInstance->m_amValueListNum;i++)
            pInstance->_amValueList.removeFirst();
        for (j=0;j<size;j++)
        {
            QJsonValue amValue((int)(pRadioSLInfo->station_freq[j]));
            pInstance->_amValueList.append(amValue);

        }
        if (bHMIReady)
        {
            emit pInstance->amValueListChanged(pInstance->_amValueList);
//            qDebug()<<"[TheXMCUAGT] _amValueList  == "<<pInstance->_amValueList;
        }
        pInstance->m_amValueListNum = size;

    }
    else
    {
        for (k=0;k<pInstance->m_fmValueListNum;k++)
            pInstance->_fmValueList.removeFirst();
        for (q=0;q<size;q++)
        {
            QJsonValue fmValue((double)(pRadioSLInfo->station_freq[q])/100.0);
            pInstance->_fmValueList.append(fmValue);

        }
        if (bHMIReady)
        {
            emit pInstance->fmValueListChanged(pInstance->_fmValueList);
        }
        pInstance->m_fmValueListNum = size;
    }
    qInfo("[TheXMCUAGT] END  m_amValueList.size = %d ,m_fmValueList.size =%d ",pInstance->m_amValueListNum,pInstance->m_fmValueListNum);
#endif
}

void TheXMCUAGT::McuMsgHandle_RetAudioSpeed(PACKET_MSG *packet_msg)
{
    unsigned short car_speed = *((unsigned short *)packet_msg->data);
    pInstance->_carSpeed = (int)car_speed;
    if (bHMIReady)
    {
        emit pInstance->carSpeedChanged(pInstance->_carSpeed);
        qInfo("[TheXMCUAGT] -----McuMsgHandle_RetAudioSpeed: carSpeed: %d",pInstance->_carSpeed);
    }
}

void TheXMCUAGT::McuMsgHandle_RetAudioVolumeInfo(PACKET_MSG *packet_msg)
{
#if 0
    AUDIO_VOLUME_INFO *pAudioVolumeInfo = (AUDIO_VOLUME_INFO *)packet_msg->data;
//    qDebug("[TheXMCUAGT] ----- RetAudioVolumeInfoaudio_info : %d,audio_type :%d,,volume_values :%d",pAudioVolumeInfo->audio_info,pAudioVolumeInfo->audio_type,pAudioVolumeInfo->volume_values);
    if((g_CurSourceId == AUDIO_SOURCE_SMARTPHONE) || (pAudioVolumeInfo->audio_type == AUDIO_SMARTPHONE_VOLUME_TYPE))
    {
       pInstance->_ringVolume = pAudioVolumeInfo->volume_values;
       if (bHMIReady)
       {
           emit pInstance->ringVolumeChanged(pInstance->_ringVolume);
           qInfo("[TheXMCUAGT] ----- _ringVolume:%d",pInstance->_ringVolume);
       }
    }
    else if(g_CurSourceId == AUDIO_SOURCE_BT_HFP)
    {
       pInstance->_bluetoothVolume = pAudioVolumeInfo->volume_values;
       if (bHMIReady)
       {
           emit pInstance->bluetoothVolumeChanged(pInstance->_bluetoothVolume);
           qInfo("[TheXMCUAGT] ----- _bluetoothVolume:%d",pInstance->_bluetoothVolume);
       }
    }
    else
    {
       pInstance->_mediaVolume = pAudioVolumeInfo->volume_values;
       if (bHMIReady)
       {
           emit pInstance->mediaVolumeChanged(pInstance->_mediaVolume);
       }
    }
#endif
}



void TheXMCUAGT::McuMsgHandle_RetTFTLanguage(PACKET_MSG *packet_msg)
{
    LANGUAGE_ID curLanguage = *((LANGUAGE_ID *)packet_msg->data);
    pInstance->_language = curLanguage;
    emit pInstance->languageChanged(pInstance->_language);
    qDebug("[TheXMCUAGT] _language  = %d ",pInstance->_language);
}

void TheXMCUAGT::McuMsgHandle_RetBeepStatus(PACKET_MSG *packet_msg)
{
    BEEP_STATUS_ID curBeepSw = *((BEEP_STATUS_ID *)packet_msg->data);
    pInstance->_beepSwitch = curBeepSw;
    if (bHMIReady)
    {
        emit pInstance->beepSwitchChanged(pInstance->_beepSwitch);
        qInfo("[TheXMCUAGT] _beepSwitch  = %d ",pInstance->_beepSwitch);
    }
}

void TheXMCUAGT::McuMsgHandle_RetHardkeyInfo(PACKET_MSG *packet_msg)
{
     HARD_KEY_CODE hardKeyCode = *((HARD_KEY_CODE *)packet_msg->data);
//     qDebug("[TheXMCUAGT] ----- RetHardkeyInfo KeyCode = [%d],g_CurSourceId =[%d]",hardKeyCode,g_CurSourceId);
     QJsonArray keyCode;
     keyCode.append(hardKeyCode & 0x3F);
     switch ((int)hardKeyCode & 0xC0)
     {
     case 0x00:
     {
         keyCode.append(0x01);
         break;
     }
     case 0x40:
     {
         keyCode.append(0x02);
         break;
     }
     case 0x80:
     {
         keyCode.append(0x00);
         break;
     }
     }
//     qDebug()<<"[TheXMCUAGT] ----- TheXPresenter KeyCode = "<<keyCode[0]<<keyCode[1];
     emit pInstance->keycodeChanged(keyCode);
}

void TheXMCUAGT::McuMsgHandle_RetAudioSettingInfo(PACKET_MSG *packet_msg)
{
    AUDIO_SETTING_INFO *pAudioSettingInfo = (AUDIO_SETTING_INFO *)packet_msg->data;
    pInstance->_audioParamBass = pAudioSettingInfo->bass;
    pInstance->_audioParamTreble = pAudioSettingInfo->treble;
    pInstance->_audioParamXFiled = pAudioSettingInfo->bal;
    pInstance->_audioParamYFiled = pAudioSettingInfo->fader;
    if (bHMIReady)
    {
        emit pInstance->audioParamBassChanged(pInstance->_audioParamBass);
        emit pInstance->audioParamTrebleChanged(pInstance->_audioParamTreble);
        emit pInstance->audioParamXFiledChanged(pInstance->_audioParamXFiled);
        emit pInstance->audioParamYFiledChanged(pInstance->_audioParamYFiled);
    }
}

void TheXMCUAGT::McuMsgHandle_RetSpeedVolumeMode(PACKET_MSG *packet_msg)
{
      AUDIO_SPEED_VOLUME_ID audio_speed_volume_id = *((AUDIO_SPEED_VOLUME_ID *)packet_msg->data);
      pInstance->_audioParamALCLevel = audio_speed_volume_id;
      if (bHMIReady)
      {
         emit pInstance->audioParamALCLevelChanged(pInstance->_audioParamALCLevel);
      }
}

void TheXMCUAGT::McuMsgHandle_RetDevicePlugStatus(PACKET_MSG *packet_msg)
{
#if 0
    AUDIO_DEVICE_PLUG_STATUS *audio_device_plug_status = (AUDIO_DEVICE_PLUG_STATUS *)packet_msg->data;
    if (audio_device_plug_status->type == EQ_PIN )
    {
        pInstance->_hasCamera =(bool) audio_device_plug_status->eq_info.detection_position;
        emit pInstance->hasCameraChanged(pInstance->_hasCamera);
        qDebug("[TheXMCUAGT] ---RetDevicePlugStatus _hasCamera = %d ",pInstance->_hasCamera);
        pInstance->_eqPinValue = audio_device_plug_status->eq_info.data;
        emit pInstance->eqPinValueChanged(pInstance->_eqPinValue);
        qDebug("[TheXMCUAGT] ---RetDevicePlugStatus _eqPinValue = %d ",pInstance->_eqPinValue);

    }
    else if (audio_device_plug_status->type == REVERSE )
    {
        pInstance->_revStatus =(bool) audio_device_plug_status->status;
        emit pInstance->mcuStatusChanged(5);
        qDebug("[TheXMCUAGT] ---RetDevicePlugStatus _revStatus =%d",pInstance->_revStatus);
        emit pInstance->revStatusChanged(pInstance->_revStatus);
    }
    else if (audio_device_plug_status->type == ILL)
    {
        pInstance->_iLLlightState = (bool) audio_device_plug_status->status;
        emit pInstance->iLLlightStateChanged(pInstance->_iLLlightState);
        qInfo("[TheXMCUAGT] ---RetDevicePlugStatus _iLLlightState :%d",pInstance->_iLLlightState);
    }
#endif
}

void TheXMCUAGT::McuMsgHandle_RetPowerStatus(PACKET_MSG *packet_msg)
{
    POWER_INFO *power_info = (POWER_INFO *)packet_msg->data;
     qDebug("[TheXMCUAGT] ---RetPowerStatus --power_status:%d ,power_mode : %d",power_info->power_status,power_info->power_mode);
     pInstance->_powerStatus =  power_info->power_status;
     pInstance->_powerMode = power_info->power_mode;
     emit pInstance->powerStatusChanged(pInstance->_powerStatus);
     emit pInstance->powerModeChanged(pInstance->_powerMode);
     emit pInstance->mcuStatusChanged(2);

}

void TheXMCUAGT::McuMsgHandle_RetTFTBackLightStatus(PACKET_MSG *packet_msg)
{
     BACKLIGHT_STATUS_ID backlight_status = *((BACKLIGHT_STATUS_ID *)packet_msg->data);
     pInstance->_backlight = (bool)backlight_status;
     emit pInstance->backlightChanged(pInstance->_backlight);
     qDebug("[TheXMCUAGT] -----RetTFTBackLightStatus  _backlight:%d ",pInstance->_backlight);
	 emit pInstance->mcuStatusChanged(3);
}

void TheXMCUAGT::McuMsgHandle_RetPowerKeyStatus(PACKET_MSG *packet_msg)
{
     POWER_INFO *power_key_info = (POWER_INFO *)packet_msg->data;
     qDebug("[TheXMCUAGT] ---power_key_info --power_status:%d, power_mode:%d",power_key_info->power_status,power_key_info->power_mode);
     pInstance->_powerKeyStatus =  power_key_info->power_status;
     emit pInstance->powerKeyStatusChanged(pInstance->_powerKeyStatus);
     pInstance->_powerKeyMode = power_key_info->power_mode;
     emit pInstance->powerKeyModeChanged(pInstance->_powerKeyMode);
     emit pInstance->mcuStatusChanged(4);
}

void TheXMCUAGT::McuMsgHandle_RetAuxGainMode(PACKET_MSG *packet_msg)
{
    AUDIO_AUX_GAIN_ID aux_gain_id = *((AUDIO_AUX_GAIN_ID *)packet_msg->data);
    pInstance->_gainState = aux_gain_id;
    if (bHMIReady)
    {
        emit pInstance->gainStateChanged(pInstance->_gainState);
        qInfo("[TheXMCUAGT] ---RetAuxGainMode _gainState :%d",pInstance->_gainState);
    }
}

void TheXMCUAGT::McuMsgHandle_RetSetupParamInfo(PACKET_MSG *packet_msg)
{
    qDebug("[TheXMCUAGT] ----- RetSetupParamInfo ,bHMIReady = %d",bHMIReady);
    if(packet_msg == NULL)
    {
        qCritical("[TheXMCUAGT] ----- RetSetupParamInfo empty msg!! ");
        return;
    }
    SETUP_PARAM_INFO *setup_param_info = (SETUP_PARAM_INFO *)packet_msg->data;

    SETTINGS_SAVE_INFO saveInfo = {0,0,0,0,0,0,0,0};
    if(setup_param_info->size >= sizeof(SETTINGS_SAVE_INFO))
    {
        memcpy(&saveInfo, setup_param_info->param_info, sizeof(SETTINGS_SAVE_INFO));
    }
    else if(setup_param_info->size < sizeof(SETTINGS_SAVE_INFO))
    {
        memcpy(&saveInfo, setup_param_info->param_info, setup_param_info->size);
    }

    if (settingsSaveInfo.settingsCamBrightnessInfo != saveInfo.settingsCamBrightnessInfo) {
        settingsSaveInfo.settingsCamBrightnessInfo = saveInfo.settingsCamBrightnessInfo;
        pInstance->_cameraBrightness = settingsSaveInfo.settingsCamBrightnessInfo;
        pInstance->m_settingsSaveInfo.settingsCamBrightnessInfo = pInstance->_cameraBrightness;
        if(pInstance->_cameraBrightness > 16)                   //mcu记忆顺序调整，过滤可能出现的非法值
            pInstance->_cameraBrightness = 8;
        if (bHMIReady)
        {
            emit pInstance->cameraBrightnessChanged(pInstance->_cameraBrightness);
            qDebug("[TheXMCUAGT] ---_cameraBrightness = %d",pInstance->_cameraBrightness);
        }
    }
    if(settingsSaveInfo.settingsCamContrastInfo != saveInfo.settingsCamContrastInfo) {
        settingsSaveInfo.settingsCamContrastInfo = saveInfo.settingsCamContrastInfo;
        pInstance->_cameraContrast = settingsSaveInfo.settingsCamContrastInfo;
        pInstance->m_settingsSaveInfo.settingsCamContrastInfo = pInstance->_cameraContrast;
        if(pInstance->_cameraContrast > 16)                   //mcu记忆顺序调整，过滤可能出现的非法值
            pInstance->_cameraContrast = 8;
        if (bHMIReady)
        {
            emit pInstance->cameraContrastChanged(pInstance->_cameraContrast);
            qDebug("[TheXMCUAGT] ---_cameraContrast = %d",pInstance->_cameraContrast);
        }
    }
    if(settingsSaveInfo.settingsCamGrayscaleInfo != saveInfo.settingsCamGrayscaleInfo) {
        settingsSaveInfo.settingsCamGrayscaleInfo = saveInfo.settingsCamGrayscaleInfo;
        pInstance->_cameraGrayScale = settingsSaveInfo.settingsCamGrayscaleInfo;
        pInstance->m_settingsSaveInfo.settingsCamGrayscaleInfo = pInstance->_cameraGrayScale;
        if(pInstance->_cameraGrayScale > 16)                   //mcu记忆顺序调整，过滤可能出现的非法值
            pInstance->_cameraGrayScale = 8;
        if (bHMIReady)
        {
           emit pInstance->cameraGrayScaleChanged(pInstance->_cameraGrayScale);
           qDebug("[TheXMCUAGT] ---_cameraGrayScale = %d",pInstance->_cameraGrayScale);
        }
    }
    if(settingsSaveInfo.settingsGrayscaleInfo != saveInfo.settingsGrayscaleInfo) {
        settingsSaveInfo.settingsGrayscaleInfo = saveInfo.settingsGrayscaleInfo;
        pInstance->_grayScale = settingsSaveInfo.settingsGrayscaleInfo;
        pInstance->m_settingsSaveInfo.settingsGrayscaleInfo = pInstance->_grayScale;
        if(pInstance->_grayScale > 16)                          //mcu记忆顺序调整，过滤可能出现的非法值
            pInstance->_grayScale = 8;
        if (bHMIReady)
        {
            emit pInstance->grayscaleChanged(pInstance->_grayScale);
            qDebug("[TheXMCUAGT] ---_grayScale :%d",pInstance->_grayScale);
        }
    }
    if(settingsSaveInfo.settingsContrastInfo != saveInfo.settingsContrastInfo) {
        settingsSaveInfo.settingsContrastInfo = saveInfo.settingsContrastInfo;
        pInstance->_contrast = settingsSaveInfo.settingsContrastInfo;
        pInstance->m_settingsSaveInfo.settingsContrastInfo = pInstance->_contrast;
        if(pInstance->_contrast > 16)                          //mcu记忆顺序调整，过滤可能出现的非法值
            pInstance->_contrast = 8;
        if (bHMIReady)
        {
            emit pInstance->contrastChanged(pInstance->_contrast);
            qDebug("[TheXMCUAGT] ---_contrast :%d",pInstance->_contrast);
        }
    }

    if(settingsSaveInfo.settingsAutoAudioSwitch != saveInfo.settingsAutoAudioSwitch) {
        settingsSaveInfo.settingsAutoAudioSwitch = saveInfo.settingsAutoAudioSwitch;
        pInstance->_autoAudioSwitch = settingsSaveInfo.settingsAutoAudioSwitch;
        pInstance->m_settingsSaveInfo.settingsAutoAudioSwitch = pInstance->_autoAudioSwitch;
        if (bHMIReady)
        {
            emit pInstance->autoAudioSwitchChanged(pInstance->_autoAudioSwitch);
            qDebug("[TheXMCUAGT] ---emit _autoAudioSwitch :%d",pInstance->_autoAudioSwitch);
        }
    }
    if(settingsSaveInfo.settingsPhoneInfoMeterShowSwitch != saveInfo.settingsPhoneInfoMeterShowSwitch) {
        settingsSaveInfo.settingsPhoneInfoMeterShowSwitch = saveInfo.settingsPhoneInfoMeterShowSwitch;
        pInstance->_showPhoneInfoOnMeterSW = settingsSaveInfo.settingsPhoneInfoMeterShowSwitch;
        pInstance->m_settingsSaveInfo.settingsPhoneInfoMeterShowSwitch = pInstance->_showPhoneInfoOnMeterSW;
        if (bHMIReady)
        {
            emit pInstance->showPhoneInfoOnMeterSWChanged(pInstance->_showPhoneInfoOnMeterSW);
            qDebug("[TheXMCUAGT] ---emit _showPhoneInfoOnMeterSW :%d",pInstance->_showPhoneInfoOnMeterSW);
        }
    }
    if(settingsSaveInfo.settingsRingtongSwitch != saveInfo.settingsRingtongSwitch) {
        settingsSaveInfo.settingsRingtongSwitch = saveInfo.settingsRingtongSwitch;
        pInstance->_ringtongSW = settingsSaveInfo.settingsRingtongSwitch;
        pInstance->m_settingsSaveInfo.settingsRingtongSwitch = pInstance->_ringtongSW;
        if (bHMIReady)
        {
            emit pInstance->ringtongSWChanged(pInstance->_ringtongSW);
            qDebug("[TheXMCUAGT] ---emit _ringtongSW :%d",pInstance->_ringtongSW);
        }
    }
    if(!bHMIReady)
    {
        qDebug("[TheXMCUAGT]-------!bHMIReady init setup param.");
        pInstance->_autoAudioSwitch = saveInfo.settingsAutoAudioSwitch;
        pInstance->_showPhoneInfoOnMeterSW = saveInfo.settingsPhoneInfoMeterShowSwitch;
        pInstance->_ringtongSW = saveInfo.settingsRingtongSwitch;
    }
}

void TheXMCUAGT::McuMsgHandle_RetDayNightModeInfo(PACKET_MSG *packet_msg)
{
#if 0
    DAYNIGHT_MODE_SET_INFO *daynight_mode_info = (DAYNIGHT_MODE_SET_INFO *)packet_msg->data;
    bool isDayMode = ((daynight_mode_info->daynight_mode == 0)? true:false);
    bool isAutoMode = ((daynight_mode_info->ILL_mode == 0)? true:false);
    pInstance->_brightness = daynight_mode_info->brightness_level;
    if (bHMIReady)
    {
        emit pInstance->brightnessChanged(pInstance->_brightness);
        qDebug()<<"[TheXMCUAGT] ----- RetDayNightModeInfo _brightness "<<pInstance->_brightness;
    }
    qDebug("[TheXMCUAGT] ----- RetDayNightModeInfo dayNightMode :%d,isAutoMode:%d",isDayMode,isAutoMode);
    if(isDayMode)
    {
        if(isAutoMode)
            pInstance->_dayOrnight = 2;
        else
            pInstance->_dayOrnight = 0;

    }
    else
    {
        if(isAutoMode)
            pInstance->_dayOrnight = 3;
        else
            pInstance->_dayOrnight = 1;
    }
    if (bHMIReady)
    {
        emit pInstance->dayOrnightChanged(pInstance->_dayOrnight);
        qDebug()<<"[TheXMCUAGT] ---_dayOrnight "<<pInstance->_dayOrnight;
    }
#endif
}

#if 0
void TheXMCUAGT::McuMsgHandle_RetIllMode(PACKET_MSG *packet_msg)
{
    ILL_MODE_ID ill_mode_id = *((ILL_MODE_ID *)packet_msg->data);
    pInstance->_iLLlightState = ill_mode_id;
    emit pInstance->iLLlightStateChanged(pInstance->_iLLlightState);
    qInfo("[TheXMCUAGT] ---McuMsgHandle_RetIllModeId _iLLlightState :%d",pInstance->_iLLlightState);
}
#endif

void TheXMCUAGT::McuMsgHandle_RetFmParamInfo(PACKET_MSG *packet_msg)
{

}

void TheXMCUAGT::McuMsgHandle_RetAmParamInfo(PACKET_MSG *packet_msg)
{

}

void TheXMCUAGT::McuMsgHandle_RetFlatModeInfo(PACKET_MSG *packet_msg)
{
#if 0
    ARKAMYS_FUNC_SW_INFO flat_mode_info =  *((ARKAMYS_FUNC_SW_INFO *)packet_msg->data);
    pInstance->_flatMode = flat_mode_info;
    if(bHMIReady)
    {
        emit pInstance->flatModeChanged(pInstance->_flatMode);
    }
#endif
}

void TheXMCUAGT::McuMsgHandle_RetMcanInfo(PACKET_MSG *packet_msg)
{
#if 0
    MCAN_DATA_INFO *info = (MCAN_DATA_INFO *)packet_msg->data;
    MCAN_MSG_ID msgId = (MCAN_MSG_ID)info->data[0];
    switch(msgId) {
       case MCAN_MSG_ID_METER_CONNECT:
            {
                QJsonObject obj;
                obj.insert("channelStatus", info->data[1]);
                obj.insert("meterConnect", info->data[3]);
                pInstance->_meterInfo = obj;
                if (bHMIReady)
                {
                    emit pInstance->meterInfoChanged(pInstance->_meterInfo);
                }
            }

              break;
        case MCAN_MSG_ID_METER_VERSION:
             {
                 qInfo("[TheXMCUAGT]---MCAN_MSG_ID_METER_VERSION");
                 QJsonArray arr;
                 for(int i = 1;i <= 9;i++)
                 {
                     arr.append(info->data[i]);
                 }
                 pInstance->_meterVersion = arr;
                 emit pInstance->meterVersionChanged(pInstance->_meterVersion);
                 qDebug()<<"[TheXMCUAGT]------meterVersion"<<arr;
             }
               break;
        case MCAN_MSG_ID_METER_SW_VERSION:
                 qDebug()<<"[TheXMCUAGT]---MCAN_MSG_ID_METER_SW_VERSION";
               break;
        case MCAN_MSG_ID_METER_INIT_INFO:
                 qDebug()<<"[TheXMCUAGT]---MCAN_MSG_ID_METER_INIT_INFO";
               break;
        case MCAN_MSG_ID_METER_DIAG_INFO:
                 qDebug()<<"[TheXMCUAGT]---MCAN_MSG_ID_METER_DIAG_INFO";
               break;
        case MCAN_MSG_ID_METER_ERR_LOG_INFO:
             {
                QJsonArray arr;
                QJsonObject obj;
                if((info->data[1] >> 7) == 1)
                {
                  obj.insert("accHistoryExit",1);
                }
                else
                {
                    obj.insert("accHistoryExit",0);
                }
                obj.insert("accHistoryCount",info->data[1] & 0x7f);
                arr.append(obj);
                obj.remove("accHistoryExit");
                obj.remove("accHistoryCount");
                if((info->data[2] >> 7) == 1)
                {
                    obj.insert("mcHistoryExit",1);
                }
                else
                {
                    obj.insert("mcHistoryExit",0);
                }
                obj.insert("mcHistoryCount",info->data[2] & 0x7f);
                arr.append(obj);
                obj.remove("mcHistoryExit");
                obj.remove("mcHistoryCount");
                if((info->data[3] >> 7) == 1)
                {
                    obj.insert("micHistoryExit",1);
                }
                else
                {
                    obj.insert("micHistoryExit",0);
                }
                obj.insert("micHistoryCount",info->data[3] & 0x7f);
                arr.append(obj);
                obj.remove("micHistoryExit");
                obj.remove("micHistoryCount");
                if((info->data[4] >> 7) == 1)
                {
                    obj.insert("swicHistoryExit",1);
                }
                else
                {
                    obj.insert("swicHistoryExit",0);
                }
                obj.insert("swicHistoryCount",info->data[4] & 0x7f);
                arr.append(obj);
                obj.remove("swicHistoryExit");
                obj.remove("swicHistoryCount");
                pInstance->_errorHistory = arr;
                if(bHMIReady)
                {
                    emit  pInstance->errorHistoryChanged(pInstance->_errorHistory);
                    qDebug()<<"[TheXMCUAGT]---MCAN_MSG_ID_METER_ERR_LOG_INFO---_errorHistory"<<pInstance->_errorHistory;
                }
             }
               break;
        case MCAN_MSG_ID_METER_ERR_LOG_DEL_INFO:
             {
                pInstance->_delErrorHistory = info->data[1];
                if(bHMIReady)
                {
                    emit pInstance->delErrorHistoryChanged(pInstance->_delErrorHistory);
                    qDebug()<<"[TheXMCUAGT]---MCAN_MSG_ID_METER_ERR_LOG_DEL_INFO ---_delErrorHistory "<<pInstance->_delErrorHistory;
                }
             }

               break;
        case MCAN_MSG_ID_METER_AVCOMM_INFO:
             {
                QJsonObject obj;
                obj.insert("busOffStatus", info->data[1]&0x80);
                obj.insert("busCount", info->data[1]&0x7F);
                obj.insert("mcanSendStatus", info->data[2]&0xC0);
                obj.insert("mcanCount", info->data[2]&0x3F);
                obj.insert("meterRecvStatus", info->data[3]&0xC0);
                obj.insert("meterCount", info->data[3]&0x3F);
                obj.insert("swRecvStatus", info->data[4]&0xC0);
                obj.insert("swCount", info->data[4]&0x3F);
                pInstance->_avCommInfo = obj;
                if(bHMIReady)
                {
                    emit pInstance->avCommInfoChanged(pInstance->_avCommInfo);
                    qDebug()<<"[TheXMCUAGT]---MCAN_MSG_ID_METER_AVCOMM_INFO --- _avCommInfo" << pInstance->_avCommInfo;
                }
              }
               break;
        case MCAN_MSG_ID_METER_AVCOMM_RESET_INFO:
                 qDebug()<<"[TheXMCUAGT]---MCAN_MSG_ID_METER_AVCOMM_RESET_INFO";
               break;
        case MCAN_MSG_ID_METER_DEL_CONN_LOG_INFO:
                 qDebug()<<"[TheXMCUAGT]---MCAN_MSG_ID_METER_DEL_CONN_LOG_INFO";
               break;
        case MCAN_MSG_ID_METER_SYSTEM_INIR_INFO:
                 qDebug()<<"[TheXMCUAGT]---MCAN_MSG_ID_METER_SYSTEM_INIR_INFO";
               break;
           default:
                  break;
       }
#endif
}

void TheXMCUAGT::McuMsgHandle_RetButtonLightInfo(PACKET_MSG *packet_msg)
{
//    qDebug()<<"[TheXMCUAGT] ----- RetButtonLightInfo: dutyCycle ="<<packet_msg->data[0];
    pInstance->_dutyCycle = packet_msg->data[0];
    if(bHMIReady)
    {
        emit pInstance->dutyCycleChanged(pInstance->_dutyCycle);
//        qDebug()<<"[TheXMCUAGT] ----- RetButtonLightInfo: _dutyCycle ="<<pInstance->_dutyCycle;
    }
}

void TheXMCUAGT::McuMsgHandle_RetCoreBoardResumeInfo(PACKET_MSG *packet_msg)
{
    qDebug("[TheXMCUAGT] -----RetCoreBoardResumeInfo");
    if(packet_msg == NULL)
    {
        qCritical("[TheXMCUAGT] ----- RetCoreBoardResumeInfo empty msg!! ");
        return;
    }
    COREBOARD_RESUME_INFO* info = (COREBOARD_RESUME_INFO *)packet_msg->data;
    USB_ACC_SAVE_INFO usb_acc_save_info = {0,0,0,0,0,0,0,0};

    if(info->length >= sizeof(USB_ACC_SAVE_INFO))
    {
        memcpy(&usb_acc_save_info, info->data, sizeof(USB_ACC_SAVE_INFO));
    }
    else if(info->length < sizeof(USB_ACC_SAVE_INFO))
    {
        memcpy(&usb_acc_save_info, info->data, info->length);
    }

    pInstance->m_usbAccSaveInfo.folderID = usb_acc_save_info.folderID;
    pInstance->m_usbAccSaveInfo.playlistType = usb_acc_save_info.playlistType;
    pInstance->m_usbAccSaveInfo.playRandomEx = usb_acc_save_info.playRandomEx;
    pInstance->m_usbAccSaveInfo.playRangen = usb_acc_save_info.playRangen;
    pInstance->m_usbAccSaveInfo.usb_folderNum = usb_acc_save_info.usb_folderNum;
    pInstance->m_usbAccSaveInfo.position = usb_acc_save_info.position;
    pInstance->m_usbAccSaveInfo.trackID = usb_acc_save_info.trackID;
    pInstance->m_usbAccSaveInfo.usb_MusicNum = usb_acc_save_info.usb_MusicNum;


//    qDebug("[TheXMCUAGT] ----- duration :%d",pInstance->m_usbAccSaveInfo.duration);
//    qDebug("[TheXMCUAGT] ----- playlistType :%d ",pInstance->m_usbAccSaveInfo.playlistType);
//    qDebug("[TheXMCUAGT] ----- playRandomEx :%d",pInstance->m_usbAccSaveInfo.playRandomEx);
//    qDebug("[TheXMCUAGT] ----- playRangen :%d",pInstance->m_usbAccSaveInfo.playRangen);
//    qDebug("[TheXMCUAGT] ----- playState :%d",pInstance->m_usbAccSaveInfo.playState);
//    qDebug("[TheXMCUAGT] ----- position :%d",pInstance->m_usbAccSaveInfo.position);
//    qDebug("[TheXMCUAGT] ----- trackID :%d",pInstance->m_usbAccSaveInfo.trackID);
//    qDebug("[TheXMCUAGT] ----- usb_MusicNum :%d",pInstance->m_usbAccSaveInfo.usb_MusicNum);

}

/* --------------------------------------------------------
 *      APIs for TheXMCUAGT
 */

int TheXMCUAGT::getCurSystemTime()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}

# if 0

double TheXMCUAGT::McuAgt_FixDataToOnePoint(double data)
{



    qDebug()<<"[TheXMCUAGT] ----- McuAgt_FixDataToOnePoint :"<<data;
//    double retVal = floor(data * 10.000f + 0.5) / 10.000f;
    double retVal = Round(data,1);
    qDebug()<<"[TheXMCUAGT] ----- fixed :"<<retVal;
    return retVal;


}



double  TheXMCUAGT::Round(double dVal, short iPlaces)
{
    double dRetval;
    double dMod = 0.0000001;
    if (dVal<0.0) dMod=-0.0000001;
    dRetval=dVal;
    dRetval+=(5.0/pow(10.0,iPlaces+1.0));
    dRetval*=pow(10.0,iPlaces);
    dRetval=floor(dRetval+dMod);
    dRetval/=pow(10.0,iPlaces);
    return(dRetval);
}

#endif

















