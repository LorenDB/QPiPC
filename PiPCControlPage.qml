import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QPiPC 1.0

ApplicationWindow {
    id: pageRoot

    title: qsTr("GPIO controls")


    ListView {
        model: [25, 26]
        spacing: 10
        anchors.margins: 10

        delegate: SwitchDelegate {
            text: qsTr("Pin %1").arg(model)
            Layout.fillWidth: true
            onCheckedChanged: QPiPC.setPin(model, checked)
        }
    }
}
