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
{ createBoard(); }

Board::Board(const Board& other) :
    QWidget(other.parentWidget()),
    boardWidth(other.boardWidth),
    boardHeight(other.boardHeight),
    winCondition(other.winCondition),
    gridWidth(other.gridWidth),
    gridHeight(other.gridHeight)
{ createBoard(); }

QVBoxLayout* Board::getLayout() const { return layout; }

int Board::getBoardWidth() const { return boardWidth; }

int Board::getBoardHeight() const { return boardHeight; }

int Board::getWinCondition() const { return winCondition; }

int Board::getGridWidth() const { return gridWidth; }

int Board::getGridHeight() const { return gridHeight; }

void Board::createBoard()
{
    board = new QGridLayout();

    layout = new QVBoxLayout();
    QLabel* winCond = new QLabel("Win Condition: " + winCondition);  // TODO: text partially hidden
    layout->addWidget(winCond, 0, Qt::AlignCenter);
    layout->addLayout(board, 1);
    layout->setSpacing(5);

    // Connect lines
    board->setSpacing(0);

    setGridWidth(board, boardWidth);

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
            board->addWidget(space, row, col);
        }
}

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
    PlayGameWindow* w = static_cast<PlayGameWindow*>(parent());

    // If space has text or image
    if (space->getSymbol() != "")  return;

    space->setSymbol(w->getCurrPlayerSymbol());

    QVector<QVector<BoardSpaceLabel*>> wins = getAllWins(space);

    displayWins(wins);

    if (0 < wins.count() || boardIsFull())  disableBoard();

    w->addCurrPlayerScore(wins.count());


    // TODO: evalTable() or just finishGame() in second indentation or neither

    if (w->allBoardsDone()) {
        const int winnerRow = w->getWinnerRow();
        w->clearPlayerHighlight();

        // If no single highest score
        if (winnerRow == -1)
            w->callDraw();

        else {
            w->highlightPlayer(winnerRow);
            w->displayWinner(winnerRow);
        }

    // Continue game
    } else {
        w->iteratePlayer();
        w->highlightPlayer();
    }
}

bool Board::boardIsFull() const
{
    for (int row = 0; row < gridHeight; row += 2)
        for (int col = 0; col < gridWidth; col += 2)
            if (getSpace(row, col)->getSymbol() == "")  return false;

    return true;
}

BoardSpaceLabel* Board::getSpace(const int row, const int col) const
{
    return qobject_cast<BoardSpaceLabel*>
            (board->itemAtPosition(row, col)->widget());
}

void Board::disableBoard()
{
    for (int row = 0; row < gridHeight; row += 2)
        for (int col = 0; col < gridWidth; col += 2)
            getSpace(row, col)->setEnabled(false);

    board->setEnabled(false);
}

void Board::displayWins(const QVector<QVector<BoardSpaceLabel*>>& wins)
{
    for (QVector<BoardSpaceLabel*> winSpaces : wins)
        for (BoardSpaceLabel* space : winSpaces) {
            space->setStyleSheet("");

            QPalette palette = space->palette();  // TODO: utils?
            palette.setColor(QPalette::Background, QColor(144, 238, 144));
            space->setAutoFillBackground(true);

            space->setPalette(palette);
        }
}

int Board::getSpaceRow(BoardSpaceLabel* space)
{
    // Get boardSpace coordinates
    int row, _col, _rowSpan, _colSpan;
    board->getItemPosition(board->indexOf(space),
                           &row, &_col,
                           &_rowSpan, &_colSpan);

    return row;
}

int Board::getSpaceCol(BoardSpaceLabel* space)
{
    // Get boardSpace coordinates
    int _row, col, _rowSpan, _colSpan;
    board->getItemPosition(board->indexOf(space),
                           &_row, &col,
                           &_rowSpan, &_colSpan);

    return col;
}

QVector<QVector<BoardSpaceLabel*>> Board::getAllWins(BoardSpaceLabel* space)
{
    // Get space coordinates
    const int row = getSpaceRow(space);
    const int col = getSpaceCol(space);

    // Collects all win lines
    QVector<QVector<BoardSpaceLabel*>> allWins;

    // Check symbols horizontally
    allWins += getLineWins(row, col, 0, 2, 0, -col);

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

    for (int r = row + rowOffset, c = col + colOffset;
         r >= 0 && c >= 0 && r < gridHeight && c < gridWidth;
         r += rowStep, c += colStep)
    {
        QVariant currSymbol = getSpace(r, c)->getSymbol();

        if (currSymbol != "" && compareSymbols(compSymbol, currSymbol)) {
            sameInARow++;
        } else {
            sameInARow = 1;
            compSymbol = currSymbol;
            currWinSpaces.clear();
        }
        currWinSpaces.push_back(getSpace(r, c));

        if (currSymbol != "" && sameInARow == winCondition) {
            allWins.push_back(currWinSpaces);
            sameInARow--;
            currWinSpaces.erase(currWinSpaces.begin());
        }
    }

    return allWins;
}
