#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "rbtree.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    Dialog(QString _name, RBTree *_tree, bool *_changed);
    ~Dialog();
    
private:
    Ui::Dialog *ui;
    RBTree *tree;
    QString name;
    Blank *data;
    bool *changed;
private slots:
    void del();
    void save();
};

#endif // DIALOG_H
