//
//  stack.cpp
//  ex2
//
//  Created by 吴席垒 on 2020/8/5.
//  Copyright © 2020 吴席垒. All rights reserved.
//

#include "stack.hpp"
Stack::Stack()
{
    top=0;
}
bool Stack::isempty() const{
    return top==0;
}
bool Stack::isfull() const{
    return top==MAX;
}
bool Stack::push(const Item&item)
{
    if(top<MAX)
    {
        items[top++]=item;
        return true;
    }
    else
        return false;
}
bool Stack::pop(Item &item)
{
    if(top>0)
    {
        item=items[--top];
        return true;
    }
    else
        return false;
}
