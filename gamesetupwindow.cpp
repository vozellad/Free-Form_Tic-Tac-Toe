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

void GameSetupWindow::on_pushButton_startGame_clicked()
{

}

void GameSetupWindow::on_spinBox_playerAmt_editingFinished()
{
    static int playerAmt = 2;
    int newPlayerAmt = ui->spinBox_playerAmt->value();
    removeLastInLayout(players);

    if (newPlayerAmt < playerAmt)
        for (int i = 0; i < playerAmt - newPlayerAmt; i++)
            removePlayer();
    else
        for (int i = 0; i < newPlayerAmt - playerAmt; i++)
            addPlayer();

    players->addItem(new QSpacerItem(5, 5), 1, 1);
    playerAmt = newPlayerAmt;
}


void GameSetupWindow::addPlayer()
{
    players->addWidget(new QLineEdit("temp txt")); // TODO: add player num in name label
    players->addWidget(new QLabel("..."));
    players->addWidget(new QToolButton());  // TODO: add "..."
}

void GameSetupWindow::removePlayer()
{
    for (int i = 0; i < 3; i++)
    {
        removeLastInLayout(players);
    }

    int row = players->count() / players->columnCount();
    if (row % 3 == 0) {
        players->setRowMinimumHeight(row, 0);
        players->setRowStretch(row, 0);
    }
}

void GameSetupWindow::removeLastInLayout(QLayout* layout)
{
    auto lastItem = layout->takeAt(layout->count() - 1);
    delete lastItem->widget();
    delete lastItem;
}
