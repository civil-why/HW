#ifndef _decoding_h_
#define _decoding_h_

#include<iostream>
#include<fstream>
#include"hfm_tree.h"

using namespace std;

class Decode
{
private:
    string origin_code;             //待译码的编码
    string data;                    //编译成的文本

public:
    Decode();
    ~Decode();
    void Read_code();
    void Write_data();
    void de_code(HfmTree);
};


#endif