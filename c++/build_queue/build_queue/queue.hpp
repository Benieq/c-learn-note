//
//  queue.hpp
//  build_queue
//
//  Created by 吴席垒 on 2020/8/7.
//  Copyright © 2020 吴席垒. All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp

class Customer
{
private:
    long arrive;
    int processtime;
public:
    Customer(){
        arrive=processtime=0;
    }
    void set(long when);
    long when() const{return arrive;}
    int ptime() const{return processtime;}
};
typedef Customer Item;
class Queue
{
private:
    struct Node{
        Item item;
        struct Node*next;
    };
    enum{Q_SIZE=10};
    
    Node*front;
    Node*rear;
    int items;
    const int qsize;
    Queue(const Queue &q):qsize(0){}
    Queue&operator=(const Queue&q){return *this;}
public:
    Queue(int qs=Q_SIZE);
    ~Queue();
    bool isempty()const;
    bool isfull()const;
    int queueconst()const;
    bool enqueue(const Item &item);
    bool dequeue(Item&item);
};
#endif /* queue_hpp */
