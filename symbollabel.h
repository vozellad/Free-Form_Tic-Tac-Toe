#ifndef SYMBOLLABEL_H
#define SYMBOLLABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>
#include <QVariant>

class SymbolLabel : public QLabel {
    Q_OBJECT

public:
    explicit SymbolLabel(QWidget* parent = Q_NULLPTR);
    explicit SymbolLabel(QVariant symbol, QWidget* parent = Q_NULLPTR);
    ~SymbolLabel();

    void setSymbol(const QVariant symbol);

    QVariant getSymbol();

signals:
    void clicked();

protected:
    QImage unscaledImage;

    void mousePressEvent(QMouseEvent* event);

    virtual void setTextSym(QString s);

    virtual void setImageSym(QImage image);

};

#endif // SYMBOLLABEL_H
