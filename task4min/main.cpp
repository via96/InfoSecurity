#include <QCoreApplication>
#include <iostream>
#include <mfile.h>

using namespace std;

int main()
{
    MFile file;
    while (true)
    {
        cout << "Input file name: ";
        string temp;
        cin >> temp;
        if (temp == "-q")
            break;
        QString fileName = QString::fromStdString(temp);
        if (file.Delete(fileName))
            cout << "File was deleted" << endl;
        else
            cout << "Can't remove file" << endl;
    }
    return 0;
}
