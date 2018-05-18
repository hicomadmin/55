import QtQuick 2.3


Item {
    id: button;
    focus: false;

    property int textsize: 32
    property string btnText: "";
    property string normalSource:"";
    property string pressSource:"";
    signal pressed();
    signal clicked();
    signal released();
    signal pressAndHold();

    Image {
        anchors.fill: parent
        source: normalSource;
        visible: !button.focus;
    }

    Image {
        anchors.fill: parent;
        source: pressSource;
        visible: button.focus;
    }

    BaseText {
        anchors.centerIn: parent;
        text: btnText;
        font.pixelSize: textsize;
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
            button.released();
        }

        onClicked: {
            button.focus = false;
            button.clicked();
        }
        onPressAndHold: {
            button.focus = true;
            button.pressAndHold();
        }
    }

}

