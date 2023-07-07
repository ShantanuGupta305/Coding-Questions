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
node* create(int v){
    node* n=new node(v);
    return n;
}
void preorder(node* &root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->l);
        preorder(root->r);
    }
}
void inorder(node* &root){
    if(root!=NULL){
        inorder(root->l);
        cout<<root->data<<" ";
        inorder(root->r);
    }
}
void postorder(node* &root){      
    if(root!=NULL){
        postorder(root->l);
        postorder(root->r);
        cout<<root->data<<" ";
    }
}
bool isbst(node* &root){
    static node* prev=NULL;
    if(root!=NULL){
        if(!isbst(root->l)){
            return false;
        }
        if(prev!=NULL&&prev->data>=root->data){
            return false;
        }
        prev=root;
        return isbst(root->r);
    }
    else{
        return true;
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
        if(root==NULL) root=create(k);
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
            if(k<prev->data) prev->l=create(k);
            else prev->r=create(k); 
        }    
    }
    else{
        cout<<"Element already exists\n";
    }
}
int main(){
    node* root=NULL,*p1=NULL,*p2=NULL,*p3=p1,*p4=p1;
    root=create(5);
    p1=create(3);
    p2=create(6);
    p3=create(1);
    p4=create(4);
    root->l=p1;
    root->r=p2;
    p1->l=p3;
    p1->r=p4;
    preorder(root);cout<<endl;
    inorder(root);cout<<endl;
    postorder(root);cout<<endl;
    if(isbst(root)) cout<<"This tree is bst\n";
    else cout<<"Not a bst\n";
    if(search(root,0)) cout<<"Found\n";
    else cout<<"Not found\n";
    int k,f=0;cin>>k;
    node* temp=root;
    while (temp!=NULL){                         //Iterative search
        if(temp->data==k){
            cout<<"Found Iteratively\n";f=1;break;
        }
        else if(k>temp->data){
            temp=temp->r;
        }
        else if (k<temp->data){
            temp=temp->l;
        }
    }
    if(!f) cout<<"Not Found Iteratively\n";
    // insert(root,2);insert(root,4);
    // insert(root,1);
    // insert(root,3);
    // insert(root,5);insert(root,6);
    // inorder(root);cout<<endl;
    if(search(root,0)) cout<<"Found\n";
    else cout<<"Not Found\n";
    return 0;
}