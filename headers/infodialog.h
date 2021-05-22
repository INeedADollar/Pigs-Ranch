#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>

/********************** InfoDialog class *********************/
namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();

    void setDisplayText(QString);
    QString getDisplayText();

private:
    Ui::InfoDialog *ui;

    QString displayText;
};
/******************************************************************/

#endif // INFODIALOG_H
