#include "symbollabel.h"

SymbolLabel::SymbolLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent)
{ }

SymbolLabel::~SymbolLabel() {}

void SymbolLabel::mousePressEvent(QMouseEvent* event)
{
    emit clicked();
}

void SymbolLabel::setSymbol(const QVariant& symbol)
{
    std::string errorMessage = "Symbol must be QString or QImage.";

    if (symbol.isNull())
        throw std::invalid_argument(errorMessage);

    else if (symbol.canConvert<QString>()) {
        setText(symbol.value<QString>());
        unscaledImage = QImage();
    }

    else if (symbol.canConvert<QImage>()) {
        QImage image = symbol.value<QImage>();

        QImage scaledImage = image.scaledToHeight(height(),
                                      Qt::SmoothTransformation);
        const QPixmap pixmap = QPixmap::fromImage(scaledImage);
        setPixmap(pixmap);

        unscaledImage = image;
    }

    else
        throw std::invalid_argument(errorMessage);
}

QVariant SymbolLabel::getSymbol()
{
    // Return image if image
    if (!unscaledImage.isNull())
        return unscaledImage;

    // Return text if text or return empty string if nothing
    return text();
}
