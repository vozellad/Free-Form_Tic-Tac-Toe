#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QVariant>

struct Player  // TODO: what if make class then in constructor give error if symbol can't cast to QString or QImage?
{
    const QString name;
    const QVariant symbol;
};

#endif // PLAYER_H
