#include "qmlinterface.h"
#include <QDebug>

MCU_MSG_HANDLE_REGISTER g_mcu_msg_handle_register[] = {
    {MCU_MSG_RET_RTC_CLOCK_INFO, QmlInterface::McuMsgHandle_RetRTCTimeInfo},\
    {MCU_MSG_RET_MB_VERSION, QmlInterface::McuMsgHandle_RetMBVersion},\
    {MCU_MSG_RET_AUDIO_BEEP_STATUS, QmlInterface::McuMsgHandle_RetBeepStatus},\
    {MCU_MSG_RET_AUDIO_VOLUME_INFO, QmlInterface::McuMsgHandle_RetVolumeInfo},\
    {MCU_MSG_RET_TFT_BACKLIGHT_STATUS, QmlInterface::McuMsgHandle_RetTFTBackLightStatus},\
    {MCU_MSG_RET_TFT_LANGUAGE, QmlInterface::McuMsgHandle_RetTFTLanguage},\
    {MCU_MSG_RET_TFT_BRIGHTNESS_STATUS, QmlInterface::McuMsgHandle_RetTFTBrightness},\
    {MCU_MSG_RET_HVAC_INFO, QmlInterface::McuMsgHandle_RetHvacInfo},\
    {MCU_MSG_RET_ENHOST_CAN, QmlInterface::McuMsgHandle_RetEnhostCAN},\
    {MCU_MSG_RET_FCC_CAN, QmlInterface::McuMsgHandle_RetFccCAN},\
    {MCU_MSG_MAX_ID,NULL}};

QmlInterface *g_qmlInterface = NULL;

/*
 ********************************
 *
 * Constructor Function
 *
 * ******************************
 */
QmlInterface::QmlInterface(QObject *parent) : QObject(parent)
{
    m_FACisAudoMode = false;
    m_FACCycleMode = false;
    m_AcStatus = false;
    m_Defrost = false;
    m_DaulStatus = false;
    m_isFrontON = false;
    m_isBackON = false;
    m_isMute = false;
    m_isLiftReadLightON  = false;
    m_isRightReadLightON = false;
    m_FACBLWLevel = -1;
    m_FACBLWModel = -1;
    m_Brightness  = 0;
//    m_mcuAgentAPI = McuAgent_client_init(g_mcu_msg_handle_register);
//    m_mcuAgentAPI->get_sync_info();
    g_qmlInterface = this;
}


void QmlInterface::qmlDebug(QString str, int val)
{
#if DEBUG_LOG
    if(val == -1)
        qDebug() << "[qml] ##### " << str;
    else
        qDebug() << "[qml] ##### " << str << ":" << val;
#endif
}

/*
 ********************************
 *
 * Get Function
 *
 * ******************************
 */
void QmlInterface::getSyncInfo()
{
    qDebug() << "=== getSyncInfo ===";
    m_mcuAgentAPI->get_sync_info();
}

void QmlInterface::getRctClock()
{
    m_mcuAgentAPI->get_rct_clock();
}

void QmlInterface::getMainVersionInfo()
{
    m_mcuAgentAPI->get_mainboard_version_info();
}

void QmlInterface::getBacklightStatus()
{
    m_mcuAgentAPI->get_backlight_status();
}

void QmlInterface::getLanguage()
{
    m_mcuAgentAPI->get_language();
}

void QmlInterface::getBrightness()
{
    int ret = m_mcuAgentAPI->get_brightness();
    qDebug() << "ret = " << ret << " m_Brightness:" << m_Brightness;
    if(m_Brightness != ret)
    {
        m_Brightness = ret;
        emit brightnessChanged();
    }
}

void QmlInterface::getCanInfo(QString info)
{
    qDebug() << "=========== getCanInfo info:" << info;
    if(info == "AC")
    {
        m_mcuAgentAPI->get_can_info(0xF7, 0x21);
    }
    else if(info == "BSD")
    {
        m_mcuAgentAPI->get_can_info(0xF7, 0x22);
    }
    else if(info == "AUDIO")
    {
      m_mcuAgentAPI->get_can_info(0xF7, 0x23);
    }
    else if(info == "AmbientLightColor")
    {
      m_mcuAgentAPI->get_can_info(0xF7, 0x25);
    }
    else if(info == "TIME")
    {
      m_mcuAgentAPI->get_can_info(0xF7, 0x26);
    }
    else if(info == "SR")
    {
      m_mcuAgentAPI->get_can_info(0xF7, 0x27);
    }
    else
    {
        qWarning("out of CAN Info");
    }
}

