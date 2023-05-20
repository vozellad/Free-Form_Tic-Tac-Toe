#include "playersymboldialog.h"
#include "ui_playersymboldialog.h"

PlayerSymbolDialog::PlayerSymbolDialog(QString name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerSymbolDialog)
{
    ui->setupUi(this);

    ui->label_title->setText(ui->label_title->text() + name);
}

PlayerSymbolDialog::~PlayerSymbolDialog()
{
    delete ui;
}

void PlayerSymbolDialog::on_pushButton_clicked()
{
    QString imgExtOptions = "Images (*.png *.jpg *.jpeg *.bmp *.gif)";
    QString filename =
            QFileDialog::getOpenFileName(this, "Choose", imgExtOptions);

    QImage img;
    if (QString::compare(filename, QString()) != 0 && img.load(filename)) {
        //img = img.scaledToWidth(/*label width*/, Qt::SmoothTransformation);
        // add image to label
    }
}

