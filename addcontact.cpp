#include "addcontact.h"
#include "ui_addcontact.h"
#include <QFileDialog>
AddContact::AddContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddContact)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);

}

AddContact::~AddContact()
{
    delete ui;
}

void AddContact::on_pushButton_clicked()
{
    // Open a file dialog and get the selected file
    QString file_path = QFileDialog::getOpenFileName(this, tr("Select Image"), QDir::homePath(), tr("Image files (*.png *.jpg *.jpeg *.bmp *.gif)"));

    // Check if a file was selected
    if (!file_path.isEmpty()) {
        // Upload the file to the server or perform other actions with it
        qDebug() << "File selected:" << file_path;
    } else {
        // Handle case where no file was selected
        qDebug() << "No file selected.";
    }
}




void AddContact::on_pushButton_5_clicked()
{
    this->close();
}

