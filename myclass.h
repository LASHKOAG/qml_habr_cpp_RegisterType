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
    Q_PROPERTY(int var_myClass READ getVar_myClass WRITE setVar_myClass NOTIFY var_myClassChanged)

    int getVar_myClass() const;
    void setVar_myClass(int newVar_myClass);

    Q_INVOKABLE void print_vars();

signals:

    void var_myClassChanged();

public slots:
    // (QML doesn't support returning values via the parameter list.)
    void buttonClicked(const QString& in);

private:
    int var_myClass{0};


};

#endif // MYCLASS_H
