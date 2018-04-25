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

#include "mcu_agent_api.h"



typedef enum {
    VOLUP_PRESS = 0x01,
    VOLDOWN_PRESS = 0x02,
    BRIGHT_PRESS =0x03,
    SEEKUP_PRESS = 0x04,
    SEEKDOWN_PRESS = 0x05,
    AUDIO_PRESS = 0x06,
    MENU_PRESS = 0x07,
    PHONE_PRESS = 0x08,
    DISP_PRESS = 0x09,
    BACK_PRESS = 0x0A,
    TUNE_PUSH_PRESS = 0x0B,
    TUNEUP_PRESS = 0x0C,
    TUNEDOWN_PRESS = 0x0D,

    BACK_SWC_PRESS = 0x20,
    UP_SWC_PRESS = 0x21,
    DOWN_SWC_PRESS = 0x22,
    OK_SWC_PRESS = 0x23,
    LEFT_SWC_PRESS = 0x24,
    RIGHT_SWC_PRESSUSB = 0x25,
    VOLUP_SWC_PRESS = 0x26,
    VOLDOWN_SWC_PRESS = 0x27,
    TEL_SWC_PRESS = 0x28,
    VR_SWC_PRESS = 0x29,
    SEEKUP_SWC_PRESS = 0x2A,
    SEEKDOWN_SWC_PRESS = 0x2B,

    HARD_KEY_CODE_MAX_ID,
}HARD_KEY_CODE;


typedef struct {
    unsigned char  settingsCamBrightnessInfo ;
    unsigned char  settingsCamContrastInfo ;
    unsigned char  settingsCamGrayscaleInfo ;
    unsigned char  settingsContrastInfo ;
    unsigned char  settingsGrayscaleInfo ;
    unsigned char  settingsAutoAudioSwitch;
    unsigned char  settingsPhoneInfoMeterShowSwitch;
    unsigned char  settingsRingtongSwitch;
}SETTINGS_SAVE_INFO;

typedef struct {
    RADIO_BAND_ID band;
    unsigned char preset_num;
    RADIO_STATUS_ID status;
    unsigned long cur_freq;
}RADIO_INFO;

typedef enum {
    MCAN_MSG_ID_METER_CONNECT = 0x20,
    MCAN_MSG_ID_METER_VERSION = 0x21,
    MCAN_MSG_ID_METER_SW_VERSION = 0x22,
    MCAN_MSG_ID_METER_INIT_INFO = 0x23,
    MCAN_MSG_ID_METER_DIAG_INFO = 0x24,
    MCAN_MSG_ID_METER_ERR_LOG_INFO = 0x25,
    MCAN_MSG_ID_METER_ERR_LOG_DEL_INFO = 0x26,
    MCAN_MSG_ID_METER_AVCOMM_INFO = 0x27,
    MCAN_MSG_ID_METER_AVCOMM_RESET_INFO = 0x28,
    MCAN_MSG_ID_METER_DEL_CONN_LOG_INFO = 0x29,
    MCAN_MSG_ID_METER_SYSTEM_INIR_INFO = 0x30,

    MCAN_MSG_ID_MAX,
}MCAN_MSG_ID;



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


class TheXMCUAGT : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(TheXMCUAGT)

    //Radio
    Q_PROPERTY(int radioBand READ getRadioBand  NOTIFY radioBandChanged)
    Q_PROPERTY(double frequency READ getFrequency NOTIFY frequencyChanged)
    Q_PROPERTY(int radioState READ getRadioState NOTIFY radioStateChanged)
    Q_PROPERTY(int presetID READ getPresetID NOTIFY presetIDChanged)
    Q_PROPERTY(QJsonArray valueList READ getValueList NOTIFY valueListChanged)
    Q_PROPERTY(QJsonArray fmpresetList READ getFmpresetList NOTIFY fmpresetListChanged)
    Q_PROPERTY(QJsonArray ampresetList READ getAmpresetList NOTIFY ampresetListChanged)
    Q_PROPERTY(double fmFrequency READ getFmFrequency NOTIFY fmFrequencyChanged)
    Q_PROPERTY(int amFrequency READ getAmFrequency NOTIFY amFrequencyChanged)

    Q_PROPERTY(QJsonArray amValueList READ getAmValueList NOTIFY amValueListChanged)
    Q_PROPERTY(QJsonArray fmValueList READ getFmValueList NOTIFY fmValueListChanged)

