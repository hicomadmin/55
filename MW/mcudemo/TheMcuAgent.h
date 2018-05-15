#ifndef HSPLUGINMCUAGENT_H
#define HSPLUGINMCUAGENT_H

#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/time.h>
#include <QFile>
#include <QDebug>

//#include "mcu_agent_api.h"
#include "hs_plugin_base_controller.h"
#include "fb_control.h"
#include "ioctrInterface.h"
#include "fbcontrol.h"
#include "include/hsfbtool.h"
#include "trajgen.h"
#include "../Bluetooth/HSBluetoothControl.h"
#include "../../shared/includes/hs_log.h"


typedef enum {
    SET_CONTRAST_ID = 1,
    SET_GRAYSCALE_ID,
    SET_CAM_BRIGHTNESS_ID,
    SET_CAM_CONTRAST_ID,
    SET_CAM_GRAYSCALE_ID,
    SET_HEARTBEAT_STATUS_ID,     //  heart beat 0: off ,1: on
    NEW_MCUAGT_DEMO_START_ID,

    MCU_CRL_MSG_MAX_ID,
}MCU_CRL_MSG_ID;





typedef struct {
    unsigned long trackID;
    unsigned long playlistType;
    unsigned long position;
    unsigned long folderID;
    unsigned long usb_folderNum;
    unsigned long playRandomEx;
    unsigned long playRangen;
    unsigned long usb_MusicNum;
}USB_ACC_SAVE_INFO;


class TheXMCUAGT : public HSPluginBaseController
{
    Q_OBJECT
    Q_DISABLE_COPY(TheXMCUAGT)

    //Radio
    
    //system
    Q_PROPERTY(bool autoAudioSwitch READ getAutoAudioSwitch WRITE setAutoAudioSwitch NOTIFY autoAudioSwitchChanged)
    Q_PROPERTY(bool revStatus READ getrevStatus NOTIFY revStatusChanged)
    Q_PROPERTY(bool backlight READ getBacklight WRITE setBacklight NOTIFY backlightChanged)
    Q_PROPERTY(bool powerKeyStatus READ getPowerKeyStatus NOTIFY powerKeyStatusChanged)
    Q_PROPERTY(bool powerStatus READ getPowerStatus NOTIFY powerStatusChanged)
    Q_PROPERTY(int powerMode READ getPowerMode NOTIFY powerModeChanged)
    Q_PROPERTY(int powerKeyMode READ getPowerKeyMode NOTIFY powerKeyModeChanged)


public:
    TheXMCUAGT(HSPluginBaseController *parent = 0 );
    ~TheXMCUAGT(void);
    static TheXMCUAGT * pInstance;

public:
   //Callbacks

  

public:
    TheXMCUAGT* getInstance(void) const;
    bool getAutoAudioSwitch();
    bool getrevStatus();
    bool getBacklight();
    bool getPowerKeyStatus();
    bool getPowerStatus();
    int getPowerMode();
    int getPowerKeyMode();
    void setOverlay(unsigned int enable, unsigned int color_key,unsigned int alpha_val);
   

signals:

    void runOnMcuCtlThread(int MsgId,int param);
    void autoAudioSwitchChanged(bool autoAudioSwitch);
    void backlightChanged(bool backlight);
    void revStatusChanged(bool revStatus);
    void powerStatusChanged(bool powerStatus);
    void powerModeChanged(int powerMode);
    void powerKeyModeChanged(int powerKeyMode);


public slots:
/* For Qml below */
    void setHMIReady(void);
    void heartBeatInit(void);
    void startHeartBeat(void);
    void startNewMcuAgtDemo(void);
    void hardkeyEventHandle(unsigned char keycode,unsigned char eventType);
    void mute(int time);
    void beep(int type);
    void sendMcanInfo(char *data, int size);
    void setAutoAudioSwitch(bool status);
    void setAudioSource(int SourceId);
    void startCamera(bool state,bool auxState);
    void setSettingOverlayer(QJsonArray data);
    void startCameraWithoutSetFB1(bool state, bool auxState);
    void setVideoSource(int source, int resolution);
    void setBacklight(bool backlight);
    void setUsbACCSaveInfo(USB_ACC_SAVE_INFO *usbSaveInfo);
    USB_ACC_SAVE_INFO *getUsbACCSaveInfo(void);
    void setUsbPower(int time);		// time * 500 ms

signals:
    void mcuStatusChanged(int statusIndex);
    void keycodeChanged(QJsonArray keyCode);
    void powerKeyStatusChanged(bool powerKeyStatus);



public:
    bool m_autoAudioSwitch;
    bool m_revStatus;
    bool m_backlight;
    bool m_powerKeyStatus;
    bool m_powerStatus;
    int  m_powerMode;
    int  m_powerKeyMode;
    bool revOpenFlag;
    USB_ACC_SAVE_INFO m_usbAccSaveInfo;

    double m_colorkey_enable;
    double m_color_key;
    double m_alpha_val;

private:
    bool m_bHeartBeatOn;

};


#endif // HSPLUGINMCUAGENT_H
