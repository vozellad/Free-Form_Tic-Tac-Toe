#include "gamesetupwindow.h"
#include "ui_gamesetupwindow.h"

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
