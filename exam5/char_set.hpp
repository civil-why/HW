#ifndef _char_set_hpp_
#define _char_set_hpp_

#include<iostream>
#include<string>

using namespace std;

struct char_set{
    char data;                      //字符
    float frequency;                //频数
    string hfm_code;                //哈夫曼编码
    void operator=(const char_set &s){data=s.data;frequency=s.frequency;hfm_code=s.hfm_code;};//重载运算符
    bool operator!=(const char_set &s){if(data==s.data&&frequency==s.frequency) return false;else return true;};
    bool operator==(const char_set &s){if(data==s.data&&frequency==s.frequency) return true;else return false;};
};                                  //字符集定义

#endif