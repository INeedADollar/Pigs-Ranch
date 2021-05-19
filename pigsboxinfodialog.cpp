#include "pigsboxinfodialog.h"
#include "ui_pigsboxinfodialog.h"

PigsBoxInfoDialog::PigsBoxInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PigsBoxInfoDialog)
{
    ui->setupUi(this);
}

PigsBoxInfoDialog::~PigsBoxInfoDialog()
{
    delete ui;
}
