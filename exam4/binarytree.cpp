#include"binarytree.h"

template<class T>
BinaryTree<T>::BinaryTree()
{
    root=nullptr;
}//默认生成空树

template<class T>
BinaryTree<T>::BinaryTree(TreeNode<T>* l=nullptr,TreeNode<T>* r=nullptr,T d)
{
    root->data=d;
    root->left=l;
    root->right=r;
}

template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& btree)//应使用前序遍历
{
    root=new TreeNode;
    root=btree.root;
}

template<class T>
bool BinaryTree<T>::Insert(TreeNode<T>* aim,T new_T)
{
    TreeNode *temp=new TreeNode;
    temp->data=new_T;
    temp->left=nullptr;
    temp->right=nullptr;
    if(aim->left==nullptr){
        aim->left=temp;
        return true;
    }
    else if(aim->right==nullptr){
        aim->right=temp;
        return true;
        }
    else return false;
}   

template<class T>
void BinaryTree<T>::Delete(TreeNode<T>* aim)
{
    if(aim!=nullptr){ 
        Delete(aim->left);
        Delete(aim->right);
        delete aim;
    }
}

