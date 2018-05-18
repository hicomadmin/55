import QtQuick 2.3

Item {
    anchors.fill: parent;
    property real driverTmp: 27.5;
    property real driverSideTmp: 27.5;
    property int  windSpeedText: 7;

    property int ofFlag:0;
    property int flag:0;
    property int onOffFlag:0;
    property int auto: 0;
    property int dual: 0;
    property int chushuang: 0;
    property int shangchuifeng: 0;
    property int xiachuifeng: 0;
    property int shangxiachuifeng: 0;
    property int xiajiachushuang: 0;
    property int neixunhuan: 0;
    property int waixunhuan: 0;
    property int degnlizhi: 0;
    property int fulizhi: 0;

    BaseButton {
        id:off;
        width: 194; height: 102;
        anchors{left: parent.left; leftMargin: 460;}
        anchors{top: parent.top; topMargin: 54;}
        normalSource: c_qmlInterface.isFrontON ? "qrc:/images/air/AC_Icon_powerd_nml.png":"qrc:/images/air/AC_Icon_powerd_dec.png";
        pressSource:  "qrc:/images/air/AC_Icon_powerd_exe.png";
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
        onClicked: {
            if(onOffFlag == 0){
                c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0'); //on
                onOffFlag = 1;
            }else{
                c_qmlInterface.sendFccCAN('1-0-0-0-0-0-0');//off
                onOffFlag = 0;
            }
        }
    }

    BaseButton {
        id:autoTmp;
        width: 194;  height: 102;
        anchors{left: off.left; leftMargin: 191; top: off.top;}
        normalSource: c_qmlInterface.isAutoMode?"qrc:/images/air/AC_Icon_powerd_dec.png":"qrc:/images/air/AC_Icon_powerd_nml.png";
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
        onClicked: {
            if(auto == 0){
                c_qmlInterface.sendFccCAN('1-0-0-16-16-0-0');
                auto = 1;
            }else{
                c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0');
                auto = 0;
            }
        }
    }

    BaseButton {
        id:doubleZone;
        width: 194;  height: 102;
        anchors{left: autoTmp.left; leftMargin: 191; top: off.top;}
        normalSource: c_qmlInterface.daulStatus?"qrc:/images/air/AC_Icon_powerd_dec.png":"qrc:/images/air/AC_Icon_powerd_nml.png";
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
        onClicked: {
            if(dual == 0){
                c_qmlInterface.sendFccCAN('1-0-0-00-80-0-0');
                dual = 1;
            }else{
                c_qmlInterface.sendFccCAN('1-0-0-00-16-0-0');
                dual = 0;
            }
        }
    }

    BaseButton {
        id:air_B;
        width: 194; height: 102;
        anchors{left: doubleZone.left; leftMargin: 191; top: off.top;}
        normalSource: c_qmlInterface.isBackON?"qrc:/images/air/AC_Icon_powerd_nml.png":"qrc:/images/air/AC_Icon_powerd_dec.png";
        pressSource:  "qrc:/images/air/AC_Icon_powerd_exe.png";
        Image {
            width: 176; height: 84;
            anchors{left: parent.left; verticalCenter: parent.verticalCenter;}
            source: "qrc:/images/air/AC_Icon_power_nml.png"
        }
        BaseText{
            anchors{left: parent.left; leftMargin: 85; top: parent.top; topMargin: 40;}
            size: 27;
            text: qsTr("后空调");
        }
        onClicked: {
            if(ofFlag === 0){
                c_qmlInterface.sendFccCAN('1-0-0-0-16-0-128'); //on
                ofFlag = 1;
            }
            else{
                c_qmlInterface.sendFccCAN('1-0-0-0-16-0-64'); //off
                ofFlag = 0;
            }
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
        pressSource:  "qrc:/images/air/AC_Icon_qcs_exe.png";
        onClicked: {
            if(chushuang == 0){
                c_qmlInterface.sendFccCAN('1-0-0-0-48-0-0'); //前除霜on
                chushuang = 1;
            }else{
                c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0'); //前除霜off
                chushuang = 0;
            }
        }
    }

    BaseButton{
        id:cmIcon
        width: 72; height: 46;
        anchors{left: qcsIcon.right; leftMargin: 55; top: qcsIcon.top;}
        normalSource: "qrc:/images/air/AC_Icon_cm_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_cm_exe.png";
        onClicked: {
            if(shangchuifeng == 0){
                c_qmlInterface.sendFccCAN('1-0-0-0-17-0-0'); //上吹风on
                shangchuifeng = 1;
            }else{
                c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0'); //上吹风off
                shangchuifeng = 0;
            }
        }
    }


    BaseButton{
        id:cjIcon
        width: 72; height: 46;
        anchors{left: cmIcon.right; leftMargin: 55; top: qcsIcon.top;}
        normalSource: "qrc:/images/air/AC_Icon_cj_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_cj_exe.png";
        onClicked: {
            if(xiachuifeng == 0){
                c_qmlInterface.sendFccCAN('1-0-0-0-19-0-0'); //下吹风on
                xiachuifeng = 1;
            }else{
                c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0'); //下吹风off
                xiachuifeng = 0;
            }
        }
    }

    BaseButton{
        id:cmjIcon
        width: 72; height: 46;
        anchors{left: cjIcon.right; leftMargin: 55; top: qcsIcon.top;}
        normalSource: "qrc:/images/air/AC_Icon_cmj_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_cmj_exe.png";
        onClicked: {
            if(shangxiachuifeng == 0){
                c_qmlInterface.sendFccCAN('1-0-0-0-18-0-0'); //上下吹风on
                shangxiachuifeng = 1;
            }else{
                c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0'); //上下吹风off
                shangxiachuifeng = 0;
            }
        }
    }

    BaseButton{
        id:cjchIcon
        width: 72; height: 46;
        anchors{left: cmjIcon.right; leftMargin: 55; top: qcsIcon.top;}
        normalSource: "qrc:/images/air/AC_Icon_cjch_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_cjch_exe.png";
        onClicked: {
            if(xiajiachushuang == 0){
                c_qmlInterface.sendFccCAN('1-0-0-0-29-0-0'); //下吹风+除霜
                xiajiachushuang = 1;
            }else{
                c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0'); //下吹风+除霜
                xiajiachushuang = 0;
            }
        }
    }

    BaseButton{
        width: 72; height: 46;
        anchors{left: cjchIcon.right; leftMargin: 55; top: qcsIcon.top;}
        normalSource: c_qmlInterface.defrost?"qrc:/images/air/AC_Icon_hcc_exe.png":"qrc:/images/air/AC_Icon_hcc_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_hcc_exe.png";
        onClicked: console.log("#### 后除霜 ####");
    }




    ////
    BaseButton{
        id:acIcon
        width: 72; height: 46;
        anchors{left: qcsIcon.left; top: qcsIcon.bottom; topMargin: 48;}
        normalSource: c_qmlInterface.acStatus?"qrc:/images/air/AC_Icon_ac_exe.png":"qrc:/images/air/AC_Icon_ac_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_ac_exe.png";
        onClicked: {
            if(flag === 1){
                c_qmlInterface.sendFccCAN('1-0-0-192-16-0-0'); //AC off
                flag = 0;
            }
            else{
                c_qmlInterface.sendFccCAN('1-0-0-192-24-0-0'); //AC on
                flag = 1;
            }
        }
    }

    BaseButton{
        width: 72; height: 46;
        anchors{left: qcsIcon.right; leftMargin: 55; top: acIcon.top;}
        normalSource: c_qmlInterface.cycleMode?"qrc:/images/air/AC_Icon_nxh_exe.png":"qrc:/images/air/AC_Icon_nxh_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_nxh_exe.png";
        onClicked: {
            if(neixunhuan === 0){
                c_qmlInterface.sendFccCAN('1-0-0-32-16-0-0'); //内循环 on
                neixunhuan = 1;
            }
            else{
                c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0'); //内循环 off
                neixunhuan = 0;
            }
        }
    }

    BaseButton{
        width: 72; height: 46;
        anchors{left: cmIcon.right;leftMargin: 55;top: acIcon.top;}
        normalSource: c_qmlInterface.cycleMode?"qrc:/images/air/AC_Icon_wxh_nml.png":"qrc:/images/air/AC_Icon_wxh_exe.png";
        pressSource:  "qrc:/images/air/AC_Icon_wxh_exe.png";
        onClicked: {
            if(waixunhuan === 0){
                c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0'); //外循环 on
                waixunhuan = 1;
            }
            else{
                c_qmlInterface.sendFccCAN('1-0-0-32-16-0-0'); //外循环 off
                waixunhuan = 0;
            }
        }
    }

    BaseButton{
        width: 72; height: 46;
        anchors{left: cjIcon.right; leftMargin: 55; top: acIcon.top;}
        normalSource: "qrc:/images/air/AC_Icon_chj_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_chj_exe.png";
        //c_qmlInterface.sendFccCAN('1-0-0-0-24-0-0'); //除菌 无CAN报文
    }

    BaseButton{
        width: 72; height: 46;
        anchors{left: cmjIcon.right; leftMargin: 55; top: acIcon.top;}
        normalSource: "qrc:/images/air/AC_Icon_dlz_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_dlz_exe.png";
        onClicked: {
            if(degnlizhi === 0){
                c_qmlInterface.sendFccCAN('1-0-0-64-16-0-0'); //等离子 on
                degnlizhi = 1;
            }
            else{
                c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0'); //等离子 off
                degnlizhi = 0;
            }
        }
    }

    BaseButton{
        width: 72; height: 46;
        anchors{left: cjchIcon.right;leftMargin: 55; top: acIcon.top;}
        normalSource: "qrc:/images/air/AC_Icon_flz_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_flz_exe.png";
        onClicked: {
            if(fulizhi === 0){
                c_qmlInterface.sendFccCAN('1-0-0-128-16-0-0'); //负离子 on
                fulizhi = 1;
            }
            else{
                c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0'); //负离子 off
                fulizhi = 0;
            }
        }
    }


    function onAdjustmentBtnClicked(val)
    {
        var tmp;
        var temVar;
        var strData;
        switch(val)
        {
        case 10:
            if(driverTmp < 40.3)
            {
                driverTmp += 0.5;
                temVar = driverTmp*10;
                strData = "1-" + temVar + "-0" + "-0" + "-16" + "-0" + "-0";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        case 11:
            if(driverTmp > 15)
            {
                driverTmp -= 0.5;
                temVar = driverTmp*10;
                strData = "1-" + temVar + "-0" + "-0" + "-16" + "-0" + "-0";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        case 20:
            if(windSpeedText < 8)
            {
                tmp = windSpeedText +1;
                windSpeedText = tmp;
                strData =  "1-" + "0-" + "0-" + windSpeedText + "-16" + "-0" + "-0";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        case 21:
            if(windSpeedText > 0){
                tmp = windSpeedText -1;
                windSpeedText = tmp;
                strData =  "1-" + "0-" + "0-" + windSpeedText + "-16" + "-0" + "-0";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        case 30:
            if(driverSideTmp < 40.3)
            {
                driverSideTmp += 0.5;
                temVar = driverSideTmp*10;
                strData = "1-" + "0-" + temVar + "-0" + "-16" + "-0" + "-0";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        case 31:
            if(driverSideTmp > 15)
            {
                driverSideTmp -= 0.5;
                temVar = driverSideTmp*10;
                strData = "1-" + "0-" + temVar + "-0" + "-16" + "-0" + "-0";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        default:
            break;
        }
    }

    function retFACwindSpeedLevel(level)
    {
        console.log("###### retFACwindSpeedLevel level #####", level);
        windSpeedText = level;
    }

    function retFACwindSpeedModel(model)
    {
        console.log("###### retFACwindSpeedModel model #####", model);
        switch(model)
        {
        case 0: // No Selection
            cmIcon.normalSource = "qrc:/images/air/AC_Icon_cm_nml.png";
            cmjIcon.pressSource = "qrc:/images/air/AC_Icon_cmj_nml.png";
            cjIcon.normalSource = "qrc:/images/air/AC_Icon_cj_nml.png";
            cjchIcon.normalSource = "qrc:/images/air/AC_Icon_cjch_nml.png";
            qcsIcon.normalSource = "qrc:/images/air/AC_Icon_qcs_nml.png";
            break;
        case 1: // Face
            cmIcon.normalSource = "qrc:/images/air/AC_Icon_cm_exe.png";
            break;
        case 2: // Face+Foot
            cmjIcon.pressSource = "qrc:/images/air/AC_Icon_cmj_exe.png";
            break;
        case 3: // Foot
            cjIcon.normalSource = "qrc:/images/air/AC_Icon_cj_exe.png";
            break;
        case 4: // Foot+Defrost
            cjchIcon.normalSource = "qrc:/images/air/AC_Icon_cjch_exe.png";
            break;
        case 5: // Front Defrost
            qcsIcon.normalSource = "qrc:/images/air/AC_Icon_qcs_exe.png";
            break;
        case 6: // Reserved
            break;
        case 7: // Invalid Value
            break;
        default:
            break;
        }
    }


//    Connections{
//        target: c_qmlInterface;
//        onSigFACwindSpeedLevel:retFACwindSpeedLevel(level);
//        onSigFACwindSpeedModel:retFACwindSpeedModel(model);
//    }

    Component.onCompleted: {
        c_qmlInterface.getCanInfo("AC");
    }

}
