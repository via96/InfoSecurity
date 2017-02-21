#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <database.h>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>


class FileManager
{
public:
    FileManager();
    void SaveBase(Database base);
    Database LoadBase();
    QString GetFileHash(QString path);
private:
    void WriteLine(QString str, QString path);
    QString ReadLine(QString path);
    QList<QString> ReadAll(QString path);
    Field StrToField(QString str);
    QString FieldToStr(Field field);
};

#endif // FILEMANAGER_H
