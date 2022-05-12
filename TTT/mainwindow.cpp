#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// MUTATORS

// Set unresizeable MainWindow size.
void MainWindow::setMinMaxSize(int min, int max)
{
    setMinimumSize(min, max);
    setMaximumSize(min, max);
}

void MainWindow::on_pushButton_freeForm_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    setMinMaxSize(341, 518);
}

