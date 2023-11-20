#ifndef _treenode_hpp_
#define _treenode_hpp_

#include<iostream>
using namespace std;

template<class T>
struct TreeNode
{
    T data;                                     //节点数据
    TreeNode* left;                             //左子树地址
    TreeNode* right;                            //右子树地址
    TreeNode();
    TreeNode(T& D,TreeNode* l=nullptr,TreeNode* r=nullptr);
    void operator=(TreeNode&);
};

template<class T>
TreeNode<T>::TreeNode()
{
    left=nullptr;
    right=nullptr;
}

template<class T>
TreeNode<T>::TreeNode(T& D,TreeNode* l,TreeNode* r)
{
    data=D;
    left=l;
    right=r;
}

template<class T>
void TreeNode<T>::operator=(TreeNode& t)
{
    data=t.data;
    left=t.left;
    right=t.right;
}


#endif