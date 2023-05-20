#ifndef PLAYERSYMBOLDIALOG_H
#define PLAYERSYMBOLDIALOG_H

#include <QFileDialog>
#include <QLabel>

namespace Ui {
class PlayerSymbolDialog;
}

class PlayerSymbolDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerSymbolDialog(QString name,
                                QLabel* symbolLabel,
                                QWidget *parent = nullptr);
    ~PlayerSymbolDialog();

private slots:
    void on_pushButton_getImage_clicked();

    void on_buttonBox_accepted();

private:
    Ui::PlayerSymbolDialog *ui;

    QImage image;
    QLabel* symbolLabel;
};

#endif // PLAYERSYMBOLDIALOG_H
