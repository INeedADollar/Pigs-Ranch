#include "headers/hallwindow.h"
#include "headers/pigsboxinfodialog.h"
#include "headers/hallswindow.h"
#include "headers/questiondialog.h"

#include <QApplication>
#include <QDate>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    PigsBoxInfoDialog d;
    d.setBoxName("Box#1");
    d.setBoxHallName("Hall#1");

    PigsBoxType boxType;
    boxType.setBoxType(PigsBoxType::LittleBox);
    d.setBoxType(boxType);

    d.setPigsNumber(100);
    d.setPopulationDate(QDate::currentDate().toString("dd/MM/yyyy"));
    d.setReleaseDate("-");
    d.setBoxDimensions(QSize(100, 200));
    d.show();

    HallsWindow wind;
    wind.setWindowTitle("Ranch overview");
    wind.show();

    QuestionDialog *dial = new QuestionDialog;
    dial->setWindowTitle("Error");
    dial->setDisplayText(QString("Hall does not have enough space for all pigs [%1 little pigs remained "
                             "(%2 little pigs boxes overflow), %4 normal pigs remained (%4 normal pigs boxes overflow)]. "
                             "Do you want to create hall anyway?"));
    dial->setMinimumWidth(700);
    dial->show();

    return a.exec();
}
