#ifndef DATABASE_H
#define DATABASE_H
#include <QCoreApplication>

struct Field
{
    QString Name;
    QString Hash;
    Field();
    Field(QString name, QString hash)
    {
        Name = name;
        Hash = hash;
    }
};

class Database
{
public:
    Database();
    Database(QList<Field> base);
    QString GetHash(QString name);
    Field GetField(int n);
    void AddField(QString name, QString hash);
    int GetCount();
private:
    QList<Field> base;
};

#endif // DATABASE_H
