/*  Customized label to hold either text or an image.
 *  This label has a click and a hover listener.
 *  It holds the unscaled image for it to be retrieved in uncompressed quality.
 */

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

    // Like setText but allows for an image
    void setSymbol(const QVariant symbol);

    QVariant getSymbol();

    bool getIsHover();

    void setIsHover(bool b);

signals:
    void clicked();

protected:
    // If the symbol is an image, the original quality
    // is held here to be retrieved later
    QImage unscaledImage;

    // Whether to highlight label on hover
    bool isHover = true;

    void mousePressEvent(QMouseEvent* event);

    virtual void setTextSym(QString s);

    virtual void setImageSym(QImage image);

    // Highlights on hover
    void enterEvent(QEvent* ev) override;

    // Un-highlights when leaving hover
    void leaveEvent(QEvent* ev) override;

};

#endif // SYMBOLLABEL_H
