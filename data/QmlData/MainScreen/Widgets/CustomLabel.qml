import QtQuick 2.12
import QtQuick.Controls 2.3
import WordleCase 1.0

Label{
    id: control

    property int value: -1

    width: 50
    height: 50
    verticalAlignment: Text.AlignVCenter
    horizontalAlignment: Text.AlignHCenter

    color: Constants.buttonTextColor

    font.pixelSize: Constants.labelPixelSize
    font.bold: true
    font.family: Constants.buttonFont

    background: Rectangle{
        id: defaultBackground

        implicitWidth: 90
        implicitHeight: 30

        color: {
            if(value === 0)
            {
                Constants.darkGrayColor
            }
            else if (value === 1)
            {
                Constants.yellowColor
            }
            else if (value === 2)
            {
                Constants.greenColor
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
