#include "mfile.h"

MFile::MFile()
{

}

bool MFile::Delete(QString path)
{
    int lenFile = GetFileSize(path);
    QByteArray byteSeries;
    for (int i = 0; i < lenFile; ++i)
        byteSeries.append('0');
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    file.write(byteSeries);
    file.close();
    return file.remove();
}

int MFile::GetFileSize(QString path)
{
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QByteArray byteSeries = file.readAll();
    file.close();
    return byteSeries.length();
}
