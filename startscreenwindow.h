/*  This window welcomes the user to the application
 *  and waits for the user to start the application.
 */

#ifndef STARTSCREENWINDOW_H
#define STARTSCREENWINDOW_H

#include <QMainWindow>

#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>
#include <QGuiApplication>

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
    // Go to next window
    void on_pushButton_start_clicked();

private:
    Ui::StartScreenWindow *ui;
};

#endif // STARTSCREENWINDOW_H
