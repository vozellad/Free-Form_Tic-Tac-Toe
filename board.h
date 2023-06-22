#ifndef BOARD_H
#define BOARD_H

#include <QGridLayout>
#include "boardspacelabel.h"
#include "imageutils.h"

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

    QGridLayout* getLayout() const;

    int getBoardWidth() const;

    int getBoardHeight() const;

    int getWinCondition() const;

    int getGridWidth() const;

    int getGridHeight() const;

private:
    // TODO: which to add getter for?

    const int boardWidth;

    const int boardHeight;

    const int winCondition;

    const int gridWidth;

    const int gridHeight;

    QGridLayout* layout;

    void createBoard();

    void addSpaces();

    void addLines();

    QFrame* getLine(QFrame::Shape lineType);

    void addClickedSpace(BoardSpaceLabel* space);

    void spaceClicked(BoardSpaceLabel* space);

    bool boardIsFull() const;

    QVariant getSymbol(const int row, const int col) const;

    BoardSpaceLabel* getSpace(const int row, const int col) const;

    void disableBoard();

    void displayWins(const QVector<QVector<BoardSpaceLabel*>>& wins);

    int getSpaceRow(BoardSpaceLabel* space);

    int getSpaceCol(BoardSpaceLabel* space);

    QVector<QVector<BoardSpaceLabel*>> getWinSpaces(BoardSpaceLabel* space);

    void sus(const int row,
             const int col,
             QVector<QVector<BoardSpaceLabel*>>& allWins);

    bool compareSymbols(QVariant sym1, QVariant sym2);

};

#endif // BOARD_H
