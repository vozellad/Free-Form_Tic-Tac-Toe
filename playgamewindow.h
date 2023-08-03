/*  This window hosts the TicTacToe game.
 *  Based on user-defined board and player settings, it has a list of players
 *  on the left that it iterates through, a collection of boards on the right
 *  for the user to click on, and space above to display the end game results.
 */

#ifndef PLAYGAMEWINDOW_H
#define PLAYGAMEWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <cmath>
#include "player.h"
#include "board.h"
#include "boardsettings.h"
#include "gamesetupwindow.h"

class Board;

namespace Ui {
class PlayGameWindow;
}

class PlayGameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayGameWindow(const QVector<Player>& players,
                            QVector<BoardSettings>& boardsSettings,
                            QWidget *parent = nullptr);
    ~PlayGameWindow();

    QVariant getCurrPlayerSymbol();

    void addCurrPlayerScore(const int scoreAdd);

    // Go to next player
    void iteratePlayer();

    // Puts a red box arounds a player in the player list
    void highlightPlayer();
    void highlightPlayer(int playerRow);

    // Removes highlights from all players
    void clearPlayerHighlight();

    // Returns true if all boards are at a draw or have a win
    bool allBoardsDone() const;

    // Unless it's a draw, this returns the player with the highest score
    int getWinnerRow();

    // Displays winner on top of window
    void displayWinner(int winnerIndex);

    // Call entire game as a draw on top of window
    void callDraw();

    // Ends game by either calling a draw or presenting the winner
    void finishGame();

private slots:
    void on_pushButton_back_clicked();

private:
    Ui::PlayGameWindow *ui;

    // Player names and symbols
    const QVector<Player> players;

    // Board grids
    QVector<Board> boards;

    // Grid hosting boards
    QGridLayout* table;

    // Players in the UI
    QGridLayout* playersUI;

    // Current player in player list in UI
    int currPlayerRow = 0;

    // Add boards to table
    void addBoards();

    // Add players to playersUI
    void addPlayers();

    // Get label within playersUI grid
    QLabel* getPlayersUILabel(const int i);

};

#endif // PLAYGAMEWINDOW_H
