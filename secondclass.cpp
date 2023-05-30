#include "secondclass.h"

SecondClass::SecondClass(QObject *parent) : QObject(parent)
{

}

int SecondClass::getFirstProperty() const
{
    return firstProperty;
}

void SecondClass::setFirstProperty(int newFirstProperty)
{
    if (firstProperty == newFirstProperty)
        return;
    firstProperty = newFirstProperty;
    emit firstPropertyChanged();
}

