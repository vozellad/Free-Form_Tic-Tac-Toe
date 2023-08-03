/*  Free-Form_Tic-Tac-Toe
 *
 *  A free-form variant of Tic-Tac-Toe. The user can define the following rules:
 *  Amount of players
 *  Player names
 *  Player symbols (text or image)
 *  Amount of boards
 *  Size of boards (width and height. Spaces for symbols. Not graphical size)
 *  Amount in a row needed to win (The win condition for that individual board)
 *
 *  Made in Qt Creator.
 */

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

class diagram

unit tests

*/
