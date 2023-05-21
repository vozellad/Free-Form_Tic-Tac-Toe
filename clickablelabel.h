#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <QtWidgets>  // TODO: which one to keep?

class ClickableLabel : public QLabel
{
    Q_OBJECT  // TODO: keep?

public:
    explicit ClickableLabel(QWidget* parent = nullptr) : QLabel(parent) {}

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event) override
    {
        if (event->button() == Qt::LeftButton)
        {
            emit clicked();
        }
    }
};

#endif // CLICKABLELABEL_H
