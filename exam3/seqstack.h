#ifndef _seqstack_h_
#define _seqstack_h_

#include<assert.h>
#include<iostream>

using namespace std;
const int Max=100;

template<class T>
class SeqStack{
private:
    T* data;                                                            //栈的指针
    int top;                                                            //栈顶位置
    int maxsize;                                                        //最大容量
    void overflow();                                                    //溢出
public:
    SeqStack(int sz=50);                                                //构造函数
    ~SeqStack(){delete [] data;};                                       //析构函数
    
    void clear(){top=-1;};                                              //清空栈
    void Push(T& x);                                                    //推入栈底
    bool Pop(T& x);                                                     //弹出栈顶
    bool Top(T& x);                                                     //返回栈顶
    bool IsEmpty()const{return(top==-1)?true:false;};                   //判定是否为空栈
    bool IsFull()const;                                                 //判断栈是否满
    int size()const{return top+1;};                                     //返回栈的元素个数

    template<class U>
    friend ostream& operator<<(ostream& os,SeqStack<U>& stack);         //输出流
};

template<class T>
SeqStack<T>::SeqStack(int sz){
    top=-1;
    data=new T[sz];
    assert(data!=nullptr);
    maxsize=sz;
}

template<class T>
void SeqStack<T>::Push(T& x){
    if(IsFull()==true){
        overflow();//如果栈满则扩大栈
        top++;
        data[top]=x;
    }
    else{
        top++;
        data[top]=x;
    }
}

template<class T>
bool SeqStack<T>::Pop(T& x){
    if(IsEmpty()==true) return false;//空栈无法弹出
    else {
        x=data[top];
        top--;
        return true;
    } 
}

template<class T>
bool SeqStack<T>::Top(T& x){
    if(IsEmpty()) return false;
    else {
        x=data[top];
        return true;
    }
}

template<class T>
bool SeqStack<T>::IsFull()const
{
    if(top+1==maxsize) return true;
    else return false;
}

template<class T>
void SeqStack<T>::overflow()
{
    int sz=maxsize;
    maxsize*=2;
    T* temp=new T[maxsize];
    for(int i=0;i<sz;i++) temp[i]=data[i];
    delete [] data;
    data=temp;
}

template<class T>
ostream &operator <<(ostream os,SeqStack<T>& s)
{
    os<<"top =">>s.top<<endl;//输出栈顶位置
    for(int i=0;i<s.top;i++){
        os<<i<<':'<<s.data[i];
    }
    return os;
}
#endif