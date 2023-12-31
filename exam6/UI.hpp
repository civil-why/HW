#pragma once

#include<iostream>
#include"graph_lnk.hpp"
#include"graph_mtx.hpp"

using namespace std;

class UI
{
private:    
    void welcome();
    void errin();
public:
    UI();
    ~UI();
};

UI::UI()
{
    welcome();
}

UI::~UI()
{
}

void UI::welcome()
{
    cout<<"——————————————————————————————————"<<endl;
    cout<<"请输入图的结点个数："<<endl;
    int m=0,n=0,d=0;
    if(cin>>m);
    else errin();
    cout<<"请输入图的弧的条数："<<endl;
    if(cin>>n);
    else errin();
    cout<<"输入0或1表示该图是否为有向图，输入0表示该图是一个无向图："<<endl;
    if(cin>>d);
    else errin();

    Graph_M<char,int> M(m);                       //邻接矩阵
    Graph_L<char,int> L(m);                       //邻接表
    // stringstream ss;
    // string str;
    // getline(cin,str);

    cout<<"请输入m个互不相同的字符，代表每个结点的字符数据："<<endl;
    //ss.str(str);

    for(int i=0;i<m;i++){
        char temp;
        //ss>>temp;
        cin>>temp;
        M.Insert_Vertice(temp);
    }
    
    cout<<"请输入n行，每行两个字符P1、P2。对于有向图，表示存在一条从P1到P2的有向边；对于无向图，表示在P1和P2之间存在一条边"<<endl;
    for(int i=0;i<n;i++){
        char P1,P2;
        cin>>P1>>P2;
        M.Insert_Edge(P1,P2,1);
    }
}//欢迎页并读取用户选项

void UI::errin()
{
    cerr<<"您的输入有误，请重新输入！"<<endl;
    cin.clear();
    cin.sync();
    welcome();
}//错误输入