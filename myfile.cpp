#include "myfile.h"

MyFile::MyFile()
{

}

MyFile::MyFile(QString filename):m_filename{filename}
{
}

int MyFile::write_file_mf()
{
    QFile file(m_filename);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text)){
        qDebug() << "File is NOT open";
        return -1;
    }

    QTextStream out(&file);
    out << "The magic number is: " << 49 << "\n";

    file.close();

    return 0;
}

int MyFile::write_file_mf(QString data)
{
    QFile file(m_filename);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text)){
        qDebug() << "File is NOT open";
        return -1;
    }

    QTextStream out(&file);
    out << "data: " << data << "\n";

    file.close();

    return 0;
}
