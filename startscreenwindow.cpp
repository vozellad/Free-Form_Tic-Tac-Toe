#include "startscreenwindow.h"
#include "ui_startscreenwindow.h"

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

// Go to next window
void StartScreenWindow::on_pushButton_start_clicked()
{
    GameSetupWindow *w = new GameSetupWindow(this);
    w->show();

    this->hide();
}
