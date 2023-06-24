#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QGridLayout>
#include <QVariant>
#include <QImage>
#include "imageutils.h"

void setGridWidth(QGridLayout* l, const int width);

bool compareSymbols(QVariant sym1, QVariant sym2);

template <typename T>
T getWidget(QGridLayout* l, const int i);

template <typename T>
T getWidget(QGridLayout* l, const int row, const int col);

#endif // UTILS_H
