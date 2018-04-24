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
        asynchronous: true;
        source: "qrc:/qml/Effcts_Set.qml";
        onLoaded: {

        }
    }

    Loader {
        id: despilay_set;
        anchors.fill: parent;
        visible: false;
        asynchronous: true;
        source: "qrc:/qml/Display_Set.qml";
        onLoaded: {

        }
    }

    Loader {
        id: starCeiling_Set;
        anchors.fill: parent;
        visible: false;
        asynchronous: true;
        source: "qrc:/qml/StarCeiling_Set.qml";
        onLoaded: {

        }
    }

    Loader {
        id: tirePressure_Set;
        anchors.fill: parent;
        visible: false;
        asynchronous: true;
        source: "qrc:/qml/TirePressure_Set.qml";
        onLoaded: {
        }
    }

//    Loader{
//       id:keyboard;
//       anchors.fill: parent;
//       visible: true;
//       asynchronous: true;
//       source: "qrc:/qml/Keyboard.qml";
//       onLoaded: {
//       }
//    }


    function slotMuteBtnClicked(flag)
    {
        switch(flag)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
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
        case 10:
            break;
        case 11:
            break;
        case 12:
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
            break;
        case 6:
            break;
        default:
            break;
        }
    }

    function slotSettingClicked(index)
    {
        switch(index)
        {
        case 1:
            setting.visible = false;
            effcts_set.visible = true;
            break;
        case 2:
            setting.visible = false;
            despilay_set.visible = true;
            break;
        case 3:
            setting.visible = false;
            starCeiling_Set.visible = true;
            break;
        case 4:
            break;
        case 5:
            setting.visible = false;
            tirePressure_Set.visible = true;
            break;
        case 6:
            setting.visible = false;
            driverAssistancePage.visible = true;
            break;
        default:
            break;
        }
    }


    Component.onCompleted: c_qmlInterface.qmlDebug("Component.onCompleted");
}

