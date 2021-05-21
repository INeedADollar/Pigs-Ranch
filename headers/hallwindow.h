#ifndef RANCHWINDOW_H
#define RANCHWINDOW_H

#include "headers/pigshall.h"
#include <QWidget>

/******************* HallWindow class ******************************/
namespace Ui {
class HallWindow;
}

class HallWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HallWindow(QWidget *parent = nullptr);
    ~HallWindow();

    void setPigsHall(PigsHall*);
    PigsHall* getPigsHall();

protected:
    void resizeEvent(QResizeEvent*);

private:
    Ui::HallWindow *ui;

    PigsHall* pigsHall;
};
/**********************************************************************/

/***************** HallBluePrintWidget class *************************/
class HallBluePrintWidget : public QWidget {
    Q_OBJECT

public:
    explicit HallBluePrintWidget(QWidget* parent = nullptr);
    ~HallBluePrintWidget();

    void setPigsHall(PigsHall*);
    PigsHall* getPigsHall();

protected:
    void mouseClickEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void paintEvent(QPaintEvent*);
    void resizeEvent(QResizeEvent*);

private:
    void resizeBoxes();
    PigsBox* boxAt(QPoint);

    PigsHall* pigsHall;
};
/**********************************************************************/

/******************** HallPigsBoxLegend class *************************/
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
