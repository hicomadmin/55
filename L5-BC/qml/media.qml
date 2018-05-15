import QtQuick 2.3

Item {
    anchors.fill: parent



    Image {
        id: prvBtn
        focus: false;
        width: 264; height: 218;
        anchors{left: parent.left; leftMargin: 237; top: parent.top; topMargin: 374;}
        source: prvBtn.focus ? "qrc:/images/media/Media_Pre_exe.png":"qrc:/images/media/Media_Pre_nml.png";
        MouseArea  {
            anchors.left: parent.left;
            anchors.right: parent.right;
            anchors.rightMargin: 40;
            anchors.top: parent.top;
            anchors.bottom: parent.bottom;
            onPressed: {
                c_qmlInterface.sendRccCAN('1-48-0-0')
                prvBtn.focus = true;
            }
            onExited: prvBtn.focus = false;
            onReleased: {
                c_qmlInterface.sendRccCAN('1-0-0-0')
                prvBtn.focus = false;
            }
            onClicked: {
                prvBtn.focus = false;
                //leftBtn.clicked();
            }
        }
    }


    Image {
        id: nextBtn
        focus: false;
        width: 264; height: 218;
        anchors{left: prvBtn.right; leftMargin: 279; top: prvBtn.top;}
        source: nextBtn.focus ? "qrc:/images/media/Media_next_exe.png":"qrc:/images/media/Media_next_nml.png";
        MouseArea  {
            anchors.left: parent.left;
            anchors.leftMargin: 40;
            anchors.right: parent.right;
            anchors.top: parent.top;
            anchors.bottom: parent.bottom;
            onPressed: {
                c_qmlInterface.sendRccCAN('1-56-0-0')
                nextBtn.focus = true;
            }
            onExited: nextBtn.focus = false;
            onReleased: {
                c_qmlInterface.sendRccCAN('1-0-0-0')
                nextBtn.focus = false;
            }
            onClicked: {
                nextBtn.focus = false;
                //leftBtn.clicked();
            }
        }
    }



    Image {
        id: leftBtn
        width: 100;
        height: 200;
        focus: false;
        anchors{left: parent.left; leftMargin: 481; top: parent.top; topMargin: 381;}
        source: leftBtn.focus ? "qrc:/images/media/Media_Left_exe.png":"qrc:/images/media/Media_Left_nml.png";
        MouseArea  {
            anchors.left: parent.left;
            anchors.right: parent.right;
            anchors.rightMargin: 16;
            anchors.top: parent.top;
            anchors.topMargin: 30;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 30;
            onPressed: {
                c_qmlInterface.sendRccCAN('1-24-0-0')
                leftBtn.focus = true;
            }
            onExited: leftBtn.focus = false;
            onReleased: {
                c_qmlInterface.sendRccCAN('1-0-0-0')
                leftBtn.focus = false;
            }
            onClicked: {
                leftBtn.focus = false;
                //leftBtn.clicked();
            }
        }
    }



    Image {
        id: upBtn
        width: 200;
        height: 100;
        focus: false;
        anchors{left: parent.left; leftMargin: 542; top: parent.top; topMargin: 322;}
        source: upBtn.focus ? "qrc:/images/media/Media_up_exe.png":"qrc:/images/media/Media_up_nml.png";
        MouseArea  {
            anchors.left: parent.left;
            anchors.leftMargin: 30;
            anchors.right: parent.right;
            anchors.rightMargin: 30;
            anchors.top: parent.top;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 16;
            onPressed: {
                c_qmlInterface.sendRccCAN('1-8-0-0')
                upBtn.focus = true;
            }
            onExited: upBtn.focus = false;
            onReleased: {
                c_qmlInterface.sendRccCAN('1-0-0-0')
                upBtn.focus = false;
            }
            onClicked: {
                upBtn.focus = false;
                //upBtn.clicked();
            }
        }

    }



    Image {
        id: rightBtn
        focus: false;
        width: 100; height: 200;
        anchors{left: leftBtn.right; leftMargin: 118; top: leftBtn.top;}
        source: rightBtn.focus ? "qrc:/images/media/Media_right_exe.png":"qrc:/images/media/Media_right_nml.png";
        MouseArea  {
            anchors.left: parent.left;
            anchors.leftMargin: 16;
            anchors.right: parent.right;
            anchors.top: parent.top;
            anchors.topMargin: 30;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 30;
            onPressed: {
                c_qmlInterface.sendRccCAN('1-32-0-0')
                rightBtn.focus = true;
            }
            onExited:  rightBtn.focus = false;
            onReleased:{
                c_qmlInterface.sendRccCAN('1-0-0-0')
                rightBtn.focus = false;
            }
            onClicked: {
                rightBtn.focus = false;
                //leftBtn.clicked();
            }
        }
    }

    Image {
        id: downBtn
        focus: false;
        width: 200; height: 100;
        anchors{left: upBtn.left; top: upBtn.bottom; topMargin: 117;}
        source: downBtn.focus ? "qrc:/images/media/Media_dn_exe.png":"qrc:/images/media/Media_dn_nml.png";
        MouseArea  {
            anchors.left: parent.left;
            anchors.leftMargin: 16;
            anchors.right: parent.right;
            anchors.top: parent.top;
            anchors.topMargin: 30;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 30;
            onPressed: {
                c_qmlInterface.sendRccCAN('1-16-0-0')
                downBtn.focus = true;
            }
            onExited:  downBtn.focus = false;
            onReleased:{
                c_qmlInterface.sendRccCAN('1-0-0-0')
                downBtn.focus = false;
            }
            onClicked: {
                downBtn.focus = false;
                //leftBtn.clicked();
            }
        }
    }




    Image {
        id: okBtn
        focus: false;
        width: 140; height: 140;
        anchors{left: parent.left; leftMargin: 570; top: parent.top; topMargin: 411;}
        source: okBtn.focus ? "qrc:/images/media/Media_OK_exe.png":"qrc:/images/media/Media_OK_nml.png";
        BaseText{
            anchors.centerIn: parent;
            text: "OK";
        }
    }

    Rectangle{
        width: 116; height: 116;
        anchors.left: parent.left;
        anchors.leftMargin: 582;
        anchors.top: parent.top;
        anchors.topMargin: 422;
        radius: 58;
        color: "transparent";
        MouseArea  {
            anchors.fill: parent
            onPressed: {
                c_qmlInterface.sendRccCAN('1-40-0-0')
                okBtn.focus = true;
            }
            onExited:  okBtn.focus = false;
            onReleased:{
                c_qmlInterface.sendRccCAN('1-0-0-0')
                okBtn.focus = false;
            }
            onClicked: {
                okBtn.focus = false;
                //leftBtn.clicked();
            }
        }
    }


}
