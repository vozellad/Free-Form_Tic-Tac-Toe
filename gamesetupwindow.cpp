#include "gamesetupwindow.h"
#include "ui_gamesetupwindow.h"
#include "startscreenwindow.h"

GameSetupWindow::GameSetupWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameSetupWindow)
{
    ui->setupUi(this);
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

void GameSetupWindow::on_spinBox_playerAmt_valueChanged(int newPlayerAmt)
{
    static int playerAmt = ui->spinBox_playerAmt->value();
    // remove spacer

    if (newPlayerAmt < playerAmt)
        for (int i = 0; i < playerAmt - newPlayerAmt; i++)
            removePlayer();
    else
        for (int i = 0; i < newPlayerAmt - playerAmt; i++)
            addPlayer();

    // add spacer
    playerAmt = newPlayerAmt;
}

void GameSetupWindow::addPlayer()
{
    QGridLayout* playerSetup = ui->gridLayout_playerSetup;

    playerSetup->addWidget(new QLineEdit("temp txt"));
    playerSetup->addWidget(new QLabel("..."));
    playerSetup->addWidget(new QToolButton());
}

void GameSetupWindow::removePlayer()
{
    QGridLayout* playerSetup = ui->gridLayout_playerSetup;

    for (int i = 0; i < 3; i++)
    {
        auto lastItem = playerSetup->takeAt(playerSetup->count() - 1);
        delete lastItem->widget();
        delete lastItem;
    }

    int row = int(playerSetup->count() / 3);
    if (row % 3 == 0) {
        playerSetup->setRowMinimumHeight(row, 0);
        playerSetup->setRowStretch(row, 0);
    }
}
