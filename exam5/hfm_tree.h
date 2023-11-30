#ifndef _hfm_tree_h_
#define _hfm_tree_h_

#include<iostream>
#include<fstream>
#include"char_set.hpp"
using namespace std;

template<class T>
struct Treenode{
    T data;                         //存放的内容
    Treenode* leftchild;            //左孩子
    Treenode* rightchild;           //右孩子
};                                  //树结点定义

typedef struct char_set_node
{
    char_set data;                  //结点内容
    Treenode<char_set>* tree;       //指向对应的树结点
    char_set_node* next;            //下一位结点位置
}node;                              //链表结点定义

class HfmTree
{
private:
    int num;                                //剩余字符集数量
    Treenode<char_set>* root;               //根结点

protected:
    void destroy(Treenode<char_set>*);      //递归删除哈夫曼树
    void build(node* &);                    //递归建立哈夫曼树
    Treenode<char_set>* find_2_min(node* &);//找出两个最小的频度
    int Height(Treenode<char_set>*);        //递归求树高
    void Pre_order_in_file(Treenode<char_set>*,ofstream&); //递归写入文件
    void build_code(Treenode<char_set>*,string);//建立哈夫曼编码
    Treenode<char_set>* Copy(Treenode<char_set>*);//递归复制树结点
    void Pre_order_out_file(Treenode<char_set>*&,ifstream&);//递归读出文件

public:
    HfmTree(){root=nullptr;};               //默认构造
    HfmTree(int,node*);                     //含参构造
    HfmTree(const HfmTree&);                //拷贝构造函数
    ~HfmTree();                             //析构

    int Height();                           //返回树高
    void Read();                            //将文件中的哈夫曼树读入内存
    void Write();                           //将哈夫曼树输出到文件中
    Treenode<char_set>* get_root(){return root;}//取根
    void Print_Tree();                      //打印树形
    bool Is_Tree();                         //是否存在树
    void operator=(const HfmTree&);         //运算符重载
};

#endif