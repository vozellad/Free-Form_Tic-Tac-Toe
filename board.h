/*  This is a TicTacToe board meant to use added to PlayGameWindow.
 *  It is a layout with text on top and a grid for the board.
 *  The board is made up of board spaces using BoardSpaceLabel with lines as
 *  visual seperators.
 */

#ifndef BOARD_H
#define BOARD_H

#include <QGridLayout>
#include "boardspacelabel.h"
#include "imageutils.h"
#include "utils.h"

class PlayGameWindow;

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(const int width,
                   const int height,
                   const int winCondition,
                   PlayGameWindow* parent);
    explicit Board(const Board& other);

    QVBoxLayout* getLayout() const;

    int getBoardWidth() const;

    int getBoardHeight() const;

    int getWinCondition() const;

    int getGridWidth() const;

    int getGridHeight() const;

    // Return true if board is finished playing (has a win or is a draw)
    bool isEnabled() const;

private:
    // The width of board spaces
    const int boardWidth;

    // The height of board spaces
    const int boardHeight;

    // Amount of same symbols in a row to win
    const int winCondition;

    // The width of elements in the grid
    const int gridWidth;

    // The height of elements in the grid
    const int gridHeight;

    // The grid containing board spaces and line seperators
    QGridLayout* board;

    // Layout to give to window. Includes title and grid.
    QVBoxLayout* layout;

    // Creates layout and board
    void createBoard();

    // Adds board spaces to board
    void addSpaces();

    // Add lines to visually seperate board spaces
    void addLines();

    // Create and return a line (that works in dark mode).
    // Horizontal or vertical decided by argument.
    QFrame* getLine(QFrame::Shape lineType);

    // Connect board space via click listener to a function
    void addClickedSpace(BoardSpaceLabel* space);

    // Functionality for when a board space is clicked
    void spaceClicked(BoardSpaceLabel* space);

    // If no empty space left in board, the board is full.
    bool boardIsFull() const;

    // Gets board space in board grid via positional values
    BoardSpaceLabel* getSpace(const int row, const int col) const;

    // Disables board and every space in the board
    void disableBoard();

    // Highlights winning lines
    void displayWins(const QVector<QVector<BoardSpaceLabel*>>& wins);

    // Gets board row(int) that board space is in
    int getSpaceRow(BoardSpaceLabel* space);

    // Gets board col(int) that board space is in
    int getSpaceCol(BoardSpaceLabel* space);

    // Gets all winning lines
    QVector<QVector<BoardSpaceLabel*>> getAllWins(BoardSpaceLabel* space);

    // Gets all wins in line. Only used in getAllWins.
    // Parameters account for different types of board lines.
    QVector<QVector<BoardSpaceLabel*>> getLineWins(const int row,
                                                   const int col,
                                                   const int rowStep,
                                                   const int colStep,
                                                   const int rowOffset,
                                                   const int colOffset);

};

#endif // BOARD_H
