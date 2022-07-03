import QtQuick 2.12
import WordleCase 1.0
import "Widgets"

Rectangle {
    id: root

    implicitWidth: Constants.width
    implicitHeight: Constants.height

    color: Constants.backgroundColor

    WordsColumn{
        id: words
    }

    Keyboard
    {
        id: keyboard
        x: 350
        y: 500
        height: 300
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 0
        objModel: words.objModel
    }
}
