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

void setImageToLabel(const QImage& image, QLabel* label)
{
    label->setPixmap(QPixmap::fromImage(image.scaledToHeight(
        label->height(), Qt::SmoothTransformation)));
}

QImage getImageFromLabel(const QLabel* label)
{
    if (label->pixmap()->isNull())
        throw ImageNotFoundException();

    // IDE warning tells me to use other overload function
    // while docs tell me to use this overload function
    return label->pixmap()->toImage();
}

bool compareImages(const QImage& image1, const QImage& image2)
{
    if (image1.isNull() || image2.isNull())  return false;
    if (image1.size() != image2.size())  return false;

    for (int y = 0; y < image1.height(); ++y)
        for (int x = 0; x < image1.width(); ++x)
            // Compare QRgb color values of current pixel
            if (image1.pixel(x, y) != image2.pixel(x, y))  return false;

    return true;
}
