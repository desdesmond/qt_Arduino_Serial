import QtQuick 2.7
import QtQuick.Controls 1.5

ApplicationWindow {
    id: applicationWindow1
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Label {
        id: clickMe
        text: qsTr("Click me!")
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.verticalCenter: parent.verticalCenter
        MouseArea {
            anchors.fill: parent
            onClicked: serialCom.helloFromTheOtherSide()
        }
    }

    Label {
        id: sendSerial
        text: qsTr("Send Message to Arduino")
        font.pointSize: 9
        textFormat: Text.PlainText
        anchors.verticalCenter: parent.verticalCenter
        scale: 2
        anchors.leftMargin: 300
        anchors.left: clickMe.right

        MouseArea {
            anchors.fill: sendSerial
            onClicked: serialCom.sendMessageToArduino()
        }
    }
}
