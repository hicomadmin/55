import QtQuick 2.3

Item {
    anchors.fill: parent;
    property int hotLeftTxt: 0;
    property int hotRightTxt: 0;
    property int windLeftTxt: 0;
    property int windRightTxt: 0;


    Image {
        id: hotBG_l
        width: 110; height: 310;
        anchors.left: parent.left;
        anchors.leftMargin: 185;
        anchors.top: parent.top;
        anchors.topMargin: 325;
        source: "qrc:/images/hotWind/Set_Light_ld.png";
        BaseButton{
            id:hotAdd_l
            width: 110;  height: 110;
            anchors{left: parent.left; top: parent.top;}
            normalSource: "qrc:/images/effects/AC_Tem_leftAdd_nml.png";
            pressSource:  "qrc:/images/effects/AC_Tem_leftAdd_exe.png";
            onClicked: onjustmentBtnClicked(1);
        }
        BaseButton{
            id:hotSub_l
            width: 110;  height: 110;
            anchors{left: parent.left; bottom: parent.bottom;}
            normalSource: "qrc:/images/effects/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/effects/AC_Tem_leftSub_exe.png";
            onClicked: onjustmentBtnClicked(2);
        }
        BaseText{
            anchors.centerIn: parent;
            text: hotLeftTxt;
        }
    }

    Image {
        id: hotBG_r
        width: 110; height: 310;
        anchors{left: hotBG_l.right; leftMargin: 106; top: hotBG_l.top;}
        source: "qrc:/images/hotWind/Set_Light_ld.png";
        BaseButton{
            id:hotAdd_r
            width: 110;  height: 110;
            anchors{left: parent.left; top: parent.top;}
            normalSource: "qrc:/images/effects/AC_Tem_leftAdd_nml.png";
            pressSource:  "qrc:/images/effects/AC_Tem_leftAdd_exe.png";
            onClicked: onjustmentBtnClicked(3);
        }
        BaseButton{
            id:hotSub_r
            width: 110;  height: 110;
            anchors{left: parent.left; bottom: parent.bottom;}
            normalSource: "qrc:/images/effects/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/effects/AC_Tem_leftSub_exe.png";
            onClicked: onjustmentBtnClicked(4);
        }
        BaseText{
            anchors.centerIn: parent;
            text: hotRightTxt;
        }
    }


    Image {
        id: windBG_l
        width: 110; height: 310;
        anchors{left: hotBG_r.right; leftMargin: 251; top: hotBG_r.top;}
        source: "qrc:/images/hotWind/Set_Light_ld.png";
        BaseButton{
            id:windAdd_l
            width: 110;  height: 110;
            anchors{left: parent.left; top: parent.top;}
            normalSource: "qrc:/images/effects/AC_Tem_leftAdd_nml.png";
            pressSource:  "qrc:/images/effects/AC_Tem_leftAdd_exe.png";
            onClicked: onjustmentBtnClicked(5);
        }
        BaseButton{
            id:windSub_l
            width: 110;  height: 110;
            anchors{left: parent.left; bottom: parent.bottom;}
            normalSource: "qrc:/images/effects/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/effects/AC_Tem_leftSub_exe.png";
            onClicked: onjustmentBtnClicked(6);
        }
        BaseText{
            anchors.centerIn: parent;
            text: windLeftTxt;
        }
    }

    Image {
        id: windBG_r
        width: 110; height: 310;
        anchors{left: windBG_l.right; leftMargin: 106; top: windBG_l.top;}
        source: "qrc:/images/hotWind/Set_Light_ld.png";
        BaseButton{
            id:windAdd_r
            width: 110;  height: 110;
            anchors{left: parent.left; top: parent.top;}
            normalSource: "qrc:/images/effects/AC_Tem_leftAdd_nml.png";
            pressSource:  "qrc:/images/effects/AC_Tem_leftAdd_exe.png";
            onClicked: onjustmentBtnClicked(7);
        }
        BaseButton{
            id:windSub_r
            width: 110;  height: 110;
            anchors{left: parent.left; bottom: parent.bottom;}
            normalSource: "qrc:/images/effects/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/effects/AC_Tem_leftSub_exe.png";
            onClicked: onjustmentBtnClicked(8);
        }
        BaseText{
            anchors.centerIn: parent;
            text: windRightTxt;
        }
    }




    Image {
        id: hotIcon
        width: 64; height: 64;
        anchors{left:hotBG_l.right; leftMargin: 20; top:hotBG_l.top; topMargin: 100;}
        source: "qrc:/images/hotWind/ZY_jr.png";
    }

    Image {
        id: windIcon
        width: 64; height: 64;
        anchors{left:windBG_l.right; leftMargin: 20; top:windBG_l.top; topMargin: 100;}
        source: "qrc:/images/hotWind/ZY_tf.png";
    }

    BaseText{
        anchors{top: hotIcon.bottom; topMargin: 12; horizontalCenter: hotIcon.horizontalCenter;}
        text: qsTr("加热");
    }

    BaseText{
        anchors{top: windIcon.bottom; topMargin: 12; horizontalCenter: windIcon.horizontalCenter;}
        text: qsTr("通风");
    }
    BaseText{
        anchors{top: hotBG_l.bottom; topMargin: 13; horizontalCenter: hotBG_l.horizontalCenter;}
        text: qsTr("左");
    }
    BaseText{
        anchors{top: hotBG_r.bottom; topMargin: 13; horizontalCenter: hotBG_r.horizontalCenter;}
        text: qsTr("右");
    }
    BaseText{
        anchors{top: windBG_l.bottom; topMargin: 13; horizontalCenter: windBG_l.horizontalCenter;}
        text: qsTr("左");
    }
    BaseText{
        anchors{top: windBG_r.bottom; topMargin: 13; horizontalCenter: windBG_r.horizontalCenter;}
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



    function onjustmentBtnClicked(val)
    {
        switch(val)
        {
        case 1:
            hotLeftTxt += 1;
            break;
        case 2:
            hotLeftTxt -= 1;
            break;
        case 3:
            hotRightTxt += 1;
            break;
        case 4:
            hotRightTxt -= 1;
            break;
        case 5:
            windLeftTxt += 1;
            break;
        case 6:
            windLeftTxt -= 1;
            break;
        case 7:
            windRightTxt += 1;
            break;
        case 8:
            windRightTxt -= 1;
            break;
        default:
            break;
        }
    }

}
