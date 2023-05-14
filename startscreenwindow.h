#ifndef STARTSCREENWINDOW_H
#define STARTSCREENWINDOW_H

#include <QMainWindow>
#include "gamesetupwindow.h"

namespace Ui {
class StartScreenWindow;
}

class StartScreenWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartScreenWindow(QWidget *parent = nullptr);
    ~StartScreenWindow();

private slots:
    // Hide current window. Go to GameSetupWindow.
    void on_pushButton_start_clicked();

private:
    Ui::StartScreenWindow *ui;
};

#endif // STARTSCREENWINDOW_H