/*
 ********************************
 *
 * Set Function
 *
 * ******************************
 */
void QmlInterface::setLanguage(int language)
{
    if(language == 0)
        m_mcuAgentAPI->set_language(LANGUAGE_CHINESE);
    else if(language == 1)
        m_mcuAgentAPI->set_language(LANGUAGE_ENGLISH);
}

void QmlInterface::setRtcMode(int modeId)
{
    m_mcuAgentAPI->set_rtc_mode((RTC_MODE_ID)modeId);
}

void QmlInterface::setRctClock(int year, int month, int day, int hour, int minutes)
{
    RTC_MSG rtc_time_info = {RTC_MODE_MAX_ID,{12,0,0,18,1,1}};
    rtc_time_info.clock_msg.year = year-2000;
    rtc_time_info.clock_msg.month = month;
    rtc_time_info.clock_msg.date = day;
    rtc_time_info.clock_msg.hours = hour;
    rtc_time_info.clock_msg.minutes = minutes;
    rtc_time_info.clock_msg.seconds = 0;
    m_mcuAgentAPI->set_rct_clock(&rtc_time_info.clock_msg);
}

void QmlInterface::setBrightness(int val)
{
    m_mcuAgentAPI->set_brightness(val);
}

void QmlInterface::setBoardLight(int infoType, int infoVal)
{
    qInfo("setDutyCycleDiagInfo:infoType:%d ,infoval:%d",infoType,infoVal);
    BUTTON_DUTY_INFO buttonDutyInfo = {SET_DUTY_CYCLE,BUTTON_ADD};
    if(infoVal == 1)
        buttonDutyInfo.value = BUTTON_MINUS;
    m_mcuAgentAPI->set_button_backlight_duty_cycle(&buttonDutyInfo);
}

void QmlInterface::setVolume(int volume)
{
    qInfo("[TheXMCUAGT] ----- setBluetoothVolume:%d ",volume);
    ABSOLUTELY_VOLUME absVolume = {SET_BTHFP_VOLUME,(unsigned char)volume};
    m_mcuAgentAPI->set_absolutely_volume(&absVolume);
}

void QmlInterface::setVolumeUp(void)
{
    m_mcuAgentAPI->set_adjust_volume(ADJUST_VOLUME_UP);

}
void QmlInterface::setVolumeDown(void)
{
    m_mcuAgentAPI->set_adjust_volume(ADJUST_VOLUME_DOWN);
}

void QmlInterface::setVolumeMute(int mTime)
{
    m_mcuAgentAPI->send_player_play_skip_status((PLATER_PLAY_SKIP_STATUS_INFO)mTime);
#if 0
    switch(mTime)
    {
    case 0:
        m_mcuAgentAPI->send_player_play_skip_status(DEMUTE);
        break;
    case 100:
        m_mcuAgentAPI->send_player_play_skip_status(MCU_MUTE_100);
        break;
    case 200:
        m_mcuAgentAPI->send_player_play_skip_status(MCU_MUTE_200);
        break;
    case 300:
        m_mcuAgentAPI->send_player_play_skip_status(MCU_MUTE_300);
        break;
    case 400:
        m_mcuAgentAPI->send_player_play_skip_status(MCU_MUTE_400);
        break;
    case 500:
        m_mcuAgentAPI->send_player_play_skip_status(MCU_MUTE_500);
        break;
    case 600:
        m_mcuAgentAPI->send_player_play_skip_status(MCU_MUTE_600);
        break;
    case 700:
        m_mcuAgentAPI->send_player_play_skip_status(MCU_MUTE_700);
        break;
    case 800:
        m_mcuAgentAPI->send_player_play_skip_status(MCU_MUTE_800);
        break;
    case 900:
        m_mcuAgentAPI->send_player_play_skip_status(MCU_MUTE_900);
        break;
    default:
        m_mcuAgentAPI->send_player_play_skip_status(MCU_MUTE_100);
        break;
    }
#endif
}

