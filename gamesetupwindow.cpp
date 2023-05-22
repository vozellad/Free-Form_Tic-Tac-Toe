#include "gamesetupwindow.h"
#include "ui_gamesetupwindow.h"
#include "startscreenwindow.h"
#include "playersymboldialog.h"

// TODO: split file into gamesetup, playersetup, and boardsetup

GameSetupWindow::GameSetupWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameSetupWindow)
{
    ui->setupUi(this);

    // hides element that helps center the title
    ui->pushButton_backBalancer->setVisible(false);

    // make - + buttons square
    QToolButton* buttonArray[4] = {
        ui->toolButton_addPlayer,
        ui->toolButton_removePlayer,
        ui->toolButton_addBoard,
        ui->toolButton_removeBoard
    };
    for (QToolButton* b : buttonArray)
        b->setMinimumWidth(b->height());

    players = ui->gridLayout_players;
    addInitialPlayers();
}

GameSetupWindow::~GameSetupWindow()
{
    delete ui;
}

// Go to previous window
void GameSetupWindow::on_pushButton_back_clicked()
{
    StartScreenWindow *w = new StartScreenWindow(this);
    w->show();

    this->hide();
}

// Go to next window
void GameSetupWindow::on_pushButton_startGame_clicked()
{

}

void GameSetupWindow::on_toolButton_addPlayer_clicked()
{
    // increment player amount
    setPlayerAmt(getPlayerAmt() + 1);

    // add name
    QString newNameStr = tr("Player %1").arg(getPlayerAmt());
    players->addWidget(new QLineEdit(newNameStr));

    // add symbol
    ClickableLabel* newSymbol = new ClickableLabel();
    newSymbol->setText("...");
    on_playerSymbol_clicked(newSymbol, newNameStr);
    players->addWidget(newSymbol);

    setButtonStates();
}

void GameSetupWindow::on_toolButton_removePlayer_clicked()
{
    // decrement player amount
    setPlayerAmt(getPlayerAmt() - 1);

    // remove player row
    for (int i = 0; i < players->columnCount(); i++)
        deleteLastGridItem(players);  // TODO: this might not need to be a function.

    reAdjustGridSize(players);

    setButtonStates();
}

void GameSetupWindow::on_playerSymbol_clicked(ClickableLabel* symbol,
                                                 QString name)
{
    QObject::connect(symbol, &ClickableLabel::clicked, this,
        [this, name, symbol]()
    {
        PlayerSymbolDialog *w = new PlayerSymbolDialog(symbol, name, this);
        w->show();
    });
}

int GameSetupWindow::getPlayerAmt()
{
    return ui->label_playerAmtDisplay->text().toInt();
}

void GameSetupWindow::setPlayerAmt(int newPlayerAmt)
{
    ui->label_playerAmtDisplay->setText(QString::number(newPlayerAmt));
}

void GameSetupWindow::setButtonStates() // TODO: find better function name
{
    ui->toolButton_addPlayer->setEnabled(true);
    ui->toolButton_removePlayer->setEnabled(true);

    if (getPlayerAmt() <= 1)
        ui->toolButton_removePlayer->setEnabled(false);
    else if (99 <= getPlayerAmt())
        ui->toolButton_addPlayer->setEnabled(false);
}

void GameSetupWindow::deleteLastGridItem(QGridLayout* l)
{
    QLayoutItem* lastItem = l->takeAt(l->count() - 1);
    delete lastItem->widget();
    delete lastItem;
}

void GameSetupWindow::reAdjustGridSize(QGridLayout *l)
{
    int row = l->count() / l->columnCount();
    l->setRowMinimumHeight(row, 0);
    l->setRowStretch(row, 0);
}

void GameSetupWindow::addInitialPlayers()
{
    QString newNameStr = "Player 1";
    players->addWidget(new QLineEdit(newNameStr), 0, 0);

    ClickableLabel* newSymbol = new ClickableLabel();
    newSymbol->setText("X");
    on_playerSymbol_clicked(newSymbol, newNameStr);
    players->addWidget(newSymbol, 0, 1);

    newNameStr = "Player 2";
    players->addWidget(new QLineEdit(newNameStr), 1, 0);

    newSymbol = new ClickableLabel();
    newSymbol->setText("O");
    on_playerSymbol_clicked(newSymbol, newNameStr);
    players->addWidget(newSymbol, 1, 1);
}

void GameSetupWindow::on_toolButton_addBoard_clicked()
{

}


void GameSetupWindow::on_toolButton_removeBoard_clicked()
{

}

int GameSetupWindow::getBoardAmt()
{
    return ui->label_boardAmtDisplay->text().toInt();
}

void GameSetupWindow::setBoardAmt(int newBoardAmt)
{
    ui->label_boardAmtDisplay->setText(QString::number(newBoardAmt));
}

QGridLayout* GameSetupWindow::getGridCopy(QGridLayout* grid)
{
    // Create a new grid layout and assign it as the layout for the target widget
    QGridLayout* newGrid = new QGridLayout(this);

    // Iterate through the rows and columns of the source grid layout
    for (int row = 0; row < grid->rowCount(); row++) {
        for (int col = 0; col < grid->columnCount(); col++) {
            QLayoutItem* item = grid->itemAtPosition(row, col);
            if (!item) continue;
            QWidget* widget = item->widget();
            if (!widget) continue;
            QWidget* clonedWidget = widget->clone();
            newGrid->addWidget(clonedWidget, row, col);
        }
    }

    return newGrid;
}
