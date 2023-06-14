#include "playsymbollabel.h"

PlaySymbolLabel::PlaySymbolLabel(QWidget* parent, Qt::WindowFlags f)
    : SymbolLabel(parent)
{

}

PlaySymbolLabel::~PlaySymbolLabel() {}

void PlaySymbolLabel::setSymbol(const QVariant& symbol)
{
    setText(symbol.value<QString>());
    unscaledImage = QImage();
    return;
    //SymbolLabel::setSymbol(symbol);

    if (symbol.isNull())
        throw std::invalid_argument("Symbol is null.");

    else if (symbol.canConvert<QString>()) {
        QString txt = symbol.value<QString>();
        setText(txt);

        QFont defaultFont = QApplication::font();
        QString fontFamily = defaultFont.family();

        int fontSize = 200;

        QFont font(fontFamily);
        font.setPointSize(fontSize);
        setFont(font);

        QFontMetrics metrics(font);

        // Decrease the font size until the text fits within the label
        auto hi1 = metrics.width(txt);
        auto hi2 = width();
        while (metrics.width(text()) > width() || metrics.height() > height()) {
            fontSize--;
            font.setPointSize(fontSize);
            metrics = QFontMetrics(font);
        }

        setText(txt);

        font.setPointSize(fontSize);
        setFont(font);

        unscaledImage = QImage();
    }

    else if (symbol.canConvert<QImage>()) {
        // TODO: base class splits this function so that this scope of code can be isolated to inheret

        QImage image = symbol.value<QImage>();
        QImage scaledImage = QImage();
        //scaledImage = image.scaledToHeight(
        //            height(), Qt::SmoothTransformation);
        const double reduceForSpacing = 0.9;

        if (height() < width())
            scaledImage = image.scaledToHeight(
                        height() * reduceForSpacing, Qt::SmoothTransformation);
        else
            scaledImage = image.scaledToWidth(
                        width() * reduceForSpacing, Qt::SmoothTransformation);

        setPixmap(QPixmap::fromImage(scaledImage));

        unscaledImage = image;
    }

    else
        throw std::invalid_argument("Symbol must be QString or QImage.");
}

void PlaySymbolLabel::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    if (uiLoaded)  resizeSymbol();
}

void PlaySymbolLabel::showEvent(QShowEvent *event)
{
    QLabel::showEvent(event);

    uiLoaded = true;
}

void PlaySymbolLabel::resizeSymbol()
{
    QVariant symbol = getSymbol();
    if (symbol == "")  return;

    setSymbol("");
    setSymbol(symbol);
}
