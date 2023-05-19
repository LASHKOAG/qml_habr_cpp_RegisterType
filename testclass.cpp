#include "testclass.h"

TestClass::TestClass(QObject *parent) : QObject(parent)
{
    m_file = new MyFile("./test.txt");
}

TestClass::~TestClass()
{
    if(m_file != nullptr){
        delete m_file;
    }
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

int TestClass::write_data()
{
    m_file->write_file_mf();
    return 0;
}

int TestClass::write_data(QString data)
{
    m_file->write_file_mf(data);
    return 0;
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
