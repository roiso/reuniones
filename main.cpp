#include "gestor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gestor w;
    w.show();

    return a.exec();
}
