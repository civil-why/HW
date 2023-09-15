#include"health_map.h"
#include"health_sheet.h"

using namespace std;

int main(int argc,char* argv[]){
    int choice=-1;
    Health_Sheet health_S;
    cout<<"欢迎使用学生健康系统"<<endl;
    cout<<"————————————————————————————————————————"<<endl;
    while(choice!=0)
    {
        cout<<"————————————————————————————————————————"<<endl;
        cout<<"1:新建学生健康表格 2:插入学生信息 3:删除学生信息 4:查询学生信息 5:查询全部学生信息 6：读取健康表格信息 7：写入学生健康表信息 0:保存学生健康表并退出系统"<<endl;
        cin>>choice;
        if(choice>7){
            cerr<<"输入出错，请重新输入"<<endl;
            exit(1);
        }
        cout<<"————————————————————————————————————————"<<endl;
        switch (choice)
        {
        case 1:{
            cout<<"警告！您确定要覆盖掉当前表格吗？当前信息会全部丢失！"<<endl;
            flag1:
            cout<<"请输入YES表示确认覆盖，输入NO回退到菜单页面: ";
            string str;
            cin>>str;
            if(str=="YES"){
                cout<<"输入新表格人数： ";
                int temp;
                cin>>temp;
                health_S.create_sheet(temp);
                }
            else if(str=="NO") break;
            else {
                cout<<"您的输入有误，请重新输入： ";
                goto flag1;
            }
            break;
        }
        case 2:{
            cout<<"选择插入位置： ";
            int temp;
            char gender;
            long long num;
            string name,condition;
            Date date;
            cin>>temp;
            cout<<"输入学生信息： "<<endl;
            cout<<"学生学号： "; cin>>num;
            cout<<"学生姓名： "; cin>>name;
            cout<<"学生出生日期(例：1999 12 31表示1999年12月31日出生)： "; cin>>date.year>>date.month>>date.day;
            cout<<"学生性别（输入M表示男生，输入W表示女生）: "; cin>>gender;
            cout<<"学生健康状况： "; cin>>condition;
            Health_Map map(num,name,date,gender,condition);
            if(health_S.ins_std(temp,map)){
                cout<<"录入信息成功！"<<endl;
            }
            else {
                cout<<"录入失败,请输入有效数据"<<endl;
                cout<<"即将回到菜单页面"<<endl;
                }
            break;
            }
        case 3:{
            cout<<"警告！您确定要删除掉学生信息吗？"<<endl;
            flag2:
            cout<<"请输入YES表示确认删除，输入NO回退到菜单页面: ";
            string str;
            cin>>str;
            if(str=="YES"){
                cout<<"输入删除学生在表格中所在位置： ";
                int temp;
                cin>>temp;
                health_S.del_std(temp);
                }
            else if(str=="NO") break;
            else {
                cout<<"您的输入有误，请重新输入： ";
                goto flag2;
            }
            break;
        }
        case 4:
            cout<<"输入所查学生的学号： ";
            long long temp;
            cin>>temp;
            if(health_S.search_std(temp)){
                cout<<"学生信息："<<endl;
            }
            else cout<<"未找到该学生，即将返回菜单"<<endl;
            break;
        case 5:
            cout<<"所有学生信息："<<endl;
            cout<<"————————————————————————————————————————"<<endl;
            health_S.putout_all();
            cout<<"————————————————————————————————————————"<<endl;
            break;
        case 6:
        {
            cout<<"已读取学生信息"<<endl;
            health_S.Read();
            health_S.putout_all();
            break;
        }
        case 7:
            health_S.Write();
            cout<<"已写入文件"<<endl;
            break;
        }
    }
    cout<<"已保存，即将退出系统"<<endl;
    return 0;
}