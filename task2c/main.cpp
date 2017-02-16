#include <QCoreApplication>
#include <iostream>
#include <converter.h>
#include <filemanager.h>
#include <stdio.h>

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
            cout << "Method: ";
            cin >> dialog;
            cout << "Input text: ";
            char temp[100];
            cin >> temp;
            QString inputStr = QString::fromStdString(temp);
            QString encodeStr;
            if (dialog == 's') //single
            {
                cout << "Input offset: ";
                int offset;
                cin >> offset;
                encodeStr = converter.EncodeSingle(inputStr, offset);
            }
            if (dialog == 'm') //multiple
            {
                cout << "Input key: ";
                char q[100];
                cin >> q;
                QString key = QString::fromStdString(q);
                encodeStr = converter.EncodeMultiple(inputStr, key);
            }
            if (dialog == 'g') //generate
            {
                QString key = converter.GenerateKey(inputStr.length());
                encodeStr = converter.EncodeGenerate(inputStr, key);
                file.Write(key, "key");
            }
            file.Write(encodeStr, "text");
        }

        if (dialog == 'd') //decode
        {
            cout << "Method: ";
            cin >> dialog;
            QString encodeStr = file.Read("text");
            QString decodeStr;
            if (dialog == 's') //single
            {
                cout << "Input offset: ";
                int offset;
                cin >> offset;
                decodeStr = converter.DecodeSingle(encodeStr, offset);
            }
            if (dialog == 'm') //multiple
            {
                cout << "Input key: ";
                char q[100];
                cin >> q;
                QString key = QString::fromStdString(q);
                decodeStr = converter.DecodeMultiple(encodeStr, key);
            }
            if (dialog == 'g') //generate
            {
                QString key = file.Read("key");
                decodeStr = converter.DecodeGenerate(encodeStr, key);
            }
            cout << decodeStr.toStdString() << endl;;

        }

        if (dialog == 'q')
        {
            break;
        }
    }
    return 0;
}