//    Settings
    Q_PROPERTY(int year READ getYear NOTIFY yearChanged)
    Q_PROPERTY(int month READ getMonth NOTIFY monthChanged)
    Q_PROPERTY(int day READ getDay NOTIFY dayChanged)
    Q_PROPERTY(int hour READ getHour NOTIFY hourChanged)
    Q_PROPERTY(int minutes READ getMinutes NOTIFY minutesChanged)
    Q_PROPERTY(int second READ getSecond NOTIFY secondChanged)
    Q_PROPERTY(bool hours24state READ getHours24state WRITE setHours24state NOTIFY hours24stateChanged) //to do
    Q_PROPERTY(bool backlight READ getBacklight WRITE setBacklight NOTIFY backlightChanged)
    Q_PROPERTY(int brightness READ getBrightness WRITE setBrightness NOTIFY brightnessChanged)
    Q_PROPERTY(int dayOrnight READ getDayOrnight WRITE setDayOrnight NOTIFY dayOrnightChanged)
    Q_PROPERTY(bool showtimesw READ getShowtimesw WRITE setShowtimesw NOTIFY showtimeswChanged)
    Q_PROPERTY(int language READ getLanguage WRITE setLanguage NOTIFY languageChanged)
    Q_PROPERTY(bool initialize READ getInitialize WRITE setInitialize NOTIFY initializeChanged)
    Q_PROPERTY(QString version READ getVersion /*WRITE setVersion*/ NOTIFY versionChanged)
    Q_PROPERTY(int contrast READ getContrast NOTIFY contrastChanged)
    Q_PROPERTY(int grayScale READ getGrayscale NOTIFY grayscaleChanged)
    Q_PROPERTY(bool beepSwitch READ getBeepSwitch WRITE setBeepSwitch NOTIFY beepSwitchChanged)
    Q_PROPERTY(int audioParamBass READ getAudioParamBass WRITE setAudioParamBass NOTIFY audioParamBassChanged)
    Q_PROPERTY(int audioParamTreble READ getAudioParamTreble WRITE setAudioParamTreble NOTIFY audioParamTrebleChanged)
    Q_PROPERTY(int audioParamXFiled READ getAudioParamXFiled WRITE setAudioParamXFiled NOTIFY audioParamXFiledChanged)
    Q_PROPERTY(int audioParamYFiled READ getAudioParamYFiled WRITE setAudioParamYFiled NOTIFY audioParamYFiledChanged)
    Q_PROPERTY(int audioParamALCLevel READ getAudioParamALCLevel WRITE setAudioParamALCLevel NOTIFY audioParamALCLevelChanged)
    Q_PROPERTY(int ringVolume READ getRingVolume WRITE setRingVolume NOTIFY ringVolumeChanged)

    Q_PROPERTY(bool hasCamera READ gethasCamera NOTIFY hasCameraChanged)
    Q_PROPERTY(bool powerStatus READ getPowerStatus NOTIFY powerStatusChanged)
    Q_PROPERTY(int powerMode READ getPowerMode NOTIFY powerModeChanged)
    Q_PROPERTY(bool powerKeyStatus READ getPowerKeyStatus NOTIFY powerKeyStatusChanged)
    Q_PROPERTY(int powerKeyMode READ getPowerKeyMode NOTIFY powerKeyModeChanged)
    Q_PROPERTY(int mediaVolume READ getMediaVolume NOTIFY mediaVolumeChanged)
    Q_PROPERTY(int bluetoothVolume READ getBluetoothVolume WRITE setBluetoothVolume NOTIFY bluetoothVolumeChanged)

    Q_PROPERTY(int audioSource READ getAudioSource NOTIFY audioSourceChanged)

    Q_PROPERTY(int cameraBrightness READ getCameraBrightness NOTIFY cameraBrightnessChanged)
    Q_PROPERTY(int cameraContrast READ getCameraContrast NOTIFY cameraContrastChanged)
    Q_PROPERTY(int cameraGrayScale READ getCameraGrayScale NOTIFY cameraGrayScaleChanged)

    Q_PROPERTY(bool auxReady READ getAuxReady NOTIFY auxReadyChanged)
    Q_PROPERTY(int gainState READ getGainState  WRITE setGainState NOTIFY gainStateChanged)
    Q_PROPERTY(QString appVerInfo READ getAppVerInfo NOTIFY appVerInfoChanged)
    Q_PROPERTY(QString mbVerInfo READ getMBVerInfo NOTIFY mbVerInfoChanged)
    Q_PROPERTY(QString mbChecksumInfo READ getMBChecksumInfo NOTIFY mbChecksumInfoChanged)
    Q_PROPERTY(QString btVerInfo READ getBtVerInfo NOTIFY btVerInfoChanged)
    Q_PROPERTY(QString btMac READ getBtMac NOTIFY btMacChanged)
    Q_PROPERTY(int carSpeed READ getCarSpeed NOTIFY carSpeedChanged)
    Q_PROPERTY(bool iLLlightState READ getILLlightState WRITE setILLlightState NOTIFY iLLlightStateChanged)
    Q_PROPERTY(int eqPinValue READ getEqPinValue NOTIFY eqPinValueChanged)
    Q_PROPERTY(bool revStatus READ getrevStatus NOTIFY revStatusChanged)

    //Diag
    Q_PROPERTY(QJsonObject radioAMDiagnoseParam READ getRadioAMDiagnoseParam NOTIFY radioAMDiagnoseParamChanged)
    Q_PROPERTY(QJsonObject radioFMDiagnoseParam READ getRadioFMDiagnoseParam NOTIFY radioFMDiagnoseParamChanged)
    Q_PROPERTY(int dutyCycle READ getDutyCycle NOTIFY dutyCycleChanged) //to do
    Q_PROPERTY(int leftRightRoll READ getLeftRightRoll NOTIFY leftRightRollChanged)
    Q_PROPERTY(int leftRightShift READ getLeftRightShift NOTIFY leftRightShiftChanged)
    Q_PROPERTY(int upDownShift READ getUpDownShift NOTIFY upDownShiftChanged)
    Q_PROPERTY(int flatMode READ getFlatMode NOTIFY flatModeChanged)
    Q_PROPERTY(QJsonObject meterInfo READ getMeterInfo NOTIFY meterInfoChanged)
    Q_PROPERTY(QJsonObject avCommInfo READ getAvCommInfo NOTIFY avCommInfoChanged)
    Q_PROPERTY(bool delErrorHistory READ getDelErrorHistory NOTIFY delErrorHistoryChanged)
    Q_PROPERTY(QJsonArray errorHistory READ getErrorHistory NOTIFY errorHistoryChanged)
    Q_PROPERTY(QJsonArray meterVersion READ getMeterVersion NOTIFY meterVersionChanged) // add 2017.12.1



    Q_PROPERTY(bool showPhoneInfoOnMeterSW READ getShowPhoneInfoOnMeterSW WRITE setShowPhoneInfoOnMeterSW NOTIFY showPhoneInfoOnMeterSWChanged)
    Q_PROPERTY(bool ringtongSW READ getringtongSW WRITE setringtongSW NOTIFY ringtongSWChanged)
    Q_PROPERTY(bool autoAudioSwitch READ getAutoAudioSwitch WRITE setAutoAudioSwitch NOTIFY autoAudioSwitchChanged)


