#include "startscreenwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Set style sheet  // TODO
    //QFile styleSheetFile("./styleSheet.qss");
    //styleSheetFile.open(QFile::ReadOnly);
    //QString styleSheet = QLatin1String(styleSheetFile.readAll());
    //a.setStyleSheet(styleSheet);

    StartScreenWindow w;
    w.show();

    return a.exec();
}

/* TODO:

offer spanish and greek translations (tr).
    swtch from literal strings to QStrings?

add docstrings at top of each file

make window appear in center of screen
(also make next window appear where old one was)

custom widget for player and boards?

class diagram

correct comments because code changed
(make comments consistently start with upper case letter)

highlight boardSpace user's cursor is on
add noise when symbol is inserted

rule of five

*/
