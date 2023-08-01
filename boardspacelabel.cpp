#include "boardspacelabel.h"

BoardSpaceLabel::BoardSpaceLabel(QWidget* parent)
    : SymbolLabel(parent)
{
    isHover = true;
    initSounds();
}

BoardSpaceLabel::~BoardSpaceLabel() {}

void BoardSpaceLabel::setImageSym(QImage image)
{
    QImage scaledImage = QImage();
    const double reduceForSpacing = 0.9;

    if (height() < width())
        scaledImage = image.scaledToHeight(
                    height() * reduceForSpacing, Qt::SmoothTransformation);
    else
        scaledImage = image.scaledToWidth(
                    width() * reduceForSpacing, Qt::SmoothTransformation);

    setPixmap(QPixmap::fromImage(scaledImage));
}

void BoardSpaceLabel::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    if (uiLoaded)  resizeSymbol();
}

void BoardSpaceLabel::showEvent(QShowEvent *event)
{
    QLabel::showEvent(event);

    uiLoaded = true;
}

void BoardSpaceLabel::resizeSymbol()
{
    QVariant symbol = getSymbol();
    if (symbol == "")  return;

    setSymbol("");
    setSymbol(symbol);
}

void BoardSpaceLabel::initSounds()
{
    hoverSound->setMedia(QUrl("qrc:/sounds/muted-bell.flac"));
    clickSound->setMedia(QUrl("qrc:/sounds/error.wav"));
}

void BoardSpaceLabel::mousePressEvent(QMouseEvent* event)
{
    SymbolLabel::mousePressEvent(event);
    clickSound->play();
}

void BoardSpaceLabel::enterEvent(QEvent* event)
{
    SymbolLabel::enterEvent(event);
    hoverSound->play();
}
