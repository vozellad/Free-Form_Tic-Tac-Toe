#include "playersymboldialog.h"
#include "ui_playersymboldialog.h"

PlayerSymbolDialog::PlayerSymbolDialog(QString name,
                                       QLabel* newSymbolLabel,
                                       QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerSymbolDialog)
{
    ui->setupUi(this);

    ui->label_title->setText(ui->label_title->text() + name);

    symbolLabel = newSymbolLabel;
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
            QString::compare(newText, QString()) != 0) {
        symbolLabel->setText(newText);

    // if image, apply image
    } else if (ui->radioButton_image->isChecked() && !image.isNull()) {
        symbolLabel->setPixmap(QPixmap::fromImage(image.scaledToHeight(
            symbolLabel->height(), Qt::SmoothTransformation)));
        symbolLabel->show();
    }
}

