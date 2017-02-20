#ifndef MATRIX_H
#define MATRIX_H
#include <QCoreApplication>
#include <QSet>

class Matrix
{
public:
    Matrix();
private:
    bool mask[4][4];
    void FillMask();
    int position;
    QSet<int> positionList;
    void RotateMask();
    int size;
};

#endif // MATRIX_H
