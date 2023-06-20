#ifndef PLAYGAMEWINDOW_H
#define PLAYGAMEWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <cmath>
#include "player.h"
#include "board.h"
#include "boardsettings.h"
#include "gamesetupwindow.h"

class Board;

namespace Ui {
class PlayGameWindow;
}

class PlayGameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayGameWindow(const QVector<Player>& players,
                            QVector<BoardSettings>& boardsSettings,
                            QWidget *parent = nullptr);
    ~PlayGameWindow();

    QVariant getCurrPlayerSymbol();

    void addCurrPlayerScore(const int scoreAdd);

    void iteratePlayer();

    void highlightCurrPlayer();

private slots:
    void on_pushButton_back_clicked();

private:
    Ui::PlayGameWindow *ui;

    const QVector<Player> players;

    QVector<Board> boards;

    QGridLayout* table;

    QGridLayout* playersUI;

    int currPlayerIndex = 0;

    void addBoards();

    void addPlayers();

    void clearPlayerHighlight();

};

#endif // PLAYGAMEWINDOW_H
