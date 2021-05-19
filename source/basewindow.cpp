#include "headers/basewindow.h"
#include "headers/createmenu.h"
#include "ui_basewindow.h"

BaseWindow::BaseWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::BaseWindow) {
  ui->setupUi(this);
}

BaseWindow::~BaseWindow() { delete ui; }

void BaseWindow::on_pushButton_clicked() {

  //  // creating a new instance
  //  CreateMenu *login = new CreateMenu(this);
  //  login->show(); // this is how to display a new window
}

void BaseWindow::on_pushButton_2_clicked() {
  CreateWindow *create = new CreateWindow(this);
  create->show();
}
