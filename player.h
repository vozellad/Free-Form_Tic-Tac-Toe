#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QVariant>

class Player
{
public:
    Player(QString name, QString symbol);

    Player(QString name, QPixmap symbol);

    QString getName();

    QVariant getSymbol();

private:
    QString name;

    QVariant symbol;
    // https://doc.qt.io/qt-6/qvariant.html
};

#endif // PLAYER_H
