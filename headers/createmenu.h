#ifndef CREATEMENU_H
#define CREATEMENU_H

#include <QDialog>
#include <QMainWindow>
#include <QWidget>

namespace Ui {
class CreateMenu;
}

class CreateMenu : public QMainWindow {
  Q_OBJECT

public:
  explicit CreateMenu(QWidget *parent = nullptr);
  ~CreateMenu();

protected:
  void closeEvent(QCloseEvent *event) override;

private:
  Ui::CreateMenu *ui;
  QWidget *parent;
};

#endif // CREATEMENU_H
