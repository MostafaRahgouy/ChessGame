#include "mainwindow.h"
#include "menuform.h"
#include <QApplication>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menuForm w;
    w.show();
    return a.exec();
}
