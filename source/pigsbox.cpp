#include "headers/pigsbox.h"
#include "headers/pigsboxinfodialog.h"

/********************** PigsBoxType class ********************/
void PigsBoxType::setBoxType(PigsBoxType::BoxType type) {
    boxType = type;
}

PigsBoxType::BoxType PigsBoxType::getBoxType() {
    return boxType;
}

QString PigsBoxType::getBoxTypeAsString() {
   switch(boxType) {
   case PigsBoxType::UnknownTypeBox:
       return "Unknown Type Box";
   case PigsBoxType::LittleBox:
       return "Little Box";
   case PigsBoxType::NormalBox:
       return "Normal Box";
   }
}
/**************************************************************/

/*********************** PigsBox class ************************/
QSize PigsBox::boxSize() {
    return QSize();
}

PigsBoxType PigsBox::boxType() {
    PigsBoxType type;
    type.setBoxType(PigsBoxType::UnknownTypeBox);

    return type;
}

void PigsBox::setRect(QRect rect) {
    boxRect = rect;
}

QRect PigsBox::getRect() {
    return boxRect;
}

void PigsBox::setBoxName(QString name){
    boxName = name;
}

QString PigsBox::getBoxName(){
    return boxName;
}

void PigsBox::setBoxHallName(QString hallName) {
    boxHallName = hallName;
}

QString PigsBox::getBoxHallName() {
    return boxHallName;
}

void PigsBox::setPigsNumber(int number) {
    pigsNumber = number;
}

int PigsBox::getPigsNumber() {
    return pigsNumber;
}

void PigsBox::setPopulationDate(QString pDate) {
    populationDate = pDate;
}

QString PigsBox::getPopulationDate() {
    return populationDate;
}

void PigsBox::setReleaseDate(QString rDate) {
    releaseDate = rDate;
}

QString PigsBox::getReleaseDate() {
    return releaseDate;
}

QJsonObject PigsBox::getJson() {
    QJsonObject box;
    QJsonObject values;

    values.insert("boxHallName", boxHallName);
    values.insert("boxType", boxType().getBoxType());
    values.insert("pigsNumber", pigsNumber);
    values.insert("populationDate", populationDate);
    values.insert("releaseDate", releaseDate);

    box.insert(boxName, values);

    return box;
}
void PigsBox::showDetailsWindow() {
    PigsBoxInfoDialog *d = new PigsBoxInfoDialog;
    d->setPigsBox(this);
    d->show();
}
/**************************************************************/

/******************** LittlePigsBox class *********************/
LittlePigsBox::LittlePigsBox() {

}

QSize LittlePigsBox::boxSize() {
    return QSize(5, 8); //metrii
}

PigsBoxType LittlePigsBox::boxType() {
    PigsBoxType type;
    type.setBoxType(PigsBoxType::LittleBox);

    return type;
}
/**************************************************************/

/******************* NormalPigsBox class **********************/
NormalPigsBox::NormalPigsBox() {

}

QSize NormalPigsBox::boxSize() {
    return QSize(20, 8); //metrii
}

PigsBoxType NormalPigsBox::boxType() {
    PigsBoxType type;
    type.setBoxType(PigsBoxType::NormalBox);

    return type;
}

/**************************************************************/
