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
<<<<<<< HEAD
=======

    // Load data
    if (m_cardManager->init() == false)
    {
        QMessageBox::critical(nullptr, "Failure", "Data load failed.");
        m_isRunning = false;
    }

    if (m_isRunning)
    {
        // Set up models
        m_featureListModel = new userListModel(this, m_cardManager, userListIndex::FEATURE);
        m_noFeatureListModel = new userListModel(this, m_cardManager, userListIndex::NOFEATURE);
        m_exceptListModel = new userListModel(this, m_cardManager, userListIndex::EXCEPT);
        m_possibleListModel = new userListModel(this, m_cardManager, userListIndex::POSSIBLE);

        // Set up views
        ui->listViewFeature->setModel(m_featureListModel);
        ui->listViewNoFeature->setModel(m_noFeatureListModel);
        ui->listViewExcept->setModel(m_exceptListModel);
        ui->listViewPossible->setModel(m_possibleListModel);

        // init combo boxes
        ui->comboBoxStar->addItems(ruleSets::cardStar);
        ui->comboBoxStar->setCurrentText("1");
        ui->comboBoxRace->addItems(ruleSets::cardRaces);
        ui->comboBoxName->setModel(m_comboBoxNameListModel);
        setComboBoxNameList();

        // Activate actions and buttons
        ui->actionRefresh->setEnabled(true);
        ui->actionRefreshAuto->setEnabled(true);
        ui->actionReset->setEnabled(true);
        ui->pushButtonDel->setEnabled(true);
        ui->pushButtonDel2->setEnabled(true);
        ui->pushButtonDel3->setEnabled(true);
        ui->pushButtonDel4->setEnabled(true);
        ui->comboBoxStar->setEnabled(true);
        ui->comboBoxRace->setEnabled(true);
        ui->comboBoxName->setEnabled(true);
        ui->lineEditNumber->setEnabled(true);
        ui->lineEditPower->setEnabled(true);
        ui->pushButtonAddFeature->setEnabled(true);
        ui->pushButtonAddNoFeature->setEnabled(true);
        ui->pushButtonAddExcept->setEnabled(true);
        ui->pushButtonReset->setEnabled(true);
        ui->pushButtonRefresh->setEnabled(true);
    }
>>>>>>> 9110f1393985e7e2218bbab7c2d552881c43eab8
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
    QApplication::aboutQt();
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
<<<<<<< HEAD
    
=======
    if (!setCurFilterCard())
        return;
    m_featureListModel->appendData(m_curFilterCard);
    m_possibleListModel->updatePossibleListFromFeatureCard(m_curFilterCard);
>>>>>>> 9110f1393985e7e2218bbab7c2d552881c43eab8
}

void MainWindow::on_pushButtonAddNoFeature_clicked()
{
<<<<<<< HEAD
    
=======
    if (!setCurFilterCard())
        return;
    m_noFeatureListModel->appendData(m_curFilterCard);
    m_possibleListModel->updatePossibleListFromNoFeatureCard(m_curFilterCard);
>>>>>>> 9110f1393985e7e2218bbab7c2d552881c43eab8
}

void MainWindow::on_pushButtonAddExcept_clicked()
{
<<<<<<< HEAD
    
=======
    if (!setCurFilterCard())
        return;
    if (m_curFilterCard.m_name == "<custom>")
    {
        QMessageBox::warning(this, "Error", "Can't add custom card to except list");
        return;
    }
    m_exceptListModel->appendData(m_curFilterCard);
    m_possibleListModel->updatePossibleListFromExceptCard(m_curFilterCard);
>>>>>>> 9110f1393985e7e2218bbab7c2d552881c43eab8
}

void MainWindow::on_pushButtonReset_clicked()
{
    on_actionReset_triggered();
}

void MainWindow::on_pushButtonRefresh_clicked()
{
    on_actionRefresh_triggered();
}
