#include "player.h"

Player::Player(const QString name, const QString symbol) :
    name(name), symbol(symbol) { }

Player::Player(const QString name, const QPixmap* symbol) :
    name(name), symbol(symbol) { }

QString Player::getName() const { return name; }

QVariant Player::getSymbol() const
{

}
