#include "headers/basewindow.h"
#include "headers/createmenu.h"
#include "headers/hallwindow.h"
#include "headers/pigsboxinfodialog.h"
#include "headers/hallswindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
      QApplication a(argc, argv);
      BaseWindow w;
      //w.show();

      HallWindow hall;
      PigsHall *pHall = new PigsHall;
      pHall->setSize(QSize(100, 20));
      hall.setPigsHall(pHall);
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
      //d.show();

      HallsWindow wind;
      wind.show();

      QListWidgetItem *item = new QListWidgetItem("Hall #1");

      QFont font = item->font();
      font.setPixelSize(25);
      QIcon ico(":/assets/bullet.png");

      item->setSizeHint(QSize(item->sizeHint().width() - 100, 100));
      item->setFont(font);
      item->setTextAlignment(Qt::AlignCenter);
      item->setIcon(ico);
      item->setBackground(QColor("#1F3143"));
      wind.addListItem(item);

      item = new QListWidgetItem("Hall #2");
    item->setSizeHint(QSize(item->sizeHint().width() - 100, 100));
    item->setFont(font);
    item->setTextAlignment(Qt::AlignCenter);
    item->setIcon(ico);
    item->setBackground(QColor("#1F3143"));
    wind.addListItem(item);

    item = new QListWidgetItem("Hall #3");
    item->setSizeHint(QSize(0, 100));
    item->setFont(font);
    item->setTextAlignment(Qt::AlignCenter);
    item->setIcon(ico);
    item->setBackground(QColor("#1F3143"));
    wind.addListItem(item);

    item = new QListWidgetItem("Hall #4");
    item->setSizeHint(QSize(item->sizeHint().width() - 100, 100));
    item->setFont(font);
    item->setTextAlignment(Qt::AlignCenter);
    item->setIcon(ico);
    item->setBackground(QColor("#1F3143"));
    wind.addListItem(item);

  return a.exec();
}
