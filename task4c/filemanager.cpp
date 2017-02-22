#include "filemanager.h"

FileManager::FileManager()
{

}

void FileManager::Encode(QString inputStr, QString path)
{
    QString source;
    QFile file();
    QTextStream stream(&file);
    file.open(path, QIODevice::ReadOnly | QIODevice::Text);
    while (!stream.atEnd())
    {
        source = stream.readAll();
    }
    file.close();
    QBitArray bitSeries = Converter::StrToBit(inputStr);
    int lastWhitespace = -1;
    for (bool curBit : bitSeries)
    {
        lastWhitespace = source.indexOf(' ', lastWhitespace);
        if (curBit)
            source.insert(lastWhitespace + 1, ' ');
    }
    file.open(path + "_encode", QIODevice::WriteOnly | QIODevice::Text);
    stream << source;
    file.close();
}

QString FileManager::Decode(QString path)
{
    QString source;
    QFile file();
    QTextStream stream(&file);
    file.open(path, QIODevice::ReadOnly | QIODevice::Text);
    while (!stream.atEnd())
    {
        source = stream.readAll();
    }
    file.close();
    QList<bool> bitContainer;
    int lastWhitespace = -1;
    while (source.indexOf(' ', lastWhitespace) != -1)
    {
        lastWhitespace = source.indexOf(' ', lastWhitespace);
        if (source.at(lastWhitespace + 1) == ' ')
        {
            lastWhitespace++;
            bitContainer.append(true);
        }
        else
            bitContainer.append(false);
    }
    return Converter::BitToStr(ListToArray(bitContainer));
}

QBitArray FileManager::ListToArray(QList<bool> bitContainer)
{
    QBitArray bitSeries(bitContainer.length());
    for (int i = 0; i < bitContainer.length(); ++i)
    {
        bitSeries[i] = bitContainer[i];
    }
    return bitSeries;
}
