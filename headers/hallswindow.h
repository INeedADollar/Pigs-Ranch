#ifndef HALLSWINDOW_H
#define HALLSWINDOW_H

#include "headers/pigshall.h"

#include <QListWidgetItem>
#include <QWidget>

/********************** PigsHallItem class ************************/
class PigsHallItem : public QListWidgetItem {

public:
    PigsHallItem(QString);

    void setHall(PigsHall*);
    PigsHall* getHall();

private:
    PigsHall* pigsHall;
};
/******************************************************************/

/********************** HallsListWidget class *********************/
class HallsListWidget : public QListWidget {

public:
    HallsListWidget(QWidget *parent = nullptr);
    ~HallsListWidget();

protected:
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
};
/******************************************************************/

/********************** HallsWindow class *************************/
namespace Ui {
class HallsWindow;
}

class HallsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HallsWindow(QWidget *parent = nullptr);
    ~HallsWindow();

    void addListItem(QListWidgetItem*);

private:
    void addHallsToList();

    Ui::HallsWindow *ui;

private slots:
    void handleItemClick(QListWidgetItem*);
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
};
/******************************************************************/

#endif // HALLSWINDOW_H
