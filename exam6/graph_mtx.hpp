#ifndef _graph_mtx_hpp_
#define _graph_mtx_hpp_

#include<iostream>
#include<queue>
using namespace std;

template<class T,class E>
class Graph_M{
private:
    T *v_list;                              //顶点表数组
    E **e_mtx;                              //边矩阵

protected:
    int max_vertices;
    int num_edges;
    int num_vertices;
    int get_first_neighbor(int);
    int get_next_neighbor(int v,int w);

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
    
    void DFS(const T& v);                   //深度优先搜索
    void DFS(int v,bool visited[]);         //深度搜索子过程

    void BFS(const T&v);                             //广度优先搜索

    int get_vertice(T);
    T get_value(int t){return v_list[t];};
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
    for(int i=0;i<max_vertices;i++)
        if(v_list[i]==t) return i;
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

template<class T,class E>
int Graph_M<T,E>::get_first_neighbor(int v)
{
    if(v!=-1){
        for(int col=0;col<num_vertices;col++)
            if(e_mtx[v][col]>0) return col;
    }
    return -1;
}

template<class T,class E>
int Graph_M<T,E>::get_next_neighbor(int v,int w)
{
    if(v!=-1&&w!=-1){
        for(int col=w+1;col<num_vertices;col++)
            if(e_mtx[v][col]>0) return col;
    }
    return -1;
}

template<class T,class E>
void Graph_M<T,E>::DFS(const T& v)
{
    int i,loc,n=num_vertices;
    bool * visited=new bool[n];
    for(i=0;i<n;i++) visited[i]=false;
    loc=get_vertice(v);
    DFS(loc,visited);
    delete [] visited;
}

template<class T,class E>
void Graph_M<T,E>::DFS(int v,bool visited[])
{
    cout<<v_list[v]<<' ';
    visited[v]=true;
    int w=get_first_neighbor(v);
    while(w!=-1){
        if(visited[w]==false) DFS(w,visited);
        w=get_next_neighbor(v,w);
    }
}

template<class T,class E>
void Graph_M<T,E>::BFS(const T& v)
{
    int w,n=num_vertices;
    bool* visited=new bool [n];
    for(int i=0;i<n;i++) visited[i]=false;
    int loc=get_vertice(v);
    cout<<get_value(loc)<<' ';
    visited[loc]=true;
    queue<int> Q;Q.push(loc);
    while(!Q.empty())
    {
        loc=Q.front();
        Q.pop();
        w=get_first_neighbor(loc);
        while(w!=-1){
            if(visited[w]==false){
                cout<<get_value(w)<<' ';
                visited[w]=true;
                Q.push(w);
            }
            w=get_next_neighbor(loc,w);
        }
    }
    delete [] visited;
}

#endif