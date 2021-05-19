#ifndef PIGSHALL_H
#define PIGSHALL_H

#include "pigsbox.h"
#include <QVector>

class PigsHall
{
public:
    PigsHall();

    void addBox(PigsBox);
    QVector<PigsBox> pigsBoxes();

private:
    QVector<PigsBox> boxes;
};

#endif // PIGSHALL_H