void QmlInterface::sendFccCAN(QString strData)
{
    MCAN_DATA_INFO mcanDataInfo = {0,{0}};
    QStringList tmp = strData.split("-");
    mcanDataInfo.size = tmp.size();
    qDebug() << " size:" <<  tmp.size();
    for(int i = 0; i<tmp.size(); ++i)
    {
        qDebug() << " ============= date:" << tmp.at(i).toInt();
        mcanDataInfo.data[i] = tmp.at(i).toInt();
    }
    m_mcuAgentAPI->send_fcc_can(&mcanDataInfo);
}


void QmlInterface::sendHostCAN(/*int size, char *data*/)
{
    char data[] = {0x01, 0x10};

    if(data == NULL)
    {
        return;
    }
    MCAN_DATA_INFO mcanDataInfo = {0,{0}};
    mcanDataInfo.size = 2;
    for (int i=0;i<mcanDataInfo.size;i++)
    {
       mcanDataInfo.data[i] = data[i];
       qDebug()<<"----- mcanDataInfo.data["<<i<<"] = %02x"<<mcanDataInfo.data[i];
    }

    int ret = m_mcuAgentAPI->send_host_can(&mcanDataInfo);
    qDebug() << " ===== ret:" << ret;
}

/*
 ********************************
 *
 * CallBack Function
 *
 * ******************************
 */
void QmlInterface::McuMsgHandle_RetRTCTimeInfo(PACKET_MSG *packet_msg)
{
    qDebug() << "==== McuMsgHandle_RetRTCTimeInfo ====";
    RTC_MSG *pTimeInfo = (RTC_MSG *)packet_msg->data;
    qDebug() << "rtc_mode" << pTimeInfo->rtc_mode;
    qDebug() << "date" << pTimeInfo->clock_msg.date;
    qDebug() << "hours" << pTimeInfo->clock_msg.hours;
    qDebug() << "minutes" << pTimeInfo->clock_msg.minutes;
}

void QmlInterface::McuMsgHandle_RetMBVersion(PACKET_MSG *packet_msg)
{
    qDebug() << "==== McuMsgHandle_RetMBVersion ====";
    MB_VERSION_INFO *mb_version_info = (MB_VERSION_INFO *)packet_msg->data;
    qDebug() << "MB_version" << mb_version_info->MB_version;
    qDebug() << "MB_checksum" << mb_version_info->MB_checksum;
    qDebug() << "CD_version" << mb_version_info->CD_version;
    qDebug() << "Panel_version" << mb_version_info->Panel_version;
    qDebug() << "AVM_version" << mb_version_info->AVM_version;
    qDebug() << "AVM_Vin " << mb_version_info->AVM_Vin;
}


void QmlInterface::McuMsgHandle_RetBeepStatus(PACKET_MSG *packet_msg)
{
    BEEP_STATUS_ID curBeepSw = *((BEEP_STATUS_ID *)packet_msg->data);
    qDebug() << "BEEP_STATUS_ID " << curBeepSw;
}


void QmlInterface::McuMsgHandle_RetVolumeInfo(PACKET_MSG *packet_msg)
{
    AUDIO_VOLUME_INFO *pAudioVolumeInfo = (AUDIO_VOLUME_INFO *)packet_msg->data;
    qDebug("RetAudioVolumeInfoaudio_info : %d,audio_type :%d,,volume_values :%d",
           pAudioVolumeInfo->audio_info,pAudioVolumeInfo->audio_type,pAudioVolumeInfo->volume_values);
}

void QmlInterface::McuMsgHandle_RetTFTBackLightStatus(PACKET_MSG *packet_msg)
{
     BACKLIGHT_STATUS_ID backlight_status = *((BACKLIGHT_STATUS_ID *)packet_msg->data);
     qDebug() << "RetTFTBackLightStatus  _backlight:" << (bool)backlight_status;
}

void QmlInterface::McuMsgHandle_RetTFTLanguage(PACKET_MSG *packet_msg)
{
    LANGUAGE_ID curLanguage = *((LANGUAGE_ID *)packet_msg->data);
    qDebug("_language  = %d ",curLanguage);
}

void QmlInterface::McuMsgHandle_RetTFTBrightness(PACKET_MSG *packet_msg)
{
    Q_UNUSED(packet_msg)
    qDebug() << "QmlInterface::McuMsgHandle_RetTFTBrightness";
}

