
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "profilewindow.h"
#include "registerfrom.h"
#include "starting_handle.h"
#include "welcomepage.h"
#include "addcontact.h"
#include "startnewchat.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    profileWindow *profWin;
//    Registerfrom *regWin ;
    WelcomePage *welcomeWin;
    AddContact *addContactWin ;
    StartNewChat *StartNewChatWin;
};

#endif // MAINWINDOW_H
