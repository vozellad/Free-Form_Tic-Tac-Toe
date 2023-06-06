#include "gamesetupwindow.h"
#include "ui_gamesetupwindow.h"

// Add new board to list of boards by duplicating the initial board in the
// designer view programatically. It's done manually because Qt does not have
// any methods for cloning widgets or layouts. Also adds a line to seperate it
// from the previous board.
void GameSetupWindow::on_toolButton_addBoard_clicked()
{
    // increment board amount
    setBoardAmt(getBoardAmt() + 1);

    if (getBoardAmt() != 1) {
        QFrame* hLine = new QFrame;
        hLine->setFrameShape(QFrame::HLine);
        boards->addWidget(hLine);
    }

    QGridLayout* newBoard = new QGridLayout();

    QString numStr = tr("<b>Board %1<b>").arg(getBoardAmt());
    newBoard->addWidget(new QLabel(numStr));

    QSpacerItem* spacerRight =
            new QSpacerItem(5, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);
    newBoard->addItem(spacerRight, 0, 4);

    newBoard->addWidget(new QLabel("Size of board: "), 1, 0);

    newBoard->addWidget(createBoardSpinBox());

    newBoard->addWidget(new QLabel("x"));

    newBoard->addWidget(createBoardSpinBox());

    newBoard->addWidget(new QLabel("In a row to win: "), 2, 0);

    newBoard->addWidget(createBoardSpinBox());

    boards->addLayout(newBoard);

    setAmtModBtnStates_boards();
}

// Take last grid layout (the last board) from list of boards and delete it and
// its contents. Also delete the line seperating it from its previous board.
void GameSetupWindow::on_toolButton_removeBoard_clicked()
{
    // decrement board amount
    setBoardAmt(getBoardAmt() - 1);

    // delete board
    QLayoutItem* board = boards->takeAt(boards->count() - 1);
    while (QLayoutItem* item = board->layout()->takeAt(0)) {
        delete item->widget();
        delete item;
    }

    // delete HLine
    deleteLastItem(boards);

    setAmtModBtnStates_boards();
}

// Get number represeting board amount in UI
int GameSetupWindow::getBoardAmt() const
{
    return ui->label_boardAmtDisplay->text().toInt();
}

// Set number representing board amount in UI
void GameSetupWindow::setBoardAmt(const int& newBoardAmt)
{
    ui->label_boardAmtDisplay->setText(QString::number(newBoardAmt));
}

// Keep board amount within range (1-99)
// If not in range, turn off appropriate board amount modifier button -/+
// to prevent user from going outside range
void GameSetupWindow::setAmtModBtnStates_boards()
{
     ui->toolButton_addBoard->setEnabled(true);
     ui->toolButton_removeBoard->setEnabled(true);

     if (getBoardAmt() <= 1)
         ui->toolButton_removeBoard->setEnabled(false);
     else if (99 <= getBoardAmt())
         ui->toolButton_addBoard->setEnabled(false);
}

QSpinBox* GameSetupWindow::createBoardSpinBox()
{
    QSpinBox* newSpinBox = new QSpinBox();
    newSpinBox->setValue(3);
    newSpinBox->setMaximumWidth(70);
    newSpinBox->setMinimum(1);
    newSpinBox->setAlignment(Qt::AlignRight);
    return newSpinBox;
}
