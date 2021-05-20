#include "headers/hallswindow.h"
#include "ui_hallswindow.h"

#include <QMouseEvent>
#include <QScrollBar>
#include <QCommonStyle>

HallsListWidget::HallsListWidget(QWidget *parent) : QListWidget(parent) {
    setMouseTracking(true);

    verticalScrollBar()->setStyle(new QCommonStyle);
    verticalScrollBar()->setStyleSheet("QScrollBar:vertical { border: none; background: transparent;"
        "width: 10px; margin: 0px 0px 0px 0px;} QScrollBar::handle:vertical { background: #ADBAC7; min-height: 0px; border-radius: 5px;}"
        "QScrollBar::add-line:vertical {background: #22272E; height: 0px; subcontrol-position: bottom; subcontrol-origin: margin;} "
        "QScrollBar::sub-line:vertical { background: "
        "#22272E; height: 0 px;"
        "subcontrol-position: top; subcontrol-origin: margin;}");
}

HallsListWidget::~HallsListWidget() {

}

void HallsListWidget::mousePressEvent(QMouseEvent *event){
    QListWidgetItem *item = itemAt(event->pos());

    if(!item && selectedItems().length() > 0)
        clearSelection();
}

void HallsListWidget::mouseMoveEvent(QMouseEvent *event) {
    QListWidgetItem *item = itemAt(event->pos());

    if(item)
        setCursor(Qt::PointingHandCursor);
    else
        setCursor(Qt::ArrowCursor);
}

HallsWindow::HallsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HallsWindow)
{
    ui->setupUi(this);
    ui->listWidget->setSpacing(7);
}

HallsWindow::~HallsWindow()
{
    delete ui;
}

void HallsWindow::addListItem(QListWidgetItem* item){
    ui->listWidget->addItem(item);
}
