#ifndef BOARDSPACELABEL_H
#define BOARDSPACELABEL_H

#include <QWidget>
#include <Qt>
#include <QVariant>
#include <QApplication>
#include "symbollabel.h"

// TODO: change to BoardSpaceLabel

class BoardSpaceLabel : public SymbolLabel {
    Q_OBJECT

public:
    explicit BoardSpaceLabel(QWidget* parent = Q_NULLPTR,
                             Qt::WindowFlags f = Qt::WindowFlags());
    ~BoardSpaceLabel();

    void setSymbol(const QVariant& symbol);

signals:
    void resized();

protected:
    void resizeEvent(QResizeEvent *event) override;

    void showEvent(QShowEvent *event) override;

private:
    bool uiLoaded = false;

    void resizeSymbol();

};

#endif // BOARDSPACELABEL_H
