#include "playersymboldialog.h"
#include "ui_playersymboldialog.h"

// TODO: when select textbox, select radio for it; when select imagebutton, select radio for it
// OPTIONS??
PlayerSymbolDialog::PlayerSymbolDialog(ClickableLabel* newSymbol,
                                       QString name,
                                       QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerSymbolDialog),
    symbol(newSymbol)
{
    ui->setupUi(this);

    ui->label_title->setText(ui->label_title->text() + name);
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

    if (QString::compare(filename, QString()) != 0)
        image.load(filename);
}

void PlayerSymbolDialog::on_buttonBox_accepted()
{
    QString newText = ui->lineEdit_text->text();

    // if text, apply text
    if (ui->radioButton_text->isChecked() &&
            QString::compare(newText, QString()) != 0)
        symbol->setText(newText);

    // if image, apply image
    else if (ui->radioButton_image->isChecked() && !image.isNull()) {
        symbol->setPixmap(QPixmap::fromImage(image.scaledToHeight(
            symbol->height(), Qt::SmoothTransformation)));
        symbol->show();
    }
}

