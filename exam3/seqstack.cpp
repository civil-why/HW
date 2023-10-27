// #include"seqstack.h"

// template<class T>
// SeqStack<T>::SeqStack(int sz){
//     top=-1;
//     data=new T[sz];
//     assert(data!=nullptr);
//     maxsize=sz;
// }

// template<class T>
// void SeqStack<T>::Push(T& x){
//     if(IsFull()==true){
//         overflow();//如果栈满则扩大栈
//         top++;
//         data[top]=x;
//     }
//     else{
//         top++;
//         data[top]=x;
//     }
// }

// template<class T>
// bool SeqStack<T>::Pop(T& x){
//     if(IsEmpty()==true) return false;//空栈无法弹出
//     else {
//         x=data[top];
//         top--;
//         return true;
//     } 
// }

// template<class T>
// bool SeqStack<T>::Top(T& x){
//     if(IsEmpty()) return false;
//     else {
//         x=data[top];
//         return true;
//     }
// }

// template<class T>
// bool SeqStack<T>::IsFull()const
// {
//     if(top+1==maxsize) return true;
//     else return false;
// }

// template<class T>
// void SeqStack<T>::overflow()
// {
//     int sz=maxsize;
//     maxsize*=2;
//     T* temp=new T[maxsize];
//     for(int i=0;i<sz;i++) temp[i]=data[i];
//     delete [] data;
//     data=temp;
// }

// template<class T>
// ostream &operator <<(ostream os,SeqStack<T>& s)
// {
//     os<<"top =">>s.top<<endl;//输出栈顶位置
//     for(int i=0;i<s.top;i++){
//         os<<i<<':'<<s.data[i];
//     }
//     return os;
// }