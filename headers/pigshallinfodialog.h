#ifndef PIGSHALLINFODIALOG_H
#define PIGSHALLINFODIALOG_H

#include <QDialog>

/******************* PigsHallInfoDialog class **********************/
namespace Ui {
class PigsHallInfoDialog;
}

class PigsHallInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PigsHallInfoDialog(QWidget *parent = nullptr);
    ~PigsHallInfoDialog();

    void setHallName(QString);
    QString getHallName();

    void setLittleBoxesNumber(int);
    int getLittleBoxesNumber();

    void setNormalBoxesNumber(int);
    int getNormalBoxesNumber();

    void setLittlePigsNumber(int);
    int getLittlePigsNumber();

    void setNormalPigsNumber(int);
    int getNormalPigsNumber();

private:
    Ui::PigsHallInfoDialog *ui;

    QString hallName;
    int littleBoxesNumber;
    int normalBoxesNumber;
    int littlePigsNumber;
    int normalPigsNumber;
};
/***********************************************************************/

#endif // PIGSHALLINFODIALOG_H
