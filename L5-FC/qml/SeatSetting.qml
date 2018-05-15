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
            pressSource:  "qrc:/images/AC_Tem_leftAdd_exe.png"
            onClicked: onJustmentBtnClicked(1);
        }

        BaseButton {
            width: 110; height: 110;
            anchors.right: parent.right;
            normalSource: "qrc:/images/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftSub_exe.png";
            onClicked: onJustmentBtnClicked(2);
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
            pressSource:  "qrc:/images/AC_Tem_leftAdd_exe.png"
            onClicked: onJustmentBtnClicked(3);
        }

        BaseButton {
            width: 110; height: 110;
            anchors.right: parent.right;
            normalSource: "qrc:/images/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftSub_exe.png";
            onClicked: onJustmentBtnClicked(4);
        }
        BaseText{
            anchors.centerIn: parent;
            size: 28;
            text: windText_l;
        }
    }


    // 2
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
            onClicked: onJustmentBtnClicked(5);
        }

        BaseButton {
            width: 110; height: 110;
            anchors.right: parent.right;
            normalSource: "qrc:/images/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftSub_exe.png";
            onClicked: onJustmentBtnClicked(6);
        }
        BaseText{
            anchors.centerIn: parent;
            size: 28;
            text: hotText_r;
        }
    }


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
            onClicked: onJustmentBtnClicked(7);
        }

        BaseButton {
            width: 110; height: 110;
            anchors.right: parent.right;
            normalSource: "qrc:/images/AC_Tem_leftSub_nml.png";
            pressSource:  "qrc:/images/AC_Tem_leftSub_exe.png";
            onClicked: onJustmentBtnClicked(8);
        }
        BaseText{
            anchors.centerIn: parent;
            size: 28;
            text: windText_r
        }
    }


    function onJustmentBtnClicked(val)
    {
        var tmp;
        var strData;
        switch(val)
        {
        case 1:
            if(hotText_l < 5){
                tmp = hotText_l +1;
                hotText_l = tmp;
                tmp = 65 + hotText_l;
                strData = "1-0-0-192-24-" + tmp + "-192";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        case 2:
            if(hotText_l > 0){
                tmp = hotText_l -1;
                hotText_l = tmp;
                tmp = 65 + hotText_l;
                strData = "1-0-0-192-24-" + tmp + "-192";
                c_qmlInterface.sendFccCAN(strData);
            }
            break;
        case 3:
            if(windText_l < 3){
                tmp = windText_l +1;
                windText_l = tmp;
                windLeft(tmp);
            }
            break;
        case 4:
            if(windText_l > 0){
                tmp = windText_l -1;
                windText_l = tmp;
                windLeft(tmp);
            }
            break;
        case 5:
            if(hotText_r < 5){
                tmp = hotText_r +1;
                hotText_r = tmp;
                hotRight(tmp);
            }
            break;
        case 6:
            if(hotText_r > 0){
                tmp = hotText_r -1;
                hotText_r = tmp;
                hotRight(tmp);
            }
            break;
        case 7:
            if(windText_r < 3){
                tmp = windText_r +1;
                windText_r = tmp;
                windRight(tmp);
            }
            break;
        case 8:
            if(windText_r > 0){
                tmp = windText_r -1;
                windText_r = tmp;
                windRight(tmp);
            }
            break;
        default:
            break;
        }
    }

    function hotRight(level)
    {
        switch(level)
        {
        case 1:
            c_qmlInterface.sendFccCAN('1-0-0-192-24-15-192');
            break;
        case 2:
            c_qmlInterface.sendFccCAN('1-0-0-192-24-23-192');
            break;
        case 3:
            c_qmlInterface.sendFccCAN('1-0-0-192-24-31-192');
            break;
        case 4:
            c_qmlInterface.sendFccCAN('1-0-0-192-24-39-192');
            break;
        case 5:
            c_qmlInterface.sendFccCAN('1-0-0-192-24-47-192');
            break;
        default:
            break;
        }
    }

    function windLeft(level)
    {
        switch(level)
        {
        case 1:
            c_qmlInterface.sendFccCAN('1-0-0-192-24-127-192');
            break;
        case 2:
            c_qmlInterface.sendFccCAN('1-0-0-192-24-191-192');
            break;
        case 3:
            c_qmlInterface.sendFccCAN('1-0-0-192-24-255-192');
            break;
        default:
            break;
        }
    }

    function windRight(level)
    {
        switch(level)
        {
        case 1:
            c_qmlInterface.sendFccCAN('1-0-0-192-23-63-193');
            break;
        case 2:
            c_qmlInterface.sendFccCAN('1-0-0-192-23-63-194');
            break;
        case 3:
            c_qmlInterface.sendFccCAN('1-0-0-192-23-63-195');
            break;
        default:
            break;
        }
    }

}
