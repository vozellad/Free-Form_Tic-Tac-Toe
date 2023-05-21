#include "gamesetupwindow.h"
#include "ui_gamesetupwindow.h"
#include "startscreenwindow.h"
#include "playersymboldialog.h"

GameSetupWindow::GameSetupWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameSetupWindow)
{
    ui->setupUi(this);

    players = ui->gridLayout_players;

    connectSymbolChangeClicked(ui->label_playerSymbol1,
                               ui->lineEdit_playerName1->text());
    connectSymbolChangeClicked(ui->label_playerSymbol2,
                               ui->lineEdit_playerName2->text());
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
    connectSymbolChangeClicked(newSymbol, newNameStr);
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

void GameSetupWindow::symbolChangeClicked(ClickableLabel* symbol, QString name)
{
    PlayerSymbolDialog *w = new PlayerSymbolDialog(symbol, name, this);
    w->show();
}

void GameSetupWindow::connectSymbolChangeClicked(ClickableLabel* symbol,
                                                 QString name)
{
    QObject::connect(symbol, &ClickableLabel::clicked, this,
        [this, name, symbol]() { symbolChangeClicked(symbol, name); });
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
