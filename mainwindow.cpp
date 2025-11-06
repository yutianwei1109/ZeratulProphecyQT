#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "packmanagerdialog.h"
#include "preferencesdialog.h"
#include "rulesettingsdialog.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui->setupUi(this);
    ui->actionExit->setShortcut(QKeySequence("Alt+F4"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionHelp_triggered()
{
}

void MainWindow::on_actionPackageManager_triggered()
{
}

void MainWindow::on_actionRuleSettings_triggered()
{
}

void MainWindow::on_actionPreferences_triggered()
{
}

void MainWindow::on_actionCheckUpdate_triggered()
{
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionRefresh_triggered()
{
    
}

void MainWindow::on_actionRefreshAuto_triggered(bool checked)
{
    Q_UNUSED(checked);
}

void MainWindow::on_actionUndoFilter_triggered()
{
}

void MainWindow::on_actionRedoFilter_triggered()
{
}

void MainWindow::on_actionReset_triggered()
{
    
}

void MainWindow::on_actionAboutApp_triggered()
{
}

void MainWindow::on_actionAboutQt_triggered()
{
}

void MainWindow::on_pushButtonDel_clicked()
{
    
}

void MainWindow::on_pushButtonDel2_clicked()
{
    
}

void MainWindow::on_pushButtonDel3_clicked()
{
    
}

void MainWindow::on_pushButtonDel4_clicked()
{
    
}

void MainWindow::on_comboBoxStar_currentTextChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
}

void MainWindow::on_comboBoxRace_currentTextChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
}

void MainWindow::on_comboBoxName_currentTextChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
}

void MainWindow::on_pushButtonAddFeature_clicked()
{
    
}

void MainWindow::on_pushButtonAddNoFeature_clicked()
{
    
}

void MainWindow::on_pushButtonAddExcept_clicked()
{
    
}

void MainWindow::on_pushButtonReset_clicked()
{
    on_actionReset_triggered();
}

void MainWindow::on_pushButtonRefresh_clicked()
{
    on_actionRefresh_triggered();
}
