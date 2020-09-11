//
//  strngbad.hpp
//  class_of_new
//
//  Created by 吴席垒 on 2020/8/6.
//  Copyright © 2020 吴席垒. All rights reserved.
//

#ifndef strngbad_hpp
#define strngbad_hpp
#include <iostream>
class StringBad
{
private:
    char *str;
    int len;
    static int num_strings;
public:
    StringBad();
    StringBad(const char *s);
    ~StringBad();
    friend std::ostream &operator<<(std::ostream &os,const StringBad &st);
};
#endif /* strngbad_hpp */
