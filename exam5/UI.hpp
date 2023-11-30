#pragma once

#include<iostream>
#include"hfm_tree.h"
#include"encoding.h"
#include"decoding.h"

using namespace std;

class UI
{
private:
    char choice;
    HfmTree Tree;
    Encode e;
    Decode d;
    
    void welcome();
    void errin();
    void act();
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
    cout<<"欢迎使用Huffman编码/译码系统，请输入字符选择您的操作："<<endl;
    cout<<"I：初始化系统"<<endl;
    cout<<"E：编码"<<endl;
    cout<<"D：译码"<<endl;
    cout<<"P：打印代码文件"<<endl;
    cout<<"T：打印霍夫曼树"<<endl;
    cout<<"Q：退出系统"<<endl;
    cin>>choice;
    act();
}//欢迎页并读取用户选项

void UI::errin()
{
    cerr<<"您的输入有误，请重新输入！"<<endl;
    cin.clear();
    cin.sync();
    welcome();
    act();
}//错误输入

void UI::act()
{
    switch (choice)
    {
    case 'I'://初始化哈夫曼树
    {
        int n;
        cout<<"请输入字符集大小n:\nn=";
        cin>>n;
        if(cin.fail()) errin();
        char_set c_set;
        cout<<"请依次输入字符和对应的权值："<<endl;
        node* head=new node;
        node* current=head;
        for(int i=0;i<n;i++){
            cout<<"字符：";
            cin.sync();
            c_set.data=getchar();
            if(c_set.data==' ') c_set.data='*';
            cout<<"对应的权值：";
            cin>>c_set.frequency;
            node* temp=new node;
            temp->data=c_set;
            temp->tree=nullptr;
            temp->next=nullptr;
            current->next=temp;
            current=temp;
        }
        HfmTree t(n,head);
        Tree=t;
        t.Write();
        cout<<"已建立哈夫曼树！"<<endl;
        welcome();
        break;
        }
    case 'E':
    {
        cout<<"开始编码，请确保ToBeTran文件已经写入内容"<<endl;
        e.Read_tree(Tree);
        e.Tran();
        e.Write_code();
        welcome();
        break;
        }
    case 'D':
    {
        cout<<"开始译码，将CodeFile文件中的内容写入Textfile中";
        d.Read_code();
        d.de_code(Tree);
        d.Write_data();
        welcome();
        break;
        }
    case 'P'://没做哦
        cout<<"没做哦"<<endl;
        break;
    case 'T'://没做哦
        cout<<"没做哦"<<endl;
        break;
    case 'Q':
        cout<<"成功退出程序！"<<endl;
        break;
    default:
        errin();
        break;
    }
};