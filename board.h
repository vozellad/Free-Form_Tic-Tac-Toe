#ifndef BOARD_H
#define BOARD_H

#include <QGridLayout>
#include "boardspacelabel.h"

class Board : public QObject
{
    Q_OBJECT

public:
    Board(const int width,
          const int height,
          const int winCondition,
          auto gameWindow);
    Board(const Board& other);
    ~Board();

    QGridLayout* getLayout();

private:
    // TODO: which to add getter for?

    const int boardWidth;

    const int boardHeight;

    const int winCondition;

    const int gridWidth;

    const int gridHeight;

    QGridLayout* layout;

    bool boardCreated = false;

    void createBoard();

    void addSpaces();

    void addLines();

    QFrame* getLine(QFrame::Shape lineType);

    void addClickedSpace(BoardSpaceLabel* space);

    void spaceClicked(BoardSpaceLabel* space, Board* b);

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
