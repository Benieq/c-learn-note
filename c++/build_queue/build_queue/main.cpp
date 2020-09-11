//
//  main.cpp
//  build_queue
//
//  Created by 吴席垒 on 2020/8/7.
//  Copyright © 2020 吴席垒. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.hpp"
const int MIN_PER_HR=60;
bool newcustomer(double x);
int main(){
    
}
bool newcustomer(double x){
    return (std::rand()*x/RAND_MAX<1);
}

