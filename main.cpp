#include "startscreenwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StartScreenWindow w;
    w.show();

    return a.exec();
}

/* TODO:

add docstrings at top of each file

make window appear in center of screen
(also make next window appear where old one was)

class diagram

correct comments because code changed
(make comments consistently start with upper case letter)

*/
