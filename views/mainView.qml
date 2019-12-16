import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.2
import QtQml 2.12
import "qrc:/Icon.js" as MDFont
import "../components"

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 920
    height: 512
    title: qsTr("XPaceView — Your cute XPace log visualizer")

    header: ToolBar {
        height: 40
        RowLayout {
            anchors.fill: parent
            spacing: 5
            RoundButton {
                text: Icons.mdfolder_open
                toolTip: qsTr("Open files in new graph")
                Layout.alignment: Qt.AlignLeft
                onClicked: {
                    backend.closeFiles()
                    fileDialog.open()
                }
            }
            RoundButton {
                text: Icons.mdadd
                toolTip: qsTr("Add files to current graph")
                Layout.alignment: Qt.AlignLeft
                onClicked: fileDialog.open()
            }
            RoundButton {
                text: Icons.mdclose
                toolTip: qsTr("Close graph")
                Layout.alignment: Qt.AlignLeft
                onClicked: backend.closeFiles()
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

            // Invisible item just to fill the space
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
            id: myLabel
            text: "Do Something!"
            font.pointSize: 30
            //color: "#d0d0d0"
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

    // FileDialog for opening and adding files
    FileDialog {
            id: fileDialog
            selectExisting: true
            selectMultiple: true
            nameFilters: {"*.log"}
            onAccepted: backend.addFiles(fileUrls)
    }
}
