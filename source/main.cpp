#include "headers/basewindow.h"
#include "headers/createmenu.h"
#include "headers/hallwindow.h"
#include "headers/pigsboxinfodialog.h"
#include "headers/ranchwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  /*BaseWindow w;
  w.show();*/

  HallWindow hall;
  hall.show();

  PigsBoxInfoDialog d;
  d.setBoxName("Box#1");
  d.setBoxHallName("Hall#1");

  PigsBoxType boxType;
  boxType.setBoxType(PigsBoxType::LittleBox);
  d.setBoxType(boxType);

  d.setPigsNumber(100);
  d.setPopulationDate("11/09/2020");
  d.setReleaseDate("23/03/2021");
  d.setBoxDimensions(QSize(100, 200));
  d.show();

  return a.exec();
}
