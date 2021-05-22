#include "headers/pigshall.h"
#include "headers/hallwindow.h"
#include "headers/pigshallinfodialog.h"

#include <cmath>
#include <QJsonArray>
#include <QApplication>

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
    HallWindow *hallWindow;
    for(QWidget *wind : qApp->topLevelWidgets()) {
        hallWindow = qobject_cast<HallWindow*>(wind);
        if(hallWindow && hallWindow->isVisible() && hallWindow->getPigsHall() == this) {
            hallWindow->activateWindow();
            return;
        }
    }

    HallWindow *wind = new HallWindow;
    wind->setWindowTitle(hallName);
    wind->setPigsHall(this);
    wind->show();
}

void PigsHall::showHallStatistics(){
    int littlePigsNumber = 0, littlePigsBoxesNumber = 0, normalPigsNumber = 0, normalPigsBoxesNumber = 0;

    for(PigsBox *box : boxes)
        if(box->boxType().getBoxType() == PigsBoxType::LittleBox) {
            littlePigsNumber += box->getPigsNumber();
            littlePigsBoxesNumber += 1;
        }
        else {
            normalPigsNumber += box->getPigsNumber();
            normalPigsBoxesNumber += 1;
        }

    PigsHallInfoDialog *d = new PigsHallInfoDialog;
    d->setWindowTitle("Hall statistics");
    d->setHallName(hallName);
    d->setLittleBoxesNumber(littlePigsBoxesNumber);
    d->setNormalBoxesNumber(normalPigsBoxesNumber);
    d->setLittlePigsNumber(littlePigsNumber);
    d->setNormalPigsNumber(normalPigsNumber);
    d->show();
}

QJsonObject PigsHall::getJson() {
    QJsonObject hall;
    QJsonObject hallData;
    QJsonArray jBoxes;

    for(PigsBox* box : boxes)
        jBoxes.push_back(box->getJson());

    hallData.insert("hallSize", QString("%1x%2").arg(hallSize.width()).arg(hallSize.height()));
    hallData.insert("boxes", jBoxes);

    hall.insert(hallName, hallData);
    return hall;
}

