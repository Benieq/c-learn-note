//
//  main.cpp
//  ex1
//
//  Created by 吴席垒 on 2020/8/4.
//  Copyright © 2020 吴席垒. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include<map>
#include<set>
#include <list>
//#include <memory>
//#include "stock00.hpp"
#include "stock10.hpp"

using namespace std;
int check();//初使确认
int file();//文件操作
int vectorsize();//vector如何增长
int stringnew();//string的几种初始化
int findex();//find example8
int exofsizeof();//
void biggies(vector<string>&words,vector<string>::size_type sz);
void elimDups(vector<string>&words);
int ex_of_map();//map 关联容器
int ex_of_map_and_set();//map and set
int size_of_set();
int ex_of_pair();
int pir_of_new();//指针 new
int do_while_ex();
int use_of_Stock_h_();//stock00类的使用例子
int usestock2();// ex of using stock10.h

int main( ){
    usestock2();
    return 0;
}
int usestock2(){
    cout<<"Using constructors to create new object\n";
    Stock stock1("NanoSmart",12,20.0);
    stock1.show();
    Stock stock2=Stock("Boffo",2,2.0);
    stock2.show();

    cout<<"Assigning stock1 to stock2\n";
    stock2=stock1;
    cout<<"Listing stock1 and stock2:\n";
    stock1.show();
    stock2.show();
    cout<<"Using a constructor to reset an object\n";
    stock1=Stock("Nifty",10,50.0);
    cout<<"Revised stock1:\n";
    stock1.show();
    cout<<"Done\n";
    return 0;
}

//int use_of_Stock_h_(){
//    //Stock sally;
//    //Stock solly;
//    Stock fluffy_the_cat;
//    fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
//    fluffy_the_cat.show();
//    fluffy_the_cat.buy(15, 18.125);
//    fluffy_the_cat.show();
//    fluffy_the_cat.sell(400, 20.00);
//    fluffy_the_cat.show();
//    fluffy_the_cat.buy(300000, 40.125);
//    fluffy_the_cat.show();
//    fluffy_the_cat.sell(300000, 0.125);
//    fluffy_the_cat.show();
//    return 0;;
//}
int do_while_ex(){
    string rsp;
    do{
        cout<<"Please enter two values:";
        int val1=0;
        int val2=0;
        cin>>val1>>val2;
        cout<<"The sum of "<<val1<<" and "<<val2
        <<" = "<<val1+val2<<"\n"
        <<"More? Enter yes or no:";
        cin>>rsp;
    }while (!rsp.empty()&&rsp[0]!='n');
    return 0;
}
int pir_of_new(){
    int *pi=new int(1024);
    //string *ps=new string(10,'9');
    cout<<pi<<" "<<*pi<<endl;
    delete pi;
    //cout<<pi<<" "<<*pi<<endl;

    
    return 0;
}
//int shared_ptr_of_ex(){
//    shared_ptr<string> p1;
//    shared_ptr<list<int>> p2;
//    if (p1&&p1->empty()) {
//        *p1="hi";
//    }
//    shared_ptr<int> p3=make_shared<int>(42);
//    shared_ptr<string> p4=make_shared<string>(10,"9");
//    shared_ptr<int> p5=make_shared<int>();
//    auto p6=make_shared<vector<string>>();
//    return 0;
//}
int ex_of_pair(){
    // pair 在#include <utility>
    pair<string,string> anon;
    pair<string,size_t> word_count;
    pair<string, vector<int>> line;
    pair<string,string> author{"James","Joyce"};
    return 0;
}
int size_of_set(){
    vector<int> ivec;
    for(int i=0;i!=10;++i){
        ivec.push_back(i);
        //ivec.push_back(i);
    }
    set<int> iset(ivec.cbegin(),ivec.cend());//set中元素唯一
    multiset<int> miset(ivec.cbegin(),ivec.cend());//multiset为另一个关联容器可以不唯一
    cout<<ivec.size()<<endl;
    cout<<iset.size()<<endl;
    cout<<miset.size()<<endl;
    return 0;
}
int ex_of_map_and_set(){
    map<string,size_t>word_count; //size_t是一种无符号的整型数，它的取值没有负数，在数组中也用不到负数，而它的取值范围是整型数的双倍。
    set<string> exclude={"The","But","And","Or","An","A",
        "the","but","and","or","an","a"};
    string word;
    while (cin>>word)
        //cout<<*exclude.end();
        if(exclude.find(word)==exclude.end())
            ++word_count[word];
    for(const auto &w:word_count)
        cout<<w.first<<" occurs "<<w.second
        <<((w.second>1)?" times":" time")<<endl;
    return 0;
    
}
int ex_of_map(){
    //vector<string>l1={"Hello"," ","the"," ","World","!"};
    //vector<string>::size_type l2={"H"};
    //biggies(l1, l2);
    map<string,size_t>word_count; //size_t是一种无符号的整型数，它的取值没有负数，在数组中也用不到负数，而它的取值范围是整型数的双倍。
    string word;
    while (cin>>word)
        ++word_count[word];
    for(const auto &w:word_count)
        cout<<w.first<<" occurs "<<w.second
        <<((w.second>1)?" times":" time")<<endl;
    return 0;

}
void elimDups(vector<string>&words){
    sort(words.begin(), words.end());
    auto end_unique=unique(words.begin(), words.end());
    words.erase(end_unique,words.end());
}

