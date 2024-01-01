#pragma once

#include<iostream>
#include"quicksort.hpp"
#include"bubblesort.hpp"
#include"selectionsort.hpp"

using namespace std;

class UI
{
private:
    int welcome();
    int errin();
public:
    UI();
    ~UI();
};

UI::UI()
{
    while(1){
        int choice=welcome();
        if(choice==1){
            int n =0;
            cout<<"请输入测试数组大小："<<endl;
            cin>>n;
            vector<int> arr;
            cout<<"请输入测试数组："<<endl;
            for(int i=0;i<n;i++){
                int t;
                cin>>t;
                arr.push_back(t);
                }

            quickSort(arr, 0, n - 1);

            cout << "快速排序后数组：";
            for (int num : arr) {
                cout << num << " ";
            }
            cout << endl;
        }
        else if(choice==2){
            int n =0;
            cout<<"请输入测试数组大小："<<endl;
            cin>>n;
            vector<int> arr;
            cout<<"请输入测试数组："<<endl;
            for(int i=0;i<n;i++){
                int t;
                cin>>t;
                arr.push_back(t);
                }

            bubbleSort(arr);

            cout << "冒泡排序后数组：";
            for (int num : arr) {
                cout << num << " ";
            }
            cout << endl;
        }
        else if(choice==3){
            int n =0;
            cout<<"请输入测试数组大小："<<endl;
            cin>>n;
            vector<int> arr;
            cout<<"请输入测试数组："<<endl;
            for(int i=0;i<n;i++){
                int t;
                cin>>t;
                arr.push_back(t);
                }

            selectionSort(arr);

            cout << "直接选择排序后数组：";
            for (int num : arr) {
                cout << num << " ";
            }
            cout << endl;
        }
        else if(choice==0) break;
        else errin();
    }
}

UI::~UI()
{
}

int UI::welcome()
{
    cout<<"——————————————————————————"<<endl;
    cout<<"实验8排序算法，输入1进行快速排序，输入2进行冒泡排序,输入3进行直接选择排序，输入0结束程序:"<<endl;
    int t;
    if(cin>>t) return t;
    else return errin();
}

int UI::errin()
{
    cerr<<"您的输入有误，请重新输入！"<<endl;
    cin.clear();
    cin.sync();
    return welcome();
}//错误输入