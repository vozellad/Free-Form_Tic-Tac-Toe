#include "gamesetupwindow.h"
#include "ui_gamesetupwindow.h"
#include "startscreenwindow.h"
#include "gamesetup2window.h"

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

// Go to previous page
void GameSetupWindow::on_pushButton_back_clicked()
{
    StartScreenWindow *w = new StartScreenWindow(this);
    w->show();

    this->hide();
}

// Go to next page
void GameSetupWindow::on_pushButton_next_clicked()
{
    GameSetup2Window *w = new GameSetup2Window(this);
    w->show();

    this->hide();
}
