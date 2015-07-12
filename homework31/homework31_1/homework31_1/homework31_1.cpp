#include <iostream>
#include <iostream>
#include <string>
using namespace std;
class Employer
{
public:
	string name;
	int age;
	Employer(int a,const string &st):age(a),name(st)
	{}
	
virtual void print()=0;
private:

};
class President:public Employer
{
public:
	President(int a,const string &st,string z):Employer(a,st),avto_num(z)
	{}
	string avto_num;
	void print(){
	cout <<"President \n"<<"age "<<age<<"\n"<<"name "<<name<<"\n"<<"avto_num "<<avto_num<<endl;
}
};
class Manager:public Employer
{
public:
	Manager(int a,const string &st,string z):Employer(a,st),moto_num(z)
	{}
	string moto_num;
	void print(){
	cout <<"Manager \n"<<"age "<<age<<"\n"<<"name "<<name<<"\n"<<"moto_num "<<moto_num<<endl;
}
};
class Worker:public Employer
{
public:
	Worker(int a,const string &st,int z):Employer(a,st),zp(z)
	{}
	int zp;
	void print(){
	cout <<"Worker \n"<<"age "<<age<<"\n"<<"name "<<name<<"\n"<<"zp "<<zp<<endl;
}
};
int main(){
	Employer *epl[3]={new Worker(22,"Ivan",1000),
						new Manager(30,"Vova","suzuki"),
							new President(40,"Oleg","ferari")};

for (int i=0;i<3;++i){
epl[i]->print();
}
return 0;
}