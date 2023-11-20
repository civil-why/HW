#ifndef _binarytree_hpp_
#define _binarytree_hpp_

#include<iostream>
#include"treenode.hpp"
#include<stack>//不讲武德
#include<sstream>

template<class T>
struct stkNode{
    TreeNode<T> *ptr;
    int tag;                                           //表示左右子树访问，用0表示访问左子树，1表示访问右子树
    stkNode(TreeNode<T> *N=nullptr):ptr(N),tag(0){};
};//关于后序遍历非递归算法的特殊栈结点定义

template<class T>
class BinaryTree
{
private:
    TreeNode<T>* root;//根节点
    T RefValue;                                                     //结束标识符

protected:
    void CreatTree(istream & in,TreeNode<T> *& SubTree);            //从输入流创造一棵新树
    bool Insert(TreeNode<T>*,T);                                    //以aim结点为根，插入新结点为aim结点的子女
    void Delete(TreeNode<T>*);                                      //删除子树
    bool Is_In_Tree(TreeNode<T>*SubTree,const T&x)const;            //判断x是否在子树中

    TreeNode<T>* Copy(TreeNode<T>* originode);                      //以目标结点为根节点复制子树
    TreeNode<T>* Parent(TreeNode<T>* SubTree,TreeNode<T> *current); //返回目标结点的父节点
    TreeNode<T>* Find(TreeNode<T>* SubTree,const T& x)const;        //前序返回第一个x的地址
    
    int Height(TreeNode<T>* SubTree);                               //返回树高
    int Size(TreeNode<T> *SubTree);                                 //返回树的总节点数
    int Leaf_Size(TreeNode<T>* SubTree);                            //返回树叶总数
    
    void Traverse(TreeNode<T>* SubTree,ostream& out);               //前序输出
    
    void preOrder(TreeNode<T> *SubTree);                            //前序遍历
    void inOrder(TreeNode<T> *SubTree);                             //中序遍历
    void postOrder(TreeNode<T> *SubTree);                           //后序遍历

public:
    BinaryTree();                                                   //构造函数默认生成空树
    BinaryTree(const BinaryTree<T>&);                               //拷贝构造，直接调用copy函数
    BinaryTree(T ref,TreeNode<T>* l=nullptr,TreeNode<T>* r=nullptr);  //含参构造时根据参数构造树
    ~BinaryTree(){Delete(root);}                                    //删除整棵树

    TreeNode<T>* Search(T& x)const{return Find(root,x);};           //从整个树中找x，若x不存在返回nullptr

    void Preorder_Recursion();                                      //前序递归访问二叉树
    void Postorder_Recursion();                                     //后递归访问二叉树
    void Inorder_Recursion();                                       //中序递归访问二叉树

    void Preorder_Interation();                                     //前序迭代访问二叉树
    void Postorder_Interation();                                    //后序迭代访问二叉树
    void Inorder_Interation();                                      //中序迭代访问二叉树

    bool IsEmpty(){if(root==nullptr) return true; else return false;}; //树是否为空
    TreeNode<T>* Parent(TreeNode<T> *current){return(root==nullptr||root==current)?nullptr:Parent(root,current);}//返回节点的父节点
    TreeNode<T>* LeftChild(TreeNode<T>* current){return(current!=nullptr)?current->left:nullptr;}//返回节点的左子节点
    TreeNode<T>* RightChild(TreeNode<T>* current){reutnr(current!=nullptr)?current->right:nullptr;}//返回节点的右子节点
    
    int Height(){return Height(root)-1;};                 //返回树高
    int Size(){return Size(root);};                     //返回树的节点总数
    int Leaf_Size(){return Leaf_Size(root);};           //返回树叶总数
    TreeNode<T>* getRoot()const{return root;}           //返回根节点
    void Creat(istream& in);                          //创建新树

    void Read();            
    void Write();

    friend istream& operator>>(istream& in,BinaryTree<T>& Tree);
    friend ostream& operator<<(ostream& out,BinaryTree<T>& Tree);
};

template<class T>
BinaryTree<T>::BinaryTree()
{
    root=nullptr;
}//默认生成空树

template<class T>
BinaryTree<T>::BinaryTree(T ref,TreeNode<T>* l,TreeNode<T>* r)
{
    root=new TreeNode<T>;
    RefValue=ref;
    root->left=l;
    root->right=r;
}

template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& btree)
{
    root=Copy(btree.root);
}

template<class T>
void BinaryTree<T>::Creat(istream& in)
{
    CreatTree(in,root);
}

template<class T>
void BinaryTree<T>::CreatTree(istream &in,TreeNode<T> *&SubTree)
{
    T item;
    if(!in.eof()){
        in>>item;
        if(item!=RefValue){
            SubTree=new TreeNode<T>(item);
            if(SubTree==nullptr){
                cerr<<"存储分配错误！"<<endl;exit(1);
            }
            CreatTree(in,SubTree->left);
            CreatTree(in,SubTree->right);
        }
        else SubTree=nullptr;
    }
}

