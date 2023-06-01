#include "playersymboldialog.h"
#include "ui_playersymboldialog.h"

PlayerSymbolDialog::PlayerSymbolDialog(ClickableLabel* newSymbol,
                                       QString name,
                                       QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerSymbolDialog),
    symbol(newSymbol)
{
    ui->setupUi(this);

    // Give large text the player name
    ui->label_title->setText(ui->label_title->text() + name);

    // Default to text
    ui->radioButton_text->setChecked(true);
}

PlayerSymbolDialog::~PlayerSymbolDialog()
{
    delete ui;
}

// Prompt user for image, verify it is a valid image,
// save image for later use, and check image radio button
void PlayerSymbolDialog::on_pushButton_getImage_clicked()
{
    // Prompt user for image
    const QString filename =
            QFileDialog::getOpenFileName(this, ui->label_explanation->text());

    // If filepath is empty
    if (QString::compare(filename, QString()) == 0)
        markGetImageButton("No file");

    // If file isn't usable as image
    else if (QImageReader::imageFormat(filename) == "")
        markGetImageButton("Not an image");

    // If image is valid
    else {
        markGetImageButton("Image selected");

        // Save image
        image.load(filename);

        // Check image radio button
        ui->radioButton_text->setChecked(false);
        ui->radioButton_image->setChecked(true);
    }
}

// When user clicks OK, check whether text or image is chosen and pass value
// of checked option
void PlayerSymbolDialog::on_buttonBox_accepted()
{
    // Get new text symbol
    const QString newText = ui->lineEdit_text->text();

    // If text, apply text
    if (ui->radioButton_text->isChecked() &&
            QString::compare(newText, QString()) != 0)
        symbol->setText(newText);

    // If image, apply image
    else if (!image.isNull())
        setImageToLabel(image, symbol);
}

// When user modifies text symbol, check text radio button
void PlayerSymbolDialog::on_lineEdit_text_textEdited()
{
    ui->radioButton_text->setChecked(true);
    ui->radioButton_image->setChecked(false);
}

// Write to text of Get Image button
// to let user know the state of retrieving image
// No parameter resets the button text.
void PlayerSymbolDialog::markGetImageButton(const QString appendedText)
{
    QPushButton* b = ui->pushButton_getImage;
    const static QString bText = b->text();

    appendedText == "" ? b->setText(bText) :
                         b->setText(bText + " (" + appendedText + ")");
}

