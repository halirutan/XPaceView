import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQml 2.12
import "qrc:/Icon.js" as MDFont
import "../components"

ApplicationWindow {    
    id: mainWindow
    visible: true
    width: 920
    height: 512
    title: qsTr("XPaceView — Your cute XPace log visualizer")


    menuBar: MenuBar {
        Menu {
            title: "File"
            MenuItem {
                text: "Open..."
            }
            MenuItem {
                text: "Close"
            }
            MenuSeparator {}
            MenuItem {
                text: "Exit"
            }
        }

        Menu {
            title: "Tools"
            MenuItem {
                text: "Cut"
            }
            MenuItem {
                text: "Copy"
            }
            MenuItem {
                text: "Paste"
            }
        }
    }

    header: ToolBar {
        height: 40
        RowLayout {
            anchors.fill: parent
            spacing: 5
            RoundButton {
                text: Icons.mdfolder_open
                toolTip: qsTr("Open Folders and Files")
                Layout.alignment: Qt.AlignLeft
            }
            RoundButton {
                text: Icons.mdadd
                toolTip: qsTr("Add Files to Graph")
                Layout.alignment: Qt.AlignLeft
            }
            RoundButton {
                text: Icons.mdclose
                toolTip: qsTr("Close Graphs")
                Layout.alignment: Qt.AlignLeft
            }
            ToolSeparator { }
            RoundButton {
                text: Icons.mdzoom_in
                toolTip: qsTr("Zoom In")
                Layout.alignment: Qt.AlignLeft
            }
            RoundButton {
                text: Icons.mdzoom_out
                toolTip: qsTr("Zoom Out")
                Layout.alignment: Qt.AlignLeft
            }
            RoundButton {
                text: Icons.mdzoom_out_map
                toolTip: qsTr("Move")
                Layout.alignment: Qt.AlignLeft
            }
            Item {
                Layout.fillWidth: true
            }

            RoundButton{
                text: Icons.mdhelp_outline
                toolTip: qsTr("Help")
                Layout.alignment: Qt.AlignRight
            }

        }
    }

    Pane {
        id: centerPane
        anchors.fill: parent
        Label {
            text: "Do Something!"
            font.pointSize: 30
            color: "#d0d0d0"
            anchors.centerIn: parent
        }
    }

    footer: ToolBar {
        RowLayout {
            anchors.fill: parent
            Label {
                text: "Read Only"
            }
        }
    }
}