template<class T>
bool BinaryTree<T>::Insert(TreeNode<T>* aim,T new_T)
{
    TreeNode<T> *temp=new TreeNode<T>;
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

template<class T>
int BinaryTree<T>::Height(TreeNode<T>* SubTree)
{
    if(SubTree==nullptr) return 1;
    int i=Height(SubTree->left),j=Height(SubTree->right);
    if(i>j) return 1+i;
    else return 1+j;
}

template<class T>
int BinaryTree<T>::Size(TreeNode<T>* SubTree)
{
    if(SubTree==nullptr) return 0;
    return Size(SubTree->left)+Size(SubTree->right)+1;
}

template<class T>
int BinaryTree<T>::Leaf_Size(TreeNode<T>* SubTree)
{
    if(SubTree==nullptr) return 0;
    if(SubTree->left==nullptr&&SubTree->right==nullptr) return 1;
    return Leaf_Size(SubTree->left)+Leaf_Size(SubTree->right);
}

template<class T>
bool BinaryTree<T>::Is_In_Tree(TreeNode<T>*SubTree,const T&x)const
{
    if(SubTree==nullptr) return false;
    if(SubTree->data==x) return true;
    if(Find(SubTree->left,x)||Find(SubTree->right,x)) return true;
    return false;
}

template<class T>
TreeNode<T>* BinaryTree<T>::Find(TreeNode<T>*SubTree,const T&x)const
{
    if(SubTree==nullptr) return nullptr;
    if(SubTree->data==x) return SubTree;
    TreeNode<T>* temp=Find(SubTree->left,x);
    if(temp!=nullptr) return temp;
    temp=Find(SubTree->right,x);
    if(temp!=nullptr) return temp;
    return nullptr;
}

template <class T>
TreeNode<T>* BinaryTree<T>::Parent(TreeNode<T>* SubTree,TreeNode<T>* current)
{
    if(SubTree==nullptr) return nullptr;
    if(SubTree->left==current||SubTree->right==current) return SubTree;
    TreeNode<T>* temp=Parent(SubTree->left,current);
    if(temp!=nullptr) return temp;
    temp=Parent(SubTree->right,current);   
    if(temp!=nullptr) return temp;
    return nullptr;
}

template<class T>
TreeNode<T>* BinaryTree<T>::Copy(TreeNode<T> *originode)
{
    TreeNode<T>* temp=new TreeNode<T>;   
    if(originode!=nullptr){
        temp->data=originode->data;   
        temp->left=Copy(originode->left);
        temp->right=Copy(originode->right);  
    }
    else return nullptr;
    return temp;
}

template<class T>
void BinaryTree<T>::Traverse(TreeNode<T>* SubTree,ostream &out)
{
    if(SubTree!=nullptr){
        out<<SubTree->data<<' ';
        Traverse(SubTree->left,out);
        Traverse(SubTree->right,out);
    }
}

template<class T>
void BinaryTree<T>::preOrder(TreeNode<T> *SubTree)//,void*(*visit)(TreeNode<T> & Tree))
{
    if(SubTree!=nullptr){
        cout<<SubTree->data<<' ';
        preOrder(SubTree->left);
        preOrder(SubTree->right);
    }
}

template<class T>
void BinaryTree<T>::inOrder(TreeNode<T> *SubTree)//,void*(*visit)(TreeNode<T> & Tree))
{
    if(SubTree!=nullptr){
        inOrder(SubTree->left);
        cout<<SubTree->data<<' ';
        inOrder(SubTree->right);
    }
}

template<class T>
void BinaryTree<T>::postOrder(TreeNode<T> *SubTree)
{
    if(SubTree!=nullptr){
        postOrder(SubTree->left);
        postOrder(SubTree->right);
        cout<<SubTree->data<<' ';
    }
}

template<class T>
istream& operator>>(istream& in,BinaryTree<T>& Tree)
{
    CreatTree(in,Tree.root);
    return in;
}

template<class T>
ostream& operator<<(ostream& out,BinaryTree<T>& Tree)
{
    out<<"二叉树的前序遍历\n";
    Tree.Traverse(Tree.root,out);
    return out;
}

template<class T>
void BinaryTree<T>::Inorder_Recursion()
{
    cout<<"使用递归进行中序遍历："<<endl;
    inOrder(root);
}

template<class T>
void BinaryTree<T>::Preorder_Recursion()
{
    cout<<"使用递归进行前序遍历："<<endl;
    preOrder(root);
}

template<class T>
void BinaryTree<T>::Postorder_Recursion()
{
    cout<<"使用递归进行后序遍历："<<endl;
    postOrder(root);
}

template<class T>
void BinaryTree<T>::Preorder_Interation()
{
    cout<<"使用非递归进行前序遍历："<<endl;
    TreeNode<T>* current=root;                  //当前节点指向根节点
    stack<TreeNode<T>*> sta;                    //建栈
    do{
        while(current!=nullptr){                
            cout<<current->data<<' ';
            sta.push(current);
            current=current->left;
        }
        if(!sta.empty()){
            current=sta.top();
            sta.pop();
            current=current->right;
        }
    }while(!sta.empty()||current!=nullptr);
}

template<class T>
void BinaryTree<T>::Inorder_Interation()
{
    cout<<"使用非递归进行中序遍历："<<endl;
    TreeNode<T>* current=root;
    stack<TreeNode<T>*> sta;
    do{
        while(current!=nullptr){
            sta.push(current);
            current=current->left;
        }
        if(!sta.empty()){
            current=sta.top();
            sta.pop();
            cout<<current->data<<' ';
            current=current->right;
        }
    }while(!sta.empty()||current!=nullptr);
}

template<class T>
void BinaryTree<T>::Postorder_Interation()
{
    cout<<"使用非递归进行后序遍历："<<endl;
    int flag=0;
    stack<stkNode<T>> S;
    stkNode<T> w;
    TreeNode<T> *p=root;
    do{
        while(p!=nullptr){
            w.ptr=p;w.tag=0;S.push(w);
            p=p->left;
        }
        int flag=1;                     //循环标记，对于循环标记为1时表示右子树需遍历
        while(flag&&!S.empty()){
            w=S.top();S.pop();p=w.ptr;
            switch (w.tag)
            {
            case 0:
                w.tag=1;
                S.push(w);
                flag=0;
                p=p->right;
                break;
            case 1:
                cout<<p->data<<' ';
                break;
            }
        }
    }while(!S.empty());
}

#endif