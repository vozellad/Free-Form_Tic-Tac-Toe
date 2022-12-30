#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStyleFactory>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Mutators

    //
    int changeAmt(int currAmt,
                  int newAmt,
                  void (MainWindow::*add)(),
                  void (MainWindow::*subtract)());

    void addPlayer();

    void removePlayer();

    //  Handles user incrementing "Number of boards" spin button (Free Form).
    void addBoard();

    //  Handles user decrementing "Number of boards" spin button (Free Form).
    void removeBoard();

    // Remove layout and its contents.
    void removeLayout(QLayoutItem* layout);

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_clicked();

    void on_spinBox_numberOfBoards_editingFinished();

    void on_spinBox_numberOfPlayers_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
