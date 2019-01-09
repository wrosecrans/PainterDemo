#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generate_image()
{
    // Just print a message so you can see what's happening, and then emit a signal at the "surface" level that's easy to connect to in main.
    std::cout << "Generate action triggered in MainWindow\n" << std::endl;
    emit generate_image();
}

void MainWindow::on_reset_image()
{
    std::cout << "Reset action triggered in MainWindow\n" << std::endl;
    emit reset_image();
}
