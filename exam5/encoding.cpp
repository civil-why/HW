#include"encoding.h"

Encode::Encode()
{
    rule=nullptr;
}

Encode::~Encode()
{
    Destroy(rule);
}

void Encode::Destroy(node* current)
{
    if(current==nullptr) return;
    else{
        Destroy(current->next);
        delete current;
    }
}

void Encode::Tran()
{
    ifstream file;
    file.open("ToBeTran.txt",ios::in);
    getline(file,origin_str);
    for(unsigned int i=0;i<origin_str.size();i++){
        node* current=rule;
        for(int j=0;j<rule_num;j++){
            if(origin_str[i]==current->data.data){
                hfm_code+=current->data.hfm_code;
                break;
                }
            current=current->next;
        }
    }
}

void Encode::Read_tree()
{
    fstream file;
    file.open("hfmTree.dat",ios::in|ios::binary);
    char_set s;
    int i=0;
    node *current=new node;
    node *begin=current;
    while(1){
        if(file.eof()) break;
        file>>s.data>>s.frequency;
        if(s.data!='#'){
            if(s.data=='*') s.data=' ';
            file>>s.hfm_code;
            node* temp=new node;
            temp->data=s;
            temp->next=nullptr;
            current->next=temp;
            current=current->next;
            i++;
        }
    }
    rule=begin;
    rule_num=i;
    //node* str=Copy_rule(rule);
    //HfmTree t(i,str);
    //Tree=t;
}

void Encode::Write_code()
{
    fstream file;
    file.open("CodeFile.txt",ios::out);
    file<<hfm_code;
}

// node* Encode::Copy_rule(node* current)
// {
//     if(current==nullptr) return nullptr;
//     else{
//         node* temp=new node;
//         temp->data=current->data;
//         temp->next=Copy_rule(current->next);
//         return temp;
//     }
// }