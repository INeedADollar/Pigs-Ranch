#include "headers/pigshall.h"

void PigsBoxData::setLittlePigsBoxesNumber(int number) {
    littlePigsBoxesNumber = number;
}

int PigsBoxData::getLittlePigsBoxesNumber() {
    return littlePigsBoxesNumber;
}

void PigsBoxData::setNormalPigsBoxesNumber(int number) {
    normalPigsBoxesNumber = number;
}

int PigsBoxData::getNormalPigsBoxesNumber() {
    return normalPigsBoxesNumber;
}

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

PigsBoxData PigsHall::calculateBoxesNumberFromInput(QSize hallSize, int littlePigsNumber, int normalPigsNumber, bool littlePigsBoxesFirst = 1) {
    PigsBoxData data;

    if(littlePigsBoxesFirst){

    }
    else {

    }
}

/**************************************************************/
