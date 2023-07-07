#include<iostream>
using namespace std;
class cicularqueue{
    public:
    int* arr;
    int size,f,r;
};
bool isempty(cicularqueue q){
    if(q.f==q.r) return true;
    return false;
}
bool isfull(cicularqueue q){
    if((q.r+1)%q.size==q.f) return true;
    else return false;
}
cicularqueue enqueue(cicularqueue* q,int v){
    cicularqueue Q=*q;
    if(isfull(Q)) {cout<<"cicularqueue is full\n";return Q;}
    else{
        Q.r=(++Q.r)%Q.size;
        Q.arr[Q.r]=v;
        return Q;
    }
}
cicularqueue dequeue(cicularqueue* q){
    cicularqueue Q=*q;
    if(isempty(Q)) {cout<<"cicularqueue is empty\n";return Q;}
    else{
        Q.f=(++Q.f)%Q.size;
        cout<<Q.arr[Q.f]<<" is dequeued\n";
        return Q;
    }
}
void display(cicularqueue q){
    if(isempty(q)) cout<<"There is nothing in cicularqueue\n";
    else{
        while (q.r!=q.f){
            q.f=(++q.f)%q.size;
            cout<<q.arr[q.f]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    cicularqueue q;
    q.size=4;q.f=q.r=0;q.arr=new int[q.size];
    q=enqueue(&q,1);
    q=enqueue(&q,2);
    q=enqueue(&q,3);
    display(q);
    return 0;
}