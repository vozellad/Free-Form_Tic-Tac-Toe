/*  Customized label to be used as a board space in a TicTacToe board.
 *  Inherets from SymbolLabel to properly use text or image.
 *  Resizes image with no progressive quality degradation as window resizes.
 */

#include "boardspacelabel.h"

BoardSpaceLabel::BoardSpaceLabel(QWidget* parent)
    : SymbolLabel(parent)
{
    isHover = true;
}

BoardSpaceLabel::~BoardSpaceLabel() {}

// Resizes symbol when window resizes
void BoardSpaceLabel::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    if (uiLoaded)  resizeSymbol();
}

// Waits for UI to load to allow resizing of symbol
void BoardSpaceLabel::showEvent(QShowEvent *event)
{
    QLabel::showEvent(event);

    uiLoaded = true;
}

// setImageSym is called within setSymbol.
void BoardSpaceLabel::resizeSymbol()
{
    QVariant symbol = getSymbol();
    if (symbol == "")  return;

    setSymbol("");
    setSymbol(symbol);
}

// Overwrites function to scale image before applying
void BoardSpaceLabel::setImageSym(QImage image)
{
    QImage scaledImage = QImage();
    const double reduceForSpacing = 0.9;

    // Scales based on larger dimension
    if (height() < width())
        scaledImage = image.scaledToHeight(
                    height() * reduceForSpacing, Qt::SmoothTransformation);
    else
        scaledImage = image.scaledToWidth(
                    width() * reduceForSpacing, Qt::SmoothTransformation);

    setPixmap(QPixmap::fromImage(scaledImage));
}
