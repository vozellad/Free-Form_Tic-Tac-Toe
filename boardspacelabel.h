#ifndef BOARDSPACELABEL_H
#define BOARDSPACELABEL_H

#include <QWidget>
#include <Qt>
#include <QVariant>
#include <QApplication>
#include <QtMultimedia>
#include "symbollabel.h"

class BoardSpaceLabel : public SymbolLabel {
    Q_OBJECT

public:
    explicit BoardSpaceLabel(QWidget* parent = Q_NULLPTR);
    ~BoardSpaceLabel();

signals:
    void resized();

protected:
    void resizeEvent(QResizeEvent *event) override;

    void showEvent(QShowEvent *event) override;

private:
    bool uiLoaded = false;

    QMediaPlayer* hoverSound = new QMediaPlayer();

    QMediaPlayer* clickSound = new QMediaPlayer();

    void resizeSymbol();

    void setImageSym(QImage image) override;

    void initSounds();

    void mousePressEvent(QMouseEvent* event) override;

    void enterEvent(QEvent* event) override;

};

#endif // BOARDSPACELABEL_H
