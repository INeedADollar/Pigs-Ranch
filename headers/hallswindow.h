#ifndef HALLSWINDOW_H
#define HALLSWINDOW_H

#include <QListWidgetItem>
#include <QWidget>

namespace Ui {
class HallsWindow;
}

class HallsListWidget : public QListWidget {

public:
    HallsListWidget(QWidget *parent = nullptr);
    ~HallsListWidget();

protected:
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
};

class HallsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HallsWindow(QWidget *parent = nullptr);
    ~HallsWindow();

    void addListItem(QListWidgetItem*);

private:
    Ui::HallsWindow *ui;
};

#endif // HALLSWINDOW_H
