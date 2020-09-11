//
//  stock00.hpp
//  ex1
//
//  Created by 吴席垒 on 2020/8/5.
//  Copyright © 2020 吴席垒. All rights reserved.
//

#ifndef stock00_hpp
#define stock00_hpp

#include <stdio.h>
#include <string>
using namespace std;
class Stock{
private:
    string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot(){total_val=share_val*shares;}
public:
    void acquire(const string &co,long n,double pr);
    void buy(long num ,double price);
    void sell(long num,double price);
    void update(double price);
    void show();
    
};

#endif /* stock00_hpp */
