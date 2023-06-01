# qml_habr_cpp_RegisterType

Case:
engine.rootContext()->setContextProperty("_myClass", &myClass);

Create class MyClass and odject myClass.

Set to qml myClass via engine.rootContext()->setContextProperty("_myClass", &myClass);.

In qml itself, this object is visible to everyone. That is, any object created in qml knows MyClass. And she can turn to him.



Создали класс MyClass и объект myClass.

Передаем объект myClass в qml через engine.rootContext()->setContextProperty("_myClass", &myClass);

В самом qml этот объект виден всем. То есть любой объект, созданный в qml знает myClass. И может к нему обратиться.


==========================================================================================
MyClass. Создаем переменную var_myClass.

MyClass добавлене через engine.rootContext()->setContextProperty("_myClass", &myClass);

Проверим что переменную var_myClass можно менять из разных объектов qmlи это не копии var_myClass:

TypeName - установим var_myClass = 50

Component.onCompleted: _myClass.var_myClass = 50



Rectangle - color: "green"

_myClass.var_myClass += 1

Происходит изменение, всё работает.
