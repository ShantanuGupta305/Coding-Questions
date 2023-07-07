#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* l,*r;int h;
    node(int k){
        data=k;l=r=NULL;h=1;
    }
};
int max(int a,int b){
    return (a>b)?a:b;
}
int getheight(node* &n){
    if(n==NULL) return 0;
    return n->h;
}
int getbf(node* &n){
    if(n==NULL) return 0;
    return getheight(n->l)-getheight(n->r);
}
node* rightrotate(node* &y){
    node* x=y->l;
    node* t2=x->r;
    x->r=y;
    y->l=t2;
    y->h=max(getheight(y->l),getheight(y->r))+1;
    x->h=max(getheight(x->l),getheight(x->r))+1;
    return x;
}
node* leftrotate(node* &x){
    node* y=x->r;
    node* t2=y->l;
    y->l=x;
    x->r=t2;
    y->h=max(getheight(y->l),getheight(y->r))+1;
    x->h=max(getheight(x->l),getheight(x->r))+1;
    return y;
}
node* insert(node* &root,int k){
    if(root==NULL) return new node(k);
    else if(k<root->data) root->l=insert(root->l,k);
    else if(k>root->data) root->r=insert(root->r,k);
    root->h=1+max(getheight(root->l),getheight(root->r));
    int bf=getbf(root);
    if(bf>1 && k<root->l->data){    //ll
        return rightrotate(root);
    }
    else if(bf<-1 && k>root->r->data){  //rr
        return leftrotate(root);
    }
    else if(bf>1 && k>root->l->data){   //lr
        root->l=leftrotate(root->l);
        return rightrotate(root);
    }
    else if(bf<-1 && k<root->r->data){  //rl
        root->r=rightrotate(root->r);
        return leftrotate(root);
    }
    return root;
}
void preorder(node* &root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->l);
    preorder(root->r);
}
int main(){
    node* root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,3);
    preorder(root);
    return 0;
}