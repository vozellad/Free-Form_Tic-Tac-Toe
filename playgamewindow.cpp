#include "playgamewindow.h"
#include "ui_playgamewindow.h"

PlayGameWindow::PlayGameWindow(const QVector<Player>& players,
                               const QVector<Board>& boards,
                               QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayGameWindow),
    players(players),
    boards(boards)
{
    ui->setupUi(this);

    table = ui->gridLayout_table;
    table->setSpacing(42);

    addBoards();  // Add boards to table

    //connect(this, &PlayGameWindow::resized,
    //        this, &PlayGameWindow::updateSymbolSizes);
}

PlayGameWindow::~PlayGameWindow()
{
    delete ui;
}

void PlayGameWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    emit resized();
}

void PlayGameWindow::updateSymbolSizes()
{
    return;
    for (int i = 0; i < table->count(); i++)
        for (int j = 0; j < table[i].count(); j += 2) {
            try {  // if label has image (else it has text)
                //getImageFromLabel();
            } catch (const ImageNotFoundException& e) {
                //symbolLabel->text();
            }
        }
}

void PlayGameWindow::addClickedBoardSpace(SymbolLabel* boardSpace,
                                          const QGridLayout* board)
{
    QObject::connect(boardSpace, &SymbolLabel::clicked, this,
        [this, boardSpace, board]() {
            insertPlayerSymbol(boardSpace);
            //evalBoardWin(board);

            // Cyclically iterate players
            currPlayerIndex = (currPlayerIndex + 1) % players.count();
        }
    );
}

void PlayGameWindow::addBoards()
{
    // addLayout() requires position values
    int row = 0, col = 0;

    const int tableWidth = ((int)sqrt(boards.count()) + 1);

    for (Board b : boards) {
        table->addLayout(createBoard(b), row, col);

        // Increment position values
        col = (col + 1) % tableWidth;
        if (col == 0)  row++;
    }
}

QGridLayout* PlayGameWindow::createBoard(const Board& board)
{
    // TODO: do with QPallete instead?

    QGridLayout* boardLayout = new QGridLayout();
    boardLayout->setSpacing(0);  // Connect lines

    // Grid sizes including grid lines
    const int gridHeight = board.sizeY * 2 - 1;
    const int gridWidth = board.sizeX * 2 - 1;

    // Set grid column width
    boardLayout->setColumnMinimumWidth(board.sizeX-1, 0);
    boardLayout->setColumnStretch(board.sizeX-1, 0);

    // Add spaces for symbols
    for (int row = 0; row < gridHeight; row += 2)
        for (int col = 0; col < gridWidth; col += 2) {
            SymbolLabel* boardSpace = new SymbolLabel();
            boardSpace->setAlignment(Qt::AlignCenter);
            addClickedBoardSpace(boardSpace, boardLayout);
            boardLayout->addWidget(boardSpace, row, col);
        }

    // Add lines
    for (int row = 0; row < gridHeight; row += 2) {
        for (int col = 1; col < gridWidth; col += 2) {
            QFrame* vLine = new QFrame;
            vLine->setFrameShape(QFrame::VLine);
            vLine->setStyleSheet("background-color: white;");  // TODO: make it theme agnostic
            boardLayout->addWidget(vLine, row, col);
        }

        // Don't add last hLine
        if (row >= gridHeight - 1)  break;

        QFrame* hLine = new QFrame;
        hLine->setFrameShape(QFrame::HLine);
        hLine->setStyleSheet("background-color: white;");  // TODO: make it theme agnostic
        boardLayout->addWidget(hLine, row + 1, 0, 1, 0);
    }

    return boardLayout;
}

void PlayGameWindow::insertPlayerSymbol(SymbolLabel* boardSpace)
{
    // if space has text or image
    if (!boardSpace->text().isEmpty() || boardSpace->pixmap() != nullptr)
        return;

    // Insert symbol
    boardSpace->setSymbol(players[currPlayerIndex].symbol);
}

void PlayGameWindow::evalBoardWin(const QGridLayout* board)
{

}
