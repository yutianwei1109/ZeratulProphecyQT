#include <QDebug>
#include <QMessageBox>

#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model/userlistmodelsmanager.h"

// #define _TEST
#ifdef _TEST
#include "../test/programtest.h"
#endif

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_modelsManager(nullptr)
    , m_isWorking(false)
    , m_refreshAuto(false)
    , m_curSelectCard()
{
    ui->setupUi(this);
    ui->actionExit->setShortcut(QKeySequence("Alt+F4"));

    m_modelsManager = UserListModelsManager::getInstance();
    qDebug() << "modelsManager address: " << (void*)m_modelsManager;

    ui->listViewFeature->setModel(m_modelsManager->getUserListModel(UserListType::FEATURE));
    ui->listViewNoFeature->setModel(m_modelsManager->getUserListModel(UserListType::NOFEATURE));
    ui->listViewExcept->setModel(m_modelsManager->getUserListModel(UserListType::EXCEPT));
    ui->listViewPossible->setModel(m_modelsManager->getUserListModel(UserListType::POSSIBLE));
    
    m_modelsManager->reset();

    // set comboBox
    QStringList starList;
    for(int i = cardRuleSets::minStar; i <= cardRuleSets::maxStar; ++i)
        starList << QString::number(i);
    ui->comboBoxStar->addItems(starList);

    QStringList raceList;
    for(const std::string& race: cardRuleSets::cardRaces) {
        raceList << QString::fromStdString(race);
    }
    ui->comboBoxRace->addItems(raceList);

#ifdef _TEST
    programTest test;
#endif

    widgetEnableStatusInit();
    ui->comboBoxStar->setCurrentIndex(1);
    ui->comboBoxRace->setCurrentIndex(0);
    refreshComboBoxName();
    ui->lineEditNumber->setText("0");
    ui->lineEditPower->setText("0");

    curSelectCardReset();
    setCurSelectCardWithFilter();
    
    m_isWorking = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::widgetEnableStatusInit() {
    // ui->actionHelp->setEnabled(true);
    // ui->actionPackageManager->setEnabled(true);
    // ui->actionRuleSettings->setEnabled(true);
    // ui->actionPreferences->setEnabled(true);
    // ui->actionCheckUpdate->setEnabled(true);

    ui->actionRefresh->setEnabled(true);
    ui->actionRefreshAuto->setEnabled(true);
    // ui->actionUndoFilter->setEnabled(true);
    // ui->actionRedoFilter->setEnabled(true);
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

void MainWindow::refreshComboBoxName() {
    ui->comboBoxName->clear();
    int star = ui->comboBoxStar->currentText().toInt();
    QString race = ui->comboBoxRace->currentText();
    QStringList nameList;
    nameList.append("<custom>");
    nameList += m_modelsManager->getNameListWithStarAndRace(star, race);
    ui->comboBoxName->addItems(nameList);
    ui->comboBoxName->setCurrentIndex(0);
}

void MainWindow::curSelectCardReset() {
    m_curSelectCard = card_struct(0, 1, "Neutral", "<custom>", 0, 0);
}

void MainWindow::setCurSelectCardWithFilter() {
    if(!m_isWorking) return;
    QString name = ui->comboBoxName->currentText().trimmed();
    if(name.isEmpty()) return;
    int id = m_modelsManager->getCardIdByCardName(name);
    if(id == -1) {
        QMessageBox::warning(this, "Error", "Can't find card with name: " + name);
        return;
    }
    int star = ui->comboBoxStar->currentText().toInt();
    QString race = ui->comboBoxRace->currentText();
    QString numberStr = ui->lineEditNumber->text().trimmed();
    if (numberStr.isEmpty()) numberStr = "0";
    QString powerStr = ui->lineEditPower->text().trimmed();
    if (powerStr.isEmpty()) powerStr = "0";
    m_curSelectCard = card_struct(
        id, star,
        race.toStdString(), name.toStdString(),
        numberStr.toInt(), powerStr.toInt()
    );
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
    m_modelsManager->refreshPossibleLists();
}

void MainWindow::on_actionRefreshAuto_triggered(bool checked)
{
    m_refreshAuto = checked;
}

void MainWindow::on_actionUndoFilter_triggered()
{

}

void MainWindow::on_actionRedoFilter_triggered()
{

}

void MainWindow::on_actionReset_triggered()
{
    m_modelsManager->reset();
}

void MainWindow::on_actionAboutApp_triggered()
{
    QMessageBox::about(
        this, "About", 
        // text
        "版权声明与授权​\n"
        "Copyright (C) 2025 Yutian Wei\n"
        "本项目包含的QT模块基于 GNU General Public License v3.0 (GPLv3)​ 开源授权协议发布。\n"
        "完整授权文本详见仓库内的 LICENSE文件。\n\n"
        "项目信息​\n"
        "仓库名称: ZeratulProphecyQT\n"
        "作者: yutianwei1109\n"
        "托管平台: GitHub\n"
        "访问链接: https://github.com/yutianwei1109/ZeratulProphecyQT\n\n"
        "关键说明​\n"
        "GPLv3 协议要求:\n"
        "衍生作品必须同样以 GPLv3 开源\n"
        "修改后的代码需保留原始版权声明\n"
        "分发时需提供完整源代码\n"
        // text end
    );
}

void MainWindow::on_actionAboutQt_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_pushButtonDel_clicked()
{
    QModelIndex index = ui->listViewFeature->currentIndex();
    const auto& card = m_modelsManager->getUserListModel(UserListType::FEATURE)->getCard(index.row());
    UserListUpdateData data(
        UserListType::FEATURE,
        UserListOperation::REMOVE,
        card
    );
    m_modelsManager->updateUserList(data);
}

void MainWindow::on_pushButtonDel2_clicked()
{
    QModelIndex index = ui->listViewNoFeature->currentIndex();
    const auto& card = m_modelsManager->getUserListModel(UserListType::NOFEATURE)->getCard(index.row());
    UserListUpdateData data(
        UserListType::NOFEATURE,
        UserListOperation::REMOVE,
        card
    );
    m_modelsManager->updateUserList(data);
}

void MainWindow::on_pushButtonDel3_clicked()
{
    QModelIndex index = ui->listViewExcept->currentIndex();
    const auto& card = m_modelsManager->getUserListModel(UserListType::EXCEPT)->getCard(index.row());
    UserListUpdateData data(
        UserListType::EXCEPT,
        UserListOperation::REMOVE,
        card
    );
    m_modelsManager->updateUserList(data);
}

void MainWindow::on_pushButtonDel4_clicked()
{
    QModelIndex index = ui->listViewPossible->currentIndex();
    const auto& card = m_modelsManager->getUserListModel(UserListType::POSSIBLE)->getCard(index.row());
    UserListUpdateData data(
        UserListType::POSSIBLE,
        UserListOperation::REMOVE,
        card
    );
    m_modelsManager->updateUserList(data);
}

void MainWindow::on_comboBoxStar_currentTextChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    refreshComboBoxName();
    curSelectCardReset();
    ui->lineEditNumber->clear();
    ui->lineEditPower->clear();
}

void MainWindow::on_comboBoxRace_currentTextChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    refreshComboBoxName();
    curSelectCardReset();
    ui->lineEditNumber->clear();
    ui->lineEditPower->clear();
}

