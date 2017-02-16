#include "converter.h"

Converter::Converter()
{
    srand(time(0));
    initSet = CreateAlphabet();
}

QString Converter::EncodeSingle(QString inputStr, int offset)
{
    QString result = "";
    for (int i = 0; i < inputStr.length(); ++i)
    {
        int temp = inputStr.at(i).toLatin1();
        if (temp == 0)
            temp = 255;
        result += (char)((temp + offset) % 256);
    }
    return result;
}

QString Converter::EncodeMultiple(QString inputStr, QString key)
{
    QString result = "";
    for (int i = 0; i < inputStr.length(); ++i)
    {
        int temp = (inputStr.at(i).toLatin1() + key.at(i % key.size()).toLatin1()) % 256;
        if (temp == 0)
            temp = 255;
        result += (char)(temp);
    }
    return result;
}

QString Converter::EncodeGenerate(QString inputStr, QString key)
{
    QString result = "";
    for (int i = 0; i < inputStr.length(); ++i)
    {
        int temp = (inputStr.at(i).toLatin1() + key.at(i).toLatin1()) % 256;
        if (temp == 0)
            temp = 255;
        result += (char)(temp);
    }
    return result;
}

QString Converter::DecodeSingle(QString inputStr, int offset)
{
    QString result = "";
    for (int i = 0; i < inputStr.length(); ++i)
    {
        int temp = inputStr.at(i).toLatin1();
        if (temp == 0)
            temp = 255;
        result += (char)((temp - offset) % 256);
    }
    return result;
}

QString Converter::DecodeMultiple(QString inputStr, QString key)
{
    QString result = "";
    for (int i = 0; i < inputStr.length(); ++i)
    {
        int temp = (inputStr.at(i).toLatin1() - key.at(i % key.size()).toLatin1()) % 256;
        if (temp == 0)
            temp = 255;
        result += (char)temp;
    }
    return result;
}

QString Converter::DecodeGenerate(QString inputStr, QString key)
{
    QString result = "";
    for (int i = 0; i < inputStr.length(); ++i)
    {
        int temp = (inputStr.at(i).toLatin1() - key.at(i).toLatin1()) % 256;
        if (temp == 0)
            temp = 255;
        result += (char)temp;
    }
    return result;
}

QString Converter::GenerateKey(int length)
{
    QString result = "";
    for (int i = 0; i < length; ++i)
    {
        result += initSet.GetChar(rand()%(initSet.GetSize() - 6));
    }
    return result;
}

Alphabet Converter::CreateAlphabet()
{
    QList<char> res;
    for (char a = 'A'; a <= 'Z'; a++)
        res.append(a);
    for (char a = 'a'; a <= 'z'; a++)
        res.append(a);
    for (char a = '0'; a <= '9'; a++)
        res.append(a);
    res.append('.');
    res.append(',');
    res.append('+');
    res.append('-');
    res.append('=');
    res.append('_');
    return Alphabet(res);
}
