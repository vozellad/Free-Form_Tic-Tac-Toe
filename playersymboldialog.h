/*  In this dialog window, the user can specify exactly what they want the
 *  symbol to be. It can be text or an image that they upload.
 */

#ifndef PLAYERSYMBOLDIALOG_H
#define PLAYERSYMBOLDIALOG_H

#include <QFileDialog>
#include <QImageReader>
#include "symbollabel.h"
#include "imageutils.h"
#include "errordialog.h"

namespace Ui {
class PlayerSymbolDialog;
}

class PlayerSymbolDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerSymbolDialog(const QString name,
                                SymbolLabel* newSymbol,
                                QWidget *parent = nullptr);
    ~PlayerSymbolDialog();

private slots:
    // Prompts user for image
    void on_pushButton_getImage_clicked();

    // Applies new selected symbol
    void on_buttonBox_accepted();

    // Selects radio button for text if text is modified
    void on_lineEdit_text_textEdited();

private:
    Ui::PlayerSymbolDialog *ui;

    // Takes image then later applies it when user presses OK
    QImage image;

    // Writes new symbol to this element
    SymbolLabel* symbol;

    // Writes to text of Get Image button
    // to let user know the state of retrieving image.
    // To reset it, call with no parameter.
    void markGetImageButton(const QString appendedText = "");
};

#endif // PLAYERSYMBOLDIALOG_H
