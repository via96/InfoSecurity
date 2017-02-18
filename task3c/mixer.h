 #ifndef MIXER_H
#define MIXER_H
#include <QCoreApplication>

class Mixer
{
public:
    Mixer();
    static QString MixBlock(QString block, QString mask);
private:

};

#endif // MIXER_H
