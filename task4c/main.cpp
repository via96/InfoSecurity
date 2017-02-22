#include <QCoreApplication>
#include <iostream>
#include <converter.h>
#include <QBitArray>

using namespace std;

int main()
{
    string temp;
    cin >> temp;
    QString inputStr = QString::fromStdString(temp);
    QBitArray bitSeries = Converter::StrToBit(inputStr);
    QString outStr = Converter::BitToStr(bitSeries);
    cout << outStr.toStdString();
    return 0;
}
