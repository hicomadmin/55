import QtQuick 2.3

Item {
    anchors.fill: parent;

    MenuButton{
        id:chirismusON_l
        width: 110;  height: 110;
        anchors{left: parent.left; leftMargin: 185;}
        anchors{top: parent.top; topMargin: 425;}
        topMag: 41;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
    }


    MenuButton{
        id:chirismusOFF_l
        width: 110;  height: 110;
        anchors{left: chirismusON_l.right; leftMargin: 106; top: chirismusON_l.top;}
        topMag: 41;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
    }



    MenuButton{
        id:chirismusON_r
        width: 110;  height: 110;
        anchors{left: chirismusOFF_l.right; leftMargin: 251; top: chirismusON_l.top;}
        topMag: 41;
        btnText: qsTr("开");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
    }


    MenuButton{
        id:chirismusOFF_r
        width: 110;  height: 110;
        anchors{left: chirismusON_r.right; leftMargin: 106; top: chirismusON_l.top;}
        topMag: 41;
        btnText: qsTr("关");
        normalSource: "qrc:/images/light/Set_Light_off_nml.png";
        pressSource:  "qrc:/images/light/Set_Light_off_exe.png";
    }


    BaseText{
        anchors{left: chirismusON_l.left; leftMargin: 12; bottom: chirismusON_l.top; topMargin: 18;}
        text: qsTr("左座椅按摩");
    }

    BaseText{
        anchors{left:chirismusON_r.left; leftMargin:12; bottom: chirismusON_r.top; topMargin:18;}
        text: qsTr("右座椅按摩");
    }

    Image {
        id: chirismusIcon_l
        width: 64; height: 64;
        anchors{left:chirismusON_l.right; leftMargin: 24; top:chirismusON_l.top;}
        source: "qrc:/images/chair/Set_icon_am_left.png";
    }

    Image {
        id: chirismusIcon_r
        width: 64; height: 64;
        anchors{left:chirismusON_r.right; leftMargin: 24; top:chirismusON_r.top;}
        source: "qrc:/images/chair/Set_icon_am_left.png";
    }

    BaseText{
        anchors{bottom: chirismusON_l.bottom; bottomMargin: 8; horizontalCenter: chirismusIcon_l.horizontalCenter;}
        text: qsTr("左");
    }

    BaseText{
        anchors{bottom: chirismusON_l.bottom; bottomMargin: 8; horizontalCenter: chirismusIcon_r.horizontalCenter;}
        text: qsTr("右");
    }


    Image {
        width: 1; height: 446;
        anchors.left: parent.left;
        anchors.leftMargin: 640;
        anchors.top: parent.top;
        anchors.topMargin:274;
        source: "qrc:/images/chair/Set_amList_SeparatorLine.png"
    }



    function onAdjustmentBtnClicked(val)
    {
        switch(val)
        {
        case 10:
            break;
        case 11:
            break;
        default:
            break;
        }
    }

}
