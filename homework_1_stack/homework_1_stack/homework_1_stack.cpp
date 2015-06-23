#include <iostream>
using namespace std;
class stack
{
public:
	stack():arr(nullptr),top(-1),max_size(4)
	{}
	~stack();
	stack(int new_size){
		arr=new int[new_size];
		top=0;
	}
int pop(){
	if (isempty()) {
		cout <<"stack is empty"<<endl;
		return 0;
	}
	return arr[top--];
}
void push(int val){
	if (isempty()){
	arr=new int[max_size];
	arr[++top]=val;
	return;
}
	if (isfull()){
		max_size*=2;
		int *new_arr=new int[max_size];
		for (int i=0;i<top+1;++i){
		new_arr[i]=arr[i];
		}
	new_arr[++top]=val;
	delete[]arr;
	this->arr=new_arr;
	return;
	}
	arr[++top]=val;
}
bool isempty(){
return top==-1;
}
int  gettop(){
return arr[top];
};
bool isfull(){
return top==max_size-1;
}
void show(){
	for (int i=0;i<top+1;++i){
	cout <<arr[i]<<" ";
	}
	cout <<endl;
}
private:
int *arr;
int top;
int max_size;
};


stack::~stack()
{
	delete []arr;
}


int main(){
stack a;
a.push(1);
a.push(2);
a.push(3);
a.push(4);
a.show();
a.push(5);
a.show();
int q=a.pop();
a.show();
return 0;
}