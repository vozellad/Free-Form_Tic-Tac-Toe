#ifndef PLAYERSYMBOLDIALOG_H
#define PLAYERSYMBOLDIALOG_H

#include <QFileDialog>
#include <QToolButton>

namespace Ui {
class PlayerSymbolDialog;
}

class PlayerSymbolDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerSymbolDialog(QToolButton* newSymbol,
                                QString name,
                                QWidget *parent = nullptr);
    ~PlayerSymbolDialog();

private slots:
    void on_pushButton_getImage_clicked();

    void on_buttonBox_accepted();

private:
    Ui::PlayerSymbolDialog *ui;

    QIcon image;
    QToolButton* symbol;
};

#endif // PLAYERSYMBOLDIALOG_H
