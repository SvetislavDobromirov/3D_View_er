#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gl_viewer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_test_but_clicked();
    void on_buttonRepaint_clicked();
    void on_red_slider_actionTriggered(int action);

    void on_green_slider_actionTriggered(int action);

    void on_blue_slider_actionTriggered(int action);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