void MainWindow::on_comboBoxName_currentTextChanged(const QString &arg1)
{
    if(!m_isWorking) return;
    const QString& name = arg1;
    if(name.isEmpty()) return;
    setCurSelectCardWithFilter();
    if(name == "<custom>") {
        ui->lineEditNumber->setEnabled(true);
        ui->lineEditPower->setEnabled(true);
        ui->lineEditNumber->clear();
        ui->lineEditPower->clear();
    } else {
        ui->lineEditNumber->setEnabled(false);
        ui->lineEditPower->setEnabled(false);

        const auto& card = m_modelsManager->getCardByName(name);
        if(card == card_struct()) {
            QMessageBox::warning(this, "Error", "Can't find card with name: " + name);
            return;
        }
        ui->lineEditNumber->setText(QString::number(card.number()));
        ui->lineEditPower->setText(QString::number(card.power()));
    }
}

void MainWindow::on_lineEditNumber_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    setCurSelectCardWithFilter();
}

void MainWindow::on_lineEditPower_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    setCurSelectCardWithFilter();
}

void MainWindow::on_pushButtonAddFeature_clicked()
{
    UserListUpdateData data(
        UserListType::FEATURE,
        UserListOperation::APPEND,
        m_curSelectCard
    );
    m_modelsManager->updateUserList(data);
}

void MainWindow::on_pushButtonAddNoFeature_clicked()
{
    UserListUpdateData data(
        UserListType::NOFEATURE,
        UserListOperation::APPEND,
        m_curSelectCard
    );
    m_modelsManager->updateUserList(data);
}

void MainWindow::on_pushButtonAddExcept_clicked()
{
    UserListUpdateData data(
        UserListType::EXCEPT,
        UserListOperation::APPEND,
        m_curSelectCard
    );
    m_modelsManager->updateUserList(data);
}

void MainWindow::on_pushButtonReset_clicked()
{
    m_modelsManager->reset();
}

void MainWindow::on_pushButtonRefresh_clicked()
{
    on_actionRefresh_triggered();
}
