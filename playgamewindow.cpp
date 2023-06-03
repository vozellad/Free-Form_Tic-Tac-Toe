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

    // Add boards to table
    int i = 0, j = 0;  // addLayout() requires position args
    for (Board b : boards) {
        table->addLayout(createBoard(b), i, j);
        j = (j + 1) % 3;
        if (j == 0) i++;
    }
    //table->addLayout(createBoard(boards[0]), 0, 0);
}

PlayGameWindow::~PlayGameWindow()
{
    delete ui;
}

QGridLayout* PlayGameWindow::createBoard(const Board& board)
{
    QGridLayout* boardLayout = new QGridLayout();

    // Set grid column width
    boardLayout->setColumnMinimumWidth(board.sizeX-1, 0);
    boardLayout->setColumnStretch(board.sizeX-1, 0);

    // Add spaces for symbols
    for (int i = 0; i < board.sizeX * board.sizeY; i++) {
        ClickableLabel* temp = new ClickableLabel();
        temp->setText("temp");
        boardLayout->addWidget(temp);
    }

    return boardLayout;
}
