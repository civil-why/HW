#pragma once

#include<iostream>
#include"search.h"
#include"search_tree.h"

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
            cout<<"二分查找测试数据：1,3,4,7,8 查找有无3出现"<<endl;

            std::vector<int> sortedArray = {1, 3, 4, 7, 8};
            int target = 3;

            if (binarySearch(sortedArray, target)) {
                std::cout << "找到目标值 " << target << std::endl;
            } else {
                std::cout << "未找到目标值 " << target << std::endl;
            }
        }
        else if(choice==2){
            BinarySearchTree bst;
            cout<<"二叉搜索树测试数据：1,3,4,7,8 "<<endl;

            // 依次查找和插入元素
            bst.searchAndInsert(3);
            bst.searchAndInsert(1);
            bst.searchAndInsert(4);
            bst.searchAndInsert(7);
            bst.searchAndInsert(8);

            // 中序遍历二叉搜索树，验证结果
            std::cout << "中序遍历结果：";
            bst.inorderTraversal();
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
    cout<<"实验7查找算法，输入1进行二分查找，输入2进行二叉搜索树,输入0结束程序:"<<endl;
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