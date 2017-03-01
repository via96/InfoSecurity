#ifndef INSTALLER_H
#define INSTALLER_H
#include <QCoreApplication>
#include <QtCore>
#include <QDir>
#include <QFile>
#include <iostream>

using namespace std;

class Installer
{
public:
    Installer();
    static void Install(QString path);
};

#endif // INSTALLER_H
