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
    Q_OBJECT

public:
    HallsListWidget(QWidget *parent = nullptr);
    ~HallsListWidget();

protected:
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;

signals:
    void itemMousePressed(QListWidgetItem*);
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

public slots:
    void addHall(PigsHall*);

private:
    void addHallsToList();

    Ui::HallsWindow *ui;

private slots:
    void handleItemClick(QListWidgetItem*);
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};
/******************************************************************/

#endif // HALLSWINDOW_H
