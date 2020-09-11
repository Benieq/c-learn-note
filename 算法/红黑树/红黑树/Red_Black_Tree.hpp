//
//  Red_Black_Tree.hpp
//  红黑树
//
//  Created by 吴席垒 on 2020/8/20.
//  Copyright © 2020 吴席垒. All rights reserved.
//

#ifndef Red_Black_Tree_hpp
#define Red_Black_Tree_hpp

#include <iostream>
using namespace std;
enum RBTColor{RED, BLACK};

class RBTNode
{
private:
public:
    RBTColor color;    // 颜色
    int key;            // 关键字(键值)
    RBTNode *left;    // 左孩子
    RBTNode *right;    // 右孩子
    RBTNode *parent; // 父结点
};
class RBTREE
{
private:
    RBTNode *root;
    //RBTNode *nil;
public:
    void LEFT_ROTATE(RBTNode *x);
    void RIGHT_ROTATE(RBTNode *y);
    void RB_INSERT(RBTNode *z);
    void RB_INSERT_FIXUP(RBTNode *z);
    void RB_TRANSPLANT(RBTNode *u,RBTNode *v);
    void RB_DELETE(RBTNode *z);
    void RB_DELET_FIXUP(RBTNode *x);
    
    RBTNode * RBTREE_TREE_MINMUM(RBTNode *x);
};

#endif /* Red_Black_Tree_hpp */
