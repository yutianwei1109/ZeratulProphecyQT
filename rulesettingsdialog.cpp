#include "rulesettingsdialog.h"
#include "ui_rulesettingsdialog.h"

RuleSettingsDialog::RuleSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RuleSettingsDialog)
{
    ui->setupUi(this);
}

RuleSettingsDialog::~RuleSettingsDialog()
{
    delete ui;
}
