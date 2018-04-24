import QtQuick 2.3

Item {
    anchors.fill: parent;
    signal sigHelpPageBack();

    Rectangle{
        anchors.fill: parent;
        color: "#000000";
    }

    Image {
        id: line1;
        width: 520; height: 1;
        anchors{left: parent.left; leftMargin: 60; top: parent.top; topMargin: 63;}
        source: homeHelpBtn.focus?"qrc:/images/help/Set_List_SeparatorLine_exe.png":"qrc:/images/help/Set_List_SeparatorLine_nml.png";
    }


    HelpButton{
        id:homeHelpBtn;
        width: 520; height: 98;
        anchors{top: line1.bottom; left: line1.left;}
        btnText: qsTr("主界面功能说明");
        optionIcon: "qrc:/images/help/Set_Icon_1.png";
        normalIcon: "qrc:/images/help/Set_Icon_bg_nml.png";
        pressIcon:  "qrc:/images/help/Set_Icon_bg_exe.png"
        //onClicked: onSetOptionClick(5);
    }

    Image {
        id: line2;
        width: 520;height: 1;
        anchors{left: line1.left; top: homeHelpBtn.bottom;}
        source: homeHelpBtn.focus | mediaHelpBtn.focus?"qrc:/images/help/Set_List_SeparatorLine_exe.png":"qrc:/images/help/Set_List_SeparatorLine_nml.png";
    }

    HelpButton{
        id:mediaHelpBtn;
        width: 520;
        height: 98;
        anchors{top: line2.bottom; left: line1.left;}
        btnText: qsTr("娱乐功能操作说明");
        optionIcon: "qrc:/images/help/Set_Icon_3.png";
        normalIcon: "qrc:/images/help/Set_Icon_bg_nml.png";
        pressIcon:  "qrc:/images/help/Set_Icon_bg_exe.png"
        //onClicked: onSetOptionClick(5);
    }

    Image {
        id: line3;
        width: 520;height: 1;
        anchors{left: line1.left; top: mediaHelpBtn.bottom;}
        source: ariHelpBtn.focus | mediaHelpBtn.focus?"qrc:/images/help/Set_List_SeparatorLine_exe.png":"qrc:/images/help/Set_List_SeparatorLine_nml.png";
    }

    HelpButton{
        id:ariHelpBtn;
        width: 520;  height: 98;
        anchors{top: line3.bottom; left: line1.left;}
        btnText: qsTr("空调操作说明");
        optionIcon: "qrc:/images/help/Set_Icon_8.png";
        normalIcon: "qrc:/images/help/Set_Icon_bg_nml.png";
        pressIcon:  "qrc:/images/help/Set_Icon_bg_exe.png"
        //onClicked: onSetOptionClick(5);
    }

    Image {
        id: line4;
        width: 520;height: 1;
        anchors.left: line1.left;
        anchors.top: ariHelpBtn.bottom;
        source: ariHelpBtn.focus | lightHelpBtn.focus?"qrc:/images/help/Set_List_SeparatorLine_exe.png":"qrc:/images/help/Set_List_SeparatorLine_nml.png";
    }

    HelpButton{
        id:lightHelpBtn;
        width: 520;  height: 98;
        anchors{top: line4.bottom; left: line1.left;}
        btnText: qsTr("灯光操作说明");
        optionIcon: "qrc:/images/help/Set_Icon_4.png";
        normalIcon: "qrc:/images/help/Set_Icon_bg_nml.png";
        pressIcon:  "qrc:/images/help/Set_Icon_bg_exe.png"
        //onClicked: onSetOptionClick(5);
    }

    Image {
        id: line5;
        width: 520;height: 1;
        anchors.left: line1.left;
        anchors.top: lightHelpBtn.bottom;
        source: curtainsHelpBtn.focus | lightHelpBtn.focus?"qrc:/images/help/Set_List_SeparatorLine_exe.png":"qrc:/images/help/Set_List_SeparatorLine_nml.png";
    }

    HelpButton{
        id:curtainsHelpBtn;
        width: 520;  height: 98;
        anchors{top: line5.bottom; left: line1.left;}
        btnText: qsTr("后窗帘说明");
        optionIcon: "qrc:/images/help/Set_Icon_6.png";
        normalIcon: "qrc:/images/help/Set_Icon_bg_nml.png";
        pressIcon:  "qrc:/images/help/Set_Icon_bg_exe.png"
        //onClicked: onSetOptionClick(5);
    }

    Image {
        id: line6;
        width: 520;height: 1;
        anchors.left: line1.left;
        anchors.top: curtainsHelpBtn.bottom;
        source: curtainsHelpBtn.focus | coldWarmHelpBtn.focus?"qrc:/images/help/Set_List_SeparatorLine_exe.png":"qrc:/images/help/Set_List_SeparatorLine_nml.png";
    }

    HelpButton{
        id:coldWarmHelpBtn;
        width: 520;  height: 98;
        anchors{top: line6.bottom; left: line1.left;}
        btnText: qsTr("冷暖箱操作说明");
        optionIcon: "qrc:/images/help/Set_Icon_7.png";
        normalIcon: "qrc:/images/help/Set_Icon_bg_nml.png";
        pressIcon:  "qrc:/images/help/Set_Icon_bg_exe.png"
        //onClicked: onSetOptionClick(5);
    }
    Image {
        width: 520;height: 1;
        anchors.left: line1.left;
        anchors.top: coldWarmHelpBtn.bottom;
        source: coldWarmHelpBtn.focus?"qrc:/images/help/Set_List_SeparatorLine_exe.png":"qrc:/images/help/Set_List_SeparatorLine_nml.png";
    }


    //第二列
    Image {
        id: line7;
        width: 520;height: 1;
        anchors.left: homeHelpBtn.right;
        anchors.leftMargin: 120;
        anchors.top: homeHelpBtn.top;
        source: bgLightHelpBtn.focus?"qrc:/images/help/Set_List_SeparatorLine_exe.png":"qrc:/images/help/Set_List_SeparatorLine_nml.png";
    }

    HelpButton{
        id:bgLightHelpBtn;
        width: 520;  height: 98;
        anchors{top: line7.bottom; left: line7.left;}
        btnText: qsTr("背景光调节说明");
        optionIcon: "qrc:/images/help/Set_Icon_2.png";
        normalIcon: "qrc:/images/help/Set_Icon_bg_nml.png";
        pressIcon:  "qrc:/images/help/Set_Icon_bg_exe.png"
        //onClicked: onSetOptionClick(5);
    }

    Image {
        id: line8;
        width: 520;height: 1;
        anchors.left: line7.left;
        anchors.top: bgLightHelpBtn.bottom;
        source: bgLightHelpBtn.focus | effetsHelpBtn.focus?"qrc:/images/help/Set_List_SeparatorLine_exe.png":"qrc:/images/help/Set_List_SeparatorLine_nml.png";
    }

    HelpButton{
        id:effetsHelpBtn;
        width: 520;  height: 98;
        anchors{top: line8.bottom; left: line7.left;}
        btnText: qsTr("音效调节说明");
        optionIcon: "qrc:/images/help/Set_Icon_5.png";
        normalIcon: "qrc:/images/help/Set_Icon_bg_nml.png";
        pressIcon:  "qrc:/images/help/Set_Icon_bg_exe.png"
        //onClicked: onSetOptionClick(5);
    }
    Image {
        width: 520;height: 1;
        anchors.left: line7.left;
        anchors.top: effetsHelpBtn.bottom;
        source: effetsHelpBtn.focus?"qrc:/images/help/Set_List_SeparatorLine_exe.png":"qrc:/images/help/Set_List_SeparatorLine_nml.png";
    }




    BaseButton{
        id: backBtn
        width: 171;  height: 110;
        anchors.right: parent.right;
        anchors.rightMargin: 48;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 52;
        btnText: qsTr("返回");
        normalSource: "qrc:/images/effects/Set_Effects_nml.png";
        pressSource:  "qrc:/images/effects/Set_Effects_exe.png";
        onClicked: sigHelpPageBack();
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
