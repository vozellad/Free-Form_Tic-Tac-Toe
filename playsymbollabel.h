#ifndef PLAYSYMBOLLABEL_H
#define PLAYSYMBOLLABEL_H

#include <QWidget>
#include <Qt>
#include <QVariant>
#include <QApplication>
#include "symbollabel.h"

class PlaySymbolLabel : public SymbolLabel {
    Q_OBJECT

public:
    explicit PlaySymbolLabel(QWidget* parent = Q_NULLPTR,
                                   Qt::WindowFlags f = Qt::WindowFlags());
    ~PlaySymbolLabel();

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

#endif // PLAYSYMBOLLABEL_H
