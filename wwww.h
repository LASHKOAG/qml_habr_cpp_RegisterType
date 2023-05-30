#ifndef WWWW_H
#define WWWW_H

#include <QObject>

class wwww : public QObject
{
    Q_OBJECT
public:
    explicit wwww(QObject *parent = nullptr);

    int vakue;

    int getVakue() const;
    void setVakue(int newVakue);

    int fgd() const;
    void setFgd(int newFgd);

    int ggg() const;
    void setGgg(int newGgg);

private:
    int m_fgd;
    int m_ggg;

    Q_PROPERTY(int ggg READ ggg WRITE setGgg NOTIFY gggChanged)

signals:

    void gggChanged();
};

#endif // WWWW_H
