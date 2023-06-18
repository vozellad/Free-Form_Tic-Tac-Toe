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
    table->setSpacing(42);

    addBoards();  // Add boards to table

    playersUI = ui->gridLayout_players;
    playersUI->setSpacing(0);

    addPlayers();
    highlightPlayer();

    // TODO: // setLambdaBeforeClick  // setLambdaAfterClick
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
    // Set column width
    playersUI->setColumnMinimumWidth(2, 0);
    playersUI->setColumnStretch(2, 0);

    const int margin = 5;

    // Add players info
    for (int i = 0; i < players.count(); i++) {
        QLabel* name = new QLabel(players[i].name);
        name->setMargin(margin);
        playersUI->addWidget(name);

        SymbolLabel* symbol = new SymbolLabel(players[i].symbol);
        symbol->setAlignment(Qt::AlignHCenter);
        symbol->setMargin(margin);
        playersUI->addWidget(symbol);

        QLabel* wins = new QLabel("0");
        wins->setAlignment(Qt::AlignRight);
        wins->setMargin(margin);
        playersUI->addWidget(wins);
    }
}

void PlayGameWindow::highlightPlayer()
{
    // Clear highlights
    for (int i = 0; i < playersUI->count(); i++)
        playersUI->itemAt(i)->widget()->setStyleSheet("");

    // Get player's name label grid position
    int i = currPlayerIndex * 3;


    // Highlight current player row

    playersUI->itemAt(i + 0)->widget()->setStyleSheet(
                "border-top: 1px solid red;"
                "border-bottom: 1px solid red;"
                "border-left: 1px solid red;");

    playersUI->itemAt(i + 1)->widget()->setStyleSheet(
                "border-top: 1px solid red;"
                "border-bottom: 1px solid red;");

    playersUI->itemAt(i + 2)->widget()->setStyleSheet(
                "border-top: 1px solid red;"
                "border-bottom: 1px solid red;"
                "border-right: 1px solid red;");
}
