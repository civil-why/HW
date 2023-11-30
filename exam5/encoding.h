#ifndef _encoding_h_
#define _encoding_h_

#include<iostream>
#include<fstream>
#include<string>
#include"hfm_tree.h"
#include"char_set.hpp"

using namespace std;

class Encode
{
private:
    string origin_str;              //未编码的原始文本
    string hfm_code;                //完成编码后的哈夫曼编码
    node* rule;                     //编码规则
    int rule_num;                   //规则数量

protected:
    void Destroy(node*);
    node* Copy_rule(node*);

public:
    Encode();
    ~Encode();

    void Tran();
    void Write_code();
    void Read_tree(HfmTree&);
};

#endif