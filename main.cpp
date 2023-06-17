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

make sure correct use of
    setColumnMinimumWidth
    setColumnStretch

make window appear in center of screen

custom widget for player and boards?

class diagram

size vs count

does switching windows while only hiding the old one
mean memory will keep building if I keep switching?

correct comments because code changed

make comments consistently start with upper case letter

highlight boardSpace user's cursor is on
add noise when symbol is inserted

const & everywhere?

rule of five

*/
