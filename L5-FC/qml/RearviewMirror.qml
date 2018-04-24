import QtQuick 2.3

Item {
    anchors.fill: parent;

    BaseButton{
        id:left_l
        width: 110;
        height: 110;
        anchors.left: parent.left;
        anchors.leftMargin: 492;
        anchors.top: parent.top;
        anchors.topMargin: 192;
        normalSource:"qrc:/images/mirror/AC_Tem_nml.png"
        pressSource: "qrc:/images/mirror/AC_Tem_exe.png"
        Image {
            width: 82;
            height: 82;
            anchors.centerIn: parent;
            source: "qrc:/images/mirror/AC_icon_left.png"
        }
    }

    BaseButton{
        id:up_l
        width: 110;
        height: 110;
        anchors.left: parent.left;
        anchors.leftMargin: 600;
        anchors.top: parent.top;
        anchors.topMargin: 95;
        normalSource:"qrc:/images/mirror/AC_Tem_nml.png"
        pressSource: "qrc:/images/mirror/AC_Tem_exe.png"
        Image {
            width: 82;
            height: 82;
            anchors.centerIn: parent;
            source: "qrc:/images/mirror/AC_icon_up.png"
        }
    }

    BaseButton{
        id:right_l
        width: 110;
        height: 110;
        anchors.left: left_l.right;
        anchors.leftMargin: 106;
        anchors.top: left_l.top;
        normalSource:"qrc:/images/mirror/AC_Tem_nml.png"
        pressSource: "qrc:/images/mirror/AC_Tem_exe.png"
        Image {
            width: 82;
            height: 82;
            anchors.centerIn: parent;
            source: "qrc:/images/mirror/AC_icon_right.png"
        }
    }

    BaseButton{
        id:down_l
        width: 110;
        height: 110;
        anchors.left: up_l.left;
        anchors.top: up_l.bottom;
        anchors.topMargin: 84;
        normalSource:"qrc:/images/mirror/AC_Tem_nml.png"
        pressSource: "qrc:/images/mirror/AC_Tem_exe.png"
        Image {
            width: 82;
            height: 82;
            anchors.centerIn: parent;
            source: "qrc:/images/mirror/AC_icon_dn.png"
        }
    }

    Image {
        id: left
        width: 80;
        height: 56;
        anchors.left: left_l.right;
        anchors.leftMargin: 13;
        anchors.top: up_l.bottom;
        anchors.topMargin: 13;
        source: "qrc:/images/mirror/Set_hsj_left.png"
        BaseText{
            anchors.centerIn: parent;
            text: qsTr("左")
        }
    }


    ///

    BaseButton{
        id:left_r
        width: 110;
        height: 110;
        anchors.left: right_l.right;
        anchors.leftMargin: 41;
        anchors.top: right_l.top;
        normalSource:"qrc:/images/mirror/AC_Tem_nml.png"
        pressSource: "qrc:/images/mirror/AC_Tem_exe.png"
        Image {
            width: 82;
            height: 82;
            anchors.centerIn: parent;
            source: "qrc:/images/mirror/AC_icon_left.png"
        }
    }

    BaseButton{
        id:up_r
        width: 110;
        height: 110;
        anchors.left: left_r.left;
        anchors.leftMargin: 108;
        anchors.top: up_l.top;
        normalSource:"qrc:/images/mirror/AC_Tem_nml.png"
        pressSource: "qrc:/images/mirror/AC_Tem_exe.png"
        Image {
            width: 82;
            height: 82;
            anchors.centerIn: parent;
            source: "qrc:/images/mirror/AC_icon_up.png"
        }
    }

    BaseButton{
        width: 110;
        height: 110;
        anchors.left: left_r.right;
        anchors.leftMargin: 106;
        anchors.top: left_r.top;
        normalSource:"qrc:/images/mirror/AC_Tem_nml.png"
        pressSource: "qrc:/images/mirror/AC_Tem_exe.png"
        Image {
            width: 82;
            height: 82;
            anchors.centerIn: parent;
            source: "qrc:/images/mirror/AC_icon_right.png"
        }
    }

    BaseButton{
        width: 110;
        height: 110;
        anchors.left: up_r.left;
        anchors.top: up_r.bottom;
        anchors.topMargin: 84;
        normalSource:"qrc:/images/mirror/AC_Tem_nml.png"
        pressSource: "qrc:/images/mirror/AC_Tem_exe.png"
        Image {
            width: 82;
            height: 82;
            anchors.centerIn: parent;
            source: "qrc:/images/mirror/AC_icon_dn.png"
        }
    }

    Image {
        id: right
        width: 80;
        height: 56;
        anchors.left: left_r.right;
        anchors.leftMargin: 13;
        anchors.top: up_r.bottom;
        anchors.topMargin: 13;
        source: "qrc:/images/mirror/Set_hsj_right.png"
        BaseText{
            anchors{left: parent.left; leftMargin: 31}
            text: qsTr("右")
        }
    }


    Image {
        id: name
        anchors.top:down_l.bottom;
        anchors.topMargin: 57;
        anchors.left: left_l.left;
        source: "qrc:/images/mirror/Set_Light_fgt.png"
    }


    BaseButton{
        id: hotOpen;
        width: 110;
        height: 110;
        anchors.top:down_l.bottom;
        anchors.topMargin: 115;
        anchors.left: left_l.left;
        btnText: qsTr("开");
        normalSource:"qrc:/images/light/Set_Light_off_nml.png"
        pressSource: "qrc:/images/light/Set_Light_off_exe.png"
    }
    Image {
        width: 80;
        height: 61;
        anchors.verticalCenter: hotOpen.verticalCenter;
        anchors.left: hotOpen.right;
        anchors.leftMargin: 15;
        source: "qrc:/images/mirror/Set_hsj_hot.png"
    }

    BaseButton{
        id:hotClose
        width: 110;
        height: 110;
        anchors.top:hotOpen.top;
        anchors.left: hotOpen.right;
        anchors.leftMargin: 106;
        btnText: qsTr("关");
        normalSource:"qrc:/images/light/Set_Light_off_nml.png"
        pressSource: "qrc:/images/light/Set_Light_off_exe.png"
    }



    BaseButton{
        id: xhOpen;
        width: 110;
        height: 110;
        anchors.top:hotClose.top
        anchors.left: hotClose.right;
        anchors.leftMargin: 41;
        btnText: qsTr("开");
        normalSource:"qrc:/images/light/Set_Light_off_nml.png"
        pressSource: "qrc:/images/light/Set_Light_off_exe.png"
    }
    Image {
        width: 80;
        height: 61;
        anchors.verticalCenter: xhOpen.verticalCenter;
        anchors.left: xhOpen.right;
        anchors.leftMargin: 15;
        source: "qrc:/images/mirror/Set_hsj_hot.png"
    }

    BaseButton{
        width: 110;
        height: 110;
        anchors.top:hotOpen.top;
        anchors.left: xhOpen.right;
        anchors.leftMargin: 106;
        btnText: qsTr("关");
        normalSource:"qrc:/images/light/Set_Light_off_nml.png"
        pressSource: "qrc:/images/light/Set_Light_off_exe.png"
    }


}
