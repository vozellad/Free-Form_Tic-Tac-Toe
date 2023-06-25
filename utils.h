#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QGridLayout>
#include <QVariant>
#include <QImage>
#include "imageutils.h"

void setGridWidth(QGridLayout* l, int width);

bool compareSymbols(QVariant sym1, QVariant sym2);

#endif // UTILS_H
