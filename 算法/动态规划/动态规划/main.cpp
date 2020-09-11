//
//  main.cpp
//  动态规划
//
//  Created by 吴席垒 on 2020/8/20.
//  Copyright © 2020 吴席垒. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//钢条
const int MIN=-500000;
const int MAX=500000;
int CUT_ROD(int p[],int n);
int MEMOIZED_CUT_ROD(int p[],int n);
int MEMOIZED_CUT_ROD_AUX(int p[],int n,int r[]);
int use_MEMOIZED_CUT_ROD();

//矩阵链乘法


int main ()
{
    return 0;
}

int use_MEMOIZED_CUT_ROD() {
    int p[]={1,5,8,9,10,17,17,20,24,30};
    for (int i=0; i<10; i++) {
        cout<<"P["<<i<<"]:"<<p[i]<<endl;
    }
    //int r[]={};
    //for (int i=0; i<=9; i++) {
    //    r[i]=MIN;
    //}for (int i=0; i<10; i++) {
    //    cout<<"r["<<i<<"]:"<<r[i]<<endl;
    //}
    cout<<MEMOIZED_CUT_ROD(p, 10)<<endl;
    return 0;
}
int MEMOIZED_CUT_ROD(int p[],int n)
{
    int r[]={};
    for (int i=0; i<=n; i++) {
        r[i]=MIN;
    }
    return MEMOIZED_CUT_ROD_AUX(p,n,r);
}
int MEMOIZED_CUT_ROD_AUX(int p[],int n,int r[])
{
    int q;
    if (r[n]>=0 ) {
        return r[n];
    }
    if (n==0) {
        q=0;
    }
    else
    {
        q=MIN;
        for (int i=1; i<=n; i++) {
            q=max(q, p[i-1]+MEMOIZED_CUT_ROD_AUX(p, n-i, r));
        }
    }
    r[n]=q;
    return q;
}

int CUT_ROD(int p[],int n)
{
    if (n==0) {
        return 0;
    }
    int q=MIN;
    for (int i=1; i<=n; i++) {
        q=max(q, p[i-1]+CUT_ROD(p, n-i));
    }
    return q;
}
