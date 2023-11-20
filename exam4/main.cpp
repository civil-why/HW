#include<iostream>
#include"binarytree.hpp"
#include"treenode.hpp"
#include<vector>

using namespace std;

int main(){
    BinaryTree<char> Tree1('#');
    int choice=-1;
    while(choice!=0){
        cout<<"——————————————————————————————————————"<<endl;
        cout<<"1------建立一棵二叉树\n2------前序遍历递归算法\n3------前序遍历非递归算法\n4------中序遍历递归算法\n5------中序遍历非递归算法\n6------后序遍历递归算法\n7------后序遍历非递归算法\n8------求树高\n9------求叶子总数\n10-----输出二叉树\n0----退出\n";    
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"中序输入建立一棵新二叉树，以“#”号作为终止符:\n";
            Tree1.Creat(cin);
            cout<<"已建立新二叉树！"<<endl;
            break;
        case 2:
            cout<<"前序递归输出二叉树:\n";
            Tree1.Preorder_Recursion();
            cout<<endl;
            break;
        case 3:
            cout<<"前序非递归输出二叉树:\n";
            Tree1.Preorder_Interation();
            cout<<endl;
            break;
        case 4:
            cout<<"中序递归输出二叉树:\n";
            Tree1.Inorder_Recursion();
            cout<<endl;
            break;
        case 5:
            cout<<"中序非递归输出二叉树:\n";
            Tree1.Inorder_Interation();
            cout<<endl;
            break;
        case 6:
            cout<<"后序递归输出二叉树:\n";
            Tree1.Postorder_Recursion();
            cout<<endl;
            break;
        case 7:
            cout<<"后序非递归输出二叉树:\n";
            Tree1.Postorder_Interation();
            cout<<endl;
            break;
        case 8:
            cout<<"二叉树高度为："<<Tree1.Height()<<endl;
            break;
        case 9:
            cout<<"树叶总数为："<<Tree1.Leaf_Size()<<endl;
            break;
        case 10:
            cout<<"输出二叉树：\n";
            Tree1.Preorder_Recursion();
            break;
        
        case 0:
            cout<<"已退出";
            break;
        }
    }
    return 0;
}