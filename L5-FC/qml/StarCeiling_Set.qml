import QtQuick 2.3

Item {
    anchors.fill: parent;
    property int brightnessTxt: 5




    BaseButton {
        id: starCeilingON;
        width: 110;
        height: 110;
        anchors.left:parent.left;
        anchors.leftMargin: 605;
        anchors.top: parent.top;
        anchors.topMargin: 197;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png"
    }

    BaseButton {
        id:starCeilingOFF;
        width: 110;
        height: 110;
        anchors.left: starCeilingON.right;
        anchors.leftMargin: 65;
        anchors.top: starCeilingON.top;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png"
    }

    BaseText{
        anchors.left: starCeilingON.left;
        anchors.leftMargin: 12;
        anchors.bottom: starCeilingON.top;
        size: 28;
        text: qsTr("星空顶棚开关");
    }


    BaseButton {
        id:redBtn;
        width: 110;
        height: 110;
        anchors.left: starCeilingON.left;
        anchors.top: starCeilingON.bottom;
        anchors.topMargin: 94;
        btnText: qsTr("红");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png"
    }

    BaseText{
        anchors.left: redBtn.left;
        anchors.leftMargin: 12;
        anchors.bottom: redBtn.top;
        size: 28;
        text: qsTr("星空顶棚颜色");
    }

    BaseButton {
        id:yellowBtn;
        width: 110;
        height: 110;
        anchors.left: redBtn.right;
        anchors.leftMargin: 65;
        anchors.top: redBtn.top;
        btnText: qsTr("黄");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png"
    }

    BaseButton {
        id:blueBtn;
        width: 110;
        height: 110;
        anchors.left: yellowBtn.right;
        anchors.leftMargin: 65;
        anchors.top: redBtn.top;
        btnText: qsTr("蓝");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png"
    }


    function onJustmentBtnClicked(val)
    {
        var tmp;
        switch(val)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            if(brightnessTxt < 10){
                tmp = brightnessTxt +1;
                brightnessTxt = tmp;
            }
            break;
        case 8:
            if(brightnessTxt > 1){
                tmp = brightnessTxt -1;
                brightnessTxt = tmp;
            }
            break;
        default:
            break;
        }
    }

}
