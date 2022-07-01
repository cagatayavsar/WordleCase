import QtQuick 2.12
import QtQuick.Controls 2.3
import WordleCase 1.0

Button {
    id: control

    readonly property alias mDefaultContentItem: defaultContentItem
    readonly property alias mDefaultBackground: defaultBackground

    property color mTextColorNormal: Constants.buttonTextColor
    property color mBorderColorNormal: Constants.interactiveItemBorderColor
    property color mBackgroundColorNormal: Constants.interactiveItemBackgroundColor

    implicitWidth: Math.max(defaultBackground.implicitWidth,
                            defaultContentItem.implicitWidth + padding * 2)

    implicitHeight: Math.max(defaultBackground.implicitHeight,
                             defaultContentItem.implicitHeight + padding * 2)

    opacity: control.text === '' ? 0 : 1

    font.family: Constants.buttonFont
    font.pixelSize: 16

    contentItem: Text {
        id: defaultContentItem

        text: control.text
        font: control.font

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        color: mTextColorNormal
    }

    background: Rectangle {
        id: defaultBackground

        implicitWidth: 30
        implicitHeight: 20
        color: mBackgroundColorNormal
        radius: 5
        border.width: 1
        border.color: mBorderColorNormal
    }

    onClicked: {
        //console.log(Qt.fontFamilies())
    }

}
