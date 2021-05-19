#ifndef PIGSBOX_H
#define PIGSBOX_H

enum PigsBoxType {
    UnknownTypeBox,
    LittleBox,
    NormalBox
};

class PigsBox
{
public:
    virtual int boxWidth();
    virtual int boxLength();
    virtual PigsBoxType boxType();
    virtual void showDetailsWindow();
};

class LittlePigsBox : public PigsBox {

public:
    LittlePigsBox();

    int boxWidth() override;
    int boxLength() override;
    PigsBoxType boxType() override;
    void showDetailsWindow() override;
};

class NormalPigsBox : public PigsBox {

public:
    NormalPigsBox();

    int boxWidth() override;
    int boxLength() override;
    PigsBoxType boxType() override;
    void showDetailsWindow() override;
};

#endif // PIGSBOX_H
