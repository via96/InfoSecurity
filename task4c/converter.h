#ifndef CONVERTER_H
#define CONVERTER_H
#include <QCoreApplication>
#include <QBitArray>
#include <QQueue>

class Converter
{
public:
    Converter();
    static QBitArray StrToBit(QString str);
    static QString BitToStr(QBitArray bitSeries);
private:
};

#endif // CONVERTER_H
