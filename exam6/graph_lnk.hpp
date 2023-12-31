#ifndef _graph_lnx_hpp_
#define _graph_lnx_hpp_

#include<iostream>
using namespace std;

const int default_vertice=30;//正常来说26个字母就够了，默认为30

template<class T,class E>
struct Edge{
    int dest;
    E cost;
    Edge<T,E> * link;
    Edge(){}
    Edge(int num,E weight):dest(num),cost(weight),link(nullptr){}
    bool operator !=(Edge<T,E>& R)const{
        return (dest!=R.dest)?true:false;
    }
};

template<class T,class E>
struct Vertex{
    T data;
    Edge<T,E> *adj;                             //边链表头指针
};

template<class T,class E>
class Graph_L
{

private:
    Vertex<T,E> *NodeTable;                     //顶点表
    int get_vertice(const T);

protected:
    int max_vertices;
    int num_edges;
    int num_vertices;
    
public:
    Graph_L(int sz=default_vertice);
    ~Graph_L();

    int get_next_neighbor(int,int);
};

template<class T,class E>
Graph_L<T,E>::Graph_L(int sz)
{
    max_vertices=sz;num_vertices=0;num_edges=0;
    NodeTable= new Vertex<T,E>[sz];
    if(NodeTable==nullptr){cerr<<"存储空间分配错误！"<<endl;exit(1);}
    for(int i=0;i<max_vertices;i++){
        NodeTable[i].adj=nullptr;
    }
}

template<class T,class E>
Graph_L<T,E>::~Graph_L()
{
    for(int i=0;i<num_vertices;i++){
        Edge<T,E> *p=NodeTable[i].adj;
        while(p!=nullptr){
            NodeTable[i].adj=p->link;
            delete p;
            p=NodeTable[i].adj;
        }
    }
    delete []NodeTable;
}

template<class T,class E>
int Graph_L<T,E>::get_vertice(const T v)
{
    for(int i=0;i<num_vertices;i++){
        if(NodeTable[i].data==v) return i;
    }
    return -1;
}

template<class T,class E>
int Graph_L<T,E>::get_next_neighbor(int v,int w)
{
    if(v!=-1){
        Edge<T,E> *p=NodeTable[v].adj;
        while(p!=nullptr&&p->dest!=w)
            p=p->link;
        if(p!=nullptr&&p->link!=nullptr)
            return p->link->dest;
    }
    return -1;
}

#endif