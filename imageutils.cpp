#include "imageutils.h"

void setImageToLabel(QImage image, QLabel label)
{
    label->setPixmap(QPixmap::fromImage(image.scaledToHeight(
        label->height(), Qt::SmoothTransformation)));
}

QImage getImageFromLabel(QLabel label)
{
    return label->pixmap()->toImage();
}
