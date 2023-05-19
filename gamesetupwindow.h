#ifndef GAMESETUPWINDOW_H
#define GAMESETUPWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QFileDialog>
#include <QSpacerItem>
#include <QLineEdit>

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

private:
    Ui::GameSetupWindow *ui;

    QGridLayout* players;
    QLabel* playerAmt;

    int getPlayerAmt();
    void setPlayerAmt(int newPlayerAmt);
    void setButtonStates();
    void deleteLastGridItem(QGridLayout* l);
    void addInitialPlayers();
    void reAdjustGridSize(QGridLayout* l);
};

#endif // GAMESETUPWINDOW_H
