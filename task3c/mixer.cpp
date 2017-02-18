#include "mixer.h"

Mixer::Mixer()
{

}

QString Mixer::MixBlock(QString block, QString mask)
{
    QList<int> maskSeries;
    int nullCode = '0';
    for (QChar a : mask)
    {
        int temp = a.digitValue();
        maskSeries.append(temp + nullCode);
    }
    QString result = "";
    for (int i = 0; i < mask.length(); i++)
    {
        result += block[maskSeries[i] - 1];
    }
    return result;
}

