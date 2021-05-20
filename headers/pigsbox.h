#ifndef PIGSBOX_H
#define PIGSBOX_H

#include <QString>

/********************** PigsBoxType class ********************/
class PigsBoxType {

public:
    enum BoxType {
        UnknownTypeBox,
        LittleBox,
        NormalBox
    };

    void setBoxType(BoxType);
    BoxType getBoxType();

    QString getBoxTypeAsString();

private:
    BoxType boxType;
};
/**************************************************************/


/*********************** PigsBox class ************************/
class PigsBox
{
public:
    virtual int boxWidth();
    virtual int boxLength();
    virtual PigsBoxType boxType();
    virtual void showDetailsWindow();
};
/**************************************************************/


/******************** LittlePigsBox class *********************/
class LittlePigsBox : public PigsBox {

public:
    LittlePigsBox();

    int boxWidth() override;
    int boxLength() override;
    PigsBoxType boxType() override;
    void showDetailsWindow() override;
};
/**************************************************************/


/******************* NormalPigsBox class **********************/
class NormalPigsBox : public PigsBox {

public:
    NormalPigsBox();

    int boxWidth() override;
    int boxLength() override;
    PigsBoxType boxType() override;
    void showDetailsWindow() override;
};
/**************************************************************/

#endif // PIGSBOX_H
