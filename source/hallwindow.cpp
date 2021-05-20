#include "headers/hallwindow.h"
#include "ui_hallwindow.h"

#include <QPainter>

/******************* HallWindow class ******************************/
HallWindow::HallWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HallWindow)
{
    ui->setupUi(this);
}

HallWindow::~HallWindow()
{
    delete ui;
}
/*******************************************************************/

/***************** HallBluePrintWidget class **********************/
HallBluePrintWidget::HallBluePrintWidget(QWidget* parent) :
    QWidget(parent)
{

}

HallBluePrintWidget::~HallBluePrintWidget() {

}

void HallBluePrintWidget::paintEvent(QPaintEvent*) {
    QPainter p(this);

    for(int i = 0; i < 10; i++) {
        p.setPen(QPen(QColor(255, 255, 255), 3));
        p.drawRect(QRect(i * 100 + i * 10, 2, 100, 50));

        //p.setPen(QPen(QColor(255, 67, 89), 8));
        //p.drawLine(QPoint(i * 50 + 1, 0), QPoint(i * 50 + 1, 50));

        p.setBrush(Qt::red);
        p.drawRect(0, 54, width(), height() - 100);
        p.setBrush(Qt::transparent);
        //p.drawRect(QRect(i * 200 + i * 10, height() - 100, 200, 100));
    }

    /*p.setPen(QPen(QColor(qrand() % 255, qrand() % 255, qrand() % 255), 3));
    p.drawRect(QRect(100, 2, 50, 100));
    p.drawRect(QRect(154, 2, 200, 100));*/
}
/**********************************************************************/

HallPigsBoxLegend::HallPigsBoxLegend(QWidget* parent) :
    QWidget(parent)
{

}

HallPigsBoxLegend::~HallPigsBoxLegend() {

}

void HallPigsBoxLegend::paintEvent(QPaintEvent*) {
    int mainViewHeight = height() - 100;
    QPoint elementsPosition = QPoint(20, (mainViewHeight - 200) / 2 + 100);
    QSize squareSize = QSize(30, 30);

    QPainter painter(this);

    QFont legendFont = font();
    legendFont.setPixelSize(30);
    painter.setFont(legendFont);

    painter.setPen(QPen(QColor("#ADBAC7"), 2));
    painter.drawText(QRect(0, 0, width(), 100), Qt::AlignCenter, "Legend");

    legendFont.setPixelSize(20);
    painter.setFont(legendFont);

    painter.setPen(QPen(Qt::red, 2));
    QRect redSquare = QRect(elementsPosition, squareSize);
    painter.drawRect(redSquare);

    painter.setPen(QPen(QColor("#ADBAC7"), 2));
    painter.drawText(QPoint(60, elementsPosition.y() + 20), "- Little Box");

    elementsPosition = QPoint(20, elementsPosition.y() + 60);
    painter.setPen(QPen(Qt::blue, 2));
    QRect blueSquare = QRect(elementsPosition, squareSize);
    painter.drawRect(blueSquare);

    painter.setPen(QPen(QColor("#ADBAC7"), 2));
    painter.drawText(QPoint(60, elementsPosition.y() + 20), "- Normal Box");

    elementsPosition = QPoint(20, elementsPosition.y() + 60);
    painter.setPen(QPen(Qt::gray, 2));
    QRect graySquare = QRect(elementsPosition, squareSize);
    painter.drawRect(graySquare);

    painter.setPen(QPen(QColor("#ADBAC7"), 2));
    painter.drawText(QPoint(60, elementsPosition.y() + 20), "- Unknown type");
}
