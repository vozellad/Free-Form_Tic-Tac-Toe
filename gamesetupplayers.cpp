/*  This file contains functions relating to player settings.
 *  The header file is gamesetupwindow.h
 *  It's on the left side of the window.
 *  The player names and symbols may be changed,
 *  as well as the amount of players. The symbol can be text or an image.
 *  The user modifies the symbol via the PlayerSymbolDialog window.
 */

#include "gamesetupwindow.h"
#include "ui_gamesetupwindow.h"

// Adds new player row to list of players (which is a grid) by adding name and
// symbol widgets to grid layout. The grid already knows the column maximum,
// so just adding the widgets with no positional values works. Each symbol gets
// a click listener for a dialog window prompting the user for a new symbol.
void GameSetupWindow::on_toolButton_addPlayer_clicked()
{
    // Increment player amount
    setPlayerAmt(getPlayerAmt() + 1);

    // Add name
    QString newNameStr = tr("Player %1").arg(getPlayerAmt());
    players->addWidget(new QLineEdit(newNameStr));

    // Add symbol
    SymbolLabel* newSymbol = new SymbolLabel();
    newSymbol->setSymbol("...");
    addClickedPlayerSymbol(newNameStr, newSymbol);
    players->addWidget(newSymbol);

    // - and + buttons may become disabled if the amount is at the edge of the
    // player range
    setAmtModBtnStates_players();
}

// To remove the last player row, removes the last element a number of times
// equal to the grid column width. The symbol and name of the last player gets
// removed. The grid size must also be readjusted or else there will be an
// empty space at the bottom.
void GameSetupWindow::on_toolButton_removePlayer_clicked()
{
    // Decrement player amount
    setPlayerAmt(getPlayerAmt() - 1);

    // Remove player row
    for (int i = 0; i < players->columnCount(); i++)
        deleteLastItem(players);

    reAdjustGridSize(players);

    // - and + buttons may become disabled if the amount is at the edge of the
    // player range
    setAmtModBtnStates_players();
}

// Connects symbol label to a click listener that brings up symbol prompt window.
void GameSetupWindow::addClickedPlayerSymbol(const QString name,
                                             SymbolLabel* symbol)
{
    QObject::connect(symbol, &SymbolLabel::clicked, this,
        [this, name, symbol]()  {  // Lambda function to pass variables
            PlayerSymbolDialog *w = new PlayerSymbolDialog(name, symbol, this);
            w->show();
        }
    );
}

// Gets number represeting player amount in UI
int GameSetupWindow::getPlayerAmt() const
{
    return ui->label_playerAmtDisplay->text().toInt();
}

// Sets number represeting player amount in UI
void GameSetupWindow::setPlayerAmt(const int newPlayerAmt)
{
    ui->label_playerAmtDisplay->setText(QString::number(newPlayerAmt));
}

// Keeps player amount within range (1-99)
// If not in range, turns off appropriate board amount modifier button -/+
// to prevent user from going outside range
void GameSetupWindow::setAmtModBtnStates_players()
{
    ui->toolButton_addPlayer->setEnabled(true);
    ui->toolButton_removePlayer->setEnabled(true);

    if (getPlayerAmt() <= 1)
        ui->toolButton_removePlayer->setEnabled(false);
    else if (20 <= getPlayerAmt())
        ui->toolButton_addPlayer->setEnabled(false);
}

// Removing players is done by removing recent elements.
// This makes sure the elements of the player are ordered correctly
// to be correctly removed.
// Similar widgets to on_toolButton_addPlayer_clicked(),
// but with values and positional arguments specific to player 1 and 2.
void GameSetupWindow::addInitialPlayers()
{
    const int width = 2;

    setGridWidth(players, width);

    // Add the 2 initial players
    on_toolButton_addPlayer_clicked();
    on_toolButton_addPlayer_clicked();

    // Set starting symbols
    qobject_cast<SymbolLabel*>(players->itemAt(1)->widget()) ->setSymbol("X");
    qobject_cast<SymbolLabel*>
            (players->itemAt(1 + width)->widget()) ->setSymbol("O");
}
