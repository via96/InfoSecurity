#include "matrix.h"

Matrix::Matrix()
{
    srand(time(0));
    FillMask();
    InitCode();
    size = 4;
    position = 0;
}

bool Matrix::EncodeWord(QString inputStr)
{

    if (inputStr.length() > 16)
        return false;
    position = 0;
    FillMask();
    while (inputStr.length() != 16)
    {
        inputStr += '#';
    }
    QList<QString> blockSeries;
    for (int i = 0; i < 4; ++i)
        blockSeries.append(inputStr.mid(i*4, 4));
    for (QString curBlock : blockSeries)
    {
        WriteBlok(curBlock);
        RotateMask();
    }
    return true;
}

QString Matrix::DecodeWord(QString inputStr)
{
    if (inputStr.length() != 16)
        return "";
    position = 0;
    FillMask();
    QList<QString> blockSeries;
    for (int i = 0; i < 4; ++i)
        blockSeries.append(inputStr.mid(i*4, 4));
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            code[i][j] = blockSeries[i][j];
    QList<QString> resultSeries;
    for (int i = 0; i < 4; ++i)
    {
        resultSeries.append(ReadBlock());
        RotateMask();
    }
    return CompileStr(resultSeries);
}

QString Matrix::GetCodeWord()
{
    QString result = "";
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result += code[i][j];
    return result;
}

void Matrix::FillMask()
{
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            mask[i][j] = false;
    mask[0][2] = true;
    mask[1][1] = true;
    mask[3][0] = true;
    mask[3][2] = true;
}

void Matrix::InitCode()
{
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            code[i][j] = rand() % 254 + 1;
}

void Matrix::RotateMask()
{
    bool tmpMask[4][4];
    for (int i=0; i<4; i++)
       for (int j=0; j<4; j++)
            tmpMask[j][3-i] = mask[i][j];
    for (int i=0; i<4; i++)
        for (int j=0; j < 4; j++)
            mask[i][j] = tmpMask[i][j];


}

void Matrix::WriteBlok(QString block)
{
    short stringIterator = 0;
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
        {
            if (stringIterator > 3)
                break;
            if (mask[i][j] == true)
            {
                code[i][j] = block[stringIterator++];
            }
        }
}

QString Matrix::ReadBlock()
{
    QString result = "";
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            if (mask[i][j] == true)
                result += code[i][j];
    return result;
}

bool Matrix::EmptyState()
{
    if (position >= 4)
        return true;
    return false;
}

QString Matrix::CompileStr(QList<QString> inputSeries)
{
    QString result = "";
    for (QString curStr : inputSeries)
    {
        result += curStr;
    }
    return result;
}
