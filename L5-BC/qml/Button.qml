import QtQuick 2.3

Item {
    id: button;
    focus: false;

    property int textsize: 32;
    property string btnText: "";
    property string normalIcon:"";
    property string pressIcon:"";
    signal pressed();
    signal clicked();

    Image {
        anchors.fill: parent;
        source: normalIcon;
        visible: !button.focus;
    }

    Image {
        anchors.fill: parent;
        source: pressIcon;
        visible: button.focus;
    }


    BaseText {
        id: txt;
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top;
        anchors.topMargin: 150;
        text: btnText;
        font.pixelSize: textsize;
        opacity: button.focus ? 1 : 0.8;
    }

    MouseArea  {
        anchors.fill: parent;

        onPressed: {
            button.focus = true;
            button.pressed();
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
        }
    }


    function onButtonPressed(x, y) {
        pressed();
    }
    function onButtonClicked(x, y) {
        clicked();
    }
}

