#include "profilewindow.h"
#include "ui_profilewindow.h"
#include <QPixmap>
#include <QFileDialog>
#include <application/application.h>
QString file_path;
profileWindow::profileWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::profileWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    if(Application::loggedUser != nullptr)
    {

        std::string loggedUserName = Application::loggedUser->getUserName();
        ui->lineEdit->setText(QString::fromStdString(loggedUserName));
        ui->ProfileImageLabel->setStyleSheet("border-image: url(" + QString::fromStdString(Application::loggedUser->getIMGpath()) + ");");

    }
    ui->lineEdit_2->setText("Hello there! I'm using chatVibes");

}

profileWindow::~profileWindow()
{
    delete ui;
}

void profileWindow::on_pushButton_5_clicked()
{

    this->close();
}


void profileWindow::on_ProfileUploadBtn_clicked()
{
    // Open a file dialog and get the selected file
     file_path = QFileDialog::getOpenFileName(this, tr("Select Image"), QDir::homePath(), tr("Image files (*.png *.jpg *.jpeg *.bmp *.gif)"));

    // Check if a file was selected
    if (!file_path.isEmpty() && Application::loggedUser != nullptr) {
        // Upload the file to the server or perform other actions with it
        qDebug() << "File selected:" << file_path;
        ui->ProfileImageLabel->setStyleSheet("border-image: url(" + file_path + ");");


    } else {
        // Handle case where no file was selected
        qDebug() << "No file selected.";
    }
}



void profileWindow::on_pushButton_clicked()
{
    Application::loggedUser->setUserName(ui->lineEdit->text().toStdString());
    Application::loggedUser->setIMGpath(file_path.toStdString());
}

