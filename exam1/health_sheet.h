//用于将学生信息放在一张表中

#ifndef _health_sheet_h_
#define _headth_sheet_h_

#include<fstream>
#include"health_map.h"
using namespace std;

const int default_max=100;

class Health_Sheet
{
private:
    Health_Map *std;//使用静态顺序表存放
    int last_std;//记录表中学生最后一位编号
    int maxSize;//表格最大允许人数
    void resize(int NewSize);
public:
    Health_Sheet();
    ~Health_Sheet();
    Health_Sheet(Health_Sheet& );
    void create_sheet(int);
    int Size()const{return maxSize;};
    int Length()const{return last_std+1;}
    bool ins_std(int,Health_Map&);
    bool del_std(int);
    bool search_std(long long);
    void putout_all();
    bool get_data(int i,Health_Map& T)const
    {if(i>=0&&i<=last_std) {std[i]=T; return true;}else return false;};
};

#endif