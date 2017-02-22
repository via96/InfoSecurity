 #ifndef MIXER_H
#define MIXER_H
#include <QCoreApplication>

class Mixer
{
public:
    Mixer();
    static QString CodeBlock(QString block, QString mask);
    static QString DecodeBlock(QString block, QString mask);
private:

};

#endif // MIXER_H
