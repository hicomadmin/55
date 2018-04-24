import QtQuick 2.3

Item {
    id: root;
    width: 1280;
    height: 720;
    visible: true;


    Image {
        id: bg;
        anchors.fill: parent;
        //asynchronous: true;
        source: "qrc:/images/BG.png";
        Component.onCompleted:c_qmlInterface.qmlDebug(" [main.qml] Loader BG.png completed");
    }

    Loader {
        id: mune
        anchors.top: parent.top;
        anchors.left: parent.left;
        width: 1280;
        height: 263;
        source: "qrc:/qml/Menu.qml";
        onLoaded: {
            item.sigMuteBtnClicked.connect(slotMuteBtnClicked);
        }
    }


    Loader {
        id: setOption;
        visible: true;
        //visible: false;
        anchors.fill: parent
        source: "qrc:/qml/SetOption.qml";
        onLoaded: {
            item.sigSetOptionClicked.connect(slotSetOptionClicked);
        }
    }

    Loader {
        id: usbPage;
        visible: false;
        anchors.fill: parent
        source: "qrc:/qml/media.qml";
    }

    Loader {
        id: airConditionerPage;
        visible: false;
        anchors.fill: parent
        asynchronous: true;
        source: "qrc:/qml/airConditioner.qml";
    }

    Loader {
        id: lightPage;
        visible: false;
        anchors.fill: parent
        asynchronous: true;
        source: "qrc:/qml/lightPage.qml";
    }

    Loader {
        id: chirismusPage;
        visible: false;
        anchors.fill: parent
        asynchronous: true;
        source: "qrc:/qml/chirismus.qml";
    }

    Loader {
        id: chairBackPage;
        visible: false;
        anchors.fill: parent
        asynchronous: true;
        source: "qrc:/qml/chairBack.qml";
    }

    Loader {
        id: hotWindPage;
        visible: false;
        anchors.fill: parent
        asynchronous: true;
        source: "qrc:/qml/hotWind.qml";
    }

    Loader {
        id: starSkyPage;
        visible: false;
        anchors.fill: parent
        asynchronous: true;
        source: "qrc:/qml/starSky.qml";
    }

    Loader {
        id: coldWarmPage;
        visible: false;
        anchors.fill: parent
        asynchronous: true;
        source: "qrc:/qml/coldWarm.qml";
    }


    Loader {
        id: backgroundLightPage;
        visible: false;
        anchors.fill: parent
        asynchronous: true;
        source: "qrc:/qml/backgroundLight.qml";
    }

    Loader {
        id: effectsPage;
        visible: false;
        anchors.fill: parent
        asynchronous: true;
        source: "qrc:/qml/effcts.qml";
    }

    Loader {
        id: carWithSpeedPage;
        visible: false;
        anchors.fill: parent
        asynchronous: true;
        source: "qrc:/qml/carWithSpeed.qml";
    }

    Loader {
        id: windowCurtainsPage;
        visible: false;
        anchors.fill: parent
        asynchronous: true;
        source: "qrc:/qml/windowCurtains.qml";
    }

    Loader {
        id: helpPage;
        visible: false;
        anchors.fill: parent
        asynchronous: true;
        source: "qrc:/qml/helpPage.qml";
        onLoaded: {
            item.sigHelpPageBack.connect(slotHelpPageBack);
        }
    }


    VolumeBar{
        id: volumeBar
        anchors.centerIn: parent;
        visible: false;
        //Component.onCompleted: show();
    }

//    Loader {
//        id: volBar;
//        visible: true;
//        anchors.fill: parent
//        source: "qrc:/qml/VolumeBar.qml";
//        onLoaded:

//    }


    function slotMuteBtnClicked(flag)
    {
        switch(flag)
        {
        case 1:
            break;
        case 2:
            hideOption();
            setOption.visible = false;
            usbPage.visible = true;
            break;
        case 3:
            hideOption();
            setOption.visible = false;
            usbPage.visible = true;
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            volumeBar.visible = true;
            break;
        case 7:
            break;
        case 8:
            hideOption();
            usbPage.visible = false;
            setOption.visible = true;
            break;
        case 9:
            volumeBar.visible = true;
            break;
        case 10:
            volumeBar.visible = true;
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
            lightPage.visible = true;
            break;
        case 3:
            setOption.visible = false;
            chirismusPage.visible = true;
            break;
        case 4:
            setOption.visible = false;
            chairBackPage.visible = true;
            break;
        case 5:
            setOption.visible = false;
            hotWindPage.visible = true;
            break;
        case 6:
            setOption.visible = false;
            starSkyPage.visible = true;
            break;
        case 7:
            setOption.visible = false;
            coldWarmPage.visible = true;
            break;
        case 8:
            setOption.visible = false;
            backgroundLightPage.visible = true;
            break;
        case 9:
            setOption.visible = false;
            effectsPage.visible = true;
            break;
        case 10:
            setOption.visible = false;
            carWithSpeedPage.visible = true;
            break;
        case 11:
            setOption.visible = false;
            windowCurtainsPage.visible = true;
            break;
        case 12:
            setOption.visible = false;
            mune.visible = false;
            bg.visible = false;
            helpPage.visible = true;
            break;
        default:
            break;
        }
    }

    function hideOption()
    {
        airConditionerPage.visible = false;
        lightPage.visible = false;
        chirismusPage.visible = false;
        chairBackPage.visible = false;
        hotWindPage.visible = false;
        starSkyPage.visible = false;
        coldWarmPage.visible = false;
        backgroundLightPage.visible = false;
        effectsPage.visible = false;
        carWithSpeedPage.visible = false;
        windowCurtainsPage.visible = false;
        helpPage.visible = false;
    }


    function slotHelpPageBack()
    {
        helpPage.visible = false;
        bg.visible = true;
        mune.visible = true;
        setOption.visible = true;
    }

}

