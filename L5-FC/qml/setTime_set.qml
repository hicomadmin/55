import QtQuick 2.3


Item {
    id:setTime
    anchors.fill: parent;
    property int hourTxt: 00;
    property int minutiTxt: 00;
    signal hideClicked();

    Rectangle {
        id: mask;
        anchors.fill: parent;
        color: "#000000";
        opacity: 0.6;
        MouseArea{
            anchors.fill: parent;
            onClicked: setTime.hideClicked();
        }
    }

    Image{
        id: setTime_bg;
        width: 720;
        height: 408;
        anchors.centerIn: parent
        source:  "qrc:/images/set/Set_time_bg.png"
        MouseArea{
            anchors.fill: parent;
            onClicked: {}
        }

    }

    Image {
        id: hour_bg
        width: 110; height: 330;
        anchors.left: setTime_bg.left;
        anchors.leftMargin: 121;
        anchors.top: setTime_bg.top;
        anchors.topMargin: 37;
        source: "qrc:/images/set/Set_clock_ld.png"
        BaseButton {
            width: 110; height: 110;
            anchors.top: parent.top;
            normalSource: "qrc:/images/AC_Tem_leftAdd_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftAdd_exe.png";
            onClicked: onAdjustmentBtnClicked(1);
        }

        BaseButton {
            width: 110; height: 110;
            anchors.bottom: parent.bottom;
            normalSource: "qrc:/images/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftSub_exe.png";
            onClicked: onAdjustmentBtnClicked(-1);
        }
        BaseText{
            anchors.centerIn: parent;
            size: 46;
            text: hourTxt
        }
    }

    BaseText{
        id: dot;
        anchors.left: hour_bg.right;
        anchors.leftMargin: 34;
        anchors.verticalCenter: hour_bg.verticalCenter;
        size: 46;
        text: ":";
    }


    Image {
        id: minute_bg
        width: 110; height: 330;
        anchors.left: hour_bg.right;
        anchors.leftMargin: 80;
        anchors.top: hour_bg.top;
        source: "qrc:/images/set/Set_clock_ld.png"
        BaseButton {
            width: 110; height: 110;
            anchors.top: parent.top;
            normalSource: "qrc:/images/AC_Tem_leftAdd_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftAdd_exe.png";
            onClicked: onAdjustmentBtnClicked(2);
        }

        BaseButton {
            width: 110; height: 110;
            anchors.bottom: parent.bottom;
            normalSource: "qrc:/images/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftSub_exe.png";
            onClicked: onAdjustmentBtnClicked(-2);
        }
        BaseText{
            anchors.centerIn: parent;
            size: 46;
            text: minutiTxt;
        }
    }


    BaseButton{
        width: 110;
        height: 110;
        anchors.left: minute_bg.right;
        anchors.leftMargin: 64;
        anchors.bottom: minute_bg.bottom;
        btnText: qsTr("确认")
        normalSource:"qrc:/images/mirror/AC_Tem_nml.png"
        pressSource: "qrc:/images/mirror/AC_Tem_exe.png"
        onClicked: {
            hideClicked();
            var temHour = "2-15-"+ hourTxt + "-0-0-0";
            var temMinute = "2-13-"+ minutiTxt + "-0-0-0";
            c_qmlInterface.sendFccCAN(temHour);
            c_qmlInterface.sendFccCAN(temMinute);
        }
    }


    function retTimeMinute(minute)
    {
        console.log("################ minute: ", minute);
        minutiTxt = minute;
    }

    function retTimeHour(hour)
    {
        console.log("################ hour: ", hour);
        hourTxt = hour;
    }


    function onAdjustmentBtnClicked(val)
    {
        switch(val)
        {
        case 1:
            if(hourTxt < 23)
                hourTxt += 1;
            if(hourTxt == 23)
                hourTxt = 0;
            break;
        case -1:
            if(hourTxt > 0)
                hourTxt -= 1;
            if(hourTxt == 0)
                hourTxt = 23;
            break;
        case 2:
            if(minutiTxt < 59)
                minutiTxt += 1;
            if( minutiTxt == 59)
                minutiTxt = 0;
            break;
        case -2:
            if(minutiTxt > 0)
                minutiTxt -= 1
            if(minutiTxt == 0)
                minutiTxt = 59
            break;
        default:
            break;
        }
    }


}


