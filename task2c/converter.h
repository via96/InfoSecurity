#ifndef CONVERTER_H
#define CONVERTER_H
#include <QCoreApplication>
#include <iostream>
#include <alphabet.h>
#include <ctime>

enum CodeType { Single, Multiple, Generate };

class Converter
{
public:
    Converter();
    QString EncodeSingle(QString inputStr, int offset);
    QString EncodeMultiple(QString inputStr, QString key);
    QString EncodeGenerate(QString inputStr, QString key);
    QString DecodeSingle(QString inputStr, int offset);
    QString DecodeMultiple(QString inputStr, QString key);
    QString DecodeGenerate(QString inputStr, QString key);
    QString GenerateKey(int length);
private:
    Alphabet initSet;
    Alphabet targetSet;
    Alphabet CreateAlphabet();
};

#endif // CONVERTER_H
