//
//  main.cpp
//  基础
//
//  Created by 吴席垒 on 2020/8/8.
//  Copyright © 2020 吴席垒. All rights reserved.
//

#include <iostream>
#include <vector>


using namespace std;
const int MAX_NUMBER =500000;//定义正负无穷大 全局常量
const int MIN_NUMBER=-500000;
int gcd(int p, int q);//辗转相除法 cout<<gcd(13,14)<<endl;
void vector_int_out(vector<int>A);//vector 输出
void insertion_sort(vector<int> &A);//插入排序
int use_of_insertion_sort();

void merge (vector<int>A,int p,int q,int r);//归并p17 未实现
void merge_sort(vector<int>A,int p,int r);//
int use_of_merge_sort();

//最大子数组问题
void find_max_crossing_subarray(vector<int>A,int low,int mid,int high,vector<int> &out_of_max );
/*输出为数组 out_of_max
0:max_left
1:max_right
2:left_sum+right_sum*/
void find_maximum_subarray(vector<int>A,int low,int high,vector<int>&out_of_fint_max);
int use_of_find_max_subarray();

//矩阵乘法的Strassen算法
void out_of_Matrix(vector<vector<int>> A);//vector<vector<int>>输出
void square_matrix_multiply(vector<vector<int>>A,vector<vector<int>>B,vector<vector<int>>&C);
//n*n的矩阵乘法 C为返回函数
//返回数组 三种方法 动态数组 指针 结构体
int use_of_square_matrix_multiply();
int *Max(int *arr,int n);//返回数组例子 动态数组
int use_of_MAX();
int  **Max(int **arr,int n,int m);//
int use_of_xx_MAX();//

//分治解决Strassen乘法
void square_matrix_multiply_recursive
 (vector<vector<int>>A,
  vector<vector<int>>B,
  vector<vector<int>>&C);
void partition_matrix_into_equation
 (vector<vector<int>>A,
  vector<vector<int>>&A11,vector<vector<int>>&A12,
  vector<vector<int>>&A21,vector<vector<int>>&A22);
void add_matrix(vector<vector<int>>A1,vector<vector<int>>A2,vector<vector<int>>
                &A);
void inverse_operation_of_partition_matrix_into_equation(
vector<vector<int>>&A,
vector<vector<int>>A11,vector<vector<int>>A12,
vector<vector<int>>A21,vector<vector<int>>A22);
int use_Strassen_bad();//失败

int main ( )
{
    cout<<1<<endl;
    return 0;
}
int use_Strassen_bad()
{
    vector<vector<int>>A=
    {
        {1,0},
        {0,1}
    };
    vector<vector<int>>B=
    {
        {1,0},
        {0,2}
    };
    vector<vector<int>>C;
    //={
    //    {MIN_NUMBER,MIN_NUMBER},
    //    {MIN_NUMBER,MIN_NUMBER}
    //};
    square_matrix_multiply_recursive(A, B, C);
    out_of_Matrix(C);
    return 0;
}
void inverse_operation_of_partition_matrix_into_equation(
vector<vector<int>>&A,
vector<vector<int>>A11,vector<vector<int>>A12,
vector<vector<int>>A21,vector<vector<int>>A22)
{
    int n=A.size();
    
    for(int i=0;i<n/2;i++)
    {
        for (int j=0; j<n/2; j++) {
            A[i][j]=A11[i][j];
        }
    }
    for(int i=0;i<n/2;i++)
    {
        for (int j=0; j<n/2; j++) {
            A[i][j+n/2]=A11[i][j]=A[i][j+n/2];
        }
    }
    for(int i=0;i<n/2;i++)
    {
        for (int j=0; j<n/2; j++) {
            A[i+n/2][j]=A21[i][j];
        }
    }
    for(int i=0;i<n/2;i++)
    {
        for (int j=0; j<n/2; j++) {
            A[i+n/2][j+n/2]=A22[i][j]=A[i+n/2][j+n/2];
        }
    }
}
void add_matrix(vector<vector<int>>A1,vector<vector<int>>A2,vector<vector<int>>&A)
{
    for (int i=0; i<A.size(); i++) {
        for (int j=0; j<A[i].size(); j++) {
            A[i][j]=A1[i][j]+A2[i][j];
        }
    }
}
void partition_matrix_into_equation(vector<vector<int>>A,
                                    vector<vector<int>>&A11,vector<vector<int>>&A12,
                                    vector<vector<int>>&A21,vector<vector<int>>&A22)
{
    int n=A.size();
    vector<int>Cl(n/2);
    for (int i=0; i<n/2; i++) {
        A11.push_back(Cl);
        A12.push_back(Cl);
        A21.push_back(Cl);
        A22.push_back(Cl);
    }
    for(int i=0;i<n/2;i++)
    {
        for (int j=0; j<n/2; j++) {
            A11[i][j]=A[i][j];
        }
    }
    for(int i=0;i<n/2;i++)
    {
        for (int j=0; j<n/2; j++) {
            A11[i][j]=A[i][j+n/2];
        }
    }
    for(int i=0;i<n/2;i++)
    {
        for (int j=0; j<n/2; j++) {
            A21[i][j]=A[i+n/2][j];
        }
    }
    for(int i=0;i<n/2;i++)
    {
        for (int j=0; j<n/2; j++) {
            A22[i][j]=A[i+n/2][j+n/2];
        }
    }
    
}
void square_matrix_multiply_recursive(vector<vector<int>>A,vector<vector<int>>B,vector<vector<int>>&C)
{
    int n=A.size();
    vector<int>Cl(n);
    for (int i=0; i<n; i++) {
        C.push_back(Cl);
    }
    if(n==1)
    {
        C[0][0]=A[0][0]*B[0][0];
    }
    else
    {
        vector<vector<int>>D1;
        vector<vector<int>>D2;

        vector<vector<int>>A11;vector<vector<int>>A12;
        vector<vector<int>>A21;vector<vector<int>>A22;
        
        vector<vector<int>>B11;vector<vector<int>>B12;
        vector<vector<int>>B21;vector<vector<int>>B22;
        
        vector<vector<int>>C11;vector<vector<int>>C12;
        vector<vector<int>>C21;vector<vector<int>>C22;
        
        partition_matrix_into_equation(A,A11,A12,A21,A22);
        partition_matrix_into_equation(B,B11,B12,B21,B22);
        partition_matrix_into_equation(C,C11,C12,C21,C22);
        
        square_matrix_multiply_recursive(A11,B11,D1);
        square_matrix_multiply_recursive(A12,B21,D2);
        add_matrix(D1,D2,C11);
        
        square_matrix_multiply_recursive(A11,B12,D1);
        square_matrix_multiply_recursive(A12,B22,D2);
        add_matrix(D1,D2,C12);
        
        square_matrix_multiply_recursive(A21,B11,D1);
        square_matrix_multiply_recursive(A22,B21,D2);
        add_matrix(D1,D2,C21);
        
        square_matrix_multiply_recursive(A21,B12,D1);
        square_matrix_multiply_recursive(A22,B22,D2);
        add_matrix(D1,D2,C22);
        
        inverse_operation_of_partition_matrix_into_equation(C,C11,C12,C21,C22);
        
    }
    
}

