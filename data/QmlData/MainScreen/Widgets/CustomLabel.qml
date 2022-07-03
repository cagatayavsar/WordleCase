import QtQuick 2.12
import QtQuick.Controls 2.3
import WordleCase 1.0

Label{
    id: control

    readonly property alias mDefaultBackground: defaultBackground

    property int value: -1

    width: 50
    height: 50
    verticalAlignment: Text.AlignVCenter
    horizontalAlignment: Text.AlignHCenter

    color: Constants.buttonTextColor

    font.pixelSize: 14
    font.family: Constants.buttonFont

    background: Rectangle{
        id: defaultBackground

        implicitWidth: 90
        implicitHeight: 30

        color: {
            if(value === 0)
            {
                "#3a3a3c"
            }
            else if (value === 1)
            {
                "#b59F3b"
            }
            else if (value === 2)
            {
                "#538d4e"
            }
            else
            {
                Constants.itemBackgroundColor
            }

        }

        border.width: 1
        border.color: Constants.itemBorderColor
    }
}
