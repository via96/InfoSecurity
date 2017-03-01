#include "converter.h"

Converter::Converter()
{

}

QString Converter::Encode(QString inputStr, QString key)
{
    QString result = "";
    for (int i = 0; i < inputStr.length(); ++i)
    {
        unsigned char temp = (inputStr.at(i).toLatin1() + key.at(i % key.size()).toLatin1()) % 255;
        if (temp == 0)
            temp = 255;
        result += temp;
    }
    return result;
}

QString Converter::Decode(QString inputStr, QString key)
{
    QString result = "";
    for (int i = 0; i < inputStr.length(); ++i)
    {
        unsigned char in = inputStr.at(i).toLatin1();
        if (in == 255)
            in =0;
        unsigned char temp = (in - key.at(i % key.size()).toLatin1()) % 255;
        result += temp;
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
