#include<bits/stdc++.h>
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
node* insucc(node* &root){
    node* curr=root;
    while(curr && curr->l!=NULL){
        curr=curr->l;
    }
    return curr;
}
node* del(node* &root,int k){
    if(k<root->data){
        root->l=del(root->l,k);
    }
    else if(k>root->data){
        root->r=del(root->r,k);
    }
    else if(k==root->data){
        if(root->l==NULL){
            node* temp=root->r;
            free(root);
            return temp;
        }
        else if(root->r==NULL){
            node* temp=root->l;
            free(root);
            return temp;
        }
        node* temp=insucc(root->r);
        root->data=temp->data;
        root->r=del(root->r,temp->data);
    }
    return root;
}
void inorder(node* &root){
    if(root!=NULL){
        inorder(root->l);
        cout<<root->data<<" ";
        inorder(root->r);
    }
}
bool search(node* &root,int k){
    if(root==NULL){
        return false;
    }
    else{
        if(k==root->data) return true;
        else if (k>root->data){
            return search(root->r,k);
        }
        else{
            return search(root->l,k);
        }
    }
}
void insert(node* &root,int k){
    if(!search(root,k)){
        node* temp=root;
        if(root==NULL) root=new node(k);
        else{
            node* prev=NULL;
            while (temp!=NULL){
                if(k<temp->data){
                    prev=temp;temp=temp->l;
                }
                else{
                    prev=temp;temp=temp->r;
                }
            }
            if(k<prev->data) prev->l=new node(k);
            else prev->r=new node(k); 
        }    
    }
    else{
        cout<<"Element already exists\n";
    }
}
int main(){
    node* root=NULL;
    insert(root,4);
    insert(root,2);
    insert(root,5);
    insert(root,1);
    insert(root,3);
    insert(root,6);
    inorder(root);cout<<endl;
    root=del(root,7); 
    inorder(root);cout<<endl;
    return 0;
}