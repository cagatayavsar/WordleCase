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
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 20
        objModel: words.objModel
    }
}
