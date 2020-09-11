//
//  stock00.cpp
//  ex1
//
//  Created by 吴席垒 on 2020/8/5.
//  Copyright © 2020 吴席垒. All rights reserved.
//

#include "stock00.hpp"
#include <iostream>
using namespace std;

void Stock::acquire(const string &co,long n,double pr){
    company=co;
    if(n<0)
    {
        cout<<"Number of shares can't be negative;"
        <<company<<" shares set to 0.\n";
        shares=0;
    }
    else
        shares=n;
    share_val=pr;
    set_tot();
}
void Stock::buy(long num ,double price){
    if(num<0)
    {
        cout<<"Number of shares can't be negative."
        <<"Transaction is aborted.\n";
    }
    else
    {
        shares+=num;
        share_val=price;
        set_tot();
    }
}
void Stock::sell(long num,double price){
    if(num<0)
    {
        cout<<"Number of shares can't be negative."
        <<"Transaction is aborted.\n";
    }
    else
    {
        shares-=num;
        share_val=price;
        set_tot();
    }
}
void Stock::update(double price){
    share_val=price;
    set_tot();
}
void Stock::show(){
    //cout<<"****************"<<"\n";
    //cout<<"Company: "<<company<<"\n"
    //    <<"Shares: "<<shares<<"\n"
    //    <<"Share Price: $ "<<share_val<<"\n"
    //    <<"Total Worth: $ "<<total_val<<"\n";
    //cout<<"****************"<<"\n";
    //cout<<endl;
    ios_base::fmtflags orig=cout.setf(ios_base::fixed,ios_base::floatfield);
    streamsize prec=cout.precision(3);
    cout<<"****************"<<"\n";
    cout<<"Company: "<<company<<"\n"
        <<"Shares: "<<shares<<"\n"
    <<"Share Price: $ "<<share_val<<"\n";
    cout.precision(2);
    cout<<"Total Worth: $ "<<total_val<<"\n";
    cout<<"****************"<<"\n";
    cout<<endl;
    cout.setf(orig,ios_base::floatfield);
    cout.precision(prec);
}
