#ifndef QUESTIONDIALOG_H
#define QUESTIONDIALOG_H

#include <QDialog>
#include <QDialogButtonBox>

/********************** QuestionDialog class *********************/
namespace Ui {
class QuestionDialog;
}

class QuestionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QuestionDialog(QWidget *parent = nullptr);
    ~QuestionDialog();

    void setDisplayText(QString);
    QString getDisplayText();

private:
    Ui::QuestionDialog *ui;

    QString displayText;

signals:
    void buttonPressed(QDialogButtonBox::StandardButton);

private slots:
    void handleButtonClick(QAbstractButton*);
};
/******************************************************************/

#endif // QUESTIONDIALOG_H
