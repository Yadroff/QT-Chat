#include "secondwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SecondWindow w;
    w.setWindowTitle("Second Client");
    w.show();
    return a.exec();
}
