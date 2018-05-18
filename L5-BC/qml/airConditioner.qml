import QtQuick 2.3

Item {
    id: airpage;
    anchors.fill: parent;
    property real driverTmp: 20.5;
    property real driverSideTmp: 20.5;
    property int  windSpeedTxt: 5;

    property int autoFlag: 0;
    property int doubl: 0;
    property int offFlag: 0;
    property int acFlag: 0;
    property int fulizhi: 0;
    property int denglizhi: 0;
    property int fengbaidianji: 0;

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
        onClicked: {
            if(autoFlag === 0){
                c_qmlInterface.sendRccCAN('4-0-0-16-2-0-0');
                autoFlag = 1;
            }else{
                c_qmlInterface.sendRccCAN('4-0-0-0-2-0-0');
                autoFlag = 0;
            }
        }
    }


    MenuButton{
        id:doubleZone;
        width: 286;  height: 110;
        anchors{top: driverAdd.top; left: parent.left; leftMargin: 672;}
        normalSource: "qrc:/images/air/AC_Tem_dub_nml.png";
        pressSource:  "qrc:/images/air/AC_Tem_dub_exe.png";

        Image {
            x:113;
            y:12;
            source: "qrc:/images/air/AC_Icon_powerd_dec.png.png"
        }
        //onClicked: onMuteBtnClicked(2);
        BaseText{
            anchors{left: parent.left; leftMargin: 130;}
            anchors{top: parent.top; topMargin: 40;}
            size: 27;
            text: qsTr("双温区");
        }
        onClicked: {
            if(doubl === 0){
                c_qmlInterface.sendRccCAN('4-0-0-0-6-0-0');
                doubl = 1;
            }else{
                c_qmlInterface.sendRccCAN('4-0-0-0-2-0-0');
                doubl = 0;
            }
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
        onClicked: {
            if(offFlag === 0){
                c_qmlInterface.sendRccCAN('4-0-0-0-2-0-0');
                offFlag = 1;
            }else{
                c_qmlInterface.sendRccCAN('4-0-0-0-0-0-0');
                offFlag = 0;
            }
        }
    }

    MenuButton{
        id:ac;
        width: 72; height: 46;
        anchors.verticalCenter: driverSub.verticalCenter;
        anchors{left: power.right; leftMargin: 50;}
        normalSource: "qrc:/images/air/AC_Icon_AC_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_AC_exe.png";
        onClicked: {
            if(acFlag === 0){
                c_qmlInterface.sendRccCAN('4-0-0-0-3-0-0');
                acFlag = 1;
            }else{
                c_qmlInterface.sendRccCAN('4-0-0-0-2-0-0');
                acFlag = 0;
            }
        }
    }

    MenuButton{
        id:sterilization;
        width: 72;
        height: 46;
        anchors.verticalCenter: driverSub.verticalCenter;
        anchors{left: ac.right; leftMargin: 51;}
        normalSource: "qrc:/images/air/AC_Icon_cj_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_cj_exe.png";
    }


    MenuButton{
        id:anion;
        width: 72; height: 46;
        anchors.verticalCenter: driverSub.verticalCenter;
        anchors{left: sterilization.right; leftMargin: 51;}
        normalSource: "qrc:/images/air/AC_Icon_flz_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_flz_exe.png";
        onClicked: {
            if(fulizhi === 0){
                c_qmlInterface.sendRccCAN('4-0-0-128-2-0-0');
                fulizhi = 1;
            }else{
                c_qmlInterface.sendRccCAN('4-0-0-0-2-0-0');
                fulizhi = 0;
            }
        }
    }

    MenuButton{
        id:plasma;
        width: 72; height: 46;
        anchors.verticalCenter: driverSub.verticalCenter;
        anchors{left: anion.right; leftMargin: 51;}
        normalSource: "qrc:/images/air/AC_Icon_dlz_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_dlz_exe.png";
        onClicked: {
            if(denglizhi === 0){
                c_qmlInterface.sendRccCAN('4-0-0-64-2-0-0');
                denglizhi = 1;
            }else{
                c_qmlInterface.sendRccCAN('4-0-0-0-2-0-0');
                denglizhi = 0;
            }
        }
    }

    MenuButton{
        id:windDirection;
        width: 72; height: 46;
        anchors.verticalCenter: driverSub.verticalCenter;
        anchors{left: plasma.right; leftMargin: 51;}
        normalSource: "qrc:/images/air/AC_Icon_fbdj_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_fbdj_exe.png";
        onClicked: {
            if(fengbaidianji === 0){
                c_qmlInterface.sendRccCAN('4-0-0-32-2-0-0');
                fengbaidianji = 1;
            }else{
                c_qmlInterface.sendRccCAN('4-0-0-0-2-0-0');
                fengbaidianji = 0;
            }
        }
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
        var temVar;
        var strData;
        switch(val)
        {
        case 10:
            if(driverTmp < 40.3)
            {
                driverTmp += 0.5;
                temVar = driverTmp*10;
                strData = "1-" + temVar + "-0" + "-0" + "-2" + "-0" + "-0";
                c_qmlInterface.sendRccCAN(strData);
            }
            break;
        case 11:
            if(driverTmp > 15)
            {
                driverTmp -= 0.5;
                temVar = driverTmp*10;
                strData = "1-" + temVar + "-0" + "-0" + "-2" + "-0" + "-0";
                c_qmlInterface.sendRccCAN(strData);
            }
            break;
        case 20:
            if(windSpeedText > 0){
                tmp = windSpeedText -1;
                windSpeedText = tmp;
                strData =  "1-" + "0-" + "0-" + windSpeedText + "-2" + "-0" + "-0";
                c_qmlInterface.sendRccCAN(strData);
            }
            break;
        case 21:
            if(windSpeedText < 8)
            {
                tmp = windSpeedText +1;
                windSpeedText = tmp;
                strData =  "1-" + "0-" + "0-" + windSpeedText + "-2" + "-0" + "-0";
                c_qmlInterface.sendRccCAN(strData);
            }
            break;
        case 30:
            if(driverSideTmp < 40.3)
            {
                driverSideTmp += 0.5;
                temVar = driverSideTmp*10;
                strData = "1-" + "0-" + temVar + "-0" + "-2" + "-0" + "-0";
                c_qmlInterface.sendRccCAN(strData);
            }
            break;
        case 31:
            if(driverSideTmp > 15)
            {
                driverSideTmp -= 0.5;
                temVar = driverSideTmp*10;
                strData = "1-" + "0-" + temVar + "-0" + "-2" + "-0" + "-0";
                c_qmlInterface.sendRccCAN(strData);
            }
            break;
        default:
            break;
        }
    }

}
