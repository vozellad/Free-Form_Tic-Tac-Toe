/* Used to hold player settings in an object to be passed around easily */

#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QVariant>

struct Player
{
    const QString name;
    const QVariant symbol;
};

#endif // PLAYER_H
