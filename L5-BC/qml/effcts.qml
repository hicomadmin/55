/*************************************************
Copyright: Shenzhen Hangsheng Electronics CO.,LTD.
Author:
Date: 2018-03-13
Description: 静音提示框
**************************************************/
import QtQuick 2.3

Item {
    anchors.fill: parent
    property int fontSize: 54;


    BaseText{
        id:lowHint
        anchors.top: parent.top;
        anchors.topMargin: 304;
        anchors.left: parent.left;
        anchors.leftMargin: 106;
        text: qsTr("低音调节");
    }
    BaseText{
        id:leftRightBalanceHint
        anchors.top: lowHint.top;
        anchors.left: lowHint.right;
        anchors.leftMargin: 257;
        text: qsTr("左右平衡");
    }
    BaseText{
        anchors.top: lowHint.top;
        anchors.left: leftRightBalanceHint.right;
        anchors.leftMargin: 258;
        text: qsTr("前后平衡");
    }
    BaseText{
        id: sopranoHint
        anchors.top: low1.bottom;
        anchors.topMargin: 48;
        anchors.left: lowHint.left;
        text: qsTr("高音调节");
    }
    BaseText{
        anchors.top: low1.bottom;
        anchors.topMargin: 48;
        anchors.left: sopranoHint.right;
        anchors.leftMargin: 256;
        text: qsTr("车辆随速音量");
    }

    BaseButton{
        id: low1;
        width: 110;
        height: 110;
        anchors.top: parent.top;
        anchors.topMargin: 352
        anchors.left: parent.left;
        anchors.leftMargin: 94;
        normalSource: "qrc:/images/effects/AC_Tem_leftAdd_nml.png"
        pressSource:  "qrc:/images/effects/AC_Tem_leftAdd_exe.png"
        onClicked: {
        }
    }
    BaseText{
        id: lowTXT
        anchors.verticalCenter: low1.verticalCenter;
        anchors.left: low1.right;
        anchors.leftMargin: 25;
        font.pixelSize: fontSize;
        text: "00";
    }
    BaseButton{
        id: low2;
        width: 110;
        height: 110;
        anchors.top: low1.top;
        anchors.left: low1.right;
        anchors.leftMargin: 106;
        normalSource: "qrc:/images/effects/AC_Tem_leftSub_nml.png"
        pressSource:  "qrc:/images/effects/AC_Tem_leftSub_exe.png"
        onClicked: {

        }
    }

    BaseButton{
        id: balance1;
        width: 110;
        height: 110;
        anchors.top: low1.top;
        anchors.left: low2.right;
        anchors.leftMargin: 56;
        normalSource: "qrc:/images/effects/AC_Tem_leftAdd_nml.png"
        pressSource:  "qrc:/images/effects/AC_Tem_leftAdd_exe.png"
    }
    Text {
        id:leftRightBalanceTXT;
        anchors.verticalCenter: low1.verticalCenter;
        anchors.left: balance1.right;
        anchors.leftMargin: 25;
        font.pixelSize: fontSize;
        color: "#ffffff";
        text: "00";
    }
    BaseButton{
        id: balance2;
        width: 110;
        height: 110;
        anchors.top: low1.top;
        anchors.left: balance1.right;
        anchors.leftMargin: 106;
        normalSource: "qrc:/images/effects/AC_Tem_leftSub_nml.png"
        pressSource:  "qrc:/images/effects/AC_Tem_leftSub_exe.png"
    }


    BaseButton{
        id: around1;
        width: 110;
        height: 110;
        anchors.top: low1.top;
        anchors.left: balance2.right;
        anchors.leftMargin: 56;
        normalSource: "qrc:/images/effects/AC_Tem_leftAdd_nml.png"
        pressSource:  "qrc:/images/effects/AC_Tem_leftAdd_exe.png"
    }
    Text {
        id:aroundBalanceTXT;
        anchors.verticalCenter: low1.verticalCenter;
        anchors.left: around1.right;
        anchors.leftMargin: 25;
        font.pixelSize: fontSize;
        color: "#ffffff";
        text: "00";
    }
    BaseButton{
        id: around2;
        width: 110;
        height: 110;
        anchors.top: low1.top;
        anchors.left: around1.right;
        anchors.leftMargin: 106;
        normalSource: "qrc:/images/effects/AC_Tem_leftSub_nml.png"
        pressSource:  "qrc:/images/effects/AC_Tem_leftSub_exe.png"
    }


    BaseButton{
        id:  highPitch1;
        width: 110;
        height: 110;
        anchors.top: low1.bottom;
        anchors.topMargin: 96;
        anchors.left: low1.left;
        normalSource: "qrc:/images/effects/AC_Tem_leftAdd_nml.png"
        pressSource:  "qrc:/images/effects/AC_Tem_leftAdd_exe.png"
    }
    Text {
        id:highPitchTXT;
        anchors.verticalCenter: highPitch1.verticalCenter;
        anchors.left: highPitch1.right;
        anchors.leftMargin: 25;
        font.pixelSize: fontSize;
        color: "#ffffff";
        text: "00";
    }
    BaseButton{
        id: highPitch2;
        width: 110;
        height: 110;
        anchors.top: highPitch1.top;
        anchors.left: highPitch1.right;
        anchors.leftMargin: 106;
        normalSource: "qrc:/images/effects/AC_Tem_leftSub_nml.png"
        pressSource:  "qrc:/images/effects/AC_Tem_leftSub_exe.png"
    }



    MenuButton{
        id: withSpeed;
        width: 171;
        height: 110;
        anchors.top: highPitch1.top;
        anchors.left: parent.left;
        anchors.leftMargin: 477;
        btnText: qsTr("关闭");
        topMag: 40;
        normalSource: "qrc:/images/effects/Set_Effects_nml.png"
        pressSource:  "qrc:/images/effects/Set_Effects_exe.png"
    }

    MenuButton{
        id: lowBtn;
        width: 171;
        height: 110;
        anchors.top: withSpeed.top;
        anchors.left: withSpeed.right;
        anchors.leftMargin: 8;
        btnText: qsTr("低");
        topMag: 40;
        normalSource: "qrc:/images/effects/Set_Effects_nml.png"
        pressSource:  "qrc:/images/effects/Set_Effects_exe.png"
    }

    MenuButton{
        id: middleBtn;
        width: 171;
        height: 110;
        anchors.top: withSpeed.top;
        anchors.left: lowBtn.right;
        anchors.leftMargin: 8;
        btnText: qsTr("中");
        topMag: 40;
        normalSource: "qrc:/images/effects/Set_Effects_nml.png"
        pressSource:  "qrc:/images/effects/Set_Effects_exe.png"
    }

    MenuButton{
        id: hightBtn;
        width: 171;
        height: 110;
        anchors.top: withSpeed.top;
        anchors.left: middleBtn.right;
        anchors.leftMargin: 8;
        btnText: qsTr("高");
        topMag: 40;
        normalSource: "qrc:/images/effects/Set_Effects_nml.png"
        pressSource:  "qrc:/images/effects/Set_Effects_exe.png"
    }


}
