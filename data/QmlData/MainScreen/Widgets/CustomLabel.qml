import QtQuick 2.12
import QtQuick.Controls 2.3
import WordleCase 1.0

Label{
    id: control

    readonly property alias mDefaultBackground: defaultBackground

    width: 50
    height: 50
    verticalAlignment: Text.AlignVCenter
    horizontalAlignment: Text.AlignHCenter

    color: Constants.buttonTextColor

    font.pixelSize: 12
    font.family: Constants.buttonFont

    background: Rectangle{
        id: defaultBackground

        implicitWidth: 90
        implicitHeight: 30

        color: Constants.itemBackgroundColor

        border.width: 1
        border.color: Constants.itemBorderColor
    }
}
