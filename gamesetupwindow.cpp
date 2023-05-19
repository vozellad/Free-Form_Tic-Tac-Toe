#include "gamesetupwindow.h"
#include "ui_gamesetupwindow.h"
#include "startscreenwindow.h"
#include <QSpacerItem>

// TODO: keep each side in horizontalLayout_body equal width

GameSetupWindow::GameSetupWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameSetupWindow)
{
    ui->setupUi(this);

    players = ui->gridLayout_players;
    playerAmt = ui->label_playerAmtDisplay;

    // add second player (because UI doesn't add them in order)
    players->addWidget(new QLineEdit("Player 2"));
    players->addWidget(new QLabel("O"));
    QToolButton* b = new QToolButton();
    b->setText("...");
    players->addWidget(b);
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

    // readjust grid size
    // add temp item
    QLabel* temp = new QLabel();
    temp->setMaximumSize(0, 0);
    players->addWidget(temp);
    // delete temp item
    deleteLastGridItem(players);

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

void GameSetupWindow::deleteLastGridItem(QLayout* layout)
{
    QLayoutItem* lastItem = layout->takeAt(layout->count() - 1);
    delete lastItem->widget();
    delete lastItem;
}
