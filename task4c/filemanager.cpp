#include "filemanager.h"

FileManager::FileManager()
{

}

void FileManager::Encode(QString inputStr, QString path)
{
    QString source;
    QFile file(path);
    QTextStream stream(&file);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    while (!stream.atEnd())
    {
        source = stream.readAll();
    }
    file.close();
    QBitArray bitSeries = Converter::StrToBit(inputStr);
    int lastWhitespace = -1;
    for (int i = 0; i < bitSeries.size(); ++i)
    {
        lastWhitespace = source.indexOf(' ', lastWhitespace);
        if (bitSeries[i])
            source.insert(lastWhitespace + 1, ' ');
    }
    QFile sFile(path + "_encode");
    QTextStream sStream(&sFile);
    sFile.open(QIODevice::WriteOnly | QIODevice::Text);
    sStream << source;
    sFile.close();
}

QString FileManager::Decode(QString path)
{
    QString source;
    QFile file(path);
    QTextStream stream(&file);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
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
