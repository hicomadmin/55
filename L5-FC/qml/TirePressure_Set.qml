import QtQuick 2.3

Item {
    anchors.fill: parent;
    property int brightnessTxt: 5



    BaseButton {
        id: flTyreBtn;
        width: 56;
        height: 90;
        anchors.left:parent.left;
        anchors.leftMargin: 552;
        anchors.top: parent.top;
        anchors.topMargin: 142;
        normalSource: "qrc:/images/set/Set_ty_lt_nml.png";
        pressSource:  "qrc:/images/set/Set_ty_lt_exe.png";
    }


    BaseButton {
        id: blTyreBtn;
        width: 56;
        height: 90;
        anchors.left:flTyreBtn.left;
        anchors.top: flTyreBtn.bottom;
        anchors.topMargin: 92;
        normalSource: "qrc:/images/set/Set_ty_lt_nml.png";
        pressSource:  "qrc:/images/set/Set_ty_lt_exe.png";
    }


    BaseText{
        anchors.left: flTyreBtn.left;
        anchors.leftMargin: 10;
        anchors.bottom: flTyreBtn.top;
        anchors.bottomMargin: 35;
        size: 28;
        text: qsTr("传感器ID设置");
    }

    Image {
        id: carPNG;
        width: 138;
        height: 294;
        anchors.left: flTyreBtn.right;
        anchors.leftMargin: 19;
        anchors.top: parent.top;
        anchors.topMargin: 131;
        source: "qrc:/images/set/Set_ty_car.png";
    }

    BaseButton {
        id: frTyreBtn;
        width: 56;
        height: 90;
        anchors.left:carPNG.right;
        anchors.leftMargin: 22;
        anchors.top: flTyreBtn.top;
        normalSource: "qrc:/images/set/Set_ty_lt_nml.png";
        pressSource:  "qrc:/images/set/Set_ty_lt_exe.png";
    }


    BaseButton {
        id: brTyreBtn;
        width: 56;
        height: 90;
        anchors.left:frTyreBtn.left;
        anchors.top: frTyreBtn.bottom;
        anchors.topMargin: 92;
        normalSource: "qrc:/images/set/Set_ty_lt_nml.png";
        pressSource:  "qrc:/images/set/Set_ty_lt_exe.png";
    }


    Image {
        id: line;
        width: 787; height: 1;
        anchors{left: blTyreBtn.left;leftMargin: -118; top: blTyreBtn.bottom; topMargin: 63;}
        source: "qrc:/images/light/Set_Light_fgt.png"
    }


    BaseButton {
        id:oN;
        width: 110;
        height: 110;
        anchors.left: line.left;
        anchors.leftMargin: 116;
        anchors.top: line.bottom;
        anchors.topMargin: 32;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png"
    }

    BaseButton {
        id:oFF;
        width: 110;
        height: 110;
        anchors.left: oN.right;
        anchors.leftMargin: 319;
        anchors.top: oN.top;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png"
    }

    BaseText{
        anchors.left: oN.right;
        anchors.leftMargin: 107;
        anchors.top: oN.top;
        anchors.topMargin: 43
        text: qsTr("胎压显示");
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
