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
    {MCU_MSG_RET_ENHOST_CAN, QmlInterface::McuMsgHandle_RetEnhostCAN},\
    {MCU_MSG_RET_FCC_CAN, QmlInterface::McuMsgHandle_RetFccCAN},\
    {MCU_MSG_RET_RCC_CAN, QmlInterface::McuMsgHandle_RetRccCAN},\
    {MCU_MSG_MAX_ID,NULL}};



/*
 ********************************
 *
 * Constructor
 *
 * ******************************
 */
QmlInterface::QmlInterface(QObject *parent) : QObject(parent)
{
//    m_mcuAgentAPI = McuAgent_client_init(g_mcu_msg_handle_register);
//    int ret = m_mcuAgentAPI->get_sync_info();
//    qDebug() << "============== get_sync_info ret : " << ret;
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
    m_mcuAgentAPI->get_brightness();
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
    qInfo("----- setBluetoothVolume:%d ",volume);
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


void QmlInterface::sendRccCANTest(int flag/*int size, char *data*/)
{
    qDebug() << " ============= date:";
    if(flag == 0)
    {
        MCAN_DATA_INFO mcanDataInfo = {0,{0}};
        mcanDataInfo.size = 4;
        mcanDataInfo.data[0] = 0x01;
        mcanDataInfo.data[1] = 0x06;
        mcanDataInfo.data[2] = 0x00;
        mcanDataInfo.data[3] = 0x00;
        m_mcuAgentAPI->send_rcc_can(&mcanDataInfo);
        qDebug() << " ============= end:";
    }
    else {
        MCAN_DATA_INFO mcanDataInfo = {0,{0}};
        mcanDataInfo.size = 4;
        mcanDataInfo.data[0] = 0x01;
        mcanDataInfo.data[1] = 0x01;
        mcanDataInfo.data[2] = 0x00;
        mcanDataInfo.data[3] = 0x00;
        m_mcuAgentAPI->send_rcc_can(&mcanDataInfo);
    }
}


void QmlInterface::sendRccCAN(QString strData)
{
    qDebug() << " ============= strData:" << strData;
    MCAN_DATA_INFO mcanDataInfo = {0,{0}};
    QStringList tmp = strData.split("-");
    mcanDataInfo.size = tmp.size();
    qDebug() << " size:" <<  tmp.size();
    for(int i = 0; i<tmp.size(); ++i)
    {
        qDebug() << " ============= date:" << tmp.at(i).toInt();
        mcanDataInfo.data[i] = tmp.at(i).toInt();
    }
    m_mcuAgentAPI->send_rcc_can(&mcanDataInfo);
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

void QmlInterface::McuMsgHandle_RetEnhostCAN(PACKET_MSG *packet_msg)
{
    Q_UNUSED(packet_msg)
    qDebug() << "QmlInterface::McuMsgHandle_RetEnhostCAN";
}

void QmlInterface::McuMsgHandle_RetFccCAN(PACKET_MSG *packet_msg)
{
    Q_UNUSED(packet_msg)
    qDebug() << "QmlInterface::McuMsgHandle_RetFccCAN";
}

void QmlInterface::McuMsgHandle_RetRccCAN(PACKET_MSG *packet_msg)
{
    Q_UNUSED(packet_msg)
    qDebug() << "QmlInterface::McuMsgHandle_RetRccCAN";
}


#if 0
void QmlInterface::McuMsgHandle_RetRccCAN(PACKET_MSG *packet_msg)
{
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
               break;
        case MCAN_MSG_ID_METER_DEL_CONN_LOG_INFO:
               break;
        case MCAN_MSG_ID_METER_SYSTEM_INIR_INFO:
               break;
           default:
                  break;
       }
}
#endif
