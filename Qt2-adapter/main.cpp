#include "mainwindow.h"
#include "stack.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    MyStack stack;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
