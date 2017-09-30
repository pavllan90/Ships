#include <QtGui/QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    int d = 0;
    printf("Run GUI?(1/0)\n");
    scanf("%d", &d);
    if(d)
    {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();

        return a.exec();
    }
    else
    {
        Blank v;
        v.show();
        Blank b("Andrey", "Sergeev", "Pobeda", "2.12", "Sevastopol");
        b.show();
        Blank c = b;
        c.show();
    }
}
