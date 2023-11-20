#ifndef _binarytree_h_
#define _binarytree_h_

#include<iostream>
#include"treenode.h"

template<class T>
class BinaryTree
{
private:
    TreeNode<T>* root;                                  //根节点
    T RefValue;                                         //结束标识符

protected:
    void CreatTree(istream & in,TreeNode<T> *& SubTree);//从输入流创造一棵新树
    bool Insert(TreeNode<T>* & SubTree,const T& x);     //在子节点出插入一个新节点x
    void Delete(TreeNode<T>*);                          //删除子树
    bool Find(TreeNode*SubTree,const T&x)const;

    TreeNode<T>* Copy(TreeNode<T>* originode);
    TreeNode<T>* Parent(TreeNode<T>* SubTree,TreeNode<T> *current);
    TreeNode<T>* Find(TreeNode<T>* SubTree,const T& x)const;
    
    int Height(TreeNode<T>* SubTree);
    int Size(TreeNode<T> *SubTree);
    
    void Traverse(TreeNode<T>* SubTree,ostream& out);       //前序输出
    void preOrder(TreeNode<T> &SubTree,void(*visit(TreeNode<T>& Tree)));
    void inOrder(TreeNode<T> &SubTree,void(*visit(TreeNode<T>& Tree)));
    void postOrder(TreeNode<T> &SubTree,void(*visit(TreeNode<T>& Tree)));

    friend istream& operator>>(istream& in,BinaryTree<T>& Tree);
    friend ostream& operator<<(ostream& out,BinaryTree<T>& Tree);

public:
    BinaryTree();                           //构造函数默认生成空树
    BinaryTree(const BinaryTree<T>&);
    BinaryTree(TreeNode<T>* ,TreeNode<T>* ,T );//含参构造时根据参数构造树
    ~BinaryTree(){Delete(root);}            //删除整棵树

    bool Insert(TreeNode<T>*,T);
    TreeNode<T>* Search(T&)const;

    void Preorder_Recursion();
    void Postorder_Recursion();
    void Inorder_Recursion();

    void Preorder_Interation();
    void Postorder_Interation();
    void Inorder_Interation();

    bool IsEmpty(){return(root==nullptr):true?false};//树是否为空
    TreeNode<T>* Parent(TreeNode<T> *current){return(root==nullptr||root==current)?nullptr:Parent(root,current);}//返回节点的父节点
    TreeNode<T>* LfetChild(TreeNode<T>* current){return(current!=nullptr)?current->left:nullptr;}//返回节点的左子节点
    TreeNode<T>* RightChild(TreeNode<T>* current){reutnr(current!=nullptr)?current->right:nullptr;}//返回节点的右子节点
    
    int Height();
    int Size();
    TreeNode<T>* getRoot()const{return root;}
    
};
#endif