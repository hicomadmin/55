import QtQuick 2.3


Item {
    id:volumeProgressBar
    anchors.fill: parent;
    property int volText:0 //音量值

    Rectangle {
        id: mask;
        anchors.fill: parent;
        color: "#000000";
        opacity: 0.6;
        MouseArea{
            anchors.fill: parent;
            onClicked: volumeProgressBar.visible = false;
        }
    }

    Image{
        id: volSysBarPic;
        width: 598;
        height: 171;
        anchors.centerIn: parent
        source:  "qrc:/images/voice/yl_bg.png"
        MouseArea{
            anchors.fill: parent;
            onClicked: {}
        }
    }

    Image {
        id: icon;
        width: 60; height: 52;
        anchors.left: volSysBarPic.left;
        anchors.leftMargin: 18;
        anchors.top: volSysBarPic.top;
        anchors.topMargin: 56;
        source: "qrc:/images/voice/yl_icon_nml.png"
    }

    Item {
        id: volView
        anchors.left: icon.right;
        anchors.leftMargin: 22;
        anchors.verticalCenter: icon.verticalCenter;
        implicitWidth: 400
        implicitHeight: 60

        QtObject {
            id: arr
            property int currentVal: 0
            property int maxValue: 40
            property variant volArray: ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10',
                                        '11','12','13','14','15','16','17','18','19','20',
                                        '21','22','23','24','25','26','27','28','29','30',
                                        '31','32','33','34','35','36','37','38','39','40']
        }

        Binding {
            target: volumeProgressBar;
            property: "volText";
            value: arr.volArray[arr.currentVal]
        }

        Rectangle{
            id: volBg;
            width: 400;
            height: 6;
            radius: 2;
            color: "#767070";
            anchors.left: parent.left;
            anchors.verticalCenter: parent.verticalCenter
        }
        Rectangle {
            id: lftexe
            width: 4;
            height: 6;
            radius: 2;
            color: "#AF1414";
            anchors.left: volBg.left;
            anchors.verticalCenter: volBg.verticalCenter
        }
        Image {
            anchors.left: lftexe.left;
            anchors.leftMargin: 2;
            width: adjustBtn.x+30;
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/images/voice/ylt_exe.png"
        }

        BaseText{ //音量值获取
            anchors.left: parent.right;
            anchors.leftMargin: 26
            anchors.verticalCenter: volBg.verticalCenter;
            size: 34
            text: (arr.currentVal>=0&&arr.currentVal<=arr.maxValue)?arr.volArray[arr.currentVal]:"*"
        }



        Image {
            id: adjustBtn;
            width: 60; height: 60;
            anchors.verticalCenter: volBg.verticalCenter;
            source: "qrc:/images/voice/yl_dot.png"
            //x: volBg.x-30
            x: volBg.x-30 + ((volBg.width-volBg.x)/40)*volText

            MouseArea{//触控区域
                anchors.fill: parent
                drag{
                    target: adjustBtn
                    minimumX: volBg.x-30
                    maximumX: volBg.width-30
                    axis: Drag.XAxis
                }
                onReleased: {
                    c_qmlInterface.qmlDebug("##### onReleased 11111 arr.currentVal",arr.currentVal)
                    //arr.currentVal = Math.round((adjustBtn.x)/(volBg.width - adjustBtn.width + 10)*arr.maxValue);
                }

                onPositionChanged: {
                    c_qmlInterface.qmlDebug("##### #############################################")
                    c_qmlInterface.qmlDebug("##### onPositionChanged  arr.currentVal = ", arr.currentVal)
                    c_qmlInterface.qmlDebug("##### onPositionChanged  adjustBtn.x  = ", adjustBtn.x )
                    arr.currentVal = Math.round((adjustBtn.x+adjustBtn.width/2)/(volBg.width)*arr.maxValue);
                }
                onActiveFocusChanged: {
                }
            }
        }

    }

//    Timer{
//        id: volumeHideTimer;
//        interval: 3000;
//        running: true
//        onTriggered:volumeProgressBar.visible = false;
//    }

    function show()
    {
        volSysBarPic.state = "";
        volumeHideTimer.restart();
    }

    function hide()
    {
        volSysBarPic.state = "hide"
    }


    function setvolume(vol)
    {
        console.log("###### vol:", vol);
        volText = vol;
    }


}




