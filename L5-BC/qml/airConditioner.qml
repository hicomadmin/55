import QtQuick 2.3

Item {
    id: airpage;
    anchors.fill: parent;
    property real driverTmp: 20.5;
    property real driverSideTmp: 20.5;
    property int  windSpeedTxt: 5;

    MenuButton{
        id:driverAdd;
        width: 110; height: 110;
        anchors{top: parent.top; topMargin: 306;}
        anchors{left: parent.left; leftMargin: 147;}
        normalSource: "qrc:/images/effects/AC_Tem_leftAdd_nml.png";
        pressSource:  "qrc:/images/effects/AC_Tem_leftAdd_exe.png";
        onClicked: onAdjustmentBtnClicked(10);
    }
    BaseText {
        anchors{top: driverAdd.bottom; topMargin: 40;}
        anchors.horizontalCenter: driverAdd.horizontalCenter;
        font.pixelSize: 60;
        text: driverTmp
        BaseText {
            anchors{left: parent.right; top: parent.top;}
            font.pixelSize: 30;
            text: "℃"
        }
    }

    MenuButton{
        id:driverSub;
        width: 110; height: 110;
        anchors{top: driverAdd.bottom; topMargin: 142; left: driverAdd.left;}
        normalSource: "qrc:/images/effects/AC_Tem_leftSub_nml.png";
        pressSource:  "qrc:/images/effects/AC_Tem_leftSub_exe.png";
        onClicked: onAdjustmentBtnClicked(11);
    }

    MenuButton{
        id:auto;
        width: 286; height: 110;
        anchors{top: driverAdd.top; left: parent.left; leftMargin: 322;}
        normalSource: "qrc:/images/air/AC_Tem_auto_nml.png";
        pressSource:  "qrc:/images/air/AC_Tem_auto_exe.png";
        //onClicked: auto.pressSource = "qrc:/images/air/AC_Tem_auto_dec.png";
        BaseText{
            anchors{left: parent.left;leftMargin: 110; top: parent.top; topMargin: 40;}
            size: 27;
            text: qsTr("自动恒温");
        }

    }


    MenuButton{
        id:doubleZone;
        width: 286;  height: 110;
        anchors{top: driverAdd.top; left: parent.left; leftMargin: 672;}
        normalSource: "qrc:/images/air/AC_Tem_dub_nml.png";
        pressSource:  "qrc:/images/air/AC_Tem_dub_exe.png";
        //onClicked: onMuteBtnClicked(2);
        BaseText{
            anchors{left: parent.left; leftMargin: 130;}
            anchors{top: parent.top; topMargin: 40;}
            size: 27;
            text: qsTr("双温区");
        }
    }


    MenuButton{
        id:windSpeedSub;
        width: 110; height: 110;
        anchors{top: doubleZone.bottom; topMargin: 16;}
        anchors{left: parent.left; leftMargin: 410;}
        normalSource: "qrc:/images/effects/AC_Tem_leftSub_nml.png";
        pressSource:  "qrc:/images/effects/AC_Tem_leftSub_exe.png";
        onClicked: onAdjustmentBtnClicked(20);
    }


    Image {
        id: windSpeedIcn
        width: 42;
        height: 44;
        anchors{left: windSpeedSub.right; leftMargin: 71;}
        anchors{top: doubleZone.bottom; topMargin: 49;}
        source: "qrc:/images/air/AC_Scale_nml.png"

        NumberAnimation {
            running: windSpeedIcn.visible
            loops: Animation.Infinite
            target: windSpeedIcn
            from: 0
            to: -360
            property: "rotation"
            duration: 1500
        }
    }

    BaseText{
        anchors.left: windSpeedIcn.right;
        anchors.verticalCenter: windSpeedIcn.verticalCenter;
        text: windSpeedTxt
        font.pixelSize: 54
    }

    MenuButton{
        id:windSpeedAdd;
        width: 110; height: 110;
        anchors{top: windSpeedSub.top; left: windSpeedSub.right; leftMargin: 240;}
        normalSource: "qrc:/images/effects/AC_Tem_leftAdd_nml.png";
        pressSource:  "qrc:/images/effects/AC_Tem_leftAdd_exe.png";
        onClicked: onAdjustmentBtnClicked(21);
    }

    MenuButton{
        id:power;
        width: 72; height: 46;
        anchors.verticalCenter: driverSub.verticalCenter;
        anchors{left: driverSub.right; leftMargin: 41;}
        normalSource: "qrc:/images/air/AC_Icon_AC_power_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_AC_power_exe.png";
        //onClicked: onMuteBtnClicked(2);
    }

    MenuButton{
        id:ac;
        width: 72; height: 46;
        anchors.verticalCenter: driverSub.verticalCenter;
        anchors{left: power.right; leftMargin: 50;}
        normalSource: "qrc:/images/air/AC_Icon_AC_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_AC_exe.png";
        //onClicked: onMuteBtnClicked(2);
    }

    MenuButton{
        id:sterilization;
        width: 72;
        height: 46;
        anchors.verticalCenter: driverSub.verticalCenter;
        anchors{left: ac.right; leftMargin: 51;}
        normalSource: "qrc:/images/air/AC_Icon_cj_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_cj_exe.png";
        //onClicked: onMuteBtnClicked(2);
    }


    MenuButton{
        id:anion;
        width: 72; height: 46;
        anchors.verticalCenter: driverSub.verticalCenter;
        anchors{left: sterilization.right; leftMargin: 51;}
        normalSource: "qrc:/images/air/AC_Icon_flz_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_flz_exe.png";
        //onClicked: onMuteBtnClicked(2);
    }

    MenuButton{
        id:plasma;
        width: 72; height: 46;
        anchors.verticalCenter: driverSub.verticalCenter;
        anchors{left: anion.right; leftMargin: 51;}
        normalSource: "qrc:/images/air/AC_Icon_dlz_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_dlz_exe.png";
        //onClicked: onMuteBtnClicked(2);
    }

    MenuButton{
        id:windDirection;
        width: 72; height: 46;
        anchors.verticalCenter: driverSub.verticalCenter;
        anchors{left: plasma.right; leftMargin: 51;}
        normalSource: "qrc:/images/air/AC_Icon_fbdj_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_fbdj_exe.png";
        //onClicked: onMuteBtnClicked(2);
    }


    MenuButton{
        id:copilotAdd;
        width: 110; height: 110;
        anchors{top: driverAdd.top; left: windDirection.right; leftMargin: 41;}
        normalSource: "qrc:/images/effects/AC_Tem_leftAdd_nml.png";
        pressSource:  "qrc:/images/effects/AC_Tem_leftAdd_exe.png";
        onClicked: onAdjustmentBtnClicked(30);
    }

    BaseText {
        anchors{top: driverAdd.bottom; topMargin: 40;}
        anchors.horizontalCenter: copilotAdd.horizontalCenter;
        font.pixelSize: 60;
        text: driverSideTmp
        BaseText {
            anchors{left: parent.right; top: parent.top;}
            font.pixelSize: 30;
            text: "℃"
        }
    }

    MenuButton{
        id:copilotSub;
        width: 110; height: 110;
        anchors{top: driverSub.top; left: copilotAdd.left;}
        normalSource: "qrc:/images/effects/AC_Tem_leftSub_nml.png";
        pressSource:  "qrc:/images/effects/AC_Tem_leftSub_exe.png";
        onClicked: {
            onAdjustmentBtnClicked(31);
        }
    }



    function onAdjustmentBtnClicked(val)
    {
        switch(val)
        {
        case 10:
            driverTmp += 0.5;
            break;
        case 11:
            driverTmp -= 0.5;
            break;
        case 20:
            if(windSpeedTxt > 1){
                windSpeedTxt = windSpeedTxt - 1;
            }
            break;
        case 21:
            if(windSpeedTxt < 10){
                windSpeedTxt = windSpeedTxt + 1;
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
