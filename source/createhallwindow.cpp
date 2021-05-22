#include "headers/createhallwindow.h"
#include "headers/infodialog.h"
#include "headers/questiondialog.h"
#include "headers/ranch.h"
#include "ui_createhallwindow.h"

#include <QDate>

/********************** CreateHallDialog class *********************/
CreateHallDialog::CreateHallDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateHallDialog)
{
    ui->setupUi(this);
    ui->radioButton_2->setAutoExclusive(false);

    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &CreateHallDialog::checkData);
    QObject::connect(ui->radioButton, &QRadioButton::clicked, this, &CreateHallDialog::disableSizeBoxes);
    QObject::connect(ui->lineEdit, &QLineEdit::textChanged, this, &CreateHallDialog::handleTextChange);
    QObject::connect(ui->lineEdit_3, &QLineEdit::textChanged, this, &CreateHallDialog::handleTextChange);
    QObject::connect(ui->lineEdit_4, &QLineEdit::textChanged, this, &CreateHallDialog::handleTextChange);
    QObject::connect(ui->lineEdit_5, &QLineEdit::textChanged, this, &CreateHallDialog::handleTextChange);
}

CreateHallDialog::~CreateHallDialog()
{
    delete ui;
}

PigsBoxData data;
void CreateHallDialog::checkData(){
    if(ui->radioButton->isChecked() && (ui->lineEdit->text() == "" || ui->lineEdit_3->text() == "")){
        InfoDialog *d = new InfoDialog;
        d->setWindowTitle("Invalid input");
        d->setDisplayText("Please input size of hall!");
        d->show();
        return;
    }

    bool isWidthNumberValid;
    bool isLenghtNumberValid;
    int hallWidth = ui->lineEdit->text().toInt(&isWidthNumberValid);
    int hallLength = ui->lineEdit_3->text().toInt(&isLenghtNumberValid);

    if(ui->radioButton->isChecked() && (!isWidthNumberValid || !isLenghtNumberValid)){
        InfoDialog *d = new InfoDialog;
        d->setWindowTitle("Invalid input");
        d->setDisplayText("Please input valid hall size!");
        d->show();
        return;
    }

    if(hallWidth < 20) {
        InfoDialog *d = new InfoDialog;
        d->setWindowTitle("Invalid input");
        d->setDisplayText("Hall's width needs to be at least 20 meters!");
        d->show();
        return;
    }

    if(hallLength < 100){
        InfoDialog *d = new InfoDialog;
        d->setWindowTitle("Invalid input");
        d->setDisplayText("Hall's length needs to be at least 100 meters!");
        d->show();
        return;
    }

    bool isLittlePigsNumberValid;
    int littlePigsNumber = ui->lineEdit_4->text().toInt(&isLittlePigsNumberValid);
    if(!isLittlePigsNumberValid){
        InfoDialog *d = new InfoDialog;
        d->setWindowTitle("Invalid input");
        d->setDisplayText("Please input valid little pigs number!");
        d->show();
        return;
    }

    bool isNormalPigsNumberValid;
    int normalPigsNumber = ui->lineEdit_5->text().toInt(&isNormalPigsNumberValid);
    if(!isNormalPigsNumberValid){
        InfoDialog *d = new InfoDialog;
        d->setWindowTitle("Invalid input");
        d->setDisplayText("Please input valid normal pigs number!");
        d->show();
        return;
    }

    ::data = PigsHall::calculateBoxesNumberFromInput(QSize(hallLength, hallWidth),
                            littlePigsNumber, normalPigsNumber, ui->radioButton_2->isChecked());

    if(::data.getOverflowLittlePigsBoxesNumber() > 0 || ::data.getOveflowNormalPigsNumber() > 0){
        QuestionDialog *d = new QuestionDialog;
        d->setWindowTitle("Not enough space");
        d->setDisplayText(QString("Hall does not have enough space for all pigs [%1 little pigs remained "
                          "(%2 little pigs boxes overflow), %3 normal pigs remained (%4 normal pigs boxes overflow)]. "
                          "Do you want to create hall anyway?").arg(::data.getOverflowLittlePigsNumber())
                          .arg(::data.getOverflowLittlePigsBoxesNumber()).arg(::data.getOveflowNormalPigsNumber())
                          .arg(::data.getOverflowNormalPigsBoxesNumber()));
        d->setMinimumWidth(700);
        d->show();

        QObject::connect(d, &QuestionDialog::buttonPressed, this, &CreateHallDialog::handleQuestionDialogButtonPress);
        return;
    }

    createHall(QSize(hallLength, hallWidth));
    close();
}

