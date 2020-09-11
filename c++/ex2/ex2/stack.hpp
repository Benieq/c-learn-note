//
//  stack.hpp
//  ex2
//
//  Created by 吴席垒 on 2020/8/5.
//  Copyright © 2020 吴席垒. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>
typedef unsigned long Item;
class Stack{
private:
    enum{MAX=10};
    Item items[MAX];
    int top;
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item&item);
    bool pop(Item &item);
    
};
#endif /* stack_hpp */
