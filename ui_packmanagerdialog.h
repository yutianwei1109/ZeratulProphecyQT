/********************************************************************************
** Form generated from reading UI file 'packmanagerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PACKMANAGERDIALOG_H
#define UI_PACKMANAGERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PackManagerDialog
{
public:
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_4;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PackManagerDialog)
    {
        if (PackManagerDialog->objectName().isEmpty())
            PackManagerDialog->setObjectName(QString::fromUtf8("PackManagerDialog"));
        PackManagerDialog->resize(579, 397);
        verticalLayout_6 = new QVBoxLayout(PackManagerDialog);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox = new QGroupBox(PackManagerDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);


        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(PackManagerDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        listWidget_2 = new QListWidget(groupBox_2);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));

        verticalLayout_2->addWidget(listWidget_2);


        horizontalLayout_3->addWidget(groupBox_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(PackManagerDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(PackManagerDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(PackManagerDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        label_4 = new QLabel(PackManagerDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        label_5 = new QLabel(PackManagerDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        comboBox = new QComboBox(PackManagerDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout_4->addWidget(comboBox);

        comboBox_2 = new QComboBox(PackManagerDialog);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        verticalLayout_4->addWidget(comboBox_2);

        lineEdit = new QLineEdit(PackManagerDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_4->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(PackManagerDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_4->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(PackManagerDialog);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_4->addWidget(lineEdit_3);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton = new QPushButton(PackManagerDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(PackManagerDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_5->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_3);

        buttonBox = new QDialogButtonBox(PackManagerDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_6->addWidget(buttonBox);


        retranslateUi(PackManagerDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PackManagerDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PackManagerDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PackManagerDialog);
    } // setupUi

    void retranslateUi(QDialog *PackManagerDialog)
    {
        PackManagerDialog->setWindowTitle(QApplication::translate("PackManagerDialog", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("PackManagerDialog", "\346\240\270\345\277\203\345\215\241\347\211\214", nullptr));
        groupBox_2->setTitle(QApplication::translate("PackManagerDialog", "\346\211\251\345\261\225\345\215\241\347\211\214", nullptr));
        label->setText(QApplication::translate("PackManagerDialog", "\346\230\237\347\272\247", nullptr));
        label_2->setText(QApplication::translate("PackManagerDialog", "\347\247\215\346\227\217", nullptr));
        label_3->setText(QApplication::translate("PackManagerDialog", "\345\220\215\347\247\260", nullptr));
        label_4->setText(QApplication::translate("PackManagerDialog", "\346\225\260\351\207\217", nullptr));
        label_5->setText(QApplication::translate("PackManagerDialog", "\346\210\230\345\212\233", nullptr));
        pushButton->setText(QApplication::translate("PackManagerDialog", "\344\277\256\346\224\271", nullptr));
        pushButton_2->setText(QApplication::translate("PackManagerDialog", "\346\226\260\345\242\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PackManagerDialog: public Ui_PackManagerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACKMANAGERDIALOG_H
