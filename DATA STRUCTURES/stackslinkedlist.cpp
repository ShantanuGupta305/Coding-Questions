#include<iostream>
using namespace std;
class stacks{
    public:
    int val;
    stacks* next;
    stacks(int v){
        val=v;
        next=NULL;
    }
};
bool isempty(stacks* &top){
    if(top==NULL) return true;
    return false;
}
void push(stacks* &top,int v){
    if(isempty(top)){
        top=new stacks(v);return;
    }
    else{
        stacks *s=new stacks(v);
        s->next=top;
        top=s;
    }
}
void peek(stacks* &top){
    if(isempty(top)) cout<<"No element\n";
    else{
        cout<<"Top of stack is "<<top->val<<endl;
    }
}
void pop(stacks* &top){
    if(isempty(top)) cout<<"Stack Underflow\n";
    else{
        stacks *s=top;
        top=top->next;
        cout<<s->val<<" is poped\n";
        free(s);
    }
}
void display(stacks* &top){
    if(isempty(top)) cout<<"Empty Stack\n";
    else{
        stacks* s=top;
        while (s!=NULL){
            cout<<s->val<<" ";
            s=s->next;
        }
        cout<<endl;
    }
}
int main(){
    stacks* top=NULL;
    peek(top);
    pop(top);
    display(top);
    push(top,1);
    peek(top);
    push(top,2);
    peek(top);
    push(top,3);
    peek(top);
    push(top,4);
    peek(top);
    display(top);
    return 0;
}