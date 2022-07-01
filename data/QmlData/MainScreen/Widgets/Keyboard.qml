import QtQuick 2.12
import QtQuick.Controls 2.3
import WordleCase 1.0

Item {
    id: root
    width: 700
    height: 500

    property double rowSpacing: 0.01 * width
    property double columnSpacing: 0.02 * height
    property double columns: 10
    property double rows: 5
    property string word: ""

    Rectangle {
        width: parent.width
        height: 0.8 * parent.height
        anchors.bottom: parent.bottom

        Item {
            id: keyboard
            anchors.fill: parent
            anchors.leftMargin:  columnSpacing

            Column{
                spacing: columnSpacing

                Row{ //Q W E R T Y U I O P
                    spacing: rowSpacing

                    Repeater{
                        model: [
                            {text: 'Q', width: 1},
                            {text: 'W', width: 1},
                            {text: 'E', width: 1},
                            {text: 'R', width: 1},
                            {text: 'T', width: 1},
                            {text: 'Y', width: 1},
                            {text: 'U', width: 1},
                            {text: 'I', width: 1},
                            {text: 'O', width: 1},
                            {text: 'P', width: 1},
                        ]

                        delegate: CustomButton{
                            text: modelData.text
                            width: modelData.width * keyboard.width / columns - rowSpacing
                            height: keyboard.height / rows - columnSpacing

                            onClicked: root.clicked(text)
                        }
                    }
                }

                Row{ //A S D F G H J K L
                    spacing: rowSpacing

                    Repeater{
                        model: [
                            {text: '', width: 0.5},
                            {text: 'A', width: 1},
                            {text: 'S', width: 1},
                            {text: 'D', width: 1},
                            {text: 'F', width: 1},
                            {text: 'G', width: 1},
                            {text: 'H', width: 1},
                            {text: 'J', width: 1},
                            {text: 'K', width: 1},
                            {text: 'L', width: 1},
                        ]

                        delegate: CustomButton{
                            text: modelData.text
                            width: modelData.width * keyboard.width / columns - rowSpacing
                            height: keyboard.height / rows - columnSpacing

                            onClicked: root.clicked(text)
                        }
                    }
                }

                Row{ //A S D F G H J K L
                    spacing: rowSpacing

                    Repeater{
                        model: [
                            {text: 'ENTER', width: 1.5},
                            {text: 'Z', width: 1},
                            {text: 'X', width: 1},
                            {text: 'C', width: 1},
                            {text: 'V', width: 1},
                            {text: 'B', width: 1},
                            {text: 'N', width: 1},
                            {text: 'M', width: 1},
                            {text: '\u2190', width: 1.5},
                        ]

                        delegate: CustomButton{
                            text: modelData.text
                            width: modelData.width * keyboard.width / columns - rowSpacing
                            height: keyboard.height / rows - columnSpacing

                            onClicked: root.clicked(text)
                        }
                    }
                }
            }
        }
    }

    signal clicked(string text)
    onClicked: {
        var length = word.length

        if (text == '\u2190')
        {
            if (length > 0)
            {
                word = word.substring(0, length-1)
            }
        }
        else if (text == "ENTER")
        {

        }
        else
        {
            if (length < 5)
            {
                word = word + text
            }
        }

        console.log(word)
    }
}
