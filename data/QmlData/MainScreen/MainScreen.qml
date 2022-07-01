import QtQuick 2.12
import WordleCase 1.0
import "Widgets"

Rectangle {
    id: root

    implicitWidth: Constants.width
    implicitHeight: Constants.height

    color: Constants.backgroundColor

    Keyboard
    {
        x: 350
        y: 500
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 10
    }
}
