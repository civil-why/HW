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
};

class Health_Map
{
private:
    long long stdnum;//学号
    string stdname;
    Date stddate;
    char gender;
    string health_condition;
public:
    Health_Map(long long,string,Date,char,string);
    Health_Map(){};
    ~Health_Map(){};
    long long get_std_num()const;
    void putout_std()const;
    void operator=(Health_Map );
};

#endif