#include "generator.h"

Generator::Generator()
{
    srand(time(0));
    alphabet = CreateAlphabet();
}

QList<QString> Generator::Generate(int amount, int length)
{
    QList<QString> result;
    for (int passCount = 0; passCount < amount; passCount++)
    {
        QString curPass = "";
        for (int lenCount = 0; lenCount < length; lenCount++)
        {
            char temp = alphabet[rand()%alphabet.length()];
            curPass += temp;
        }
        result.append(curPass);
    }
    return result;
}

QList<char> Generator::CreateAlphabet()
{
    QList<char> res;
    for (char a = 'A'; a <= 'Z'; a++)
        res.append(a);
    for (char a = 'a'; a <= 'z'; a++)
        res.append(a);
    for (char a = '0'; a <= '9'; a++)
        res.append(a);
    return res;
}
