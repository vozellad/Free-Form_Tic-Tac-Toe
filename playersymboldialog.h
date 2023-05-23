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
    // Prompt user for image
    // Select radio button for image if image is given
    void on_pushButton_getImage_clicked();

    // Apply new selected symbol
    void on_buttonBox_accepted();

    // Select radio button for text if text is modified
    void on_lineEdit_text_textEdited();

private:
    Ui::PlayerSymbolDialog *ui;

    // Take image then later apply it when user presses OK
    QImage image;

    // Write new symbol to this element
    ClickableLabel* symbol;

    // Write to text of Get Image button
    // to let user know the state of retrieving image.
    // No parameter resets the button text.
    void markGetImageButton(const QString appendedText = "");
};

#endif // PLAYERSYMBOLDIALOG_H
