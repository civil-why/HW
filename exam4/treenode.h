#ifndef _treenode_h_
#define _treenode_h_

#include<iostream>
using namespace std;

template<class T>
class TreeNode
{
private:
    T data;                                     //节点数据
    TreeNode* left;                             //左子树地址
    TreeNode* right;                            //右子树地址
public:
    TreeNode();
    TreeNode(T&,TreeNode*,TreeNode*);
    ~TreeNode();
    T getdata(){return data;};
    void operator=(TreeNode&);
};

#endif