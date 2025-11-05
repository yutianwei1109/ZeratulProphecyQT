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

    
}

MainWindow::~MainWindow()
{
    delete ui;
}

