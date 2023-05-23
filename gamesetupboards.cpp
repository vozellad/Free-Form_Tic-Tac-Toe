#include "gamesetupwindow.h"
#include "ui_gamesetupwindow.h"

void GameSetupWindow::on_toolButton_addBoard_clicked()
{
    // increment board amount
    setBoardAmt(getBoardAmt() + 1);

    QFrame* hLine = new QFrame;
    hLine->setFrameShape(QFrame::HLine);
    hLine->setFrameShadow(QFrame::Sunken);
    boards->addWidget(hLine);

    QGridLayout* newBoard = new QGridLayout();

    QString numStr = tr("<b>Board %1<b>").arg(getBoardAmt());
    QLabel* num = new QLabel(numStr);
    newBoard->addWidget(num);

    QSpacerItem* spacerRight = new QSpacerItem(5,
                                               5,
                                               QSizePolicy::Expanding,
                                               QSizePolicy::Minimum);
    newBoard->addItem(spacerRight, 0, 4);

    newBoard->addWidget(new QLabel("Size of board: "), 1, 0);

    QSpinBox* sizeRow = new QSpinBox();
    sizeRow->setValue(3);
    sizeRow->setMaximumWidth(55);  // TODO: why different
    sizeRow->setMinimum(1);
    newBoard->addWidget(sizeRow);

    newBoard->addWidget(new QLabel("x"));

    QSpinBox* sizeCol = new QSpinBox();
    sizeCol->setValue(3);
    sizeCol->setMaximumWidth(55);
    sizeCol->setMinimum(1);
    newBoard->addWidget(sizeCol);

    newBoard->addWidget(new QLabel("In a row to win: "), 2, 0);

    QSpinBox* win = new QSpinBox();
    win->setValue(3);
    win->setMaximumWidth(55);
    win->setMinimum(1);
    newBoard->addWidget(win);

    boards->addLayout(newBoard);

    setAmtModBtnStates_boards();
}

void GameSetupWindow::on_toolButton_removeBoard_clicked()
{
    // decrement board amount
    setBoardAmt(getBoardAmt() - 1);

    // delete board
    QLayoutItem* board = boards->takeAt(boards->count() - 1);
    while (QLayoutItem* item = board->layout()->takeAt(0))
    {
        delete item->widget();
        delete item;
    }

    // delete HLine
    deleteLastItem(boards);

    setAmtModBtnStates_boards();
}

int GameSetupWindow::getBoardAmt() const
{
    return ui->label_boardAmtDisplay->text().toInt();
}

void GameSetupWindow::setBoardAmt(int newBoardAmt)
{
    ui->label_boardAmtDisplay->setText(QString::number(newBoardAmt));
}

void GameSetupWindow::setAmtModBtnStates_boards()
{
     ui->toolButton_addBoard->setEnabled(true);
     ui->toolButton_removeBoard->setEnabled(true);

     if (getBoardAmt() <= 1)
         ui->toolButton_removeBoard->setEnabled(false);
     else if (99 <= getBoardAmt())
         ui->toolButton_addBoard->setEnabled(false);
}
