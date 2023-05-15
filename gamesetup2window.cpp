#include "gamesetup2window.h"
#include "ui_gamesetup2window.h"

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
