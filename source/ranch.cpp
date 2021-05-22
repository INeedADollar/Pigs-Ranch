#include "headers/ranch.h"

#include <QJsonArray>
#include <QStringList>
#include <QDebug>

Ranch *ranch = new Ranch;

/************************* Ranch class *************************/
void Ranch::addHall(PigsHall* hall){
    halls.push_back(hall);
}

QVector<PigsHall*> Ranch::pigsHalls() {
    return halls;
}

QJsonObject Ranch::getJson() {
    QJsonObject ranch;
    QJsonArray jHalls;

    for(PigsHall *hall : halls)
        jHalls.push_back(hall->getJson());

    ranch.insert("Ranch", jHalls);
    return ranch;
}

int Ranch::loadRanchFromJson(QJsonDocument document){
    halls.clear();

    QJsonArray halls = document.object()["Ranch"].toArray();
    if(halls.isEmpty())
        return 0;

    QJsonArray hallBoxes;
    QJsonObject boxObj;
    PigsHall *currentHall;

    int i = 0, j = 0;
    for(QJsonValue hall : halls) {
        i++;
        j = 0;

        QString hallName = QString("Hall #%1").arg(i);
        hallBoxes = hall.toObject()[hallName].toObject()["boxes"].toArray();
        if(hallBoxes.isEmpty())
            return 0;

        currentHall = new PigsHall;
        currentHall->setHallName(hallName);
        QStringList sizeMembers = hall.toObject()[hallName].toObject()["hallSize"].toString().split("x");
        QSize hallSize;

        if(sizeMembers.length() < 2)
            hallSize = QSize(100, 20);
        else {
            bool isWidthValid, isLengthValid;
            int length = sizeMembers[0].toInt(&isLengthValid);
            int width = sizeMembers[1].toInt(&isWidthValid);

            if(!isWidthValid || !isLengthValid)
                hallSize = QSize(100, 20);
            else
                hallSize = QSize(length, width);
        }

        qDebug() << hallSize;
        currentHall->setSize(hallSize);
        for(QJsonValue box : hallBoxes){
            j++;
            QString boxName = QString("Box #%1").arg(j);
            boxObj = box.toObject()[QString("Box #%1").arg(j)].toObject();
            if(boxObj.isEmpty())
                return 0;

            if(boxObj["boxType"].toInt() == PigsBoxType::LittleBox) {
                LittlePigsBox *pBox = new LittlePigsBox;
                pBox->setBoxName(boxName);
                pBox->setBoxHallName(boxObj["boxHallName"].toString());
                pBox->setPigsNumber(boxObj["pigsNumber"].toInt());
                pBox->setPopulationDate(boxObj["populationDate"].toString());
                pBox->setReleaseDate(boxObj["releaseDate"].toString());
                currentHall->addBox(pBox);
            }
            else {
                NormalPigsBox *pBox = new NormalPigsBox;
                pBox->setBoxName(boxName);
                pBox->setBoxHallName(boxObj["boxHallName"].toString());
                pBox->setPigsNumber(boxObj["pigsNumber"].toInt());
                pBox->setPopulationDate(boxObj["populationDate"].toString());
                pBox->setReleaseDate(boxObj["releaseDate"].toString());
                currentHall->addBox(pBox);
            }

        }

        addHall(currentHall);
    }

    return 1;
}
/**************************************************************/
