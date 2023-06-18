#ifndef PLAYGAMEWINDOW_H
#define PLAYGAMEWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <cmath>
#include "player.h"
#include "board.h"
#include "boardspacelabel.h"  // TODO
#include "gamesetupwindow.h"

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

private slots:
    void on_pushButton_back_clicked();

private:
    Ui::PlayGameWindow *ui;

    QVector<Player> players;

    QVector<Board> boards;

    QGridLayout* table;

    QGridLayout* playersUI;

    int currPlayerIndex = 0;

    void addBoards();

    void addPlayers();

    void highlightPlayer();

};

#endif // PLAYGAMEWINDOW_H
