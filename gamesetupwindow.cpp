#include "gamesetupwindow.h"
#include "ui_gamesetupwindow.h"
#include "startscreenwindow.h"
#include <QSpacerItem>

GameSetupWindow::GameSetupWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameSetupWindow)
{
    ui->setupUi(this);

    players = ui->gridLayout_players;
    playerAmt = ui->label_playerAmtDisplay;
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
void GameSetupWindow::on_toolButton_addPlayer_clicked()  // TODO: maybe just get the position in addPlayer instead
{
    // add player row
    players->addWidget(new QLineEdit("temp txt")); // TODO: add player num in name label
    players->addWidget(new QLabel("..."));
    players->addWidget(new QToolButton());  // TODO: add "..."

    // increment player amount
    setPlayerAmt(getPlayerAmt() + 1);

    setButtonStates();
}

void GameSetupWindow::on_toolButton_removePlayer_clicked()
{
    // remove player row
    for (int i = 0; i < 3; i++) {
        auto lastItem = players->takeAt(players->count() - 1);
        delete lastItem->widget();
        delete lastItem;
    }

    // decrement player amount
    setPlayerAmt(getPlayerAmt() - 1);

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
