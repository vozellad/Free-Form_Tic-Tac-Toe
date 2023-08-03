/*  This window allows the user to define the settings of the game.
 *  On the left side is the settings for the players.
 *  The player names and symbols may be changed,
 *  as well as the amount of players. The symbol can be text or an image.
 *  What may be changed about the boards is the amount of them,
 *  the board's horizontal and vertical sizes, and the amount in a row to win.
 *  Includes dialog window to display errors to the user.
 *  Includes boardsettings.h struct to pass board settings to next window
 *  easily.
 */

#ifndef GAMESETUPWINDOW_H
#define GAMESETUPWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QFileDialog>
#include <QSpacerItem>
#include <QLineEdit>
#include <QSpinBox>
#include <QMessageBox>
#include <algorithm>
#include <set>
#include "startscreenwindow.h"
#include "playersymboldialog.h"
#include "symbollabel.h"
#include "playgamewindow.h"
#include "player.h"
#include "boardsettings.h"
#include "imageutils.h"
#include "errordialog.h"
#include "utils.h"

namespace Ui {
class GameSetupWindow;
}

class GameSetupWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameSetupWindow(QWidget *parent = nullptr);
    ~GameSetupWindow();

private slots:
    // Go to previous window
    void on_pushButton_back_clicked();

    // Go to next window
    void on_pushButton_startGame_clicked();

    // Adds new player row to list of players
    void on_toolButton_addPlayer_clicked();

    // Removes last player row from list of players
    void on_toolButton_removePlayer_clicked();

    // Adds new board to list of boards
    void on_toolButton_addBoard_clicked();

    // Removes last board from list of boards
    void on_toolButton_removeBoard_clicked();

private:
    Ui::GameSetupWindow *ui;

    // List of players
    QGridLayout* players;

    // List of boards
    QVBoxLayout* boards;

    // Prompts user for new symbol to replace clicked symbol
    void addClickedPlayerSymbol(const QString name, SymbolLabel* symbol);

    // Gets current amount of players
    int getPlayerAmt() const;

    // Sets current amount of players
    void setPlayerAmt(const int newPlayerAmt);

    // Keeps player amount within range (1-99)
    // If not in range, turn off appropriate player amount modifier button -/+
    // to prevent user from going outside range
    void setAmtModBtnStates_players();

    // Gets names from player setup
    QVector<QString> getNames();

    // Gets symbols from player setup
    QVector<QVariant> getSymbols();

    // Makes sure list of names from player setup is usable
    bool validateNames(QVector<QString> playerNames);

    // Makes sure list of symbols from player setup is usable
    bool validateSymbols(QVector<QVariant> playerSymbols);

    // Gets boards from board setup
    QVector<BoardSettings> getBoards();

    // Makes sure list of boards is usable
    bool validateBoards(QVector<BoardSettings> boardsList);

    // Dialog window to show errors to user
    void displayErrorDialog(const QString message);

    // Deletes last item in given layout
    void deleteLastItem(QLayout* l);

    // Deleting from a grid doesn't reduce the grid size appropriately.
    // This corrects the grid size.
    // Use after reducing the size of a grid.
    void reAdjustGridSize(QGridLayout* l);

    // Removing players is done by removing recent elements.
    // This makes sure the elements of the player are ordered correctly
    // to be correctly removed.
    void addInitialPlayers();

    // Gets current amount of boards
    int getBoardAmt() const;

    // Sets current amount of boards
    void setBoardAmt(const int newBoardAmt);

    // Keeps board amount within range (1-99)
    // If not in range, turns off appropriate board amount modifier button -/+
    // to prevent user from going outside range
    void setAmtModBtnStates_boards();

    // Returns a spinbox modified for board setup
    QSpinBox* createBoardSpinBox();
};

#endif // GAMESETUPWINDOW_H
