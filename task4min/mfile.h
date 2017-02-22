#ifndef MFILE_H
#define MFILE_H
#include <QCoreApplication>
#include <QFile>

class MFile
{
public:
    MFile();
    bool Delete(QString path);
private:
    int GetFileSize(QString path);
};

#endif // MFILE_H
