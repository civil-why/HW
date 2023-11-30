#include"decoding.h"

Decode::Decode()
{}

Decode::~Decode()
{}

void Decode::Read_code()
{
    fstream file;
    file.open("CodeFile.txt",ios::in);
    file>>origin_code;
}

void Decode::Write_data()
{
    fstream file;
    file.open("Textfile.txt",ios::out);
    file<<data;
}

void Decode::de_code(HfmTree Tree)
{
    Treenode<char_set>* temp=Tree.get_root();
    for(unsigned int i=0;i<=origin_code.size();i++){
        if(temp->data.data=='#'){
            if(origin_code[i]=='0') temp=temp->leftchild;
            else temp=temp->rightchild;
        }
        else{
            data+=temp->data.data;
            temp=Tree.get_root();
            i--;
        }
    }
}

