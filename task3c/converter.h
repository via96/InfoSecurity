#ifndef CONVERTER_H
#define CONVERTER_H
#include <QCoreApplication>
#include <mixer.h>

class Converter
{
public:
    Converter();
    QString EncodeLine(QString inputStr, QString mask);
    QString DecodeLine(QString inputStr, QString mask);
    QString MyEncode(QString inputStr, QString mask);
    QString MyDecode(QString inputStr, QString mask);
private:
    void Swap(QChar* a, QChar* b);
    QString CompileStr(QList<QString> inputSeries);
};

#endif // CONVERTER_H
