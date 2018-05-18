import QtQuick 2.3

Item {
    id: root;
    width: 1280;
    height: 720;
    visible: true;


    Image {
        id: bg;
        anchors.fill: parent;
        source: "qrc:/images/BG.png";
    }

    Loader {
        id: mune
        anchors.top: parent.top;
        anchors.left: parent.left;
        width: 406;
        height: 720;
        source: "qrc:/qml/Menu.qml";
        onLoaded: {
            item.sigMuteBtnClicked.connect(slotMuteBtnClicked);
        }
    }

    Loader {
        id: testMCU;
        visible: false;
        anchors.fill: parent
        source: "qrc:/qml/TestFccMCU.qml";
        z:2;
        onLoaded: {
            item.testMcuBack.connect(onTestMcuBack);
        }
    }

    Loader {
        id: setOption;
        x: 458;
        anchors.top: parent.top;
        anchors.topMargin: 63;
        source: "qrc:/qml/SetOption.qml";
        visible: true;
        onLoaded: {
            item.sigSetOptionClicked.connect(slotSetOptionClicked);
        }
    }



    Loader {
        id: airConditionerPage;
        anchors.fill: parent;
        visible: false;
        source: "qrc:/qml/AirConditioner.qml";
    }

    Loader {
        id: rearviewMirrorPage;
        anchors.fill: parent;
        visible: false;
        source: "qrc:/qml/RearviewMirror.qml";
    }

    Loader {
        id: seatSetingPage;
        anchors.fill: parent;
        visible: false;
        source: "qrc:/qml/SeatSetting.qml";
    }

    Loader {
        id: lightingPage;
        anchors.fill: parent;
        visible: false;
        source: "qrc:/qml/LightPage.qml";
        onLoaded: {

        }
    }

    Loader {
        id: driverAssistancePage;
        anchors.fill: parent;
        visible: false;
        source: "qrc:/qml/DriverAssistance_Set.qml";
    }


    Loader {
        id: setting;
        x: 458;
        anchors.top: parent.top;
        anchors.topMargin: 63;
        source: "qrc:/qml/Setting.qml";
        visible: false;
        onLoaded: {
            item.sigSettingClicked.connect(slotSettingClicked);
        }
    }

    Loader {
        id: effcts_set;
        anchors.fill: parent;
        visible: false;
        //asynchronous: true;
        source: "qrc:/qml/Effcts_Set.qml";
    }

    Loader {
        id: despilay_set;
        anchors.fill: parent;
        visible: false;
        asynchronous: true;
        source: "qrc:/qml/Display_Set.qml";
        onLoaded: {
            item.clockButtonClicked.connect(onClockButtonClicked)
        }
    }

    Loader {
        id: starCeiling_Set;
        anchors.fill: parent;
        visible: false;
        asynchronous: true;
        source: "qrc:/qml/StarCeiling_Set.qml";
    }

    Loader {
        id: tirePressure_Set;
        anchors.fill: parent;
        visible: false;
        asynchronous: true;
        source: "qrc:/qml/TirePressure_Set.qml";
    }

    Loader {
        id: photoplaying;
        anchors.fill: parent;
        visible: false;
        asynchronous: true;
        source: "qrc:/qml/PhotoPlaying.qml";
        onLoaded: {
            item.quitPhoto.connect(function(){
                                       photoplaying.visible = false;
                                   });
        }
    }

    Loader{
        id: setTimePage
        anchors.fill: parent;
        visible: false;
        source: "qrc:/qml/setTime_set.qml";
        onLoaded: {
            item.hideClicked.connect(onHideClicked);
        }
    }

    VolumeBar{
        id: volumeBar
        anchors.centerIn: parent;
        visible: false;
        //Component.onCompleted: show();
    }

    Item { // mcu test MouseArea
        width: 50;
        height: 100;
        anchors.right: parent.right;
        anchors.bottom: parent.bottom;
        MouseArea{
            anchors.fill: parent;
            onClicked: {
                c_qmlInterface.qmlDebug("testMCU.visible = true");
                testMCU.visible = true;
            }
        }
    }
    function onTestMcuBack()
    {
        testMCU.visible = false;
    }


    function onClockButtonClicked()
    {
        setTimePage.visible = true;
    }

    function onHideClicked()
    {
        setTimePage.visible = false;
    }

    function slotMuteBtnClicked(flag)
    {
        switch(flag)
        {
        case 1: //radio
            c_qmlInterface.sendFccCAN('2-1-1-0-0-0');
            break;
        case 2: //media
            c_qmlInterface.sendFccCAN('2-1-6-0-0-0');
            break;
        case 3: //Navi
            c_qmlInterface.sendFccCAN('2-1-4-0-0-0');
            break;
        case 4: //BT
            c_qmlInterface.sendFccCAN('2-1-5-0-0-0');
            break;
        case 5: //BT music
            c_qmlInterface.sendFccCAN('2-1-7-0-0-0');
            break;
        case 6: //VR
            c_qmlInterface.sendFccCAN('2-1-8-0-0-0');
            break;
        case 7: //vol+
            c_qmlInterface.sendFccCAN('2-6-1-0-0-0');
            c_qmlInterface.sendFccCAN('2-6-0-0-0-0');
            //c_qmlInterface.setVolumeUp();
            break;
        case 8:
            volumeBar.visible = true;
            break;
        case 9: //HOME
            airConditionerPage.visible = false;
            rearviewMirrorPage.visible = false;
            seatSetingPage.visible = false;
            lightingPage.visible = false;
            driverAssistancePage.visible = false;
            setting.visible = false;
            effcts_set.visible = false;
            despilay_set.visible = false;
            starCeiling_Set.visible = false;
            tirePressure_Set.visible = false;
            setOption.visible = true;
            break;
        case 10: //Mute
            c_qmlInterface.setVolumeMute(100);
            break;
        case 11: //vol-
            c_qmlInterface.sendFccCAN('2-6-2-0-0-0');
            c_qmlInterface.sendFccCAN('2-6-0-0-0-0');
            //c_qmlInterface.setVolumeDown();
            break;
        case 12:
            photoplaying.visible = true;
            break;
        default:
            break;
        }
    }

    function slotSetOptionClicked(index)
    {
        switch(index)
        {
        case 1:
            setOption.visible = false;
            airConditionerPage.visible = true;
            break;
        case 2:
            setOption.visible = false;
            rearviewMirrorPage.visible = true;
            break;
        case 3:
            setOption.visible = false;
            seatSetingPage.visible = true;
            break;
        case 4:
            setOption.visible = false;
            lightingPage.visible = true;
            break;
        case 5:
            setOption.visible = false;
            setting.visible = true;
            c_qmlInterface.getBrightness();
            c_qmlInterface.getCanInfo("BSD");
            break;
        case 6: //泊车雷达
            break;
        default:
            break;
        }
    }

    function slotSettingClicked(index)
    {
        switch(index)
        {
        case 1: //Effcts
            setting.visible = false;
            effcts_set.visible = true;
            break;
        case 2: //desplay
            setting.visible = false;
            despilay_set.visible = true;
            break;
        case 3: //星空顶棚
            setting.visible = false;
            starCeiling_Set.visible = true;
            break;
        case 4: //雨刮复位
            c_qmlInterface.sendFccCAN('1-19-1-0-0-0-0');
            c_qmlInterface.sendFccCAN('1-19-0-0-0-0-0');
            break;
        case 5://胎压
            setting.visible = false;
            tirePressure_Set.visible = true;
            break;
        case 6://辅助驾驶
            setting.visible = false;
            driverAssistancePage.visible = true;
            break;
        default:
            break;
        }
    }


    Connections{
        target: c_qmlInterface;
        onSigAUDIOInfoVolume:volumeBar.setvolume(vol);
        onSigAUDIOInfoTreble:effcts_set.item.setTrebleVal(treble);
        onSigAUDIOInfoBass:effcts_set.item.setBassVal(bass);
        onSigFACwindSpeedLevel:airConditionerPage.item.retFACwindSpeedLevel(level);
        onSigFACwindSpeedModel:airConditionerPage.item.retFACwindSpeedModel(model);
        //onSigSRLightLevel:lightingPage.item.retSRLightLevel(level);//星空顶棚模式
        onSigLightBrightnessLevel:lightingPage.item.retSRLightLevel(level);
        onSigTimeMinute:setTimePage.item.retTimeMinute(minute);
        onSigTimeHour:setTimePage.item.retTimeHour(hour);
        onSigSubDistanceA:despilay_set.item.retSubDistanceA(distance);
        onSigSubDistanceB:despilay_set.item.retSubDistanceB(distance);
        onSigBSDInfoFCW:driverAssistancePage.item.retBSDInfoFCW(flag);
        onSigBSDInfoLDW:driverAssistancePage.item.retBSDInfoLDW(flag);
        onSigBSDInfoISA:driverAssistancePage.item.retBSDInfoISA(flag);
        onSigBSDInfoBSDF:driverAssistancePage.item.retBSDInfoBSDF(flag);
        onSigBSDInfoBSD:driverAssistancePage.item.retBSDInfoBSD(flag);
        onSigBSDInfoRCW:driverAssistancePage.item.retBSDInfoRCW(flag);
        onSigBSDInfoDOW:driverAssistancePage.item.retBSDInfoDOW(flag);
        onSigBSDInfoIHC:driverAssistancePage.item.retBSDInfoIHC(flag);
    }

    Component.onCompleted: {
        c_qmlInterface.getCanInfo("AUDIO");
    }


}

