#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <iostream>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>

class FileManager
{
public:
    FileManager();
    void Write(QString str, QString path);
    QString Read(QString path);
private:
    QString path;
};

#endif // FILEMANAGER_H
