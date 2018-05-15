
#include "TheMcuAgent.h"

using namespace std;


TheXMCUAGT* TheXMCUAGT::pInstance = nullptr;

static void * pvHandle = NULL;

int g_CurSourceId = 4;

CAMERAPARAM cameraParamInfo = {0,0,0,0,0,0};

TheXMCUAGT::TheXMCUAGT(HSPluginBaseController *parent):
    HSPluginBaseController(parent)
{
    hslog_debug("TheXMCUAGT start up...");
    hslog_debug("[TheXMCUAGT] ----- TheXMCUAGT-----thread: [%x]",(int)QThread::currentThreadId());
    pInstance = this;
    revOpenFlag = false;
}

TheXMCUAGT::~TheXMCUAGT(void) /*! release resources. */
{
    hslog_debug("\n [TheXMCUAGT]------------ ~TheXMCUAGT -------\n");

}
TheXMCUAGT* TheXMCUAGT::getInstance(void) const
{
    return pInstance;
}

bool TheXMCUAGT::getAutoAudioSwitch()
{
    return m_autoAudioSwitch;
}

bool TheXMCUAGT::getrevStatus()
{
    return m_revStatus;
}

bool TheXMCUAGT::getBacklight()
{
    return m_backlight;
}

bool TheXMCUAGT::getPowerKeyStatus()
{
    return m_powerKeyStatus;
}

bool TheXMCUAGT::getPowerStatus()
{
    return m_powerStatus;
}

int TheXMCUAGT::getPowerMode()
{
    return m_powerMode;
}

int TheXMCUAGT::getPowerKeyMode()
{
    return m_powerKeyMode;
}

void TheXMCUAGT::setOverlay(unsigned int enable, unsigned int color_key, unsigned int alpha_val)
{
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
}

void TheXMCUAGT::setHMIReady()
{

}

void TheXMCUAGT::heartBeatInit()
{

}

void TheXMCUAGT::startHeartBeat()
{

}

void TheXMCUAGT::startNewMcuAgtDemo()
{
    hslog_debug("[TheXMCUAGT] ----- startNewMcuAgtDemo! ---\n");
    emit runOnMcuCtlThread(NEW_MCUAGT_DEMO_START_ID,0);
}

void TheXMCUAGT::hardkeyEventHandle(unsigned char keycode, unsigned char eventType)
{
    hslog_debug("[TheXMCUAGT] ----- hardkeyEventHandle ! 0x%02X 0x%02X\n", keycode, eventType);
}

void TheXMCUAGT::mute(int time)
{
    hslog_debug("[TheXMCUAGT] ----- mute:%d---\n",time);

}

void TheXMCUAGT::beep(int type)
{
    hslog_debug("[TheXMCUAGT] ----- beep:%d---\n",type);

}

void TheXMCUAGT::sendMcanInfo(char *data, int size)
{

}

void TheXMCUAGT::setAutoAudioSwitch(bool status)
{
    m_autoAudioSwitch = status;
}

void TheXMCUAGT::setAudioSource(int SourceId)
{
    hslog_info("[TheXMCUAGT] ----- setAudioSource :%d",SourceId);
    //mcu_agent_api->set_audio_source((AUDIO_SOURCE_ID)SourceId);
}

void TheXMCUAGT::startCamera(bool state, bool auxState)
{
    hslog_debug("[TheXMCUAGT] ----- startCamera: %d ,revOpenFlag: %d ",state,revOpenFlag);
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
                    hslog_error("[TheXMCUAGT] -----auxState Error:cannot open the framebuffer device!\n");
                    close(fbfd);
                    return;
                }
                if(ioctl(fbfd,FAST_REVERSE_IOCTL_START_WITHOUT_SET_FB1,NULL))
                {
                    hslog_error("[TheXMCUAGT] -----auxState Error reading variable information\n");
                    close(fbfd);
                    return;
                }
                hslog_debug("[TheXMCUAGT] -----auxState startCameraWithoutSetFB1!");
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
                    hslog_error("[TheXMCUAGT] -----!auxState Error:cannot open the framebuffer device!\n");
                    close(fbfd);
                    return;
                }
                if(ioctl(fbfd,FAST_REVERSE_IOCTL_START_WITHOUT_SET_FB1,NULL))
                {
                    hslog_error("[TheXMCUAGT] -----!auxState Error reading variable information\n");
                    close(fbfd);
                    return;
                }
                hslog_debug("[TheXMCUAGT] -----!auxState startCameraWithoutSetFB1!");
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
}

void TheXMCUAGT::setVideoSource(int source, int resolution)
{
    hslog_debug("[TheXMCUAGT] ----- startCamera-source= %d ,resolution = %d",source,resolution);
//    VIDEO_SOURCE_INFO video_source_info = {VIDEO_SOURCE_CAMERA,VIDEO_TYPE_480P};
//    if (source == 0)
//        video_source_info.video_source = VIDEO_SOURCE_NAVI;
    //mcu_agent_api->set_video_source(&video_source_info);

}

void TheXMCUAGT::setBacklight(bool backlight)
{
    hslog_info("[TheXMCUAGT] ----- setBacklight :%d",backlight);
}

void TheXMCUAGT::setUsbACCSaveInfo(USB_ACC_SAVE_INFO *usbSaveInfo)
{

}

USB_ACC_SAVE_INFO *TheXMCUAGT::getUsbACCSaveInfo()
{
    hslog_info("[TheXMCUAGT] ----- getUsbACCSaveInfo ");
    USB_ACC_SAVE_INFO *usb_acc_save_info = &m_usbAccSaveInfo;
    return usb_acc_save_info;
}

void TheXMCUAGT::setUsbPower(int time)
{
    hslog_info("[TheXMCUAGT] ----- setUsbPower :%d",time);

}
