import QtQuick 2.12
import WordleCase 1.0
import "Widgets"

Rectangle {
    id: root

    implicitWidth: Constants.width
    implicitHeight: Constants.height

    color: Constants.backgroundColor

    Column{
        width: 270
        height: 350
        anchors.top: parent.top
        anchors.topMargin: 100
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10
        Repeater{
            model: [
                {},
                {},
                {},
                {},
                {},
                {}
            ]

            delegate: WordWidget{

            }
        }
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

    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}
}
##^##*/
