#include "filemanager.h"

FileManager::FileManager()
{

}

void FileManager::SaveBase(Database base)
{
    QFile file("base");
    file.open(QIODevice::WriteOnly);
    file.write("");
    file.close();
    for (int i = 0; i < base.GetCount(); ++i)
        WriteLine(FieldToStr(base.GetField(i)), "base");
}

Database FileManager::LoadBase()
{
    QList<Field> result;
    QList<QString> strSeries = ReadAll("base");
    for (QString curStr : strSeries)
        result.append(StrToField(curStr));
    return Database(result);
}

void FileManager::WriteLine(QString str, QString path)
{
    QFile file(path);
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    QTextStream out(&file);
    out << str << endl;
    file.close();
}

QString FileManager::ReadLine(QString path)
{
    QString result;
    QFile file(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    result = in.readLine();
    file.close();
    return result;
}

QList<QString> FileManager::ReadAll(QString path)
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

Field FileManager::StrToField(QString str)
{
    //Field result;
    //result.Name = str.left(str.indexOf(" "));
    //result.Hash = str.right(str.length() - str.indexOf(" ") + 1);
    return Field(str.left(str.indexOf(" ")), str.right(str.length() - str.indexOf(" ") + 1));
}

QString FileManager::FieldToStr(Field field)
{
    return field.Name + " " + field.Hash;
}

QString FileManager::GetFileHash(QString path)
{
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QByteArray res = file.readAll();
    QCryptographicHash hash(QCryptographicHash::Md5);
    return QString::fromStdString(hash.hash(res, QCryptographicHash::Md5).toStdString());
}
