#include "headers/pigsboxinfodialog.h"
#include "ui_pigsboxinfodialog.h"

#include <QDialogButtonBox>
#include <QPushButton>

/******************* PigsBoxInfoDialog class **********************/
PigsBoxInfoDialog::PigsBoxInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PigsBoxInfoDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    setWindowTitle("Box info");

    QPushButton* okBut = ui->buttonBox->button(QDialogButtonBox::Ok);
    okBut->setStyleSheet("QPushButton {"
       "border: 2px solid #ADBAC7; border-radius: 20px; background: #22272E;"
       "color: #ADBAC7; font-size: 20px; padding: 10px; padding-left: 20px;"
       "padding-right: 20px;} QPushButton:hover {border-color: #8598ab; color: #8598ab;}");

    QObject::connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::close);
}

PigsBoxInfoDialog::~PigsBoxInfoDialog()
{
    delete ui;
}

void PigsBoxInfoDialog::setBoxName(QString name){
    boxName = name;
    ui->label->setText(boxName);
}
QString PigsBoxInfoDialog::getBoxName(){
    return boxName;
}

void PigsBoxInfoDialog::setBoxHallName(QString hallName) {
    boxHallName = hallName;
    ui->label_2->setText("Box hall:               " + boxHallName);
}

QString PigsBoxInfoDialog::getBoxHallName() {
    return boxHallName;
}

void PigsBoxInfoDialog::setBoxType(PigsBoxType type) {
    boxType = type;
    ui->label_7->setText("Box type:              " + boxType.getBoxTypeAsString());
}

PigsBoxType PigsBoxInfoDialog::getBoxType(){
    return boxType;
}

void PigsBoxInfoDialog::setPigsNumber(int number) {
    pigsNumber = number;
    ui->label_5->setText("Pigs number:        " + QString::number(number));
}

int PigsBoxInfoDialog::getPigsNumber() {
    return pigsNumber;
}

void PigsBoxInfoDialog::setPopulationDate(QString pDate) {
    populationDate = pDate;
    ui->label_3->setText("Population date:   " + populationDate);
}

QString PigsBoxInfoDialog::getPopulationDate() {
    return populationDate;
}

void PigsBoxInfoDialog::setReleaseDate(QString rDate) {
    releaseDate = rDate;
    ui->label_4->setText("Release date:       " + releaseDate);
}

QString PigsBoxInfoDialog::getReleaseDate() {
    return releaseDate;
}

void PigsBoxInfoDialog::setBoxDimensions(QSize dimensions) {
    boxDimensions = dimensions;
    ui->label_6->setText("Dimensions:         " + QString("%1x%2").arg(boxDimensions.width()).arg(boxDimensions.height()));
}

QSize PigsBoxInfoDialog::getBoxDimensions() {
    return boxDimensions;
}
/***********************************************************************/
