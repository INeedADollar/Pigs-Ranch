#ifndef RANCH_H
#define RANCH_H

#include "pigshall.h"
#include <QVector>

class Ranch
{
public:
    Ranch();

    void addHall(PigsHall);
    QVector<PigsHall> pigsHalls();

private:
    QVector<PigsHall> halls;
};

#endif // RANCH_H