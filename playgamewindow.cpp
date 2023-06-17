#include "playgamewindow.h"
#include "ui_playgamewindow.h"

// TODO: board stuff might all need to be contained in a class

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
    table->setSpacing(42);

    addBoards();  // Add boards to table

    playersUI = ui->gridLayout_players;

    addPlayers();
}

PlayGameWindow::~PlayGameWindow()
{
    delete ui;
}

// Go to previous window
void PlayGameWindow::on_pushButton_back_clicked()
{
    GameSetupWindow *w = new GameSetupWindow(this);
    w->show();

    this->hide();
}

void PlayGameWindow::addBoards()
{
    // addLayout() requires position values
    int row = 0, col = 0;

    const int tableWidth = ((int)sqrt(boards.count() + 1));

    for (int i = 0; i < boards.count(); i++) {
        table->addLayout(boards[i].getLayout(), row, col);

        // Increment position values
        col = (col + 1) % tableWidth;
        if (col == 0)  row++;
    }
}

void PlayGameWindow::addPlayers()
{
    //playersUI->setRowMinimumHeight(2, 0);
    //playersUI->setRowStretch(2, 0);

    playersUI->addWidget(new QLabel(players[0].name), 0, 0);
    playersUI->addWidget(new SymbolLabel(players[0].symbol), 0, 1);
    playersUI->addWidget(new QLabel("0"), 0, 2);
    for (int i = 1; i < players.count(); i++) {
        playersUI->addWidget(new QLabel(players[i].name));
        playersUI->addWidget(new SymbolLabel(players[i].symbol));
        playersUI->addWidget(new QLabel("0"));
    }
}
