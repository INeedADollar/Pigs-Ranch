#ifndef PIGSBOX_H
#define PIGSBOX_H

#include <QString>
#include <QSize>
#include <QRect>
#include <QJsonObject>

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
    virtual QSize boxSize();
    virtual PigsBoxType boxType();
    void showDetailsWindow();

    void setRect(QRect);
    QRect getRect();

    void setBoxName(QString);
    QString getBoxName();

    void setBoxHallName(QString);
    QString getBoxHallName();

    void setPigsNumber(int);
    int getPigsNumber();

    void setPopulationDate(QString);
    QString getPopulationDate();

    void setReleaseDate(QString);
    QString getReleaseDate();

    QJsonObject getJson();

private:
    QRect boxRect;
    QString boxName;
    QString boxHallName;
    int pigsNumber;
    QString populationDate;
    QString releaseDate;
};
/**************************************************************/


/******************** LittlePigsBox class *********************/
class LittlePigsBox : public PigsBox {

public:
    LittlePigsBox();

    virtual QSize boxSize() override;
    PigsBoxType boxType() override;
};
/**************************************************************/


/******************* NormalPigsBox class **********************/
class NormalPigsBox : public PigsBox {

public:
    NormalPigsBox();

    virtual QSize boxSize() override;
    PigsBoxType boxType() override;
};
/**************************************************************/

#endif // PIGSBOX_H
