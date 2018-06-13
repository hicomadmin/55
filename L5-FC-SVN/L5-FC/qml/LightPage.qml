import QtQuick 2.3

Item {
    anchors.fill: parent;
    property int brightnessTxt: 5;

    QtObject {
        id: arr
        property int currentVal: 0
        property int maxValue: 64
        property variant volArray: ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10',
                                    '11','12','13','14','15','16','17','18','19','20',
                                    '21','22','23','24','25','26','27','28','29','30',
                                    '31','32','33','34','35','36','37','38','39','40',
                                    '41','42','43','44','45','46','47','48','49','50',
                                    '51','52','53','54','55','56','57','58','59','60',
                                    '61','62','63','64']
    }



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
        Image {
            x:30; y:12;
            visible: c_qmlInterface.isLiftReadLightON;
            source: "qrc:/images/air/AC_Icon_powerd_dec.png"
        }
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked:  c_qmlInterface.sendFccCAN('5-1-1-0-0');
    }

    BaseButton {
        id:leftLightOFF;
        width: 110;
        height: 110;
        anchors.left: leftLightON.right;
        anchors.leftMargin: 38;
        anchors.top: leftLightON.top;
        btnText: qsTr("关");
        Image {
            x:30; y:12;
            visible: !c_qmlInterface.isLiftReadLightON;
            source: "qrc:/images/air/AC_Icon_powerd_dec.png"
        }
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked:  c_qmlInterface.sendFccCAN('5-1-0-0-0');
        //onClicked:  c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0');
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
        Image {
            x:30; y:12;
            visible: c_qmlInterface.isRightReadLigtON;
            source: "qrc:/images/air/AC_Icon_powerd_dec.png"
        }
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked:  c_qmlInterface.sendFccCAN('5-2-1-0-0');
        //onClicked:  c_qmlInterface.sendFccCAN('1-0-0-0-16-0-8');
    }


    BaseButton {
        id:rightLightOFF;
        width: 110;
        height: 110;
        anchors.left: rightLightON.right;
        anchors.leftMargin: 38;
        anchors.top: leftLightON.top;
        btnText: qsTr("关");
        Image {
            x:30; y:12;
            visible: !c_qmlInterface.isRightReadLigtON;
            source: "qrc:/images/air/AC_Icon_powerd_dec.png"
        }
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked:  c_qmlInterface.sendFccCAN('5-2-0-0-0');
        //onClicked:  c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0');
    }

    Image {
        id: split
        width: 787; height: 1;
        anchors{left: leftLightON.left; top: leftLightON.bottom; topMargin: 45;}
        source: "qrc:/images/light/Set_Light_fgt.png"
    }


    BaseText{
        anchors.horizontalCenter: name.horizontalCenter;
        anchors.bottom: btnBg.top;
        size: 28;
        text: qsTr("氛围灯亮度");
    }

    Image {
        id: btnBg
        width: 326;
        height: 110;
        anchors.horizontalCenter: name.horizontalCenter;
        anchors.top: parent.top;
        anchors.topMargin: 373;
        source: "qrc:/images/light/Set_Light_ld.png"

        BaseButton {
            width: 110;
            height: 110;
            anchors.left: parent.left;
            normalSource: "qrc:/images/AC_Tem_leftAdd_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftAdd_exe.png"
            onClicked: onJustmentBtnClicked(1);
        }

        BaseButton {
            width: 110;
            height: 110;
            anchors.right: parent.right;
            normalSource: "qrc:/images/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftSub_exe.png"
            onClicked: onJustmentBtnClicked(2);
        }
    }

    BaseText{
        anchors.centerIn: btnBg;
        size: 46;
        text: brightnessTxt;
    }

    BaseText{
        anchors.horizontalCenter: name.horizontalCenter;
        anchors.bottom: name.top;
        anchors.bottomMargin: 20;
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


    Rectangle{
        id: cursor;
        width: 30; height: 30;
        radius: 10
        anchors.verticalCenter: name.verticalCenter;
        x: name.x;
        color: "#000000";
        opacity: 0.8

        MouseArea{//触控区域
            anchors.fill: parent
            drag{
                target: cursor
                minimumX: name.x
                maximumX: name.x+name.width-30
                axis: Drag.XAxis
            }
            onReleased: {
                arr.currentVal = Math.round((cursor.x)/(name.width - cursor.width + 15)*arr.maxValue);
                c_qmlInterface.qmlDebug("##### onReleased 11111 arr.currentVal",arr.currentVal)
                var val = (arr.currentVal>=0&&arr.currentVal<=arr.maxValue)?arr.volArray[arr.currentVal]:arr.volArray[0];
                setColor(val);
            }

            onPositionChanged: {
                c_qmlInterface.qmlDebug("##### #############################################")
                c_qmlInterface.qmlDebug("##### onPositionChanged  arr.currentVal = ", arr.currentVal)
                c_qmlInterface.qmlDebug("##### onPositionChanged  cursor.x  = ", cursor.x )
                arr.currentVal = Math.round((cursor.x+cursor.width/2)/(name.width)*arr.maxValue);
            }
            onActiveFocusChanged: {
            }
        }
    }


    function setColor(val)
    {

        var tmp = val -49;  //49-112
        switch(tmp)
        {
        case 0:
             //c_qmlInterface.sendFccCAN("5-2-1-0-0");
            break;
        case 1:
            break;

        default:
            break;
    }


    function onJustmentBtnClicked(val)
    {
        var tmp;
        if(val === 1)
        {
            if(brightnessTxt < 7)
            {
                tmp = brightnessTxt +1;
                brightnessTxt = tmp;
                tmp = "5-7-"+brightnessTxt + "-0-0";
                c_qmlInterface.sendFccCAN(tmp);
            }
        }
        else if(val === 2)
        {
            if(brightnessTxt > 1)
            {
                tmp = brightnessTxt -1;
                brightnessTxt = tmp;
                tmp = "5-7-"+brightnessTxt + "-0-0";
                c_qmlInterface.sendFccCAN(tmp);
            }
        }
        else
        {
              console.log(" #### LightPage.qml undeifne Val ###");
        }

    }



    function retSRLightLevel(level)
    {
        console.log(" ###### retSRLightLevel level:", level);
        brightnessTxt = level;
        if(level === 1)
        {
            offFlag.visible = true;
        }
        else{
            offFlag.visible = false;
        }
    }


    Component.onCompleted: {
//        c_qmlInterface.getCanInfo("AmbientLightColor");
//        c_qmlInterface.getCanInfo("SR");
    }

}
