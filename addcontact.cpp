#include "addcontact.h"
#include "logic/contact.h"
#include "ui_addcontact.h"
#include <QFileDialog>
#include <QPropertyAnimation>
#include <QEvent>
#include "application/application.h"

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





void AddContact::on_pushButton_10_clicked()
{
     this->close();
}




void AddContact::on_pushButton_2_clicked()
{

     std::string id = ui->lineEdit_4->text().toStdString(); // assign unique id to each contact
     std::string name = ui->lineEdit_5->text().toStdString();
     std::string imgPath = img_path.toStdString();

     for (auto &user : Application::users) {
         if (user.isLoggedIn()) {
             Contact newContact(id, imgPath, name);
             user.addContact(newContact);
                 // Add the new contact to the user's contact list and display a success message
                 qDebug() << "New contact added:" << user.getUserName() << newContact.getName().c_str() << newContact.getID().c_str() << newContact.getImgPath().c_str() ;
                 qDebug() << user.getUserContacts().size() ;
             }
         }


     // Display an error message if no user is currently logged in
     qDebug() << "No user is currently logged in.";
}




void AddContact::on_pushButton_9_clicked()
{
     // Open a file dialog and get the selected file
     img_path = QFileDialog::getOpenFileName(this, tr("Select Image"), QDir::homePath(), tr("Image files (*.png *.jpg *.jpeg *.bmp *.gif)"));

     // Check if a file was selected
     if (!img_path.isEmpty()) {
        // Upload the file to the server or perform other actions with it
        qDebug() << "File selected:" << img_path;
     } else {
        // Handle case where no file was selected
        qDebug() << "No file selected.";
     }
}

