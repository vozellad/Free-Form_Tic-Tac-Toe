#ifndef GAMESETUPWINDOW_H
#define GAMESETUPWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QFileDialog>
#include <QSpacerItem>
#include <QLineEdit>
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

private:
    Ui::GameSetupWindow *ui;

    QGridLayout* players;
    // TODO: might need to store playerSymbol images

    int getPlayerAmt();
    void setPlayerAmt(int newPlayerAmt);
    void setButtonStates();
    void deleteLastGridItem(QGridLayout* l);
    void reAdjustGridSize(QGridLayout* l);
    void addInitialPlayers();
};

#endif // GAMESETUPWINDOW_H
