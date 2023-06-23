#include "gamesetupwindow.h"
#include "ui_gamesetupwindow.h"

// TODO: how to name extended source files of class

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

// Go to next window
/*
void GameSetupWindow::on_pushButton_startGame_clicked_()
{
    // List of players to pass to next window
    QVector<Player> playersList;

    // Used to test for dulplicates and emptiness
    QVector<QString> playerNames;
    QVector<QVariant> playerSymbols;

    // Iterate through players
    for (int i = 0; i < players->count(); i += 2) {

        // Get name
        QString name = qobject_cast<QLineEdit*>
                (players->itemAt(i)->widget()) ->text();
        playerNames.push_back(name);

        // Test for empty name
        if (name.isEmpty()) {
            displayErrorDialog("Names cannot be empty.");
            return;
        }

        // Get symbol
        SymbolLabel* symbolLabel = qobject_cast<SymbolLabel*>
                (players->itemAt(i + 1)->widget());
        QVariant symbol = symbolLabel->getSymbol();
        playerSymbols.push_back(symbol);

        // Test for empty symbol
        if (symbol == "") {
            displayErrorDialog("Symbols cannot be empty.");
            return;
        } else if (symbol == "...") {
            displayErrorDialog("Symbols cannot be ellipses.");
            return;
        }
    }

    // Test for non-unique name
    const std::set<QString> nameTest(playerNames.begin(), playerNames.end());
    if (static_cast<int>(nameTest.size()) < playerNames.size()) {
        displayErrorDialog("Names must be unique.");
        return;
    }

    // Test for non-unique symbol
    QVector<QVariant> symbolTest(playerSymbols);
    std::sort(symbolTest.begin(), symbolTest.end());
    // Adjacent compare
    for (int i = 0; i < symbolTest.size() - 1; i++) {
        // If comparing text and both texts are the same, display error
        if (compareSymbols(symbolTest[i], symbolTest[i + 1])) {
            displayErrorDialog("Symbols must be unique.");
            return;
        }
    }

    // Make player lists
    for (int i = 0; i < getPlayerAmt(); i++)
        playersList.push_back(Player{playerNames[i], playerSymbols[i]});

    // List of boards to pass to next window
    QVector<BoardSettings> boardsList;

    // Iterate through boards
    for (int i = 0; i < boards->count(); i+=2) {  // +2 to skip hLines
        // Get board
        QGridLayout* currBoard =
                qobject_cast<QGridLayout*>(boards->itemAt(i)->layout());

        // Get board spinbox numbers
        const int sizeX = qobject_cast<QSpinBox*>  // TODO: need a getWidget function
                (currBoard->itemAt(3)->widget()) ->value();
        const int sizeY = qobject_cast<QSpinBox*>
                (currBoard->itemAt(5)->widget()) ->value();
        const int winCond = qobject_cast<QSpinBox*>
                (currBoard->itemAt(7)->widget()) ->value();

        // Verify winCond is possible
        if (sizeX < winCond && sizeY < winCond) {
            QString e = "'In a row to win' number can't be more than grid size.";
            displayErrorDialog(e);
            return;
        }

        boardsList.push_back(BoardSettings{sizeX, sizeY, winCond});
    }

    PlayGameWindow *w = new PlayGameWindow(playersList, boardsList, this);
    w->show();
    this->hide();
}*/

// Go to next window
void GameSetupWindow::on_pushButton_startGame_clicked()
{
    // List of players to pass to next window
    QVector<Player> playersList = getPlayers();


    // List of boards to pass to next window
    QVector<BoardSettings> boardsList = getBoards();

    if (!validateBoards(boardsList))
        return;

    PlayGameWindow* w = new PlayGameWindow(playersList, boardsList, this);
    w->show();
    this->hide();
}

QVector<Player> GameSetupWindow::getPlayers()
{
    QVector<Player> playersList;

    // Used to test for dulplicates and emptiness
    QVector<QString> playerNames;
    QVector<QVariant> playerSymbols;

    // Iterate through players
    for (int i = 0; i < players->count(); i += 2) {

        // Get name
        QString name = getWidget<SymbolLabel*>(players, i)->text();
        playerNames.push_back(name);

        // Test for empty name
        if (name.isEmpty()) {
            displayErrorDialog("Names cannot be empty.");
            //return;
        }

        // Get symbol
        SymbolLabel* symbolLabel = getWidget<SymbolLabel*>(players, i + 1);
        QVariant symbol = symbolLabel->getSymbol();
        playerSymbols.push_back(symbol);

        // Test for empty symbol
        if (symbol == "") {
            displayErrorDialog("Symbols cannot be empty.");
            //return;
        } else if (symbol == "...") {
            displayErrorDialog("Symbols cannot be ellipses.");
            //return;
        }
    }

    // Test for non-unique name
    const std::set<QString> nameTest(playerNames.begin(), playerNames.end());
    if (static_cast<int>(nameTest.size()) < playerNames.size()) {
        displayErrorDialog("Names must be unique.");
        //return;
    }

    // Test for non-unique symbol
    QVector<QVariant> symbolTest(playerSymbols);
    std::sort(symbolTest.begin(), symbolTest.end());
    // Adjacent compare
    for (int i = 0; i < symbolTest.size() - 1; i++) {
        // If comparing text and both texts are the same, display error
        if (compareSymbols(symbolTest[i], symbolTest[i + 1])) {
            displayErrorDialog("Symbols must be unique.");
            //return;
        }
    }

    // Make player lists
    for (int i = 0; i < getPlayerAmt(); i++)
        playersList.push_back(Player{playerNames[i], playerSymbols[i]});

    return playersList;
}

QVector<BoardSettings> GameSetupWindow::getBoards()
{
    QVector<BoardSettings> boardsList;

    // Iterate through boards
    for (int i = 0; i < boards->count(); i+=2) {  // +2 to skip hLines
        // Get board
        QGridLayout* currBoard =
                qobject_cast<QGridLayout*>(boards->itemAt(i)->layout());

        // Get board spinbox numbers
        const int sizeX = getWidget<QSpinBox*>(currBoard, 3)->value();
        const int sizeY = getWidget<QSpinBox*>(currBoard, 5)->value();
        const int winCond = getWidget<QSpinBox*>(currBoard, 7)->value();

        boardsList.push_back(BoardSettings{sizeX, sizeY, winCond});
    }

    return boardsList;
}

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

void GameSetupWindow::displayErrorDialog(const QString message)
{
    ErrorDialog* w = new ErrorDialog(message, this);
    w->show();
}

// Delete last item and widget within item in given layout
void GameSetupWindow::deleteLastItem(QLayout* l)
{
    QLayoutItem* lastItem = l->takeAt(l->count() - 1);
    delete lastItem->widget();
    delete lastItem;
}

// Deleting from a grid doesn't reduce the grid size appropriately.
// This makes sure it is.
void GameSetupWindow::reAdjustGridSize(QGridLayout *l)
{
    int row = l->count() / l->columnCount() - 1;
    l->setRowMinimumHeight(row, 0);
    l->setRowStretch(row, 0);
}
