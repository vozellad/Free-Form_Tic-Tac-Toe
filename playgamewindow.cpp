#include "playgamewindow.h"
#include "ui_playgamewindow.h"

PlayGameWindow::PlayGameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayGameWindow)
{
    ui->setupUi(this);
}

PlayGameWindow::~PlayGameWindow()
{
    delete ui;
}
