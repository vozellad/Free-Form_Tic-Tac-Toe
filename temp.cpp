#include "temp.h"
#include "ui_mainwindow.h"

Temp::Temp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Temp)
{
    ui->setupUi(this);

    // Set default style to "Fusion", the default style on Windows.
    QApplication::setStyle(QStyleFactory::create("Fusion"));
}

Temp::~Temp()
{
    delete ui;
}

// Mutators

int Temp::changeAmt(int currAmt,
                          int newAmt,
                          void (Temp::*add)(),
                          void (Temp::*remove)())
{
    int difference = newAmt - currAmt;

    // Function pointer.
    // Used to limit to 1 for loop
    // that calls to add or remove depending on difference.
    void (Temp::*addOrRemove)();

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

void Temp::addPlayer()
{
    // TODO: allow the option to either use character or image for symbol
    // TODO: allow customizeable name

    // Get vertical layout of players.
    QVBoxLayout* layout = ui->verticalLayout_playerSymbols;

    int count = layout->count();

    // Adds a new row representing added player.
    QHBoxLayout* newPlayer = new QHBoxLayout();

    // Create elements for new row.

    QLineEdit* nameBox =
            new QLineEdit(tr("Player %1: ").arg(layout->count() + 1));

    // Suggest symbol for new player.
    char symbol = ('a' - 2 + count);
    if (count == 0)
        symbol = 'x';
    else if (count == 1)
        symbol = 'o';
    else if (count > 15)
    {
        symbol += 1;
        if (count > 23)
            symbol += 1;
    }
    // TODO: maybe make player (dictionary or class) that has these
    // TODO: honestly, this is sloppy, but fix depends on how projects turns out

    QLineEdit* symbolBox = new QLineEdit(tr("%1").arg(symbol));
    symbolBox->setFixedWidth(ui->lineEdit_player1Symbol->width());

    int horizontalSpacer = ui->horizontalSpacer_player1->width();

    // Add new elements to new row.
    newPlayer->addWidget(nameBox);
    newPlayer->addWidget(symbolBox);
    newPlayer->addSpacing(horizontalSpacer);

    layout->addLayout(newPlayer);
}

void Temp::removePlayer()
{
    // Get vertical layout of players.
    QVBoxLayout* layout = ui->verticalLayout_playerSymbols;

    // Get last player.
    QLayoutItem* lastPlayer = layout->itemAt(layout->count() - 1);

    removeLayout(lastPlayer);

    // Adding an element dynamically increases the size of the window.
    // This does not happen when removing an element,
    // so it must be done manually.
    this->window()->resize(QSize(ui->centralwidget->width(), 1));
}

//  Handles user incrementing "Number of boards" spin button.
void Temp::addBoard()
{

}

//  Handles user decrementing "Number of boards" spin button.
void Temp::removeBoard()
{

}

void Temp::removeLayout(QLayoutItem* layout)
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

void Temp::on_pushButton_start_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Temp::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Temp::on_spinBox_numberOfBoards_editingFinished()
{
    static int currNumOfBoards = 1;
    int newNumOfBoards = ui->spinBox_numberOfBoards->value();

    currNumOfBoards = changeAmt(currNumOfBoards,
                                newNumOfBoards,
                                &Temp::addBoard,
                                &Temp::removeBoard);
}

void Temp::on_spinBox_numberOfPlayers_valueChanged(int newNumOfPlayers)
{
    static int currNumOfPlayers = 2;

    currNumOfPlayers = changeAmt(currNumOfPlayers,
                                 newNumOfPlayers,
                                 &Temp::addPlayer,
                                 &Temp::removePlayer);
}

