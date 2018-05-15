import QtQuick 2.0

Rectangle {
    id: playPage
    width: 1280;
    height: 720;

    signal quitPhoto();

    property string photoPath: "/usr/app/images/"
    property string photoName: "1.png"
    property bool bVision: true

    Component.onCompleted: {
//        timer_to_set_screen.start()
        showFullScreen()
    }

    Timer {
        id:timer_to_set_screen
        repeat: false
        interval: 3000
        onTriggered:
        {
            showFullScreen()
        }
    }


    Image {
        x:0
        y:0
        width: playPage.width
        height:playPage.height
        source:"file://" + photoPath + photoName
        fillMode: Image.Pad
        cache: false
    }

    MenuButton{
        id:prev;
        width: 250;
        height: 119;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 60;
        anchors.left: parent.left
        anchors.leftMargin: 200
        btnText: qsTr("下一张");
        visible: bVision
        normalSource: "qrc:/images/Menu_Icon_VR_nml.png";
        pressSource:  "qrc:/images/Menu_Icon_VR_exe.png";
        onClicked: {
            quitFullScreen()
            nextPage()
        }
    }

    MenuButton{
        id:next;
        width: 250;
        height: 119;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 60;
        anchors.right: parent.right
        anchors.rightMargin: 200
        visible: bVision
        btnText: qsTr("退出");
        normalSource: "qrc:/images/Menu_Icon_VR_nml.png";
        pressSource:  "qrc:/images/Menu_Icon_VR_exe.png";
        onClicked: {
            timer_to_set_screen.stop()
            quitPhoto()
        }
    }

    MouseArea{
        anchors.fill: parent
        visible: !bVision
        onClicked: {
            quitFullScreen()
        }
    }

    function showFullScreen()
    {
        bVision = false
        if(timer_to_set_screen.running)
            timer_to_set_screen.stop()
    }

    function quitFullScreen()
    {
        bVision = true
        timer_to_set_screen.restart()
    }

    function nextPage()
    {
        if(photoName == "1.png") {
            photoName = "2.png"
        } else {
            photoName = "1.png"
        }
    }
}
