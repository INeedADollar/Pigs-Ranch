#ifndef RANCHWINDOW_H
#define RANCHWINDOW_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class RanchWindow;
}

class RanchWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RanchWindow(QWidget *parent = nullptr);
    ~RanchWindow();

    void addListItem(QListWidgetItem*);

private:
    Ui::RanchWindow *ui;
};

#endif // RANCHWINDOW_H
