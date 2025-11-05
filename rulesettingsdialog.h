#ifndef RULESETTINGSDIALOG_H
#define RULESETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class RuleSettingsDialog;
}

class RuleSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RuleSettingsDialog(QWidget *parent = nullptr);
    ~RuleSettingsDialog();

private:
    Ui::RuleSettingsDialog *ui;
};

#endif // RULESETTINGSDIALOG_H
