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

    ui->label_title->setText(ui->label_title->text() + name);

    ui->radioButton_text->setChecked(true);
}

PlayerSymbolDialog::~PlayerSymbolDialog()
{
    delete ui;
}

void PlayerSymbolDialog::on_pushButton_getImage_clicked()
{
    QString imageExtOptions = "Images (*.png *.jpg *.jpeg *.bmp *.gif)";
    QString filename =
            QFileDialog::getOpenFileName(this, "Choose", imageExtOptions);

    if (QString::compare(filename, QString()) != 0) {
        image.load(filename);

        ui->radioButton_text->setChecked(false);
        ui->radioButton_image->setChecked(true);
    }
}

void PlayerSymbolDialog::on_buttonBox_accepted()
{
    QString newText = ui->lineEdit_text->text();

    // if text, apply text
    if (ui->radioButton_text->isChecked() &&
            QString::compare(newText, QString()) != 0)
        symbol->setText(newText);

    // if image, apply image
    else if (!image.isNull())
        symbol->setPixmap(QPixmap::fromImage(image.scaledToHeight(
            symbol->height(), Qt::SmoothTransformation)));
}

void PlayerSymbolDialog::on_lineEdit_text_textEdited()
{
    ui->radioButton_text->setChecked(true);
    ui->radioButton_image->setChecked(false);
}

