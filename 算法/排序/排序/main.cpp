//
//  main.cpp
//  排序
//
//  Created by 吴席垒 on 2020/8/15.
//  Copyright © 2020 吴席垒. All rights reserved.
//

#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
//void exchange(int &a,int &b);
void vector_int_out(vector<int>A);
//堆排序
int PARENT(int i);//parent
int LEFT(int i);
int RIGHT(int i);
void MAX_HEAPLEY(vector<int>&A,int i);//max_heapley 维护堆的性质
void exchange_0(int &a,int &b);
int use_MAX_HEAPLEY_2();
int use_MAX_HEAPLEY_ALL();
void BUILD_MAX_HEAP(vector<int>&A);//建堆
int use_of_BUILD_MAX_HEAP();
//优先队列

//快速排序
class Quick_SORT_CLASS
{
private:
    vector<int>A={1,2,4,3,5};
    
    //vector<double>A={0.79,0.13,0.16,0.64,0.39,0.20,0.89,0.53,0.71,0.42};
public:
    void QUICKSORT(int p,int r);
    int PARTITION(int p,int r);
    int vector_size();
    void out_vector();
    
    //void BUCKET_SORT();
};
int use_of_Quick_SORT_CLASS();
//计数排序
void counting_sort(vector<int>&A,vector<int>&B,int k);
int use_of_counting_sort();
void counting_sort_of_beni(vector<int>A,vector<int>&B);
int use_of_counting_sort_of_beni();

//基数排序
//桶排序 X:写在Quick_SORT_CLASS类中的BUCKET_SORT 失败
void BUCKET_SORT(vector<double>A,vector<double>&sort_of_A);
void vector_double_out(vector<double>A);
void bucket_sort(int a[], int n, int max);
int use_bucket_suse_ort();

//中位数和顺序统计量
int MINIMUM(vector<int>A);
int main()
{
    vector<int>A={1,2,3};
    cout<<MINIMUM(A);
    return 0;
}
int MINIMUM(vector<int>A){
    int min=A[1-1];
    for (int i=2; i<=A.size(); i++) {
        if (min>A[i-1]) {
            min=A[i-1];
        }
    }
    return min;
}


