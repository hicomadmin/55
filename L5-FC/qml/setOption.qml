/*************************************************
Copyright: Shenzhen Hangsheng Electronics CO.,LTD.
Author:
Date: 2018-03-13
Description: 设置选项按键界面
**************************************************/
import QtQuick 2.3

Item {
    signal sigSetOptionClicked(int index);

    Button{
        id:airCondition;
        width: 720;
        height: 100;
        anchors.left: parent.left;
        btnText: qsTr("空调");
        normalIcon: "qrc:/images/Menu_Icon_AC_nml.png";
        pressIcon:  "qrc:/images/Menu_Icon_AC_exe.png";
        onClicked: onSetOptionBtnClicked(1);
    }

    Button{
        id:rearviewMirror;
        width: 720;
        height: 100;
        anchors.left: airCondition.left;
        anchors.top: airCondition.bottom;
        btnText: qsTr("外后视镜");
        normalIcon: "qrc:/images/Menu_Icon_rearviewMirror_nml.png";
        pressIcon:  "qrc:/images/Menu_Icon_rearviewMirror_exe.png"
        onClicked: onSetOptionBtnClicked(2);
    }

    Button{
        id:chairSetting;
        width: 720;
        height: 100;
        anchors.left: airCondition.left;
        anchors.top: rearviewMirror.bottom;
        btnText: qsTr("座椅设置");
        normalIcon: "qrc:/images/Menu_Icon_chairSetting_nml.png";
        pressIcon:  "qrc:/images/Menu_Icon_chairSetting_exe.png";
        onClicked: onSetOptionBtnClicked(3);
    }

    Button{
        id:lighting;
        width: 720;
        height: 100;
        anchors.left: airCondition.left;
        anchors.top: chairSetting.bottom;
        btnText: qsTr("灯光");
        normalIcon: "qrc:/images/Menu_Icon_light_nml.png";
        pressIcon:  "qrc:/images/Menu_Icon_light_exe.png"
        onClicked: onSetOptionBtnClicked(4);
    }

    Button{
        id:auxiliaryDriving;
        width: 720;
        height: 100;
        anchors.left: airCondition.left;
        anchors.top: lighting.bottom;
        btnText: qsTr("设置");
        normalIcon: "qrc:/images/Menu_Icon_setting_nml.png";
        pressIcon:  "qrc:/images/Menu_Icon_setting_exe.png";
//        normalIcon: "qrc:/images/Menu_Icon_auxiliaryDriving_exe.png";
//        pressIcon:  "qrc:/images/Menu_Icon_auxiliaryDriving_nml.png";
        onClicked: onSetOptionBtnClicked(5);
    }

    Button{
        id:forwardReversingRadar;
        width: 720;
        height: 100;
        anchors.left: airCondition.left;
        anchors.top: auxiliaryDriving.bottom;
        btnText: qsTr("泊车雷达");
        normalIcon: "qrc:/images/Menu_Icon_Radar_nml.png";
        pressIcon:  "qrc:/images/Menu_Icon_Radar_exe.png";
        onClicked: onSetOptionBtnClicked(6);
    }



    function onSetOptionBtnClicked(index)
    {
        sigSetOptionClicked(index);
    }


}
