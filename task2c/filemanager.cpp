#include "filemanager.h"

FileManager::FileManager()
{

}

void FileManager::Write(QString str, QString path)
{
    QFile file(path);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << str << endl;
    file.close();
}

QString FileManager::Read(QString path)
{
    QString result;
    QFile file(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    result = in.readLine();
    file.close();
    return result;
}
