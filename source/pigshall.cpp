#include "headers/pigshall.h"
#include "headers/hallwindow.h"

#include <QJsonArray>

/********************** PigsBoxData class *********************/
void PigsBoxData::setLittlePigsBoxesNumber(int number) {
    littlePigsBoxesNumber = number;
}

int PigsBoxData::getLittlePigsBoxesNumber() {
    return littlePigsBoxesNumber;
}

void PigsBoxData::setOverflowLittlePigsBoxesNumber(int number) {
    overflowLittlePigsBoxesNumber = number;
}

int PigsBoxData::getOverflowLittlePigsBoxesNumber() {
    return overflowLittlePigsBoxesNumber;
}

void PigsBoxData::setNormalPigsBoxesNumber(int number) {
    normalPigsBoxesNumber = number;
}

int PigsBoxData::getNormalPigsBoxesNumber() {
    return normalPigsBoxesNumber;
}

void PigsBoxData::setOverflowNormalPigsBoxesNumber(int number) {
    overflowNormalPigsBoxesNumber = number;
}

int PigsBoxData::getOverflowNormalPigsBoxesNumber() {
    return overflowNormalPigsBoxesNumber;
}

void PigsBoxData::setLittlePigsNumber(int number){
    littlePigsNumber = number;
}

int PigsBoxData::getLittlePigsNumber(){
    return littlePigsNumber;
}

void PigsBoxData::setOverflowLittlePigsNumber(int number){
    overflowLittlePigsNumber = number;
}

int PigsBoxData::getOverflowLittlePigsNumber(){
    return overflowLittlePigsNumber;
}

void PigsBoxData::setNormalPigsNumber(int number){
    normalPigsNumber = number;
}

int PigsBoxData::getNormalPigsNumber(){
    return normalPigsNumber;
}

void PigsBoxData::setOveflowNormalPigsNumber(int number){
    overflowNormalPigsNumber = number;
}

int PigsBoxData::getOveflowNormalPigsNumber(){
    return overflowNormalPigsNumber;
}
/*************************************************************/

/******************** PigsHall class *************************/
void PigsHall::addBox(PigsBox* box) {
    boxes.push_back(box);
}

QVector<PigsBox*> PigsHall::pigsBoxes() {
    return boxes;
}

void PigsHall::setSize(QSize size){
    hallSize = size; //metri
}

QSize PigsHall::getSize() {
    return hallSize;
}

void PigsHall::setHallName(QString name){
    hallName = name;
}

QString PigsHall::getHallName() {
    return hallName;
}

void PigsHall::showHallWindow() {
    HallWindow *wind = new HallWindow;
    wind->setWindowTitle(hallName);
    wind->setPigsHall(this);
    wind->show();
}

QJsonObject PigsHall::getJson() {
    QJsonObject hall;
    QJsonArray jBoxes;

    for(PigsBox* box : boxes)
        jBoxes.push_back(box->getJson());

    hall.insert(hallName, jBoxes);
    return hall;
}

PigsBoxData PigsHall::calculateBoxesNumberFromInput(QSize hallSize, int littlePigsNumber, int normalPigsNumber, bool littlePigsBoxesFirst = 1) {
    PigsBoxData data;

    QPoint currentPoint = QPoint(1, 1);

    while(littlePigsNumber > 0 && normalPigsNumber > 0){
        if(littlePigsBoxesFirst){
            if(littlePigsNumber > 0) {
                data.setLittlePigsBoxesNumber(data.getLittlePigsBoxesNumber() + 1);

                currentPoint.setX(currentPoint.x() + 6);
                if(currentPoint.x() > hallSize.width() && currentPoint.y() == 1)
                    currentPoint.setY(hallSize.height() - 10);
                else {
                    if(littlePigsNumber > 0) {
                        data.setOverflowLittlePigsBoxesNumber(littlePigsNumber % 25);
                        data.setOverflowLittlePigsNumber(littlePigsNumber);
                    }

                    if(normalPigsNumber > 0) {
                        data.setOverflowNormalPigsBoxesNumber(normalPigsNumber % 25);
                        data.setOverflowNormalPigsBoxesNumber(normalPigsNumber);
                    }

                    break;
                }
                littlePigsNumber -= 25;
            }
            else {
                data.setNormalPigsBoxesNumber(data.getNormalPigsBoxesNumber() + 1);

                currentPoint.setX(currentPoint.x() + 6);
                if(currentPoint.x() > hallSize.width() && currentPoint.y() == 1)
                    currentPoint.setY(hallSize.height() - 10);
                else {
                    if(littlePigsNumber > 0) {
                        data.setOverflowLittlePigsBoxesNumber(littlePigsNumber % 25);
                        data.setOverflowLittlePigsNumber(littlePigsNumber);
                    }

                    if(normalPigsNumber > 0) {
                        data.setOverflowNormalPigsBoxesNumber(normalPigsNumber % 25);
                        data.setOverflowNormalPigsBoxesNumber(normalPigsNumber);
                    }

                    break;
                }
                normalPigsNumber -= 25;
            }
        }
        else {
            if(normalPigsNumber > 0) {
                data.setLittlePigsBoxesNumber(data.getNormalPigsBoxesNumber() + 1);

                currentPoint.setX(currentPoint.x() + 6);
                if(currentPoint.x() > hallSize.width() && currentPoint.y() == 1)
                    currentPoint.setY(hallSize.height() - 10);

                normalPigsNumber -= 25;
            }
            else {
                data.setLittlePigsBoxesNumber(data.getLittlePigsBoxesNumber() + 1);

                currentPoint.setX(currentPoint.x() + 6);
                if(currentPoint.x() > hallSize.width() && currentPoint.y() == 1)
                    currentPoint.setY(hallSize.height() - 10);

                littlePigsNumber -= 25;
            }
        }
    }

    return data;
}

/**************************************************************/
