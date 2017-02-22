#include "converter.h"

Converter::Converter()
{

}

QBitArray Converter::StrToBit(QString str)
{
    QByteArray byteSeries = QByteArray::fromStdString(str.toStdString());
    QBitArray result(byteSeries.length()*8);
    for (int i = 0; i < byteSeries.length(); ++i)
    {
        char temp = 1;
        for (int j = 0; j < 8; ++j)
        {
            result[(i+1)*(j+1) - 1] = byteSeries[i] & temp;
            temp << 1;
        }
    }
    return result;
}

QString Converter::BitToStr(QBitArray bitSeries)
{
    QByteArray byteSeries;
    char c = 0;
    int blokSize = 0;
    for (bool curBit : bitSeries)
    {
        char temp = 0;
        if (blokSize < 8)
        {
            temp |= curBit;
            temp << 7 - blokSize;
            c |= temp;
            blokSize++;
        }
        else
        {
            byteSeries.append(c);
            blokSize = 0;
            c = 0;
        }
    }
    return QString::fromStdString(byteSeries.toStdString());
}
