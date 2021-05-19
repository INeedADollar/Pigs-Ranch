#ifndef PIGSBOXINFODIALOG_H
#define PIGSBOXINFODIALOG_H

#include <QDialog>

namespace Ui {
class PigsBoxInfoDialog;
}

class PigsBoxInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PigsBoxInfoDialog(QWidget *parent = nullptr);
    ~PigsBoxInfoDialog();

private:
    Ui::PigsBoxInfoDialog *ui;
};

#endif // PIGSBOXINFODIALOG_H
