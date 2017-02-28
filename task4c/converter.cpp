#include "converter.h"

Converter::Converter()
{

}

QBitArray Converter::StrToBit(QString str)
{
    QByteArray bytes = QByteArray::fromStdString(str.toStdString());
    QBitArray bits;
    bits.resize(bytes.size()*8);
    for(int i=0; i<bytes.count(); ++i)
        for(int b=0; b<8; ++b)
            bits.setBit(i*8+b, bytes.at(i)&(1<<(7-b)));
    return bits;
}

QString Converter::BitToStr(QBitArray bits)
{
    QByteArray bytes;
    bytes.resize(bits.size()/8);
    for(int j=0; j<bits.count(); ++j)
        bytes[j/8] = (bytes.at(j/8) | ((bits[j]?1:0)<<(j%8)));
    return QString::fromStdString(bytes.toStdString());
}

QBitArray Converter::BytesToBits(QByteArray bytes)
{
    QBitArray bits;
    bits.resize(bytes.size()*8);
    for(int i=0; i<bytes.count(); ++i)
        for(int b=0; b<8; ++b)
            bits.setBit(i*8+b, bytes.at(i)&(1<<(7-b)));
    return bits;
}

QByteArray Converter::BitsToBytes(QBitArray bits)
{
    QByteArray bytes;
    bytes.resize(bits.size()/8);
    for(int j=0; j<bits.count(); ++j)
        bytes[j/8] = (bytes.at(j/8) | ((bits[j]?1:0)<<(j%8)));
    return bytes;
}
