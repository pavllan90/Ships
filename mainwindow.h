#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rbtree.h"

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
    void search();
    void save();
    void load();
    void del();
private:
    Ui::MainWindow *ui;
    RBTree tree;

};

#endif // MAINWINDOW_H
