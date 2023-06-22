#ifndef SYMBOLLABEL_H
#define SYMBOLLABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>
#include <QVariant>
#include "imageutils.h"

class SymbolLabel : public QLabel {
    Q_OBJECT

public:
    explicit SymbolLabel(QWidget* parent = Q_NULLPTR,
                         Qt::WindowFlags f = Qt::WindowFlags());
    explicit SymbolLabel(QVariant symbol,
                         QWidget* parent = Q_NULLPTR,
                         Qt::WindowFlags f = Qt::WindowFlags());
    ~SymbolLabel();

    void setSymbol(const QVariant symbol);

    QVariant getSymbol();

signals:
    void clicked();

protected:
    QImage unscaledImage;

    void mousePressEvent(QMouseEvent* event);

};

#endif // SYMBOLLABEL_H
