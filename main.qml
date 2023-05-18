import QtQuick 2.12
import QtQuick.Window 2.12

import ModuleName 1.0

//https://habr.com/ru/articles/140899/

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle{
        width: 360
        height: 360
        TypeName{
            id: myObj
            someProperty: 10
            onSomeSignal: {
                big_rec.visible = true;
            }
            onSomePropertyChanged: {
                console.log("onSomePropertyChanged")
            }
        }
        Text {
            id: txt_property
            text: qsTr("My property is: " + myObj.someProperty)
            anchors.centerIn: parent
        }
        //        MouseArea{
        //            anchors.fill: parent
        //            onClicked: {
        //                Qt.quit();
        //            }
        //        }

        Rectangle{
            width: 20
            height: 20
            color: "red"
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    myObj.mySlot();
                }
            }
        }
        Rectangle{
            anchors.right: parent.right
            width: 20
            height: 20
            color: "blue"
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    myObj.myMethod();
                }
            }
        }
        Rectangle{
            id:big_rec
            width: 400
            height: 250
            color: "red"
            visible: false
            anchors.centerIn: parent
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    Qt.quit();
                }
            }
        }
    }
}
