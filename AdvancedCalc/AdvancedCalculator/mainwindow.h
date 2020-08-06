#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QFormLayout>
#include "classic.h"
#include "scientific.h"

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
    void on_Settings_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    Classic classicWid;
    Scientific sciWid;
};
#endif // MAINWINDOW_H
