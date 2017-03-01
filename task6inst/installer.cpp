#include "installer.h"

Installer::Installer()
{

}

void Installer::Install(QString path)
{
    QDir directory("install");
    QDir target(path);
    target.mkpath("bin");
    path += "/bin/";
    QFileInfoList infoList = directory.entryInfoList();
    for (auto fInfo : infoList)
    {
        if (fInfo.fileName() != "." && fInfo.fileName() != "..")
        {
            if (QFile::copy(fInfo.filePath(), path + fInfo.fileName()))
                cout << fInfo.filePath().toStdString() << " | " << fInfo.fileName().toStdString() << endl;
        }
    }
}
