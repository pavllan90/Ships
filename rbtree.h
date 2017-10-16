#ifndef RBTREE_H
#define RBTREE_H
#include "node.h"
#include "blank.h"
#include <QFile>
#include <cstddef>

class RBTree
{
public:
    RBTree();
    RBTree (const RBTree &a);
    Node* getRoot();
    RBTree find(QString s_name);
    void show(Node *_root = 0);
    int size();
    bool isEmpty();
    void deleteByKey(int _key);
    Node *findByKey(Node* _root, int _key);
    void insertByKey(int _key, Blank _data);
    void writeToFile(QString f_name);
    void readFromFile(QString f_name);
private:
    Node* root;
    void rotate_left(Node* n);
    void rotate_right(Node* n);
    void find_one(RBTree *result, Node* root, QString s_name);
    void deleteOne(Node *n);
    void insert1(Node* n);
    void insert2(Node* n);
    void insert3(Node* n);
    void insert4(Node* n);
    void insert5(Node* n);
    void delete1(Node *n);
    void delete2(Node *n);
    void delete3(Node *n);
    void delete4(Node *n);
    void delete5(Node *n);
    void delete6(Node *n);
    void insert(Blank a, int _key);
    Node* getNext(Node* n);
    int size_of;
};

#endif // RBTREE_H
