
#include "mainwindow.h"
#include "welcomepage.h"
#include<QJsonArray>
#include <QApplication>
#include "lib/filesystem_lib.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    WelcomePage welcomeWin ;
    welcomeWin.show();
    w.show();
    // Connect a slot to the QApplication::aboutToQuit signal
    QObject::connect(&a, &QApplication::aboutToQuit, [](){
        fileSystem_lib::saveData();
    });


    return a.exec();
}
