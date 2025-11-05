#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "packmanagerdialog.h"
#include "preferencesdialog.h"
#include "rulesettingsdialog.h"
#include "cardmanager.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_isRunning(true)
    , m_cardManager(new CardManager(this))
    , m_featureListModel(nullptr)
    , m_noFeatureListModel(nullptr)
    , m_exceptListModel(nullptr)
    , m_possibleListModel(nullptr)
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
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

