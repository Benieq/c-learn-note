//
//  string.cpp
//  string
//
//  Created by 吴席垒 on 2020/8/6.
//  Copyright © 2020 吴席垒. All rights reserved.
//
#include <cstring>
#include "string1.hpp"
using std::cin;
using std::cout;

int String::num_strings=0;

int String::HowMany()
{
    return num_strings;
}

String::String(const char*s)
{
    len=std::strlen(s);
    str=new char[len+1];
    std::strcpy(str, s);
    num_strings++;
}

String::String()
{
    len=4;
    str=new char[1];
    str[0]='\0';
    num_strings++;
}

String::String (const String & st) //noexcept
//隐式声明的复制构造函数的定义
{
    num_strings++;
    len=st.len;
    str=new char[len+1];
    std::strcpy(str,st.str);
}
String::~String()
{
    --num_strings;
    delete [] str;
}
