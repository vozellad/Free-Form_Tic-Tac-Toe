#include "gamesetupwindow.h"
#include "ui_gamesetupwindow.h"

// TODO: how to name extended source files of class

GameSetupWindow::GameSetupWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameSetupWindow)
{
    ui->setupUi(this);

    // hides element that helps center the title
    ui->pushButton_backBalancer->setVisible(false);

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
    // TODO: Make another source file for this

    // List of players to pass to next window
    QVector<Player> players_;  // TODO: fix name

    // Used to test for dulplicates and emptiness
    QVector<QString> playerNames;
    QVector<QVariant> playerSymbols;

    // Get names
    for (int i = 0; i < players->count(); i += 2) {
        QString name = qobject_cast<QLineEdit*>
                (players->itemAt(i)->widget()) ->text();
        playerNames.push_back(name);

        // Test for empty name
        if (name.isEmpty()) {
            // dialog error window (make function that does this) - empty name
            return;
        }
    }

    // Get symbols
    for (int i = 1; i < players->count(); i += 2) {
        ClickableLabel* symbolLabel = qobject_cast<ClickableLabel*>
                (players->itemAt(i)->widget());
        QString symbolText = symbolLabel->text();
        QImage* symbolImage = getImageFromLabel(symbolLabel);

        if (!symbolText.isEmpty())
            playerSymbols.push_back(symbolText);
        else if (symbolImage->isNull())
            playerSymbols.push_back(symbolImage);

        // Test for empty symbol
        else if (symbolText.isEmpty() || symbolText != "...") {
            // dialog error window - empty symbol
        }
    }

    // Test for non-unique name
    // TODO: arr.begin() or begin(arr)
    std::set<QString> nameTest(playerNames.begin(), playerNames.end());
    if (nameTest.size() < playerNames.size()) {
        // dialog error window - duplicate name
    }

    // Test for non-unique symbol
    std::set<QVariant> symbolTest(playerSymbols.begin(), playerSymbols.end());
    if (symbolTest.size() < playerSymbols.size()) {
        // dialog error window - duplicate name
        ui->label_title->setText("duplicate found");
    }

    // Make player list
    for (int i = 0; i < players->rowCount(); i++)
        if (playerSymbols[i].canConvert<QString>())
            players_.push_back(Player(playerNames[i],
                                      playerSymbols[i].value<QString>()));
        else
            players_.push_back(Player(playerNames[i],
                                      playerSymbols[i].value<QImage*>()));


    // PlayGameWindow *w = new PlayGameWindow(players_, this);
    // this->hide();
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
    int row = l->count() / l->columnCount();
    l->setRowMinimumHeight(row, 0);
    l->setRowStretch(row, 0);
}
