#ifndef CREATEWINDOW_H
#define CREATEWINDOW_H

#include <QMainWindow>

/********************** CreateWindow class ********************/
namespace Ui {
class CreateWindow;
}

class CreateWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit CreateWindow(QWidget *parent = nullptr);
  ~CreateWindow();

private:
  Ui::CreateWindow *ui;
  QWidget *parent;
};
/**************************************************************/

#endif // CREATEWINDOW_H
