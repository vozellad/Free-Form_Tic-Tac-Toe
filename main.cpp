// TODO:
//  GameSetupWindow2 has scrollable sections for player,board

#include "startscreenwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartScreenWindow w;
    w.show();
    return a.exec();
}