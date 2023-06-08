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
#include "clickablelabel.h"
#include "playgamewindow.h"
#include "player.h"
#include "board.h"
#include "imageutils.h"
#include "errordialog.h"

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

    // Add new player row to list of players
    void on_toolButton_addPlayer_clicked();

    // Remove last player row from list of players
    void on_toolButton_removePlayer_clicked();

    // Add new board to list of boards
    void on_toolButton_addBoard_clicked();

    // Remove last board from list of boards
    void on_toolButton_removeBoard_clicked();

private:
    Ui::GameSetupWindow *ui;

    // List of players
    QGridLayout* players;

    // List of boards
    QVBoxLayout* boards;

    // Prompt user for new symbol to replace clicked symbol
    void addClickedPlayerSymbol(const QString& name,
                                ClickableLabel* symbol,
                                QLabel* symImgHolder);

    // Get current amount of players
    int getPlayerAmt() const;

    // Set current amount of players
    void setPlayerAmt(const int& newPlayerAmt);

    // Keep player amount within range (1-99)
    // If not in range, turn off appropriate player amount modifier button -/+
    // to prevent user from going outside range
    void setAmtModBtnStates_players();

    // Delete last item in given layout
    void deleteLastItem(QLayout* l);

    // Deleting from a grid doesn't reduce the grid size appropriately.
    // This makes sure it is.
    void reAdjustGridSize(QGridLayout* l);

    // Removing players is done by removing recent elements.
    // This makes sure the elements of the player are ordered correctly
    // to be correctly removed.
    void addInitialPlayers();

    // Get current amount of boards
    int getBoardAmt() const;

    // Set current amount of boards
    void setBoardAmt(const int& newBoardAmt);

    // Keep board amount within range (1-99)
    // If not in range, turn off appropriate board amount modifier button -/+
    // to prevent user from going outside range
    void setAmtModBtnStates_boards();

    QSpinBox* createBoardSpinBox();
};

#endif // GAMESETUPWINDOW_H
