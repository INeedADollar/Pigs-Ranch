#ifndef PIGSHALL_H
#define PIGSHALL_H

#include "pigsbox.h"

#include <QVector>
#include <QSize>
#include <QJsonObject>

/********************** PigsBoxData class *********************/
class PigsBoxData {

public:
    void setLittlePigsBoxesNumber(int);
    int getLittlePigsBoxesNumber();

    void setOverflowLittlePigsBoxesNumber(int);
    int getOverflowLittlePigsBoxesNumber();

    void setNormalPigsBoxesNumber(int);
    int getNormalPigsBoxesNumber();

    void setOverflowNormalPigsBoxesNumber(int);
    int getOverflowNormalPigsBoxesNumber();

    void setLittlePigsNumber(int);
    int getLittlePigsNumber();

    void setOverflowLittlePigsNumber(int);
    int getOverflowLittlePigsNumber();

    void setNormalPigsNumber(int);
    int getNormalPigsNumber();

    void setOveflowNormalPigsNumber(int);
    int getOveflowNormalPigsNumber();

private:
    int littlePigsBoxesNumber = 0;
    int overflowLittlePigsBoxesNumber = 0;
    int normalPigsBoxesNumber = 0;
    int overflowNormalPigsBoxesNumber = 0;
    int littlePigsNumber = 0;
    int overflowLittlePigsNumber = 0;
    int normalPigsNumber = 0;
    int overflowNormalPigsNumber = 0;
};
/*************************************************************/

/******************** PigsHall class *************************/
class PigsHall
{
public:
    void addBox(PigsBox*);
    QVector<PigsBox*> pigsBoxes();

    void setSize(QSize);
    QSize getSize();

    void setHallName(QString);
    QString getHallName();

    void showHallWindow();
    QJsonObject getJson();

    static PigsBoxData calculateBoxesNumberFromInput(QSize, int, int, bool);

private:
    QVector<PigsBox*> boxes;
    QSize hallSize; //meters
    QString hallName;
};
/**************************************************************/

#endif // PIGSHALL_H
