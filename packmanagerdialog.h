#ifndef PACKMANAGERDIALOG_H
#define PACKMANAGERDIALOG_H

#include <QDialog>

namespace Ui {
class PackManagerDialog;
}

class PackManagerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PackManagerDialog(QWidget *parent = nullptr);
    ~PackManagerDialog();

private:
    Ui::PackManagerDialog *ui;
};

#endif // PACKMANAGERDIALOG_H
