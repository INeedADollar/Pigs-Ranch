#ifndef RANCHWINDOW_H
#define RANCHWINDOW_H

#include "headers/pigshall.h"

#include <QWidget>
#include <QScrollArea>

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

/******************* HallBluePrintScrollArea class ********************/
class HallBluePrintScrollArea : public QScrollArea {

public:
    HallBluePrintScrollArea(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent*) override;
};
/*********************************************************************/

/***************** HallBluePrintWidget class *************************/
class HallBluePrintWidget : public QWidget {
    Q_OBJECT

public:
    explicit HallBluePrintWidget(QWidget* parent = nullptr);
    ~HallBluePrintWidget();

    void setPigsHall(PigsHall*);
    PigsHall* getPigsHall();
    PigsBox* boxAt(QPoint);

protected:
    void mouseMoveEvent(QMouseEvent*);
    void paintEvent(QPaintEvent*);
    void resizeEvent(QResizeEvent*);

private:
    void resizeBoxes();

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
