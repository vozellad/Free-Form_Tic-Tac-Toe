#ifndef PLAYERSYMBOLDIALOG_H
#define PLAYERSYMBOLDIALOG_H

#include <QFileDialog>

namespace Ui {
class PlayerSymbolDialog;
}

class PlayerSymbolDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerSymbolDialog(QWidget *parent = nullptr);
    ~PlayerSymbolDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PlayerSymbolDialog *ui;
};

#endif // PLAYERSYMBOLDIALOG_H
