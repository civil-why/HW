#ifndef _graph_mtx_hpp_
#define _graph_mtx_hpp_

#include<iostream>
using namespace std;

template<class T,class E>
class Graph_M{
private:
    T *v_list;                              //顶点表数组
    E **e_mtx;                              //边矩阵

    int get_vertice(T);

protected:
    int max_vertices;
    int num_edges;
    int num_vertices;

public:
    Graph_M(int sz=30);
    ~Graph_M();

    bool Insert_Edge(T,T,E);                   //在两顶点之间增加边
    bool Insert_Vertice(const T&);
    bool remove_Vertex(T);
    bool remove_Edge(T,T);

    bool Is_Empty()const {return (num_edges==0)?true:false;}
    bool Is_Full()const {return (num_vertices==max_vertices||num_edges==max_vertices*(max_vertices-1)/2)?true:false;}

    int get_num_vertice() {return num_vertices;}
    int get_num_edges() {return num_edges;}
};

template<class T,class E>
Graph_M<T,E>::Graph_M(int sz)
{
    max_vertices=sz;num_vertices=0;num_edges=0;
    v_list=new T[max_vertices];
    for(int i=0;i<max_vertices;i++)   v_list[i]=0;  //初始化v_list
    e_mtx=(E**) new E* [max_vertices];              //创建max_vertices个指针并强制转换为E**格式
    for(int i=0;i<max_vertices;i++)
        e_mtx[i]=new E[max_vertices];
    for(int i=0;i<max_vertices;i++)
        for(int j=0;j<max_vertices;j++)
            e_mtx[i][j]=0;
}

template<class T,class E>
Graph_M<T,E>::~Graph_M()
{
    delete [] v_list;
    for(int i=0;i<max_vertices;i++)
        delete [] e_mtx[i];
    delete[] e_mtx;
}

template<class T,class E>
int Graph_M<T,E>::get_vertice(T t)
{
    if(Is_Empty()) return -1;
    else{
        for(int i=0;i<max_vertices;i++)
            if(v_list[i]==t) return i;
    }
    return -1;
}

template<class T,class E>
bool Graph_M<T,E>::Insert_Edge(T t1,T t2,E e)
{
    int pos1=get_vertice(t1),pos2=get_vertice(t2);
    if(pos1==-1||pos2==-1) return false;
    e_mtx[pos1][pos2]=e;
    e_mtx[pos2][pos1]=e;
    num_edges++;
    return true;
}

template<class T,class E>
bool Graph_M<T,E>::Insert_Vertice(const T& t)
{
    if(Is_Full()) return false;
    v_list[num_vertices++]=t;
    return true;
}

template<class T,class E>
bool Graph_M<T,E>::remove_Vertex(T t)
{
    int v=get_vertice(t);
    if(v<0)return false;
    if(num_vertices==1) return false;
    int i,j;
    v_list[v]=v_list[num_vertices-1];
    for(int i=0;i<num_vertices;i++) if(e_mtx[i][v]>0)num_edges--;
    for(i=0;i<num_vertices;i++)
        e_mtx[i][v]=e_mtx[i][num_vertices-1];
    num_vertices--;
    for(j=0;j<num_vertices;j++)
        e_mtx[v][j]=e_mtx[num_vertices][j];
    return true;
}

template<class T,class E>
bool Graph_M<T,E>::remove_Edge(T t1,T t2)
{
    int v1=get_vertice(t1),v2=get_vertice(t2);
    if(v1==-1||v2==-1||e_mtx[v1][v2]<=0) return false;
    else{
        e_mtx[v1][v2]=e_mtx[v2][v1]=0;
        num_edges--;
        return true;
    }
}

#endif