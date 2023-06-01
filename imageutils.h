#ifndef IMAGEUTILS_H
#define IMAGEUTILS_H

#include <QImage>
#include <QLabel>
#include <QException>

class ImageNotFoundException : public QException
{
public:
    void raise() const override;
    ImageNotFoundException* clone() const override;
    const char* what() const noexcept override;
};

void setImageToLabel(const QImage& image, QLabel* label);

QImage getImageFromLabel(const QLabel* label);

#endif // IMAGEUTILS_H
