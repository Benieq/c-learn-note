//
//  main.cpp
//  ex_of_new
//
//  Created by 吴席垒 on 2020/8/7.
//  Copyright © 2020 吴席垒. All rights reserved.
//

#include <iostream>
#include <string>
#include <new>

using namespace std;
const int BUF=512;
class JustTesting
{
private:
    string works;
    int number;
public:
    JustTesting(const string &s="Just Testing",int n=0)
    {
        works=s;
        number=n;
        cout<<works<<" constructed\n";
    }
    ~JustTesting()
    {
        cout<<works<<" destroyed\n";
    }
    void Show() const
    {
        cout<<works<<", "<<number<<endl;
    }
};
int main()
{
    char *buffer=new char[BUF];
    JustTesting *pc1,*pc2;
    pc1=new(buffer) JustTesting;
    pc2=new JustTesting("Heap1",20);
    
    cout<<"Memory block addresses:\n"<<"buffer:"<<(void*)buffer<<" heap:"<<pc2<< endl;
    cout << "Memory contents:" << endl;
    cout<<pc1<<": ";
    pc1->Show();
    cout<<pc2<<": ";
    pc2->Show();
    
    JustTesting *pc3,*pc4;
    pc3=new (buffer) JustTesting("Bad Idea",6);
    pc4=new JustTesting("Heap2",10);
    
    cout << "Memory contents:\n";
    cout<<pc3<<": ";
    pc3->Show();
    cout<<pc4<<": ";
    pc4->Show();
    
    delete pc2;
    delete pc4;
    delete [] buffer;
    cout<<"Done\n";
    return 0;
    
}

