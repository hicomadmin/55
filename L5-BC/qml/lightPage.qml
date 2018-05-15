import QtQuick 2.3

Item {
    anchors.fill: parent;
    property int level: 1;

    MenuButton{
        id:leadingLightON_l;
        width: 110;  height: 110;
        anchors{left: parent.left; leftMargin: 94; top: parent.top; topMargin: 362;}
        topMag: 41;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendRccCAN('4-0-0-0-2-0-4');
    }

    BaseText{
        anchors{left: leadingLightON_l.left; leftMargin: 12;}
        anchors.bottom: leadingLightON_l.top;
        anchors.bottomMargin: 18;
        text: qsTr("左阅读灯");

    }

    MenuButton{
        id:leadingLightOFF_l;
        width: 110;  height: 110;
        anchors{left: leadingLightON_l.right; leftMargin: 38; top: leadingLightON_l.top;}
        topMag: 41;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendRccCAN('4-0-0-0-2-0-0');
    }



    MenuButton{
        id:leadingLightON_r;
        width: 110;  height: 110;
        anchors{left: leadingLightOFF_l.right; leftMargin: 124; top: leadingLightON_l.top;}
        topMag: 41;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendRccCAN('4-0-0-0-2-0-8');
    }

    BaseText{
        anchors{left: leadingLightON_r.left; leftMargin: 12;}
        anchors.bottom: leadingLightON_l.top;
        anchors.bottomMargin: 18;
        text: qsTr("右阅读灯");

    }

    MenuButton{
        id:leadingLightOFF_r;
        width: 110;  height: 110;
        anchors{left: leadingLightON_r.right; leftMargin: 38; top: leadingLightON_l.top;}
        topMag: 41;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendRccCAN('4-0-0-0-2-0-0');
    }



    MenuButton{
        id:atmosphereON;
        width: 110;  height: 110;
        anchors{left: leadingLightOFF_r.right; leftMargin: 124; top: leadingLightON_l.top;}
        topMag: 41;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendRccCAN('5-125-125-125-16');
    }

    BaseText{
        anchors{left: atmosphereON.left; leftMargin: 12;}
        anchors.bottom: leadingLightON_l.top;
        anchors.bottomMargin: 18;
        text: qsTr("氛围灯");

    }

    MenuButton{
        width: 110;  height: 110;
        anchors{left: atmosphereON.right; leftMargin: 38; top: leadingLightON_l.top;}
        topMag: 41;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendRccCAN('5-125-125-125-0');
    }



    Image {
        id: color
        width: 669;
        height: 29;
        anchors{left: parent.left; leftMargin: 104}
        anchors{top: leadingLightON_l.bottom; topMargin: 127;}
        source: "qrc:/images/light/Set_Light_ys.png"
    }
    BaseText{
        anchors{left: leadingLightON_l.left; leftMargin: 12;}
        anchors.bottom: color.top;
        anchors.bottomMargin: 59;
        text: qsTr("氛围灯颜色");
    }


    Image {
        id: btnBg
        width: 326;
        height: 110;
        anchors{left: color.right; leftMargin: 83; verticalCenter: color.verticalCenter}
        source: "qrc:/images/light/Set_Light_ld.png";
        BaseButton{
            width: 110;  height: 110;
            anchors.left: parent.left;
            normalSource: "qrc:/images/effects/AC_Tem_leftAdd_nml.png";
            pressSource:  "qrc:/images/effects/AC_Tem_leftAdd_exe.png";
            onClicked: onAdjustmentBtnClicked(10);
        }
        BaseButton{
            width: 110;  height: 110;
            anchors.right: parent.right;
            normalSource: "qrc:/images/effects/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/effects/AC_Tem_leftSub_exe.png";
            onClicked: onAdjustmentBtnClicked(11);
        }
        BaseText{
            anchors.centerIn: parent;
            text: level//"00"
        }
    }
    BaseText{
        anchors{left: atmosphereON.left; leftMargin: 12;}
        anchors.bottom: btnBg.top;
        anchors.bottomMargin: 18;
        text: qsTr("氛围灯亮度");
    }



    function onAdjustmentBtnClicked(val)
    {
        var strData;
        switch(val)
        {
        case 10:
            level += 1
            strData = "5-125-125-125-" + level+1
            c_qmlInterface.sendRccCAN(strData);
            break;
        case 11:
            level += 1
            strData = "5-125-125-125-" + level+1
            c_qmlInterface.sendRccCAN(strData);
            break;
        default:
            break;
        }
    }

}
