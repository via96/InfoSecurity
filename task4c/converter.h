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
    static QString BitToStr(QBitArray bits);
private:
    QBitArray BytesToBits(QByteArray bytes);
    QByteArray BitsToBytes(QBitArray bits);
};

#endif // CONVERTER_H
