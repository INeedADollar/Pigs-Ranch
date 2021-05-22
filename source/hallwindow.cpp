#include "headers/hallwindow.h"
#include "ui_hallwindow.h"

#include <QPainter>
#include <QScrollBar>
#include <QCommonStyle>
#include <QMouseEvent>
#include <QResizeEvent>

/******************* HallWindow class ******************************/
HallWindow::HallWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HallWindow)
{
    ui->setupUi(this);
    ui->scrollArea->setWidgetResizable(false);

    ui->scrollArea->horizontalScrollBar()->setStyle(new QCommonStyle);
    ui->scrollArea->horizontalScrollBar()->setStyleSheet("QScrollBar:horizontal { border: none; background: transparent;"
                                                         "height: 10px; margin: 0px 0px 0px 0px;} QScrollBar::handle:horizontal { background: #ADBAC7; min-height: 0px; border-radius: 5px;}"
                                                         "QScrollBar::add-line:horizontal {background: #22272E; width: 0px; subcontrol-position: right; subcontrol-origin: margin;} "
                                                         "QScrollBar::sub-line:horizontal { background: "
                                                         "#22272E; width: 0 px;"
                                                         "subcontrol-position: left; subcontrol-origin: margin;}");

    ui->scrollArea->verticalScrollBar()->setStyle(new QCommonStyle);
    ui->scrollArea->verticalScrollBar()->setStyleSheet("QScrollBar:vertical { border: none; background: transparent;"
                                                       "width: 10px; margin: 0px 0px 0px 0px;} QScrollBar::handle:vertical { background: #ADBAC7; min-height: 0px; border-radius: 5px;}"
                                                       "QScrollBar::add-line:vertical {background: #22272E; height: 0px; subcontrol-position: bottom; subcontrol-origin: margin;} "
                                                       "QScrollBar::sub-line:vertical { background: "
                                                       "#22272E; height: 0 px;"
                                                       "subcontrol-position: top; subcontrol-origin: margin;}");
}

HallWindow::~HallWindow()
{
    delete ui;
}

void HallWindow::setPigsHall(PigsHall *hall){
    pigsHall = hall;
    ui->scrollAreaWidgetContents->setPigsHall(hall);
}

PigsHall* HallWindow::getPigsHall() {
    return pigsHall;
}

void HallWindow::resizeEvent(QResizeEvent *){
    QSize scrollAreaSize = ui->scrollArea->size();
    QWidget *scrollContent = ui->scrollAreaWidgetContents;

    float ratio = pigsHall->getSize().width() / pigsHall->getSize().height();
    scrollContent->resize(ratio * scrollAreaSize.height(), scrollAreaSize.height());
}
/*******************************************************************/

/******************* HallBluePrintScrollArea class *****************/
HallBluePrintScrollArea::HallBluePrintScrollArea(QWidget *parent) :
    QScrollArea(parent) {

}
void HallBluePrintScrollArea::mousePressEvent(QMouseEvent *event){
    HallBluePrintWidget *wid = qobject_cast<HallBluePrintWidget*>(widget());
    if(wid) {
        PigsBox* box = wid->boxAt(event->pos() + QPoint(horizontalScrollBar()->value(), verticalScrollBar()->value()));
        if(box)
            box->showDetailsWindow();
    }
}
/*******************************************************************/

/***************** HallBluePrintWidget class **********************/
HallBluePrintWidget::HallBluePrintWidget(QWidget* parent) :
    QWidget(parent)
{
    setMouseTracking(true);
}

HallBluePrintWidget::~HallBluePrintWidget() {

}

void HallBluePrintWidget::setPigsHall(PigsHall *hall){
    pigsHall = hall;
    resizeBoxes();
    update();
}

PigsHall* HallBluePrintWidget::getPigsHall() {
    return pigsHall;
}

void HallBluePrintWidget::resizeBoxes(){
    QSize bluePrintSize = size();
    QVector<PigsBox*> boxes = pigsHall->pigsBoxes();
    QPoint currentPoint = QPoint(4, 4);

    for(PigsBox* box : boxes) {
        if(box->boxType().getBoxType() == PigsBoxType::LittleBox) {
            QSize littleBoxSize = QSize((bluePrintSize.height() * box->boxSize().width()) / pigsHall->getSize().height(), (bluePrintSize.height() * box->boxSize().height()) / pigsHall->getSize().height());
            box->setRect(QRect(currentPoint, littleBoxSize));

            currentPoint = QPoint(currentPoint.x() + littleBoxSize.width() + 10, currentPoint.y());
        }

        if(box->boxType().getBoxType() == PigsBoxType::NormalBox) {
            QSize littleBoxSize = QSize((bluePrintSize.height() * box->boxSize().width()) / pigsHall->getSize().height(), (bluePrintSize.height() * box->boxSize().height()) / pigsHall->getSize().height());
            box->setRect(QRect(currentPoint, littleBoxSize));

            currentPoint = QPoint(currentPoint.x() + littleBoxSize.width() + 10, currentPoint.y());
        }

        if(currentPoint.x() > bluePrintSize.width() && currentPoint.y() == 4)
            currentPoint = QPoint(4, height() - 4 - (bluePrintSize.height() * box->boxSize().height()) / pigsHall->getSize().height());


    }
}

PigsBox* HallBluePrintWidget::boxAt(QPoint pt){
    QVector<PigsBox*> boxes = pigsHall->pigsBoxes();

    for(PigsBox* box : boxes) {
        if(box->getRect().contains(pt))
            return box;
    }

    return nullptr;
}

void HallBluePrintWidget::mouseMoveEvent(QMouseEvent *event){
    PigsBox* box = boxAt(event->pos());

    if(box)
        setCursor(Qt::PointingHandCursor);
    else
        setCursor(Qt::ArrowCursor);
}

void HallBluePrintWidget::paintEvent(QPaintEvent*) {
    QPainter p(this);

    QVector<PigsBox*> boxes = pigsHall->pigsBoxes();

    for(PigsBox* box : boxes) {
        if(box->boxType().getBoxType() == PigsBoxType::LittleBox)
            p.setPen(QPen(QColor("#c2946e"), 3));

        if(box->boxType().getBoxType() == PigsBoxType::NormalBox)
            p.setPen(QPen(QColor("#80644d"), 3));

        p.drawRect(box->getRect());
    }
}

void HallBluePrintWidget::resizeEvent(QResizeEvent *){
    resizeBoxes();
}
/**********************************************************************/

/******************** HallPigsBoxLegend class *************************/
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

    painter.setPen(QPen(QColor("#c2946e"), 2));
    QRect redSquare = QRect(elementsPosition, squareSize);
    painter.drawRect(redSquare);

    painter.setPen(QPen(QColor("#ADBAC7"), 2));
    painter.drawText(QPoint(60, elementsPosition.y() + 20), "- Little Box");

    elementsPosition = QPoint(20, elementsPosition.y() + 60);
    painter.setPen(QPen(QColor("#80644d"), 2));
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
/**********************************************************************/
