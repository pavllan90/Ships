#include "rbtree.h"
#include <stdio.h>
#include <QDebug>

RBTree::RBTree()
{
    count=0;
    root = NULL;
}

void RBTree::deleteOne(Node *n)
{
    Node* child;
    count-=1;
    if(!n->right->is_Leaf)
    {
        child = n->right;
        while(!child->left->is_Leaf) child=child->left;
        n->data = child->data;
    }
    else if(!n->left->is_Leaf)
        {
            child = n->left;
            while(!child->right->is_Leaf) child = child->right;
            n->data = child->data;
        }
        else child = n;
    Node* child1 = child->right->is_Leaf ? child->left : child->right;
    child1->parent = child->parent;
    if(child->parent->left == child) child->parent->left = child1;
    else child->parent->right = child1;
    child->parent =NULL;
    if (child->red == 0) {
            if (child1->red ==1)
                child1->red = 0;
            else
                delete1(child1);
    }
    root = child1;
    while(root->parent) root = root->parent;
    delete child;
}

void RBTree::delete1(Node* n)
{
    if(n->parent)
    {
        delete2(n);
    }
}

void RBTree::delete2(Node* n)
{
    Node *s = n->sibling();
    if(s->red==1)
    {
        n->parent->red = 1;
        s->red = 0;
        if(n == n->parent->left)
        {
            rotate_left(n->parent);
        }
        else
        {
            rotate_right(n->parent);
        }
    }

    delete3(n);
}

void RBTree::delete3(Node* n)
{
    Node* s = n->sibling();
    if(n->parent->red==0&&s->red==0&&s->left->red==0&&s->right->red==0)
    {
        s->red=1;
        delete1(n->parent);
    }
    else delete4(n);
}

void RBTree::delete4(Node* n)
{
    Node* s = n->sibling();
    if(n->parent->red==1&&s->red==0&&s->left->red==0&&s->right->red==0)
    {
        s->red=1;
        n->parent->red=0;
    }
    else delete5(n);
}

void RBTree::delete5(Node* n)
{
    Node *s = n->sibling();

        if  (s->red==0) {
            if ((n == n->parent->left) &&
                (s->right->red==0) &&
                (s->left->red==1)) {
                s->red==1;
                s->left->red==0;
                rotate_right(s);
            } else if ((n == n->parent->right) &&
                       (s->left->red==0) &&
                       (s->right->red==1)) {
                s->red==1;
                s->right->red == 0;
                rotate_left(s);
            }
        }
        delete6(n);
}

void RBTree::delete6(Node* n)
{
    Node *s = n->sibling();

        s->red = n->parent->red;
        n->parent->red=0;

        if (n == n->parent->left) {
            s->right->red=0;
            rotate_left(n->parent);
        } else {
            s->left->red=0;
            rotate_right(n->parent);
        }
}


void RBTree::insert(Blank a)
{
    Node* temp = new Node;

    temp->data=a;
    temp->key = count;
    count+=1;
    if(!root) root = temp ,insert1(root);
    else
    {
        Node* r = root;
        bool f = true;
        while(!(r->left->is_Leaf&&r->right->is_Leaf)&&f)
        {
            if(r->key>=temp->key)
            {
                qDebug("Left");
                if(!r->left->is_Leaf)
                    r=r->left;
                else
                    f = false;
            }
            else
            {
                qDebug("Right");
                if(!r->right->is_Leaf)
                    r=r->right;
                else f = false;
            }
        }
        temp->parent=r;
        if(temp->key>=r->key) r->right = temp, qDebug("To right");
        else r->left = temp, qDebug("To left");
        insert1(temp);
    }
    while(root->parent) root = root->parent;
    //count+=1;
    printf("ADDED %d\n", temp->key);
}

Node* RBTree::find(Node* r, int key)
{

        if (r)
        {
            if(key>r->key) find(r->right, key);
            else if (key<r->key) find(r->left, key);
            else if(key==r->key) return r;
        }

}

void RBTree::rotate_left(Node* n)
{
    Node* pivot = n->right;
    pivot->parent = n->parent;
    if(n->parent)
    {
        if(n->parent->left == n)
        {
            n->parent->left = pivot;
        }
        else
        {
            n->parent->right = pivot;
        }
    }
    n->right = pivot->left;
    if(pivot->left)
    {
        pivot->left->parent = n;
    }
    n->parent = pivot;
    pivot->left = n;
}

void RBTree::rotate_right(Node* n)
{
    Node* pivot = n->left;
    pivot->parent = n->parent;
    if(n->parent)
    {
        if(n->parent->left == n)
        {
            n->parent->left = pivot;
        }
        else
        {
            n->parent->right = pivot;
        }
    }
    n->left = pivot->right;
    if(pivot->right)
    {
        pivot->right->parent = n;
    }
    n->parent = pivot;
    pivot->right = n;
}

void RBTree::insert1(Node* n)
{
    if(n->parent == NULL)
    {
        n->red=0;
    }
    else insert2(n);
}

void RBTree::insert2(Node* n)
{
    if(n->parent->red == 1 )
    {
        insert3(n);
    }
}

void RBTree::insert3(Node* n)
{
    Node *u = n->uncle(), *g = n->grandparent();
    if(u&&u->red==1)
    {
        n->parent->red = 0;
        u->red = 0;
        g->red = 1;
        insert1(g);
    }
    else
    {
        insert4(n);
    }
}



void RBTree::insert4(Node* n)
{
    Node *g = n->grandparent();
    if(n == n->parent->right && n->parent==g->left)
    {
        rotate_left(n->parent);
        n = n->left;
    }
    else if(n == n->parent->left && n->parent==g->right)
    {
        rotate_right(n->parent);
        n = n->right;
    }
    insert5(n);
}

void RBTree::insert5(Node* n)
{
    Node *g = n->grandparent();
    n->parent->red = 0;
    g->red = 1;
    if(n==n->parent->left&&n->parent == g->left)
    {
        rotate_right(g);
    }
    else
    {
        rotate_left(g);
    }
}
