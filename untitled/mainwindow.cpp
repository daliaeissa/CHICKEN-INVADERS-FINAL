#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // ui->setupUi(this);
    // this->setStyleSheet("{background-image: url(:C:/Users/dalia/Desktop/Spring 2024 semester/CS2 lab/Assignments/Assignment 2 QT MULTIMEDIA CI/spacefinal.jpg);}");
}

MainWindow::~MainWindow() {}
