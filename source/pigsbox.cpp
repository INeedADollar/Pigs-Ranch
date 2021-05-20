#include "headers/pigsbox.h"

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
int PigsBox::boxWidth() {
    return 0;
}

int PigsBox::boxLength() {
    return 0;
}

PigsBoxType PigsBox::boxType() {
    PigsBoxType type;
    type.setBoxType(PigsBoxType::UnknownTypeBox);

    return type;
}

void PigsBox::showDetailsWindow() {

}
/**************************************************************/

/******************** LittlePigsBox class *********************/
LittlePigsBox::LittlePigsBox() {

}

int LittlePigsBox::boxWidth() {
    return 5;
}

int LittlePigsBox::boxLength() {
    return 10;
}

PigsBoxType LittlePigsBox::boxType() {
    PigsBoxType type;
    type.setBoxType(PigsBoxType::LittleBox);

    return type;
}

void LittlePigsBox::showDetailsWindow() {

}
/**************************************************************/

/******************* NormalPigsBox class **********************/
NormalPigsBox::NormalPigsBox() {

}

int NormalPigsBox::boxWidth() {
    return 20;
}

int NormalPigsBox::boxLength() {
    return 10;
}

PigsBoxType NormalPigsBox::boxType() {
    PigsBoxType type;
    type.setBoxType(PigsBoxType::NormalBox);

    return type;
}

void NormalPigsBox::showDetailsWindow() {

}
/**************************************************************/
