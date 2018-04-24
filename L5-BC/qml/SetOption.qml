/*************************************************
Copyright: Shenzhen Hangsheng Electronics CO.,LTD.
Author:
Date: 2018-03-13
Description: 设置选项按键界面
**************************************************/
import QtQuick 2.3

Item {
    anchors.fill: parent;
    signal sigSetOptionClicked(int index)


    Image {
        id: line1;
        width: 1;
        height: 216;
        anchors.left: parent.left;
        anchors.leftMargin: 114;
        anchors.top: parent.top;
        anchors.topMargin: 269
        source: airCondition.focus?"qrc:/images/Main Set_List_SeparatorLine exe.png":"qrc:/images/Main Set_List_SeparatorLine nml.png";
    }

    Button{
        id:airCondition;
        width: 174;
        height: 216;
        anchors.left: line1.right;
        anchors.top: parent.top;
        anchors.topMargin: 269
        btnText: qsTr("空调");
        normalIcon: "qrc:/images/Menu_Icon_AC_nml.png";
        pressIcon:  "qrc:/images/Menu_Icon_AC_exe.png"
        onClicked: onSetOptionClick(1);
    }

    Image {
        id: line2;
        width: 1;
        height: 216;
        anchors.left: airCondition.right;
        anchors.top: parent.top;
        anchors.topMargin: 269
        source: airCondition.focus | lighting.focus ? "qrc:/images/Main Set_List_SeparatorLine exe.png":"qrc:/images/Main Set_List_SeparatorLine nml.png";
    }

    Button{
        id:lighting;
        width: 174;
        height: 216;
        anchors.left: line2.right;
        anchors.top: airCondition.top;
        btnText: qsTr("灯光");
        normalIcon: "qrc:/images/Menu_Icon_light_nml.png";
        pressIcon:  "qrc:/images/Menu_Icon_light_exe.png";
        onClicked: onSetOptionClick(2);
    }

    Image {
        id: line3;
        width: 1;
        height: 216;
        anchors.left: lighting.right;
        anchors.top: parent.top;
        anchors.topMargin: 269
        source: chirismus.focus | lighting.focus ? "qrc:/images/Main Set_List_SeparatorLine exe.png":"qrc:/images/Main Set_List_SeparatorLine nml.png";
    }

    Button{
        id:chirismus;
        width: 174;
        height: 216;
        anchors.left: line3.right;
        anchors.top: airCondition.top;
        btnText: qsTr("按摩");
        normalIcon: "qrc:/images/Menu_Icon_massage_nml.png";
        pressIcon:  "qrc:/images/Menu_Icon_massage_exe.png";
        onClicked: onSetOptionClick(3);
    }

    Image {
        id: line4;
        width: 1;
        height: 216;
        anchors.left: chirismus.right;
        anchors.top: parent.top;
        anchors.topMargin: 269
        source: chirismus.focus | chairSetting.focus ? "qrc:/images/Main Set_List_SeparatorLine exe.png":"qrc:/images/Main Set_List_SeparatorLine nml.png";
    }

    Button{
        id:chairSetting;
        width: 174;
        height: 216;
        anchors.left: line4.right;
        anchors.top: airCondition.top;
        btnText: qsTr("靠背");
        normalIcon: "qrc:/images/Menu_Icon_lazyback_nml.png";
        pressIcon:  "qrc:/images/Menu_Icon_lazyback_exe.png";
        onClicked: onSetOptionClick(4);
    }

    Image {
        id: line5;
        width: 1;
        height: 216;
        anchors.left: chairSetting.right;
        anchors.top: parent.top;
        anchors.topMargin: 269
        source: hotBtn.focus | chairSetting.focus ? "qrc:/images/Main Set_List_SeparatorLine exe.png":"qrc:/images/Main Set_List_SeparatorLine nml.png";
    }


    Button{
        id:hotBtn;
        width: 174;
        height: 216;
        anchors.left: line5.right;
        anchors.top: airCondition.top;
        btnText: qsTr("通风加热");
        normalIcon: "qrc:/images/Menu_Icon_hot_nml.png";
        pressIcon:  "qrc:/images/Menu_Icon_hot_exe.png"
        onClicked: onSetOptionClick(5);
    }

    Image {
        id: line6;
        width: 1;
        height: 216;
        anchors.left: hotBtn.right;
        anchors.top: parent.top;
        anchors.topMargin: 269
        source: hotBtn.focus | skylight.focus ? "qrc:/images/Main Set_List_SeparatorLine exe.png":"qrc:/images/Main Set_List_SeparatorLine nml.png";
    }

    Button{
        id:skylight;
        width: 174;
        height: 216;
        anchors.left: line6.right;
        anchors.top: airCondition.top;
        btnText: qsTr("星空顶棚");
        normalIcon: "qrc:/images/Menu_Icon_skylight_nml.png";
        pressIcon:  "qrc:/images/Menu_Icon_skylight_exe.png"
        onClicked: onSetOptionClick(6);
    }

    Image {
        id: line7;
        width: 1;
        height: 216;
        anchors.left: skylight.right;
        anchors.top: parent.top;
        anchors.topMargin: 269
        source: skylight.focus ? "qrc:/images/Main Set_List_SeparatorLine exe.png":"qrc:/images/Main Set_List_SeparatorLine nml.png";
    }

    Image {
        id:separatorLine;
        width: 1280;
        height: 1;
        anchors.top: skylight.bottom;
        anchors.left: parent.left;
        source: "qrc:/images/Main Set_List_SeparatorLine.png";
    }


    // +++++++ 第二栏 ++++++++
    Image {
        id: line8;
        width: 1;
        height: 216;
        anchors.left: parent.left;
        anchors.leftMargin: 114;
        anchors.top: separatorLine.bottom;
        source: cold.focus?"qrc:/images/Main Set_List_SeparatorLine exe.png":"qrc:/images/Main Set_List_SeparatorLine nml.png";
    }

    Button{
        id:cold;
        width: 174;
        height: 216;
        anchors.left: line8.right;
        anchors.top: separatorLine.bottom;
        btnText: qsTr("冷暖箱");
        normalIcon: "qrc:/images/Menu_Icon_cold_nml.png";
        pressIcon:  "qrc:/images/Menu_Icon_cold_exe.png"
        onClicked: onSetOptionClick(7);
    }

    Image {
        id: line9;
        width: 1;
        height: 216;
        anchors.left: cold.right;
        anchors.top: separatorLine.bottom;
        source: cold.focus | lightback.focus ? "qrc:/images/Main Set_List_SeparatorLine exe.png":"qrc:/images/Main Set_List_SeparatorLine nml.png";
    }

    Button{
        id:lightback;
        width: 174;
        height: 216;
        anchors.left: line9.right;
        anchors.top: cold.top;
        btnText: qsTr("背景光");
        normalIcon: "qrc:/images/Menu_Icon_lightback_nml.png";
        pressIcon:  "qrc:/images/Menu_Icon_lightback_exe.png";
        onClicked: onSetOptionClick(8);
    }

    Image {
        id: line10;
        width: 1;
        height: 216;
        anchors.left: lightback.right;
        anchors.top: separatorLine.bottom;
        source: effects.focus | lightback.focus ? "qrc:/images/Main Set_List_SeparatorLine exe.png":"qrc:/images/Main Set_List_SeparatorLine nml.png";
    }


    Button{
        id:effects;
        width: 174;
        height: 216;
        anchors.left: line10.right;
        anchors.top: cold.top;
        btnText: qsTr("音效");
        normalIcon: "qrc:/images/Set_Effects_nml.png";
        pressIcon:  "qrc:/images/Set_Effects_exe.png";
        onClicked: onSetOptionClick(9);
    }

    Image {
        id: line11;
        width: 1;
        height: 216;
        anchors.left: effects.right;
        anchors.top: separatorLine.bottom;
        source: effects.focus | follow.focus ? "qrc:/images/Main Set_List_SeparatorLine exe.png":"qrc:/images/Main Set_List_SeparatorLine nml.png";
    }

    Button{
        id:follow;
        width: 174;
        height: 216;
        anchors.left: line11.right;
        anchors.top: cold.top;
        btnText: qsTr("车辆随速");
        normalIcon: "qrc:/images/Menu_Icon_follow_nml.png";
        pressIcon:  "qrc:/images/Menu_Icon_follow_exe.png";
        onClicked: onSetOptionClick(10);
    }

    Image {
        id: line12;
        width: 1;
        height: 216;
        anchors.left: follow.right;
        anchors.top: separatorLine.bottom;
        source: curtainback.focus | follow.focus ? "qrc:/images/Main Set_List_SeparatorLine exe.png":"qrc:/images/Main Set_List_SeparatorLine nml.png";
    }


    Button{
        id:curtainback;
        width: 174;
        height: 216;
        anchors.left: line12.right;
        anchors.top: cold.top;
        btnText: qsTr("后帘窗");
        normalIcon: "qrc:/images/Set_curtainback_nml.png";
        pressIcon:  "qrc:/images/Set_curtainback_exe.png";
        onClicked: onSetOptionClick(11);
    }

    Image {
        id: line13;
        width: 1;
        height: 216;
        anchors.left: curtainback.right;
        anchors.top: separatorLine.bottom;
        source: curtainback.focus | help.focus ? "qrc:/images/Main Set_List_SeparatorLine exe.png":"qrc:/images/Main Set_List_SeparatorLine nml.png";
    }

    Button{
        id:help;
        width: 174;
        height: 216;
        anchors.left: line13.right;
        anchors.top: cold.top;
        btnText: qsTr("帮助");
        normalIcon: "qrc:/images/Menu_Icon_help_nml.png";
        pressIcon:  "qrc:/images/Menu_Icon_help_exe.png"
        onClicked: onSetOptionClick(12);
    }

    Image {
        id: line14;
        width: 1;
        height: 216;
        anchors.left: help.right;
        anchors.top: separatorLine.bottom;
        source: help.focus ? "qrc:/images/Main Set_List_SeparatorLine exe.png":"qrc:/images/Main Set_List_SeparatorLine nml.png";
    }

    function onSetOptionClick(index)
    {
        c_qmlInterface.qmlDebug("[ SetOption.qml ]onAirConditionButtonClicked", index);
        sigSetOptionClicked(index);
    }


}
