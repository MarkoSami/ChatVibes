#include "welcomepage.h"
#include<QJsonArray>
#include <QApplication>
#include "lib/filesystem_lib.h"

int main(int argc, char *argv[])
{
    int currentExitCode = 0;

    do{
    QApplication a(argc, argv);
    QApplication::setFont(QFont("Tajawal", 12));


    WelcomePage welcomeWin ;
    welcomeWin.show();

    // Connect a slot to the QApplication::aboutToQuit signal
    QObject::connect(&a, &QApplication::aboutToQuit, [](){
        fileSystem_lib::saveData();
    });
    currentExitCode = a.exec();
    } while(currentExitCode == profileWindow::EXIT_CODE_REBOOT);

        return currentExitCode;
}
