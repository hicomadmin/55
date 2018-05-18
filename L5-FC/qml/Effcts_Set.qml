import QtQuick 2.3

Item {
    anchors.fill: parent;
    property int withSpeedTxt: 5;
    property int fbBalanceTxt: 5;
    property int lrBalanceTxt: 5;
    property int hightTxt: 5;
    property int lowTxt: 5;


    Image {
        id: lowBtnBg
        width: 326;
        height: 110;
        anchors.left: parent.left;
        anchors.leftMargin: 493;
        anchors.top: parent.top;
        anchors.topMargin: 126;
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
            text: lowTxt;
        }
    }

    Image {
        id: hightBtnBg
        width: 326;
        height: 110;
        anchors.left: lowBtnBg.right;
        anchors.leftMargin: 41;
        anchors.top: lowBtnBg.top;
        source: "qrc:/images/light/Set_Light_ld.png"

        BaseButton {
            width: 110;
            height: 110;
            anchors.left: parent.left;
            normalSource: "qrc:/images/AC_Tem_leftAdd_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftAdd_exe.png"
            onClicked: onJustmentBtnClicked(3);
        }

        BaseButton {
            width: 110;
            height: 110;
            anchors.right: parent.right;
            normalSource: "qrc:/images/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftSub_exe.png"
            onClicked: onJustmentBtnClicked(4);
        }
        BaseText{
            anchors.centerIn: parent;
            size: 46;
            text: hightTxt;
        }
    }


    Image {
        id: lrBalanceBtnBg
        width: 326;
        height: 110;
        anchors.left: lowBtnBg.left;
        anchors.top: lowBtnBg.bottom;
        anchors.topMargin: 80;
        source: "qrc:/images/light/Set_Light_ld.png"

        BaseButton {
            width: 110;
            height: 110;
            anchors.left: parent.left;
            normalSource: "qrc:/images/AC_Tem_leftAdd_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftAdd_exe.png"
            onClicked: onJustmentBtnClicked(5);
        }

        BaseButton {
            width: 110;
            height: 110;
            anchors.right: parent.right;
            normalSource: "qrc:/images/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftSub_exe.png"
            onClicked: onJustmentBtnClicked(6);
        }
        BaseText{
            anchors.centerIn: parent;
            size: 46;
            text: lrBalanceTxt;
        }
    }


    Image {
        id: fbBalanceBtnBg
        width: 326;
        height: 110;
        anchors.left: lowBtnBg.right;
        anchors.leftMargin: 41;
        anchors.top: lrBalanceBtnBg.top;
        source: "qrc:/images/light/Set_Light_ld.png"

        BaseButton {
            width: 110;
            height: 110;
            anchors.left: parent.left;
            normalSource: "qrc:/images/AC_Tem_leftAdd_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftAdd_exe.png"
            onClicked: onJustmentBtnClicked(7);
        }

        BaseButton {
            width: 110;
            height: 110;
            anchors.right: parent.right;
            normalSource: "qrc:/images/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftSub_exe.png"
            onClicked: onJustmentBtnClicked(8);
        }
        BaseText{
            anchors.centerIn: parent;
            size: 46;
            text: fbBalanceTxt;
        }
    }


    BaseButton {
        id:withSpeedON;
        width: 110;
        height: 110;
        anchors.left:lowBtnBg.left;
        anchors.top: lrBalanceBtnBg.bottom;
        anchors.topMargin: 104;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png"
    }

    BaseButton {
        id:withSpeedOFF;
        width: 110;
        height: 110;
        anchors.left: withSpeedON.right;
        anchors.leftMargin: 106;
        anchors.top: withSpeedON.top;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png"
    }



    Image {
        id: noneBtnBg
        width: 326;
        height: 110;
        anchors.left: withSpeedOFF.right;
        anchors.leftMargin: 41;
        anchors.top: withSpeedOFF.top;
        source: "qrc:/images/light/Set_Light_ld.png"

        BaseButton {
            width: 110;
            height: 110;
            anchors.left: parent.left;
            normalSource: "qrc:/images/AC_Tem_leftAdd_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftAdd_exe.png"
            onClicked: onJustmentBtnClicked(9);
        }

        BaseButton {
            width: 110;
            height: 110;
            anchors.right: parent.right;
            normalSource: "qrc:/images/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftSub_exe.png"
            onClicked: onJustmentBtnClicked(10);
        }
        BaseText{
            anchors.centerIn: parent;
            size: 46;
            text: withSpeedTxt;
        }
    }

    Image {
        width: 787; height: 1;
        anchors{left: lrBalanceBtnBg.left; top: lrBalanceBtnBg.bottom; topMargin: 45;}
        source: "qrc:/images/light/Set_Light_fgt.png"
    }



    BaseText{
        anchors.left: lowBtnBg.left;
        anchors.leftMargin: 12;
        anchors.bottom: lowBtnBg.top;
        size: 28;
        text: qsTr("低音调节");
    }

    BaseText{
        anchors.left: hightBtnBg.left;
        anchors.leftMargin: 12;
        anchors.bottom: hightBtnBg.top;
        size: 28;
        text: qsTr("高音调节");
    }

    BaseText{
        anchors.left: lrBalanceBtnBg.left;
        anchors.leftMargin: 12;
        anchors.bottom: lrBalanceBtnBg.top;
        size: 28;
        text: qsTr("左右平衡");
    }

    BaseText{
        anchors.left: fbBalanceBtnBg.left;
        anchors.leftMargin: 12;
        anchors.bottom: fbBalanceBtnBg.top;
        size: 28;
        text: qsTr("前后平衡");
    }

    BaseText{
        anchors.left: withSpeedON.left;
        anchors.leftMargin: 12;
        anchors.bottom: withSpeedON.top;
        size: 28;
        text: qsTr("车辆随速音量");
    }


    function onJustmentBtnClicked(val)
    {
        var tmp;
        switch(val)
        {
        case 1:
            if(lowTxt < 10){
                tmp = lowTxt +1;
                lowTxt = tmp;
                c_qmlInterface.sendFccCAN('2-4-1-0-0-0');
                c_qmlInterface.sendFccCAN('2-4-0-0-0-0');
            }
            break;
        case 2:
            if(lowTxt > 1){
                tmp = lowTxt -1;
                lowTxt = tmp;
                c_qmlInterface.sendFccCAN('2-4-2-0-0-0');
                c_qmlInterface.sendFccCAN('2-4-0-0-0-0');
            }
            break;
        case 3:
            if(hightTxt < 10){
                tmp = hightTxt +1;
                hightTxt = tmp;
                c_qmlInterface.sendFccCAN('2-3-1-0-0-0');
                c_qmlInterface.sendFccCAN('2-3-0-0-0-0');
            }
            break;
        case 4:
            if(hightTxt > 1){
                tmp = hightTxt -1;
                hightTxt = tmp;
                c_qmlInterface.sendFccCAN('2-3-2-0-0-0');
                c_qmlInterface.sendFccCAN('2-3-0-0-0-0');
            }
            break;
        case 5:
            if(lrBalanceTxt < 10){
                tmp = lrBalanceTxt +1;
                lrBalanceTxt = tmp;
                c_qmlInterface.sendFccCAN('2-5-0-0-0-0');
                c_qmlInterface.sendFccCAN('2-5-7-0-0-0'); //7为保留，没有Release
            }
            break;
        case 6:
            if(lrBalanceTxt > 1){
                tmp = lrBalanceTxt -1;
                lrBalanceTxt = tmp;
                c_qmlInterface.sendFccCAN('2-5-1-0-0-0');
                c_qmlInterface.sendFccCAN('2-5-7-0-0-0'); //7为保留，没有Release
            }
            break;
        case 7:
            if(fbBalanceTxt < 10){
                tmp = fbBalanceTxt +1;
                fbBalanceTxt = tmp;
                c_qmlInterface.sendFccCAN('2-5-2-0-0-0');
                c_qmlInterface.sendFccCAN('2-5-7-0-0-0'); //7为保留，没有Release
            }
            break;
        case 8:
            if(fbBalanceTxt > 1){
                tmp = fbBalanceTxt -1;
                fbBalanceTxt = tmp;
                c_qmlInterface.sendFccCAN('2-5-3-0-0-0');
                c_qmlInterface.sendFccCAN('2-5-7-0-0-0'); //7为保留，没有Release
            }
            break;
        case 9:
            if(withSpeedTxt < 10){
                tmp = withSpeedTxt +1;
                withSpeedTxt = tmp;
            }
            break;
        case 10:
            if(withSpeedTxt > 1){
                tmp = withSpeedTxt -1;
                withSpeedTxt = tmp;
            }
            break;
        default:
            break;
        }
    }


    function setTrebleVal(treble)
    {
        console.log("############### treble ################ ", treble);
        hightTxt = treble;
    }

    function setBassVal(bass)
    {
        console.log("############### bass ################ ", bass);
        lowTxt = bass;
    }


}
