#ifndef SECONDCLASS_H
#define SECONDCLASS_H

#include <QObject>

class SecondClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int firstProperty READ getFirstProperty WRITE setFirstProperty NOTIFY firstPropertyChanged)

public:
    explicit SecondClass(QObject *parent = nullptr);

    int getFirstProperty() const;
    void setFirstProperty(int newFirstProperty);

private:
    int firstProperty{100};

signals:
    void firstPropertyChanged();

};

#endif // SECONDCLASS_H
