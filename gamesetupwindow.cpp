#include "gamesetupwindow.h"
#include "ui_gamesetupwindow.h"
#include "startscreenwindow.h"
#include <QSpacerItem>
#include <QLineEdit>

// TODO: keep each side in horizontalLayout_body equal width

GameSetupWindow::GameSetupWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameSetupWindow)
{
    ui->setupUi(this);

    players = ui->gridLayout_players;
    playerAmt = ui->label_playerAmtDisplay;

    //addInitialPlayers();
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

// TODO: explain dealing with spacer here
void GameSetupWindow::on_toolButton_addPlayer_clicked()
{
    // increment player amount
    setPlayerAmt(getPlayerAmt() + 1);

    // add player row
    QString newNameStr = tr("Player %1").arg(getPlayerAmt());
    players->addWidget(new QLineEdit(newNameStr));  // add name
    players->addWidget(new QLabel());  // add symbol
    QToolButton* b = new QToolButton();
    b->setText("...");
    players->addWidget(b);  // add symbol options

    setButtonStates();
}

void GameSetupWindow::on_toolButton_removePlayer_clicked()
{
    // decrement player amount
    setPlayerAmt(getPlayerAmt() - 1);

    // remove player row
    for (int i = 0; i < 3; i++)
        deleteLastGridItem(players);

    //reAdjustGridSize(players);  // TODO: delete line later if don't use

    setButtonStates();
}

int GameSetupWindow::getPlayerAmt()
{
    return playerAmt->text().toInt();
}

void GameSetupWindow::setPlayerAmt(int newPlayerAmt)
{
    playerAmt->setText(QString::number(newPlayerAmt));
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

// because UI doesn't add them in order
void GameSetupWindow::addInitialPlayers()
{
    /*
    // add first player
    players->addWidget(new QLineEdit("Player 1"), 0, 0);
    players->addWidget(new QLabel("X"), 0, 1);
    QToolButton* b1 = new QToolButton();
    b1->setText("...");
    players->addWidget(b1, 0, 2);
    */

    // add second player
    players->addWidget(new QLineEdit("Player 2"));
    players->addWidget(new QLabel("O"));
    QToolButton* b2 = new QToolButton();
    b2->setText("...");
    players->addWidget(b2);
}

void GameSetupWindow::reAdjustGridSize(QGridLayout *l)  // TODO: delete later if don't use
{
    // add temp item
    QLabel* temp = new QLabel();
    temp->setMaximumSize(0, 0);
    l->addWidget(temp);
    // delete temp item
    deleteLastGridItem(l);
}
