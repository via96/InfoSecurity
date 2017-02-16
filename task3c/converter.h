#ifndef CONVERTER_H
#define CONVERTER_H
#include <QCoreApplication>

class Converter
{
public:
    Converter();
    QString EncodeLine(QString inputStr, int blockSize);
    QString DecodeLine(QString inputStr, int blockSize);
private:
    void Swap(QChar* a, QChar* b);
};

#endif // CONVERTER_H
