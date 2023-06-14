#include "playgamewindow.h"
#include "ui_playgamewindow.h"

// TODO: board stuff might all need to be contained in a class

PlayGameWindow::PlayGameWindow(const QVector<Player>& players,
                               const QVector<Board>& boards,
                               QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayGameWindow),
    players(players),
    boards(boards)
{
    ui->setupUi(this);

    table = ui->gridLayout_table;
    table->setSpacing(42);

    addBoards();  // Add boards to table
}

PlayGameWindow::~PlayGameWindow()
{
    delete ui;
}

void PlayGameWindow::addClickedBoardSpace(PlaySymbolLabel* boardSpace,
                                          const QGridLayout* boardLayout,
                                          const Board& boardSettings)
{
    QObject::connect(boardSpace, &PlaySymbolLabel::clicked, this,
        [this, boardSpace, boardLayout, boardSettings]() {
            // if space has text or image
            if (boardSpace->getSymbol() != "")
                return;

            boardSpace->setSymbol(players[currPlayerIndex].symbol);

            QVector<PlaySymbolLabel*> winSpaces = getWinSpaces(boardSpace,
                                                               boardLayout,
                                                               boardSettings);

            for (PlaySymbolLabel* space : winSpaces) {
                QPalette palette = space->palette();
                palette.setColor(QPalette::Background,
                                 QColor(144, 238, 144));
                space->setAutoFillBackground(true);
                space->setPalette(palette);

                disableBoard(boardLayout);
            }

            if (!winSpaces && boardIsFull(boardLayout))
                disableBoard(boardLayout);

            // Cyclically iterate players
            currPlayerIndex = (currPlayerIndex + 1) % players.count();
        }
    );
}

void PlayGameWindow::addBoards()
{
    // addLayout() requires position values
    int row = 0, col = 0;

    const int tableWidth = ((int)sqrt(boards.count()) + 1);

    for (Board b : boards) {
        table->addLayout(createBoard(b), row, col);

        // Increment position values
        col = (col + 1) % tableWidth;
        if (col == 0)  row++;
    }
}

QGridLayout* PlayGameWindow::createBoard(const Board& boardSettings)
{
    // TODO: do with QPallete instead?

    QGridLayout* boardLayout = new QGridLayout();
    boardLayout->setSpacing(0);  // Connect lines

    // Grid sizes including grid lines
    const int gridHeight = getGridSize(boardSettings.sizeY);
    const int gridWidth = getGridSize(boardSettings.sizeX);

    // Set grid column width
    boardLayout->setColumnMinimumWidth(boardSettings.sizeX-1, 0);
    boardLayout->setColumnStretch(boardSettings.sizeX-1, 0);

    // Add spaces for symbols
    for (int row = 0; row < gridHeight; row += 2)
        for (int col = 0; col < gridWidth; col += 2) {
            PlaySymbolLabel* boardSpace = new PlaySymbolLabel();
            boardSpace->setAlignment(Qt::AlignCenter);
            addClickedBoardSpace(boardSpace, boardLayout, boardSettings);
            boardLayout->addWidget(boardSpace, row, col);
        }

    // Add lines
    for (int row = 0; row < gridHeight; row += 2) {
        for (int col = 1; col < gridWidth; col += 2) {
            QFrame* vLine = new QFrame;
            vLine->setFrameShape(QFrame::VLine);
            vLine->setStyleSheet("background-color: white;");  // TODO: make it theme agnostic
            boardLayout->addWidget(vLine, row, col);
        }

        // Don't add last hLine
        if (row >= gridHeight - 1)  break;

        QFrame* hLine = new QFrame;
        hLine->setFrameShape(QFrame::HLine);
        hLine->setStyleSheet("background-color: white;");  // TODO: make it theme agnostic
        boardLayout->addWidget(hLine, row + 1, 0, 1, 0);
    }

    return boardLayout;
}

void PlayGameWindow::evalBoardWin(const QGridLayout* board)
{

}

