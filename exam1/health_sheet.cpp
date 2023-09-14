#include"health_sheet.h"

void Health_Sheet::create_sheet(int max=default_max)
{
    maxSize=max;
    std = new Health_Map[max];
    if(std==nullptr){
        cerr<<"内存分配错误！"<<endl;
        exit(1);
    }
}

Health_Sheet::Health_Sheet()
{
    create_sheet();
    fstream file;
    file.open("Sheet.dat",ios::in|ios::binary);
    Health_Map s;
    last_std=-1;
    while(1){
        file.read((char*)&s,sizeof(s));
        if(!file) break;
        last_std++;
        std[last_std]=s;
    }
    last_std++;
    file.close();
}

Health_Sheet::Health_Sheet(Health_Sheet& T)//复制T到当前表
{
    maxSize=T.Size();
    last_std=T.Length()-1;
    std = new Health_Map[maxSize];
    if(std==nullptr){
        cerr<<"内存分配错误！"<<endl;
        exit(1);
    }
    Health_Map temp;//暂存
    for(int i=0;i<=last_std;i++){
        T.get_data(i,temp);
        std[i]=temp;
    }
}

Health_Sheet::~Health_Sheet(){
    fstream file;
    file.open("Sheet.dat",ios::out|ios::binary);
    Health_Map s;
    for(int i=0;i<last_std;i++){
        s=std[i];
        file.write((char*)&s,sizeof(s));
    }
    file.close();
    delete []std;
}

void Health_Sheet::resize(int NewSize){
    if(NewSize<=0){
        cerr<<"无效数组大小";
        return;
    }
    if(NewSize!=maxSize){
        Health_Map *newarr = new Health_Map[NewSize];
        if(newarr==nullptr){
        cerr<<"内存分配错误！"<<endl;
        exit(1);
        }
        int n=last_std+1;
        Health_Map * srcptr = std;
        Health_Map * desptr = newarr;
        while (--n)
            *desptr++=*srcptr++;
        delete [] std;
        std= newarr;
        maxSize= NewSize;
    }
}

bool Health_Sheet::ins_std(int adr,Health_Map& T){
    if(last_std==maxSize-1){
        resize(2*maxSize);
        }//表满，不可插入，重新建表
    if(adr<=0||adr>last_std+1) return false;//无效数据，不可插入
    for(int j=last_std;j>=adr-1;j--){
        std[j+1]=std[j];
    }
    std[adr-1]=T;
    last_std++;
    return true;
}

bool Health_Sheet::del_std(int adr){
    if(last_std==-1) return false;
    if(adr<1||adr>last_std+1) return false; 
    for(int i=adr;i<last_std;i++)
        std[i-1]=std[i];
    last_std--;
    return true;
}//删除某元素

bool Health_Sheet::search_std(long long s_num){
    for(int i=0;i<last_std;i++){
        long long temp=std[i].get_std_num();
        if(temp==s_num){
            std[i].putout_std();
            return true;
        }
    }
    return false;
}

void Health_Sheet::putout_all(){
    for(int i=0;i<last_std;i++)
        std[i].putout_std();
}//输出全部内容