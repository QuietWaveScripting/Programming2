#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Convert to uppercase string
std::string string_toupper(std::string input) {
    std::string output = "";
    for (std::string::size_type i = 0; i < input.length(); ++i) {
        // Append the uppercase converted letter to the output string
        output += toupper(input.at(i));
    }
    // Return uppercase string
    return output;
}

void MainWindow::on_findPushButton_clicked()
{
    // Check if file exists
    std::ifstream fileToSearch(fileName);
    QString result = "";

    if (!fileToSearch) {
        result = "File not found";
    } else {
        result = "File found";

        // Check if word is not empty
        if (!wordToFind.empty()) {
            result = "Word not found";

            // Search file for word
            std::string row;
            while (std::getline(fileToSearch, row)) {
                std::string wordToSearch = wordToFind;

                // Set to uppercase if matchCase
                if (matchCase != 2) {
                    row = string_toupper(row);
                    wordToSearch = string_toupper(wordToSearch);
                }

                if (row.find(wordToSearch) != std::string::npos) {
                    result = "Word found";
                    break;
                }
            }
        }
    }

    // Set textBrowser status
    ui->textBrowser->clear();
    ui->textBrowser->setText(result);
}

void MainWindow::on_fileLineEdit_textChanged(const QString &arg1)
{
    // Update filename
    fileName = arg1.toStdString();
}

void MainWindow::on_keyLineEdit_textChanged(const QString &arg1)
{
    // Update word to find
    wordToFind = arg1.toStdString();
}

void MainWindow::on_matchCheckBox_stateChanged(int arg1)
{
    // Update checkbox status
    matchCase = arg1;
}
