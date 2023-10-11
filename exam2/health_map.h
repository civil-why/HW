//用于储存单个学生信息

#ifndef _health_map_h_
#define _health_map_h_

#include<iostream>
#include<string>

using namespace std;

struct Date{
    int year;
    int month;
    int day;
};                                  //日期结构

class Health_Map
{
private:
    long long stdnum;               //学号
    string stdname;                 //学生姓名
    Date stddate;                   //学生出生日期
    char gender;                    //学生性别
    string health_condition;        //学生健康状况
public:
    Health_Map(long long,string,Date,char,string);//构造函数
    Health_Map(){};
    ~Health_Map(){};                //析构
    long long get_std_num()const;   //返回学生学号
    void putout_std()const;         //输出学生信息
    void operator=(Health_Map );    //用于复制内容
};

#endif