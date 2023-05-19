#ifndef TESTCLASS_H
#define TESTCLASS_H

//https://habr.com/ru/articles/140899/

//для того что бы он был доступен из QML – это унаследовать его от QObject

//Теперь сделаем доступным из QML какое-нибудь свойство, для этого существует макрос Q_PROPERTY.
//someProperty собственно само наше свойство
//Если мы собираемся менять наше свойство из C++
//то нам необходимо уведомлять об этом интерфейс на QML с помощью сигнала somePropertyChanged.


//Теперь должны зарегистрировать наш класс в QML
// qmlRegisterTypes

//Для того что бы иметь возможность вызывать из QML C++ методы
//их необходимо определять как слоты либо при помощи макроса Q_INVOKABLE.


//модифицируем наш метод и слот так что бы при изменении свойства испускался сигнал somePropertyChanged.


//Для того что бы поймать этот сигнал в QML
//нашему объекту необходим обработчик события onSomeSignal

//ToDo 2. Changed сигнал должен emit'иться не абы где, а именно в setter'е и, желательно,
//только в том случае, если пришедшее значение действительно отличается от текущего.

#include <QObject>
#include <QDebug>
#include <myfile.h>

class TestClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int someProperty READ getSomeProperty WRITE setSomeProperty NOTIFY somePropertyChanged)
public:
    explicit TestClass(QObject *parent = nullptr);
    ~TestClass();

    int getSomeProperty() const;
    void setSomeProperty(const int &);

    Q_INVOKABLE void myMethod();


    //-------------------------
    Q_INVOKABLE int write_data();
    Q_INVOKABLE int write_data(QString data);

private:
    int someProperty;

    //-------------------------
    MyFile* m_file;

signals:
    void somePropertyChanged();
    void someSignal();

public slots:
    void mySlot();

};

#endif // TESTCLASS_H
