// mainwindow.cpp
#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "gradecalculator.hh"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set the range for the spin boxes
        ui->spinBoxN->setRange(0, 800);
        ui->spinBoxG->setRange(0, 120);
        ui->spinBoxP->setRange(0, 250);
        ui->spinBoxE->setRange(0, 5); // Adjust this range as needed

    // Connect the button click to the corresponding slot
    connect(ui->calculatePushButton, SIGNAL(clicked()), this, SLOT(on_calculatePushButton_clicked()));
}

void MainWindow::on_calculatePushButton_clicked()
{
    // Get input values from spin boxes
    unsigned int n = ui->spinBoxN->value();
    unsigned int g = ui->spinBoxG->value();
    unsigned int p = ui->spinBoxP->value();
    unsigned int e = ui->spinBoxE->value();

    // Calculate total grade using GradeCalculator class
    unsigned int totalGrade = calculate_total_grade(n, g, p, e);

    // Display the result in the textBrowser widget
    ui->textBrowser->setText(QString("W-Score: %1\nP-Score: %2\nTotal grade: %3")
                                .arg(score_from_weekly_exercises(n, g))
                                .arg(score_from_projects(p))
                                .arg(totalGrade));
}

MainWindow::~MainWindow()
{
    delete ui;
}
