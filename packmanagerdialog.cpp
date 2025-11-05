#include "packmanagerdialog.h"
#include "ui_packmanagerdialog.h"

PackManagerDialog::PackManagerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PackManagerDialog)
{
    ui->setupUi(this);
}

PackManagerDialog::~PackManagerDialog()
{
    delete ui;
}
