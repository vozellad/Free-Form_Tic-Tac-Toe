#ifndef SYMBOLLABEL_H
#define SYMBOLLABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>
#include <QVariant>

class SymbolLabel : public QLabel {
    Q_OBJECT

public:
    explicit SymbolLabel(bool isHover = true, QWidget* parent = Q_NULLPTR);
    explicit SymbolLabel(QVariant symbol,
                         bool isHover = true,
                         QWidget* parent = Q_NULLPTR);
    ~SymbolLabel();

    void setSymbol(const QVariant symbol);

    QVariant getSymbol();

    bool getIsHover();

    void setIsHover(bool b);

signals:
    void clicked();

protected:
    QImage unscaledImage;

    bool isHover = true;

    void mousePressEvent(QMouseEvent* event);

    virtual void setTextSym(QString s);

    virtual void setImageSym(QImage image);

    void enterEvent(QEvent* ev) override;

    void leaveEvent(QEvent* event) override;

};

#endif // SYMBOLLABEL_H
