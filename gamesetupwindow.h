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

private:
    Ui::GameSetupWindow *ui;
};

#endif // GAMESETUPWINDOW_H
