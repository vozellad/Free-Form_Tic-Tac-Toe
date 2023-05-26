#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QVariant>

class Player
{
public:
    Player(const QString name, const QString symbol);

    Player(const QString name, const QPixmap* symbol);

    QString getName() const;

    QVariant getSymbol() const;

private:
    const QString name;

    const QVariant symbol;
    // https://doc.qt.io/qt-6/qvariant.html
};

#endif // PLAYER_H
