#include "rbtree.h"
#include <stdio.h>
#include <QDebug>

RBTree::RBTree()
{
    sizeOf = 0;
    root = NULL;
}

RBTree::RBTree(const RBTree &a)
{
    sizeOf = 0;
    root = NULL;
    Node* temp = a.root;
    while(temp->left&&!temp->left->is_Leaf) temp = temp->left;
    while(temp&&!temp->is_Leaf)
    {
        insertByKey(temp->data);
        temp = getNext(temp);
    }
}

void RBTree::insertByKey(Blank *_data)
{
    qDebug("%s",_data->getName().toLatin1().data());
    Node* nex = getByKey(root, _data->getName());
    //_data->show();
    if(!nex)
    {
        Node* temp = new Node;
        temp->data=_data;
        temp->key = _data->getName();
        if(!root) root = temp , insertCase1(root);
        else
        {
            Node* r = root;
            bool f = true;
            while(!(r->left->is_Leaf&&r->right->is_Leaf)&&f)
            {
                if(compare(r->key,temp->key))
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
            if(compare(temp->key,r->key)) r->right = temp;
            else r->left = temp;
            insertCase1(temp);
        }
        while(root->parent) root = root->parent;
        sizeOf+=1;
    }
}

void RBTree::deleteByKey(QString _key)
{
    Node* del_node =NULL;
    del_node = getByKey(root, _key);
    if(del_node)deleteNode(del_node);
}

void RBTree::showAll()
{
    show(root);
}

int RBTree::size()
{
    return sizeOf;
}

bool RBTree::isEmpty()
{
    if(root) return false;
    else return true;
}

bool RBTree::compare(QString a, QString b)
{
    int x = 0;
    while(x<a.length()&&x<b.length()&&a.at(x)==b.at(x)) x+=1;
    if(x == a.length()||x==b.length())
    {
        if(a.length()<b.length()) return true;
        else return false;
    }
    else
    {
        if(a.at(x)>b.at(x))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void RBTree::show(Node *_root)
{
    if(_root)
    {
        if(!_root->is_Leaf){
        show(_root->left);
        _root->data->show();
        show(_root->right);
        }
    }
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
    else if(n->parent&&n->parent->left&&n->parent->left==n) return next->parent;
    else if(n->parent&&n->parent->parent&&n->parent->parent->left&&n->parent->parent->left==n->parent) return next->parent->parent;
    else return NULL;
}

void RBTree::deleteNode(Node *n)
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
                deleteCase1(child1);
    }
    root = child1;
    while(root->parent) root = root->parent;
    sizeOf-=1;
    delete child;
}

Blank *RBTree::find(QString shipName)
{
    Blank *res = NULL;
    findOne(&res, root, shipName);
    return res;
}

void RBTree::findOne(Blank **result, Node* root, QString shipName)
{
    if(root&&!root->is_Leaf)
    {
        if(root->data->getName()==shipName) *result=root->data;
        findOne(result, root->left, shipName);
        findOne(result, root->right, shipName);
    }
}

Node* RBTree::getByKey(Node *_root, QString _key)
{
    if(_root&&!_root->is_Leaf)
    {
        if(_root->key==_key) return _root;
        else
        {
            if(_key<_root->key) return getByKey(_root->left, _key);
            else return getByKey(_root->right, _key);
            return NULL;
        }
    }
    else return NULL;
}

void RBTree::writeToFile(QString fileName)
{
    Node* _r = root;
    QFile file;
    file.setFileName(fileName);
    file.open(QIODevice::WriteOnly);
    QDataStream stream (&file);
    while(!_r->left->is_Leaf)
    {
        _r=_r->left;
    }
    for(int i = 0; i<sizeOf; i++)
    {
        if(_r->data->getType()==0)
            stream<<QString::number(_r->data->getType())<<_r->data->getOwner().name<<_r->data->getOwner().surname<<_r->data->getName()<<QString::number(_r->data->getTonnage())<<_r->data->getHome()<<QString::number(_r->data->getLineage());
        else
            stream<<QString::number(_r->data->getType())<<_r->data->getOwner().name<<_r->data->getOwner().surname<<_r->data->getName()<<QString::number(_r->data->getTonnage())<<_r->data->getHome()<<QString::number(_r->data->getLineage())<<dynamic_cast<CruiseBlank*>(_r->data)->getFinalDestination()<<QString::number(dynamic_cast<CruiseBlank*>(_r->data)->getPassengersAmount());
        _r=getNext(_r);
    }
    file.close();
}

void RBTree::readFromFile(QString fileName)
{
    QFile file;
    file.setFileName(fileName);
    file.open(QIODevice::ReadOnly);
    QDataStream stream(&file);
    while(!file.atEnd())
    {
        QString _ownersName ;
        QString _ownersSurname;
        QString _name;
        QString _home ;
        QString _tonnage;
        QString _lineage;
        QString _fdist;
        QString _pas_am;
        QString type;
        stream>>type;
        if(type.toInt()==0)
        {
            stream>>_ownersName>>_ownersSurname>>_name>>_tonnage>>_home>>_lineage;
            //Blank x (_ownersName, _ownersSurname, _name, _tonnage.toFloat(), _home, _lineage.toFloat());
            insertByKey(new Blank (_ownersName, _ownersSurname, _name, _tonnage.toFloat(), _home, _lineage.toFloat()));
        }
        else
        {
            stream>>_ownersName>>_ownersSurname>>_name>>_tonnage>>_home>>_lineage>>_fdist>>_pas_am;
            //Blank x (_ownersName, _ownersSurname, _name, _tonnage.toFloat(), _home, _lineage.toFloat());
            insertByKey(new CruiseBlank (_ownersName, _ownersSurname, _name, _tonnage.toFloat(), _home, _lineage.toFloat(), _pas_am.toInt(), _fdist));
        }
    }
    file.close();
}

void RBTree::insertCase1(Node* n)
{
    if(n->parent == NULL)
    {
        n->red=0;
    }
    else insertCase2(n);
}

void RBTree::insertCase2(Node* n)
{
    if(n->parent->red == 1 )
    {
        insertCase3(n);
    }
}

void RBTree::insertCase3(Node* n)
{
    Node *u = n->uncle(), *g = n->grandparent();
    if(u&&u->red==1)
    {
        n->parent->red = 0;
        u->red = 0;
        g->red = 1;
        insertCase1(g);
    }
    else
    {
        insertCase4(n);
    }
}

void RBTree::insertCase4(Node* n)
{
    Node *g = n->grandparent();
    if(n == n->parent->right && n->parent==g->left)
    {
        rotateLeft(n->parent);
        n = n->left;
    }
    else if(n == n->parent->left && n->parent==g->right)
    {
        rotateRight(n->parent);
        n = n->right;
    }
    insertCase5(n);
}

void RBTree::insertCase5(Node* n)
{
    Node *g = n->grandparent();
    n->parent->red = 0;
    g->red = 1;
    if(n==n->parent->left&&n->parent == g->left)
    {
        rotateRight(g);
    }
    else
    {
        rotateLeft(g);
    }
}

void RBTree::deleteCase1(Node* n)
{
    if(n->parent)
    {
        deleteCase2(n);
    }
}

void RBTree::deleteCase2(Node* n)
{
    Node *s = n->sibling();
    if(s->red==1)
    {
        n->parent->red = 1;
        s->red = 0;
        if(n == n->parent->left)
        {
            rotateLeft(n->parent);
        }
        else
        {
            rotateRight(n->parent);
        }
    }

    deleteCase3(n);
}

void RBTree::deleteCase3(Node* n)
{
    Node* s = n->sibling();
    if(n->parent->red==0&&s->red==0&&s->left->red==0&&s->right->red==0)
    {
        s->red=1;
        deleteCase1(n->parent);
    }
    else deleteCase4(n);
}

void RBTree::deleteCase4(Node* n)
{
    Node* s = n->sibling();
    if(n->parent->red==1&&s->red==0&&s->left->red==0&&s->right->red==0)
    {
        s->red=1;
        n->parent->red=0;
    }
    else deleteCase5(n);
}

void RBTree::deleteCase5(Node* n)
{
    Node *s = n->sibling();

        if  (s->red==0) {
            if ((n == n->parent->left) &&
                (s->right->red==0) &&
                (s->left->red==1)) {
                s->red==1;
                s->left->red==0;
                rotateRight(s);
            } else if ((n == n->parent->right) &&
                       (s->left->red==0) &&
                       (s->right->red==1)) {
                s->red==1;
                s->right->red == 0;
                rotateLeft(s);
            }
        }
        deleteCase6(n);
}

void RBTree::deleteCase6(Node* n)
{
    Node *s = n->sibling();

        s->red = n->parent->red;
        n->parent->red=0;

        if (n == n->parent->left) {
            s->right->red=0;
            rotateLeft(n->parent);
        } else {
            s->left->red=0;
            rotateRight(n->parent);
        }
}

void RBTree::rotateLeft(Node* n)
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

void RBTree::rotateRight(Node* n)
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


