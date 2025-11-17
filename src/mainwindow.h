#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "src/model/userlistmodelsmanager.h"
#include "src/common/card_struct.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void widgetEnableStatusInit();
    void refreshComboBoxName();
    void curSelectCardReset();
    void setCurSelectCardWithFilter();

private slots:
    // Menu File
    void on_actionHelp_triggered();
    void on_actionPackageManager_triggered();
    void on_actionRuleSettings_triggered();
    void on_actionPreferences_triggered();
    void on_actionCheckUpdate_triggered();
    void on_actionExit_triggered();
    // Menu Edit
    void on_actionRefresh_triggered();
    void on_actionRefreshAuto_triggered(bool checked);
    void on_actionUndoFilter_triggered();
    void on_actionRedoFilter_triggered();
    void on_actionReset_triggered();
    // Menu About
    void on_actionAboutApp_triggered();
    void on_actionAboutQt_triggered();
    // listView Button
    void on_pushButtonDel_clicked();
    void on_pushButtonDel2_clicked();
    void on_pushButtonDel3_clicked();
    void on_pushButtonDel4_clicked();
    // Filter
    void on_comboBoxStar_currentTextChanged(const QString &arg1);
    void on_comboBoxRace_currentTextChanged(const QString &arg1);
    void on_comboBoxName_currentTextChanged(const QString &arg1);
    void on_lineEditNumber_textChanged(const QString &arg1);
    void on_lineEditPower_textChanged(const QString &arg1);
    // Button
    void on_pushButtonAddFeature_clicked();
    void on_pushButtonAddNoFeature_clicked();
    void on_pushButtonAddExcept_clicked();
    void on_pushButtonReset_clicked();
    void on_pushButtonRefresh_clicked();

private:
    Ui::MainWindow *ui;
    UserListModelsManager *m_modelsManager;
    bool m_isWorking;
    bool m_refreshAuto;
    card_struct m_curSelectCard;
};
#endif // MAINWINDOW_H
