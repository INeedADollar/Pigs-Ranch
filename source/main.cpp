#include "headers/hallwindow.h"
#include "headers/pigsboxinfodialog.h"
#include "headers/hallswindow.h"
#include "headers/questiondialog.h"

#include <QApplication>
#include <QDate>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    HallsWindow wind;
    wind.setWindowTitle("Ranch overview");
    wind.show();

    return a.exec();
}
