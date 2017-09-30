#ifndef RBTREE_H
#define RBTREE_H
#include "node.h"
#include <cstddef>

class RBTree
{
public:
    RBTree();
    Node* root;
    int count;
    void rotate_left(Node* n);
    void rotate_right(Node* n);
    void insert(int a);
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

    Node *find(Node* r, int key);
    void deleteOne(Node *n);
};

#endif // RBTREE_H
