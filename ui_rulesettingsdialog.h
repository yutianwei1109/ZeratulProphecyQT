/********************************************************************************
** Form generated from reading UI file 'rulesettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULESETTINGSDIALOG_H
#define UI_RULESETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_RuleSettingsDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RuleSettingsDialog)
    {
        if (RuleSettingsDialog->objectName().isEmpty())
            RuleSettingsDialog->setObjectName(QString::fromUtf8("RuleSettingsDialog"));
        RuleSettingsDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(RuleSettingsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(RuleSettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), RuleSettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RuleSettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(RuleSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *RuleSettingsDialog)
    {
        RuleSettingsDialog->setWindowTitle(QApplication::translate("RuleSettingsDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RuleSettingsDialog: public Ui_RuleSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULESETTINGSDIALOG_H
