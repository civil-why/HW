#include<iostream>
#include"seqstack.h"
#include"calculator.h"
#include<string>
#include<sstream>
using namespace std;

bool CheckPairs(string expression)//判断括号是否匹配的算法
{
    SeqStack<int> s(Max);
    int j,length=expression.size();
    for(int i=1;i<length;i++){
        if(expression[i-1]=='(') s.Push(i);
        else if(expression[i-1]==')'){
            if(!s.Pop(j)){
                cout<<"右括号输入有误，缺少与第"<<i<<"个右括号匹配的左括号，请重新输入！"<<endl;
                return false;
            }
        }
    }
    int flag=0;
    while(!s.IsEmpty()){
        flag=1;
        s.Pop(j);
        cout<<"没有与第"<<j<<"个左括号相匹配的右括号"<<endl;
    }
    if(flag==1)    return false;
    return true;
}

int isp(char c){
    switch (c)
    {
    case '(':
        return 1;
        break;
    case '*':case '/':
        return 5;
        break;
    case '+':case '-':
        return 3;
        break;
    case ')':
        return 6;
        break;
    case '#':
        return 0;
        break;
    }
    return -1;
}

int icp(char c){
    switch (c)
    {
    case '(':
        return 6;
        break;
    case '*':case '/':
        return 4;
        break;
    case '+':case '-':
        return 2;
        break;
    case ')':
        return 1;
        break;
    case '#':
        return 0;
        break;
    }
    return -1;
}

stringstream middle_to_back(){
    double num[50];
    SeqStack<char> symbol;
    string str;
    char c='#';
    int i=0;
    symbol.Push(c);//栈底放入#
    cin>>c;
    while(symbol.IsEmpty()==false&&c!='#'){
        if(c<'9'&&c>'0'){
            str+=c;
            cin>>c;
        }
        else{
            char t;
            symbol.Top(t);
            if(icp(c)>isp(t)){
                symbol.Push(c);
                if(c=='+'||c=='-'||c=='*'||c=='/')
                str+=' ';
                cin>>c;
            }
            else if(icp(c)<isp(t)){
                symbol.Pop(t);
                str+=t;
            }
            else {
                symbol.Pop(t);
                if(t=='(') cin>>c;
            }
        }
    }
    char temp='\0';
    while(temp!='#'){
        symbol.Pop(temp);
        str+=temp;
    }
    CheckPairs(str);
    stringstream ss1(str);
    return ss1;
    //cout<<str;
}//中缀转后缀

int main(){
    Calculator C;
    stringstream ss=middle_to_back();
    C.Run(ss);
    return 0;
}