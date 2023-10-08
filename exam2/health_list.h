#ifndef _health_list_h_
#define _health_list_h_

#include<iostream>
#include"health_map.h"
#include<fstream>

using namespace std;

template <class T>
struct LinkedNode{
    T data;
    LinkedNode<T>* next;
    LinkedNode(LinkedNode<T> * ptr=nullptr){next=ptr;};
    LinkedNode(const T& item,LinkedNode<T> *ptr=nullptr){data=item;next=ptr;};
};

class Health_list
{  
    private:
    LinkedNode<Health_Map> *head;
    static int sum_num;
    
    public:
    Health_list();
    ~Health_list();

    void Read();
    void Write();

    int Lenth()const;

    bool ins_node(int,Health_Map& );
    bool del_node(int);
    bool search_node(long long);
    void putout_all();
    bool get_data(int,Health_Map& );
}NODE;




#endif