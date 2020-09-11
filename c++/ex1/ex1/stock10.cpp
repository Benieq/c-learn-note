//
//  stock10.cpp
//  ex1
//
//  Created by 吴席垒 on 2020/8/5.
//  Copyright © 2020 吴席垒. All rights reserved.
//

#include "stock10.hpp"
#include <iostream>
using namespace std;

Stock::Stock(){
    cout<<"Default constructor called\n";
    company="no name";
    shares=0;
    share_val=0.0;
    total_val=0.0;
}
Stock::Stock(const string &co,long n,double pr){
    cout<<"Constructor using "<<co<<" called\n";
    company=co;
    if(n<0){
        cout<<"Number of shares can't be negative."
        <<company<<" shares set to 0.\n";
        shares=0;
    }
    else
        shares=n;
    share_val=pr;
    set_tot();
}
Stock::~Stock(){
    cout<<"Bye,"<<company<<"!\n";
}
//void Stock::acquire(const string &co,long n,double //pr){
//    company=co;
//    if(n<0)
//    {
//        cout<<"Number of shares can't be negative;"
//        <<company<<" shares set to 0.\n";
//        shares=0;
//    }
//    else
//        shares=n;
//    share_val=pr;
//    set_tot();
//}
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
