#ifndef BOARDSPACELABEL_H
#define BOARDSPACELABEL_H

#include <QWidget>
#include <Qt>
#include <QVariant>
#include <QApplication>
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

    void enterEvent(QEvent* ev) override;

    void leaveEvent(QEvent* ev) override;

    // TODO: do same for gamesetupwindow? make hoversymbollabel class?

private:
    bool uiLoaded = false;

    void resizeSymbol();

    void setTextSym(QString text) override;

    void setImageSym(QImage image) override;

};

#endif // BOARDSPACELABEL_H
