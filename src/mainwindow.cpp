#include "mainwindow.h"
#include "ui_mainwindow.h"

#define _TEST
#ifdef _TEST
#include "../test/programtest.h"
#endif

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

#ifdef _TEST
    programTest test;
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}
