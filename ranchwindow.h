#ifndef RANCHWINDOW_H
#define RANCHWINDOW_H

#include <QWidget>

namespace Ui {
class RanchWindow;
}

class RanchWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RanchWindow(QWidget *parent = nullptr);
    ~RanchWindow();

protected:
    void paintEvent(QPaintEvent*);

private:
    Ui::RanchWindow *ui;
};

#endif // RANCHWINDOW_H
