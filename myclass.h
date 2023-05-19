#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QDebug>

class MyClass : public QObject
{
    Q_OBJECT
public:
    explicit MyClass(QObject *parent = nullptr);

    Q_INVOKABLE int someMethod();

signals:

public slots:
    // (QML doesn't support returning values via the parameter list.)
    void buttonClicked(const QString& in);

};

#endif // MYCLASS_H
