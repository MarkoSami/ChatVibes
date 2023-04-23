#include "profilewindow.h"
#include "ui_profilewindow.h"
#include <QPixmap>
#include <QFileDialog>
profileWindow::profileWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::profileWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    ui->lineEdit->setText("Mina Melad") ;
    ui->lineEdit_2->setText("Hello there! I'm using chatVibes");
//    ui->ProfileUploadBtn->setStyleSheet("QPushButton#ProfileUploadBtn{background-color: #3663fd; border-radius: 5px; font-size: 20px; color: white; font-weight: bold;}"
//                                      "QPushButton#ProfileUploadBtn:hover{color : red;}");
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


