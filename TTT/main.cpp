// TODO:
//
// Create animations for adding/removing elements and changing screens.
//
//// Adding/Removing boards first calls method that acts on changed values.
//// Values are stored so when they are changed, the old and new are compared.
// Add and remove board functions exist.
// Difference between old and new value is how many times one of those functions will be called.
// Which function is called depends on the direction of the difference of course.
//
// Remove spacing above bottom line in free form that only appears in runtime.

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
