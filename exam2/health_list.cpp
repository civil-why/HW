#include"health_list.h"

void Health_list::list_delete_all(LinkedNode<Health_Map>* ptr){
    LinkedNode<Health_Map>* temp=ptr->next;
    for(int i=0;i<sum_num;i++){
        delete ptr;
        ptr=temp;
        if(ptr->next!=nullptr)temp=ptr->next;
    }
}

void Health_list::new_list()
{
    //LinkedNode<Health_Map>* p=head->next;
    for(int i=1;i<=sum_num;i++)
        del_node(i);
    sum_num=0;
}

void Health_list::putout_all(){
    LinkedNode<Health_Map>*temp=head->next;
    for(int i=0;i<Health_list::sum_num;i++){
        temp->data.putout_std();
        temp=temp->next;
    }
}

bool Health_list::ins_node(int adr,Health_Map& T){
    if(adr<0||adr>=Health_list::sum_num+1) return false;//无效数据
    LinkedNode<Health_Map>* temp=new LinkedNode<Health_Map> ;
    if(temp==nullptr){
        cerr<<"内存分配错误！"<<endl;
        exit(1);
        }
    LinkedNode<Health_Map>* p=head;
    for(int i=0;i<adr;i++) p=p->next;
    temp->data=T;
    temp->next=p->next;
    p->next=temp;
    // 插入最后不用特判
    // for(int i=1;i<adr;i++) p=p->next;
        // p->next=temp;
        // temp->next=nullptr;
    Health_list::sum_num++;
    return true;
}

bool Health_list::del_node(int adr){
    if(Health_list::sum_num==0) return false;
    if(adr<1||adr>Health_list::sum_num+1) return false; 
    LinkedNode<Health_Map>* q=head;
    for(int i=1;i<adr;i++) q=q->next;
    LinkedNode<Health_Map>* del=q->next;
    q->next=del->next;
    delete del;
    sum_num--;
    return true;
}

bool Health_list::search_node(long long num){
    LinkedNode<Health_Map> *p=head->next;
    for(int i=0;i<Health_list::sum_num;i++){
        long long temp=p->data.get_std_num();
        if(temp==num){
            p->data.putout_std();
            return true;
        }
        p=p->next;
    }
    return false;
}

void Health_list::Read()
{
    fstream file;
    file.open("List.dat",ios::in);
    Health_Map s;
    Health_list::sum_num=0;
    list_delete_all(head);                                  //释放原先的list
    LinkedNode<Health_Map> *p=new LinkedNode<Health_Map>;
    head=p;
    while(1){
        file.read((char*)&s,sizeof(s));
        if(!file) break;
        Health_list::sum_num++;
        LinkedNode<Health_Map>* temp=new LinkedNode<Health_Map>;
        p->next=temp;
        p=temp;
        p->data=s;
    }
    file.close();
}

void Health_list::Write(){
    fstream file;
    file.open("List.dat",ios::out);
    Health_Map s;
    LinkedNode<Health_Map>* p=head->next;
    for(int i=0;i<Health_list::sum_num;i++){
        s=p->data;
        file.write((char*)&s,sizeof(s));
        p=p->next;
    }
    file.close();
}

//bool Health_list::get_data(int adr,Health_Map& p){}