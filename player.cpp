#include "player.h"

Player::Player(const QString name, const QVariant symbol) :
    name(name), symbol(symbol) { }

QString Player::getName() const { return name; }

QObject Player::getSymbol()  // TODO: change class from variant
{
    if (symbol.canConvert<QString>())
        return symbol.toString();

    return symbol.value<QImage>();
}
