#include "board.h"

Board::Board(const int& width, const int& height, const int& winCondition) :
    boardWidth(width),
    boardHeight(height),
    winCondition(winCondition),
    gridWidth(width * 2 - 1),
    gridHeight(height * 2 - 1)
{
    createBoard();
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wextra"
Board::Board::Board(const Board& other) :
    boardWidth(other.boardWidth),
    boardHeight(other.boardHeight),
    winCondition(other.winCondition),
    gridWidth(other.gridWidth),
    gridHeight(other.gridHeight)
{
    createBoard();
}
#pragma GCC diagnostic pop

Board::~Board()
{
    // TODO: delete layout
}

QGridLayout* Board::getLayout() const
{
    //TODO: return if no error
    return layout;
}

//get via index

void Board::createBoard()
{
    // TODO: do with QPallete instead?

    layout = new QGridLayout();

    // Connect lines
    layout->setSpacing(0);

    // Set grid column width
    layout->setColumnMinimumWidth(boardWidth - 1, 0);
    layout->setColumnStretch(boardWidth - 1, 0);

    addSpaces();

    addLines();
}

void Board::addSpaces()
{
    for (int row = 0; row < gridHeight; row += 2)
        for (int col = 0; col < gridWidth; col += 2) {
            BoardSpaceLabel* space = new BoardSpaceLabel();
            space->setAlignment(Qt::AlignCenter);
            addClickedSpace(space);
            layout->addWidget(space, row, col);
        }
}

void Board::addLines()
{
    for (int row = 0; row < gridHeight; row += 2) {
        for (int col = 1; col < gridWidth; col += 2)
            layout->addWidget(getLine(QFrame::VLine), row, col);

        // Don't add last hLine
        if (row >= gridHeight - 1)  break;

        layout->addWidget(getLine(QFrame::HLine), row + 1, 0, 1, 0);
    }
}

QFrame* Board::getLine(QFrame::Shape lineType)
{
    QFrame* line = new QFrame;
    line->setFrameShape(lineType);
    line->setStyleSheet("background-color: white;");  // TODO: make it theme agnostic
    return line;
}

void Board::addClickedSpace(BoardSpaceLabel* space)
{
    QObject::connect(space, &BoardSpaceLabel::clicked, this,
        [this, space]() { spaceClicked(space); }
    );
}

void Board::spaceClicked(BoardSpaceLabel* space)
{
    // if space has text or image
    if (space->getSymbol() != "")
        return;

    // TODO: boardSpace->setSymbol(players[currPlayerIndex].symbol);
    space->setSymbol("X");

    QVector<QVector<BoardSpaceLabel*>> wins = getWinSpaces(space);

    displayWins(wins);

    if (0 < wins.count() || boardIsFull())  disableBoard();

    // Cyclically iterate players
    // TODO: currPlayerIndex = (currPlayerIndex + 1) % players.count();
}

bool Board::boardIsFull() const
{
    for (int row = 0; row < gridHeight; row += 2)
        for (int col = 0; col < gridWidth; col += 2)
            if (getSymbol(row, col) == "")
                return false;

    return true;
}

// TODO: next 2 functions might get replaced by a utils function

QVariant Board::getSymbol(const int row, const int col) const
{
    return getSpace(row, col)->getSymbol();
}

BoardSpaceLabel* Board::getSpace(const int row, const int col) const
{
    return qobject_cast<BoardSpaceLabel*>
            (layout->itemAtPosition(row, col)->widget());
}

void Board::disableBoard()
{
    for (int row = 0; row < gridHeight; row += 2)
        for (int col = 0; col < gridWidth; col += 2)
            getSpace(row, col)->setEnabled(false);
}

void Board::displayWins(const QVector<QVector<BoardSpaceLabel*>>& wins)
{
    for (QVector<BoardSpaceLabel*> winSpaces : wins)
        for (BoardSpaceLabel* space : winSpaces) {
            QPalette palette = space->palette();
            palette.setColor(QPalette::Background, QColor(144, 238, 144));
            space->setAutoFillBackground(true);

            space->setPalette(palette);
        }
}

int Board::getSpaceRow(BoardSpaceLabel* space)
{
    // Get boardSpace coordinates
    int row, _col, _rowSpan, _colSpan;
    layout->getItemPosition(layout->indexOf(space),
                            &row, &_col,
                            &_rowSpan, &_colSpan);

    return row;
}

int Board::getSpaceCol(BoardSpaceLabel* space)
{
    // Get boardSpace coordinates
    int _row, col, _rowSpan, _colSpan;
    layout->getItemPosition(layout->indexOf(space),
                            &_row, &col,
                            &_rowSpan, &_colSpan);

    return col;
}


// TODO: there's enough duplicate code to justify a creating a function for it,
// but the code is similar enough to make it difficult.
// I don't yet know how to do it.
QVector<QVector<BoardSpaceLabel*>>
Board::getWinSpaces(BoardSpaceLabel* space)
{
    // Get space coordinates
    const int row = getSpaceRow(space);
    const int col = getSpaceCol(space);

    //
    QVector<BoardSpaceLabel*> currWinSpaces;

    //
    QVector<QVector<BoardSpaceLabel*>> allWins;

    // Check symbols horizontally
    int sameInARow = 0;
    QVariant compareSymbol = getSymbol(row, 0);
    for (int c = 0; c < gridWidth; c += 2) {
        QVariant currSymbol = getSymbol(row, c);

        if (currSymbol != "" && compareSymbol == currSymbol) {
            sameInARow++;
            currWinSpaces.push_back(getSpace(row, c));
        } else {
            sameInARow = 1;
            compareSymbol = currSymbol;
            currWinSpaces.clear();
            currWinSpaces.push_back(getSpace(row, c));
        }

        if (sameInARow == winCondition) {
            allWins.push_back(currWinSpaces);
            sameInARow--;
            currWinSpaces.erase(currWinSpaces.begin());
        }
    }

    // Reset spaces to return
    currWinSpaces.clear();

    //

    // Check symbols vertically
    sameInARow = 0;
    compareSymbol = getSymbol(0, col);
    for (int r = 0; r < gridHeight; r += 2) {
        QVariant currSymbol = getSymbol(r, col);

        if (currSymbol != "" && compareSymbol == currSymbol) {
            sameInARow++;
            currWinSpaces.push_back(getSpace(r, col));
        } else {
            sameInARow = 1;
            compareSymbol = currSymbol;
            currWinSpaces.clear();
            currWinSpaces.push_back(getSpace(r, col));
        }

        if (sameInARow == winCondition) {
            allWins.push_back(currWinSpaces);
            sameInARow--;
            currWinSpaces.erase(currWinSpaces.begin());
        }
    }

    currWinSpaces.clear();

    // Get beginning of diagonal line (first)
    int dRow = row, dCol = col;
    while (0 < dRow && 0 < dCol) {
        dRow--;
        dCol--;
    }

    // check symbols diagonally (first)
    sameInARow = 0;
    compareSymbol = getSymbol(dRow, dCol);
    for (; dRow < gridHeight && dCol < gridWidth; dRow += 2, dCol += 2) {
        QVariant currSymbol = getSymbol(dRow, dCol);

        if (currSymbol != "" && compareSymbol == currSymbol) {
            sameInARow++;
            currWinSpaces.push_back(getSpace(dRow, dCol));
        } else {
            sameInARow = 1;
            compareSymbol = currSymbol;
            currWinSpaces.clear();
            currWinSpaces.push_back(getSpace(dRow, dCol));
        }

        if (sameInARow == winCondition) {
            allWins.push_back(currWinSpaces);
            sameInARow--;
            currWinSpaces.erase(currWinSpaces.begin());
        }
    }

    currWinSpaces.clear();

    // Get beginning of diagonal line (second)
    dRow = row, dCol = col;
    while (0 < dRow && dCol + 2 <= gridWidth) {
        dRow--;
        dCol++;
    }

    // Check symbols diagonally (second)
    sameInARow = 0;
    compareSymbol = getSymbol(dRow, dCol);
    for (; dRow < gridHeight && 0 <= dCol; dRow += 2, dCol -= 2) {
        QVariant currSymbol = getSymbol(dRow, dCol);

        if (currSymbol != "" && compareSymbol == currSymbol) {
            sameInARow++;
            currWinSpaces.push_back(getSpace(dRow, dCol));
        } else {
            sameInARow = 1;
            compareSymbol = currSymbol;
            currWinSpaces.clear();
            currWinSpaces.push_back(getSpace(dRow, dCol));
        }

        if (sameInARow == winCondition) {
            allWins.push_back(currWinSpaces);
            sameInARow--;
            currWinSpaces.erase(currWinSpaces.begin());
        }
    }

    return allWins;
}

