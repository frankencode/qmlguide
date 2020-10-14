import QtQuick

Rectangle {
    color: Qt.darker("white", mouse.pressed ? 1.1 : 0)
    Text {
        anchors.centerIn: parent
        text: "Press me!"
    }
    MouseArea {
        id: mouse
        anchors.fill: parent
    }
}
