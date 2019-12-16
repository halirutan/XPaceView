import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4


RoundButton {
    property string toolTip
    id: button
    implicitHeight: 32
    implicitWidth: 32
    font.pointSize: 18
    font.family: "Material Icons"
    padding: 10
    ToolTip {
        text: parent.toolTip
        delay: 700
        // I'm too dumb to understand how I can change the color
        // of the background taking the overall application colors as basis.
        background: Rectangle {
            color: "#ffffff"
            border.color: "#aaaaaa"
            radius: 3
        }

        visible: parent.toolTip.length > 0 ? hovered : false
    }
}

