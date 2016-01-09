import QtQuick 2.5
import QtQuick.Controls 1.3

Rectangle {
    property alias mouseArea: mouseArea

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        Grid {
            columns: 2
            spacing: 2

            TextInput {
                id: inputNumber1
                width: 80
                height: 20
                text: "1"
            }
            TextInput {
                id: inputNumber2
                width: 80
                height: 20
                text: "2"
            }
            Button {
                id: buttonSum
                width: 80
                height: 20
                text: "Sum!"
                isDefault: true
                onClicked: textSum.text = sum.sum(inputNumber1.text, inputNumber2.text);
            }
            Text {
                id: textSum
                text: "?"
            }
        }
    }
}

