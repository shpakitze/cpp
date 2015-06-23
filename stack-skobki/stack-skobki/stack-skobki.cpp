#include <iostream>
using namespace std;
class stack
{
public:
	stack():arr(nullptr),top(-1)
	{}
	~stack();
	stack(int new_size){
		arr=new char[new_size];
		top=-1;
	}
void pop(){
	if (isempty()) {
		cout <<"stack is empty"<<endl;
		return;
	}
	--top;
}
void push(char val){
	arr[++top]=val;
}
bool isempty(){
return top==-1;
}
char  gettop(){
return arr[top];
};
void show(){
	for (int i=0;i<top+1;++i){
	cout <<arr[i]<<" ";
	}
	cout <<endl;
}
private:
char *arr;
int top;
};


stack::~stack()
{
	delete []arr;
}
bool proverka(char *str){
	int size=strlen(str);
	stack expression(size);
char curr_char;
for (int i=0;i<size;++i){
	curr_char=str[i];
	if ((curr_char=='(')||(curr_char=='{')||(curr_char=='[')){
		expression.push(curr_char);
		
	}
	else if (((curr_char==')')&&(expression.gettop()=='('))||((curr_char==']')&&(expression.gettop()=='['))||((curr_char=='}')&&(expression.gettop()=='{'))){
				if (!expression.isempty()) expression.pop();
				else return false;
		
	}
	
}
return expression.isempty();
}

int main(){
char a[256];
bool expr;
cin.getline(a,256);
expr=proverka(a);
if (expr) cout <<"OK"<<endl;
else
cout <<"error"<<endl;
return 0;
}