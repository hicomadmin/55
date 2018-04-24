import QtQuick 2.3

Item {
    anchors.fill: parent;
    property real driverTmp: 27.5;
    property real driverSideTmp: 27.5;
    property int  windSpeedText: 7;


    BaseButton {
        id:off;
        width: 194; height: 102;
        anchors{left: parent.left; leftMargin: 460;}
        anchors{top: parent.top; topMargin: 54;}
        normalSource: "qrc:/images/air/AC_Icon_powerd_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_powerd_exe.png"
        Image {
            width: 176; height: 84;
            anchors{left: parent.left; verticalCenter: parent.verticalCenter;}
            source: "qrc:/images/air/AC_Icon_power_nml.png"
        }
        BaseText{
            anchors{left: parent.left; leftMargin: 96;}
            anchors{top: parent.top; topMargin: 40;}
            size: 27;
            text: qsTr("关机");
        }
    }

    BaseButton {
        id:autoTmp;
        width: 194;  height: 102;
        anchors{left: off.left; leftMargin: 191; top: off.top;}
        normalSource: "qrc:/images/air/AC_Icon_powerd_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_powerd_exe.png"
        Image {
            width: 176; height: 84;
            anchors{left: parent.left; leftMargin: 15; verticalCenter: parent.verticalCenter;}
            source: "qrc:/images/air/AC_Icon_auhw_nml.png"
        }
        BaseText{
            anchors{left: parent.left;leftMargin: 70; top: parent.top; topMargin: 40;}
            size: 27;
            text: qsTr("自动恒温");
        }
    }

    BaseButton {
        id:doubleZone;
        width: 194;  height: 102;
        anchors{left: autoTmp.left; leftMargin: 191; top: off.top;}
        normalSource: "qrc:/images/air/AC_Icon_powerd_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_powerd_exe.png"
        Image {
            width: 176; height: 84;
            anchors{left: parent.left; leftMargin: 15; verticalCenter: parent.verticalCenter;}
            source: "qrc:/images/air/AC_Icon_seq_nml.png"
        }
        BaseText{
            anchors{left: parent.left; leftMargin: 85;}
            anchors{top: parent.top; topMargin: 40;}
            size: 27;
            text: qsTr("双温区");
        }
    }

    BaseButton {
        id:air_B;
        width: 194; height: 102;
        anchors{left: doubleZone.left; leftMargin: 191; top: off.top;}
        normalSource: "qrc:/images/air/AC_Icon_powerd_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_powerd_exe.png"
        Image {
            width: 176; height: 84;
            anchors{left: parent.left; leftMargin: 15; verticalCenter: parent.verticalCenter;}
            source: "qrc:/images/air/AC_Icon_seq_nml.png"
        }
        BaseText{
            anchors{left: parent.left; leftMargin: 85; top: parent.top; topMargin: 40;}
            size: 27;
            text: qsTr("后空调");
        }
    }


    BaseButton{
        id:driverAdd
        width: 110; height: 110;
        anchors{left: parent.left; leftMargin: 581;}
        anchors{top: off.bottom; topMargin: 9;}
        normalSource: "qrc:/images/AC_Tem_leftAdd_nml.png";
        pressSource:  "qrc:/images/AC_Tem_leftAdd_exe.png"
        onClicked: onAdjustmentBtnClicked(10);
    }

    BaseText {
        anchors{top: driverAdd.bottom; topMargin: 5;}
        anchors.horizontalCenter: driverAdd.horizontalCenter;
        font.pixelSize: 60;
        text: driverTmp
        BaseText {
            anchors{left: parent.right; top: parent.top;}
            font.pixelSize: 30;
            text: "℃"
        }
    }

    BaseButton{
        id:driverSub
        width: 110; height: 110;
        anchors{left: driverAdd.left; top: driverAdd.bottom; topMargin: 81;}
        normalSource: "qrc:/images/AC_Tem_leftSub_nml.png";
        pressSource:  "qrc:/images/AC_Tem_leftSub_exe.png"
        onClicked: onAdjustmentBtnClicked(11);
    }



    BaseButton{
        id:windSpeedAdd
        width: 110; height: 110;
        anchors{left: driverAdd.right; leftMargin: 99; top: driverAdd.top;}
        normalSource: "qrc:/images/AC_Tem_leftAdd_nml.png";
        pressSource:  "qrc:/images/AC_Tem_leftAdd_exe.png"
        onClicked: onAdjustmentBtnClicked(20);
    }

    BaseText {
        anchors{top: windSpeedAdd.bottom; topMargin: 5;}
        anchors.horizontalCenter: windSpeedAdd.horizontalCenter
        font.pixelSize: 60;
        text: windSpeedText
    }

    BaseButton{
        id:windSpeedSub
        width: 110; height: 110;
        anchors{left: windSpeedAdd.left; top: windSpeedAdd.bottom; topMargin: 81;}
        normalSource: "qrc:/images/AC_Tem_leftSub_nml.png";
        pressSource:  "qrc:/images/AC_Tem_leftSub_exe.png"
        onClicked: onAdjustmentBtnClicked(21);
    }



    BaseButton{
        id:copilotAdd
        width: 110; height: 110;
        anchors{left: windSpeedAdd.right; leftMargin: 99; top: driverAdd.top;}
        normalSource: "qrc:/images/AC_Tem_leftAdd_nml.png";
        pressSource:  "qrc:/images/AC_Tem_leftAdd_exe.png"
        onClicked: onAdjustmentBtnClicked(30);
    }

    BaseText {
        anchors{top: driverAdd.bottom; topMargin: 5;}
        anchors.horizontalCenter: copilotAdd.horizontalCenter
        font.pixelSize: 60;
        text: driverSideTmp
        BaseText {
            anchors{left: parent.right; top: parent.top;}
            font.pixelSize: 30;
            text: "℃"
        }
    }

    BaseButton{
        id:copilotSub
        width: 110; height: 110;
        anchors{left: copilotAdd.left; top: copilotAdd.bottom; topMargin: 81;}
        normalSource: "qrc:/images/AC_Tem_leftSub_nml.png";
        pressSource:  "qrc:/images/AC_Tem_leftSub_exe.png"
        onClicked: onAdjustmentBtnClicked(31);
    }

    BaseButton{
        id:qcsIcon
        width: 72; height: 46;
        anchors{left: parent.left; leftMargin: 495;}
        anchors{top: copilotSub.bottom; topMargin: 56;}
        normalSource: "qrc:/images/air/AC_Icon_qcs_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_qcs_exe.png"
    }

    BaseButton{
        id:cmIcon
        width: 72; height: 46;
        anchors{left: qcsIcon.right; leftMargin: 55; top: qcsIcon.top;}
        normalSource: "qrc:/images/air/AC_Icon_cm_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_cm_exe.png"
    }

    BaseButton{
        id:cjIcon
        width: 72; height: 46;
        anchors{left: cmIcon.right; leftMargin: 55; top: qcsIcon.top;}
        normalSource: "qrc:/images/air/AC_Icon_cj_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_cj_exe.png"
    }

    BaseButton{
        id:cmjIcon
        width: 72; height: 46;
        anchors{left: cjIcon.right; leftMargin: 55; top: qcsIcon.top;}
        normalSource: "qrc:/images/air/AC_Icon_cmj_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_cmj_exe.png"
    }

    BaseButton{
        id:cjchIcon
        width: 72; height: 46;
        anchors{left: cmjIcon.right; leftMargin: 55; top: qcsIcon.top;}
        normalSource: "qrc:/images/air/AC_Icon_cjch_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_cjch_exe.png"
    }

    BaseButton{
        width: 72; height: 46;
        anchors{left: cjchIcon.right; leftMargin: 55; top: qcsIcon.top;}
        normalSource: "qrc:/images/air/AC_Icon_hcc_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_hcc_exe.png"
    }




    ////
    BaseButton{
        id:acIcon
        width: 72; height: 46;
        anchors{left: qcsIcon.left; top: qcsIcon.bottom; topMargin: 48;}
        normalSource: "qrc:/images/air/AC_Icon_ac_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_ac_exe.png"
    }

    BaseButton{
        width: 72; height: 46;
        anchors{left: qcsIcon.right; leftMargin: 55; top: acIcon.top;}
        normalSource: "qrc:/images/air/AC_Icon_nxh_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_nxh_exe.png"
    }

    BaseButton{
        width: 72; height: 46;
        anchors{left: cmIcon.right;leftMargin: 55;top: acIcon.top;}
        normalSource: "qrc:/images/air/AC_Icon_wxh_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_wxh_exe.png"
    }

    BaseButton{
        width: 72; height: 46;
        anchors{left: cjIcon.right; leftMargin: 55; top: acIcon.top;}
        normalSource: "qrc:/images/air/AC_Icon_chj_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_chj_exe.png"
    }

    BaseButton{
        width: 72; height: 46;
        anchors{left: cmjIcon.right; leftMargin: 55; top: acIcon.top;}
        normalSource: "qrc:/images/air/AC_Icon_dlz_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_dlz_exe.png"
    }

    BaseButton{
        width: 72; height: 46;
        anchors{left: cjchIcon.right;leftMargin: 55; top: acIcon.top;}
        normalSource: "qrc:/images/air/AC_Icon_flz_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_flz_exe.png"
    }


    function onAdjustmentBtnClicked(val)
    {
        var tmp;
        switch(val)
        {
        case 10:
            driverTmp += 0.5;
            break;
        case 11:
            driverTmp -= 0.5;
            break;
        case 20:
            tmp = windSpeedText +1;
            windSpeedText = tmp;
            break;
        case 21:
            if(windSpeedText>1){
                tmp = windSpeedText -1;
                windSpeedText = tmp;
            }
            break;
        case 30:
            driverSideTmp += 0.5;
            break;
        case 31:
            driverSideTmp -= 0.5;
            break;
        default:
            break;
        }
    }


}
