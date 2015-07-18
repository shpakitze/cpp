#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cstdlib>
using namespace std;
string oper[]={"+","-","*","/","(",")"};
string ar_oper[]={"+","-","*","/"};
string getnext(const string &st){
return 0;
}
bool isoper(string a){
	for (int i=0;i<6;++i){
	if (a==oper[i]) return true;
	} 
return false;
}
bool isar_oper(string a){
	for (int i=0;i<6;++i){
	if (a==ar_oper[i]) return true;
	} 
return false;
}
int main(){
string expr,temp;
//cin >> expr;
expr="(8+2*5)/(1+3*2-4)";
//expr="(1+2)*4";
std::queue<string> a,opn;
std::stack<string> help_opn;
int size=expr.size();
temp="";
string ch;
int i=0;
while (i<size){
	ch=expr[i];
	if (!isoper(ch)) {temp=temp+expr[i];++i;}else
{	if (temp!="") a.push(temp);
	temp=ch;
	if (temp!="") a.push(temp);
	++i;
	temp="";
}
}
if (temp!="") a.push(temp);
//while (!a.empty()){
//cout <<a.front()<<"!"<<endl;
//a.pop();
//}
//----------------------------------------------------
string cur;
string cur_oper;
while (!a.empty()){
	cur=a.front();
	if (!isoper(cur))
	{opn.push(cur);a.pop();}
	if (cur=="(")
	{help_opn.push(cur);a.pop();}
	if (cur==")")
	{
		while ((!help_opn.empty())&&(help_opn.top()!="(")){
			opn.push(help_opn.top());
			help_opn.pop();
		}
		if (!help_opn.empty()) help_opn.pop();
		a.pop();
	}
	cur_oper=cur;
	if (isar_oper(cur_oper)){
		if (!help_opn.empty()){
		if ((cur_oper=="+")||(cur_oper=="-")){
			while ((!help_opn.empty())&&(isar_oper(help_opn.top()))){
				opn.push(help_opn.top());
				help_opn.pop();
			}
		}
		if ((cur_oper=="*")||(cur_oper=="/")){
			while ((!help_opn.empty())&&((isar_oper(help_opn.top()))&&((help_opn.top()=="*")||(help_opn.top()=="/")))){
				opn.push(help_opn.top());
				help_opn.pop();
			}
		}
	}
		help_opn.push(cur_oper);
		a.pop();
	}
}
while (!help_opn.empty()){
opn.push(help_opn.top());
help_opn.pop();
}
std::stack<double> result;
std::queue<string> view=opn;
while (!view.empty()){
cout <<view.front()<<"!"<<endl;
view.pop();
}
double operand1, operand2,res;
while(!opn.empty()){
	cur=opn.front();
	opn.pop();
	if (!isar_oper(cur)) {result.push(stod(cur));} 
	else {
	operand1=result.top();
	result.pop();
	operand2=result.top();
	result.pop();
	char cur_char=cur[0];
	switch (cur_char)
	{
		case '+':
			res=operand2+operand1;
			break;
		case '-':
			res=operand2-operand1;
			break;
		case '*':
			res=operand2*operand1;
			break;
		case '/':
			res=operand2/operand1;
			break;
		
	}
	result.push(res);
	}
}
cout <<result.top();
return 0;
}