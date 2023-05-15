#include "gamesetup2window.h"
#include "ui_gamesetup2window.h"
#include "gamesetupwindow.h"

GameSetup2Window::GameSetup2Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameSetup2Window)
{
    ui->setupUi(this);
}

GameSetup2Window::~GameSetup2Window()
{
    delete ui;
}

// Go to previous page
void GameSetup2Window::on_pushButton_back_clicked()
{
    GameSetupWindow *w = new GameSetupWindow(this);
    w->show();

    this->hide();
}

