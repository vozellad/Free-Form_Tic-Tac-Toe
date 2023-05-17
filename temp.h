#ifndef TEMP_H
#define TEMP_H

#include <QMainWindow>
#include <QStyleFactory>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Temp; }
QT_END_NAMESPACE

class Temp : public QMainWindow
{
    Q_OBJECT

public:
    Temp(QWidget *parent = nullptr);
    ~Temp();

    // Mutators

    //
    int changeAmt(int currAmt,
                  int newAmt,
                  void (Temp::*add)(),
                  void (Temp::*subtract)());

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
    Ui::Temp *ui;
};
#endif // TEMP_H
