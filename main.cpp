#include <QtGui/QApplication>
#include "mainwindow.h"
#include <cassert>


int main(int argc, char *argv[])
{
    RBTree tree;
    assert(tree.size()==0&&tree.isEmpty());
    tree.insertByKey(10, Blank());
    assert(tree.size()==1 && !tree.isEmpty());
    tree.insertByKey(1, Blank("A","B", "C", 1.47, "F", 2.03));
    tree.insertByKey(12, Blank("N", "I", "M", 3.12, "H", 1000.99));
    Node * f_check = tree.findByKey(tree.getRoot(), 1);
    assert(f_check->data.getOwner().name=="A"&&f_check->data.getOwner().surname=="B"&&f_check->data.getName()=="C"&&f_check->data.getHome()=="F");
    RBTree cp_tree = tree;
    cp_tree.show();
    assert(f_check->data.getHome()==cp_tree.findByKey(cp_tree.getRoot(), 1)->data.getHome());
//        QApplication a(argc, argv);
//        MainWindow w;
//        w.show();

//        return a.exec();
        return 0;
}
