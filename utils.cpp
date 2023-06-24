#include "utils.h"

void setGridWidth(QGridLayout* l, const int width)
{
    // TODO: test for 0 in unit test
    l->setColumnMinimumWidth(width - 1, 0);
    l->setColumnStretch(width - 1, 0);
}

bool compareSymbols(QVariant sym1, QVariant sym2)
{
    // TODO: change to be like ifs or one return?

    // Check if same datatype
    if (sym1.userType() != sym2.userType())  return false;

    return  // Compare as string
            (sym1.userType() == QMetaType::QString &&
            sym1.value<QString>() == sym2.value<QString>()) ||
            // Compare as image
            (sym1.userType() == QMetaType::QImage &&
            compareImages(sym1.value<QImage>(), sym2.value<QImage>()));
}
