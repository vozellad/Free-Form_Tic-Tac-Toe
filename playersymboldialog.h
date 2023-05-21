#ifndef PLAYERSYMBOLDIALOG_H
#define PLAYERSYMBOLDIALOG_H

#include <QFileDialog>
#include "clickablelabel.h"

namespace Ui {
class PlayerSymbolDialog;
}

class PlayerSymbolDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerSymbolDialog(ClickableLabel* newSymbol,
                                QString name,
                                QWidget *parent = nullptr);
    ~PlayerSymbolDialog();

private slots:
    void on_pushButton_getImage_clicked();

    void on_buttonBox_accepted();

private:
    Ui::PlayerSymbolDialog *ui;

    QImage image;
    ClickableLabel* symbol;
};

#endif // PLAYERSYMBOLDIALOG_H