int use_bucket_suse_ort(){
    //vector<double>A={0.79,0.13,0.16,0.64,0.39,0.20,0.89,0.53,0.71,0.42};
    int A[]={79,13,16,64,39,20,89,53,71,42};
    int n=10;
    int MAX=89;
    //bucket_sort(A[],n,MAX);
    return 0;
}
void vector_double_out(vector<double>A){
    for (int i=0; i<A.size(); i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
/*
 * 桶排序
 *
 * 参数说明：
 *   a -- 待排序数组
 *   n -- 数组a的长度
 *   max -- 数组a中最大值的范围
 */
void bucket_sort(int a[], int n, int max)
{
  int i, j;
  int *buckets;

  if (a==NULL || n<1 || max<1)
    return ;

  // 创建一个容量为max的数组buckets，并且将buckets中的所有数据都初始化为0。
  if ((buckets=(int *)malloc(max*sizeof(int)))==NULL)
    return ;
  memset(buckets, 0, max*sizeof(int));

  // 1. 计数
  for(i = 0; i < n; i++)
    buckets[a[i]]++;

  // 2. 排序
  for (i = 0, j = 0; i < max; i++)
    while( (buckets[i]--) >0 )
      a[j++] = i;

  free(buckets);
}



//void BUCKET_SORT(vector<double>A,vector<double>&sort_of_A){
//    int n=A.size();
//    vector<vector<int>>B(n);
//    vector<int>b;
//    for (int i=0; i<=n-1; i++) {
//        B.push_back(b);
//    }
//    for (int i=1; i<=n; i++) {
//        int k= floor(n*A[i]);
//        B[k-1].push_back(A[i]);
//    }
//    //vector<int>sort;
//    for (int i=0; i<B.size(); i++) {
//        for (int j=0; j<B[i].size(); j++) {
//            sort_of_A.push_back(B[i][ j]);
//        }
//    }
//    //vector_int_out(sort);
//}

int use_of_counting_sort_of_beni()

{
    vector<int>A={2,5,3,0,2,3,0,3};
    vector<int>B(A.size());
    counting_sort_of_beni(A, B);
    vector_int_out(B);
    return 0;
    
}
void counting_sort_of_beni(vector<int>A,vector<int>&B)
{
    int n=A.size();
    int MAX_A=*max_element(A.begin(),A.end());
    vector<int>C(MAX_A+1);
    for (int i=0; i<=MAX_A; i++) {
        C[i]=0;
    }
    for (int i=0; i<n; i++) {
        C[A[i]]=C[A[i]]+1;
    }
    for (int i=1; i<=MAX_A; i++) {
        C[i]=C[i]+C[i-1];
    }
    for (int i=n; i>=1; i--) {
        B[C[A[i-1]]]=A[i-1];
        C[A[i-1]]=C[A[i-1]]-1;
    }
    
    
}

int use_of_counting_sort()

{
    vector<int>A={2,5,3,0,2,3,0,3};
    int n=A.size();
    vector<int>B(n);
    int MAX_A =  *max_element(A.begin(),A.end());
    //cout<<MAX_A<<endl;
    counting_sort(A, B, MAX_A);
    vector_int_out(B);
    return 0;
}
void counting_sort(vector<int>&A,vector<int>&B,int k)
{
    vector<int>C(k+1);
    for (int i=0; i<=k; i++) {
        C[i]=0;
    }
    for (int j=1; j<=A.size(); j++) {
        C[A[j-1]]=C[A[j-1]]+1;
    }
    for (int i=1; i<=k; i++) {
        C[i]=C[i]+C[i-1];
    }
    for (int j=A.size(); j>=1; j--) {
        B[C[A[j-1]]-1]=A[j-1];
        C[A[j]-1]=C[A[j]-1]-1;
    }
    
}
int use_of_Quick_SORT_CLASS(){
    Quick_SORT_CLASS A;
    int n=A.vector_size();
    A.PARTITION(1, n);
    A.out_vector();
    return 0;
}
int Quick_SORT_CLASS::vector_size(){
    return A.size();
}
void Quick_SORT_CLASS::out_vector(){
    vector_int_out(A);
}

void Quick_SORT_CLASS::QUICKSORT(int p,int r)
{
    if(p<r)
    {
        int q=PARTITION(p, r);
        QUICKSORT(p, q-1);
        QUICKSORT(q+1, r);
    }
}
int Quick_SORT_CLASS::PARTITION(int p,int r)
{
    int x=A[r-1];
    int i=p-1;
    for (int j=p; j<=r-1;j++) {
        if (A[j-1]<=x) {
            i=i+1;
            exchange_0(A[i-1], A[j-1]);
        }
    }
    exchange_0(A[i+1-1], A[r-1]);
    return i+1;
}

int use_of_BUILD_MAX_HEAP()
{
    vector<int>A={4,1,3,2,16,9,10,14,8,7};
    BUILD_MAX_HEAP(A);
    vector_int_out(A);
    return 0;
}
void BUILD_MAX_HEAP(vector<int>&A)
{
    int A_heap_size=A.size();
    for (int i=A.size()/2; i>=1; i--) {
        MAX_HEAPLEY(A, i);
    }
}
int use_MAX_HEAPLEY_ALL(){
    vector<int>A={16,4,10,14,7,9,3,2,8,1};
    vector_int_out(A);
    for(int i=1;i<=A.size();i++){
        MAX_HEAPLEY(A, i);
    }
    vector_int_out(A);
    return 0;
}
int use_MAX_HEAPLEY_2() {
    vector<int>A={16,4,10,14,7,9,3,2,8,1};
    vector_int_out(A);
    MAX_HEAPLEY(A, 2);
    vector_int_out(A);
    return 0;
}
void MAX_HEAPLEY(vector<int>&A,int i)
{
    int l=LEFT(i);
    int r=RIGHT(i);
    int largest;
    if(l<=A.size()&&A[l-1]>A[i-1])
    {
        largest=l;
    }
    else{
        largest=i;
    }
    if(r<=A.size()&&A[r-1]>A[largest-1])
    {
        largest=r;
    }
    if(largest!=i)
    {
        exchange_0(A[i-1], A[largest-1]);
        MAX_HEAPLEY(A, largest);
    }
}
void exchange_0(int &a,int &b)
{
    int key=a;
    a=b;
    b=key;
}
int PARENT(int i)
{
    return (i/2);
}
int LEFT(int i)
{
    return (2*i);
}
int RIGHT(int i)
{
    return (2*i+1);
}
void vector_int_out(vector<int>A)
{
    for (int i=0; i<A.size(); i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

