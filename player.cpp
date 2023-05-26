#include "player.h"

Player::Player(QString name, QString symbol) :
    name(name), symbol(symbol) { }

Player::Player(QString name, QPixmap symbol) :
    name(name), symbol(symbol) { }

QString Player::getName() { return name; }

QVariant Player::getSymbol()
{

}
