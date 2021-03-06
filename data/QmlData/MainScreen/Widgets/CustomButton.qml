import QtQuick 2.12
import QtQuick.Controls 2.3
import WordleCase 1.0

Button {
    id: control

    implicitWidth: Math.max(defaultBackground.implicitWidth,
                            defaultContentItem.implicitWidth + padding * 2)

    implicitHeight: Math.max(defaultBackground.implicitHeight,
                             defaultContentItem.implicitHeight + padding * 2)

    property int value: -1

    opacity: control.text === '' ? 0 : 1

    font.family: Constants.buttonFont
    font.pixelSize: Constants.buttonPixelSize

    contentItem: Text {
        id: defaultContentItem

        text: control.text
        font: control.font

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        color: hovered ? Constants.itemBorderHoveredColor : Constants.buttonTextColor
    }

    background: Rectangle {
        id: defaultBackground

        implicitWidth: 30
        implicitHeight: 20
        color: {
            var color = Constants.itemBackgroundColor
            var pressedColor = Constants.interactiveItemBackgroundDarkColor

            if(value === 0)
            {
                color = Constants.darkGrayColor
                pressedColor = Constants.darkGrayColorPressed
            }
            else if (value === 1)
            {
                color = Constants.yellowColor
                pressedColor = Constants.yellowColorPressed
            }
            else if (value === 2)
            {
                color = Constants.greenColor
                pressedColor = Constants.greenColorPressed
            }

            return pressed ? pressedColor : color
        }
        radius: 5
        border.width: hovered ? 3 : 1
        border.color: hovered ? Constants.itemBorderHoveredColor : Constants.interactiveItemBorderColor
    }
}
