/*  This file contains functions relating to transfering the settings to
 *  PlayGameWindow when the Start Game button is pressed to go to the next
 *  window, the window that hosts the game using the settings from this window.
 */

#include "gamesetupwindow.h"
#include "ui_gamesetupwindow.h"

// Go to next window.
// Gather board and player settings and pass them to next window.
void GameSetupWindow::on_pushButton_startGame_clicked()
{
    // Get and validate names and symbols
    QVector<QString> playerNames = getNames();
    QVector<QVariant> playerSymbols = getSymbols();
    if(!validateNames(playerNames) || !validateSymbols(playerSymbols))
        return;

    // Create player list
    QVector<Player> playersList;
    for (int i = 0; i < getPlayerAmt(); i++)
        playersList.push_back(Player{playerNames[i], playerSymbols[i]});

    // Get and validate boards
    QVector<BoardSettings> boardsList = getBoards();
    if (!validateBoards(boardsList))
        return;

    // Pass players and boards to new window
    PlayGameWindow* w = new PlayGameWindow(playersList, boardsList, this);
    w->show();
    this->hide();
}

// Get names from player setup
QVector<QString> GameSetupWindow::getNames()
{
    QVector<QString> playerNames;

    for (int i = 0; i < players->count(); i += 2) {
        QString name = qobject_cast<QLineEdit*>
                (players->itemAt(i)->widget())->text();
        playerNames.push_back(name);
    }

    return playerNames;
}

// Get symbols from player setup
QVector<QVariant> GameSetupWindow::getSymbols()
{
    QVector<QVariant> playerSymbols;

    for (int i = 1; i < players->count(); i += 2) {
        QVariant symbol = qobject_cast<SymbolLabel*>
                (players->itemAt(i)->widget())->getSymbol();
        playerSymbols.push_back(symbol);
    }

    return playerSymbols;
}

// Make sure list of names from player setup is usable
bool GameSetupWindow::validateNames(QVector<QString> playerNames)
{
    // Test for empty name
    for (QString name : playerNames) {
        if (name.isEmpty()) {
            displayErrorDialog("Names cannot be empty.");
            return false;
        }
    }

    // Test for non-unique name
    const std::set<QString> nameTest(playerNames.begin(), playerNames.end());
    if (static_cast<int>(nameTest.size()) < playerNames.size()) {
        displayErrorDialog("Names must be unique.");
        return false;
    }

    return true;
}

// Make sure list of symbols from player setup is usable
bool GameSetupWindow::validateSymbols(QVector<QVariant> playerSymbols)
{
    // Test for empty symbol
    for (QVariant symbol : playerSymbols) {
        if (symbol == "") {
            displayErrorDialog("Symbols cannot be empty.");
            return false;
        } else if (symbol == "...") {
            displayErrorDialog("Symbols cannot be ellipses.");
            return false;
        }
    }

    // Test for non-unique symbol
    std::sort(playerSymbols.begin(), playerSymbols.end());
    // Adjacent compare
    for (int i = 0; i < playerSymbols.size() - 1; i++) {
        // If comparing text and both texts are the same, display error
        if (compareSymbols(playerSymbols[i], playerSymbols[i + 1])) {
            displayErrorDialog("Symbols must be unique.");
            return false;
        }
    }

    return true;
}

// Get boards from board setup
QVector<BoardSettings> GameSetupWindow::getBoards()
{
    QVector<BoardSettings> boardsList;

    // Iterate through boards
    for (int i = 0; i < boards->count(); i+=2) {  // +2 to skip hLines
        // Get board
        QGridLayout* currBoard =
                qobject_cast<QGridLayout*>(boards->itemAt(i)->layout());

        // Get board spinbox numbers
        const int sizeX = qobject_cast<QSpinBox*>
                (currBoard->itemAt(3)->widget()) ->value();
        const int sizeY = qobject_cast<QSpinBox*>
                (currBoard->itemAt(5)->widget()) ->value();
        const int winCond = qobject_cast<QSpinBox*>
                (currBoard->itemAt(7)->widget()) ->value();

        boardsList.push_back(BoardSettings{sizeX, sizeY, winCond});
    }

    return boardsList;
}

// Make sure list of boards is usable
bool GameSetupWindow::validateBoards(QVector<BoardSettings> boardsList)
{
    // Verify winCond is possible
    for (BoardSettings& b : boardsList)
        if (b.sizeX < b.winCond && b.sizeY < b.winCond) {
            QString e = "'In a row to win' number can't be more than grid size.";
            displayErrorDialog(e);
            return false;
        }

    return true;
}

// Dialog window to show errors to user
void GameSetupWindow::displayErrorDialog(const QString message)
{
    ErrorDialog* w = new ErrorDialog(message, this);
    w->show();
}
