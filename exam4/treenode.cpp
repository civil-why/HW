#include"treenode.h"

template<class T>
TreeNode<T>::TreeNode()
{
    left=nullptr;
    right=nullptr;
}

template<class T>
TreeNode<T>::TreeNode(T& D,TreeNode* l=nullptr,TreeNode* r=nullptr)
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
