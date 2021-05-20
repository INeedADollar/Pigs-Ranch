#ifndef RANCHWINDOW_H
#define RANCHWINDOW_H

#include "headers/pigshall.h"
#include <QWidget>

/******************* RanchWindow class ******************************/
namespace Ui {
class HallWindow;
}

class HallWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HallWindow(QWidget *parent = nullptr);
    ~HallWindow();

    void drawPigsHall(PigsHall*);

private:
    Ui::HallWindow *ui;
};
/**********************************************************************/

/***************** HallBluePrintWidget class *************************/
class HallBluePrintWidget : public QWidget {
    Q_OBJECT

public:
    explicit HallBluePrintWidget(QWidget* parent = nullptr);
    ~HallBluePrintWidget();

protected:
    void paintEvent(QPaintEvent*);
};
/**********************************************************************/

/***************** RanchBluePrintWidget class *************************/
class HallPigsBoxLegend : public QWidget {
    Q_OBJECT

public:
    explicit HallPigsBoxLegend(QWidget* parent = nullptr);
    ~HallPigsBoxLegend();

protected:
    void paintEvent(QPaintEvent*);
};
/**********************************************************************/
#endif // RANCHWINDOW_H
