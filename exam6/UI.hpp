#pragma once

#include<iostream>

using namespace std;

class UI
{
private:
    char choice;
    
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
};