#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStyleFactory>

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

    //  Handles user incrementing "Number of boards" spin button (Free Form).
    void addBoard();

    //  Handles user decrementing "Number of boards" spin button (Free Form).
    void removeBoard();

private slots:
    void on_pushButton_freeForm_clicked();

    void on_pushButton_clicked();

    void on_spinBox_numberOfBoards_editingFinished();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
