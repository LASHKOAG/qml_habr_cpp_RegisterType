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
