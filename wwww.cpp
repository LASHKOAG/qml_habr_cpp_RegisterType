#include "wwww.h"

wwww::wwww(QObject *parent) : QObject(parent)
{

}

int wwww::getVakue() const
{
    return vakue;
}

void wwww::setVakue(int newVakue)
{
    vakue = newVakue;
}

int wwww::fgd() const
{
    return m_fgd;
}

void wwww::setFgd(int newFgd)
{
    m_fgd = newFgd;
}

int wwww::ggg() const
{
    return m_ggg;
}

void wwww::setGgg(int newGgg)
{
    if (m_ggg == newGgg)
        return;
    m_ggg = newGgg;
    emit gggChanged();
}
