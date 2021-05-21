#include "headers/ranch.h"

#include <QJsonArray>
#include <QStringList>

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

void Ranch::loadRanchFromJson(QJsonDocument document){
    halls.clear();

    QJsonArray halls = document.object()["Ranch"].toArray();
    QJsonArray hallBoxes;
    QJsonObject boxObj;
    PigsHall *currentHall;

    for(QJsonValue hall : halls) {
        hallBoxes = hall.toArray();
        currentHall = new PigsHall;

        for(QJsonValue box : hallBoxes){
            boxObj = box.toObject();
            QString boxName = boxObj.keys()[0];

            if(boxObj[boxName].toObject()["boxHallName"].toInt() == PigsBoxType::LittleBox) {
                LittlePigsBox *pBox = new LittlePigsBox;
                pBox->setBoxName(boxName);
                pBox->setBoxHallName(boxObj[boxName].toObject()["boxHallName"].toString());
                pBox->setPigsNumber(boxObj[boxName].toObject()["pigsNumber"].toInt());
                pBox->setPopulationDate(boxObj[boxName].toObject()["populationDate"].toString());
                pBox->setReleaseDate(boxObj[boxName].toObject()["populationDate"].toString());
                currentHall->addBox(pBox);
            }
            else {
                NormalPigsBox *pBox = new NormalPigsBox;
                pBox->setBoxName(boxName);
                pBox->setBoxHallName(boxObj[boxName].toObject()["boxHallName"].toString());
                pBox->setPigsNumber(boxObj[boxName].toObject()["pigsNumber"].toInt());
                pBox->setPopulationDate(boxObj[boxName].toObject()["populationDate"].toString());
                pBox->setReleaseDate(boxObj[boxName].toObject()["populationDate"].toString());
                currentHall->addBox(pBox);
            }

        }

        addHall(currentHall);
    }
}
/**************************************************************/
