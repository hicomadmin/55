import QtQuick 2.3

Item {
    anchors.fill: parent;


    BaseButton{
        id: off
        width: 171;  height: 110;
        btnText: qsTr("关闭");
        anchors{left: parent.left; leftMargin: 287; top: parent.top; topMargin: 431;}
        normalSource: "qrc:/images/coldWarm/Set_zr_nml.png";
        pressSource:  "qrc:/images/coldWarm/Set_zr_exe.png";
    }
    BaseButton{
        id: low
        width: 171;  height: 110;
        btnText: qsTr("低");
        anchors{left: off.right; leftMargin: 8; top:off.top;}
        normalSource: "qrc:/images/coldWarm/Set_zr_nml.png";
        pressSource:  "qrc:/images/coldWarm/Set_zr_exe.png";
    }

    BaseButton{
        id: middle
        width: 171;  height: 110;
        btnText: qsTr("中");
        anchors{left: low.right; leftMargin: 8; top:off.top;}
        normalSource: "qrc:/images/coldWarm/Set_zr_nml.png";
        pressSource:  "qrc:/images/coldWarm/Set_zr_exe.png";
    }

    BaseButton{
        width: 171;  height: 110;
        btnText: qsTr("高");
        anchors{left: middle.right; leftMargin: 8; top:off.top;}
        normalSource: "qrc:/images/coldWarm/Set_zr_nml.png";
        pressSource:  "qrc:/images/coldWarm/Set_zr_exe.png";
    }


    BaseText{
        anchors.left: off.left;
        anchors.leftMargin: 12;
        anchors.bottom: off.top;
        anchors.bottomMargin: 18;
        size: 28;
        text: qsTr("左娱乐屏亮度调节");
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