void CreateHallDialog::createHall(QSize hallSize){
    QVector<PigsHall*> halls = ranch->pigsHalls();
    PigsHall *hall = new PigsHall;
    hall->setSize(hallSize);

    LittlePigsBox *lBox;
    NormalPigsBox *nBox;
    int pigsNumber;

    if(halls.size() > 0)
        hall->setHallName("Hall #" + QString::number(halls.last()->getHallName().split("#")[1].toInt() + 1));
    else
        hall->setHallName("Hall #1");

    if(ui->radioButton_2->isChecked()) {
        for(int i = 0; i < ::data.getLittlePigsBoxesNumber() - 1; i++){
            lBox = new LittlePigsBox;
            lBox->setBoxName(QString("Box #%1").arg(i + 1));
            lBox->setBoxHallName(hall->getHallName());
            lBox->setPigsNumber(25);
            lBox->setPopulationDate(QDate::currentDate().toString("dd/MM/yyyy"));
            lBox->setReleaseDate("-");

            hall->addBox(lBox);
        }

        lBox = new LittlePigsBox;
        lBox->setBoxName(QString("Box #%1").arg(::data.getLittlePigsBoxesNumber()));
        lBox->setBoxHallName(hall->getHallName());

        pigsNumber = ::data.getLittlePigsNumber() % 25 ? ::data.getLittlePigsNumber() % 25 : 25;
        lBox->setPigsNumber(pigsNumber);
        lBox->setPopulationDate(QDate::currentDate().toString("dd/MM/yyyy"));
        lBox->setReleaseDate("-");

        hall->addBox(lBox);

        for(int i = 0; i < ::data.getNormalPigsBoxesNumber() - 1; i++){
            nBox = new NormalPigsBox;
            nBox->setBoxName(QString("Box #%1").arg(i + ::data.getLittlePigsBoxesNumber() + 1));
            nBox->setBoxHallName(hall->getHallName());
            nBox->setPigsNumber(25);
            nBox->setPopulationDate(QDate::currentDate().toString("dd/MM/yyyy"));
            nBox->setReleaseDate("-");

            hall->addBox(nBox);
        }

        nBox = new NormalPigsBox;
        nBox->setBoxName(QString("Box #%1").arg(::data.getLittlePigsBoxesNumber() + ::data.getNormalPigsBoxesNumber()));
        nBox->setBoxHallName(hall->getHallName());

        pigsNumber = ::data.getNormalPigsNumber() % 25 ? ::data.getNormalPigsNumber() % 25 : 25;
        nBox->setPigsNumber(pigsNumber);
        nBox->setPopulationDate(QDate::currentDate().toString("dd/MM/yyyy"));
        nBox->setReleaseDate("-");

        hall->addBox(nBox);
    }
    else {
        for(int i = 0; i < ::data.getNormalPigsBoxesNumber() - 1; i++){
            nBox = new NormalPigsBox;
            nBox->setBoxName(QString("Box #%1").arg(i + 1));
            nBox->setBoxHallName(hall->getHallName());
            nBox->setPigsNumber(25);
            nBox->setPopulationDate(QDate::currentDate().toString("dd/MM/yyyy"));
            nBox->setReleaseDate("-");

            hall->addBox(nBox);
        }

        if(::data.getNormalPigsBoxesNumber() > 0) {
            nBox = new NormalPigsBox;
            nBox->setBoxName(QString("Box #%1").arg(::data.getNormalPigsBoxesNumber()));
            nBox->setBoxHallName(hall->getHallName());

            pigsNumber = ::data.getNormalPigsNumber() % 25 ? ::data.getNormalPigsNumber() % 25 : 25;
            nBox->setPigsNumber(pigsNumber);
            nBox->setPopulationDate(QDate::currentDate().toString("dd/MM/yyyy"));
            nBox->setReleaseDate("-");

            hall->addBox(nBox);
        }

        for(int i = 0; i < ::data.getLittlePigsBoxesNumber() - 1; i++){
            lBox = new LittlePigsBox;
            lBox->setBoxName(QString("Box #%1").arg(::data.getNormalPigsBoxesNumber() + i + 1));
            lBox->setBoxHallName(hall->getHallName());
            lBox->setPigsNumber(25);
            lBox->setPopulationDate(QDate::currentDate().toString("dd/MM/yyyy"));
            lBox->setReleaseDate("-");

            hall->addBox(lBox);
        }

        if(::data.getLittlePigsBoxesNumber() > 0) {
            lBox = new LittlePigsBox;
            lBox->setBoxName(QString("Box #%1").arg(::data.getLittlePigsBoxesNumber() + ::data.getNormalPigsBoxesNumber()));
            lBox->setBoxHallName(hall->getHallName());

            pigsNumber = ::data.getLittlePigsNumber() % 25 ? ::data.getLittlePigsNumber() % 25 : 25;
            lBox->setPigsNumber(pigsNumber);
            lBox->setPopulationDate(QDate::currentDate().toString("dd/MM/yyyy"));
            lBox->setReleaseDate("-");

            hall->addBox(lBox);
        }
    }

    ranch->addHall(hall);
    emit dataSubmitted(hall);
}

