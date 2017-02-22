#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <converter.h>

class FileManager
{
public:
    FileManager();
    void Encode(QString inputStr, QString path);
    QString Decode(QString path);
private:
    QBitArray ListToArray(QList<bool> bitContainer);
};

#endif // FILEMANAGER_H
