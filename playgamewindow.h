#ifndef PLAYGAMEWINDOW_H
#define PLAYGAMEWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include "player.h"
#include "board.h"
#include "imageutils.h"

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

    const QVector<Player>& players;

    const QVector<Board>& boards;

    QGridLayout* table;
};

#endif // PLAYGAMEWINDOW_H
