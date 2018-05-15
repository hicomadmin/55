#ifndef QMLINTERFACE_H
#define QMLINTERFACE_H

#include <QObject>
#include <QString>
#include "./protocol/mcu_agent_api.h"

class QmlInterface : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QmlInterface)
public:
    explicit QmlInterface(QObject *parent = 0);

    //common
    Q_INVOKABLE void qmlDebug(QString str, int val = -1);
    //get
    Q_INVOKABLE void getSyncInfo();         //向主板发送请求同步数据
    Q_INVOKABLE void getRctClock();         //获取RTC时间
    Q_INVOKABLE void getMainVersionInfo();  //获取主板系统的版本信息
    Q_INVOKABLE void getBacklightStatus();  //获取背光开关状态
    Q_INVOKABLE void getLanguage();         //获取当前语言状态。
    Q_INVOKABLE void getBrightness();       //获取亮度值
    //set
    Q_INVOKABLE void setLanguage(int language); //设定语言
    Q_INVOKABLE void setRtcMode(int modeId);    //设定RTC时间
    Q_INVOKABLE void setRctClock(int year, int month, int day, int hour, int minutes);
    Q_INVOKABLE void setBrightness(int val);    //设定亮度值
    Q_INVOKABLE void setBoardLight(int infoType, int infoVal);  //调节面板灯亮度（目前仅用在诊断模式)
    Q_INVOKABLE void setVolume(int volume);     //设置/获取主板各个音源的音量
    Q_INVOKABLE void setVolumeUp(void);         //音量+
    Q_INVOKABLE void setVolumeDown(void);       //音量-
    //send
    Q_INVOKABLE void sendRccCANTest(int flag); //测试CAN消息
    Q_INVOKABLE void sendRccCAN(QString data); //后中控发送CAN消息到主机
    Q_INVOKABLE void sendHostCAN(/*int size, char *data*/);//主机发出CAN消息到中控

    //callback
    static void McuMsgHandle_RetRTCTimeInfo(PACKET_MSG *packet_msg);
    static void McuMsgHandle_RetMBVersion(PACKET_MSG *packet_msg);
    static void McuMsgHandle_RetBeepStatus(PACKET_MSG *packet_msg);
    static void McuMsgHandle_RetVolumeInfo(PACKET_MSG *packet_msg);
    static void McuMsgHandle_RetTFTBackLightStatus(PACKET_MSG *packet_msg);
    static void McuMsgHandle_RetTFTLanguage(PACKET_MSG *packet_msg);
    static void McuMsgHandle_RetTFTBrightness(PACKET_MSG *packet_msg);
    static void McuMsgHandle_RetEnhostCAN(PACKET_MSG *packet_msg);  //返回L5项目CAN相关信息
    static void McuMsgHandle_RetFccCAN(PACKET_MSG *packet_msg);     //返回L5项目前中控CAN相关信息
    static void McuMsgHandle_RetRccCAN(PACKET_MSG *packet_msg);     //返回L5项目后中控CAN相关信息

private:
    MCU_AGENT_API *m_mcuAgentAPI;

};


#endif // QMLINTERFACE_H
