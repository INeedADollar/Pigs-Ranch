#ifndef CREATEHALLDIALOG_H
#define CREATEHALLDIALOG_H

#include "headers/pigshall.h"

#include <QMainWindow>
#include <QDialogButtonBox>

/********************** CreateHallDialog class *********************/
namespace Ui {
class CreateHallDialog;
}

class CreateHallDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateHallDialog(QWidget *parent = nullptr);
    ~CreateHallDialog();

private:
    void createHall(QSize);

    Ui::CreateHallDialog *ui;

private slots:
    void checkData();
    void disableSizeBoxes();
    void handleQuestionDialogButtonPress(QDialogButtonBox::StandardButton);

signals:
    void dataSubmitted(PigsHall*);
};

#endif // CREATEHALLDIALOG_H
