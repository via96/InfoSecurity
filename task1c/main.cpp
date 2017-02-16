#include <QCoreApplication>
#include <iostream>
#include <generator.h>
#include <converter.h>
#include <filemanager.h>

using namespace std;

int main()
{
    Generator generator;
    Converter converter;
    FileManager file("passwords");
    while (true)
    {
        cout << ">>> ";
        char dialog;
        cin >> dialog;
        if (dialog == 'e')
        {
            cout << "Input password count: ";
            int countPass;
            cin >> countPass;
            cout << "Inpun password length: ";
            int lengthPass;
            cin >> lengthPass;
            cout << "Input key: ";
            char q[100];
            cin >> q;
            QString key = QString::fromStdString(q);
            QList<QString> passSet = generator.Generate(countPass, lengthPass);
            file.Write(converter.EncodeSeries(passSet, key));
            for (QString curStr : passSet)
            {
                cout << curStr.toStdString() << endl;
            }
        }

        if (dialog == 'd')
        {
            cout << "Input key: ";
            char q[100];
            cin >> q;
            QString key = QString::fromStdString(q);
            QList<QString> passSet = converter.DecodeSeries(file.Read(), key);
            for (QString curStr : passSet)
                cout << curStr.toStdString() << endl;
        }

        if (dialog == 't')
        {
            QString text = "ebarz";
            cout << text.toStdString() << endl;
            QString enText = converter.Encode(text, "ntnmf");
            cout << enText.toStdString() << endl;
            cout << converter.Decode(enText, "ntnmf").toStdString() << endl;
        }

        if (dialog == 'q')
        {
            break;
        }
    }
    return 0;
}
