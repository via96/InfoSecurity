#ifndef ALPHABET_H
#define ALPHABET_H
#include <iostream>
#include <QCoreApplication>

class Alphabet
{
public:
    Alphabet();
    Alphabet(QList<char> set);
    char GetChar(int n);
    int GetSize();
private:
    QList<char> letterContainer;
};

#endif // ALPHABET_H
