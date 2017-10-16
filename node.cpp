#include "node.h"

using namespace std;

Node::Node()
{
    parent = NULL;
    left = new Node(this);
    right = new Node (this);
    is_Leaf = false;
    red = 1;
    key = -1;
}

Node::Node(Node *a)
{
    parent = a;
    left = right = NULL;
    red = 0;
    is_Leaf = true;
    key = -1;
}

Node* Node::grandparent()
{
    if(this&&this->parent)
    {
        return this->parent->parent;
    }
    else return NULL;
}

Node* Node::uncle()
{
    Node* g;
    if(g = this->grandparent())
    {
        if(this->parent==g->left) return g->right;
        else return g->left;
    }
    else return NULL;
}

Node* Node::sibling()
{
    if(this->parent->left==this) return this->parent->right;
    else return this->parent->left;
}


void Node::show()
{
    cout<<key<<endl;
    cout<<data.getOwner().name.toLatin1().data()<<endl;
    cout<<data.getOwner().surname.toLatin1().data()<<endl;
    cout<<data.getName().toLatin1().data()<<endl;
    cout<<data.getHome().toLatin1().data()<<endl;
    cout<<data.getTonnage()<<endl;
    cout<<"-------------"<<endl;
}
