import QtQuick 2.12
import QtQuick.Controls 2.3
import WordleCase 1.0

Item {
    id: root
    width: 700
    height: 300

    property double rowSpacing: 0.01 * width
    property double columnSpacing: 0.03 * height
    property double columns: 10
    property double rows: 3
    property int letterCount: 5
    property int currentWordIndex: 0

    property ListModel objModel

    property ListModel firstRowModel: ListModel {
        ListElement {textP: 'Q'; widthP: 1; valueP: -1}
        ListElement {textP: 'W'; widthP: 1; valueP: -1}
        ListElement {textP: 'E'; widthP: 1; valueP: -1}
        ListElement {textP: 'R'; widthP: 1; valueP: -1}
        ListElement {textP: 'T'; widthP: 1; valueP: -1}
        ListElement {textP: 'Y'; widthP: 1; valueP: -1}
        ListElement {textP: 'U'; widthP: 1; valueP: -1}
        ListElement {textP: 'I'; widthP: 1; valueP: -1}
        ListElement {textP: 'O'; widthP: 1; valueP: -1}
        ListElement {textP: 'P'; widthP: 1; valueP: -1}
    }

    property ListModel secondRowModel: ListModel {
        ListElement {textP: ''; widthP: 0.5; valueP: -1}
        ListElement {textP: 'A'; widthP: 1; valueP: -1}
        ListElement {textP: 'S'; widthP: 1; valueP: -1}
        ListElement {textP: 'D'; widthP: 1; valueP: -1}
        ListElement {textP: 'F'; widthP: 1; valueP: -1}
        ListElement {textP: 'G'; widthP: 1; valueP: -1}
        ListElement {textP: 'H'; widthP: 1; valueP: -1}
        ListElement {textP: 'J'; widthP: 1; valueP: -1}
        ListElement {textP: 'K'; widthP: 1; valueP: -1}
        ListElement {textP: 'L'; widthP: 1; valueP: -1}
    }

    property ListModel thirdRowModel: ListModel {
        ListElement {textP: 'ENTER'; widthP: 1.5; valueP: -1}
        ListElement {textP: 'Z'; widthP: 1; valueP: -1}
        ListElement {textP: 'X'; widthP: 1; valueP: -1}
        ListElement {textP: 'C'; widthP: 1; valueP: -1}
        ListElement {textP: 'V'; widthP: 1; valueP: -1}
        ListElement {textP: 'B'; widthP: 1; valueP: -1}
        ListElement {textP: 'N'; widthP: 1; valueP: -1}
        ListElement {textP: 'M'; widthP: 1; valueP: -1}
        ListElement {textP: '\u2190'; widthP: 1.5; valueP: -1}
    }

    Rectangle {
        width: parent.width
        height: parent.height
        anchors.bottom: parent.bottom
        color: "transparent"

        Item {
            id: keyboard
            anchors.fill: parent
            anchors.leftMargin:  columnSpacing

            Column{
                spacing: columnSpacing

                Row{
                    spacing: rowSpacing

                    Repeater{
                        model: firstRowModel

                        delegate: CustomButton{
                            text: textP
                            value: valueP
                            width: widthP * keyboard.width / columns - rowSpacing
                            height: keyboard.height / rows - columnSpacing

                            onClicked: root.clicked(text)
                        }
                    }
                }

                Row{
                    spacing: rowSpacing

                    Repeater{
                        model: secondRowModel

                        delegate: CustomButton{
                            text: textP
                            value: valueP
                            width: widthP * keyboard.width / columns - rowSpacing
                            height: keyboard.height / rows - columnSpacing

                            onClicked: root.clicked(text)
                        }
                    }
                }

                Row{
                    spacing: rowSpacing

                    Repeater{
                        model: thirdRowModel

                        delegate: CustomButton{
                            text: textP
                            value: valueP
                            width: widthP * keyboard.width / columns - rowSpacing
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
        var obj = objModel.get(currentWordIndex)
        var length = obj.wordTextP.length

        if (text === '\u2190')
        {
            if (length > 0)
            {
                obj.wordTextP = obj.wordTextP.substring(0, length-1)
            }
        }
        else if (text === "ENTER")
        {
            if (length === letterCount)
            {
                var str = WordleChecker.compare(obj.wordTextP)
                obj.valuesP = str;
                updateKeyboard(str, obj.wordTextP)
                currentWordIndex++
            }
            else
            {
                console.log("Not Enough Letters!");
            }
        }
        else
        {
            if (length < letterCount)
            {
                obj.wordTextP = obj.wordTextP + text
            }
        }
    }

    function updateKeyboard(str, word){
        var length = str.length

        for (var i = 0; i < length; i++) {

            iterate(firstRowModel, str[i], word[i])
            iterate(secondRowModel, str[i], word[i])
            iterate(thirdRowModel, str[i], word[i])
        }
    }

    function iterate(model, value, word)
    {
        for (var i = 0; i < model.count; i++)
        {
            var obj = model.get(i)

            if (obj.textP === word)
            {
                if (obj.valueP !== 2)
                {
                    obj.valueP = parseInt(value)
                }
            }
        }
    }
}
