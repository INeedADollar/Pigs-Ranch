#include "headers/hallswindow.h"
#include "headers/ranch.h"
#include "ui_hallswindow.h"

#include <QMouseEvent>
#include <QScrollBar>
#include <QCommonStyle>
#include <QFileDialog>
#include <QMessageBox>
#include <QJsonDocument>

/************************** PigsHallItem class **************************/
PigsHallItem::PigsHallItem(QString title) : QListWidgetItem(title) {

}

void PigsHallItem::setHall(PigsHall *hall){
    pigsHall = hall;
}

PigsHall* PigsHallItem::getHall() {
    return pigsHall;
}
/************************************************************************/

/************************** HallsListWidget class ***********************/
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
/************************************************************************/

/************************** HallsWindow class ***************************/
HallsWindow::HallsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HallsWindow)
{
    ui->setupUi(this);
    ui->listWidget->setSpacing(7);
    QObject::connect(ui->listWidget, &QListWidget::itemClicked, this, &HallsWindow::handleItemClick);
    addHallsToList();
}

HallsWindow::~HallsWindow()
{
    delete ui;
}

void HallsWindow::addListItem(QListWidgetItem* item){
    ui->listWidget->addItem(item);
}

void HallsWindow::addHallsToList(){
    QVector<PigsHall*> halls = ranch->pigsHalls();

    QIcon ico(":/assets/bullet.png");
    QFont font;

    for(PigsHall *hall : halls){
        PigsHallItem *item = new PigsHallItem(hall->getHallName());
        item->setHall(hall);

        font = item->font();
        font.setPixelSize(25);

        item->setSizeHint(QSize(item->sizeHint().width() - 100, 100));
        item->setFont(font);
        item->setTextAlignment(Qt::AlignCenter);
        item->setIcon(ico);
        item->setBackground(QColor("#1F3143"));

        ui->listWidget->addItem(item);
    }
}

void HallsWindow::handleItemClick(QListWidgetItem *item){
    PigsHallItem *cItem = reinterpret_cast<PigsHallItem*>(item);
    cItem->getHall()->showHallWindow();
}

void HallsWindow::on_pushButton_3_clicked() {
    QString filePath = QFileDialog::getSaveFileName(this, "Save ranch", "", "*.json (Json Document)");
    if(filePath != ""){
        QFile file(filePath);
        if(file.open(QIODevice::WriteOnly)) {
            QJsonDocument document;
            document.setObject(ranch->getJson());
            file.write(document.toJson());
            file.close();

            QMessageBox::information(this, "Success", "File was saved succesfully!");
        }
        else {
            QMessageBox::information(this, "Error", "File could not be saved! Please try again with other file.");
        }
    }
}

void HallsWindow::on_pushButton_2_clicked(){
    QString filePath = QFileDialog::getOpenFileName(this, "Save ranch", "", "*.json (Json Document)");
    if(filePath != ""){

    }
}
/************************** HallsWindow class ***************************/
