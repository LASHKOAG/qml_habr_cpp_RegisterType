import QtQuick 2.12
import QtQuick.Window 2.12

import ModuleName 1.0
import ModuleNameSecond 1.0

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
            Component.onCompleted: _myClass.var_myClass = 50
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
                    _myClass.buttonClicked("Hello: " + myObj.someProperty)
                    var res = _myClass.someMethod()
                    console.log("res: " + res)

                    _myClass.print_vars();
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
            color: "grey"
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

    Rectangle{
        anchors.right: parent.right
        width: 20
        height: 20
        color: "green"
        SecondClass{
            id: sc
            firstProperty: 500
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log("------------------------ ")
                console.log("SecondClass sc, firstProperty: " + sc.firstProperty)
                sc.firstProperty = 12
                console.log("SecondClass sc, firstProperty: " + sc.firstProperty)
                sc.getFirstProperty()
                console.log("SecondClass sc, firstProperty: " + sc.getFirstProperty())
                console.log("------------------------ ")
                _myClass.var_myClass += 1
                _myClass.print_vars();
                console.log("------------------------ ")

            }
        }
    }
}
