import QtQuick 2.3

Item {
    anchors.fill: parent;


    Image {
        id: hint
        width: 460;  height: 110;
        anchors.left: parent.left;
        anchors.leftMargin: 410;
        anchors.top: parent.top;
        anchors.topMargin: 306;
        source: "qrc:/images/coldWarm/Set_lnx_ztl.png"
        BaseText{
            anchors.centerIn: parent;
            size: 28;
            text: qsTr("已关机");
        }
    }
    BaseText{
        anchors.horizontalCenter: hint.horizontalCenter;
        anchors.bottom: hint.bottom;
        anchors.bottomMargin: 88;
        size: 28;
        text: qsTr("工作状态")
    }

    BaseText{
        anchors.horizontalCenter: hint.horizontalCenter;
        anchors.top: hint.bottom;
        anchors.topMargin: 58;
        size: 28;
        text: qsTr("车厢冷暖箱")
    }



    MenuButton{
        id:coldWarmON
        width: 110;  height: 110;
        anchors{left: hint.left; top: hint.bottom; topMargin: 16;}
        topMag: 41;
        textsize: 28;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
    }


    MenuButton{
        id:coldWarmOFF
        width: 110;  height: 110;
        anchors{left: coldWarmON.right; leftMargin: 240; top: coldWarmON.top;}
        topMag: 41;
        textsize: 28;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
    }

    MenuButton{
        id:cold
        width: 171;  height: 110;
        anchors{left: hint.left; top: coldWarmON.bottom; topMargin: 16;}
        topMag: 41;
        textsize: 28;
        btnText: qsTr("制冷");
        normalSource: "qrc:/images/coldWarm/Set_zr_nml.png";
        pressSource:  "qrc:/images/coldWarm/Set_zr_exe.png";
    }


    MenuButton{
        id:warm
        width: 171;  height: 110;
        anchors{left: cold.right; leftMargin: 117; top: cold.top;}
        topMag: 41;
        textsize: 28;
        btnText: qsTr("制热");
        normalSource: "qrc:/images/coldWarm/Set_zr_nml.png";
        pressSource:  "qrc:/images/coldWarm/Set_zr_exe.png";
    }


    function onAdjustmentBtnClicked(val)
    {
        switch(val)
        {
        case 10:
            break;
        case 11:
            break;
        default:
            break;
        }
    }

}
