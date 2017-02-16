#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QCoreApplication>
#include <iostream>
#include <QFile>
#include <QTextStream>

class FileManager
{
public:
    FileManager();
    FileManager(QString path);
    void Write(QList<QString> passwords);
    QList<QString> Read();
private:
    QString path;
};

#endif // FILEMANAGER_H
