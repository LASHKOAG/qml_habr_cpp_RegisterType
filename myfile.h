#ifndef MYFILE_H
#define MYFILE_H

#include <QDebug>
#include <QFile>
#include <QString>

class MyFile
{
public:
    MyFile();
    MyFile(QString filename);

    int write_file_mf();
    int write_file_mf(QString data);

private:

    QString m_filename{""};
};

#endif // MYFILE_H
