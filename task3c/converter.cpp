#include "converter.h"

Converter::Converter()
{

}

QString Converter::EncodeLine(QString inputStr, QString mask)
{
    for (int i = 0; i < inputStr.length()%mask.length(); i++)
        inputStr += "#";
    QList<QString> blockSeries;
    int test = inputStr.length()/mask.length();
    for (int i = 0; i < inputStr.length()/mask.length(); ++i)
    {
        blockSeries.append(inputStr.mid(i*mask.length(), mask.length()));
    }
    for (int i = 0; i < blockSeries.length(); ++i)
    {
        blockSeries[i] = Mixer::CodeBlock(blockSeries[i], mask);
    }
    return CompileStr(blockSeries);
}

QString Converter::DecodeLine(QString inputStr, QString mask)
{
    QList<QString> blockSeries;
    for (int i = 0; i < inputStr.length()/mask.length(); ++i)
    {
        blockSeries.append(inputStr.mid(i*mask.length(), mask.length()));
    }
    for (int i = 0; i < blockSeries.length(); ++i)
    {
        blockSeries[i] = Mixer::DecodeBlock(blockSeries[i], mask);
    }
    return CompileStr(blockSeries);
}

QString Converter::EncodeKardan(QString inputStr)
{

}

QString Converter::DecodeKardan(QString inputStr)
{

}

QString Converter::CompileStr(QList<QString> inputSeries)
{
    QString result = "";
    for (QString curStr : inputSeries)
    {
        result += curStr;
    }
    return result;
}