void CreateHallDialog::disableSizeBoxes(){
    if(ui->radioButton->isChecked()) {
        ui->lineEdit->setReadOnly(false);
        ui->lineEdit->setText("");
        ui->lineEdit_3->setReadOnly(false);
        ui->lineEdit_3->setText("");
        ui->radioButton->setAutoExclusive(false);
    }
    else {
        ui->lineEdit->setReadOnly(true);
        ui->lineEdit->setText("20");
        ui->lineEdit_3->setReadOnly(true);
        ui->lineEdit_3->setText("100");
    }
}

void CreateHallDialog::handleQuestionDialogButtonPress(QDialogButtonBox::StandardButton but){
    if(but == QDialogButtonBox::Ok) {
        QSize hallSize = QSize(ui->lineEdit_3->text().toInt(), ui->lineEdit->text().toInt());
        createHall(hallSize);
        close();
    }
}

void CreateHallDialog::handleTextChange(const QString &){
    if(ui->radioButton->isChecked() && (ui->lineEdit->text() == "" || ui->lineEdit_3->text() == ""))
        return;

    bool isWidthNumberValid;
    bool isLenghtNumberValid;
    int hallWidth = ui->lineEdit->text().toInt(&isWidthNumberValid);
    int hallLength = ui->lineEdit_3->text().toInt(&isLenghtNumberValid);

    if(ui->radioButton->isChecked() && (!isWidthNumberValid || !isLenghtNumberValid))
        return;

    if(hallWidth < 20)
        return;

    if(hallLength < 100)
        return;

    bool isLittlePigsNumberValid;
    int littlePigsNumber = ui->lineEdit_4->text().toInt(&isLittlePigsNumberValid);
    if(!isLittlePigsNumberValid)
        return;

    bool isNormalPigsNumberValid;
    int normalPigsNumber = ui->lineEdit_5->text().toInt(&isNormalPigsNumberValid);
    if(!isNormalPigsNumberValid)
        return;

    int totalPrice = 70 * (hallWidth * hallLength) + littlePigsNumber * 40 + normalPigsNumber * 400;
    ui->lineEdit_total_price->setText(QString::number(totalPrice) + "€");
}
/******************************************************************/
