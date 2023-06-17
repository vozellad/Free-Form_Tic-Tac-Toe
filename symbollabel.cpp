#include "symbollabel.h"

SymbolLabel::SymbolLabel(QWidget* parent,
                         Qt::WindowFlags f)
    : QLabel(parent)
{
}

SymbolLabel::SymbolLabel(QVariant symbol,
                         QWidget* parent,
                         Qt::WindowFlags f)
    : QLabel(parent)
{
    setSymbol(symbol);
}

SymbolLabel::~SymbolLabel() {}

void SymbolLabel::mousePressEvent(QMouseEvent* event)
{
    emit clicked();
}

void SymbolLabel::setSymbol(const QVariant symbol)
{
    if (symbol.isNull())
        throw std::invalid_argument("Symbol is null.");

    else if (symbol.canConvert<QString>()) {
        // TODO
        setText(symbol.value<QString>());
        unscaledImage = QImage();
    }

    else if (symbol.canConvert<QImage>()) {
        // TODO
        QImage image = symbol.value<QImage>();

        QImage scaledImage = image.scaledToHeight(
                    height(), Qt::SmoothTransformation);
        const QPixmap pixmap = QPixmap::fromImage(scaledImage);
        setPixmap(pixmap);

        unscaledImage = image;
    }

    else
        throw std::invalid_argument("Symbol must be QString or QImage.");
}

QVariant SymbolLabel::getSymbol()
{
    // Return image if image
    if (!unscaledImage.isNull())
        return unscaledImage;

    // Return text if text or return empty string if nothing
    return text();
}
