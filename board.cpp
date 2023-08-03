/*  This is a TicTacToe board meant to use added to PlayGameWindow.
 *  It is a layout with text on top and a grid for the board.
 *  The board is made up of board spaces using BoardSpaceLabel with lines as
 *  visual seperators.
 */

#include "board.h"
#include "playgamewindow.h"

Board::Board(const int width,
             const int height,
             const int winCondition,
             PlayGameWindow* parent) :
    QWidget(parent),
    boardWidth(width),
    boardHeight(height),
    winCondition(winCondition),
    gridWidth(width * 2 - 1),
    gridHeight(height * 2 - 1)
{
    createBoard();
}

Board::Board(const Board& other) :
    QWidget(other.parentWidget()),
    boardWidth(other.boardWidth),
    boardHeight(other.boardHeight),
    winCondition(other.winCondition),
    gridWidth(other.gridWidth),
    gridHeight(other.gridHeight)
{
    createBoard();
}

QVBoxLayout* Board::getLayout() const { return layout; }

int Board::getBoardWidth() const { return boardWidth; }

int Board::getBoardHeight() const { return boardHeight; }

int Board::getWinCondition() const { return winCondition; }

int Board::getGridWidth() const { return gridWidth; }

int Board::getGridHeight() const { return gridHeight; }

// Return true if board is finished playing (has a win or is a draw)
bool Board::isEnabled() const { return board->isEnabled(); }

// Create layout and board
void Board::createBoard()
{
    board = new QGridLayout();

    layout = new QVBoxLayout();

    // Setup layout
    QString boardTitle = QString::number(winCondition) + " in a row";
    QLabel* winCond = new QLabel(boardTitle);
    layout->addWidget(winCond, 0, Qt::AlignCenter);
    layout->addLayout(board, 1);
    layout->setSpacing(5);

    // Setup board
    board->setSpacing(0);  // Remove spacing between lines
    setGridWidth(board, boardWidth);
    addSpaces();
    addLines();
}

// Add board spaces to board (amount based on user-given width and height)
void Board::addSpaces()
{
    for (int row = 0; row < gridHeight; row += 2)
        for (int col = 0; col < gridWidth; col += 2) {
            BoardSpaceLabel* space = new BoardSpaceLabel();
            space->setAlignment(Qt::AlignCenter);
            addClickedSpace(space);
            board->addWidget(space, row, col);
        }
}

// Add lines to visually seperate board spaces
void Board::addLines()
{
    for (int row = 0; row < gridHeight; row += 2) {
        for (int col = 1; col < gridWidth; col += 2)
            board->addWidget(getLine(QFrame::VLine), row, col);

        // Don't add last hLine
        if (row >= gridHeight - 1)  break;

        board->addWidget(getLine(QFrame::HLine), row + 1, 0, 1, 0);
    }
}

// Create and return a line (that works in dark mode).
// Horizontal or vertical decided by argument.
QFrame* Board::getLine(QFrame::Shape lineType)
{
    QFrame* line = new QFrame;
    line->setFrameShape(lineType);
    line->setStyleSheet("background-color: white;");
    return line;
}

// Connect board space via click listener to a function
void Board::addClickedSpace(BoardSpaceLabel* space)
{
    QObject::connect(space, &BoardSpaceLabel::clicked, this,
        [this, space]() { spaceClicked(space); }
    );
}

// Functionality for when a board space is clicked.
// Requires usage of parent window, the window hosting the game,
// to use functions from that window.
// Function writes symbol, handles winning lines,
// and handles the state of the game.
// This class handles the board, but because this is where the click listener
// is, it uses functionality from the parent class as well.
void Board::spaceClicked(BoardSpaceLabel* space)
{
    // Get parent game window
    PlayGameWindow* w = static_cast<PlayGameWindow*>(parent());

    // If space has text or image
    if (space->getSymbol() != "")  return;

    // Write current player symbol to clicked space
    space->setSymbol(w->getCurrPlayerSymbol());

    QVector<QVector<BoardSpaceLabel*>> wins = getAllWins(space);
    displayWins(wins);
    w->addCurrPlayerScore(wins.count());

    if (0 < wins.count() || boardIsFull()) disableBoard();

    if (w->allBoardsDone()) {
        w->finishGame();
    } else {  // Continue game
        w->iteratePlayer();
        w->highlightPlayer();
    }
}

// If no empty space left in board, the board is full.
// It's meant to be used to evaluate whether the board should be disabled.
// It likely indicates the board is at a draw.
bool Board::boardIsFull() const
{
    for (int row = 0; row < gridHeight; row += 2)
        for (int col = 0; col < gridWidth; col += 2)
            if (getSpace(row, col)->getSymbol() == "")  return false;

    return true;
}

