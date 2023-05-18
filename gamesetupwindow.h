#ifndef GAMESETUPWINDOW_H
#define GAMESETUPWINDOW_H

#include <QMainWindow>

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

    void on_pushButton_startGame_clicked();

    void on_spinBox_playerAmt_valueChanged(int newPlayerAmt);

private:
    Ui::GameSetupWindow *ui;
    //QGridLayout* playerSetup = ui->gridLayout_playerSetup;

    void addPlayer();

    void removePlayer();
};

#endif // GAMESETUPWINDOW_H
