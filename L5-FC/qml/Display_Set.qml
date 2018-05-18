import QtQuick 2.3

Item {
    anchors.fill: parent;
    property int brightnessTxt:c_qmlInterface.brightness;
    signal clockButtonClicked();

    Image {
        id: brightnessBtnBg
        width: 326;
        height: 110;
        anchors.left: parent.left;
        anchors.leftMargin: 455;
        anchors.top: parent.top;
        anchors.topMargin: 111;
        source: "qrc:/images/light/Set_Light_ld.png"

        BaseButton {
            width: 110;
            height: 110;
            anchors.left: parent.left;
            normalSource: "qrc:/images/AC_Tem_leftAdd_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftAdd_exe.png"
            onClicked: onJustmentBtnClicked(1);
        }

        BaseButton {
            width: 110;
            height: 110;
            anchors.right: parent.right;
            normalSource: "qrc:/images/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftSub_exe.png"
            onClicked: onJustmentBtnClicked(2);
        }
        BaseText{
            anchors.centerIn: parent;
            size: 46;
            text: brightnessTxt;
        }
    }

    BaseText{
        anchors.left: brightnessBtnBg.left;
        anchors.leftMargin: 12;
        anchors.bottom: brightnessBtnBg.top;
        size: 28;
        text: qsTr("液晶屏亮度调节");
    }



    BaseButton {
        id: autoSetTimeON;
        width: 110;
        height: 110;
        anchors.left:brightnessBtnBg.left;
        anchors.top: brightnessBtnBg.bottom;
        anchors.topMargin: 95;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png"
    }

    BaseButton {
        id:autoSetTimeOFF;
        width: 110;
        height: 110;
        anchors.left: autoSetTimeON.right;
        anchors.leftMargin: 38;
        anchors.top: autoSetTimeON.top;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png"
    }

    BaseText{
        anchors.left: autoSetTimeON.left;
        anchors.leftMargin: 12;
        anchors.bottom: autoSetTimeON.top;
        size: 28;
        text: qsTr("自动设置时间");
    }


    BaseButton {
        id:timeRegulation;
        width: 200;
        height: 110;
        anchors.left: autoSetTimeOFF.right;
        anchors.leftMargin: 40;
        anchors.top: autoSetTimeON.top;
        btnText: qsTr("时钟调节");
        normalSource: "qrc:/images/set/Set_ty_mmqr_nml.png";
        pressSource:  "qrc:/images/set/Set_ty_mmqr_exe.png"
        onClicked: clockButtonClicked();
    }


    BaseButton {
        id:mileageA;
        width: 200;
        height: 110;
        anchors.left: autoSetTimeON.left;
        anchors.top: autoSetTimeON.bottom;
        anchors.topMargin: 94;
        btnText: qsTr("里程A");
        normalSource: "qrc:/images/set/Set_ty_mmqr_nml.png";
        pressSource:  "qrc:/images/set/Set_ty_mmqr_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('2-8-1-0-0-0');
        //onClicked: c_qmlInterface.sendFccCAN('2-0-0-1-0-0');
    }

    BaseText{
        anchors.left: mileageA.left;
        anchors.leftMargin: 12;
        anchors.bottom: mileageA.top;
        size: 28;
        text: qsTr("里程显示");
    }

    BaseButton {
        id:mileageB;
        width: 200;
        height: 110;
        anchors.left: mileageA.left;
        anchors.leftMargin: 191;
        anchors.top: mileageA.top;
        btnText: qsTr("里程B");
        normalSource: "qrc:/images/set/Set_ty_mmqr_nml.png";
        pressSource:  "qrc:/images/set/Set_ty_mmqr_exe.png";
        onClicked: c_qmlInterface.sendFccCAN('2-8-2-0-0-0');
        //onClicked: c_qmlInterface.sendFccCAN('2-0-0-2-0-0');
    }


    BaseButton {
        id:mileageAReset;
        width: 200;
        height: 110;
        anchors.left: mileageB.left;
        anchors.leftMargin: 191;
        anchors.top: mileageA.top;
        btnText: qsTr("里程A复位");
        normalSource: "qrc:/images/set/Set_ty_mmqr_nml.png";
        pressSource:  "qrc:/images/set/Set_ty_mmqr_exe.png";
        onPressed: c_qmlInterface.sendFccCAN('2-9-1-0-0-0');
        onReleased: c_qmlInterface.sendFccCAN('2-9-0-0-0-0');
        //onClicked: c_qmlInterface.sendFccCAN('2-0-0-4-0-0');
    }


    BaseButton {
        id:mileageBReset;
        width: 200;
        height: 110;
        anchors.left: mileageAReset.left;
        anchors.leftMargin: 191;
        anchors.top: mileageA.top;
        btnText: qsTr("里程B复位");
        normalSource: "qrc:/images/set/Set_ty_mmqr_nml.png";
        pressSource:  "qrc:/images/set/Set_ty_mmqr_exe.png";
        onPressed: c_qmlInterface.sendFccCAN('2-10-1-0-0-0');
        onReleased: c_qmlInterface.sendFccCAN('2-10-0-0-0-0');
        //onClicked: c_qmlInterface.sendFccCAN('2-0-0-8-0-0');
    }

    BaseText{
        anchors.left: mileageB.right;
        anchors.leftMargin: 32;
        anchors.top: mileageB.bottom;
        anchors.topMargin: 5;
        size: 22;
        text: qsTr("(加油后清零)");
    }

    BaseText{
        id: hinit;
        anchors.left: mileageAReset.right;
        anchors.leftMargin: 32;
        anchors.top: mileageB.bottom;
        anchors.topMargin: 5;
        size: 22;
        text: qsTr("(维修后清零)");
    }



    Item {
        width: 100;
        height: 40
        anchors.left: mileageAReset.right;
        anchors.leftMargin: 32;
        anchors.top: mileageB.bottom;
        anchors.topMargin: 10;
        MouseArea{
            anchors.fill: parent;
            onPressed: version.visible = true;
            onReleased: version.visible = false;
        }
    }
    BaseText{
        id: version
        anchors.left: mileageA.left;
        anchors.top: mileageA.bottom;
        anchors.topMargin: 5;
        size: 22;
        visible: false;
        text: qsTr("V1.0_20180517");
    }



    function onJustmentBtnClicked(val)
    {
        var tmp;
        var strData;
        switch(val) //本机设置亮度
        {
        case 1:
            if(brightnessTxt < 10){
                brightnessTxt = brightnessTxt +1;
                tmp = brightnessTxt* 100;
                console.log(" ################# +++ c_qmlInterface.brightness",c_qmlInterface.brightness);
                console.log(" ################# +++ tmp",tmp);
                c_qmlInterface.setBrightness(brightnessTxt);
            }
            break;
        case 2:
            if(brightnessTxt > 0){
                brightnessTxt = brightnessTxt -1;
                tmp = brightnessTxt* 100;
                console.log(" ################# --- tmp",tmp);
                c_qmlInterface.setBrightness(brightnessTxt);
            }
            break;
        default:
            break;
        }
    }


    function retSubDistanceA(distance)
    {
        console.log("################ distance A: ", distance);
    }

    function retSubDistanceB(distance)
    {
        console.log("################ distance B: ", distance);
    }


    Component.onCompleted: {
        c_qmlInterface.getCanInfo("TIME");
    }

}
