#include "startnewchat.h"
#include "ui_startnewchat.h"
#include <QThread>
#include <QProgressBar>
#include <QTimer>
StartNewChat::StartNewChat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartNewChat)
{
    ui->setupUi(this);
        this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
}

StartNewChat::~StartNewChat()
{
    delete ui;
}

void StartNewChat::on_pushButton_clicked()
{
    QProgressBar *progressBar = new QProgressBar();
    ui->verticalGroupBox->layout()->addWidget(progressBar);
    progressBar->setValue(0);

    // Set up a timer to update the progress bar at regular intervals
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [=]() {
        int value = progressBar->value() + 1;
        progressBar->setFormat("");
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setStyleSheet("QProgressBar { background-color: blue; } QProgressBar::chunk { background-color: #3663fd; }");

        progressBar->setValue(value);
        if (value == 100) {
            // Stop the timer when the progress bar reaches 100%
            timer->stop();
            timer->deleteLater();
            this->close();
        }
    });

    // Start the timer to animate the progress bar
    timer->start(10); // Update the progress bar every 10 milliseconds
}

