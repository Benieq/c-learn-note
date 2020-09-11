//
//  main.cpp
//  copy_function
//
//  Created by 吴席垒 on 2020/8/7.
//  Copyright © 2020 吴席垒. All rights reserved.
//


#include <iostream>
using namespace std;
 
//定义一个Point类
class Point{
public:
    Point(int xx=0,int yy=0):x(xx),y(yy){}     //构造函数
    ~Point(){ };                              //析构函数
    Point(const Point &p);                //复制构造函数
    int getX()const{return x;}
    int getY()const {return y;}
private:
    int x,y;//私有成员
 
};
 
Point::Point(const Point &p)
{
    x = p.x;
    y = p.y;
    cout << "Calling the copy constructor" <<endl;
 
}
//形参作为Point类对象的函数
void fun1(Point p)
{
    cout<< p.getX()<<endl;
 
}
 
//返回类的对象
Point fun2()
{
    Point a(1,2);
    return a;
}
 
int main()
{
    Point a(4);    //第一个对象A,该过程利用了重载，后面的y默认为0
    
    Point b(a);      //此时调用copy构造函数；情况1，用a初始化b，第一次调用copy构造函数
    cout << b.getX()<<endl;
 
    fun1(b);  //此时调用copy构造函数；类的对象在函数中为实参，第二次调用copy构造函数
 
    b = fun2();//此时调用copy构造函数；函数返回值为类的对象，第三次调用copy构造函数
    cout << b.getX()<<endl;
    return 0;
}

