import QtQuick 2.3


Item {
    id: button;
    focus: false;

    property int ispressinputboxtext:0;
    property int textsize: 32
    property string normalSource;
    property string pressSource;
    property string btnText: "";
    signal pressed();
    signal clicked();
    signal released();


    Image {
        id: normal;
        anchors.fill: parent;
        source: normalSource;
        visible: !button.focus;
    }
    Image {
        id: press;
        anchors.fill: parent;
        source: pressSource;
        visible: button.focus;
    }

    BaseText {
        anchors.left: parent.left;
        anchors.leftMargin: 90;
        anchors.verticalCenter: parent.verticalCenter;
        text: btnText;
        font.pixelSize: textsize;
    }

    MouseArea  {
        anchors.fill: parent;

        onPressed: {
            button.focus = true;
            onButtonPressed(mouse.x, mouse.y);
        }

        onExited: {
            button.focus = false;
        }

        onReleased: {
            button.focus = false;
            onButtonReleased(mouse.x, mouse.y);
        }

        onClicked: {
            button.focus = false;
            onButtonClicked(mouse.x, mouse.y);
        }
    }



    function onButtonPressed(x, y) {
        pressed();
    }

    function onButtonReleased(x, y) {
        released();
    }

    function onButtonClicked(x, y) {
        clicked();
    }
}

