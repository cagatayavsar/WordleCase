pragma Singleton
import QtQuick 2.10

QtObject {

    readonly property int width: 800
    readonly property int height: 900

    readonly property color backgroundColor: "#121213"
    readonly property color darkGrayColor: "#3a3a3c"
    readonly property color greenColor: "#538d4e"
    readonly property color yellowColor: "#b59F3b"

    readonly property color itemBorderColor: "#3a3a3c"
    readonly property color itemBorderHoveredColor: "#b59F3b"
    readonly property color itemBackgroundColor: "#121213"
    readonly property color interactiveItemBorderColor: "#c0c0c0"
    readonly property color interactiveItemBackgroundColor: "#323232"
    readonly property color interactiveItemBackgroundDarkColor: "#262626"

    readonly property string buttonFont: "Calibri"
    readonly property color buttonTextColor: "#ffffff"
    readonly property int buttonPixelSize: 20
    readonly property int labelPixelSize: 24
}
