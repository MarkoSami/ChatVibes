#include "addcontact.h"
#include "logic/contact.h"
#include "ui_addcontact.h"
#include <QFileDialog>
#include <QPropertyAnimation>
#include <QEvent>
#include "application/application.h"
#include <QString>

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
     QString imgPath = img_path;

     User *targetUser = Application::getLogInUser() ;

     if ((&targetUser) != nullptr) {

        Contact newContact(id, imgPath.toStdString(), name);
        Conversation newConversation(newContact , false , newContact.getName());
        targetUser->addContact(newContact) ;
        targetUser->addNewConversation(newConversation);
        emit renderConversation() ;
     }

}


void AddContact::on_pushButton_9_clicked()
{
     // Open a file dialog and get the selected file
     img_path = QFileDialog::getOpenFileName(this, tr("Select Image"), QDir::homePath(), tr("Image files (*.png *.jpg *.jpeg *.bmp *.gif)"));

     // Check if a file was selected
     if (!img_path.isEmpty()) {
        // Upload the file to the server or perform other actions with it
         ui->profileIMGLB->setStyleSheet("border-image: url(" + img_path + ");border-radius:5px");
        qDebug() << "File selected:" << img_path;
     } else {
        // Handle case where no file was selected
        qDebug() << "No file selected.";
     }
}

