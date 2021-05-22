#include "headers/infodialog.h"
#include "ui_infodialog.h"

#include <QPushButton>
#include <QStyle>

/********************** InfoDialog class *********************/
InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);

    QPushButton* okBut = ui->buttonBox->button(QDialogButtonBox::Ok);
    okBut->setStyleSheet("QPushButton {"
       "border: 2px solid #ADBAC7; border-radius: 20px; background: #22272E;"
       "color: #ADBAC7; font-size: 20px; padding: 10px; padding-left: 20px;"
       "padding-right: 20px;} QPushButton:hover {border-color: #8598ab; color: #8598ab;}");

    QIcon info = style()->standardIcon(QStyle::SP_MessageBoxInformation);
    ui->label->setPixmap(info.pixmap(QSize(64, 64)));
    setFixedSize(500, 200);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::setDisplayText(QString text){
    displayText = text;
    ui->label_2->setText(displayText);
}

QString InfoDialog::getDisplayText(){
    return displayText;
}
/******************************************************************/
