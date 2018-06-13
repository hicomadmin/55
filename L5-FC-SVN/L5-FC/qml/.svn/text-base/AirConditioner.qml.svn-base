import QtQuick 2.3

Item {
    anchors.fill: parent;
    property real driverTmp: 27.5;
    property real driverSideTmp: 27.5;
    property int  windSpeedText: 7;
    property int  circle: 1500;


    BaseButton {
        id:autoTmp;
        width: 194;  height: 102;
        anchors{left: parent.left; leftMargin: 482;}
        anchors{top: parent.top; topMargin: 54;}
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
        Image {
            x:71; y:8;
            visible: c_qmlInterface.isAutoMode
            source: "qrc:/images/air/AC_Icon_powerd_dec.png"
        }
        onClicked: {
            if(c_qmlInterface.isAutoMode){
                c_qmlInterface.sendFccCAN('1-4-0-0-0-0-0'); //off cmd
            }else{
                c_qmlInterface.sendFccCAN('1-4-1-0-0-0-0'); //on cmd
            }
        }
    }

    BaseButton {
        id:doubleZone;
        width: 194;  height: 102;
        anchors{left: autoTmp.right; leftMargin: 42; top: autoTmp.top;}
        normalSource: "qrc:/images/air/AC_Icon_powerd_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_powerd_exe.png";
        Image {
            width: 176; height: 84;
            anchors{left: parent.left; leftMargin: 15; verticalCenter: parent.verticalCenter;}
            source: "qrc:/images/air/AC_Icon_seq_nml.png"
        }
        Image {
            x:71; y:8;
            visible: c_qmlInterface.daulStatus
            source: "qrc:/images/air/AC_Icon_powerd_dec.png"
        }
        BaseText{
            anchors{left: parent.left; leftMargin: 85;}
            anchors{top: parent.top; topMargin: 40;}
            size: 27;
            text: qsTr("双温区");
        }

        onClicked: {
            if(c_qmlInterface.daulStatus){
                c_qmlInterface.sendFccCAN('1-11-0-0-0-0-0'); //off cmd
            }else{
                c_qmlInterface.sendFccCAN('1-11-1-0-0-0-0'); //on cmd
            }
        }
    }

    BaseButton {
        id:air_B;
        width: 194; height: 102;
        anchors{left: doubleZone.right; leftMargin: 42; top: autoTmp.top;}
        normalSource: "qrc:/images/air/AC_Icon_powerd_nml.png";
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
        Image {
            x:71; y:8;
            visible: !c_qmlInterface.isBackON
            source: "qrc:/images/air/AC_Icon_powerd_dec.png"
        }
        onClicked: {
            if(c_qmlInterface.isBackON){
                c_qmlInterface.sendFccCAN('1-20-0-0-0-0-0'); //off cmd
            }
            else{
                c_qmlInterface.sendFccCAN('1-20-1-0-0-0-0'); //on cmd
            }
        }
    }


    BaseButton{
        id:driverAdd
        width: 110; height: 110;
        anchors{left: parent.left; leftMargin: 581;}
        anchors{top: autoTmp.bottom; topMargin: 9;}
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

    Image {
        width: 1; height: 320;
        anchors.left: driverSub.right;
        anchors.leftMargin: 49;
        anchors.top: parent.top;
        anchors.topMargin: 155;
        source: "qrc:/images/air/Set_List_SeparatorLine.png"
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
        id: speedText;
        anchors{top: windSpeedAdd.bottom; topMargin: 5;}
        anchors.horizontalCenter: windSpeedAdd.horizontalCenter
        anchors.horizontalCenterOffset: 10;
        font.pixelSize: 60;
        text: windSpeedText
    }

    Image {
        id: windSpeedIcn
        width: 42;
        height: 44;
        anchors.verticalCenter: speedText.verticalCenter;
        anchors.right: speedText.left;
        source: "qrc:/images/air/AC_Scale_nml.png"
    }
    NumberAnimation {
        id: animation
        running: c_qmlInterface.isFrontON
        loops: Animation.Infinite
        target: windSpeedIcn
        from: 0
        to: -360
        property: "rotation"
        duration: circle
    }

    BaseButton{
        id:windSpeedSub
        width: 110; height: 110;
        anchors{left: windSpeedAdd.left; top: windSpeedAdd.bottom; topMargin: 81;}
        normalSource: "qrc:/images/AC_Tem_leftSub_nml.png";
        pressSource:  "qrc:/images/AC_Tem_leftSub_exe.png"
        onClicked: onAdjustmentBtnClicked(21);
    }


    Image {
        width: 1; height: 320;
        anchors.left: windSpeedSub.right;
        anchors.leftMargin: 49;
        anchors.top: parent.top;
        anchors.topMargin: 155;
        source: "qrc:/images/air/Set_List_SeparatorLine.png"
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

    Image {
        width: 900; height: 1;
        anchors{left: parent.left; leftMargin: 410;}
        anchors.top: copilotSub.bottom;
        anchors.topMargin: 17;
        source: "qrc:/images/air/Set_List_SeparatorLineh.png"
    }




    BaseButton{
        id:qcsIcon
        width: 72; height: 46;
        anchors{left: parent.left; leftMargin: 495;}
        anchors{top: copilotSub.bottom; topMargin: 56;}
        normalSource: "qrc:/images/air/AC_Icon_qcs_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_qcs_exe.png";
        onClicked: {
            if(qcsIcon.normalSource == "qrc:/images/air/AC_Icon_qcs_nml.png"){
                c_qmlInterface.sendFccCAN('1-7-5-0-0-48-0'); //前除霜on cmd
            }else{
                c_qmlInterface.sendFccCAN('1-7-0-0-0-0-0'); //未选择 cmd
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
            if(cmIcon.normalSource == "qrc:/images/air/AC_Icon_cm_nml.png"){
                c_qmlInterface.sendFccCAN('1-7-1-0-0-0-0'); //上吹风on cmd
                //c_qmlInterface.sendFccCAN('1-0-0-0-17-0-0');
            }else{
                c_qmlInterface.sendFccCAN('1-7-0-0-0-0-0'); //上吹风未选择 cmd
                //c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0');
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
            if(cjIcon.normalSource == "qrc:/images/air/AC_Icon_cj_nml.png"){
                c_qmlInterface.sendFccCAN('1-7-3-0-0-19-0'); //下吹风on cmd
                //c_qmlInterface.sendFccCAN('1-0-0-0-19-0-0');
            }else{
                c_qmlInterface.sendFccCAN('1-7-0-0-0-0-0'); //上吹风未选择 cmd
                //c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0'); //下吹风off
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
            if(cmjIcon.normalSource == "qrc:/images/air/AC_Icon_cmj_nml.png"){
                c_qmlInterface.sendFccCAN('1-7-2-0-0-0-0'); //上下吹风on cmd
                //c_qmlInterface.sendFccCAN('1-0-0-0-18-0-0');
            }else{
                c_qmlInterface.sendFccCAN('1-7-0-0-0-0-0'); //上吹风未选择 cmd
                //c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0'); //上下吹风off
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
            if(cjchIcon.normalSource == "qrc:/images/air/AC_Icon_cjch_nml.png"){
                c_qmlInterface.sendFccCAN('1-7-4-0-0-18-0'); //下吹风+除霜 cmd
                //c_qmlInterface.sendFccCAN('1-0-0-0-29-0-0');
            }else{
                c_qmlInterface.sendFccCAN('1-7-0-0-0-0-0'); //未选择 cmd
                //c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0');
            }
        }
    }

    BaseButton{
        id:hccIcon
        width: 72; height: 46;
        anchors{left: cjchIcon.right; leftMargin: 55; top: qcsIcon.top;}
        normalSource: c_qmlInterface.defrost?"qrc:/images/air/AC_Icon_hcc_exe.png":"qrc:/images/air/AC_Icon_hcc_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_hcc_exe.png";
        onClicked: {
            if(c_qmlInterface.defrost){
               c_qmlInterface.sendFccCAN('1-10-0-0-0-0-0'); //off cmd
            }else{
               c_qmlInterface.sendFccCAN('1-10-1-0-0-0-0'); //on cmd
            }
        }
    }


    ////
    BaseButton{
        id:acIcon
        width: 72; height: 46;
        anchors{left: qcsIcon.left; top: qcsIcon.bottom; topMargin: 48;}
        normalSource: c_qmlInterface.acStatus?"qrc:/images/air/AC_Icon_ac_exe.png":"qrc:/images/air/AC_Icon_ac_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_ac_exe.png";
        onClicked: {
            if(c_qmlInterface.acStatus){
                c_qmlInterface.sendFccCAN('1-8-0-0-0-0-0'); //AC off
                //c_qmlInterface.sendFccCAN('1-0-0-192-16-0-0');
            }
            else{
                c_qmlInterface.sendFccCAN('1-8-1-0-0-0-0'); //AC on
                //c_qmlInterface.sendFccCAN('1-0-0-192-24-0-0');
            }
        }
    }

    BaseButton{
        width: 72; height: 46;
        anchors{left: qcsIcon.right; leftMargin: 55; top: acIcon.top;}
        normalSource: c_qmlInterface.cycleMode?"qrc:/images/air/AC_Icon_nxh_exe.png":"qrc:/images/air/AC_Icon_nxh_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_nxh_exe.png";
        onClicked: {
            if(c_qmlInterface.cycleMode){
                console.log("内循环 on");
                //c_qmlInterface.sendFccCAN('1-0-0-32-16-0-0');
            }
            else{
                c_qmlInterface.sendFccCAN('1-5-1-0-0-0-0'); //内循环 on
                //c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0'); //内循环 off
            }
        }
    }

    BaseButton{
        width: 72; height: 46;
        anchors{left: cmIcon.right;leftMargin: 55;top: acIcon.top;}
        normalSource: c_qmlInterface.cycleMode?"qrc:/images/air/AC_Icon_wxh_nml.png":"qrc:/images/air/AC_Icon_wxh_exe.png";
        pressSource:  "qrc:/images/air/AC_Icon_wxh_exe.png";
        onClicked: {
            if(c_qmlInterface.cycleMode){
                c_qmlInterface.sendFccCAN('1-5-0-0-0-0-0');
                //c_qmlInterface.sendFccCAN('1-0-0-32-16-0-0');
            }
            else{
                console.log("外循环 on");
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
        id:dlzIcon
        width: 72; height: 46;
        anchors{left: cmjIcon.right; leftMargin: 55; top: acIcon.top;}
        normalSource: "qrc:/images/air/AC_Icon_dlz_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_dlz_exe.png";
        onClicked: {
            if(dlzIcon.normalSource == "qrc:/images/air/AC_Icon_dlz_nml.png"){
                c_qmlInterface.sendFccCAN('1-6-1-0-0-0-0'); //等离子 on
                //c_qmlInterface.sendFccCAN('1-0-0-64-16-0-0');
            }
            else{
                c_qmlInterface.sendFccCAN('1-6-0-0-0-0-0');  //等离子 off
                //c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0');
            }
        }
    }

    BaseButton{
        id:flzIcon
        width: 72; height: 46;
        anchors{left: cjchIcon.right;leftMargin: 55; top: acIcon.top;}
        normalSource: "qrc:/images/air/AC_Icon_flz_nml.png";
        pressSource:  "qrc:/images/air/AC_Icon_flz_exe.png";
        onClicked: {
            if(flzIcon.normalSource == "qrc:/images/air/AC_Icon_flz_nml.png"){
                c_qmlInterface.sendFccCAN('1-6-2-0-0-0-0'); //负离子 on
                //c_qmlInterface.sendFccCAN('1-0-0-128-16-0-0');
            }
            else{
                c_qmlInterface.sendFccCAN('1-6-2-0-0-0-0'); //负离子 off
                //c_qmlInterface.sendFccCAN('1-0-0-0-16-0-0');
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
                strData = "1-1-" + temVar + "-0" + "-0" + "-0" + "-0";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        case 11:
            if(driverTmp > 15)
            {
                driverTmp -= 0.5;
                temVar = driverTmp*10;
                strData = "1-1-" + temVar + "-0" + "-0" + "-0" + "-0";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        case 20:
            if(windSpeedText < 8)
            {
                tmp = windSpeedText +1;
                ctlSpeedIcon(tmp);
                windSpeedText = tmp;
                strData =  "1-3-" + windSpeedText + "-0" + "-0" + "-0" + "-0";
                //strData =  "1-" + "0-" + "0-" + windSpeedText + "-16" + "-0" + "-0";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        case 21:
            if(windSpeedText > 0){
                tmp = windSpeedText -1;
                ctlSpeedIcon(tmp);
                windSpeedText = tmp;
                strData =  "1-3-" + windSpeedText + "-0" + "-0" + "-0" + "-0";
                //strData =  "1-" + "0-" + "0-" + windSpeedText + "-16" + "-0" + "-0";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        case 30:
            if(driverSideTmp < 40.3)
            {
                driverSideTmp += 0.5;
                temVar = driverSideTmp*10;
                strData = "1-2-" + temVar + "-0"  + "-0" + "-0" + "-0";
                //strData = "1-" + "0-" + temVar + "-0" + "-16" + "-0" + "-0";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        case 31:
            if(driverSideTmp > 15)
            {
                driverSideTmp -= 0.5;
                temVar = driverSideTmp*10;
                strData = "1-2-" + temVar + "-0"  + "-0" + "-0" + "-0";
                //strData = "1-" + "0-" + temVar + "-0" + "-16" + "-0" + "-0";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        default:
            break;
        }
    }


    function ctlSpeedIcon(val)
    {
        switch(val)
        {
        case 0:
            circle = 1000;
            break;
        case 1:
            circle = 1200;
            break;
        case 2:
            circle = 1400;
            break;
        case 3:
            circle = 1600;
            break;
        case 4:
            circle = 1800;
            break;
        case 5:
            circle = 2000;
            break;
        case 6:
            circle = 2200;
            break;
        case 7:
            circle = 2400;
            break;
        case 7:
            circle = 2600;
            break;
        default:
            break;
        }
    }

    function retFACwindSpeedLevel(level)
    {
        console.log("###### retFACwindSpeedLevel level #####", level);
        windSpeedText = level;
        ctlSpeedIcon(level);
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

    Component.onCompleted:{
        c_qmlInterface.getCanInfo("AC");
    }
}
