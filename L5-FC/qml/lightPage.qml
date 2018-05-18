﻿import QtQuick 2.3

Item {
    anchors.fill: parent;
    property int brightnessTxt: 5;


    BaseText{
        anchors.left: leftLightON.left;
        anchors.leftMargin: 12;
        anchors.bottom: leftLightON.top;
        size: 28;
        text: qsTr("左阅读灯");
    }

    BaseButton {
        id:leftLightON;
        width: 110;
        height: 110;
        anchors.left: parent.left;
        anchors.leftMargin: 493;
        anchors.top: parent.top;
        anchors.topMargin: 138;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked:  c_qmlInterface.sendFccCAN('1-0-0-0-16-0-4');
    }

    BaseButton {
        id:leftLightOFF;
        width: 110;
        height: 110;
        anchors.left: leftLightON.right;
        anchors.leftMargin: 38;
        anchors.top: leftLightON.top;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked:  c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0');
    }

    BaseText{
        anchors.left: rightLightON.left;
        anchors.leftMargin: 12;
        anchors.bottom: rightLightON.top;
        size: 28;
        text: qsTr("右阅读灯");
    }

    BaseButton{
        id:rightLightON;
        width: 110;
        height: 110;
        anchors.left: leftLightOFF.right;
        anchors.leftMargin: 109;
        anchors.top: leftLightON.top;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked:  c_qmlInterface.sendFccCAN('1-0-0-0-16-0-8');
    }


    BaseButton {
        id:rightLightOFF;
        width: 110;
        height: 110;
        anchors.left: rightLightON.right;
        anchors.leftMargin: 38;
        anchors.top: leftLightON.top;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked:  c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0');
    }

    Image {
        width: 787; height: 1;
        anchors{left: leftLightON.left; top: leftLightON.bottom; topMargin: 45;}
        source: "qrc:/images/light/Set_Light_fgt.png"
    }


    BaseText{
        anchors.left: atmosphereLightON.left;
        anchors.leftMargin: 12;
        anchors.bottom: atmosphereLightON.top;
        size: 28;
        text: qsTr("氛围灯");
    }

    BaseButton {
        id:atmosphereLightON;
        width: 110;
        height: 110;
        anchors.left: leftLightON.left;
        anchors.top: parent.top;
        anchors.topMargin: 373;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked:  c_qmlInterface.sendFccCAN('5-125-125-125-2');
    }


    BaseButton {
        id:atmosphereLightOFF;
        width: 110;
        height: 110;
        anchors.left: atmosphereLightON.right;
        anchors.leftMargin: 38;
        anchors.top: atmosphereLightON.top;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked:  c_qmlInterface.sendFccCAN('5-125-125-125-1');
    }


    BaseText{
        anchors.left: rightLightON.left;
        anchors.leftMargin: 12;
        anchors.bottom: btnBg.top;
        size: 28;
        text: qsTr("氛围灯亮度");
    }

    Image {
        id: btnBg
        width: 326;
        height: 110;
        anchors.left: atmosphereLightOFF.right;
        anchors.leftMargin: 109;
        anchors.top: atmosphereLightON.top;
        source: "qrc:/images/light/Set_Light_ld.png"

        BaseButton {
            width: 110;
            height: 110;
            anchors.left: parent.left;
            normalSource: "qrc:/images/AC_Tem_leftAdd_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftAdd_exe.png"
            onClicked: onJustmentBtnClicked(7);
        }

        BaseButton {
            width: 110;
            height: 110;
            anchors.right: parent.right;
            normalSource: "qrc:/images/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftSub_exe.png"
            onClicked: onJustmentBtnClicked(8);
        }
    }

    BaseText{
        anchors.centerIn: btnBg;
        size: 46;
        text: brightnessTxt;
    }


    BaseText{
        anchors{left: atmosphereLightON.left; leftMargin: 12;}
        anchors{top: atmosphereLightON.bottom; topMargin: 52;}
        size: 28;
        text: qsTr("氛围灯颜色");
    }
    Image {
        id: name
        width: 669; height: 29;
        anchors{left: parent.left; leftMargin: 505;}
        anchors{top: btnBg.bottom; topMargin: 96;}
        source: "qrc:/images/light/Set_Light_ys.png"
    }


    function onJustmentBtnClicked(val)
    {
        var tmp;
        switch(val)
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
            if(brightnessTxt < 10){
                tmp = brightnessTxt +1;
                brightnessTxt = tmp;
                tmp = "5-125-125-125-"+"-tmp";
                c_qmlInterface.sendFccCAN(tmp)
            }
            break;
        case 8:
            if(brightnessTxt > 1){
                tmp = brightnessTxt -1;
                brightnessTxt = tmp;
                tmp = "5-125-125-125-"+"-tmp";
                c_qmlInterface.sendFccCAN(tmp)
            }
            break;
        default:
            break;
        }
    }

    function retSRLifeReadingLight(flag)
    {
        if(flag === 0){
            console.log(" ###### Life Reading Light Off");
            leftLightOFF.normalSource = "qrc:/images/light/Set_Light_off_exe.png";
            leftLightON.normalSource = "qrc:/images/light/Set_Light_off_nml.png";
        }else{
            console.log(" ###### Life Reading Light On");
            leftLightOFF.normalSource = "qrc:/images/light/Set_Light_off_nml.png";
            leftLightON.normalSource = "qrc:/images/light/Set_Light_off_exe.png";
        }
    }

    function retSRRightReadingLight(flag)
    {
        if(flag === 0){
            console.log(" ###### Right Reading Light Off");
            rightLightOFF.normalSource = "qrc:/images/light/Set_Light_off_exe.png";
            rightLightOFF.normalSource = "qrc:/images/light/Set_Light_off_nml.png";
        }else{
            console.log(" ###### Right Reading Light On");
            rightLightOFF.normalSource = "qrc:/images/light/Set_Light_off_nml.png";
            rightLightOFF.normalSource = "qrc:/images/light/Set_Light_off_exe.png";
        }
    }

    function retSRLightLevel(level)
    {
        console.log(" ###### retSRLightLevel level:", level);
        brightnessTxt = level;
    }

//    Connections{
//        target: c_qmlInterface;
//        onSigSRLifeReadingLight:retSRLifeReadingLight(flag);
//        onSigSRRightReadingLight:retSRRightReadingLight(flag);
//        onSigSRLightLevel:retSRLightLevel(level);
//    }


    Component.onCompleted: {
        c_qmlInterface.getCanInfo("AmbientLightColor");
        c_qmlInterface.getCanInfo("SR");
    }

}