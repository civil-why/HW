#include"health_map.h"

Health_Map::Health_Map(long long num,string name,Date date,char gen,string condition):stdnum(num),stdname(name),stddate(date),gender(gen),health_condition(condition)
{}


long long Health_Map::get_std_num()const
{
    return stdnum;
}

void Health_Map::putout_std()const{
    cout<<"\n学生学号： "<<stdnum<<endl;
    cout<<"姓名： "<<stdname<<endl;
    cout<<"出生日期： "<<stddate.year<<"年"<<stddate.month<<"月"<<stddate.day<<"日"<<endl;
    cout<<"性别： ";
    if(gender=='M'){
        cout<<"男"<<endl;
    }
    else if(gender=='W'){
        cout<<"女"<<endl;
    }
    else cout<<"?"<<endl;
    cout<<"学生身体状况："<<health_condition<<endl;
}

void Health_Map::operator=(Health_Map s){
    this->stdnum=s.stdnum;
    this->gender=s.gender;
    this->stdname=s.stdname;
    this->stddate.year=s.stddate.year;
    this->stddate.month=s.stddate.month;
    this->stddate.day=s.stddate.day;
    this->health_condition=s.health_condition;
}

