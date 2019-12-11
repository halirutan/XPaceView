import QtQuick 2.12
import QtQuick.Controls 2.12


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
        background: Rectangle {
            color: "#ffffff"
            border.color: "#aaaaaa"
        }

        visible: parent.toolTip.length > 0 ? hovered : false
    }

}

