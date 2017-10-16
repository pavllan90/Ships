#ifndef NODE_H
#define NODE_H
#include <cstddef>
#include "blank.h"
#include <iostream>
class Node
{
public:
    Node();
    Node(Node *a);
    Blank data;
    int key;
    Node *parent, *left, *right;
    bool red;
    bool is_Leaf;
    Node* grandparent();
    Node* uncle();
    Node* sibling();
    void show();

};

#endif // NODE_H
