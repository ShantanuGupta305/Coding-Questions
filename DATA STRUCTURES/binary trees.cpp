#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* l,*r;
    node (int v){
        data=v;
        l=r=NULL;
    }
};
/*working in gdb but not here*/
node* create(int v){
    node* n=new node(v);
    return n;
}
/*working in gdb but not here*/
void preorder(node* &root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->l);
        preorder(root->r);
    }
}
/*working in gdb but not here*/
void inorder(node* &root){
    if(root!=NULL){
        inorder(root->l);
        cout<<root->data<<" ";
        inorder(root->r);
    }
}
/*working in gdb but not here*/
void postorder(node* &root){      
    if(root!=NULL){
        postorder(root->l);
        postorder(root->r);
        cout<<root->data<<" ";
    }
}
int main(){
    node* root=NULL,*p1=NULL,*p2=NULL,*p3=p1,*p4=p1;
    root=create(1);
    p1=create(2);
    p2=create(3);
    p3=create(4);
    p4=create(5);
    root->l=p1;
    root->r=p2;
    p1->l=p3;
    p1->r=p4;
    preorder(root);cout<<endl;
    inorder(root);cout<<endl;
    postorder(root);cout<<endl;
    return 0;
}