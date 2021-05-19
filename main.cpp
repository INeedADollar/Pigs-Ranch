#include "headers/basewindow.h"
#include "headers/createmenu.h"
#include "ranchwindow.h"
#include "pigsboxinfodialog.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  /*BaseWindow w;
  w.show();*/

  RanchWindow ranch;
  ranch.show();

  PigsBoxInfoDialog d;
  d.show();
  return a.exec();
}