QVector<PlaySymbolLabel*> PlayGameWindow::getWinSpaces(
        PlaySymbolLabel* boardSpace,
        const QGridLayout* boardLayout,
        const Board& boardSettings)
{
    // TODO: account for multiple lines of single win

    // Grid sizes including grid lines
    const int gridHeight = getGridSize(boardSettings.sizeY);
    const int gridWidth = getGridSize(boardSettings.sizeX);

    // Get boardSpace coordinates
    int _row, _col, _rowSpan, _colSpan;
    boardLayout->getItemPosition(boardLayout->indexOf(boardSpace),
                                 &_row, &_col,
                                 &_rowSpan, &_colSpan);

    // Make coordinates immutable
    const int row = _row;
    const int col = _col;

    // Winning spaces to return
    QVector<PlaySymbolLabel*> winSpaces;

    // Helps account for multiple wins
    QVector<QVector<PlaySymbolLabel*>> pastWins;

    // Check symbols horizontally
    int sameInARow = 0;
    QVariant compareSymbol = getSymbol(boardLayout, row, 0);
    for (int c = 0; c < gridWidth; c += 2) {
        QVariant currSymbol = getSymbol(boardLayout, row, c);

        if (compareSymbol == currSymbol) {
            sameInARow++;
            winSpaces.push_back(getSpace(boardLayout, row, c));
        } else {
            sameInARow = 1;
            compareSymbol = currSymbol;
            winSpaces.clear();
        }

        if (sameInARow == boardSettings.winCond) {
            //if (winSpaces in pastWins)
            if (vectorInVector(winSpaces, pastWins)) {
                sameInARow--;
                winSpaces.erase(winSpaces.begin());
            } else  pastWins.push_back(winSpaces);
        }
    }

    // Reset spaces to return
    winSpaces.clear();

    //

    // Check symbols vertically
    sameInARow = 0;
    compareSymbol = getSymbol(boardLayout, 0, col);
    for (int r = 0; r < gridHeight; r += 2) {
        QVariant currSymbol = getSymbol(boardLayout, r, col);

        if (compareSymbol == currSymbol) {
            sameInARow++;
            winSpaces.push_back(getSpace(boardLayout, r, col));
        } else {
            sameInARow = 1;
            compareSymbol = currSymbol;
            winSpaces.clear();
        }

        if (sameInARow == boardSettings.winCond)
            return winSpaces;
    }

    winSpaces.clear();

    // check symbols diagonally


    winSpaces.clear();

    return QVector<PlaySymbolLabel*>();
    // TODO: what's the correct wa to do this?
    //       is it just return winSpaces because it's cleared?
}

bool PlayGameWindow::boardIsFull(const QGridLayout* boardLayout)
{
    for (int row = 0; row < boardLayout->rowCount(); row += 2)
        for (int col = 0; col < boardLayout->columnCount(); col += 2)
            if (getSymbol(boardLayout, row, col) == "")
                return false;

    return true;
}

// TODO: next 2 functions might get replaced by a utils function

QVariant PlayGameWindow::getSymbol(const QGridLayout* boardLayout,
                                   const int& row,
                                   const int& col)
{
    return qobject_cast<PlaySymbolLabel*>
            (boardLayout->itemAtPosition(row, col)->widget())
            ->getSymbol();
    // TODO: this or use getSpace().getSymbol()?
}

PlaySymbolLabel* PlayGameWindow::getSpace(const QGridLayout* boardLayout,
                                          const int& row,
                                          const int& col)
{
    return qobject_cast<PlaySymbolLabel*>
            (boardLayout->itemAtPosition(row, col)->widget());
}

int PlayGameWindow::getGridSize(const int& widthOrHeight)
{
    return widthOrHeight * 2 - 1;
}

void PlayGameWindow::disableBoard(const QGridLayout* boardLayout)
{
    for (int row = 0; row < boardLayout->rowCount(); row += 2)
        for (int col = 0; col < boardLayout->columnCount(); col += 2)
            getSpace(boardLayout, row, col)->setEnabled(false);
}


// TODO: utils function?
bool PlayGameWindow::vectorInVector(QVector& vec1, QVector& vec2)
{

}
