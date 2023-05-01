#ifndef ADDSTORY_H
#define ADDSTORY_H

#include <QDialog>

namespace Ui {
class AddStory;
}

class AddStory : public QDialog
{
    Q_OBJECT

public:
    explicit AddStory(QWidget *parent = nullptr);
    ~AddStory();

private slots:
    void on_pushButton_clicked();
private:
    Ui::AddStory *ui;
};

#endif // ADDSTORY_H
