import QtQuick 2.12
import WordleCase 1.0

Item {
    id: root

    implicitWidth: Constants.width
    implicitHeight: Constants.height

    property ListModel objModel: ListModel{}
    property int columnCount: 6

    Column{
        width: 270
        height: 350
        anchors.top: parent.top
        anchors.topMargin: 100
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10

        Repeater{
            model: objModel

            delegate: WordWidget{
                wordText: wordTextP
                values: valuesP
            }
        }
    }

    Component.onCompleted: {
        for (var i = 0; i < columnCount; i++) {
            objModel.append({"wordTextP":"", "valuesP":""})
        }
    }
}
