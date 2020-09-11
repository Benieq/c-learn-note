//
//  string.hpp
//  string
//
//  Created by 吴席垒 on 2020/8/6.
//  Copyright © 2020 吴席垒. All rights reserved.
//
#ifndef string1_hpp
#define string1_hpp
#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
    char *str;
    int len;
    static int num_strings;
    static const int CINLIM=80;
public:
    //constructors and other methods
    String();
    String(const char *s);
    ~String();
    String(const char &);
    //overloaded operator methods
    String &operator=(const String &);
    String &operator=(const char*);
    char &operator[](int i);
    const char &operator[](int i)const;
    //friend
    friend bool operator<(const String &st,const String &st2);
    friend bool operator>(const String &st1,const String &st2);
    friend bool operator==(const String &st,const String &st2);
    friend ostream &operator<<(ostream &os,const String &st);
    friend istream &operator<<(istream &os,const String &st);
    //static
    static int HowMany();
};
#endif