void biggies(vector<string>&words,vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(),words.end(),[](const string &a,const string &b)
                {return a.size()<b.size();});
    auto wc=find_if(words.begin(), words.end(), [sz](const string &a)
                {return a.size()>=sz;});
    auto count =words.end()-wc;
    cout<<count<<" ";
    // <<make_plural(count,"word","s")
    cout<<" of length"<<sz<<" or longer"<<endl;
    for_each(wc,words.end(),[](const string &s){cout<<s<<" ";});
    cout<<endl;
}
int exofsizeof(){
    //int a1[]={0,1,2,3,4,5};
    //cout<<sizeof(a1)/sizeof(a1[0])<<endl;
    
    //auto f=[](const string &a,const string &b)
    {
        //return a.size()<b.size();
        
    };
    
    return 0;
}
int findex(){
    vector<int> vec={1,2,3,242,12};
    cout<<accumulate(vec.cbegin(),vec.cend(),0)<<endl;
    int val=12;
    auto result=find(vec.cbegin(),vec.cend(),val);
    cout<<*result;
    cout<<"The value "<<val
    <<(result==vec.cend()
       ?" is not present":" is present")<<endl;
    return 0;
}
int stringnew(){
    const char *cp="Hello World!";
    char noNull[]={'H','i'};
    //cout<<strlen(cp)<<" "<<strlen(noNull)<<endl;
    string s1(cp);
    string s2(noNull,2);
    string s3(noNull);
    cout<<s1.size()<<endl;
    cout<<"s1:"<<s1<<endl;
    cout<<"s2:"<<s2<<endl;
    cout<<"s3:"<<s3<<endl;
    return 0;
}
int vectorsize(){
    vector<int>l1;
    cout<<"size:"<<l1.size()<<" capacity:"<<l1.capacity()<<endl;
    for (int ix=0; ix!=24; ++ix) {
        l1.push_back(ix);
    }
    cout<<"size:"<<l1.size()<<" capacity:"<<l1.capacity()<<endl;
    while (l1.size()!=l1.capacity())
    {
        l1.push_back(0);
    }
    cout<<"size:"<<l1.size()<<" capacity:"<<l1.capacity()<<endl;
    l1.push_back(42);
    cout<<"size:"<<l1.size()<<" capacity:"<<l1.capacity()<<endl;
    l1.shrink_to_fit();
    cout<<"size:"<<l1.size()<<" capacity:"<<l1.capacity()<<endl;


    return 0;
}

int file() {
     ofstream out("/Users/wuxilei/Desktop/123.txt");
     if (out.is_open())
    {
         out << "This is a line.\n";
         out << "This is another line.\n";
         out.close();
     }
    char buffer[256];
    ifstream in("/Users/wuxilei/Desktop/123.txt");
    if (! in.is_open())
    {
        cout << "Error opening file";
        exit (1);
    }
    while (!in.eof() )
    {
        in.getline (buffer,100);
        cout << buffer << endl;
    }
     return 0;
}
int check(){
    
     vector<int> l1={1,23,4};
    for (int i=0; i<l1.size(); i++) {
        cout<<l1[i]<<" ";
    }
    cout<<endl;
    
    //int n=10;
    
    cout << "Hello, World!\n";
    return 0;
}
