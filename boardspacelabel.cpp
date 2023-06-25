#include "boardspacelabel.h"

BoardSpaceLabel::BoardSpaceLabel(QWidget* parent)
    : SymbolLabel(parent)
{

}

BoardSpaceLabel::~BoardSpaceLabel() {}

void BoardSpaceLabel::setTextSym(QString s)
{
    setText(s);return;

    QFont defaultFont = QApplication::font();
    QString fontFamily = defaultFont.family();

    int fontSize = 200;

    QFont font(fontFamily);
    font.setPointSize(fontSize);
    setFont(font);

    QFontMetrics metrics(font);

    // Decrease the font size until the text fits within the label
    //auto hi1 = metrics.width(txt);
    //auto hi2 = width();
    while (metrics.width(text()) > width() || metrics.height() > height()) {
        fontSize--;
        font.setPointSize(fontSize);
        metrics = QFontMetrics(font);
    }

    setText(s);

    font.setPointSize(fontSize);
    setFont(font);
}

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

void BoardSpaceLabel::enterEvent(QEvent*)
{
    if (isEnabled())
        setStyleSheet("QLabel { background-color : gray; }");
}

void BoardSpaceLabel::leaveEvent(QEvent*)
{
    if (isEnabled())
        setStyleSheet("");
}