public:
    TheXMCUAGT(QObject *parent = 0);
    ~TheXMCUAGT(void);
    static TheXMCUAGT * pInstance;

public:
   //Callbacks
   static void McuMsgHandle_RetMBVersion(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetRTCTimeInfo(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetRadioInfo(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetRadioPresetInfo(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetCurSourceId(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetRadioStationList(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetAudioSpeed(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetAudioVolumeInfo(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetTFTLanguage(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetBeepStatus(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetHardkeyInfo(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetAudioSettingInfo(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetSpeedVolumeMode(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetDevicePlugStatus(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetPowerStatus(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetTFTBackLightStatus(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetPowerKeyStatus(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetAuxGainMode(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetSetupParamInfo(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetDayNightModeInfo(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetFmParamInfo(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetAmParamInfo(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetFlatModeInfo(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetMcanInfo(PACKET_MSG *packet_msg);
   static void McuMsgHandle_RetButtonLightInfo(PACKET_MSG *packet_msg); //dutyCycle property need
   static void McuMsgHandle_RetCoreBoardResumeInfo(PACKET_MSG *packet_msg);

public:
    int getRadioBand(void) const;
    double getFrequency(void) const;
    QJsonArray getAmpresetList() const;
    QJsonArray getFmpresetList() const;
    int getPresetID(void) const;
    int getRadioState(void)const;
    QJsonArray getValueList();
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMinutes() const;
    int getSecond() const;
    bool getHours24state() const;
    bool getBacklight() const;
    int getBrightness() const;
    int getDayOrnight() const;
    bool getShowtimesw() const;
    int getLanguage() const;
    bool getInitialize() const;
    QString getVersion() const;
    int getContrast() const;
    int getGrayscale() const;
    bool getBeepSwitch() const;
    QJsonArray getAmValueList() const;
    QJsonArray getFmValueList() const;
    int getAudioParamBass() const;
    int getAudioParamTreble() const;
    int getAudioParamXFiled() const;
    int getAudioParamYFiled() const;
    int getAudioParamALCLevel() const;
    int getRingVolume() const;
    bool getPowerStatus() const;
    int getPowerMode() const;
    bool getPowerKeyStatus() const;
    int getPowerKeyMode() const;
    int getMediaVolume() const;
    int getBluetoothVolume() const;
    void setOverlay(unsigned int enable, unsigned int color_key,unsigned int alpha_val);
    int getAudioSource() const;
    int getCameraBrightness() const;
    int getCameraContrast() const;
    int getCameraGrayScale() const;
    bool getAuxReady() const;
    int getGainState() const;
    double getFmFrequency() const;
    int getAmFrequency() const;
    QString getAppVerInfo() const;
    bool getShowPhoneInfoOnMeterSW() const;
    bool getringtongSW() const;
    bool getAutoAudioSwitch() const;
    QString getMBVerInfo() const;
    QString getMBChecksumInfo() const;
    QString getBtVerInfo() const;
    QString getBtMac() const;
    int getCarSpeed() const;
    bool getILLlightState() const;
    int getEqPinValue() const;
    bool getrevStatus() const;
    QJsonObject getRadioAMDiagnoseParam() const;
    QJsonObject getRadioFMDiagnoseParam() const;
    int getDutyCycle() const;
    int getLeftRightRoll() const;
    int getLeftRightShift() const;
    int getUpDownShift() const;
    int getFlatMode() const;
    QJsonObject getAvCommInfo() const;
    QJsonObject getMeterInfo() const;
    bool getDelErrorHistory() const;
    QJsonArray getErrorHistory() const;
    QJsonArray getMeterVersion() const;

signals:
    void radioBandChanged(int radioBand);            //Radio
    void frequencyChanged(double frequency);
    void ampresetListChanged(QJsonArray ampresetList);
    void fmpresetListChanged(QJsonArray fmpresetList);
    void presetIDChanged(int presetID);
    void radioStateChanged(int radioState);
    void valueListChanged(QJsonArray valueList);
    void yearChanged(int year);                      //Settings
    void monthChanged(int month);
    void dayChanged(int day);
    void hourChanged(int hour);
    void minutesChanged(int minutes);
    void secondChanged(int second);
    void hours24stateChanged(bool hours24state);
    void backlightChanged(bool backlight);
    void brightnessChanged(int brightness);
    void dayOrnightChanged(bool dayOrnight);
    void showtimeswChanged(bool showtimesw);
    void languageChanged(int language);
    void initializeChanged(bool initialize);
    void versionChanged(QString version);
    void contrastChanged(int contrast);
    void grayscaleChanged(int grayScale);
    void beepSwitchChanged(bool beepSwitch);
    void amValueListChanged(QJsonArray amValueList);
    void fmValueListChanged(QJsonArray fmValueList);
    void audioParamBassChanged(int audioParamBass);
    void audioParamTrebleChanged(int audioParamTreble);
    void audioParamXFiledChanged(int audioParamXFiled);
    void audioParamYFiledChanged(int audioParamYFiled);
    void audioParamALCLevelChanged(int audioParamALCLevel);
    void ringVolumeChanged(int ringVolume);
    void hasCameraChanged(bool hasCamera);
    void powerStatusChanged(bool powerStatus);
    void powerModeChanged(int powerMode);
    void powerKeyStatusChanged(bool powerKeyStatus);
    void powerKeyModeChanged(int powerKeyMode);
    void mediaVolumeChanged(int mediaVolume);
    void bluetoothVolumeChanged(int bluetoothVolume);
    void audioSourceChanged(int audioSource);
    void cameraBrightnessChanged(int cameraBrightness);
    void cameraContrastChanged(int cameraContrast);
    void cameraGrayScaleChanged(int cameraGrayScale);
    void auxReadyChanged(bool auxReady);
    void gainStateChanged(int gainState);
    void fmFrequencyChanged(double fmFrequency);
    void amFrequencyChanged(int amFrequency);
    void appVerInfoChanged(QString appVerInfo);
    void showPhoneInfoOnMeterSWChanged(bool showPhoneInfoOnMeterSW);
    void ringtongSWChanged(bool ringtongSW);
    void autoAudioSwitchChanged(bool autoAudioSwitch);
    void mbVerInfoChanged(QString mbVerInfo);
    void mbChecksumInfoChanged(QString mbChecksumInfo);
    void btVerInfoChanged(QString btVerInfo);
    void btMacChanged(QString btMac);
    void carSpeedChanged(int carSpeed);
    void iLLlightStateChanged(bool iLLlightState);
    void eqPinValueChanged(int eqPinValue);
    void revStatusChanged(bool revStatus);
    void radioAMDiagnoseParamChanged(QJsonObject radioAMDiagnoseParam);
    void radioFMDiagnoseParamChanged(QJsonObject radioFMDiagnoseParam);
    void dutyCycleChanged(int dutyCycle);
    void leftRightRollChanged(int leftRightRoll);
    void leftRightShiftChanged(int leftRightShift);
    void upDownShiftChanged(int upDownShift);
    void flatModeChanged(int flatMode);
    void avCommInfoChanged(QJsonObject avCommInfo);
    void meterInfoChanged(QJsonObject meterInfo);
    void delErrorHistoryChanged(bool delErrorHistory);
    void errorHistoryChanged(QJsonArray errorHistory);
    void meterVersionChanged(QJsonArray meterVersion);

public slots:
/* For Qml below */
    void setHMIReady(void);
    void mcuagtInit(void);
    void mcuAgtAPITest(void);          //System
    void setVolumeUp(void);
    void setVolumeDown(void);
    void setAudioSource(int SourceId);
    void startUpdataCore(void);
    void restartCore(void);
    void beep(int beepType);
    bool gethasCamera(void);
    bool getrevStatus(void);
    void setUsbPower(int time);		// time * 500 ms
    void setAudioPower(bool powerStatus);
    void setBluetoothVolume(int btVolume);
    void setEngineerMode(int engineerModeId);
    void setCameraBrightness(int brightness);
    void setCameraContrast(int contrast);
    void setCameraGrayScale(int greyscale);
    void startCamera(bool state,bool auxState);
    void setSettingOverlayer(QJsonArray data);
    void startCameraWithoutSetFB1(bool state, bool auxState);
    void setVideoSource(int source, int resolution);
    void setBlackfb();
    void setSaveSettingsInfo(void);
    void getSaveSettingsInfo(void);
    void reqAppVersionInfo(void);
    void sendMcanInfo(char *data, int size);
    void reqMBInfo(void);
    void reqBtVerInfo(void);
    void reqBtMac(void);
	void setReverseline(bool bShowReverseLine);
    void setReverseLanguage(bool language);
    void setUsbACCSaveInfo(USB_ACC_SAVE_INFO *usbSaveInfo);
    void setCoreboardResumeInfo(void);
    void getCoreboardResumeInfo(void);
    USB_ACC_SAVE_INFO *getUsbACCSaveInfo(void);

    void setRTCMode(int modeId);      //Settings
    void setRTCTime(CLOCK_MSG *clock_msg);
    void setDateAndTime(int year,int month,int day,int hour,int minutes);
    void getTime(void);
    void requestCarSpeed(void);
    void setHours24state(bool hours24state);
    void setShowtimesw(bool showtimesw);
    void setBacklight(bool backlight);
    void setBrightness(int brightness);
    void setDayOrnight(int dayOrnight);
    void setLanguage(int language);
    void setInitialize(int initialize);
    void setContrast(int contrast);
    void setGrayScale(int greyscale);
    void setBeepSwitch(bool beepSwitch);
    void setRingVolume(int ringvolume);
    void setAudioParamBass(int audioParamBass);
    void setAudioParamTreble(int audioParamTreble);
    void setAudioParamXFiled(int audioParamXFiled);
    void setAudioParamYFiled(int audioParamYFiled);
    void setAudioParamALCLevel(int audioParamALCLevel);
    void setShowPhoneInfoOnMeterSW(bool showPhoneInfoOnMeterSW);
    void setringtongSW(bool ringtongSW);
    void setAutoAudioSwitch(bool autoAudioSwitch);
    void mute(int time);  // time from [1,9]: mute 100ms * time , time = 0 :unMute


    void radioInit(void);
    void radioScan();         //  Radio
    void setFrequency(double frequency);
    void setTuneUp();
    void setTuneDown();
    void radioSeekUp();
    void radioSeekDown();
    void savePreset(int  index);
    void recallPreset(int index);
    void getValueStationList(int band);
    void updateValueStationList();
    void cancelupdateValueStationList();
    void radioInfoUpdate();


    void getPresetList();



    void setGainState(int index);        //Aux

    void setILLlightState(bool illLightState);      //Diag
    void reqIlllightState(void);
    void reqEqPinValue(void);
    void setRadioDiagStatus(int status);
    void setDutyCycleDiagInfo(int infoType, int infoVal);
    void saveReverseDiag(bool saveRevDiag);
    void setReverseDiag(int btn);
    void playRecordFileInDiag(int status);
    void setFlatMode(int status);
    void reqFlatMode(void);
    void setAudioSpeakerDiag(int value);
    void setRadioStopConditions(int item, int operate);
    void getCamDiagInfo();

    int getCurSystemTime();
    void notifyMCUSound(void);


signals:
    void mcuStatusChanged(int statusIndex);
    void keycodeChanged(QJsonArray keyCode);


public:
    int _year;       //Settings
    int _month;
    int _day;
    int _hour;
    int _minutes;
    int _second;
    bool _hours24state;
    bool _backlight;
    int _brightness;
    int _dayOrnight;
    bool _showtimesw;
    int _language;
    bool _initialize;
    QString _version;
    int _contrast;
    int _grayScale;
    bool _beepSwitch;
    int _bluetoothVolume;
    int _audioParamBass;
    int _audioParamTreble;
    int _audioParamXFiled;
    int _audioParamYFiled;
    int _audioParamALCLevel;
    int _ringVolume;
    bool _hasCamera;
    bool _revStatus;
    bool _powerStatus;
    int _powerMode;
    bool _powerKeyStatus;
    int _powerKeyMode;
    int _mediaVolume;
    int _audioSource;
    int _cameraBrightness;
    int _cameraContrast;
    int _cameraGrayScale;
    QString _appVerInfo;
    bool _showPhoneInfoOnMeterSW;
    bool _ringtongSW;
    bool _autoAudioSwitch;
    QString _mbVerInfo;
    QString _mbChecksumInfo;
    QString _btVerInfo;
    QString _btMac;
    int _carSpeed;
    SETTINGS_SAVE_INFO m_settingsSaveInfo;
    USB_ACC_SAVE_INFO m_usbAccSaveInfo;

    int _radioBand;          //Radio
    double _frequency;
    QJsonArray _ampresetList;
    QJsonArray _fmpresetList;
    int _presetID;
    int _radioState;
    QJsonArray _valueList;

    QJsonArray _amValueList;
    QJsonArray _fmValueList;
    int _amFrequency;
    double _fmFrequency;
    RADIO_INFO m_radioInfo;
    int m_amValueListNum ;
    int m_fmValueListNum ;
    bool m_bRadioInited ;


    bool _auxReady;     //Aux
    int _gainState;

    bool _iLLlightState;       //Diag
    int _eqPinValue;
    QJsonObject _radioAMDiagnoseParam;
    QJsonObject _radioFMDiagnoseParam;
    int _dutyCycle;
    int _leftRightRoll;
    int _leftRightShift;
    int _upDownShift;
    int _flatMode;
    int _action;
    QJsonObject _avCommInfo;
    QJsonObject _meterInfo;
    bool _delErrorHistory;
    QJsonArray _errorHistory;
    QJsonArray _meterVersion;
    bool revOpenFlag;
    double m_colorkey_enable;
    double m_color_key;
    double m_alpha_val;

    bool bHardKeyTestFlag;
    int timeStampStart;
    int timeStampEnd;
};


#endif // HSPLUGINMCUAGENT_H
