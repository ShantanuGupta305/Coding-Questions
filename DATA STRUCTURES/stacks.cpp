#include<iostream>
using namespace std;
struct stacks{
	int size;
	int top;
	int *arr;
};
bool isempty(stacks s){
	if(s.top==-1) return true;
	return false;
}
bool isfull(stacks s){
	if(s.top==s.size-1) return true;
	return false;
}
stacks push(stacks *s,int val){
	stacks S=*s;
	if(isfull(S)){
		cout<<"Cannot push "<<val<<endl;
		return S;
	}
	S.top++;
	S.arr[S.top]=val;
	return S;
}
stacks pop(stacks *s){
	stacks S=*s;
	if(isempty(S)){
		cout<<"Cannot pop element\n";
		return S;
	}
	int a=S.arr[S.top];
	cout<<a<<endl;
	S.top--;
	return S;
}
void peek(stacks s){
	if(isempty(s)){
		cout<<"Cannot peek\n";return;
	}
	cout<<"Top element is "<<s.arr[s.top]<<endl;
}
void traverse(stacks s){
	if(isempty(s)){
		cout<<"Cannot Traverse\n";return;
	}
	while (s.top!=-1)
	{
		cout<<s.arr[s.top--]<<" ";
	}
	cout<<endl;
}
int main(){
	stacks s;
	s.size=4;s.top=-1;s.arr=new int[s.size];
	s=push(&s,1);
	s=push(&s,2);
	s=push(&s,3);
	s=push(&s,4);
	s=push(&s,5);
	peek(s);
	traverse(s);
	s=pop(&s);
	return 0;
}