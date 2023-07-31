#include "startscreenwindow.h"

#include <QApplication>
#include <QtMultimedia>

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

class diagram

correct comments because code changed
(make comments consistently start with upper case letter)

add noise

rule of five

what namespaces to add? Utils?

*/
