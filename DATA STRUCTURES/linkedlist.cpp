#include <iostream>
using namespace std;
class node{
    public:
    int val;node* next;
    node(int v){
        val=v;
        next=NULL;
    }
};
void insAThead(node* &head,int v){
    node* n=new node(v);
    if(head==NULL) head=n;
    else{
        n->next=head;
        head=n;
    }
}
void insATtail(node* &head,int v){
    node* n=new node(v);
    if(head==NULL) head=n;
    else{
        node* temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
    }
}
bool search(node* &head,int v){
    if(head==NULL) return false;
    else{
        node* temp=head;
        while(temp){
            if(temp->val==v) return true;
            temp=temp->next;
        }
        return false;
    }
}
void display(node* &head){
    if(head==NULL) cout<<"Empty"<<endl;
    else{
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }cout<<"NULL"<<endl;
    }
}
void del(node* &head,int v){
    if(head==NULL) printf("No element\n");
    else{
        int c=0;
        node* temp=head;
        while (temp!=NULL)
        {   
            if(temp->next==NULL&&temp->val!=v){
                cout<<"Element Not Present\n";    
                return;       
            }
            else if(temp->val==v&&head==temp){
                head=temp->next;
                delete temp;return;
            }
            else if(temp->next->val==v){
                c=1;break;
            }
            temp=temp->next;
        }
        if (c==1)
        {
            node* todel=temp->next;
            temp->next=temp->next->next;
            delete todel;
        }
    }
}
void insINbet(node* &head,int p,int v){
    node* n=new node(v);
    if(head==NULL) head=n;
    else{
        node* temp=head;
        while (temp!=NULL)
        {
           if(temp->next==NULL&&temp->val!=p){
               cout<<"Element cant be inserted\n";    
               return;       
           }
           else if(temp->val==p&&temp==head){
               n->next=head;
               head=n;
               return;
           } 
           else if(temp->next->val==p){
               n->next=temp->next;
               temp->next=n;
               return;
           }
           temp=temp->next;
        }
    }
}
void iterrev(node* &head){
    if(head==NULL) cout<<"Empty"<<endl;
    else if(head->next==NULL) return;
    else{
        node* prev=NULL,*nex,*curr=head;
        while (curr!=NULL)
        {
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        head=prev;
    }
}
node* recurrev(node* &head){
    if (head==NULL||head->next==NULL)
    {
        return head;
    }
    node* newhead=recurrev(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
node* revknodes(node* &head,int k){
    if(head==NULL||head->next==NULL) return head;
    node* prev=NULL,*curr=head,*nex;int c=0;
    while (curr!=NULL&&c<k)
    {
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
        c++;
    }
    if(nex!=NULL){
        head->next=revknodes(nex,k);
    }
    return prev;
}
void makecycle(node* &head,int pos){
    node* temp=head,*startpos;int count=1;
    while (temp->next!=NULL)
    {
        if(count==pos){
            startpos=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startpos;
}
bool detectcycle(node* &head){
    node* s=head,*f=head;
    while(f!=NULL&&f->next!=NULL){
        s=s->next;f=f->next->next;
        if (f==s)
        {
            return true;
        }
    }
    return false;
}
void remcycle(node* &head){
    if(detectcycle(head)){
        node* s=head,*f=head;
        do{
            s=s->next;f=f->next->next;
        }while(s!=f);f=head;
        while (f->next!=s->next)
        {
            f=f->next;
            s=s->next;
        }
        s->next=NULL;
    }
    else{
        cout<<"\nCycle not present";
    }
}
int main(){
    node* head=NULL;
    insATtail(head,1);
    insAThead(head,2);
    insATtail(head,3);
    insINbet(head,3,4);
    display(head);
    iterrev(head);
    display(head);
    node* newhead=recurrev(head);
    display(newhead);
    newhead=revknodes(newhead,2);
    display(newhead);
    if (detectcycle(head)){
        cout<<"\nCycle found";
    }
    else{
        cout<<"\nNot cycle";
    }
    makecycle(newhead,3);
    if (detectcycle(head)){
        cout<<"\nCycle found";
    }
    else{
        cout<<"\nNot cycle";
    }
    remcycle(newhead);
    display(newhead);
    return 0;
}