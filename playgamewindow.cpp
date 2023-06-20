#include "playgamewindow.h"
#include "ui_playgamewindow.h"

PlayGameWindow::PlayGameWindow(const QVector<Player>& players,
                               QVector<BoardSettings>& boardsSettings,
                               QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayGameWindow),
    players(players)
{
    ui->setupUi(this);

    table = ui->gridLayout_table;
    table->setSpacing(42);

    for (BoardSettings b : boardsSettings)
        boards.push_back(Board(b.sizeX, b.sizeY, b.winCond, this));

    addBoards();  // Add boards to table

    playersUI = ui->gridLayout_players;
    playersUI->setSpacing(0);

    addPlayers();
    highlightCurrPlayer();
}

PlayGameWindow::~PlayGameWindow()
{
    delete ui;
}

QVariant PlayGameWindow::getCurrPlayerSymbol()
{
    return players[0].symbol;
}

void PlayGameWindow::addCurrPlayerScore(const int scoreAdd)
{
    // Get player's score label grid position
    int i = currPlayerIndex * 3 + 2;

    QLabel* score = qobject_cast<QLabel*>(playersUI->itemAt(i)->widget());

    score->setText(QString::number(score->text().toInt() + scoreAdd));
}

void PlayGameWindow::iteratePlayer()
{
    currPlayerIndex = (currPlayerIndex + 1) % players.count();
}

void PlayGameWindow::highlightCurrPlayer()
{
    // Clear highlights
    for (int i = 0; i < playersUI->count(); i++)
        playersUI->itemAt(i)->widget()->setStyleSheet("");

    // Get player's name label grid position
    int i = currPlayerIndex * 3;


    // Highlight current player row

    // TODO: QStrings to reduce duplicate substrings

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

        QLabel* score = new QLabel("0");
        score->setAlignment(Qt::AlignRight);
        score->setMargin(margin);
        playersUI->addWidget(score);
    }
}
