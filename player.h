#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QImage>
#include <QVariant>

class Player
{
public:
    Player(const QString name, const QVariant symbol);

    QString getName() const;

    QObject getSymbol();

private:
    const QString name;

    const QVariant symbol;
};

#endif // PLAYER_H
