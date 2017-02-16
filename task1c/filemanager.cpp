#include "filemanager.h"

FileManager::FileManager()
{

}

FileManager::FileManager(QString path)
{
    //path = "passwords.txt";
    this->path = path;
}

void FileManager::Write(QList<QString> passwords)
{
    QFile file(path);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    for (QString curStr : passwords)
        out << curStr << endl;
    file.close();
}

QList<QString> FileManager::Read()
{
    QList<QString> result;
    QFile file(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    while (!in.atEnd())
    {
        result.append(in.readLine());
    }
    file.close();
    return result;
}
