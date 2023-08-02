#include "startscreenwindow.h"
#include "ui_startscreenwindow.h"

StartScreenWindow::StartScreenWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartScreenWindow)
{
    ui->setupUi(this);
    this->move(900, 900);
    this->show();
}

StartScreenWindow::~StartScreenWindow()
{
    delete ui;
}

// Go to next window
void StartScreenWindow::on_pushButton_start_clicked()
{
    GameSetupWindow *w = new GameSetupWindow(this);
    w->show();

    this->hide();
}

void StartScreenWindow::showEvent(QShowEvent *ev)
{
    QWidget::showEvent(ev);

    // geometry of the main window
    QRect qr = this->frameGeometry();

    // center point of screen
    QScreen *qc = QGuiApplication::primaryScreen();
    QPoint cp = qc->geometry().center();

    // move rectangle's center point to screen's center point
    qr.moveCenter(cp);

    // top left of rectangle becomes top left of window centering it
    this->move(qr.topLeft());

    return;

    QScreen *primaryScreen = QGuiApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->availableGeometry();

    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height();
    int windowWidth = this->width();
    int windowHeight = this->height();
    int x = (screenWidth - windowWidth);
    int y = (screenHeight - windowHeight);

    this->move(900, 900);
    this->show();
}
