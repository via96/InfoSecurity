#include "matrix.h"

Matrix::Matrix()
{
    FillMask();
    size = 4;
    position = 0;
    positionList << position;
}

void Matrix::FillMask()
{
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            mask[i][j] = false;
    mask[2][0] = true;
    mask[1][1] = true;
    mask[0][3] = true;
    mask[2][3] = true;
}

void Matrix::RotateMask()
{
    for(int i = 0;i <= 3;i++)
        for(int j = i+1;j < size-i; j++)
        {
            int k = mask[j][size-i-1];
            mask[j][size-i-1] = mask[i][j];
            mask[i][j] = mask[size-j-1][i];
            mask[size-j-1][i] = mask[size-1-i][size-1-j];
            mask[size-1-i][size-1-j] = k;
        }
    position = ++position % 4;
    if (!positionList.contains(position))
        positionList << position;
}
