#ifndef PLAYGAMEWINDOW_H
#define PLAYGAMEWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <cmath>
#include "player.h"
#include "board.h"
#include "imageutils.h"
#include "playsymbollabel.h"

// TODO: players on top. etc on bottom.

namespace Ui {
class PlayGameWindow;
}

class PlayGameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayGameWindow(const QVector<Player>& players,
                            const QVector<Board>& boards,
                            QWidget *parent = nullptr);
    ~PlayGameWindow();

private:
    Ui::PlayGameWindow *ui;

    QVector<Player> players;

    QVector<Board> boards;

    QGridLayout* table;

    int currPlayerIndex = 0;

    void addClickedBoardSpace(PlaySymbolLabel* boardSpace,
                              const QGridLayout* boardLayout,
                              const Board& boardSettings);

    void addBoards();

    QGridLayout* createBoard(const Board& boardSettings);

    void boardSpaceClicked(PlaySymbolLabel* boardSpace,
                           const QGridLayout* boardLayout,
                           const Board& boardSettings);

    QVector<QVector<PlaySymbolLabel*>> getWinSpaces(
            PlaySymbolLabel* boardSpace,
            const QGridLayout* boardLayout,
            const Board& boardSettings);

    bool boardIsFull(const QGridLayout* board);

    QVariant getSymbol(const QGridLayout* boardLayout,
                       const int& row,
                       const int& col);

    PlaySymbolLabel* getSpace(const QGridLayout* boardLayout,
                              const int& row,
                              const int& col);

    int getGridSize(const int& widthOrHeight);

    void disableBoard(const QGridLayout* boardLayout);

    bool vectorInVector(const QVector<PlaySymbolLabel*>& vec1,
                        const QVector<QVector<PlaySymbolLabel*>>& vec2);

    void displayWins(const QVector<QVector<PlaySymbolLabel*>>& wins);

    QVector<QVector<PlaySymbolLabel*>> sus(const int& gridSize,
                                           const QGridLayout* boardLayout);

    void sus(
            const int& pos,
            bool horiORVert,
            const int& size,
            const QGridLayout* boardLayout,
            QVector<QVector<PlaySymbolLabel*>>* allWins,
            const int& winCond);
};

#endif // PLAYGAMEWINDOW_H
