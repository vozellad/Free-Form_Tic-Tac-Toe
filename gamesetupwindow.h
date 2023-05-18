#ifndef GAMESETUPWINDOW_H
#define GAMESETUPWINDOW_H

#include <QMainWindow>
#include <QGridLayout>

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

    void on_spinBox_playerAmt_editingFinished();

private:
    Ui::GameSetupWindow *ui;
    QGridLayout* players;

    void addPlayer();

    void removePlayer();

    void removeLastInLayout(QLayout* layout);
};

#endif // GAMESETUPWINDOW_H
