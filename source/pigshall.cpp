#include "headers/pigshall.h"

/******************** PigsHall class *************************/
PigsHall::PigsHall()
{

}

void PigsHall::addBox(PigsBox* box) {
    boxes.push_back(box);
}

QVector<PigsBox*> PigsHall::pigsBoxes() {
    return boxes;
}
/**************************************************************/
