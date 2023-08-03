/*  Customized label to hold either text or an image.
 *  This label has a click and a hover listener.
 *  It holds the unscaled image for it to be retrieved in uncompressed quality.
 */

#include "symbollabel.h"

SymbolLabel::SymbolLabel(bool hoverEvent, QWidget* parent) : QLabel(parent)
{
    isHover = hoverEvent;
}

SymbolLabel::SymbolLabel(QVariant symbol, bool hoverEvent, QWidget* parent)
    : QLabel(parent)
{
    setSymbol(symbol);
    isHover = hoverEvent;
}

SymbolLabel::~SymbolLabel() {}

void SymbolLabel::mousePressEvent(QMouseEvent*)
{
    emit clicked();
}

// Like setText but allows for an image
void SymbolLabel::setSymbol(const QVariant symbol)
{
    if (symbol.isNull()) throw std::invalid_argument("Symbol is null.");

    else if (symbol.canConvert<QString>()) {
        setTextSym(symbol.value<QString>());
        unscaledImage = QImage();
    }

    else if (symbol.canConvert<QImage>()) {
        QImage image = symbol.value<QImage>();
        setImageSym(image);
        unscaledImage = image;
    }

    else throw std::invalid_argument("Symbol must be QString or QImage.");
}

QVariant SymbolLabel::getSymbol()
{
    // Return image if image
    if (!unscaledImage.isNull())
        return unscaledImage;

    // Return text if text or return empty string if nothing
    return text();
}

bool SymbolLabel::getIsHover() { return isHover; }

void SymbolLabel::setIsHover(bool b) { isHover = b; }

// Used in setSymbol
void SymbolLabel::setTextSym(QString s) { setText(s); }

// Used in setSymbol
void SymbolLabel::setImageSym(QImage image)
{
    QImage scaledImage = image.scaledToHeight(
                height(), Qt::SmoothTransformation);
    const QPixmap pixmap = QPixmap::fromImage(scaledImage);
    setPixmap(pixmap);
}

// Highlights on hover
void SymbolLabel::enterEvent(QEvent*)
{
    if (isHover && isEnabled())
        setStyleSheet("QLabel { background-color : gray; }");
}

// Un-highlights when leaving hover
void SymbolLabel::leaveEvent(QEvent*)
{
    if (isHover && isEnabled())
        setStyleSheet("");
}
