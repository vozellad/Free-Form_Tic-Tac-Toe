#include "startscreenwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StartScreenWindow w;
    w.show();

    return a.exec();
}

// TODO: offer spanish and greek translations (tr)
