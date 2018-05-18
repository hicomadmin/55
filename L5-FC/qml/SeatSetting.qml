import QtQuick 2.3

Item {
    anchors.fill: parent;
    property int hotText_l: 2;
    property int hotText_r: 2;
    property int windText_l: 2;
    property int windText_r: 2;

    BaseText{
        anchors{right: hotBtnBg.left; rightMargin: 13;}
        anchors.verticalCenter: hotBtnBg.verticalCenter;
        text: qsTr("左");
    }

    BaseText{
        anchors{right: hotBtnBg.left; rightMargin: 13;}
        anchors.verticalCenter: hotBtnBg_r.verticalCenter;
        text: qsTr("右");
    }

    BaseText{
        anchors{right: tfBtnBg.left; rightMargin: 13;}
        anchors.verticalCenter: tfBtnBg.verticalCenter;
        text: qsTr("左");
    }

    BaseText{
        anchors{right: tfBtnBg_r.left; rightMargin: 13;}
        anchors.verticalCenter: tfBtnBg_r.verticalCenter;
        text: qsTr("右");
    }

    Image {
        id: hotIcon;
        width: 64; height: 64;
        anchors{left: parent.left; leftMargin: 599;}
        anchors{top:parent.top; topMargin: 122;}
        source: "qrc:/images/chair/ZY_jr.png.png"
    }
    BaseText{
        anchors{top: parent.top; topMargin: 188;}
        anchors.horizontalCenter: hotIcon.horizontalCenter;
        text: qsTr("加热");
        size: 28;
    }

    Image {
        id:tfIcon
        width: 64; height: 64;
        anchors{left: hotIcon.right; leftMargin: 367;}
        anchors.top:hotIcon.top;
        source: "qrc:/images/chair/ZY_tf.png.png"
    }
    BaseText{
        anchors{top: parent.top; topMargin: 188;}
        anchors.horizontalCenter: tfIcon.horizontalCenter;
        text: qsTr("通风");
        size: 28;
    }

    Image {
        id: hotBtnBg
        width: 326; height: 110;
        anchors{left: parent.left; leftMargin: 467;}
        anchors{top: hotIcon.bottom; topMargin: 45;}
        source: "qrc:/images/light/Set_Light_ld.png"

        BaseButton {
            width: 110; height: 110;
            anchors.left: parent.left;
            normalSource: "qrc:/images/AC_Tem_leftAdd_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftAdd_exe.png";
            onPressed: onJustmentBtnMouseEvent(1);
            onReleased: c_qmlInterface.sendFccCAN('1-12-0-0-0-0-0');
        }

        BaseButton {
            width: 110; height: 110;
            anchors.right: parent.right;
            normalSource: "qrc:/images/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftSub_exe.png";
            onPressed: onJustmentBtnMouseEvent(2);
            onReleased: c_qmlInterface.sendFccCAN('1-12-0-0-0-0-0');
        }
        BaseText{
            anchors.centerIn: parent;
            size: 28;
            text: hotText_l;
        }
    }


    Image {
        id: tfBtnBg
        width: 326; height: 110;
        anchors{left: hotBtnBg.right; leftMargin: 105; top: hotBtnBg.top;}
        source: "qrc:/images/light/Set_Light_ld.png"

        BaseButton {
            width: 110; height: 110;
            anchors.left: parent.left;
            normalSource: "qrc:/images/AC_Tem_leftAdd_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftAdd_exe.png";
            onPressed: onJustmentBtnMouseEvent(3);
            onReleased: c_qmlInterface.sendFccCAN('1-14-0-0-0-0-0');
        }

        BaseButton {
            width: 110; height: 110;
            anchors.right: parent.right;
            normalSource: "qrc:/images/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftSub_exe.png";
            onPressed: onJustmentBtnMouseEvent(4);
            onReleased: c_qmlInterface.sendFccCAN('1-14-0-0-0-0-0');
        }
        BaseText{
            anchors.centerIn: parent;
            size: 28;
            text: windText_l;
        }
    }


    // right hot
    Image {
        id: hotBtnBg_r
        width: 326; height: 110;
        anchors{left: hotBtnBg.left; top: hotBtnBg.bottom; topMargin: 80;}
        source: "qrc:/images/light/Set_Light_ld.png"
        BaseButton {
            width: 110; height: 110;
            anchors.left: parent.left;
            normalSource: "qrc:/images/AC_Tem_leftAdd_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftAdd_exe.png"
            onPressed: onJustmentBtnMouseEvent(5);
            onReleased: c_qmlInterface.sendFccCAN('1-13-0-0-0-0-0');
        }

        BaseButton {
            width: 110; height: 110;
            anchors.right: parent.right;
            normalSource: "qrc:/images/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftSub_exe.png";
            onPressed: onJustmentBtnMouseEvent(6);
            onReleased: c_qmlInterface.sendFccCAN('1-13-0-0-0-0-0');
        }
        BaseText{
            anchors.centerIn: parent;
            size: 28;
            text: hotText_r;
        }
    }

    // right wind
    Image {
        id: tfBtnBg_r
        width: 326; height: 110;
        anchors{left: hotBtnBg_r.right; leftMargin: 105; top: hotBtnBg_r.top;}
        source: "qrc:/images/light/Set_Light_ld.png"

        BaseButton {
            width: 110; height: 110;
            anchors.left: parent.left;
            normalSource: "qrc:/images/AC_Tem_leftAdd_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftAdd_exe.png";
            onPressed: onJustmentBtnMouseEvent(7);
            onReleased: c_qmlInterface.sendFccCAN('1-15-0-0-0-0-0');
        }

        BaseButton {
            width: 110; height: 110;
            anchors.right: parent.right;
            normalSource: "qrc:/images/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftSub_exe.png";
            onClicked: onJustmentBtnMouseEvent(8);
            onReleased: c_qmlInterface.sendFccCAN('1-15-0-0-0-0-0');
        }
        BaseText{
            anchors.centerIn: parent;
            size: 28;
            text: windText_r
        }
    }


    function onJustmentBtnMouseEvent(val)
    {
        var tmp;
        var strData;
        switch(val)
        {
        case 1:
            if(hotText_l < 5){
                tmp = hotText_l +1;
                hotText_l = tmp;
                strData = "1-12-" + hotText_l +"-0-0-0-0";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        case 2:
            if(hotText_l > 1){
                tmp = hotText_l -1;
                hotText_l = tmp;
                strData = "1-12-" + hotText_l +"-0-0-0-0";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        case 3:
            if(windText_l < 3){
                tmp = windText_l +1;
                windText_l = tmp;
                strData = "1-14-" + windText_l + "-0-0-0-0";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        case 4:
            if(windText_l > 1){
                tmp = windText_l -1;
                windText_l = tmp;
                strData = "1-14-" + windText_l + "-0-0-0-0";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        case 5:
            if(hotText_r < 5){
                tmp = hotText_r +1;
                hotText_r = tmp;
                strData = "1-13-" + hotText_r + "-0-0-0-0";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        case 6:
            if(hotText_r > 1){
                tmp = hotText_r -1;
                hotText_r = tmp;
                strData = "1-13-" + hotText_r + "-0-0-0-0";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        case 7:
            if(windText_r < 3){
                tmp = windText_r +1;
                windText_r = tmp;
                strData = "1-15-" + windText_r + "-0-0-0-0";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        case 8:
            if(windText_r > 1){
                tmp = windText_r -1;
                windText_r = tmp;
                strData = "1-15-" + windText_r + "-0-0-0-0";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        default:
            break;
        }
    }

}