void QmlInterface::McuMsgHandle_RetHvacInfo(PACKET_MSG *packet_msg)
{
    Q_UNUSED(packet_msg)
    qDebug() << "QmlInterface::McuMsgHandle_RetHvacInfo";
}

void QmlInterface::McuMsgHandle_RetEnhostCAN(PACKET_MSG *packet_msg)
{
    Q_UNUSED(packet_msg)
    qDebug() << "CallBack === QmlInterface::McuMsgHandle_RetEnhostCAN ===";
}

void QmlInterface::McuMsgHandle_RetFccCAN(PACKET_MSG *packet_msg)
{
    MCAN_DATA_INFO *info = (MCAN_DATA_INFO *)packet_msg->data;
    FCCCAN_MSG_ID msgId = (FCCCAN_MSG_ID)info->data[0];
    if(!g_qmlInterface)
    {
        qCritical() << "g_qmlInterface == NULL init fail";
        return;
    }
    qDebug() << "CallBack ===McuMsgHandle_RetFccCAN ==== msgId: " << msgId;
    switch ((int)msgId) {
    case MCAN_MSG_ID_METER_FAC_INFO:
    {
        // 1
        bool autoModel = info->data[1]&0x01;
        int level =  (info->data[1]>>1)&0x0F;
        int model = (info->data[1]>>5)&0x07;
        g_qmlInterface->writeAutoMode(autoModel);
        if(g_qmlInterface->m_FACBLWLevel != level)
        {
            g_qmlInterface->sigFACwindSpeedLevel(level);
            g_qmlInterface->m_FACBLWLevel = level;
        }
        if(g_qmlInterface->m_FACBLWModel != model)
        {
            g_qmlInterface->sigFACwindSpeedModel(model);
            g_qmlInterface->m_FACBLWModel = model;
        }
        // 2
        g_qmlInterface->writeCycleMode(info->data[2]&0x01);
        g_qmlInterface->writeAcStatus((info->data[2]>>1)&0x01);
        g_qmlInterface->writeDefrost((info->data[2]>>2)&0x01);
        g_qmlInterface->writedaulStatus((info->data[2]>>3)&0x01);
        g_qmlInterface->writeFrontON((info->data[2]>>4)&0x01);
        g_qmlInterface->writeBackON((info->data[2]>>5)&0x01);

        int FrontON = (info->data[2]>>4)&0x01;
        int BackON = (info->data[2]>>5)&0x01;
        int daulStatus = (info->data[2]>>3)&0x01;
        int writeCycleMode = info->data[2]&0x01;
        ::qDebug() << "==== writeFrontON :" << FrontON;
        ::qDebug() << "==== writeBackON :" << BackON;
        ::qDebug() << "==== autoModel :" << autoModel;
        ::qDebug() << "==== writedaulStatus :" << daulStatus;
        ::qDebug() << "==== writeCycleMode :" << writeCycleMode;
    }
        break;
    case MCAN_MSG_ID_METER_BSD_INFO:
        g_qmlInterface->sigBSDInfoFCW((info->data[1]>>1)&0x01);
        g_qmlInterface->sigBSDInfoLDW((info->data[1]>>2)&0x01);
        g_qmlInterface->sigBSDInfoISA((info->data[1]>>3)&0x01);
        g_qmlInterface->sigBSDInfoBSDF((info->data[1]>>4)&0x01); //BSD
        g_qmlInterface->sigBSDInfoBSD((info->data[1]>>5)&0x01);
        g_qmlInterface->sigBSDInfoRCW((info->data[1]>>6)&0x01);
        g_qmlInterface->sigBSDInfoDOW((info->data[1]>>6)&0x01);
        break;
    case MCAN_MSG_ID_METER_AUDIO_INFO:
    {
        bool retMute = info->data[2]>>7;
        if(g_qmlInterface->m_isMute != retMute)                   //是否静音
        {
            g_qmlInterface->m_isMute = retMute;
            emit g_qmlInterface->muteStatusChanged();
        }
        g_qmlInterface->sigAUDIOInfoVolume(10);   //开机音量
        //g_qmlInterface->sigAUDIOInfoVolume(info->data[2]&0x0F);   //开机音量
        g_qmlInterface->sigAUDIOInfoTreble(info->data[3]&0x0F);   //高音调节值
        g_qmlInterface->sigAUDIOInfoBass(info->data[3]>>4);       //低音调节值
    }
        break;
    case MCAN_MSG_ID_METER_AmbientLightColor_INFO:
        g_qmlInterface->sigBCMRedColor(info->data[1]);
        g_qmlInterface->sigBCMGreenColor(info->data[2]);
        g_qmlInterface->sigBCMBlueColor(info->data[3]);
        g_qmlInterface->sigLightBrightnessLevel(info->data[4]&0x0F);
        g_qmlInterface->sigFrontLightStatus((info->data[4]>>4)&0x01);
        g_qmlInterface->sigBackLightStatus((info->data[4]>>5)&0x01);
        g_qmlInterface->sigBSDInfoIHC(info->data[5]);
        break;
    case MCAN_MSG_ID_METER_TIME_INFO:
        g_qmlInterface->sigTimeMinute(info->data[1]);
        g_qmlInterface->sigTimeHour(info->data[2]);
        qDebug() << " ====MCAN_MSG_ID_METER_TIME_INFO==== " << (info->data[4]<<8);
        g_qmlInterface->sigSubDistanceA(((info->data[4]<<8)|0xFF)&info->data[3]);
        g_qmlInterface->sigSubDistanceB(((info->data[6]<<8)|0xFF)&info->data[5]);
        break;
    case MCAN_MSG_ID_METER_SR_INFO:
    {
        bool retLifetON = info->data[1]&0x01;
        if(g_qmlInterface->m_isLiftReadLightON != retLifetON)
        {
            g_qmlInterface->m_isLiftReadLightON = retLifetON;
            emit g_qmlInterface->liftReadLightChanged();
        }
        bool  retRightON = (info->data[1]>>1)&0x01;
        if(g_qmlInterface->m_isRightReadLightON != retRightON)
        {
            g_qmlInterface->m_isRightReadLightON = retRightON;
            emit g_qmlInterface->rightReadLightChanged();
        }
        g_qmlInterface->sigSRLightLevel((info->data[1]>>4));
    }
        break;
    default:
        break;
    }
}



