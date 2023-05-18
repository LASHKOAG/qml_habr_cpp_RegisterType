#include "testclass.h"

TestClass::TestClass(QObject *parent) : QObject(parent)
{

}

int TestClass::getSomeProperty() const
{
    qDebug() << "I am getter";
    return someProperty;
}

void TestClass::setSomeProperty(const int & var)
{
    qDebug() << "I am setter";
    someProperty = var;
}

void TestClass::myMethod()
{
    qDebug() << "I am Method";
    someProperty++;
    emit somePropertyChanged();
}

void TestClass::mySlot()
{
    qDebug() << "I am SLOT";
    someProperty--;
    emit somePropertyChanged();

    if(someProperty < 0) emit someSignal();
}

//void C_Controller::setSettings(bool a)
//{
//    if(m_isSettings != a){
//        m_isSettings = a;
//        emit isSettingsChanged();
//    }
//}
