#include <QCoreApplication>
#include <iostream>
#include <converter.h>
#include <filemanager.h>
#include <matrix.h>

using namespace std;

int main()
{
    char dialog = 'a';
    while (true)
    {
        Converter converter;
        FileManager file;
        Matrix matrix;
        cout << ">>> ";
        cin >> dialog;
        if (dialog == 'e') //encode
        {
            cout << "Method: ";
            cin >> dialog;
            if (dialog == 'l')
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
            if (dialog == 'k')
            {
                cout << "Input text: ";
                char temp[100];
                cin >> temp;
                QString inputStr = QString::fromStdString(temp);
                if (matrix.EncodeWord(inputStr))
                {
                    cout << matrix.GetCodeWord().toStdString() << endl;
                    file.Write(matrix.GetCodeWord(), "text");
                }
                else
                    cout << "Encode error." << endl;
            }
            if (dialog == 'm')
            {
                cout << "Input text: ";
                char temp[100];
                cin >> temp;
                QString inputStr = QString::fromStdString(temp);
                cout << "Input mask: ";
                cin >> temp;
                QString mask = QString::fromStdString(temp);
                QString encodeStr = converter.MyEncode(inputStr, mask);
                file.Write(encodeStr, "text");
            }
        }

        if (dialog == 'd') //decode
        {
            cout << "Method: ";
            cin >> dialog;
            if (dialog == 'l')
            {
                char temp[100];
                cout << "Input mask: ";
                cin >> temp;
                QString mask = QString::fromStdString(temp);
                QString decodeStr = converter.DecodeLine(file.Read("text"), mask);
                cout << decodeStr.toStdString() << endl;
            }
            if (dialog == 'k')
            {
                QString decodeStr = matrix.DecodeWord(file.Read("text"));
                cout << decodeStr.toStdString() << endl;
            }
            if (dialog == 'm')
            {
                char temp[100];
                cout << "Input mask: ";
                cin >> temp;
                QString mask = QString::fromStdString(temp);
                QString decodeStr = converter.MyDecode(file.Read("text"), mask);
                cout << decodeStr.toStdString() << endl;
            }
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
