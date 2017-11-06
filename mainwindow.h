#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "rbtree.h"
#include <QTimer>
#include <QTreeWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void recursiveShow(Node* _root, QTreeWidgetItem *_parent);
private slots:
    void show_list(int a);
    void add();
    void search();
    void save();
    void size();
    void isEmpty();
    void load();
    void del();
    void showOne(QTreeWidgetItem* _item);
    void check();
private:
    RBTree tree;
    Ui::MainWindow *ui;
    Dialog *dial;
    QTimer* timer;

};

#endif // MAINWINDOW_H
