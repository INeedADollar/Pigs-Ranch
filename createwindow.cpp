#include "createwindow.h"
#include "ui_createwindow.h"

CreateWindow::CreateWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CreateWindow) {
  ui->setupUi(this);
  this->parent = parent;
}

CreateWindow::~CreateWindow() { delete ui; }
