/*  Customized label to be used as a board space in a TicTacToe board.
 *  Inherets from SymbolLabel to properly use text or image.
 *  Resizes image with no progressive quality degradation as window resizes.
 */

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
    // Resizes symbol when window resizes
    void resizeEvent(QResizeEvent *event) override;

    // Waits for UI to load to allow resizing of symbol
    void showEvent(QShowEvent *event) override;

private:
    bool uiLoaded = false;

    void resizeSymbol();

    // Overwrites function to scale image before applying
    void setImageSym(QImage image) override;

};

#endif // BOARDSPACELABEL_H
