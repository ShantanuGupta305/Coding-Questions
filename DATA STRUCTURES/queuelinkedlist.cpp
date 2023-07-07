#include<iostream>
using namespace std;
class queue{
    public:
    int val;
    queue* next;
    queue(int v){
        val=v;
        next=NULL;
    }
};
bool isempty(queue* &f,queue* &l){
    if(f==NULL && l==NULL) return true;
    return false; 
}
void enqueue(queue* &f,queue* &l,int v){
    if(isempty(f,l)){
        f=l=new queue(v);
    }
    else{
        queue* n=new queue(v);
        l->next=n;
        l=n;
    }
}
void dequeue(queue* &f,queue* &l){
    if(isempty(f,l)) cout<<"Nothing to dequeue\n";
    else if(f==l){
        queue* n=f;
        f=f->next;l=l->next;
        cout<<n->val<<" is dequeued\n";
        free(n);
    }
    else{
        queue* n=f;
        f=f->next;
        cout<<n->val<<" is dequeued\n";
        free(n);
    }
}
void display(queue* &f,queue* &l){
    if(isempty(f,l)) cout<<"Nothing to display\n";
    else{
        queue* n=f;
        while (n!=NULL){
            cout<<n->val<<" ";
            n=n->next;
        }
        cout<<endl;
    }
}
int main(){
    queue* f=NULL,*l=NULL;
    enqueue(f,l,1);
    enqueue(f,l,2);
    enqueue(f,l,3);
    enqueue(f,l,4);
    display(f,l);
    return 0;
}