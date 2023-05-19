#include "playersymboldialog.h"
#include "ui_playersymboldialog.h"

PlayerSymbolDialog::PlayerSymbolDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerSymbolDialog)
{
    ui->setupUi(this);
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

