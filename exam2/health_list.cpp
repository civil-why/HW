#include"health_list.h"

void Health_list::list_delete_all(LinkedNode<Health_Map>* ptr){
    if(ptr==nullptr) return;
    list_delete_all(ptr->next);
    delete ptr;
}

void Health_list::putout_all(){
    LinkedNode<Health_Map>*temp=head;
    for(int i=0;i<sum_num;i++){
        temp->data.putout_std();
        temp=temp->next;
    }
}

bool Health_list::ins_node(int adr,Health_Map& T){
    if(adr<=0||adr>sum_num+1) return false;//无效数据
    LinkedNode<Health_Map>* temp=new LinkedNode<Health_Map> ;
    if(temp==nullptr){
        cerr<<"内存分配错误！"<<endl;
        exit(1);
        }
    LinkedNode<Health_Map>* p=head;
    if(adr!=sum_num){
        for(int i=0;i<adr;i++) p=p->next;
        temp->next=p->next;
        p->next=temp;
    }
    else {
        for(int i=1;i<adr;i++) p=p->next;
        p->next=temp;
        temp->next=nullptr;
    }
    sum_num++;
    return true;
}

bool Health_list::del_node(int adr){
    if(sum_num==0) return false;
    if(adr<1||adr>sum_num+1) return false; 
    LinkedNode<Health_Map>* q=head;
    for(int i=1;i<adr;i++) q=q->next;
    q->next=q->next->next;
    delete q->next;
    return true;
}

bool Health_list::search_node(long long num){
    LinkedNode<Health_Map> *p=head;
    for(int i=0;i<sum_num;i++){
        long long temp=p->data.get_std_num();
        if(temp==num){
            p->data.putout_std();
            return true;
        }
        p=p->next;
    }
    return false;
}



;
//bool Health_list::get_data(int adr,Health_Map& p){}