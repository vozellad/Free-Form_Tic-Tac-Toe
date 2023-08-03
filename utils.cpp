/* Utility functions available to any file in project */

#include "utils.h"

// Used before inserting items in grid to not have to specify
// positional values
void setGridWidth(QGridLayout* l, int width)
{
    l->setColumnMinimumWidth(width - 1, 0);
    l->setColumnStretch(width - 1, 0);
}

// Compares symbols of either text or image
bool compareSymbols(QVariant sym1, QVariant sym2)
{
    // Compare datatypes
    if (sym1.userType() != sym2.userType())
        return false;

    // Compare as string
    if (sym1.userType() == QMetaType::QString &&
            sym1.value<QString>() == sym2.value<QString>())
        return true;

    // Compare as image
    return sym1.userType() == QMetaType::QImage &&
            compareImages(sym1.value<QImage>(), sym2.value<QImage>());
}

void setLabelBackgroundColor(QLabel* label, QColor color)
{
    label->setStyleSheet("");

    QPalette palette = label->palette();
    palette.setColor(QPalette::Background, color);
    label->setAutoFillBackground(true);

    label->setPalette(palette);
}
