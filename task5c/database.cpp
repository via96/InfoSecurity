#include "database.h"

Database::Database()
{

}

Database::Database(QList<Field> base)
{
    this->base = base;
}

QString Database::GetHash(QString name)
{
    for (Field cur : base)
    {
        if (cur.Name == name)
        {
            return cur.Hash;
        }
    }
    return "";
}

Field Database::GetField(int n)
{
    return base[n];
}

void Database::AddField(QString name, QString hash)
{
    base.append(Field(name, hash));
}

int Database::GetCount()
{
    return base.size();
}
