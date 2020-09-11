//
//  Red_Black_Tree.cpp
//  红黑树
//
//  Created by 吴席垒 on 2020/8/20.
//  Copyright © 2020 吴席垒. All rights reserved.
//

#include "Red_Black_Tree.hpp"
void RBTREE::LEFT_ROTATE(RBTNode *x)
{
    RBTNode *y=x->right;
    x->right=y->left;
    if (y->left!=nullptr)
    {
        y->left->parent=x;
    }
    y->parent = x->parent;
    if (x->parent==nullptr)
    {
        root = y;
    }
    else if (x->parent->left == x)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}
void RBTREE::RIGHT_ROTATE(RBTNode *y)
{
    RBTNode *x=y->left;
    y->left=x->right;
    if (x->right!=nullptr) {
        x->right->parent=x;
    }
    x->parent=y->parent;
    if (y->parent==nullptr) {
        root=y;
    }
    else if (y->parent->right==y)
    {
        y->parent->right=x;
    }
    else
    {
        y->parent->right=x;
    }
    x->right=y;
    y->parent=x;
}
void RBTREE::RB_INSERT(RBTNode *z)
{
    RBTNode *y=nullptr;
    RBTNode *x=root;
    while (x!=nullptr)
    {
        y=x;
        if (z->key<x->key)
        {
            x=x->left;
        }
        else
            x=x->right;
    }
    z->parent=y;
    if (y==nullptr) {
        root=z;
    }
    else if (z->key<y->key)
        y->left=z;
    else
        y->right=z;
    z->left=nullptr;
    z->right=nullptr;
    z->color=RED;
    RB_INSERT_FIXUP(z);
}

void RBTREE::RB_INSERT_FIXUP(RBTNode *z)
{
    RBTNode *y;
    while (z->parent->color==RED)
    {
        if (z->parent==z->parent->parent->left)
        {
            y=z->parent->parent->right;
            if (y->color==RED)
            {
                z->parent->color=BLACK;
                y->color=BLACK;
                z->parent->parent->color=RED;
                z=z->parent->parent;
            }
            else if(z==z->parent->right)
            {
                z=z->parent;
                LEFT_ROTATE(z);
            }
            z->parent->color=BLACK;
            z->parent->parent->color=RED;
            RIGHT_ROTATE(z->parent->parent);
        }
        else if(z->parent==z->parent->parent->right)
        {
            y=z->parent->parent->left;
            if (y->color==RED)
            {
                z->parent->color=BLACK;
                y->color=BLACK;
                z->parent->parent->color=RED;
                z=z->parent->parent;
            }
            else if(z==z->parent->left)
            {
                z=z->parent;
                LEFT_ROTATE(z);
            }
            z->parent->color=BLACK;
            z->parent->parent->color=RED;
            RIGHT_ROTATE(z->parent->parent);
        }
        else
        {
            cout<<"error:RB_INSERT_FIXUP"<<endl;
        }
    }
    root->color=BLACK;
}
void RBTREE::RB_TRANSPLANT(RBTNode *u,RBTNode *v)
{
    if (u->parent==nullptr)
    {
        root=v;
    }
    else if (u==u->parent->left)
    {
        u->parent->left=v;
    }
    else
    {
        u->parent->right=v;
    }
    v->parent=u->parent;
}
void RBTREE::RB_DELETE(RBTNode *z)
{
    RBTNode *y=z;
    RBTColor y_original_color=y->color;
    RBTNode *x;
    if (z->left==nullptr) {
        x=z->right;
        RB_TRANSPLANT(z, z->right);
    }
    else if (z->right==nullptr)
    {
        x=z->left;
        RB_TRANSPLANT(z, z->left);
    }
    else
    {
        y=RBTREE_TREE_MINMUM(z->right);
        y_original_color=y->color;
        x=y->right;
        if (y->parent==z) {
            x->parent=y;
        }
        else
        {
            RB_TRANSPLANT(y, y->right);
            y->right=z->right;
            y->right->parent=y;
        }
        RB_TRANSPLANT(z, y);
        y->left=z->left;
        y->left->parent=y;
        y->color=z->color;
    }
    if (y_original_color==BLACK)
    {
        RB_DELET_FIXUP(x);
    }
}

RBTNode *RBTREE::RBTREE_TREE_MINMUM(RBTNode *x)
{
    while (x->right!=nullptr) {
        x=x->right;
    }
    return x;
}

void RBTREE::RB_DELET_FIXUP(RBTNode *x)
{
    RBTNode *w;
    while ( (x!=root) && (x->color==BLACK) )
    {
        if (x==x->parent->left)
        {
            w=x->parent->right;
            if (w->color==RED)
            {
                w->color=BLACK;
                x->parent->color=RED;
                LEFT_ROTATE(x->parent);
                w=x->parent->right;
            }
            if (w->left->color==BLACK&&w->right->color==BLACK)
            {
                w->color=RED;
                x=x->parent;
            }
            else if (w->right->color==BLACK)
            {
                w->left->color=BLACK;
                w->color=RED;
                RIGHT_ROTATE(w);
                w=x->parent->right;
            }
            w->color=x->parent->color;
            x->parent->color=BLACK;
            w->right->color=BLACK;
            LEFT_ROTATE(x->parent);
            x=root;
        }
        else
        {
            w=x->parent->left;
            if (w->color==RED)
            {
                w->color=BLACK;
                x->parent->color=RED;
                LEFT_ROTATE(x->parent);
                w=x->parent->left;
            }
            if (w->right->color==BLACK&&w->left->color==BLACK)
            {
                w->color=RED;
                x=x->parent;
            }
            else if (w->left->color==BLACK)
            {
                w->right->color=BLACK;
                w->color=RED;
                RIGHT_ROTATE(w);
                w=x->parent->left;
            }
            w->color=x->parent->color;
            x->parent->color=BLACK;
            w->left->color=BLACK;
            LEFT_ROTATE(x->parent);
            x=root;
        }
    }
    x->color=BLACK;
}
