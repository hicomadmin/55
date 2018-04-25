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

    Q_INVOKABLE void qmlDebug(QString str, int val = -1);

    Q_INVOKABLE void getRctClock();
    Q_INVOKABLE void getMainVersionInfo();
    Q_INVOKABLE void getBacklightStatus();
    Q_INVOKABLE void getLanguage();
    Q_INVOKABLE void getBrightness();   //获取亮度值

    Q_INVOKABLE void setRctClock(int year, int month, int day, int hour, int minutes);

    static void McuMsgHandle_RetRTCTimeInfo(PACKET_MSG *packet_msg);
    static void McuMsgHandle_RetMBVersion(PACKET_MSG *packet_msg);
    static void McuMsgHandle_RetBeepStatus(PACKET_MSG *packet_msg);
    static void McuMsgHandle_RetVolumeInfo(PACKET_MSG *packet_msg);
    static void McuMsgHandle_RetTFTBackLightStatus(PACKET_MSG *packet_msg);
    static void McuMsgHandle_RetTFTLanguage(PACKET_MSG *packet_msg);
    static void McuMsgHandle_RetTFTBrightness(PACKET_MSG *packet_msg);

private:
    MCU_AGENT_API *m_mcuAgentAPI;

};

extern QmlInterface *g_QmlInterface;

#endif // QMLINTERFACE_H
