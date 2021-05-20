#include "headers/ranchwindow.h"
#include "ui_ranchwindow.h"

RanchWindow::RanchWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RanchWindow)
{
    ui->setupUi(this);
}

RanchWindow::~RanchWindow()
{
    delete ui;
}

void RanchWindow::addListItem(QListWidgetItem *item){

}