// Contains the multi-layered syntax required to get a board space via
// positional values
BoardSpaceLabel* Board::getSpace(const int row, const int col) const
{
    return qobject_cast<BoardSpaceLabel*>
            (board->itemAtPosition(row, col)->widget());
}

// Disables board and every space in the board.
// It's meant to be used for when the board is at a draw or has a win
// and no more input should be accepted.
// As side effect, any images in the board will become grayscale.
// This side effect is purposefully accepted.
void Board::disableBoard()
{
    for (int row = 0; row < gridHeight; row += 2)
        for (int col = 0; col < gridWidth; col += 2)
            getSpace(row, col)->setEnabled(false);

    board->setEnabled(false);
}

// Applies a color to the board spaces that are part of a winning line
void Board::displayWins(const QVector<QVector<BoardSpaceLabel*>>& wins)
{
    for (QVector<BoardSpaceLabel*> winSpaces : wins)
        for (BoardSpaceLabel* space : winSpaces)
            setLabelBackgroundColor(space, QColor(144, 238, 144));
}

// Uses getItemPosition function to get one of the four values it gives back
int Board::getSpaceRow(BoardSpaceLabel* space)
{
    // Get boardSpace coordinates
    int row, _col, _rowSpan, _colSpan;
    board->getItemPosition(board->indexOf(space),
                           &row, &_col,
                           &_rowSpan, &_colSpan);

    return row;
}

// Uses getItemPosition function to get one of the four values it gives back
int Board::getSpaceCol(BoardSpaceLabel* space)
{
    // Get boardSpace coordinates
    int _row, col, _rowSpan, _colSpan;
    board->getItemPosition(board->indexOf(space),
                           &_row, &col,
                           &_rowSpan, &_colSpan);

    return col;
}

// Gets all winning lines
QVector<QVector<BoardSpaceLabel*>> Board::getAllWins(BoardSpaceLabel* space)
{
    // Get space coordinates
    const int row = getSpaceRow(space);
    const int col = getSpaceCol(space);

    // Collects all win lines
    QVector<QVector<BoardSpaceLabel*>> allWins;

    // Check symbols horizontally
    allWins += getLineWins(row, col, 0, 2, 0, -col);

    if (winCondition == 1) return allWins;
    // Otherwise, the rest of this function will find the same space as a win.

    // Check symbols vertically
    allWins += getLineWins(row, col, 2, 0, -row, 0);

    // Get beginning of diagonal line (first)
    int dRow = row, dCol = col;
    for (; 0 < dRow && 0 < dCol; dRow--, dCol--);

    // check symbols diagonally (first)
    allWins += getLineWins(dRow, dCol, 2, 2, 0, 0);

    // Get beginning of diagonal line (second)
    dRow = row, dCol = col;
    for (; 0 < dRow && dCol + 2 <= gridWidth; dRow--, dCol++);

    // Check symbols diagonally (second)
    allWins += getLineWins(dRow, dCol, 2, -2, 0, 0);

    return allWins;
}

// Gets all wins in line
QVector<QVector<BoardSpaceLabel*>> Board::getLineWins(const int row,
                                                      const int col,
                                                      const int rowStep,
                                                      const int colStep,
                                                      const int rowOffset,
                                                      const int colOffset)
{
    QVector<BoardSpaceLabel*> currWinSpaces;
    QVector<QVector<BoardSpaceLabel*>> allWins;
    int sameInARow = 0;
    QVariant compSymbol =
            getSpace(row + rowOffset, col + colOffset)->getSymbol();

    // For loop with parameters to account for the line being
    // horizontal, vertical, or diagonal(either way)
    for (int r = row + rowOffset, c = col + colOffset;
         r >= 0 && c >= 0 && r < gridHeight && c < gridWidth;
         r += rowStep, c += colStep)
    {
        QVariant currSymbol = getSpace(r, c)->getSymbol();

        // If the symbol is the same as the last space's symbol.
        // Must check empty space because multiple empty spaces
        // in a row should not count as a win.
        if (currSymbol != "" && compareSymbols(compSymbol, currSymbol)) {
            sameInARow++;
        } else {
            // Count current space as start of possible winning line
            sameInARow = 1;
            compSymbol = currSymbol;
            currWinSpaces.clear();
        }
        currWinSpaces.push_back(getSpace(r, c));

        // If amount of same symbols is the win condition
        if (currSymbol != "" && sameInARow == winCondition) {
            allWins.push_back(currWinSpaces);
            // Example: winCondition of 3 and 4 same symbols
            // in a row counts as 2 wins
            sameInARow--;
            currWinSpaces.erase(currWinSpaces.begin());
        }
    }

    return allWins;
}
