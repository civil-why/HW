#include"calculator.h"

void Calculator::Run(stringstream &ss)
{
    char ch;
    double newOperand;
    while(ss>>ch,ch!='#'){
        switch (ch)
        {
        case '+':case '-':case '*':case '/':
            DoOperator(ch);break;
        default:
            ss.putback(ch);
            ss>>newOperand;                    //读取数字
            AddOperand(newOperand);
        }
    }
    double out;
    s.Top(out);
    cout<<out;
}

void Calculator::DoOperator(char op){
    double left,right,value;
    int result;
    result=get2Operands(left,right);
    if(result==true)
    switch (op)
    {
    case '+':
        value=left+right;s.Push(value);
        break;
    case '-':
        value=left-right;s.Push(value);
        break;
    case '*':
        value=left*right;
        s.Push(value);
        break;
    case '/':
        if(right!=0.0) {value=left/right;s.Push(value);}
        else {cerr<<"除数不可以为0!"<<endl;Clear();}
        break;
    }
    else Clear();
}

bool Calculator::get2Operands(double& left,double& right)
{
    if(s.IsEmpty()==true){
        cerr<<"缺少右操作数！"<<endl;
        return false;
    }
    s.Pop(right);
    if(s.IsEmpty()==true){
        cerr<<"缺少左操作数！"<<endl;
        return false;
    }
    s.Pop(left);
    return true;
}

void Calculator::AddOperand(double value)
{
    s.Push(value);
}

void Calculator::Clear(){
    s.clear();
}