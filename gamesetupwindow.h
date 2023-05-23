#ifndef GAMESETUPWINDOW_H
#define GAMESETUPWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QFileDialog>
#include <QSpacerItem>
#include <QLineEdit>
#include "startscreenwindow.h"
#include "playersymboldialog.h"
#include "clickablelabel.h"

namespace Ui {
class GameSetupWindow;
}

class GameSetupWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameSetupWindow(QWidget *parent = nullptr);
    ~GameSetupWindow();

private slots:
    // Go to previous window
    void on_pushButton_back_clicked();

    // Go to next window
    void on_pushButton_startGame_clicked();

    void on_toolButton_addPlayer_clicked();

    void on_toolButton_removePlayer_clicked();

    void on_playerSymbol_clicked(ClickableLabel* symbol, QString name);

    void on_toolButton_addBoard_clicked();

    void on_toolButton_removeBoard_clicked();

private:
    Ui::GameSetupWindow *ui;

    QGridLayout* players;

    QVBoxLayout* boards;

    int getPlayerAmt();

    void setPlayerAmt(int newPlayerAmt);

    void setAmtModBtnStates_players();

    void deleteLastItem(QLayout* l);

    void reAdjustGridSize(QGridLayout* l);

    void addInitialPlayers();

    int getBoardAmt();

    void setBoardAmt(int newBoardAmt);

    void setAmtModBtnStates_boards();
};

#endif // GAMESETUPWINDOW_H
