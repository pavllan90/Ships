#ifndef NODE_H
#define NODE_H
#include <cstddef>
#include "cruiseblank.h"
#include "blank.h"
#include <iostream>
class Node
{
public:
    Node();
    Node(Node *a);
    Blank* data;
    QString key;
    Node *parent, *left, *right;
    bool red;
    bool is_Leaf;
    Node* grandparent();
    Node* uncle();
    Node* sibling();
};

#endif // NODE_H