PigsBoxData PigsHall::calculateBoxesNumberFromInput(QSize hallSize, int littlePigsNumber, int normalPigsNumber, bool littlePigsBoxesFirst = 1) {
    PigsBoxData data;

    QPoint currentPoint = QPoint(1, 1);
    int pigsNumberToAdd;

    while(littlePigsNumber > 0 || normalPigsNumber > 0){
        if(littlePigsBoxesFirst){
            if(littlePigsNumber > 0) {
                data.setLittlePigsBoxesNumber(data.getLittlePigsBoxesNumber() + 1);
                if(littlePigsNumber <= 25) {
                    pigsNumberToAdd = littlePigsNumber % 25 ? littlePigsNumber % 25 : 25;
                    data.setLittlePigsNumber(data.getLittlePigsNumber() + pigsNumberToAdd);
                }
                else
                    data.setLittlePigsNumber(data.getLittlePigsNumber() + 25);

                littlePigsNumber -= 25;

                currentPoint.setX(currentPoint.x() + 7);
                if(currentPoint.x() > hallSize.width() && currentPoint.y() != 1){
                    if(littlePigsNumber > 0) {
                        double intPart;
                        int littlePigsOverflow = modf(littlePigsNumber / 25, &intPart) != 0 ? littlePigsNumber / 25 + 1 : littlePigsNumber / 25;
                        data.setOverflowLittlePigsBoxesNumber(littlePigsOverflow);
                        data.setOverflowLittlePigsNumber(littlePigsNumber);
                    }

                    if(normalPigsNumber > 0) {
                        double intPart;
                        int normalPigsOverflow = modf(normalPigsNumber / 25, &intPart) != 0 ? normalPigsNumber / 25 + 1 : normalPigsNumber / 25;
                        data.setOverflowNormalPigsBoxesNumber(normalPigsOverflow);
                        data.setOverflowNormalPigsBoxesNumber(normalPigsNumber);
                    }

                    break;
                }

                if(currentPoint.x() > hallSize.width() && currentPoint.y() == 1)
                    currentPoint = QPoint(1, hallSize.height() - 8);
            }
            else {
                data.setNormalPigsBoxesNumber(data.getNormalPigsBoxesNumber() + 1);
                if(normalPigsNumber <= 25) {
                    pigsNumberToAdd = normalPigsNumber % 25 ? normalPigsNumber % 25 : 25;
                    data.setNormalPigsNumber(data.getNormalPigsNumber() + pigsNumberToAdd);
                }
                else
                    data.setNormalPigsNumber(data.getNormalPigsNumber() + 25);

                normalPigsNumber -= 25;

                currentPoint.setX(currentPoint.x() + 22);
                if(currentPoint.x() > hallSize.width() && currentPoint.y() != 1) {
                    if(littlePigsNumber > 0) {
                        double intPart;
                        int littlePigsOverflow = modf(littlePigsNumber / 25, &intPart) != 0 ? littlePigsNumber / 25 + 1 : littlePigsNumber / 25;
                        data.setOverflowLittlePigsBoxesNumber(littlePigsOverflow);
                        data.setOverflowLittlePigsNumber(littlePigsNumber);
                    }

                    if(normalPigsNumber > 0) {
                        double intPart;
                        int normalPigsOverflow = modf(normalPigsNumber / 25, &intPart) != 0 ? normalPigsNumber / 25 + 1 : normalPigsNumber / 25;
                        data.setOverflowNormalPigsBoxesNumber(normalPigsOverflow);
                        data.setOverflowNormalPigsBoxesNumber(normalPigsNumber);
                    }

                    break;
                }

                if(currentPoint.x() > hallSize.width() && currentPoint.y() == 1)
                    currentPoint = QPoint(1, hallSize.height() - 8);
            }
        }
        else {
            if(normalPigsNumber > 0) {
                data.setNormalPigsBoxesNumber(data.getNormalPigsBoxesNumber() + 1);
                if(normalPigsNumber <= 25) {
                    pigsNumberToAdd = normalPigsNumber % 25 ? normalPigsNumber % 25 : 25;
                    data.setNormalPigsNumber(data.getNormalPigsNumber() + pigsNumberToAdd);
                }
                else
                    data.setNormalPigsNumber(data.getNormalPigsNumber() + 25);

                normalPigsNumber -= 25;

                currentPoint.setX(currentPoint.x() + 22);
                if(currentPoint.x() > hallSize.width() && currentPoint.y() != 1) {
                    if(littlePigsNumber > 0) {
                        double intPart;
                        int littlePigsOverflow = modf(littlePigsNumber / 25, &intPart) != 0 ? littlePigsNumber / 25 + 1 : littlePigsNumber / 25;
                        data.setOverflowLittlePigsBoxesNumber(littlePigsOverflow);
                        data.setOverflowLittlePigsNumber(littlePigsNumber);
                    }

                    if(normalPigsNumber > 0) {
                        double intPart;
                        int normalPigsOverflow = modf(normalPigsNumber / 25, &intPart) != 0 ? normalPigsNumber / 25 + 1 : normalPigsNumber / 25;
                        data.setOverflowNormalPigsBoxesNumber(normalPigsOverflow);
                        data.setOverflowNormalPigsBoxesNumber(normalPigsNumber);
                    }

                    break;
                }

                if(currentPoint.x() > hallSize.width() && currentPoint.y() == 1)
                    currentPoint = QPoint(1, hallSize.height() - 8);

            }
            else {
                data.setLittlePigsBoxesNumber(data.getLittlePigsBoxesNumber() + 1);
                if(littlePigsNumber <= 25) {
                    pigsNumberToAdd = littlePigsNumber % 25 ? littlePigsNumber % 25 : 25;
                    data.setLittlePigsNumber(data.getLittlePigsNumber() + pigsNumberToAdd);
                }
                else
                    data.setLittlePigsNumber(data.getLittlePigsNumber() + 25);

                littlePigsNumber -= 25;

                currentPoint.setX(currentPoint.x() + 7);
                if(currentPoint.x() > hallSize.width() && currentPoint.y() != 1) {
                    if(littlePigsNumber > 0) {
                        double intPart;
                        int littlePigsOverflow = modf(littlePigsNumber / 25, &intPart) != 0 ? littlePigsNumber / 25 + 1 : littlePigsNumber / 25;
                        data.setOverflowLittlePigsBoxesNumber(littlePigsOverflow);
                        data.setOverflowLittlePigsNumber(littlePigsNumber);
                    }

                    if(normalPigsNumber > 0) {
                        double intPart;
                        int normalPigsOverflow = modf(normalPigsNumber / 25, &intPart) != 0 ? normalPigsNumber / 25 + 1 : normalPigsNumber / 25;
                        data.setOverflowNormalPigsBoxesNumber(normalPigsOverflow);
                        data.setOverflowNormalPigsBoxesNumber(normalPigsNumber);
                    }

                    break;
                }

                if(currentPoint.x() > hallSize.width() && currentPoint.y() == 1)
                    currentPoint = QPoint(1, hallSize.height() - 8);
            }
        }
    }

    return data;
}

/**************************************************************/
