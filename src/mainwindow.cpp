#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"

// #define _TEST
#ifdef _TEST
#include "../test/programtest.h"
#endif

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_modelsManager(nullptr)
{
    ui->setupUi(this);

    m_modelsManager = UserListModelsManager::getInstance();
    qDebug() << "modelsManager address: " << (void*)m_modelsManager;

    ui->listViewFeature->setModel(m_modelsManager->getUserListModel(UserListType::FEATURE));
    ui->listViewNoFeature->setModel(m_modelsManager->getUserListModel(UserListType::NOFEATURE));
    ui->listViewExcept->setModel(m_modelsManager->getUserListModel(UserListType::EXCEPT));
    ui->listViewPossible->setModel(m_modelsManager->getUserListModel(UserListType::POSSIBLE));
    
    m_modelsManager->reset();

#ifdef _TEST
    programTest test;
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}
