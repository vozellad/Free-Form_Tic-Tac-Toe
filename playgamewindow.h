#ifndef PLAYGAMEWINDOW_H
#define PLAYGAMEWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <cmath>
#include "player.h"
#include "board.h"
#include "imageutils.h"
#include "clickablelabel.h"

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

    void addClickedBoardSpace(ClickableLabel* boardSpace,
                              const QGridLayout* board);

    void addBoards();

    QGridLayout* createBoard(const Board& board);

    void insertPlayerSymbol(ClickableLabel* boardSpace);

    void evalBoard(const QGridLayout* board);

};

#endif // PLAYGAMEWINDOW_H
