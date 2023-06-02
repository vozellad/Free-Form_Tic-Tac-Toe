#include "playgamewindow.h"
#include "ui_playgamewindow.h"

PlayGameWindow::PlayGameWindow(const QVector<Player>& players,
                               const QVector<Board>& boards,
                               QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayGameWindow),
    players(players),
    boards(boards)
{
    ui->setupUi(this);

    table = ui->gridLayout_table;

    // Get grid column width based on boards amount
    int boardWidth = 1;
    while (boardWidth * boardWidth <= boards.count())
        boardWidth++;

    // Set grid column width
    table->setColumnMinimumWidth(boardWidth, 0);
    table->setColumnStretch(boardWidth, 0);

    // TODO: used ui lines to make grid lines

}

PlayGameWindow::~PlayGameWindow()
{
    delete ui;
}
