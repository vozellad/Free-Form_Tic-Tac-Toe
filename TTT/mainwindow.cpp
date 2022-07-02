#include "mainwindow.h"
#include "ui_mainwindow.h"

// TEMP
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set default style to "Fusion", the default style on Windows.
    QApplication::setStyle(QStyleFactory::create("Fusion"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Mutators

//  Handles user incrementing "Number of boards" spin button (Free Form).
void MainWindow::addBoard()
{

}

//  Handles user decrementing "Number of boards" spin button (Free Form).
void MainWindow::removeBoard()
{

}

void MainWindow::on_pushButton_freeForm_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_spinBox_numberOfBoards_editingFinished()
{
    static int currNumOfBoards = 1;
    int newNumOfBoards = ui->spinBox_numberOfBoards->value();

    int difference = newNumOfBoards - currNumOfBoards;

    // Function pointer.
    void (MainWindow::*modifyNumOfBoards)();

    if (difference < 0)
    {
        modifyNumOfBoards = &MainWindow::removeBoard;
        difference = -difference;
    }
    else
    {
        modifyNumOfBoards = &MainWindow::addBoard;
    }

    for (int i = 0; i < difference; i++)
    {
        (this->*modifyNumOfBoards)();
    }

    // Update num of boards.
    currNumOfBoards = newNumOfBoards;
}

