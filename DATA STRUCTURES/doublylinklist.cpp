#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void inshead(node* &head,int v){
    if(head==NULL){
        node* n=new node(v);
        head=n;
    }
    else{
        node* n=new node(v);
        node* temp=head;
        n->next=temp;
        temp->prev=n;
        head=n;
    }
}
void instail(node* &head,int v){
    if (head==NULL)
    {
        node* n=new node(v);
        head=n;
    }
    else{
        node* n=new node(v);
        node* temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
        n->prev=temp;
    }
}
bool search(node* &head,int v){
    if(head==NULL){
        return false;
    }
    else{
        node* temp=head;
        while (temp!=NULL)
        {
            if(temp->data==v){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
}
void del(node* &head,int v){
    if(search(head,v)){
        node* temp=head,*p=NULL;
        while (temp!=NULL)
        {
            if(temp->data==v){
                p=temp;break;
            }
            temp=temp->next;
        }
        if (temp!=head&&temp->next!=NULL){
            temp->next->prev=temp->prev;
            temp->prev->next=temp->next;
            delete p;
        }
        else if (temp->next==NULL&&temp!=head){
            temp->prev->next=NULL;
            delete p;
        }
        else{
            temp->next->prev=NULL;head=temp->next;
            delete p;
        }
    }
    else{
        cout<<"Can't be deleted\n";
    }
}
void display(node* &head){
    if(head==NULL) cout<<"Empty linked list\n";
    else{
        node* temp=head;
        while (temp!=NULL)
        {
            cout<<temp->data<<"<=>";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
}
void insbef(node* &head,int v,int k){
    if(head==NULL){
        cout<<"Since no element present hence inserted at head\n";
        node* n=new node(k);
        head=n;
    }
    else{
        node* n=new node(k),*temp=head;int c=0;
        while (temp!=NULL){
            if(temp->data==v&&temp!=head){
                n->next=temp;
                n->prev=temp->prev;
                temp->prev->next=n;
                temp->prev=n;c=1;break;
            }
            else if(temp->data==v&&temp==head){
                n->next=temp;
                temp->prev=n;
                head=n;c=1;break;
            }
            temp=temp->next;
        }
        if(c==0){
            cout<<"Element not found hence can't be inserted\n";
        }
    }
}
int main(){
    node* head=NULL;
    insbef(head,1,0);
    inshead(head,2);
    instail(head,3);
    instail(head,4);
    instail(head,5);
    instail(head,6);
    instail(head,7);
    instail(head,8);
    inshead(head,1);
    del(head,9);
    if (search(head,8)){
        cout<<"Found\n";
    }
    else{
        cout<<"Not Found\n";
    }
    display(head);
    return 0;
}