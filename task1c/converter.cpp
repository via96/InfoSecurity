#include "converter.h"

Converter::Converter()
{

}

QString Converter::Encode(QString inputStr, QString key)
{
    QString result = "";
    for (int i = 0; i < inputStr.length(); ++i)
    {
        int temp = (inputStr.at(i).toLatin1() + key.at(i % key.size()).toLatin1()) % 256;
        if (temp == 0)
            temp = 255;
        result += (char)(temp);
    }
    return result;
}

QString Converter::Decode(QString inputStr, QString key)
{
    QString result = "";
    for (int i = 0; i < inputStr.length(); ++i)
    {
        int temp = (inputStr.at(i).toLatin1() - key.at(i % key.size()).toLatin1()) % 256;
        if (temp == 0)
            temp = 255;
        result += (char)temp;
    }
    return result;
}

QList<QString> Converter::EncodeSeries(QList<QString> series, QString key)
{
    QList<QString> result;
    for (QString curStr : series)
    {
        result.append(Encode(curStr, key));
    }
    return result;
}

QList<QString> Converter::DecodeSeries(QList<QString> series, QString key)
{
    QList<QString> result;
    for (QString curStr : series)
    {
        result.append(Decode(curStr, key));
    }
    return result;
}
