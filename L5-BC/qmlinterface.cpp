#include "qmlinterface.h"
#include <QDebug>


MCU_MSG_HANDLE_REGISTER g_mcu_msg_handle_register[] =
    {{MCU_MSG_RET_RTC_CLOCK_INFO, QmlInterface::McuMsgHandle_RetRTCTimeInfo},\
     {MCU_MSG_RET_MB_VERSION, QmlInterface::McuMsgHandle_RetMBVersion},\
     {MCU_MSG_RET_AUDIO_BEEP_STATUS, QmlInterface::McuMsgHandle_RetBeepStatus},\
     {MCU_MSG_RET_AUDIO_VOLUME_INFO, QmlInterface::McuMsgHandle_RetVolumeInfo},\
     {MCU_MSG_RET_TFT_BACKLIGHT_STATUS, QmlInterface::McuMsgHandle_RetTFTBackLightStatus},\
     {MCU_MSG_RET_TFT_LANGUAGE, QmlInterface::McuMsgHandle_RetTFTLanguage},\
     {MCU_MSG_RET_TFT_BRIGHTNESS_STATUS, QmlInterface::McuMsgHandle_RetTFTBrightness}};


QmlInterface::QmlInterface(QObject *parent) : QObject(parent)
{
    m_mcuAgentAPI = McuAgent_client_init(g_mcu_msg_handle_register);
    m_mcuAgentAPI->get_sync_info();
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
    m_mcuAgentAPI->get_brightness();
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
     qDebug() << "QmlInterface::McuMsgHandle_RetTFTBrightness";
}


