/* Utility for image handling */

#ifndef IMAGEUTILS_H
#define IMAGEUTILS_H

#include <QImage>
#include <QLabel>
#include <QException>

// Custom exception for when there's no image in a label
class ImageNotFoundException : public QException
{
public:
    void raise() const override;
    ImageNotFoundException* clone() const override;
    const char* what() const noexcept override;
};

void setImageToLabel(const QImage& image, QLabel* label);

QImage getImageFromLabel(const QLabel* label);

bool compareImages(const QImage& image1, const QImage& image2);

#endif // IMAGEUTILS_H
