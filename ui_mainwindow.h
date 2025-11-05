/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPackageManager;
    QAction *actionPreferences;
    QAction *actionExit;
    QAction *actionUndoFilter;
    QAction *actionRedoFilter;
    QAction *actionReset;
    QAction *actionHelp;
    QAction *actionCheckUpdate;
    QAction *actionAboutApp;
    QAction *actionAboutQt;
    QAction *actionRuleSettings;
    QAction *actionRefresh;
    QAction *actionRefreshAuto;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListView *listViewFeature;
    QPushButton *pushButtonDel;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QListView *listViewNoFeature;
    QPushButton *pushButtonDel2;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QListView *listViewExcept;
    QPushButton *pushButtonDel3;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_7;
    QListView *listViewPossible;
    QPushButton *pushButtonDel4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBoxStar;
    QLabel *label_2;
    QComboBox *comboBoxRace;
    QLabel *label_3;
    QComboBox *comboBoxName;
    QLabel *label_4;
    QLineEdit *lineEditNumber;
    QLabel *label_5;
    QLineEdit *lineEditPower;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonAddFeature;
    QPushButton *pushButtonAddNoFeature;
    QPushButton *pushButtonAddExcept;
    QPushButton *pushButtonReset;
    QPushButton *pushButtonRefresh;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(904, 573);
        actionPackageManager = new QAction(MainWindow);
        actionPackageManager->setObjectName(QString::fromUtf8("actionPackageManager"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionUndoFilter = new QAction(MainWindow);
        actionUndoFilter->setObjectName(QString::fromUtf8("actionUndoFilter"));
        actionRedoFilter = new QAction(MainWindow);
        actionRedoFilter->setObjectName(QString::fromUtf8("actionRedoFilter"));
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionCheckUpdate = new QAction(MainWindow);
        actionCheckUpdate->setObjectName(QString::fromUtf8("actionCheckUpdate"));
        actionAboutApp = new QAction(MainWindow);
        actionAboutApp->setObjectName(QString::fromUtf8("actionAboutApp"));
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName(QString::fromUtf8("actionAboutQt"));
        actionRuleSettings = new QAction(MainWindow);
        actionRuleSettings->setObjectName(QString::fromUtf8("actionRuleSettings"));
        actionRefresh = new QAction(MainWindow);
        actionRefresh->setObjectName(QString::fromUtf8("actionRefresh"));
        actionRefreshAuto = new QAction(MainWindow);
        actionRefreshAuto->setObjectName(QString::fromUtf8("actionRefreshAuto"));
        actionRefreshAuto->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_8 = new QVBoxLayout(centralwidget);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listViewFeature = new QListView(groupBox);
        listViewFeature->setObjectName(QString::fromUtf8("listViewFeature"));

        verticalLayout->addWidget(listViewFeature);

        pushButtonDel = new QPushButton(groupBox);
        pushButtonDel->setObjectName(QString::fromUtf8("pushButtonDel"));

        verticalLayout->addWidget(pushButtonDel);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        listViewNoFeature = new QListView(groupBox_2);
        listViewNoFeature->setObjectName(QString::fromUtf8("listViewNoFeature"));

        verticalLayout_5->addWidget(listViewNoFeature);

        pushButtonDel2 = new QPushButton(groupBox_2);
        pushButtonDel2->setObjectName(QString::fromUtf8("pushButtonDel2"));

        verticalLayout_5->addWidget(pushButtonDel2);


        horizontalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setFlat(false);
        groupBox_3->setCheckable(false);
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        listViewExcept = new QListView(groupBox_3);
        listViewExcept->setObjectName(QString::fromUtf8("listViewExcept"));

        verticalLayout_6->addWidget(listViewExcept);

        pushButtonDel3 = new QPushButton(groupBox_3);
        pushButtonDel3->setObjectName(QString::fromUtf8("pushButtonDel3"));

        verticalLayout_6->addWidget(pushButtonDel3);


        horizontalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setFlat(false);
        groupBox_4->setCheckable(false);
        verticalLayout_7 = new QVBoxLayout(groupBox_4);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        listViewPossible = new QListView(groupBox_4);
        listViewPossible->setObjectName(QString::fromUtf8("listViewPossible"));

        verticalLayout_7->addWidget(listViewPossible);

        pushButtonDel4 = new QPushButton(groupBox_4);
        pushButtonDel4->setObjectName(QString::fromUtf8("pushButtonDel4"));

        verticalLayout_7->addWidget(pushButtonDel4);


        horizontalLayout->addWidget(groupBox_4);


        verticalLayout_8->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        comboBoxStar = new QComboBox(centralwidget);
        comboBoxStar->setObjectName(QString::fromUtf8("comboBoxStar"));

        horizontalLayout_2->addWidget(comboBoxStar);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        comboBoxRace = new QComboBox(centralwidget);
        comboBoxRace->setObjectName(QString::fromUtf8("comboBoxRace"));

        horizontalLayout_2->addWidget(comboBoxRace);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        comboBoxName = new QComboBox(centralwidget);
        comboBoxName->setObjectName(QString::fromUtf8("comboBoxName"));

        horizontalLayout_2->addWidget(comboBoxName);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_4);

        lineEditNumber = new QLineEdit(centralwidget);
        lineEditNumber->setObjectName(QString::fromUtf8("lineEditNumber"));

        horizontalLayout_2->addWidget(lineEditNumber);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_5);

        lineEditPower = new QLineEdit(centralwidget);
        lineEditPower->setObjectName(QString::fromUtf8("lineEditPower"));

        horizontalLayout_2->addWidget(lineEditPower);


        verticalLayout_8->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButtonAddFeature = new QPushButton(centralwidget);
        pushButtonAddFeature->setObjectName(QString::fromUtf8("pushButtonAddFeature"));

        horizontalLayout_3->addWidget(pushButtonAddFeature);

        pushButtonAddNoFeature = new QPushButton(centralwidget);
        pushButtonAddNoFeature->setObjectName(QString::fromUtf8("pushButtonAddNoFeature"));

        horizontalLayout_3->addWidget(pushButtonAddNoFeature);

        pushButtonAddExcept = new QPushButton(centralwidget);
        pushButtonAddExcept->setObjectName(QString::fromUtf8("pushButtonAddExcept"));

        horizontalLayout_3->addWidget(pushButtonAddExcept);

        pushButtonReset = new QPushButton(centralwidget);
        pushButtonReset->setObjectName(QString::fromUtf8("pushButtonReset"));

        horizontalLayout_3->addWidget(pushButtonReset);

        pushButtonRefresh = new QPushButton(centralwidget);
        pushButtonRefresh->setObjectName(QString::fromUtf8("pushButtonRefresh"));

        horizontalLayout_3->addWidget(pushButtonRefresh);


        verticalLayout_8->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 904, 28));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionHelp);
        menuFile->addSeparator();
        menuFile->addAction(actionPackageManager);
        menuFile->addAction(actionRuleSettings);
        menuFile->addSeparator();
        menuFile->addAction(actionPreferences);
        menuFile->addAction(actionCheckUpdate);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionRefresh);
        menuEdit->addAction(actionRefreshAuto);
        menuEdit->addSeparator();
        menuEdit->addAction(actionUndoFilter);
        menuEdit->addAction(actionRedoFilter);
        menuEdit->addSeparator();
        menuEdit->addAction(actionReset);
        menuAbout->addAction(actionAboutApp);
        menuAbout->addAction(actionAboutQt);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\230\237\351\231\205\351\205\222\351\246\206\346\263\275\346\213\211\345\233\276\351\242\204\350\250\200\347\211\214\347\255\233\351\200\211\345\231\250", nullptr));
        actionPackageManager->setText(QApplication::translate("MainWindow", "\345\215\241\345\214\205\347\256\241\347\220\206", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPackageManager->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionPreferences->setText(QApplication::translate("MainWindow", "\351\246\226\351\200\211\351\241\271", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPreferences->setShortcut(QApplication::translate("MainWindow", "Ctrl+,", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionUndoFilter->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\200\346\255\245", nullptr));
#ifndef QT_NO_SHORTCUT
        actionUndoFilter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_NO_SHORTCUT
        actionRedoFilter->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\346\255\245", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRedoFilter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", nullptr));
#endif // QT_NO_SHORTCUT
        actionReset->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256", nullptr));
#ifndef QT_NO_SHORTCUT
        actionReset->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        actionHelp->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\345\270\256\345\212\251", nullptr));
#ifndef QT_NO_SHORTCUT
        actionHelp->setShortcut(QApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_NO_SHORTCUT
        actionCheckUpdate->setText(QApplication::translate("MainWindow", "\346\243\200\346\237\245\346\233\264\346\226\260", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCheckUpdate->setShortcut(QApplication::translate("MainWindow", "Ctrl+U", nullptr));
#endif // QT_NO_SHORTCUT
        actionAboutApp->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216\346\234\254\347\250\213\345\272\217", nullptr));
#ifndef QT_NO_SHORTCUT
        actionAboutApp->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_NO_SHORTCUT
        actionAboutQt->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216QT", nullptr));
#ifndef QT_NO_SHORTCUT
        actionAboutQt->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+I", nullptr));
#endif // QT_NO_SHORTCUT
        actionRuleSettings->setText(QApplication::translate("MainWindow", "\350\247\204\345\210\231\350\256\276\347\275\256", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRuleSettings->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        actionRefresh->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRefresh->setShortcut(QApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        actionRefreshAuto->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\345\210\267\346\226\260", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRefreshAuto->setShortcut(QApplication::translate("MainWindow", "Ctrl+F5", nullptr));
#endif // QT_NO_SHORTCUT
        groupBox->setTitle(QApplication::translate("MainWindow", "\347\211\271\345\276\201\345\215\241", nullptr));
        pushButtonDel->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\351\235\236\347\211\271\345\276\201\345\215\241", nullptr));
        pushButtonDel2->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\346\216\222\351\231\244\345\215\241", nullptr));
        pushButtonDel3->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\345\200\231\351\200\211\345\215\241", nullptr));
        pushButtonDel4->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244/\346\216\222\351\231\244", nullptr));
        label->setText(QApplication::translate("MainWindow", "\346\230\237\347\272\247", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\347\247\215\346\227\217", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\345\215\241\347\211\214\345\220\215\347\247\260", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\345\215\225\344\275\215\346\225\260\351\207\217", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\346\210\230\346\226\227\345\212\233", nullptr));
        pushButtonAddFeature->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\347\211\271\345\276\201\345\215\241", nullptr));
        pushButtonAddNoFeature->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\351\235\236\347\211\271\345\276\201\345\215\241", nullptr));
        pushButtonAddExcept->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\345\267\262\346\216\222\351\231\244\345\215\241", nullptr));
        pushButtonReset->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256", nullptr));
        pushButtonRefresh->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(F)", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(E)", nullptr));
        menuAbout->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216(A)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
