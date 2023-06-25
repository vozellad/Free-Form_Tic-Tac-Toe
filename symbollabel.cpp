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

bool SymbolLabel::getIsHover() { return isHover; }

void SymbolLabel::setIsHover(bool b) { isHover = b; }

QVariant SymbolLabel::getSymbol()
{
    // Return image if image
    if (!unscaledImage.isNull())
        return unscaledImage;

    // Return text if text or return empty string if nothing
    return text();
}

void SymbolLabel::setTextSym(QString s) { setText(s); }

void SymbolLabel::setImageSym(QImage image)
{
    QImage scaledImage = image.scaledToHeight(
                height(), Qt::SmoothTransformation);
    const QPixmap pixmap = QPixmap::fromImage(scaledImage);
    setPixmap(pixmap);
}

void SymbolLabel::enterEvent(QEvent*)
{
    if (isHover && isEnabled())
        setStyleSheet("QLabel { background-color : gray; }");
}

void SymbolLabel::leaveEvent(QEvent*)
{
    if (isHover && isEnabled())
        setStyleSheet("");
}
