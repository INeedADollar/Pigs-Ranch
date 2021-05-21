#include "headers/questiondialog.h"
#include "ui_questiondialog.h"

#include <QPushButton>
#include <QStyle>

/********************** QuestionDialog class *********************/
QuestionDialog::QuestionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuestionDialog)
{
    ui->setupUi(this);

    QPushButton* okBut = ui->buttonBox->button(QDialogButtonBox::Ok);
    okBut->setStyleSheet("QPushButton {"
       "border: 2px solid #ADBAC7; border-radius: 20px; background: #22272E;"
       "color: #ADBAC7; font-size: 20px; padding: 10px; padding-left: 20px;"
       "padding-right: 20px;} QPushButton:hover {border-color: #8598ab; color: #8598ab;}");

    QPushButton* cancelBut = ui->buttonBox->button(QDialogButtonBox::Cancel);
    cancelBut->setStyleSheet("QPushButton {"
       "border: 2px solid #ADBAC7; border-radius: 20px; background: #22272E;"
       "color: #ADBAC7; font-size: 20px; padding: 10px; padding-left: 20px;"
       "padding-right: 20px;} QPushButton:hover {border-color: #8598ab; color: #8598ab;}");

    QIcon question = style()->standardIcon(QStyle::SP_MessageBoxQuestion);
    ui->label_2->setPixmap(question.pixmap(QSize(64, 64)));
    setFixedSize(500, 200);

    QObject::connect(ui->buttonBox, &QDialogButtonBox::clicked, this, &QuestionDialog::handleButtonClick);
}

QuestionDialog::~QuestionDialog()
{
    delete ui;
}

void QuestionDialog::setDisplayText(QString text){
    displayText = text;
    ui->label->setText(displayText);
}

QString QuestionDialog::getDisplayText(){
    return displayText;
}

void QuestionDialog::handleButtonClick(QAbstractButton *but){
    if(but == ui->buttonBox->button(QDialogButtonBox::Ok))
        emit buttonPressed(QDialogButtonBox::Ok);
    else
        emit buttonPressed(QDialogButtonBox::Cancel);
}
/******************************************************************/
