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
        onPressAndHold: {
            button.focus = false;
            button.pressAndHold();
        }
    }


    function onButtonPressed(x, y) {
        pressed();
    }
    function onButtonClicked(x, y) {
        clicked();
    }
}

