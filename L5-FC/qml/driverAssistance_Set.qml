﻿import QtQuick 2.3

Item {
    anchors.fill: parent;


    BaseText{
        anchors.left: ldwON.left;
        anchors.leftMargin: 12;
        anchors.bottom: ldwON.top;
        size: 28;
        text: qsTr("车道偏离预警LDW");
    }

    BaseButton {
        id:ldwON;
        width: 110;
        height: 110;
        anchors.left: parent.left;
        anchors.leftMargin: 493;
        anchors.top: parent.top;
        anchors.topMargin: 69;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('2-0-0-0-0-0');
    }

    BaseButton {
        id:ldwOFF;
        width: 110;
        height: 110;
        anchors.left: ldwON.right;
        anchors.leftMargin: 66;
        anchors.top: ldwON.top;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('2-0-0-0-0-1');
    }

    BaseText{
        anchors.left: dowON.left;
        anchors.leftMargin: 12;
        anchors.bottom: dowON.top;
        size: 28;
        text: qsTr("开门提醒DOW");
    }

    BaseButton{
        id:dowON;
        width: 110;
        height: 110;
        anchors.left: ldwOFF.right;
        anchors.leftMargin: 121;
        anchors.top: ldwON.top;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('2-0-0-0-0-0');
    }


    BaseButton {
        id:dowOFF;
        width: 110;
        height: 110;
        anchors.left: dowON.right;
        anchors.leftMargin: 66;
        anchors.top: ldwON.top;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('2-0-0-0-0-128');
    }

    BaseText{
        anchors.left: fcwON.left;
        anchors.leftMargin: 12;
        anchors.bottom: fcwON.top;
        size: 28;
        text: qsTr("前碰撞预警灯FCW");
    }

    BaseButton {
        id:fcwON;
        width: 110;
        height: 110;
        anchors.left: ldwON.left;
        anchors.top: ldwON.bottom;
        anchors.topMargin: 60;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('2-0-0-0-0-0');
    }


    BaseButton {
        id:fcwOFF;
        width: 110;
        height: 110;
        anchors.left: fcwON.right;
        anchors.leftMargin: 66;
        anchors.top: fcwON.top;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('2-0-0-0-0-2');
    }


    BaseText{
        anchors.left: dowON.left;
        anchors.leftMargin: 12;
        anchors.bottom: rcwON.top;
        size: 28;
        text: qsTr("后碰撞预警灯RCW");
    }

    BaseButton {
        id:rcwON;
        width: 110;
        height: 110;
        anchors.left: fcwOFF.right;
        anchors.leftMargin: 121;
        anchors.top: fcwON.top;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('2-0-0-0-0-0');
    }


    BaseButton {
        id:rcwONOFF;
        width: 110;
        height: 110;
        anchors.left: rcwON.right;
        anchors.leftMargin: 66;
        anchors.top: fcwON.top;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('2-0-0-0-0-64');
    }



    BaseText{
        anchors.left: isaON.left;
        anchors.leftMargin: 12;
        anchors.bottom: isaON.top;
        size: 28;
        text: qsTr("智能限速ISA");
    }

    BaseButton {
        id:isaON;
        width: 110;
        height: 110;
        anchors.left: ldwON.left;
        anchors.top: fcwON.bottom;
        anchors.topMargin: 60;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        //onClicked: c_qmlInterface.sendFccCAN('2-0-0-0-0-0');
    }

    BaseButton {
        id:isaOFF;
        width: 110;
        height: 110;
        anchors.left: isaON.right;
        anchors.leftMargin: 66;
        anchors.top: isaON.top;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        //onClicked: c_qmlInterface.sendFccCAN('2-0-0-0-0-0');
    }

    BaseText{
        anchors.left: ihcON.left;
        anchors.leftMargin: 12;
        anchors.bottom: ihcON.top;
        size: 28;
        text: qsTr("智能远近灯IHC");
    }

    BaseButton {
        id:ihcON;
        width: 110;
        height: 110;
        anchors.left: isaOFF.right;
        anchors.leftMargin: 121;
        anchors.top: isaOFF.top;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('2-0-0-0-0-0');
    }

    BaseButton {
        id:ihcOFF;
        width: 110;
        height: 110;
        anchors.left: ihcON.right;
        anchors.leftMargin: 66;
        anchors.top: ihcON.top;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('2-0-0-0-0-8');
    }

    BaseText{
        anchors.left: bsdON.left;
        anchors.leftMargin: 12;
        anchors.bottom: bsdON.top;
        size: 28;
        text: qsTr("盲区探测BSD");
    }

    BaseButton {
        id:bsdON;
        width: 110;
        height: 110;
        anchors.left: ldwON.left;
        anchors.top: ihcOFF.bottom;
        anchors.topMargin: 60;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('2-0-0-0-0-0');
    }

    BaseButton {
        id:bsdOFF;
        width: 110;
        height: 110;
        anchors.left: bsdON.right;
        anchors.leftMargin: 66;
        anchors.top: bsdON.top;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('2-0-0-0-0-16');
    }

    BaseText{
        anchors.left: asdsON.left;
        anchors.leftMargin: 12;
        anchors.bottom: asdsON.top;
        size: 28;
        text: qsTr("车道偏离和防撞预警ASDS");
    }

    BaseButton {
        id:asdsON;
        width: 110;
        height: 110;
        anchors.left: isaOFF.right;
        anchors.leftMargin: 121;
        anchors.top: bsdOFF.top;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        //onClicked: c_qmlInterface.sendFccCAN('2-0-0-0-0-0');
    }

    BaseButton {
        id:asdsOFF;
        width: 110;
        height: 110;
        anchors.left: asdsON.right;
        anchors.leftMargin: 66;
        anchors.top: asdsON.top;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
        //onClicked: c_qmlInterface.sendFccCAN('2-0-0-0-0-0');
    }


    Image {
        width: 1;
        height: 720;
        anchors.left: parent.left;
        anchors.leftMargin: 838;
        source: "qrc:/images/Main Set_List_SeparatorLine.png"
    }



    function retBSDInfoFCW(flag)
    {
       if(flag === 0){
           console.log(" ###### BSD Activated");
       }else{
           console.log(" ###### BSD deActivated");
       }
    }

    function retBSDInfoLDW(flag)
    {
        if(flag === 0){
            console.log(" ###### LDW Activated");
        }else{
            console.log(" ###### LDW deActivated");
        }
    }

    function retBSDInfoISA(flag)
    {
        if(flag === 0){
            console.log(" ###### ISA Activated");
        }else{
            console.log(" ###### ISA deActivated");
        }
    }

    function retBSDInfoBSDF(flag)
    {
        if(flag === 0){
            console.log(" ###### BSDF Activated");
        }else{
            console.log(" ###### BSDF deActivated");
        }
    }

    function retBSDInfoBSD(flag)
    {
        if(flag === 0){
            console.log(" ###### BSD Activated");
        }else{
            console.log(" ###### BSD deActivated");
        }
    }

    function retBSDInfoRCW(flag)
    {
        if(flag === 0){
            console.log(" ###### RCW Activated");
        }else{
            console.log(" ###### RCW deActivated");
        }
    }

    function retBSDInfoDOW(flag)
    {
        if(flag === 0){
            console.log(" ###### DOW Activated");
        }else{
            console.log(" ###### DOW deActivated");
        }
    }

    function retBSDInfoIHC(flag)
    {
        if(flag === 0){
            console.log(" ###### IHC Activated");
        }else{
            console.log(" ###### IHC deActivated");
        }
    }

//    Connections{
//        target: c_qmlInterface;
//        onSigBSDInfoFCW:retBSDInfoFCW(flag);
//        onSigBSDInfoLDW:retBSDInfoLDW(flag);
//        onSigBSDInfoISA:retBSDInfoISA(flag);
//        onSigBSDInfoBSDF:retBSDInfoBSDF(flag);
//        onSigBSDInfoBSD:retBSDInfoBSD(flag);
//        onSigBSDInfoRCW:retBSDInfoRCW(flag);
//        onSigBSDInfoDOW:retBSDInfoDOW(flag);
//        onSigBSDInfoIHC:retBSDInfoIHC(flag);
//    }


}
