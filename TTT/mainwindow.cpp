#include "mainwindow.h"
#include "ui_mainwindow.h"

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

int MainWindow::changeAmt(int currAmt,
                          int newAmt,
                          void (MainWindow::*add)(),
                          void (MainWindow::*remove)())
{
    int difference = newAmt - currAmt;

    // Function pointer.
    // Used to limit to 1 for loop
    // that calls to add or remove depending on difference.
    void (MainWindow::*addOrRemove)();

    if (difference < 0)
    {
        addOrRemove = remove;
        difference = -difference;
    }
    else  // if difference == 0, for loop doesn't run.
    {
        addOrRemove = add;
    }

    for (int i = 0; i < difference; i++)
    {
        (this->*addOrRemove)();
    }

    // Update num of boards.
    currAmt = newAmt;
    return currAmt;
}

void MainWindow::addPlayer()
{
    // Get layout that holds layouts that hold board settings.
    QVBoxLayout* layout =
        qobject_cast<QVBoxLayout*>(ui->verticalLayout_boardsSettings);

    // Make layout that holds board settings.
    QGridLayout* innerLayout =
        qobject_cast<QGridLayout*>(ui->verticalLayout_boardsSettings);

}

void MainWindow::removePlayer()
{

}

//  Handles user incrementing "Number of boards" spin button.
void MainWindow::addBoard()
{
    // Get layout that holds layouts that hold board settings.
    QVBoxLayout* layout =
        qobject_cast<QVBoxLayout*>(ui->verticalLayout_boardsSettings);

    // Make layout that holds board settings.
    QGridLayout* innerLayout =
        qobject_cast<QGridLayout*>(ui->verticalLayout_boardsSettings);

}

//  Handles user decrementing "Number of boards" spin button.
void MainWindow::removeBoard()
{

}

void MainWindow::on_pushButton_start_clicked()
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

    currNumOfBoards = changeAmt(currNumOfBoards,
                                newNumOfBoards,
                                &MainWindow::addBoard,
                                &MainWindow::removeBoard);
}

void MainWindow::on_spinBox_numberOfPlayers_editingFinished()
{
    static int currNumOfPlayers = 1;
    int newNumberOfPlayers = ui->spinBox_numberOfPlayers->value();

    currNumOfPlayers = changeAmt(currNumOfPlayers,
                        newNumberOfPlayers,
                        &MainWindow::addPlayer,
                        &MainWindow::removePlayer);
}

