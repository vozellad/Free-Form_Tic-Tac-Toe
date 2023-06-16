#ifndef BOARD_H
#define BOARD_H

#include <QGridLayout>
#include "playsymbollabel.h"

class Board
{
public:
    Board(const int& width, const int& height, const int& winCondition);

    QGridLayout* getLayout();

private:
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

    void addClickedSpace(PlaySymbolLabel* space);

    void spaceClicked(PlaySymbolLabel* space);

    bool boardIsFull();

    QVariant getSymbol(const int& row, const int& col);

    PlaySymbolLabel* getSpace(const int& row, const int& col);

    void disableBoard();

    void displayWins(const QVector<QVector<PlaySymbolLabel*>>& wins);

    int getSpaceRow(PlaySymbolLabel* space);

    int getSpaceCol(PlaySymbolLabel* space);

    QVector<QVector<PlaySymbolLabel*>> getWinSpaces(PlaySymbolLabel* space);

};

#endif // BOARD_H
