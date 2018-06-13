#ifndef QMLINTERFACE_H
#define QMLINTERFACE_H

#include <QObject>
#include <QString>
#include "./MW/mcu_agent_api.h"



typedef enum {
    MCAN_MSG_ID_METER_FAC_INFO = 0x21,
    MCAN_MSG_ID_METER_BSD_INFO = 0x22,
    MCAN_MSG_ID_METER_AUDIO_INFO = 0x23,
    MCAN_MSG_ID_METER_AmbientLightColor_INFO = 0x25,
    MCAN_MSG_ID_METER_TIME_INFO = 0x26,
    MCAN_MSG_ID_METER_SR_INFO = 0x27,
    MCAN_MSG_ID_MAX,
}FCCCAN_MSG_ID;


class QmlInterface : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QmlInterface)
    // Air Conditioner
    Q_PROPERTY(bool isAutoMode READ readAutoMode  WRITE writeAutoMode   NOTIFY autoModeChanged)
    Q_PROPERTY(bool cycleMode  READ readCycleMode WRITE writeCycleMode  NOTIFY cycleModeChanged)
    Q_PROPERTY(bool acStatus   READ readAcStatus  WRITE writeAcStatus   NOTIFY acStatusChanged)
    Q_PROPERTY(bool defrost    READ readDefrost   WRITE writeDefrost    NOTIFY defrostChanged)
    Q_PROPERTY(bool daulStatus READ readaulStatus WRITE writedaulStatus NOTIFY daulStatusChanged)
    Q_PROPERTY(bool isFrontON  READ readFrontON   WRITE writeFrontON    NOTIFY frontONChanged)
    Q_PROPERTY(bool isBackON   READ readBackON    WRITE writeBackON     NOTIFY backONChanged)
    // AUDIO
    Q_PROPERTY(bool isMute     READ readMuteStatus NOTIFY muteStatusChanged)
    // LIGHT
    Q_PROPERTY(bool isLiftReadLightON  READ readLiftReadLight  NOTIFY liftReadLightChanged)
    Q_PROPERTY(bool isRightReadLigtON  READ readRightReadLight NOTIFY rightReadLightChanged)
    Q_PROPERTY(int  brightness         READ readBrightness     NOTIFY brightnessChanged)

public:
    //common
    explicit QmlInterface(QObject *parent = 0);
    Q_INVOKABLE void qmlDebug(QString str, int val = -1);
    //get
    Q_INVOKABLE void getSyncInfo();             //向主板发送请求同步数据
    Q_INVOKABLE void getRctClock();             //获取RTC时间
    Q_INVOKABLE void getMainVersionInfo();      //获取主板系统的版本信息
    Q_INVOKABLE void getBacklightStatus();      //获取背光开关状态
    Q_INVOKABLE void getLanguage();             //获取当前语言状态。
    Q_INVOKABLE void getBrightness();           //获取亮度值
    Q_INVOKABLE void getCanInfo(QString info);  //获取CAN信息
    //set
    Q_INVOKABLE void setLanguage(int language); //设定语言
    Q_INVOKABLE void setRtcMode(int modeId);    //设定RTC时间
    Q_INVOKABLE void setRctClock(int year, int month, int day, int hour, int minutes);
    Q_INVOKABLE void setBrightness(int val);    //设定亮度值
    Q_INVOKABLE void setBoardLight(int infoType, int infoVal);  //调节面板灯亮度（目前仅用在诊断模式)
    Q_INVOKABLE void setVolume(int volume);     //设置/获取主板各个音源的音量
    Q_INVOKABLE void setVolumeUp(void);         //音量+
    Q_INVOKABLE void setVolumeDown(void);       //音量-
    Q_INVOKABLE void setVolumeMute(int mTime);  //静音
    //send
    Q_INVOKABLE void sendFccCAN(QString data);  //前中控发送CAN消息到主机
    Q_INVOKABLE void sendHostCAN(/*int size, char *data*/);

    //callback
    static void McuMsgHandle_RetRTCTimeInfo(PACKET_MSG *packet_msg);
    static void McuMsgHandle_RetMBVersion(PACKET_MSG *packet_msg);
    static void McuMsgHandle_RetBeepStatus(PACKET_MSG *packet_msg);
    static void McuMsgHandle_RetVolumeInfo(PACKET_MSG *packet_msg);
    static void McuMsgHandle_RetTFTBackLightStatus(PACKET_MSG *packet_msg);
    static void McuMsgHandle_RetTFTLanguage(PACKET_MSG *packet_msg);
    static void McuMsgHandle_RetTFTBrightness(PACKET_MSG *packet_msg);
    static void McuMsgHandle_RetHvacInfo(PACKET_MSG *packet_msg);
    static void McuMsgHandle_RetEnhostCAN(PACKET_MSG *packet_msg);  //返回L5项目CAN相关信息
    static void McuMsgHandle_RetFccCAN(PACKET_MSG *packet_msg);     //返回L5项目前中控CAN相关信息

    //PROPERTY
    bool readAutoMode();
    bool readCycleMode();
    bool readAcStatus();
    bool readDefrost();
    bool readaulStatus();
    bool readFrontON();
    bool readBackON();
    bool readMuteStatus();
    bool readLiftReadLight();
    bool readRightReadLight();
    int readBrightness();
    void writeAutoMode(bool isAuto);
    void writeCycleMode(bool cycle);
    void writeAcStatus(bool status);
    void writeDefrost(bool status);
    void writedaulStatus(bool status);
    void writeFrontON(bool isON);
    void writeBackON(bool isON);

signals:
    void sigFACwindSpeedLevel(int level);
    void sigFACwindSpeedModel(int model);
    void sigBSDInfoFCW(int flag);
    void sigBSDInfoLDW(int flag);
    void sigBSDInfoISA(int flag);
    void sigBSDInfoBSDF(int flag);
    void sigBSDInfoBSD(int flag);
    void sigBSDInfoRCW(int flag);
    void sigBSDInfoDOW(int flag);
    void sigBSDInfoIHC(int flag);
    void sigAUDIOInfoVolume(int vol);
    void sigAUDIOInfoMute(bool isMute);
    void sigAUDIOInfoTreble(int treble);
    void sigAUDIOInfoBass(int bass);
    void sigBCMRedColor(int red);
    void sigBCMGreenColor(int green);
    void sigBCMBlueColor(int blue);
    void sigLightBrightnessLevel(int level);
    void sigFrontLightStatus(int status);
    void sigBackLightStatus(int status);
    void sigTimeMinute(int minute);
    void sigTimeHour(int hour);
    void sigSubDistanceA(int distance);
    void sigSubDistanceB(int distance);
    void sigSRLightLevel(int level);
    //PROPERTY
    void autoModeChanged();
    void cycleModeChanged();
    void acStatusChanged();
    void defrostChanged();
    void daulStatusChanged();
    void frontONChanged();
    void backONChanged();
    void muteStatusChanged();
    void liftReadLightChanged();
    void rightReadLightChanged();
    void brightnessChanged();

private:
    MCU_AGENT_API *m_mcuAgentAPI;
    bool m_FACisAudoMode;
    bool m_FACCycleMode;
    bool m_AcStatus;
    bool m_Defrost;
    bool m_DaulStatus;
    bool m_isFrontON;
    bool m_isBackON;
    bool m_isMute;
    bool m_isLiftReadLightON;
    bool m_isRightReadLightON;
    int  m_Brightness;

public:
    //flag
    int m_FACBLWLevel;
    int m_FACBLWModel;

};


#endif // QMLINTERFACE_H
