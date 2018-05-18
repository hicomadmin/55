import QtQuick 2.3


Item {
    id: button;
    focus: false;

    property int textsize: 32
    property string btnText: "";
    property string normalIcon:"";
    property string pressIcon:"";
    signal pressed();
    signal clicked();

    Image {
        anchors.left: parent.left;
        anchors.leftMargin: 226;
        anchors.verticalCenter: parent.verticalCenter;
        source: normalIcon;
        visible: !button.focus;
    }

    Image {
        anchors.left: parent.left;
        anchors.leftMargin: 226;
        anchors.verticalCenter: parent.verticalCenter;
        source: pressIcon;
        visible: button.focus;
    }


    Image {
        id: normal;
        anchors.fill: parent;
        source: "qrc:/images/List_BG_nml.png";
        visible: !button.focus;
    }

    Image {
        id: press;
        anchors.fill: parent;
        source: "qrc:/images/List_BG_exe.png";
        visible: button.focus;
    }

    BaseText {
        anchors.left: parent.left;
        anchors.leftMargin: 338;
        anchors.verticalCenter: parent.verticalCenter;
        text: btnText;
        font.pixelSize: textsize;
        opacity: button.focus ? 1 : 0.8;
    }

    MouseArea  {
        anchors.fill: parent;

        onPressed: {
            button.focus = true;
            button.pressed();
            //onButtonPressed(mouse.x, mouse.y);
        }

        onExited: {
            button.focus = false;
        }

        onReleased: {
            button.focus = false;
        }

        onClicked: {
            button.focus = false;
            button.clicked();
            //onButtonClicked(mouse.x, mouse.y);
        }
    }


    function onButtonPressed(x, y) {
        pressed();
    }
    function onButtonClicked(x, y) {
        clicked();
    }
}

