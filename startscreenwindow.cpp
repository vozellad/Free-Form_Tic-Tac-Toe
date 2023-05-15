#include "startscreenwindow.h"
#include "ui_startscreenwindow.h"
#include "gamesetupwindow.h"

StartScreenWindow::StartScreenWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartScreenWindow)
{
    ui->setupUi(this);
}

StartScreenWindow::~StartScreenWindow()
{
    delete ui;
}

// Hide current window. Go to GameSetupWindow.
void StartScreenWindow::on_pushButton_start_clicked()
{
    GameSetupWindow *w = new GameSetupWindow(this);
    w->show();

    this->hide();

}

