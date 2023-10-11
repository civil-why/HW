#ifndef _health_list_h_
#define _health_list_h_

#include<iostream>
#include"health_map.h"
#include<fstream>

using namespace std;

template <class T>
struct LinkedNode{               
    T data;                                                                             //内容
    LinkedNode<T>* next;                                                                //下一个节点的位置
    LinkedNode(LinkedNode<T> * ptr=nullptr){next=ptr;};                                 //构造函数
    LinkedNode(const T& item,LinkedNode<T> *ptr=nullptr){data=item;next=ptr;};          //带内容的构造函数
};                                                                                  //使用模板类定义链表节点

class Health_list
{  
    private:
    LinkedNode<Health_Map> *head;                                                       //头节点
    int sum_num;                                                                        //学生数

    public:
    Health_list(){head= new LinkedNode<Health_Map>;head->next=nullptr;sum_num=0;};      //构造函数
    Health_list(LinkedNode<Health_Map>* ptr){head=ptr;sum_num=1;};                      //带头节点的构造函数
    ~Health_list(){list_delete_all(head);};                                             //析构函数（先全部释放空间再删除）
    Health_list(const Health_list& L){head=L.head;sum_num=L.sum_num;};                  //拷贝构造函数

    void Read();                                                                        //读取文件中的内容
    void Write();                                                                       //内存写入文件

    int Lenth()const{return sum_num;};                                                  //获取学生人数
    void list_delete_all(LinkedNode<Health_Map>*);                                      //全部释放空间（用于析构）
    bool ins_node(int,Health_Map& );                                                    //插入学生健康表
    bool del_node(int);                                                                 //删除学生健康表
    bool search_node(long long);                                                        //使用学生学号查找对应表
    void putout_all();                                                                  //输出全部学生信息
    void new_list();
    //bool get_data(int,Health_Map& );                                                  
};




#endif