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

private:
    const int boardWidth;

    const int boardHeight;

    const int winCondition;

    const int gridWidth;

    const int gridHeight;

    QGridLayout* board;

    QVBoxLayout* layout;

    void createBoard();

    void addSpaces();

    void addLines();

    QFrame* getLine(QFrame::Shape lineType);

    void addClickedSpace(BoardSpaceLabel* space);

    void spaceClicked(BoardSpaceLabel* space);

    bool boardIsFull() const;

    BoardSpaceLabel* getSpace(const int row, const int col) const;

    void disableBoard();

    void displayWins(const QVector<QVector<BoardSpaceLabel*>>& wins);

    int getSpaceRow(BoardSpaceLabel* space);

    int getSpaceCol(BoardSpaceLabel* space);

    QVector<QVector<BoardSpaceLabel*>> getAllWins(BoardSpaceLabel* space);

    QVector<QVector<BoardSpaceLabel*>> getLineWins(const int row,
                                                   const int col,
                                                   const int rowStep,
                                                   const int colStep,
                                                   const int rowOffset,
                                                   const int colOffset);

};

#endif // BOARD_H
