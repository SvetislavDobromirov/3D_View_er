#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

extern "C" {

}
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


void MainWindow::on_test_but_clicked()
{
//    ui->openGLWidget->show();
    ui->openGLWidget->init_test();
}


void MainWindow::on_buttonRepaint_clicked()
{

        ui->openGLWidget->left =  ui->line_left->text().toFloat();
         ui->openGLWidget->right = ui->line_right->text().toFloat();
         ui->openGLWidget->botton = ui->line_botton->text().toFloat();
         ui->openGLWidget->far = ui->line_far->text().toFloat();
         ui->openGLWidget->near = ui->line_near->text().toFloat();
         ui->openGLWidget->top = ui->line_top->text().toFloat();
         ui->openGLWidget->update();
}




void MainWindow::on_red_slider_actionTriggered(int action)
{
    ui->openGLWidget->red = 0.0 + ui->red_slider->value() / 100.0;
    std:: cout << 0.0 + ui->red_slider->value() / 100.0 << std::endl;
    ui->openGLWidget->update();
}


void MainWindow::on_green_slider_actionTriggered(int action)
{
    ui->openGLWidget->green = 0.0 + ui->green_slider->value() / 100.0;
    ui->openGLWidget->update();
}


void MainWindow::on_blue_slider_actionTriggered(int action)
{
    ui->openGLWidget->blue = 0.0 + ui->blue_slider->value() / 100.0;
     ui->openGLWidget->update();
}