/*
 ********************************
 *
 * PROPERTY Function
 *
 * ******************************
 */
bool QmlInterface::readAutoMode()
{
    return m_FACisAudoMode;
}

bool QmlInterface::readCycleMode()
{
    return m_FACCycleMode;
}

bool QmlInterface::readAcStatus()
{
    return m_AcStatus;
}

bool QmlInterface::readDefrost()
{
    return m_Defrost;
}

bool QmlInterface::readaulStatus()
{
    return m_DaulStatus;
}

bool QmlInterface::readFrontON()
{
    return m_isFrontON;
}

bool QmlInterface::readBackON()
{
    return m_isBackON;
}

bool QmlInterface::readMuteStatus()
{
    return m_isMute;
}

bool QmlInterface::readLiftReadLight()
{
    return m_isLiftReadLightON;
}

bool QmlInterface::readRightReadLight()
{
    return m_isRightReadLightON;
}

int QmlInterface::readBrightness()
{
    return m_Brightness;
}



void QmlInterface::writeAutoMode(bool isAuto)
{
    if(m_FACisAudoMode != isAuto)
    {
        m_FACisAudoMode = isAuto;
        emit autoModeChanged();
    }
}

void QmlInterface::writeCycleMode(bool cycle)
{
    if(m_FACCycleMode != cycle)
    {
        m_FACCycleMode = cycle;
        emit cycleModeChanged();
    }
}

void QmlInterface::writeAcStatus(bool status)
{
    if(m_AcStatus != status)
    {
        m_AcStatus = status;
        emit acStatusChanged();
    }
}

void QmlInterface::writeDefrost(bool status)
{
    if(m_Defrost != status)
    {
        m_Defrost = status;
        emit defrostChanged();
    }
}

void QmlInterface::writedaulStatus(bool status)
{
    if(m_DaulStatus != status)
    {
        m_DaulStatus = status;
        emit daulStatusChanged();
    }
}

void QmlInterface::writeFrontON(bool isON)
{
    if(m_isFrontON != isON)
    {
        m_isFrontON = isON;
        emit frontONChanged();
    }
}

void QmlInterface::writeBackON(bool isON)
{
    if(m_isBackON != isON)
    {
        m_isBackON = isON;
        emit backONChanged();
    }
}



