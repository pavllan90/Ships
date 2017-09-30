#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rbtree.h"
#include <cstddef>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    int insert(RBTree *tree, int data);
    RBTree tree;
private slots:
    void ins();
    void show_it();
    void del();
    void sh(Node* root, int i);

};

#endif // MAINWINDOW_H
