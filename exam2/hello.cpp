#include"hello.h"

void hello::input(){
    cout<<"输入内容：";
    string s;
    cin>>s;
    note+=s;
}

void hello::output(){
    cout<<note<<endl;
}
