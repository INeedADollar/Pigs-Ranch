#ifndef PIGSHALL_H
#define PIGSHALL_H

#include "pigsbox.h"

#include <QVector>
#include <QSize>

class PigsBoxData {

public:
    void setLittlePigsBoxesNumber(int);
    int getLittlePigsBoxesNumber();

    void setNormalPigsBoxesNumber(int);
    int getNormalPigsBoxesNumber();

private:
    int littlePigsBoxesNumber;
    int normalPigsBoxesNumber;
};

/******************** PigsHall class *************************/
class PigsHall
{
public:
    PigsHall();

    void addBox(PigsBox*);
    QVector<PigsBox*> pigsBoxes();

    static PigsBoxData calculateBoxesNumberFromInput(QSize, int, int, bool);

private:
    QVector<PigsBox*> boxes;
};
/**************************************************************/

#endif // PIGSHALL_H
