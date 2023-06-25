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
    // TODO: each board on table needs a label on top of it to show winCondition or other info when relevant (might have to do in board class)

    for (BoardSettings& b : boardsSettings)
        boards.push_back(Board(b.sizeX, b.sizeY, b.winCond, this));

    addBoards();  // Add boards to table

    playersUI = ui->gridLayout_players;
    playersUI->setSpacing(0);

    addPlayers();
    highlightPlayer();
}

PlayGameWindow::~PlayGameWindow()
{
    delete ui;
}

QVariant PlayGameWindow::getCurrPlayerSymbol()
{
    return players[currPlayerRow].symbol;
}

void PlayGameWindow::addCurrPlayerScore(const int scoreAdd)
{
    // Get player's score label grid position
    int i = currPlayerRow * 3 + 2;

    QLabel* score = getPlayerUILabel(i);

    score->setText(QString::number(score->text().toInt() + scoreAdd));
}

void PlayGameWindow::iteratePlayer()
{
    currPlayerRow = (currPlayerRow + 1) % players.count();
}

void PlayGameWindow::highlightPlayer()
{
    highlightPlayer(currPlayerRow);
}

void PlayGameWindow::highlightPlayer(int playerRow)
{
    // Get player's name label grid position
    playerRow *= 3;

    clearPlayerHighlight();

    QString borderStyle = ": 1px solid red;";

    QString bottomTopBorder = "border-top" + borderStyle +
                              "border-bottom" + borderStyle;

    playersUI->itemAt(playerRow)->widget()->setStyleSheet(
                bottomTopBorder + "border-left" + borderStyle);

    playersUI->itemAt(playerRow + 1)->widget()->setStyleSheet(bottomTopBorder);

    playersUI->itemAt(playerRow + 2)->widget()->setStyleSheet(
                bottomTopBorder + "border-right" + borderStyle);
}

void PlayGameWindow::clearPlayerHighlight()
{
    for (int i = 0; i < playersUI->count(); i++)
        playersUI->itemAt(i)->widget()->setStyleSheet("");
}

bool PlayGameWindow::allBoardsDone() const
{
    for (int i = 0; i < boards.count(); i++)
        if (boards[i].getLayout()->isEnabled())
            return false;

    return true;
}

int PlayGameWindow::getWinnerRow()
{
    int maxScore = -1, playerOfMax = -1;
    bool draw = false;

    for (int i = 2; i < playersUI->count(); i += 3) {
        const int currScore = getPlayerUILabel(i)->text().toInt();

        if (maxScore < currScore) {
            maxScore = currScore;
            playerOfMax = i - 2;
            draw = false;
        } else if (maxScore == currScore) {
            draw = true;
        }
    }

    return draw ? -1 : playerOfMax / 3;
}

void PlayGameWindow::displayWinner(int winnerIndex)
{
    winnerIndex *= 3;

    QString name = getPlayerUILabel(winnerIndex)->text();
    QString score = getPlayerUILabel(winnerIndex + 2)->text();
    QString s = "Winner is " + name + " with " + score + " win";
    if (1 < score.toInt())  s += "s";
    ui->label_winner->setText(s);
}

void PlayGameWindow::callDraw()
{
    ui->label_winner->setText("It's a draw");
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
    setGridWidth(playersUI, 3);

    const int margin = 5;

    // Add players info
    for (int i = 0; i < players.count(); i++) {
        QLabel* name = new QLabel(players[i].name);
        name->setMargin(margin);
        playersUI->addWidget(name);

        SymbolLabel* symbol = new SymbolLabel();
        symbol->setAlignment(Qt::AlignHCenter);
        symbol->setFixedHeight(name->sizeHint().height());
        symbol->setSymbol(players[i].symbol);
        // TODO: why is padding weird?
        playersUI->addWidget(symbol);

        QLabel* score = new QLabel("0");
        score->setAlignment(Qt::AlignRight);
        score->setMargin(margin);
        playersUI->addWidget(score);
    }
}

QLabel* PlayGameWindow::getPlayerUILabel(const int i)
{
    return qobject_cast<QLabel*>(playersUI->itemAt(i)->widget());
}
