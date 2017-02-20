#include <QCoreApplication>
#include <iostream>
#include <converter.h>
#include <filemanager.h>

using namespace std;

int main()
{
    char dialog;
    while (true)
    {
        Converter converter;
        FileManager file;
        dialog = 'a';
        cout << ">>> ";
        cin >> dialog;
        if (dialog == 'e') //encode
        {
            cout << "Input text: ";
            char temp[100];
            cin >> temp;
            QString inputStr = QString::fromStdString(temp);
            cout << "Input mask: ";
            cin >> temp;
            QString mask = QString::fromStdString(temp);
            QString encodeStr = converter.EncodeLine(inputStr, mask);
            file.Write(encodeStr, "text");
        }

        if (dialog == 'd') //decode
        {
            char temp[100];
            cout << "Input mask: ";
            cin >> temp;
            QString mask = QString::fromStdString(temp);
            QString decodeStr = converter.DecodeLine(file.Read("text"), mask);
            cout << decodeStr.toStdString() << endl;
        }

        if (dialog == 'p')
        {
            cout << file.Read("text").toStdString() << endl;
        }

        if (dialog == 'q')
        {
            break;
        }
    }
    return 0;
}
