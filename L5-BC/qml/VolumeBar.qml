import QtQuick 2.3


Item {
    id:volumeProgressBar
    anchors.fill: parent;
    property int volText //音量值

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
            x: volBg.x-30

            MouseArea{//触控区域
                anchors.fill: parent
                drag{
                    target: adjustBtn
                    minimumX: volBg.x-30
                    maximumX: volBg.width-30
                    axis: Drag.XAxis
                }
                onReleased: {
                    console.log("##### onReleased 11111 arr.currentVal",arr.currentVal)
                    //arr.currentVal = Math.round((adjustBtn.x)/(volBg.width - adjustBtn.width + 10)*arr.maxValue);
                }

                onPositionChanged: {
                    console.log("##### #############################################")
                    console.log("##### onPositionChanged  arr.currentVal = ", arr.currentVal)
                    console.log("##### onPositionChanged  adjustBtn.x  = ", adjustBtn.x )
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


}















/*
Item {
    id:volumeProgressBar
    anchors.fill: parent;


    Rectangle {
        id: mask;
        anchors.fill: parent;
        color: "#000000";
        opacity: 0.6;
    }

    Image{
        id: volSysBarPic;
        width: 598;
        height: 171;
        anchors.centerIn: parent
        source:  "qrc:/images/voice/yl_bg.png"
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


    property int volText //音量值
    Item {
        id: volView
        anchors.left: icon.right;
        anchors.leftMargin: 12;
        anchors.verticalCenter: icon.verticalCenter;
        implicitWidth: 410
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
            width: 410;
            height: 6;
            radius: 2;
            color: "#767070";
            anchors.left: parent.left;
            anchors.verticalCenter: parent.verticalCenter
        }



        Text{
            id: headText
            font.pixelSize: 10
            text: "0"
            color: "#349adf"
            visible: true
            anchors{right: parent.left;verticalCenter: parent.verticalCenter}

        }

        Text{
            font.pixelSize: 10
            text: "40"
            color: "#349adf"
            visible: true;
            anchors{right: parent.right;verticalCenter: parent.verticalCenter}
        }

        MouseArea{
            anchors.fill: parent
            onPressed: {
                console.log(" ### mouse.x = ", mouse.x);
                console.log(" ### headText.width + (adjustBtn.width / 2) = ", headText.width + (adjustBtn.width / 2));
                if(mouse.x < headText.width + (adjustBtn.width / 2)){
                    arr.currentVal = 0;
                }else if(mouse.x > (headText.width + volBg.width - adjustBtn.width / 2)){
                    arr.currentVal = arr.maxValue;
                }else{
                    arr.currentVal = Math.round((mouse.x - headText.width - adjustBtn.width/2)/(volBg.width - adjustBtn.width + 10)*arr.maxValue);
                }
                adjustBtn.x = arr.currentVal *((volBg.width - adjustBtn.width + 10)/arr.maxValue) + headText.width;
            }
        }


        Image {
            id: adjustBtn;
            width: 60; height: 60;
            anchors.verticalCenter: volBg.verticalCenter;
            source: "qrc:/images/voice/yl_dot.png"

            x: headText.width

            Text{ //音量值获取
                anchors.centerIn: parent
                font.pixelSize: 25
                color:  "#000000"//"transparent";
                text: (arr.currentVal>=0&&arr.currentVal<=arr.maxValue)?arr.volArray[arr.currentVal]:"*"
            }

            MouseArea{//触控区域
                anchors.fill: parent
                drag{
                    target: adjustBtn
                    minimumX: headText.x-10
                    maximumX: volBg.width - adjustBtn.width + 10 + headText.width
                    axis: Drag.XAxis
                }
                onReleased: {
                    console.log("##### onReleased 11111")
                    arr.currentVal = Math.round((adjustBtn.x - headText.width)/(volBg.width - adjustBtn.width + 10)*arr.maxValue);
                }

                onPositionChanged: {
                    console.log("##### #############################################")
                    console.log("##### onPositionChanged  arr.currentVal = ", arr.currentVal)
                    console.log("##### onPositionChanged  adjustBtn.x  = ", adjustBtn.x )
                    console.log("##### onPositionChanged  headText.width  = ", headText.width )
                    console.log("##### onPositionChanged   = ", (adjustBtn.x - headText.width)/(volBg.width - adjustBtn.width + 10)*arr.maxValue )
                    arr.currentVal = Math.round((adjustBtn.x - headText.width)/(volBg.width - adjustBtn.width + 10)*arr.maxValue);
                }

            }
        }

    }


}


*/

/*

Item {
    id:volumeProgressBar
    anchors.fill: parent;
    property int volumeValue: 15;
    property int volumeMax: 30;

    Rectangle {
        anchors.fill: parent;

        color: "#000000";
        opacity: 0.6;
    }



    MouseArea{
        anchors.fill: parent
        onClicked: {
            //volSysBarPic.state = "hide"
        }
    }

    function show()
    {
        volSysBarPic.state = "";
        volumeHideTimer.restart();
    }

    function hide()
    {
        volSysBarPic.state = "hide"
    }

    Image{
        id: volSysBarPic;
        width: 598;
        height: 171;
        anchors.centerIn: parent
        source:  "qrc:/images/voice/yl_bg.png"
        visible:0 !== opacity
        state:"hide"
        Image {
            id: icon;
            width: 60; height: 52;
            anchors.left: volSysBarPic.left;
            anchors.leftMargin: 18;
            anchors.top: volSysBarPic.top;
            anchors.topMargin: 56;
            source: "qrc:/images/voice/yl_icon_nml.png"
        }

        Rectangle{
            id: volBg;
            width: 410;
            height: 6;
            radius: 2;
            color: "#767070";
            anchors.left: icon.right;
            anchors.leftMargin: 12;
            anchors.verticalCenter: icon.verticalCenter
        }


        Image {
            id: adjustBtn;
            width: 60; height: 60;
            x:80;
            anchors.verticalCenter: volBg.verticalCenter;
            source: "qrc:/images/voice/yl_dot.png"
            Drag.active: dragArea.drag.active
            Drag.dragType: Drag.Automatic
            Drag.supportedActions: Qt.CopdyAction
            MouseArea {
                id: dragArea
                anchors.fill: parent

                drag.target: parent
                onPressed: {
                    adjustBtn.x = mouse.x+60;
                }
            }
        }

        MouseArea{
            anchors.fill: volBg
            onClicked: {
                console.log(" ######onClicked mouse.x = ", mouse.x);
                adjustBtn.x = mouse.x+60;
            }

        }

//        MouseArea{
//            anchors.fill: adjustBtn
//            onPressed: {
//                console.log(" ######onPressed mouse.x = ", mouse.x);
//                if((mouse.x > 25)&&(mouse.x < adjustBtn.x+410)){
//                    console.log(" ######onPressed mouse.x = ", mouse.x);
//                    adjustBtn.x = mouse.x+60;
//                }
//            }

//        }

//        Rectangle{
//            id: barLength
//            anchors.left: icon.right;
//            anchors.leftMargin: 12;
//            anchors.verticalCenter: parent.verticalCenter;
//            height: 6
//            width: (550/volumeMax)*volumeValue
//            color: "#00fffc"
//        }

        BaseText{
            anchors.right: parent.right;
            anchors.rightMargin: 45
            anchors.verticalCenter: parent.verticalCenter
            color: "#ffffff"
            text: volumeValue
        }

        states: State{
            name: "hide"
            PropertyChanges {
                target: volSysBarPic
                opacity:0
            }
        }

    }




    Timer{
        id: volumeHideTimer;
        interval: 3000;
        running: true
        //onTriggered:volSysBarPic.state = "hide";
    }

}



*/
