import QtQuick 2.3


Text {
    id: root
    property alias size: root.font.pixelSize
    property alias textColor: root.color
    font.pixelSize: 32
    color: "#ffffff"
    //font.family: fontName
}
