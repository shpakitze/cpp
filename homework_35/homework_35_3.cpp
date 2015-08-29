#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class student
{
public:
	student(const string&fn,const string&ln,int a):first_name(fn),last_name(ln),age(a)
	{};
	student()
	{};
	friend ostream& operator<<(ostream& os,const student &st){
		os<<"first name: "<<st.first_name<<endl<<"last name: "<<st.last_name<<endl<<"age: "<<st.age;
		return os;
	}
	string get_fname(){
		return first_name;
	};
	string get_lname(){
		return last_name;
	};
	int get_age(){
		return age;
	};
private:
	string first_name;
	string last_name;//97-122
	int age;
};
string rand_string(){
	string st="";
	for (int i=0;i<5+rand()%5;++i){
		st=st+char(97+rand()%26);
	}
	st=char(97+rand()%26);
	return st;
}
void show_vector(vector<student>& st){
	vector<student>::iterator it=st.begin();
	for(int i=0;i<st.size();++i){
		cout <<*(it+i)<<endl;
	}
	cout <<"----------------------"<<endl;
}
bool compare_f_name(student& st1,student& st2){
	return (st1.get_fname() < st2.get_fname());
}
bool compare_l_name(student& st1,student& st2){
	return (st1.get_lname() < st2.get_lname());
}
bool compare_age(student& st1,student& st2){
	return (st1.get_age() < st2.get_age());
}
int main(){
	vector<student> group;
	int size_group=5;
	group.resize(size_group);
	for(int i=0;i<size_group;++i){
		student st(rand_string(),rand_string(),1+rand()%4);
		group[i]=st;
	}
	show_vector(group);
	vector<student>:: iterator group_first=group.begin();
	vector<student>:: iterator group_last=group.end();
	sort(group.begin(),group.end(),compare_f_name);
	show_vector(group);
	sort(group.begin(),group.end(),compare_l_name);
	show_vector(group);
	iter_swap(group_first,min_element(group_first,group_last,compare_age));
	iter_swap(group_first+1,min_element(group_first+1,group_last,compare_age));
	iter_swap(group_first+2,min_element(group_first+2,group_last,compare_age));
	show_vector(group);
	return 0;
}