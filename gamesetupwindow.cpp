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
void GameSetupWindow::on_pushButton_startGame_clicked()
{
    // TODO: how to or do I split this?

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
            ErrorDialog *w = new ErrorDialog("Names cannot be empty.", this);
            w->show();
            return;
        }

        // Get symbol
        SymbolLabel* symbolLabel = qobject_cast<SymbolLabel*>
                (players->itemAt(i + 1)->widget());
        QVariant symbol = symbolLabel->getSymbol();
        playerSymbols.push_back(symbol);

        // Test for empty symbol
        if (symbol == "" || symbol == "...") {
            ErrorDialog *w = new ErrorDialog("Symbols cannot be empty.", this);
            w->show();
            return;
        }
    }

    // Test for non-unique name
    const std::set<QString> nameTest(playerNames.begin(), playerNames.end());
    if (static_cast<int>(nameTest.size()) < playerNames.size()) {
        ErrorDialog *w = new ErrorDialog("Names must be unique.", this);
        w->show();
        return;
    }

    // Test for non-unique symbol
    QVector<QVariant> symbolTest(playerSymbols);
    std::sort(symbolTest.begin(), symbolTest.end());
    // Adjacent compare
    for (int i = 0; i < symbolTest.size() - 1; i++) {

        // Get symbols to compare
        QVariant sym1 = symbolTest[i];
        QVariant sym2 = symbolTest[i + 1];

        // Check if same datatype
        if (sym1.userType() != sym2.userType())  continue;

        // Get comparison condition
        bool duplicateFound =
                // Compare as string
                (sym1.userType() == QMetaType::QString &&
                sym1.value<QString>() == sym2.value<QString>()) ||
                // Compare as image
                (sym1.userType() == QMetaType::QImage &&
                compareImages(sym1.value<QImage>(), sym2.value<QImage>()));

        // If comparing text and both texts are the same, display error
        if (duplicateFound) {
            ErrorDialog *w = new ErrorDialog("Symbols must be unique.", this);
            w->show();
            return;
        }
    }

    // Make player lists
    for (int i = 0; i < getPlayerAmt(); i++)
        playersList.push_back(Player{playerNames[i], playerSymbols[i]});

    // List of boards to pass to next window
    QVector<Board> boardsList;

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

        // Verify winCond is possible
        if (sizeX < winCond && sizeY < winCond) {
            QString e = "'In a row to win' number can't be more than grid size.";
            ErrorDialog *w = new ErrorDialog(e, this);
            w->show();
            return;
        }

        boardsList.push_back(Board(sizeX, sizeY, winCond));
    }

    PlayGameWindow *w = new PlayGameWindow(playersList, boardsList, this);
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
// This makes sure it is.
void GameSetupWindow::reAdjustGridSize(QGridLayout *l)
{
    int row = l->count() / l->columnCount() - 1;
    l->setRowMinimumHeight(row, 0);
    l->setRowStretch(row, 0);
}