int  **Max(int **arr,int n,int m)
{
    int **data;
    data=(int **)malloc(n*sizeof(int *));
    for (int i=0;i<n;i++)
        data[i]=(int *)malloc(2*sizeof(int));
    for (int i=0;i<n;++i)
    {
        int maxNum=0;
        for (int j=0;j<m;++j)
        {
            //printf("arr[%d][%d]=%d ",i,j,*((int *)arr+m*i+j));
            if (*((int *)arr+m*i+j)>maxNum)
            {
                maxNum=*((int *)arr+m*i+j);
                data[i][0]=maxNum;data[i][1]=j;
            }
        }
        //printf("\n");
    }
    return data;
}
 
int use_of_xx_MAX()
{
    int a[2][3]=
    {5,2,
        4,6,
        3,9};
    int **b=Max((int **)a,2,3);
    for (int i=0;i<2;i++)
    {
        printf("the maximum num for row %d is %d\n",i+1,b[i][0]);
        printf("the maximum num for row %d is in %d",i+1,b[i][1]+1);
        printf("\n");
    }
    for(int i=0;i<2;i++)
        free(b[i]);
    free(b);
    return 0;
}

int *Max(int *arr,int n)
{
    int *a=(int *)malloc(2*sizeof(int));
    int maxNum=0;
    int maxIndex=-1;
    for(int i=0;i<n;i++)
    {
        if (arr[i]>maxNum)
        {
            maxNum=arr[i];
            maxIndex=i+1;
        }
    }
    a[0]=maxNum;
    a[1]=maxIndex;
    return a;
}
 
int use_of_MAX()
{
    int a[2]={5,2};//a[0]=5,a[1]=2;
    int *b=Max(a,2);
    cout<<b[0]<<" "<<b[1];
    return 0;
}
int use_of_square_matrix_multiply()
{
    vector<vector<int>>A=
    {
        {1,1},
        {0,1}
    };
    vector<vector<int>>B=
    {
        {1,1},
        {0,1}
    };
    out_of_Matrix(A);
    cout<<endl;
    out_of_Matrix(B);
    cout<<endl;
    vector<vector<int>>C;
    square_matrix_multiply(A,B,C);
    out_of_Matrix(C);
    return 0;
}


