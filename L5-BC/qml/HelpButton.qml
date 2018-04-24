import QtQuick 2.3

Item {
    id: button;
    focus: false;

    property int textsize: 32;
    property string btnText: "";
    property string normalIcon:"";
    property string pressIcon:"";
    property string optionIcon:"";
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

    Image {
        id: icon
        width: 64;
        height: 64
        anchors.left: parent.left;
        anchors.leftMargin: 92
        anchors.verticalCenter: parent.verticalCenter;
        source: optionIcon;
        opacity: button.focus ? 1 : 0.8;
    }



    BaseText {
        id: txt;
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: icon.right;
        anchors.leftMargin: 15;
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

