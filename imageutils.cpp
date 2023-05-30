#include "imageutils.h"

void ImageNotFoundException::raise() const { throw *this; }

ImageNotFoundException* ImageNotFoundException::clone() const
{
    return new ImageNotFoundException(*this);
}

const char* ImageNotFoundException::what() const noexcept
{
    return "Image not found in the label. Is there text instead?";
}

void setImageToLabel(QImage image, QLabel* label)
{
    label->setPixmap(QPixmap::fromImage(image.scaledToHeight(
        label->height(), Qt::SmoothTransformation)));
}

QImage getImageFromLabel(QLabel* label)
{
    if (label->pixmap() == nullptr)
        throw ImageNotFoundException();

    return label->pixmap()->toImage();
}
