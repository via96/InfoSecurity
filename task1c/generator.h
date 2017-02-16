#ifndef GENERATOR_H
#define GENERATOR_H
#include <QCoreApplication>
#include <iostream>
#include <ctime>

class Generator
{
public:
    Generator();
    QList<QString> Generate(int amount, int lenght);
private:
    QList<char> CreateAlphabet();
    QList<char> alphabet;
};

#endif // GENERATOR_H
