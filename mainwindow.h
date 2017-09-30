#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "blank.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void show_list();
    void add();
private:
    Ui::MainWindow *ui;
    Blank mass[10];
    int count;

};

#endif // MAINWINDOW_H
