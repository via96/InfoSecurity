#ifndef CONVERTER_H
#define CONVERTER_H
#include <QCoreApplication>
#include <iostream>

class Converter
{
public:
    Converter();
    QString Encode(QString inputStr, QString key);
    QString Decode(QString inputStr, QString key);
    QList<QString> EncodeSeries(QList<QString> series, QString key);
    QList<QString> DecodeSeries(QList<QString> series, QString key);
private:

};

#endif // CONVERTER_H
