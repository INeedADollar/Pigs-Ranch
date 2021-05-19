#include "ranchwindow.h"
#include "ui_ranchwindow.h"

#include <QPainter>

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

void RanchWindow::paintEvent(QPaintEvent*) {
    QPainter p(this);

    for(int i = 0; i < 5; i++) {
        p.setPen(QPen(QColor(qrand() % 255, qrand() % 255, qrand() % 255), 3));
        p.drawRect(QRect(i * 100 + 2, 2, 100, 50));
    }
}
