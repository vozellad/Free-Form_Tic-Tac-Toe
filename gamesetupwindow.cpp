/*  This window allows the user to define the settings of the game.
 *
 *  The functions relating to player settings
 *  are kept in the file gamesetupplayers.cpp
 *
 *  The functions relating to the board settings
 *  are kept in the file gamesetupboards.cpp
 *
 *  The functions relating to transfering the settings to PlayGameWindow
 *  are kept in the file gamesetupstartgame.cpp
 */

#include "gamesetupwindow.h"
#include "ui_gamesetupwindow.h"

GameSetupWindow::GameSetupWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameSetupWindow)
{
    ui->setupUi(this);

    // make - + buttons square
    QToolButton* buttonArray[4] = {
        ui->toolButton_addPlayer,
        ui->toolButton_removePlayer,
        ui->toolButton_addBoard,
        ui->toolButton_removeBoard
    };
    for (QToolButton* b : buttonArray)
        b->setMinimumWidth(b->height());

    players = ui->gridLayout_players;
    addInitialPlayers();

    boards = ui->verticalLayout_boards;
    on_toolButton_addBoard_clicked();  // Add initial board

    // Keeps UI of board setup from being smaller than the UI of player setup
    // when window is sized down
    ui->label_boardAmtDisplay->
        setMinimumWidth(ui->label_playerAmtDisplay->width());
}

GameSetupWindow::~GameSetupWindow()
{
    delete ui;
}

// Go to previous window
void GameSetupWindow::on_pushButton_back_clicked()
{
    StartScreenWindow *w = new StartScreenWindow(this);
    w->show();

    this->hide();
}

// Delete last item and widget within item in given layout
void GameSetupWindow::deleteLastItem(QLayout* l)
{
    QLayoutItem* lastItem = l->takeAt(l->count() - 1);
    delete lastItem->widget();
    delete lastItem;
}

// Deleting from a grid doesn't reduce the grid size appropriately.
// This corrects the grid size.
void GameSetupWindow::reAdjustGridSize(QGridLayout *l)
{
    int row = l->count() / l->columnCount() - 1;
    l->setRowMinimumHeight(row, 0);
    l->setRowStretch(row, 0);
}
