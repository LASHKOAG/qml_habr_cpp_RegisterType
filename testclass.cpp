#include "testclass.h"
#include <QQuickView>
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

//not working --------------------------------------------------------------------
void TestClass::set_obj(QObject *objt)
{
    QObject *rect = objt->findChild<QObject*>("obj_rec_test");
    if (rect)
        rect->setProperty("color", "red");
}
//----------- --------------------------------------------------------------------

void TestClass::mySlot()
{
    qDebug() << "I am SLOT";
    someProperty--;
    emit somePropertyChanged();

    if(someProperty < 0) emit someSignal();
}

void TestClass::test_obj_Slot()
{
    qDebug() << "void TestClass::test_obj_Slot()" ;

}

//void C_Controller::setSettings(bool a)
//{
//    if(m_isSettings != a){
//        m_isSettings = a;
//        emit isSettingsChanged();
//    }
//}
