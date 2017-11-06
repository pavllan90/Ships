#include <QtGui/QApplication>
#include "mainwindow.h"
#include <cassert>


int main(int argc, char *argv[])
{
   RBTree tree;
//    tree.isEmpty();
//    assert(tree.size()==0&&tree.isEmpty());
//    Blank r;
//    tree.insertByKey(new Blank());
    //tree.showAll();
//    assert(tree.size()==1 && !tree.isEmpty());
    tree.insertByKey(new Blank("A","B", "C", 1.47, "F", 2.03));
//    tree.insertByKey(new Blank("N", "I", "M", 3.12, "H", 1000.99));
    Blank *v = new CruiseBlank("Anton", "Chehov", "Cruiser", 3.12, "Home", 1000.99, 10000, "Bolivia");
    tree.insertByKey(v);
    //tree.showAll();
    Blank *f_check = tree.find("C");
 //   assert(f_check->getOwner().name=="A"&&f_check->getOwner().surname=="B"&&f_check->getName()=="C"&&f_check->getHome()=="F");
    RBTree cp_tree = tree;
    cp_tree.showAll();
//    assert(tree.size()==cp_tree.size());
//    assert(tree.find("C")->getName()==cp_tree.find("C")->getName());
//    assert(tree.find("M")->getName()==cp_tree.find("M")->getName());
//    assert(tree.find("Avrora")->getName()==cp_tree.find("Avrora")->getName());

        QApplication a(argc, argv);
        MainWindow w;
        w.show();

        return a.exec();
        return 0;
}
