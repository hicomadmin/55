import QtQuick 2.3

Item {
    anchors.fill: parent;


    Image {
        id: leftMedia
        width: 326;  height: 110;
        anchors{left: parent.left; leftMargin: 94; top: parent.top; topMargin: 431;}
        source: "qrc:/images/Set_Light_ld.png"
        BaseButton{
            width: 110;  height: 110;
            anchors.left: parent.left;
            normalSource: "qrc:/images/effects/AC_Tem_leftAdd_nml.png";
            pressSource:  "qrc:/images/effects/AC_Tem_leftAdd_exe.png";
        }
        BaseButton{
            width: 110;  height: 110;
            anchors.right: parent.right;
            normalSource: "qrc:/images/effects/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/effects/AC_Tem_leftSub_exe.png";
        }
        BaseText{
            anchors.centerIn: parent
            size: 28;
            text: "00";
        }
    }

    BaseText{
        anchors.left: leftMedia.left;
        anchors.leftMargin: 12;
        anchors.bottom: leftMedia.top;
        anchors.bottomMargin: 18;
        size: 28;
        text: qsTr("左娱乐屏亮度调节");
    }




    Image {
        id: middleCtrl
        width: 326;  height: 110;
        anchors{left: leftMedia.right; leftMargin: 56; top: leftMedia.top;}
        source: "qrc:/images/Set_Light_ld.png"
        BaseButton{
            width: 110;  height: 110;
            anchors.left: parent.left;
            normalSource: "qrc:/images/effects/AC_Tem_leftAdd_nml.png";
            pressSource:  "qrc:/images/effects/AC_Tem_leftAdd_exe.png";
        }
        BaseButton{
            width: 110;  height: 110;
            anchors.right: parent.right;
            normalSource: "qrc:/images/effects/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/effects/AC_Tem_leftSub_exe.png";
        }
        BaseText{
            anchors.centerIn: parent
            size: 28;
            text: "00";
        }
    }

    BaseText{
        anchors.left: middleCtrl.left;
        anchors.leftMargin: 12;
        anchors.bottom: middleCtrl.top;
        anchors.bottomMargin: 18;
        size: 28;
        text: qsTr("后中控屏亮度调节");
    }




    Image {
        id: rightMedia
        width: 326;  height: 110;
        anchors{left: middleCtrl.right; leftMargin: 56; top: leftMedia.top;}
        source: "qrc:/images/Set_Light_ld.png"
        BaseButton{
            width: 110;  height: 110;
            anchors.left: parent.left;
            normalSource: "qrc:/images/effects/AC_Tem_leftAdd_nml.png";
            pressSource:  "qrc:/images/effects/AC_Tem_leftAdd_exe.png";
        }
        BaseButton{
            width: 110;  height: 110;
            anchors.right: parent.right;
            normalSource: "qrc:/images/effects/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/effects/AC_Tem_leftSub_exe.png";
        }
        BaseText{
            anchors.centerIn: parent
            size: 28;
            text: "00";
        }
    }

    BaseText{
        anchors.left: rightMedia.left;
        anchors.leftMargin: 12;
        anchors.bottom: rightMedia.top;
        anchors.bottomMargin: 18;
        size: 28;
        text: qsTr("右娱乐屏亮度调节");
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
