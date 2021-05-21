#ifndef PIGSBOXINFODIALOG_H
#define PIGSBOXINFODIALOG_H

#include "headers/pigsbox.h"
#include <QDialog>

/******************* PigsBoxInfoDialog class **********************/
namespace Ui {
class PigsBoxInfoDialog;
}

class PigsBoxInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PigsBoxInfoDialog(QWidget *parent = nullptr);
    ~PigsBoxInfoDialog();

    void setBoxName(QString);
    QString getBoxName();

    void setBoxHallName(QString);
    QString getBoxHallName();

    void setBoxType(PigsBoxType);
    PigsBoxType getBoxType();

    void setPigsNumber(int);
    int getPigsNumber();

    void setPopulationDate(QString);
    QString getPopulationDate();

    void setReleaseDate(QString);
    QString getReleaseDate();

    void setBoxDimensions(QSize);
    QSize getBoxDimensions();

private:
    Ui::PigsBoxInfoDialog *ui;

    QString boxName;
    QString boxHallName;
    PigsBoxType boxType;
    int pigsNumber;
    QString populationDate;
    QString releaseDate;
    QSize boxDimensions;
};
/***********************************************************************/

#endif // PIGSBOXINFODIALOG_H
