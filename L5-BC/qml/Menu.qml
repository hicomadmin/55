/*************************************************
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
        id:leftScreen;
        anchors.left: parent.left;
        anchors.top: parent.top;
        width: 255;
        height: 130;
        btnText: qsTr("左屏");
        normalSource: "qrc:/images/Menu_Icon_power_nml.png";
        pressSource:  "qrc:/images/Menu_Icon_power_exe.png";
        onClicked: onMuteBtnClicked(1);
    }


    MenuButton{
        id:radio;
        anchors.top: parent.top;
        anchors.left: leftScreen.right;
        width: 255;
        height: 130;
        btnText: qsTr("收音机");
        normalSource: "qrc:/images/Menu_Icon_radio_nml.png";
        pressSource:  "qrc:/images/Menu_Icon_radio_exe.png";
        onClicked: onMuteBtnClicked(2);
    }


    MenuButton{
        id:media;
        width: 255;
        height: 130;
        anchors.top: parent.top;
        anchors.left: radio.right;
        btnText: qsTr("多媒体");
        normalSource: "qrc:/images/Menu_Icon_media_nml.png";
        pressSource:  "qrc:/images/Menu_Icon_media_exe.png";
        onClicked: onMuteBtnClicked(3);
    }

    MenuButton{
        id:navi;
        width: 255;
        height: 130;
        anchors.top: parent.top;
        anchors.left: media.right;
        btnText: qsTr("导航");
        normalSource: "qrc:/images/Menu_Icon_navi_nml.png";
        pressSource:  "qrc:/images/Menu_Icon_navi_exe.png";
        onClicked: onMuteBtnClicked(4);
    }


    MenuButton{
        id:rightScreen;
        width: 255;
        height: 130;
        anchors.top: parent.top;
        anchors.left: navi.right;
        btnText: qsTr("右屏");
        normalSource: "qrc:/images/Menu_Icon_power_nml.png";
        pressSource:  "qrc:/images/Menu_Icon_power_exe.png";
        onClicked: onMuteBtnClicked(5);
    }


    Image {
        anchors.left: parent.left;
        anchors.leftMargin: 249;
        width: 13;
        height: 131;
        source: "qrc:/images/List_SeparatorLine.png"
    }

    Image {
        anchors.left: parent.left;
        anchors.leftMargin: 504;
        width: 13;
        height: 131;
        source: "qrc:/images/List_SeparatorLine.png"
    }

    Image {
        anchors.left: parent.left;
        anchors.leftMargin: 760;
        width: 13;
        height: 131;
        source: "qrc:/images/List_SeparatorLine.png"
    }

    Image {
        anchors.left: parent.left;
        anchors.leftMargin: 1016;
        width: 13;
        height: 131;
        source: "qrc:/images/List_SeparatorLine.png"
    }



    MenuButton{
        anchors.left: parent.left;
        anchors.leftMargin: 49
        anchors.top: parent.top;
        anchors.topMargin: 154;
        width: 70;
        height: 70;
        btnText: qsTr("");
        normalSource: "qrc:/images/Top_Icon_volum-_nml.png";
        pressSource:  "qrc:/images/Top_Icon_volum-_exe.png";
        onClicked: onMuteBtnClicked(6);
    }


    MenuButton{
        anchors.left: parent.left;
        anchors.leftMargin: 265
        anchors.top: parent.top;
        anchors.topMargin: 154;
        width: 70;
        height: 70;
        btnText: qsTr("");
        normalSource: "qrc:/images/Top_Icon_mute_nml.png";
        pressSource:  "qrc:/images/Top_Icon_mute_exe.png";
        onClicked: onMuteBtnClicked(7);
    }


    MenuButton{
        id:home;
        width: 130;
        height: 130;
        anchors.left: parent.left;
        anchors.leftMargin: 574;
        anchors.top: parent.top;
        anchors.topMargin: 133;
        btnText: qsTr("");
        normalSource: "qrc:/images/Top_Icon_home_nml.png";
        pressSource:  "qrc:/images/Top_Icon_home_exe.png";
        onClicked: onMuteBtnClicked(8);
    }


    MenuButton{
        id: volum;
        anchors.left: home.right;
        anchors.leftMargin: 224;
        anchors.top: parent.top;
        anchors.topMargin: 154;
        width: 70;
        height: 70;
        btnText: qsTr("");
        normalSource: "qrc:/images/Top_Icon_volum_nml.png";
        pressSource:  "qrc:/images/Top_Icon_volum_exe.png";
        onClicked: onMuteBtnClicked(9);
    }

    MenuButton{
        anchors.left: volum.right;
        anchors.leftMargin: 163;
        anchors.top: parent.top;
        anchors.topMargin: 154;
        width: 70;
        height: 70;
        btnText: qsTr("");
        normalSource: "qrc:/images/Top_Icon_volum+_nml.png";
        pressSource:  "qrc:/images/Top_Icon_volum+_exe.png";
        onClicked: onMuteBtnClicked(10);
    }


    // ++++++++++ function +++++++++

    function onMuteBtnClicked(flag)
    {
        sigMuteBtnClicked(flag);
        c_qmlInterface.qmlDebug("[ Menu.qml ] onMuteBtnClicked flag = ", flag);
    }



}
