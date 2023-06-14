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

    void evalBoardWin(const QGridLayout* boardLayout);

    QVector<PlaySymbolLabel*> getWinSpaces(PlaySymbolLabel* boardSpace,
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
};

#endif // PLAYGAMEWINDOW_H
