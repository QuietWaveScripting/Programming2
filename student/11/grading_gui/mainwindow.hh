#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include "gradecalculator.hh" // Include the GradeCalculator module

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_calculatePushButton_clicked(); // Add slot for the Calculate button

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
