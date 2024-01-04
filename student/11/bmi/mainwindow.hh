#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


const QString OVER_WEIGHT = "You are overweight.";
const QString UNDER_WEIGHT = "You are underweight.";
const QString OK_WEIGHT = "Your weight is normal.";

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void calculateBMI();

};
#endif // MAINWINDOW_HH
