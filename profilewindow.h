#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H

#include <QWidget>

namespace Ui {
class profileWindow;
}

class profileWindow : public QWidget
{
    Q_OBJECT

public:
    explicit profileWindow(QWidget *parent = nullptr);
    ~profileWindow();
    signals:
    void showWelcomePage();
    void exitMainWindow();

private slots:
    void on_pushButton_5_clicked();
    void on_ProfileUploadBtn_clicked();
    void on_pushButton_clicked();

private:
    Ui::profileWindow *ui;

};

#endif // PROFILEWINDOW_H
