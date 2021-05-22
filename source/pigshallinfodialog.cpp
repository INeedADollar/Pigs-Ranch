#include "headers/pigshallinfodialog.h"
#include "ui_pigshallinfodialog.h"

#include <QPushButton>

/******************* PigsHallInfoDialog class **********************/
PigsHallInfoDialog::PigsHallInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PigsHallInfoDialog)
{
    ui->setupUi(this);

    QPushButton* okBut = ui->buttonBox->button(QDialogButtonBox::Ok);
    okBut->setStyleSheet("QPushButton {"
       "border: 2px solid #ADBAC7; border-radius: 20px; background: #22272E;"
       "color: #ADBAC7; font-size: 20px; padding: 10px; padding-left: 20px;"
       "padding-right: 20px;} QPushButton:hover {border-color: #8598ab; color: #8598ab;}");
}

PigsHallInfoDialog::~PigsHallInfoDialog()
{
    delete ui;
}

void PigsHallInfoDialog::setHallName(QString name){
    hallName = name;
    ui->label->setText(hallName);
}

QString PigsHallInfoDialog::getHallName(){
    return hallName;
}

void PigsHallInfoDialog::setLittleBoxesNumber(int number){
    littleBoxesNumber = number;
    ui->label_2->setText(QString("Little Boxes:        %1").arg(littleBoxesNumber));
}

int PigsHallInfoDialog::getLittleBoxesNumber(){
    return littleBoxesNumber;
}

void PigsHallInfoDialog::setNormalBoxesNumber(int number){
    normalBoxesNumber = number;
    ui->label_3->setText(QString("Normal Boxes:     %1").arg(normalBoxesNumber));
}

int PigsHallInfoDialog::getNormalBoxesNumber(){
    return normalBoxesNumber;
}

void PigsHallInfoDialog::setLittlePigsNumber(int number){
    littlePigsNumber = number;
    ui->label_4->setText(QString("Little pigs:           %1").arg(littlePigsNumber));
}

int PigsHallInfoDialog::getLittlePigsNumber(){
    return littlePigsNumber;
}

void PigsHallInfoDialog::setNormalPigsNumber(int number){
    normalPigsNumber = number;
    ui->label_5->setText(QString("Normal pigs:        %1").arg(normalPigsNumber));
}

int PigsHallInfoDialog::getNormalPigsNumber(){
    return normalPigsNumber;
}
/***********************************************************************/
