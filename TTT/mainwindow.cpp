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
    // TODO: allow the option to either use character or image for symbol
    // TODO: allow customizeable name

    // Get vertical layout of players.
    QVBoxLayout* layout = ui->verticalLayout_playerSymbols;

    int count = layout->count();

    // Adds a new row representing added player.
    QHBoxLayout* newPlayer = new QHBoxLayout();

    // Create elements for new row.

    QLabel* name =
            new QLabel(tr("Player %1 symbol: ").arg(layout->count() + 1));

    // Suggest symbol for new player.
    char symbol = ('a' - 2 + count);
    if (count == 1)
        symbol = 'x';
    else if (symbol == 2)
        symbol = 'o';
    // TODO: maybe make player (dictionary or class) that has these

    QLineEdit* symbolBox = new QLineEdit(tr("%1").arg(symbol));
    symbolBox->setFixedWidth(42);  // TODO: make dynamic

    // Add new elements to new row.
    newPlayer->addWidget(name);
    newPlayer->addWidget(symbolBox);
    newPlayer->addSpacing(60);

    layout->addLayout(newPlayer);
}

void MainWindow::removePlayer()
{
    // Get vertical layout of players.
    QVBoxLayout* layout = ui->verticalLayout_playerSymbols;

    QLayoutItem* lastPlayer = layout->itemAt(layout->count() - 1);

    removeLayout(lastPlayer);
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

void MainWindow::removeLayout(QLayoutItem* layout)
{
    if (layout->layout() != NULL)
    {
        QLayoutItem* item;
        while ((item = layout->layout()->takeAt(0)) != NULL)
        {
            delete item->widget();
            delete item;
        }
        delete layout->layout();
    }
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


void MainWindow::on_spinBox_numberOfPlayers_valueChanged(int newNumOfPlayers)
{
    static int currNumOfPlayers = 2;

    currNumOfPlayers = changeAmt(currNumOfPlayers,
                                 newNumOfPlayers,
                                 &MainWindow::addPlayer,
                                 &MainWindow::removePlayer);
}

