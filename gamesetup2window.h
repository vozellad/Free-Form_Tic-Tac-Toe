#ifndef GAMESETUP2WINDOW_H
#define GAMESETUP2WINDOW_H

#include <QMainWindow>

namespace Ui {
class GameSetup2Window;
}

class GameSetup2Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameSetup2Window(QWidget *parent = nullptr);
    ~GameSetup2Window();

private slots:
    // Go to previous page
    void on_pushButton_back_clicked();

private:
    Ui::GameSetup2Window *ui;
};

#endif // GAMESETUP2WINDOW_H
