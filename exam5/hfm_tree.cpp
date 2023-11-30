#include"hfm_tree.h"

HfmTree::HfmTree(int n,node* str):num(n)
{   
    build(str);
}

HfmTree::HfmTree(const HfmTree& h)
{
    num=h.num;
    root=Copy(h.root);
}

HfmTree::~HfmTree()
{
    if(root!=nullptr) destroy(root);
}

void HfmTree::destroy(Treenode<char_set> *current)
{
    if(current!=nullptr){
        if(current->leftchild!=nullptr) destroy(current->leftchild);
        if(current->rightchild!=nullptr) destroy(current->rightchild);
        delete current;
    }
}

Treenode<char_set>* HfmTree::find_2_min(node* &str)
{
    char_set min1,min2;
    node* s=str->next;//临时指针，指向结点位置
    min1=s->data;
    for(int i=0;i<num;i++){
        if(s->data.frequency<min1.frequency)
            min1=s->data;
        s=s->next;
    }
    s=str->next;//重置临时指针
    if(min1==s->data) min2=s->next->data;
    else min2=s->data;
    for(int i=0;i<num;i++){
        if(s->data.frequency<min2.frequency&&s->data.data!=min1.data)
            min2=s->data;
        s=s->next;
    }

    node* t=new node;
    t->data.data='#';
    t->data.frequency=min1.frequency+min2.frequency;
    t->next=str->next;
    str->next=t;

    Treenode<char_set>* temp= new Treenode<char_set>;   //将两个最小值放入同一树中
    temp->leftchild=nullptr;
    temp->rightchild=nullptr;

    s=str;                                              //重置临时指针
    while(min1!=s->next->data) s=s->next;
    node* k=s->next;                                    //临时指针，用于删除多余结点
    s->next=k->next;
    if(min1.data!='#'){                                 
        temp->leftchild=new Treenode<char_set>;
        temp->leftchild->leftchild=nullptr;
        temp->leftchild->rightchild=nullptr;
        temp->leftchild->data=min1;
    }                                                   //判断是否需要新建左子女结点
    else temp->leftchild=k->tree;
    delete k;                                           //删掉原本的链表结点

    s=str;                                              //重置临时指针
    while(min2!=s->next->data) s=s->next;
    k=s->next;                                          //临时指针，用于删除多余结点
    s->next=k->next;
    if(min2.data!='#'){                                 //判断是否需要新建右子女结点
        temp->rightchild=new Treenode<char_set>;
        temp->rightchild->leftchild=nullptr;
        temp->rightchild->rightchild=nullptr;
        temp->rightchild->data=min2;
        }
    else temp->rightchild=k->tree;
    delete k;                                           //删掉原本的链表结点

    temp->data=t->data;                                 
    t->tree=temp;
    num--;                                              //删了两个加了一个，总数减一                                   
    
    return temp;
}

void HfmTree::build(node* &str)
{
    while(num>2) find_2_min(str);
    root=find_2_min(str);
    string s;
    build_code(root,s);
}

int HfmTree::Height()
{
    return Height(root);
}

int HfmTree::Height(Treenode<char_set>* current)
{
    if(current==nullptr) return 1;
    else {
        int l,r;
        l=Height(current->leftchild);
        r=Height(current->rightchild);
        if(l>r) return l;
        else return r;
    }
}

void HfmTree::Print_Tree()
{
    //先考虑层序遍历再考虑树形
}

void HfmTree::Write()
{
    ofstream file;
    file.open("hfmTree.dat",ios::out|ios::binary);
    Pre_order_in(root,file);
    file.close();
}

void HfmTree::Pre_order_in(Treenode<char_set>* current,ofstream &os)
{
    if(current==nullptr) return;
    else {
        os<<current->data.data<<' '<<current->data.frequency<<' '<<current->data.hfm_code<<' ';
        Pre_order_in(current->leftchild,os);
        Pre_order_in(current->rightchild,os);
        }
}

void HfmTree::build_code(Treenode<char_set>* current,string hfm_code)
{
    if(current->data.data!='#'){
        current->data.hfm_code=hfm_code;
        return;
    }
    else {
        build_code(current->leftchild,hfm_code+'0');
        build_code(current->rightchild,hfm_code+'1');
    }
}

Treenode<char_set>* HfmTree::Copy(Treenode<char_set>* current)
{
    Treenode<char_set>* temp=new Treenode<char_set>;
    if(current==nullptr) return nullptr;
    else{
        temp->data=current->data;
        temp->leftchild=Copy(current->leftchild);
        temp->rightchild=Copy(current->rightchild);
    }
    return temp;
}

bool HfmTree::Is_Tree()
{
    return  (root==nullptr)?false:true;
}

void HfmTree::operator=(const HfmTree& h)
{
    root=Copy(h.root);
}