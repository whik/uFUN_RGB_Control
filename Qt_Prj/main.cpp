#include "rgb.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RGB w;
    w.show();

    return a.exec();
}
