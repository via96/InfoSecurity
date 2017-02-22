#include <QCoreApplication>
#include <iostream>
#include <database.h>
#include <filemanager.h>

using namespace std;

int main()
{
    string dialog;
    Database base;
    FileManager file;
    bool isBase = false;
    while (true)
    {
        cout << ">>> ";
        cin >> dialog;
        if (dialog == "load")
        {
            base = file.LoadBase();
            isBase = true;
            cout << "Base loaded" << endl;
        }

        if (dialog == "save")
        {
            if (isBase)
                file.SaveBase(base);
            cout << "Base saved" << endl;
        }

        if (dialog == "add")
        {
            cout << "Input file name: ";
            char temp[100];
            cin >> temp;
            QString fileName = QString::fromStdString(temp);
            QString hash = file.GetFileHash(fileName);
            base.AddField(fileName, hash);
            isBase = true;
        }

        if (dialog == "changed")
        {
            cout << "Input file name: ";
            char temp[100];
            cin >> temp;
            QString fileName = QString::fromStdString(temp);
            if (base.GetHash(fileName) == file.GetFileHash(fileName))
                cout << "File has not changed" << endl;
            else
                cout << "File has been changed" << endl;
        }

        if (dialog == "quit")
        {
            break;
        }
    }
    return 0;
}
