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
        onPressed: {
            c_qmlInterface.sendFccCAN('1-16-1-0-0-0-0');
            console.log("##### 外后视镜-左-向左 Pressed");
            c_qmlInterface.sendFccCAN('1-17-3-0-0-0-0');
        }
        onReleased:  {
            c_qmlInterface.sendFccCAN('1-16-0-0-0-0-0');
            console.log("##### 外后视镜-左-向左 Released");
            c_qmlInterface.sendFccCAN('1-17-0-0-0-0-0');
        }
        //onClicked: c_qmlInterface.sendFccCAN('2-15-205-0-0-0');
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
        onPressed: {
            c_qmlInterface.sendFccCAN('1-16-1-0-0-0-0');
            console.log("##### 外后视镜-左-向上 Pressed");
            c_qmlInterface.sendFccCAN('1-17-1-0-0-0-0');
        }
        onReleased:  {
            c_qmlInterface.sendFccCAN('1-16-0-0-0-0-0');
            console.log("##### 外后视镜-左-向上 Released");
            c_qmlInterface.sendFccCAN('1-17-0-0-0-0-0');
        }
        //onClicked: c_qmlInterface.sendFccCAN('2-15-197-0-0-0');
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
        onPressed: {
            c_qmlInterface.sendFccCAN('1-16-1-0-0-0-0');
            console.log("##### 外后视镜-左-向右 Pressed");
            c_qmlInterface.sendFccCAN('1-17-4-0-0-0-0');
        }
        onReleased:  {
            c_qmlInterface.sendFccCAN('1-16-0-0-0-0-0');
            console.log("##### 外后视镜-左-向右 Released");
            c_qmlInterface.sendFccCAN('1-17-0-0-0-0-0');
        }
        //onClicked: c_qmlInterface.sendFccCAN('2-15-209-0-0-0');
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
        onPressed: {
            c_qmlInterface.sendFccCAN('1-16-1-0-0-0-0');
            console.log("##### 外后视镜-左-向下 Pressed");
            c_qmlInterface.sendFccCAN('1-17-2-0-0-0-0');
        }
        onReleased:  {
            c_qmlInterface.sendFccCAN('1-16-0-0-0-0-0');
            console.log("##### 外后视镜-左-向下 Released");
            c_qmlInterface.sendFccCAN('1-17-0-0-0-0-0');
        }
        //onClicked: c_qmlInterface.sendFccCAN('2-15-201-0-0-0');
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
        onPressed: {
            c_qmlInterface.sendFccCAN('1-16-2-0-0-0-0');
            console.log("##### 外后视镜-右-向左 Pressed");
            c_qmlInterface.sendFccCAN('1-17-3-0-0-0-0');
        }
        onReleased:  {
            c_qmlInterface.sendFccCAN('1-16-0-0-0-0-0');
            console.log("##### 外后视镜-右-向左 Released");
            c_qmlInterface.sendFccCAN('1-17-0-0-0-0-0');
        }
        //onClicked: c_qmlInterface.sendFccCAN('2-15-206-0-0-0');
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
        onPressed: {
            c_qmlInterface.sendFccCAN('1-16-2-0-0-0-0');
            console.log("##### 外后视镜-右-向上 Pressed");
            c_qmlInterface.sendFccCAN('1-17-1-0-0-0-0');
        }
        onReleased:  {
            c_qmlInterface.sendFccCAN('1-16-0-0-0-0-0');
            console.log("##### 外后视镜-右-向上 Released");
            c_qmlInterface.sendFccCAN('1-17-0-0-0-0-0');
        }
        //onClicked: c_qmlInterface.sendFccCAN('2-15-198-0-0-0');
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
        onPressed: {
            c_qmlInterface.sendFccCAN('1-16-2-0-0-0-0');
            console.log("##### 外后视镜-右-向右 Pressed");
            c_qmlInterface.sendFccCAN('1-17-4-0-0-0-0');
        }
        onReleased:  {
            c_qmlInterface.sendFccCAN('1-16-0-0-0-0-0');
            console.log("##### 外后视镜-右-向右 Released");
            c_qmlInterface.sendFccCAN('1-17-0-0-0-0-0');
        }
        //onClicked: c_qmlInterface.sendFccCAN('2-15-210-0-0-0');
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
        onPressed: {
            c_qmlInterface.sendFccCAN('1-16-2-0-0-0-0');
            console.log("##### 外后视镜-右-向下 Pressed");
            c_qmlInterface.sendFccCAN('1-17-2-0-0-0-0');
        }
        onReleased:  {
            c_qmlInterface.sendFccCAN('1-16-0-0-0-0-0');
            console.log("##### 外后视镜-右-向下 Released");
            c_qmlInterface.sendFccCAN('1-17-0-0-0-0-0');
        }
        //onClicked: c_qmlInterface.sendFccCAN('2-15-202-0-0-0');
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
        onClicked: c_qmlInterface.sendFccCAN('1-18-1-0-0-0-0');
        //onClicked: c_qmlInterface.sendFccCAN('2-15-253-0-0-0');
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
        onClicked: c_qmlInterface.sendFccCAN('1-18-0-0-0-0-0');
        //onClicked: c_qmlInterface.sendFccCAN('2-15-221-0-0-0');
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
        onClicked: c_qmlInterface.sendFccCAN('1-21-1-0-0-0-0');
    }
    Image {
        width: 83;
        height: 58;
        anchors.verticalCenter: xhOpen.verticalCenter;
        anchors.left: xhOpen.right;
        anchors.leftMargin: 14;
        source: "qrc:/images/mirror/Set_hsj_xh.png"
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
        onClicked: c_qmlInterface.sendFccCAN('1-21-0-0-0-0-0');
    }


}
