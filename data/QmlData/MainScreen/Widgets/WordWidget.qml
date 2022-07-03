import QtQuick 2.12
import QtQuick.Controls 2.3
import WordleCase 1.0

Item{
    id: root

    width: 500
    height: 50

    property double rowSpacing: 0.01 * width
    property double rows: 5
    property alias wordText: root.wordTextStr
    property string wordTextStr:""
    property string values: ""

    //letter array
    property ListModel letterModel: ListModel{}

    Rectangle {
        width: parent.width
        height: parent.height
        anchors.bottom: parent.bottom
        color: "transparent"

        Item {
            id: word
            anchors.fill: parent

            Row {
                spacing: rowSpacing

                Repeater{
                    model: letterModel

                    delegate: CustomLabel{
                        text: modelText
                        value: valueP
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        for (var i = 0; i < rows; i++) {
            letterModel.append({"modelText":'', "valueP":-1})
        }
    }

    onWordTextChanged: {
        var length = wordText.length
        for (var i = 0; i < rows; i++){
            var obj = letterModel.get(i)

            if (i < length)
            {
                obj.modelText = wordText.charAt(i)
            }
            else
            {
                obj.modelText = ''
            }
        }
    }

    onValuesChanged: {
        var length = values.length

        for (var i = 0; i < length; i++){
            var obj = letterModel.get(i)

            obj.valueP = parseInt(values.charAt(i))
        }
    }
}
