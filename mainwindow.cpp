#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "packmanagerdialog.h"
#include "preferencesdialog.h"
#include "rulesettingsdialog.h"
#include "cardmanager.h"

#include <algorithm>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_isRunning(true)
    , m_isAutoRefresh(false)
    , m_cardManager(new CardManager(this))
    , m_featureListModel(nullptr)
    , m_noFeatureListModel(nullptr)
    , m_exceptListModel(nullptr)
    , m_possibleListModel(nullptr)
    , m_comboBoxNameListModel(new QStringListModel(this))
    , m_curFilterCard()
{
    ui->setupUi(this);

    // Load data
    if(m_cardManager->init() == false) {
        QMessageBox::critical(nullptr, "Failure", "Data load failed.");
        m_isRunning = false;
    }

    if(m_isRunning) {
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
}

MainWindow::~MainWindow()
{
    m_cardManager = nullptr;

    if(m_isRunning) {
        m_featureListModel = nullptr;
        m_noFeatureListModel = nullptr;
        m_exceptListModel = nullptr;
        m_possibleListModel = nullptr;
    }

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
    if(checked) {
        m_isAutoRefresh = true;
        ui->actionRefresh->setEnabled(false);
        ui->pushButtonRefresh->setEnabled(false);
    } else {
        m_isAutoRefresh = false;
        ui->actionRefresh->setEnabled(true);
        ui->pushButtonRefresh->setEnabled(true);
    }
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
    QModelIndex index = ui->listViewFeature->currentIndex();
    if(index.isValid()) {
        m_featureListModel->removeData(index);
    }
}

void MainWindow::on_pushButtonDel2_clicked()
{
    QModelIndex index = ui->listViewNoFeature->currentIndex();
    if(index.isValid()) {
        m_noFeatureListModel->removeData(index);
    }
}

void MainWindow::on_pushButtonDel3_clicked()
{
    QModelIndex index = ui->listViewExcept->currentIndex();
    if(index.isValid()) {
        m_curFilterCard = m_exceptListModel->getData(index);
        m_exceptListModel->removeData(index);
        if (m_curFilterCard.m_name == "<custom>") {
            return;
        } else {
            m_possibleListModel->appendData(m_curFilterCard);
        }
    }
}

void MainWindow::on_pushButtonDel4_clicked()
{
    QModelIndex index = ui->listViewPossible->currentIndex();
    if(index.isValid()) {
        m_possibleListModel->removeData(index);
    }
}

void MainWindow::on_comboBoxStar_currentTextChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    setComboBoxNameList();
}

void MainWindow::on_comboBoxRace_currentTextChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    setComboBoxNameList();
}

void MainWindow::on_comboBoxName_currentTextChanged(const QString &arg1)
{
    if(arg1 == "<custom>") {
        ui->lineEditNumber->setEnabled(true);
        ui->lineEditPower->setEnabled(true);
        ui->lineEditNumber->clear();
        ui->lineEditPower->clear();
    } else {
        ui->lineEditNumber->setEnabled(false);
        ui->lineEditPower->setEnabled(false);
        const auto& allCards = m_cardManager->getAllCards();
        for(const auto& card : allCards) {
            if(card.m_name == arg1) {
                m_curFilterCard = card;
                ui->lineEditNumber->setText(QString::number(card.m_number));
                ui->lineEditPower->setText(QString::number(card.m_power));
                break;
            }
        }
    }
}

void MainWindow::on_pushButtonAddFeature_clicked()
{
    if (!setCurFilterCard()) return;
    m_featureListModel->appendData(m_curFilterCard);
}

void MainWindow::on_pushButtonAddNoFeature_clicked()
{
    if (!setCurFilterCard()) return;
    m_noFeatureListModel->appendData(m_curFilterCard);
}

void MainWindow::on_pushButtonAddExcept_clicked()
{
    if (!setCurFilterCard()) return;
    m_exceptListModel->appendData(m_curFilterCard);
}

void MainWindow::on_pushButtonReset_clicked()
{
    on_actionReset_triggered();
}

void MainWindow::on_pushButtonRefresh_clicked()
{
    on_actionRefresh_triggered();
}

void MainWindow::setComboBoxNameList() {
    const auto& allCards = m_cardManager->getAllCards();
    const QString& starStr = ui->comboBoxStar->currentText();
    int star = starStr.toInt();
    const QString& race = ui->comboBoxRace->currentText();

    QStringList nameList;
    nameList.append("<custom>");
    for(const auto& card : allCards) {
        if(card.m_star == star && card.m_race == race) {
            nameList.append(card.m_name);
        }
    }

    m_comboBoxNameListModel->setStringList(nameList);
    if(nameList.size() > 0) {
        ui->comboBoxName->setCurrentIndex(0);
    }
}

bool MainWindow::setCurFilterCard() {
    // check filter
    if (ui->lineEditNumber->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Error", "Card number is empty");
        return false;
    }
    if (ui->lineEditPower->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Error", "Card power is empty");
        return false;
    }

    if (ui->comboBoxName->currentText() == "<custom>") {
        m_curFilterCard.m_id = 0;
        m_curFilterCard.m_star = ui->comboBoxStar->currentText().toInt();
        m_curFilterCard.m_race = ui->comboBoxRace->currentText();
        m_curFilterCard.m_name = "<custom>";
        m_curFilterCard.m_number = ui->lineEditNumber->text().toInt();
        m_curFilterCard.m_power = ui->lineEditPower->text().toInt();
    }
    return true;
}
