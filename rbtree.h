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
    Blank* find(QString shipName);
    void showAll();
    int size();
    bool isEmpty();
    void deleteByKey(QString _key);
    void writeToFile(QString fileName);
    void readFromFile(QString fileName);
    void insertByKey(Blank *_data);

    Node* root;
private:
    void show(Node *_root);
    void rotateLeft(Node* n);
    void rotateRight(Node* n);
    void findOne(Blank **result, Node* root, QString shipName);
    void deleteNode(Node *n);
    void insertCase1(Node* n);
    void insertCase2(Node* n);
    void insertCase3(Node* n);
    void insertCase4(Node* n);
    void insertCase5(Node* n);
    void deleteCase1(Node *n);
    void deleteCase2(Node *n);
    void deleteCase3(Node *n);
    void deleteCase4(Node *n);
    void deleteCase5(Node *n);
    void deleteCase6(Node *n);
    Node* getNext(Node* n);
    bool compare(QString a, QString b);
    Node* getByKey(Node* _root, QString _key);
    int sizeOf;
};

#endif // RBTREE_H
