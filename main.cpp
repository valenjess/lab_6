#include "universe.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Universe w;
    w.show();
    return a.exec();
}
