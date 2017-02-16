#include "alphabet.h"

Alphabet::Alphabet()
{

}

Alphabet::Alphabet(QList<char> set)
{
    letterContainer = set;
}

char Alphabet::GetChar(int n)
{
    return letterContainer[n];
}

int Alphabet::GetSize()
{
    return letterContainer.size();
}
