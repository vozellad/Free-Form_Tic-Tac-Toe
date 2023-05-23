#ifndef PLAYERSYMBOLDIALOG_H
#define PLAYERSYMBOLDIALOG_H

#include <QFileDialog>
#include <QImageReader>
#include "clickablelabel.h"

namespace Ui {
class PlayerSymbolDialog;
}

class PlayerSymbolDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerSymbolDialog(ClickableLabel* newSymbol,
                                const QString name,
                                QWidget *parent = nullptr);
    ~PlayerSymbolDialog();

private slots:
    void on_pushButton_getImage_clicked();

    void on_buttonBox_accepted();

    void on_lineEdit_text_textEdited();

private:
    Ui::PlayerSymbolDialog *ui;

    QImage image;

    ClickableLabel* symbol;

    void markGetImageButton(const QString appendedText = "");
};

#endif // PLAYERSYMBOLDIALOG_H
