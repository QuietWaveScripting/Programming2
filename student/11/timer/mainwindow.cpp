#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // initialize timer
    timer = new QTimer();

    // add connections
    connect(timer, &QTimer::timeout, this, &MainWindow::updateView);

    // buttons
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startTimer);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::stopTimer);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::resetTimer);
    connect(ui->closeButton, &QPushButton::clicked, this, &MainWindow::closeWindow);

}

MainWindow::~MainWindow()
{
    delete ui;


}

void MainWindow::updateView()
{
    //increment seconds value
    seconds_++;

    // convert seconds to minutes + seconds
    //update lcd views

    int mins = seconds_ / 60;
    int sec = seconds_ % 60;

    ui->lcdNumberMin->display(mins);
    ui->lcdNumberSec->display(sec);



}

void MainWindow::startTimer()
{   
    timer -> start(1000);
}

void MainWindow::resetTimer()
{
    // account for updateView sec++
    seconds_ = -1;
    updateView();
}

void MainWindow::stopTimer()
{
    if(timer != nullptr)
    {
        timer -> stop();
    }
}

void MainWindow::closeWindow()
{
    this->close();
}
