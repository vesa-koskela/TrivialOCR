import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("TrivialOCR")

    RowLayout{
        anchors.fill: parent
        Image {
            id: srcimg
            source: "../Images/phototest.png"
        }
        Text {
            id: name
            text: qsTr("text")
        }

    }
}
