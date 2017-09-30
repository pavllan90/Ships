#ifndef NODE_H
#define NODE_H
#include <cstddef>
#include "blank.h"
class Node
{
public:
    Node();
    Node(Node *a);
    Blank data;
    Node *parent, *left, *right;
    int key;

    bool red;
    bool is_Leaf;
    Node* grandparent();
    Node* uncle();
    Node* sibling();

};

#endif // NODE_H
