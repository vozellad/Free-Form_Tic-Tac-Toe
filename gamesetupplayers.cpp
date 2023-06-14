#include "gamesetupwindow.h"
#include "ui_gamesetupwindow.h"

// Add new player row to list of players (which is a grid) by adding name and
// symbol widgets to grid layout. The grid already knows the column maximum,
// so just adding the widgets with no positional values works. Each symbol gets
// a click listener for a dialog window prompting the user for a new symbol.
void GameSetupWindow::on_toolButton_addPlayer_clicked()
{
    // increment player amount
    setPlayerAmt(getPlayerAmt() + 1);

    // add name
    QString newNameStr = tr("Player %1").arg(getPlayerAmt());
    players->addWidget(new QLineEdit(newNameStr));

    // add symbol
    SymbolLabel* newSymbol = new SymbolLabel();
    newSymbol->setSymbol("...");
    addClickedPlayerSymbol(newNameStr, newSymbol);
    players->addWidget(newSymbol);

    setAmtModBtnStates_players();
}

// To remove the last player row, remove the last element a number of times
// equal to the grid column width. The symbol and name of the last player gets
// removed. The grid size must also be readjusted or else there will be an
// empty space at the bottom.
void GameSetupWindow::on_toolButton_removePlayer_clicked()
{
    // decrement player amount
    setPlayerAmt(getPlayerAmt() - 1);

    // remove player row
    for (int i = 0; i < players->columnCount(); i++)
        deleteLastItem(players);

    reAdjustGridSize(players);

    setAmtModBtnStates_players();
}

// Connect symbol label to a click listener that brings up symbol prompt window.
// Function is a lambda function to pass variables.
void GameSetupWindow::addClickedPlayerSymbol(const QString& name,
                                             SymbolLabel* symbol)
{
    QObject::connect(symbol, &SymbolLabel::clicked, this,
        [this, name, symbol]()  {
            PlayerSymbolDialog *w = new PlayerSymbolDialog(name, symbol, this);
            w->show();
        }
    );
}

// Get number represeting player amount in UI
int GameSetupWindow::getPlayerAmt() const
{
    return ui->label_playerAmtDisplay->text().toInt();
}

// Set number represeting player amount in UI
void GameSetupWindow::setPlayerAmt(const int& newPlayerAmt)
{
    ui->label_playerAmtDisplay->setText(QString::number(newPlayerAmt));
}

// Keep player amount within range
// If not in range, turn off appropriate board amount modifier button -/+
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

    // Set grid column width
    players->setColumnMinimumWidth(width - 1, 0);
    players->setColumnStretch(width - 1, 0);

    // Add the 2 initial players
    on_toolButton_addPlayer_clicked();
    on_toolButton_addPlayer_clicked();

    // Set starting symbols
    qobject_cast<SymbolLabel*>(players->itemAt(1)->widget()) ->setSymbol("X");
    qobject_cast<SymbolLabel*>(
                players->itemAt(1 + width)->widget()) ->setSymbol("O");
}
