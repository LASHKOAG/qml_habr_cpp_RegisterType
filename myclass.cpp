#include "myclass.h"

MyClass::MyClass(QObject *parent) : QObject(parent)
{

}

int MyClass::someMethod()
{
    qDebug() << "MyClass: someMethod(): done";
    return 5;
}

void MyClass::buttonClicked(const QString &in)
{
    qDebug() << in;
}

int MyClass::getVar_myClass() const
{
    return var_myClass;
}

void MyClass::setVar_myClass(int newVar_myClass)
{
    if (var_myClass == newVar_myClass)
        return;
    var_myClass = newVar_myClass;
    emit var_myClassChanged();
}

void MyClass::print_vars()
{
    qDebug() << "var_myClass: " << var_myClass;
}
