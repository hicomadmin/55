﻿/*************************************************
Copyright: Shenzhen Hangsheng Electronics CO.,LTD.
Author:
Date: 2018-03-13
Description: 中控屏主菜单界面
**************************************************/
import QtQuick 2.3

Item {
    anchors.fill: parent
    signal sigMuteBtnClicked(int flag);

    MenuButton{
        id:radio;
        anchors.left: parent.left;
        anchors.top: parent.top;
        width: 250;
        height: 119;
        btnText: qsTr("收音机");
        normalSource: "qrc:/images/Menu_Icon_radio_nml.png";
        pressSource:  "qrc:/images/Menu_Icon_radio_exe.png";
        onClicked: onMuteBtnClicked(1);
    }

    MenuButton{
        id:usbMedia;
        width: 250;
        height: 119;
        anchors.top: parent.top;
        anchors.topMargin: 120;
        btnText: qsTr("多媒体");
        normalSource: "qrc:/images/Menu_Icon_media_nml.png";
        pressSource:  "qrc:/images/Menu_Icon_media_exe.png";
        onClicked: onMuteBtnClicked(2);
    }

    MenuButton{
        id:navi;
        width: 250;
        height: 119;
        anchors.top: parent.top;
        anchors.topMargin: 240;
        btnText: qsTr("导航");
        normalSource: "qrc:/images/Menu_Icon_navi_nml.png";
        pressSource:  "qrc:/images/Menu_Icon_navi_exe.png";
        onClicked: onMuteBtnClicked(3);
    }

    MenuButton{
        id:bluetooth;
        width: 250;
        height: 119;
        anchors.top: parent.top;
        anchors.topMargin: 360;
        btnText: qsTr("蓝牙");
        normalSource: "qrc:/images/Menu_Icon_BT_nml.png";
        pressSource:  "qrc:/images/Menu_Icon_BT_exe.png";
        onClicked:onMuteBtnClicked(4);
    }

    MenuButton{
        id:bluetoothMusic;
        width: 250;
        height: 119;
        anchors.top: parent.top;
        anchors.topMargin: 480;
        btnText: qsTr("蓝牙音乐");
        normalSource: "qrc:/images/Menu_Icon_BT-Music_nml.png";
        pressSource:  "qrc:/images/Menu_Icon_BT-Music_exe.png";
        onClicked: onMuteBtnClicked(5);
    }

    MenuButton{
        id:voice;
        width: 250;
        height: 119;
        anchors.top: parent.top;
        anchors.topMargin: 600;
        btnText: qsTr("语音");
        normalSource: "qrc:/images/Menu_Icon_VR_nml.png";
        pressSource:  "qrc:/images/Menu_Icon_VR_exe.png";
        onClicked: onMuteBtnClicked(6);
    }

    Image {
        anchors.top: parent.top
        anchors.topMargin: 116
        width: 250;
        height: 8;
        source: "qrc:/images/List_SeparatorLine.png"
    }

    Image {
        anchors.top: parent.top
        anchors.topMargin: 236
        width: 250;
        height: 8;
        source: "qrc:/images/List_SeparatorLine.png"
    }

    Image {
        anchors.top: parent.top
        anchors.topMargin: 356
        width: 250;
        height: 8;
        source: "qrc:/images/List_SeparatorLine.png"
    }

    Image {
        anchors.top: parent.top
        anchors.topMargin: 476
        width: 250;
        height: 8;
        source: "qrc:/images/List_SeparatorLine.png"
    }

    Image {
        anchors.top: parent.top
        anchors.topMargin: 596
        width: 250;
        height: 8;
        source: "qrc:/images/List_SeparatorLine.png"
    }

    MenuButton{
        id:off;
        anchors.left: radio.right;
        anchors.leftMargin: 21
        anchors.top: parent.top;
        anchors.topMargin: 54;
        width: 64;
        height: 58;
        btnText: qsTr("");
        normalSource: "qrc:/images/Top_Icon_volum+_nml.png";
        pressSource:  "qrc:/images/Top_Icon_volum+_exe.png";
        onClicked: onMuteBtnClicked(7);
    }

    MenuButton{
        id:sound;
        anchors.left: off.left;
        anchors.top: off.bottom;
        anchors.topMargin: 86;
        width: 64;
        height: 58;
        btnText: qsTr("");
        normalSource: c_qmlInterface.isMute?"qrc:/images/Top_Icon_sound_exe.png":"qrc:/images/Top_Icon_sound_nml.png";
        pressSource:  "qrc:/images/Top_Icon_sound_exe.png";
        onClicked: onMuteBtnClicked(8);
    }

    MenuButton{
        id:home;
        width: 130;
        height: 130;
        anchors.left: off.left;
        anchors.top: parent.top;
        anchors.topMargin: 295;
        btnText: qsTr("");
        normalSource: "qrc:/images/Top_Icon_home_nml.png";
        pressSource:  "qrc:/images/Top_Icon_home_exe.png";
        onClicked: onMuteBtnClicked(9);

    }

    Item {
        width: 130;
        height: 130;
        anchors.left: home.right;
        anchors.top: parent.top;
        anchors.topMargin: 295;
        MouseArea {
            anchors.fill: parent
            onClicked:onMuteBtnClicked(12);
        }
    }


    MenuButton{
        id:mute;
        width: 64;
        height: 58;
        anchors.left: off.left;
        anchors.top: home.bottom;
        anchors.topMargin: 39;
        btnText: qsTr("");
        normalSource: "qrc:/images/Top_Icon_mute_nml.png";
        pressSource:  "qrc:/images/Top_Icon_mute_exe.png";
        onClicked: onMuteBtnClicked(10);
    }

    MenuButton{
        id:seting;
        width: 64;
        height: 58;
        anchors.left: off.left;
        anchors.top: mute.bottom;
        anchors.topMargin: 86;
        btnText: qsTr("");
        normalSource: "qrc:/images/Top_Icon_volum-_nml.png";
        pressSource:  "qrc:/images/Top_Icon_volum-_exe.png";
        onClicked: onMuteBtnClicked(11);
    }


    // ++++++++++ function +++++++++

    function onMuteBtnClicked(flag)
    {
        sigMuteBtnClicked(flag);
    }


}
