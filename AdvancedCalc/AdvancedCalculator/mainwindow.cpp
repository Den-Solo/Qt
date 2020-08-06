#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->addWidget(&classicWid);
    ui->stackedWidget->addWidget(&sciWid);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Settings_currentIndexChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
    ui->TypeName->setText(ui->Settings->itemText(index));
}
