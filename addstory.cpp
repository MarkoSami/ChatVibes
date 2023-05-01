#include "addstory.h"
#include "ui_addstory.h"
#include <QFileDialog>
#include "logic/story.h"

AddStory::AddStory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStory)
{
    ui->setupUi(this);
}

AddStory::~AddStory()
{
    delete ui;
}

void AddStory::on_pushButton_clicked()
{
    // Open a file dialog and get the selected file
    QString img_path = QFileDialog::getOpenFileName(this, tr("Select Image"), QDir::homePath(), tr("Image files (*.png *.jpg *.jpeg *.bmp *.gif)"));

    // Check if a file was selected
    if (!img_path.isEmpty()) {
        // Upload the file to the server or perform other actions with it
        qDebug() << "File selected:" << img_path;
    } else {
        // Handle case where no file was selected
        qDebug() << "No file selected.";
    }
}

