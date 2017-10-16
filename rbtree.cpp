#include "rbtree.h"
#include <stdio.h>
#include <QDebug>

RBTree::RBTree()
{
    size_of = 0;
    root = NULL;
}

RBTree::RBTree(const RBTree &a)
{
    size_of = 0;
    root = NULL;
    Node* temp = a.root;
    while(temp->left&&!temp->left->is_Leaf) temp = temp->left;
    while(temp&&!temp->is_Leaf)
    {
        insertByKey(temp->key, temp->data);
        temp = getNext(temp);
    }
//    for(int i = 0; i<a.size_of&&temp; i++)
//    {
//        insertByKey(temp->key, temp->data);
//        temp = getNext(temp);
//    }
}

void RBTree::writeToFile(QString f_name)
{
    Node* _r = root;
    QFile file;
    file.setFileName(f_name);
    file.open(QIODevice::WriteOnly);
    QDataStream stream (&file);
    while(!_r->left->is_Leaf)
    {
        _r=_r->left;
    }
    while(_r)
    {
        stream<<QString::number(_r->key)<<_r->data.getOwner().name<<_r->data.getOwner().surname<<_r->data.getName()<<QString::number(_r->data.getTonnage())<<_r->data.getHome()<<QString::number(_r->data.getLineage());
        _r=getNext(_r);
    }
    file.close();
}

void RBTree::readFromFile(QString f_name)
{
    QFile file;
    file.setFileName(f_name);
    file.open(QIODevice::ReadOnly);
    QDataStream stream(&file);
    while(!file.atEnd())
    {
        int _key = 0;
        QString K;
        QString o_name ;
        QString o_surname;
        QString _name;
        QString _home ;
        QString _tonnage;
        QString _lineage;
        stream>>K>>o_name>>o_surname>>_name>>_tonnage>>_home>>_lineage;
        _key = K.toInt();
        Blank x (o_name, o_surname, _name, _tonnage.toFloat(), _home, _lineage.toFloat());
        insertByKey(_key, x);
    }
    file.close();
}

void RBTree::deleteByKey(int _key)
{
    Node* delNode =NULL;
    delNode = findByKey(root, _key);
    if(delNode)deleteOne(delNode);
    else std::cout<<"No such key"<<std::endl;
}

Node* RBTree::findByKey(Node *_root, int _key)
{
    if(_root&&!_root->is_Leaf)
    {
        if(_root->key==_key) return _root;
        else
        {
            if(_key<_root->key) return findByKey(_root->left, _key);
            else return findByKey(_root->right, _key);
            return NULL;
        }
    }
    else return NULL;
}

void RBTree::show(Node *_root)
{
    if(_root == 0) _root = root;
    if(_root)
    {
        if(!_root->is_Leaf){
        show(_root->left);
        _root->show();
        show(_root->right);
        }
    }
}

int RBTree::size()
{
    return size_of;
}

bool RBTree::isEmpty()
{
    if(root) return false;
    else return true;
}

RBTree RBTree::find(QString s_name)
{
    RBTree * res = new RBTree;
    find_one(res, root, s_name);
    return *res;
}

Node* RBTree::getNext(Node *n)
{
    Node* next = n;
    if(!n->right->is_Leaf)
    {
        next = next->right;
        while(!next->left->is_Leaf) next = next->left;
        return next;
    }
    else if(n->parent->left==n) return next->parent;
    else if(n->parent->parent&&n->parent->parent->left==n->parent) return next->parent;
    else return NULL;
}

void RBTree::deleteOne(Node *n)
{
    Node* child;
    if(!n->right->is_Leaf)
    {
        child = n->right;
        while(!child->left->is_Leaf) child=child->left;
        n->data = child->data;
        n->key = child->key;
    }
    else if(!n->left->is_Leaf)
        {
            child = n->left;
            while(!child->right->is_Leaf) child = child->right;
            n->data = child->data;
            n->key = child->key;
        }
        else child = n;
    Node* child1 = child->right->is_Leaf ? child->left : child->right;
    child1->parent = child->parent;
    if(child->parent)
    {
        if(child->parent->left == child) child->parent->left = child1;
        else child->parent->right = child1;
    }
    child->parent =NULL;
    if (child->red == 0) {
            if (child1->red ==1)
                child1->red = 0;
            else
                delete1(child1);
    }
    root = child1;
    while(root->parent) root = root->parent;
    size_of-=1;
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

Node* RBTree::getRoot()
{
    return root;
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

void RBTree::insert(Blank a, int _key)
{
    Node* temp = new Node;
    temp->data=a;
    temp->key = _key;
    if(!root) root = temp ,insert1(root);
    else
    {
        Node* r = root;
        bool f = true;
        while(!(r->left->is_Leaf&&r->right->is_Leaf)&&f)
        {
            if(r->key>=temp->key)
            {
                if(!r->left->is_Leaf)
                    r=r->left;
                else
                    f = false;
            }
            else
            {
                if(!r->right->is_Leaf)
                    r=r->right;
                else f = false;
            }
        }
        temp->parent=r;
        if(temp->key>=r->key) r->right = temp;
        else r->left = temp;
        insert1(temp);
    }
    while(root->parent) root = root->parent;
    size_of+=1;
}

void RBTree::insertByKey(int _key, Blank _data)
{
    Node* nex = findByKey(root, _key);
    if(!nex)
        insert (_data, _key);
}

void RBTree::find_one(RBTree *result, Node* root, QString s_name)
{
    if(root&&!root->is_Leaf)
    {
        if(root->data.getName()==s_name) result->insert(root->data, root->key);
        find_one(result, root->left, s_name);
        find_one(result, root->right, s_name);
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
