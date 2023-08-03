/*  This window hosts the TicTacToe game.
 *  Based on user-defined board and player settings, it has a list of players
 *  on the left that it iterates through, a collection of boards on the right
 *  for the user to click on, and space above to display the end game results.
 */

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

    // Set up grid to host boards
    table = ui->gridLayout_table;
    table->setSpacing(42);

    // Create boards with board settings
    for (BoardSettings& b : boardsSettings)
        boards.push_back(Board(b.sizeX, b.sizeY, b.winCond, this));

    // Add boards to table
    addBoards();

    // Set up player list
    playersUI = ui->gridLayout_players;
    playersUI->setSpacing(0);

    addPlayers();
    highlightPlayer();
}

PlayGameWindow::~PlayGameWindow()
{
    delete ui;
}

// Current player is kept track by currPlayerRow
QVariant PlayGameWindow::getCurrPlayerSymbol()
{
    return players[currPlayerRow].symbol;
}

// Score is the amount of wins on all boards
void PlayGameWindow::addCurrPlayerScore(const int scoreAdd)
{
    // Get player's score label grid position
    int i = currPlayerRow * 3 + 2;

    QLabel* score = getPlayersUILabel(i);

    score->setText(QString::number(score->text().toInt() + scoreAdd));
}

void PlayGameWindow::iteratePlayer()
{
    currPlayerRow = (currPlayerRow + 1) % players.count();
}

// Puts a red box arounds a player in the player list
void PlayGameWindow::highlightPlayer()
{ highlightPlayer(currPlayerRow); }
void PlayGameWindow::highlightPlayer(int playerRow)
{
    // Get player's name label grid position
    playerRow *= 3;

    clearPlayerHighlight();

    QString style = ": 1px solid red;";

    playersUI->itemAt(playerRow + 0)->widget()->setStyleSheet(
                "border-top"    + style +
                "border-bottom" + style +
                "border-left"   + style);

    playersUI->itemAt(playerRow + 1)->widget()->setStyleSheet(
                "border-top"    + style +
                "border-bottom" + style);

    playersUI->itemAt(playerRow + 2)->widget()->setStyleSheet(
                "border-top"    + style +
                "border-bottom" + style +
                "border-right"  + style);
}

// Removes highlights from all players
void PlayGameWindow::clearPlayerHighlight()
{
    for (int i = 0; i < playersUI->count(); i++)
        playersUI->itemAt(i)->widget()->setStyleSheet("");
}

// Returns true if all boards are at a draw or have a win
bool PlayGameWindow::allBoardsDone() const
{
    for (int i = 0; i < boards.count(); i++)
        if (boards[i].isEnabled())
            return false;

    return true;
}

// Unless it's a draw, this returns the player with the highest score
int PlayGameWindow::getWinnerRow()
{
    int maxScore = -1, playerOfMax = -1;
    bool draw = false;

    for (int i = 2; i < playersUI->count(); i += 3) {
        const int currScore = getPlayersUILabel(i)->text().toInt();

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

// Displays winner on top of window
void PlayGameWindow::displayWinner(int winnerIndex)
{
    winnerIndex *= 3;  // Multiply by playersUI width

    QString name = getPlayersUILabel(winnerIndex)->text();
    QString score = getPlayersUILabel(winnerIndex + 2)->text();
    QString s = "Winner is " + name + " with " + score + " win";
    if (1 < score.toInt())  s += "s";
    ui->label_winner->setText(s);
}

// Call entire game as a draw on top of window
void PlayGameWindow::callDraw()
{
    ui->label_winner->setText("It's a draw");
}

// Ends game by either calling a draw or presenting the winner
void PlayGameWindow::finishGame()
{
    const int winnerRow = getWinnerRow();

    clearPlayerHighlight();

    // If no single highest score
    if (winnerRow == -1)
        callDraw();

    else {
        highlightPlayer(winnerRow);
        displayWinner(winnerRow);
    }
}

// Go to previous window
void PlayGameWindow::on_pushButton_back_clicked()
{
    GameSetupWindow *w = new GameSetupWindow(this);
    w->show();

    this->hide();
}

// Add boards to table
void PlayGameWindow::addBoards()
{
    // addLayout() requires position values
    int row = 0, col = 0;

    // Intent is to make table height and width closer to equal
    const int tableWidth = ((int)sqrt(boards.count() + 1));

    for (int i = 0; i < boards.count(); i++) {
        table->addLayout(boards[i].getLayout(), row, col);

        // Increment position values
        col = (col + 1) % tableWidth;
        if (col == 0)  row++;
    }
}

// Add players to playersUI
void PlayGameWindow::addPlayers()
{
    setGridWidth(playersUI, 3);

    // Add players info
    for (int i = 0; i < players.count(); i++) {
        // Add name
        QLabel* name = new QLabel(players[i].name);
        name->setMargin(5);
        playersUI->addWidget(name);

        // Add symbol
        SymbolLabel* symbol = new SymbolLabel(false);
        symbol->setAlignment(Qt::AlignHCenter);
        symbol->setFixedHeight(name->sizeHint().height() + 2);
        symbol->setSymbol(players[i].symbol);
        playersUI->addWidget(symbol);

        // Add score
        QLabel* score = new QLabel("0");
        score->setAlignment(Qt::AlignRight);
        score->setMargin(5);
        playersUI->addWidget(score);
    }
}

// Get label within playersUI grid
QLabel* PlayGameWindow::getPlayersUILabel(const int i)
{
    return qobject_cast<QLabel*>(playersUI->itemAt(i)->widget());
}
