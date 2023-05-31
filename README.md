# qml_habr_cpp_RegisterType

main.cpp

qmlRegisterType<TestClass>("ModuleName", 1, 0, "TypeName");




main.qml
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
        
Создаем объект в qml

у объектов qml бывают свойтсва.

они создается в .h:

Q_PROPERTY(int someProperty READ getSomeProperty WRITE setSomeProperty NOTIFY somePropertyChanged)


Чтобы в qml у объекта был сигнал:

onSignal:{}

делай в .h

signals:
    void somePropertyChanged();
    void someSignal();