void square_matrix_multiply(vector<vector<int>>A,vector<vector<int>>B,vector<vector<int>>&C)
{
    int n=A.size();
    //int  C[n][n];
    vector<int>Cl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) {
            Cl.push_back(0);
            for (int k=0; k<n; k++) {
                Cl[j]=Cl[j]+A[i][k]*B[k][j];
            }//cout<<C[i][j]<<" ";
        }//cout<<endl;
        C.push_back(Cl);
        Cl.clear();
    }
}
void out_of_Matrix(vector<vector<int>> A)
{
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    //return 0;
}
int use_of_find_max_subarray()
{
    vector<int>A={1,-1,2,2};
    vector_int_out(A);
    int An=A.size();
    vector<int>A_max_sub;
    find_maximum_subarray(A,1,An,A_max_sub);
    vector_int_out(A_max_sub);
    for(int i=A_max_sub[0];i<=A_max_sub[1];i++)
    {
        cout<<A[i]<<"+";
    }
    cout<<"="<<A_max_sub[2]<<endl;
    return 0;
}
void find_maximum_subarray(vector<int>A,int low,int high,vector<int>&out_of_fint_max)
{
    if(high==low)
    {
        out_of_fint_max.push_back(low);
        out_of_fint_max.push_back(high);
        out_of_fint_max.push_back(A[low-1]);
        //eturn out_of_fint_max ;
    }
    else
    {
        int mid=(high+low)/2;
        vector<int>left;//0:left_low 1:left_high 2:left_sum
        find_maximum_subarray(A,low, mid,left);
        vector<int>right;//0:right_low 1:right_high 2:right_sum
        find_maximum_subarray(A, mid+1, high,right);
        vector<int>cross;//0:cross_low 1:cross_high 2:cross_sum
        find_max_crossing_subarray(A,low,mid,high,cross);
        if(left[2]>=right[2]&&left[2]>=cross[2])
        {
            out_of_fint_max.push_back(left[0]);
            out_of_fint_max.push_back(left[1]);
            out_of_fint_max.push_back(left[2]);
        }
        else if (right[2]>=left[2]&&right[2]>=cross[2])
        {
            out_of_fint_max.push_back(right[0]);
            out_of_fint_max.push_back(right[1]);
            out_of_fint_max.push_back(right[2]);
        }
        else
        {
            out_of_fint_max.push_back(cross[0]);
            out_of_fint_max.push_back(cross[1]);
            out_of_fint_max.push_back(cross[2]);
        }
    }
}

void find_max_crossing_subarray(vector<int>A,int low,int mid,int high,vector<int> &out_of_max)
{
    int left_sum=MIN_NUMBER;
    int sum=0;
    int max_left;
    for(int i=mid-1;i>=low-1;i--)
    {
        sum=sum+A[i];
        if(sum>left_sum)
        {
            left_sum=sum;
            max_left=i;
        }
    }
    int right_sum=MIN_NUMBER;
    sum=0;
    int max_right;
    for (int j=mid+1-1; j<=high-1; j++)
    {
        sum=sum+A[j];
        if(sum>right_sum)
        {
            right_sum=sum;
            max_right=j;
        }
    }
    out_of_max.push_back(max_left);
    out_of_max.push_back(max_right);
    out_of_max.push_back(left_sum+right_sum);
    
}

int use_of_merge_sort()
{
    vector<int> A={4,3,2,1};
    merge_sort(A, 1, 4);
    vector_int_out(A);
    return 0;
}
void merge_sort(vector<int>A,int p,int r)
{
    if (p<r)
    {
        int q=(p+r)/2;
        merge_sort(A, p, r);
        merge_sort(A, q+1, r);
        merge(A,p,q,r);
    }
}

void merge(vector<int>A,int p,int q,int r)
{
    //if(p<=q&&q<r)
    //{
    //
    //}
    //else
    //{
    //    cout<<"满足p<=q<r条件"<<endl;
    //    //return false;
    //}
    int n1=q-p+1;
    int n2=r-q;
    vector<int>L(n1+1);
    vector<int>R(n2+1);
    for (int i=0; i<=n1; i++) {
        L[i]=A[p+i-1];
    }
    for (int j=0; j<=n2; j++) {
        R[j]=A[q+j];
    }
    L[n1]=1000000;//代表无穷大
    R[n2]=1000000;
    int i=0;
    int j=0;
    for (int k=p; k<=r; k++)
    {
        if (L[i]<=R[j])
        {
            A[k]=L[i];
            i=i+1;
        }
        else
        {
            A[k]=R[j];
            j=j+1;
        }
    }
    
    
}
void insertion_sort(vector<int> &A)
{
    int key;
    int i;
    for(int j=1;j<A.size();j++)
    {
        key=A[j];
        i=j-1;
        while (i>=0&&A[i]>key) {
            A[i+1]=A[i];
            i=i-1;
        }
        A[i+1]=key;
        cout<<"j:"<<j<<" i:"<<i<<endl;
        vector_int_out(A);

    }
}
int use_of_insertion_sort()
{
    vector<int>A={4,3,2,1,9};
    insertion_sort(A);
    vector_int_out(A);
    return 0;
}
void vector_int_out(vector<int>A)
{
    for (int i=0; i<A.size(); i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int gcd(int p, int q)
{
    if (q==0) {
        return p;
    }
    int r=p%q;
    return gcd(q,r);
}
