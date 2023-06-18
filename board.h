#ifndef BOARD_H
#define BOARD_H

#include <QGridLayout>
#include "boardspacelabel.h"

// TODO: change name to BoardGrid/BoardGridLayout?

class Board : public QGridLayout
{
    Q_OBJECT

public:
    Board(const int width,
          const int height,
          const int winCondition,
          QWidget* parent = Q_NULLPTR);
    Board(const Board& other, QWidget* parent = Q_NULLPTR);
    ~Board();

private:
    const int boardWidth;

    const int boardHeight;

    const int winCondition;

    const int gridWidth;

    const int gridHeight;

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

};

#endif // BOARD_H
