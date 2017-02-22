#include "mixer.h"

Mixer::Mixer()
{

}

QString Mixer::CodeBlock(QString block, QString mask)
{
    QList<int> maskSeries;
    int nullCode = '0';
    for (QChar a : mask)
    {
        int temp = a.digitValue() - 48;
        maskSeries.append(temp + nullCode);
    }
    QString result = "";
    for (int i = 0; i < mask.length(); i++)
    {
        result += block.at(maskSeries[i] - 1);
    }
    return result;
}

QString Mixer::DecodeBlock(QString block, QString mask)
{
    QList<int> maskSeries;
    int nullCode = '0';
    for (QChar a : mask)
    {
        int temp = a.digitValue() - 48;
        maskSeries.append(temp + nullCode);
    }
    QString result = "";
    for (int i = 0; i < mask.length(); i++)
    {
        result += block.at(maskSeries.indexOf(i + 1));
    }
    return result;
}

