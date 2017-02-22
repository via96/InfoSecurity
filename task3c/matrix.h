#ifndef MATRIX_H
#define MATRIX_H
#include <QCoreApplication>
#include <QSet>
#include <ctime>

class Matrix
{
public:
    Matrix();
    bool EncodeWord(QString inputStr);
    QString DecodeWord(QString inputStr);
    QString GetCodeWord();
private:
    bool mask[4][4];
    QChar code[4][4];
    void FillMask();
    void InitCode();
    int position;
    void RotateMask();
    int size;
    void WriteBlok(QString block);
    QString ReadBlock();
    bool EmptyState();
    QString CompileStr(QList<QString> inputSeries);
};

#endif // MATRIX_H
