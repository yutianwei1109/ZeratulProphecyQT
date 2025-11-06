#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>

#include "userlistmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Menu 文件
    void on_actionHelp_triggered();
    void on_actionPackageManager_triggered();
    void on_actionRuleSettings_triggered();
    void on_actionPreferences_triggered();
    void on_actionCheckUpdate_triggered();
    void on_actionExit_triggered();
    // Menu 编辑
    void on_actionRefresh_triggered();
    void on_actionRefreshAuto_triggered(bool checked);
    void on_actionUndoFilter_triggered();
    void on_actionRedoFilter_triggered();
    void on_actionReset_triggered();
    // Menu 关于
    void on_actionAboutApp_triggered();
    void on_actionAboutQt_triggered();

    // listView 删除
    void on_pushButtonDel_clicked();
    void on_pushButtonDel2_clicked();
    void on_pushButtonDel3_clicked();
    void on_pushButtonDel4_clicked();
    // filter 变更
    void on_comboBoxStar_currentTextChanged(const QString &arg1);
    void on_comboBoxRace_currentTextChanged(const QString &arg1);
    void on_comboBoxName_currentTextChanged(const QString &arg1);
    // listView 添加
    void on_pushButtonAddFeature_clicked();
    void on_pushButtonAddNoFeature_clicked();
    void on_pushButtonAddExcept_clicked();
    void on_pushButtonReset_clicked();
    void on_pushButtonRefresh_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
