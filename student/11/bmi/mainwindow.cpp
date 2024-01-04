#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Add the following connections in the constructor
    connect(ui->countButton, &QPushButton::clicked, this, &MainWindow::calculateBMI);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::calculateBMI()
{
    bool weightOk, heightOk;
    double weight = ui->weightLineEdit->text().toDouble(&weightOk);
    double heightCM = ui->heightLineEdit->text().toDouble(&heightOk);

    // Convert height from centimeters to meters
    double heightM = heightCM / 100.0;

    if (weightOk && heightOk && heightM != 0) {
        double bmi = weight / (heightM * heightM);

        // Update resultLabel with the calculated BMI
        ui->resultLabel->setText(QString::number(bmi));

        // Update infoTextBrowser with BMI information
        if (bmi < 18.5)
            ui->infoTextBrowser->setText("Underweight");
        else if (bmi >= 18.5 && bmi <= 25)
            ui->infoTextBrowser->setText("Normal range");
        else
            ui->infoTextBrowser->setText("Overweight");
    } else {
        // If weight or height is invalid or height is zero, show "Cannot count" in resultLabel
        ui->resultLabel->setText("Cannot count");
        // Clear infoTextBrowser
        ui->infoTextBrowser->clear();
    }
}





