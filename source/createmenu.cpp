#include "headers/createmenu.h"
#include "ui_loginmenu.h"
#include <QCloseEvent>
#include <QMessageBox>
#include <QtGui>

CreateMenu::CreateMenu(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CreateMenu) {
  ui->setupUi(this);
  this->parent = parent;
  parent->hide();
}

void CreateMenu::closeEvent(QCloseEvent *event) { this->parent->show(); }

CreateMenu::~CreateMenu() { delete ui; }
