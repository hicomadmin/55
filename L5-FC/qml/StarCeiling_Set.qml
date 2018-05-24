import QtQuick 2.3

Item {
    anchors.fill: parent;
    property int whichMode: 0;
    signal goBackClicked();

    BaseButton {
        id: starCeilingON;
        width: 110;
        height: 110;
        anchors.left:parent.left;
        anchors.leftMargin: 692;
        anchors.top: parent.top;
        anchors.topMargin: 165;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: {
            if(whichMode < 1 || whichMode > 8){
                whichMode = 1;
            }
            var strData = "5-3-" + whichMode + "-0-0";
            c_qmlInterface.sendFccCAN(strData);
        }
    }

    BaseButton {
        id:starCeilingOFF;
        width: 110;
        height: 110;
        anchors.left: starCeilingON.right;
        anchors.leftMargin: 66;
        anchors.top: starCeilingON.top;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('5-3-0-0-0');
    }

    BaseText{
        anchors.left: starCeilingON.left;
        anchors.leftMargin: 65;
        anchors.bottom: starCeilingON.top;
        size: 28;
        text: qsTr("星空顶棚开关");
    }


    BaseText{
        anchors.left: yellowBtn.left;
        anchors.leftMargin: 62;
        anchors.bottom: redBtn.top;
        size: 28;
        text: qsTr("星空顶棚颜色");
    }


    BaseButton {
        id:redBtn;
        width: 110;
        height: 110;
        anchors.left:parent.left;
        anchors.leftMargin: 517;
        anchors.top: starCeilingOFF.bottom;
        anchors.topMargin: 109;
        btnText: qsTr("主题1");
        textsize: 28;
        Image {
            x:30; y:12
            visible: whichMode==1;
            source: "qrc:/images/air/AC_Icon_powerd_dec.png"
        }
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('5-3-1-0-0');
    }

    BaseButton {
        id:yellowBtn;
        width: 110;
        height: 110;
        anchors.left: redBtn.right;
        anchors.leftMargin: 66;
        anchors.top: redBtn.top;
        btnText: qsTr("主题2");
        textsize: 28;
        Image {
            x:30; y:12
            visible: whichMode==2;
            source: "qrc:/images/air/AC_Icon_powerd_dec.png"
        }
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('5-3-2-0-0');
    }

    BaseButton {
        id:blueBtn;
        width: 110;
        height: 110;
        anchors.left: yellowBtn.right;
        anchors.leftMargin: 66;
        anchors.top: redBtn.top;
        btnText: qsTr("主题3");
        textsize: 28;
        Image {
            x:30; y:12
            visible: whichMode==3;
            source: "qrc:/images/air/AC_Icon_powerd_dec.png"
        }
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('5-3-3-0-0');
    }

    BaseButton {
        id:theme4;
        width: 110;
        height: 110;
        anchors.left: blueBtn.right;
        anchors.leftMargin: 66;
        anchors.top: redBtn.top;
        btnText: qsTr("主题4");
        textsize: 28;
        Image {
            x:30; y:12
            visible: whichMode==4;
            source: "qrc:/images/air/AC_Icon_powerd_dec.png"
        }
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('5-3-4-0-0');
    }

    BaseButton {
        id:theme5;
        width: 110;
        height: 110;
        anchors.left: redBtn.left;
        anchors.top: redBtn.bottom;
        anchors.topMargin: 4;
        btnText: qsTr("主题5");
        textsize: 28;
        Image {
            x:30; y:12
            visible: whichMode==5;
            source: "qrc:/images/air/AC_Icon_powerd_dec.png"
        }
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('5-3-5-0-0');
    }

    BaseButton {
        id:theme6;
        width: 110;
        height: 110;
        anchors.left: theme5.right;
        anchors.leftMargin: 66
        anchors.top: theme5.top;
        btnText: qsTr("主题6");
        textsize: 28;
        Image {
            x:30; y:12
            visible: whichMode==6;
            source: "qrc:/images/air/AC_Icon_powerd_dec.png"
        }
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('5-3-6-0-0');
    }

    BaseButton {
        id:theme7;
        width: 110;
        height: 110;
        anchors.left: theme6.right;
        anchors.leftMargin: 66
        anchors.top: theme5.top;
        btnText: qsTr("主题7");
        textsize: 28;
        Image {
            x:30; y:12;
            visible: whichMode==7;
            source: "qrc:/images/air/AC_Icon_powerd_dec.png"
        }
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('5-3-7-0-0');
    }

    BaseButton {
        id:theme8;
        width: 110;
        height: 110;
        anchors.left: theme7.right;
        anchors.leftMargin: 66
        anchors.top: theme5.top;
        btnText: qsTr("主题8");
        textsize: 28;
        Image {
            x:30; y:12;
            visible: whichMode==8;
            source: "qrc:/images/air/AC_Icon_powerd_dec.png"
        }
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('5-3-8-0-0');
    }

    BaseButton {
        id: goBack
        width: 60; height: 60;
        anchors.right: parent.right;
        anchors.rightMargin: 48;
        anchors.top: parent.top;
        anchors.topMargin: 31;
        normalSource: "qrc:/images/set/Set_icon_tymm_back.png";
        pressSource:  "qrc:/images/set/Set_icon_tymm_back.png";
        onClicked: goBackClicked();
    }


    function retSRLightLevel(level)
    {
        console.log(" #### StarCeiling_Set.qml level = ", level);
        whichMode = level;
    }

}
