#ifndef SYMBOLLABEL_H
#define SYMBOLLABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>
#include <QVariant>

class SymbolLabel : public QLabel {
    Q_OBJECT

public:
    explicit SymbolLabel(QWidget* parent = Q_NULLPTR,
                            Qt::WindowFlags f = Qt::WindowFlags());
    ~SymbolLabel();

    void setSymbol(const QVariant& symbol);

    QVariant getSymbol();

signals:
    void clicked();

    void resized();

protected:
    void mousePressEvent(QMouseEvent* event);

    void resizeEvent(QResizeEvent *event) override;

private:
    QImage unscaledImage;

    void updateSize();

};

#endif // SYMBOLLABEL_H
