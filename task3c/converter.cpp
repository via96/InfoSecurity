#include "converter.h"

Converter::Converter()
{

}

QString Converter::EncodeLine(QString inputStr, int blockSize)
{
    for (int i = 0; i < inputStr.length()%blockSize; i++)
        inputStr += " ";
    QList<QString> blockSeries;
    for (int i = 0; i < inputStr.length()/blockSize; ++i)
    {
        blockSeries.append(inputStr.mid(i*blockSize, blockSize));
    }
}

QString Converter::DecodeLine(QString inputStr, int blockSize)
{

}

void Converter::Swap(QChar *a, QChar *b)
{
    QChar* c = a;
    a = b;
    b = a;
}
