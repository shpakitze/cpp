#include <iostream>
#include <string.h>
using namespace std;
class str
{
public:
	str();
	~str();
	str(char *a);
	str(const str&);
	const char *getstr(){ return my_str;};
	void setstr();
	void setstr(char *s);
	int getsize();
	str& operator=(const str&);
	str operator+(const str&);
	void ins(int position,char a);
	void up();
	void low();
	void show_ascii();
private:
	int size;
	char *my_str;
};

str::str()
{
	size=0;
	my_str=NULL;
}
str::str(char *a)
{
	size=strlen(a);
	my_str=new char[size+1];
	strcpy(my_str,a);
}
str::str(const str &a){
	size=a.size;
	my_str=new char[size+1];
	strcpy(my_str,a.my_str);
}
str::~str()
{
	delete []my_str;
}
void str::setstr(){
	if (my_str!=NULL) delete []my_str;
	char a[256];
	cin.getline(a,256);
	size=strlen(a)+1;
	my_str=new char[size];
	strcpy(my_str,a);

}
int str::getsize(){
return size;
}
void str::setstr(char *s){
	if (my_str!=NULL) delete []my_str;
	size=strlen(s)+1;
	my_str=new char[size];
	strcpy(my_str,s);

}
str& str::operator=(const str&a){
	if (this==&a) return *this;
	if ((size!=a.size)||(size==0)){
	delete [] my_str;
	size=a.size;
	my_str=new char [size+1];
	strcpy(my_str,a.my_str);
	return *this;
	}
}
str str::operator+(const str& a){
str q;
q.size=size+a.size;
q.my_str=new char[q.size+1];
strcpy(q.my_str,my_str);
strcat(q.my_str,a.my_str);
return q;
}
void str::ins(int position,char a){
str q=*this;
delete [] my_str;
size=q.size+1;
my_str=new char[size+1];
for (int i=0;i<position;++i){
*(my_str+i)=*(q.my_str+i);
}
*(my_str+position)=a;
for (int i=position+1;i<size;++i){
	*(my_str+i)=*(q.my_str+i-1);
	}
*(my_str+size)='\0';
cout <<my_str<<"---"<<q.my_str<<endl;
}
void str::up(){
	strupr(my_str);
}
void str::low(){
	strlwr(my_str);
}
void str::show_ascii(){
	char a;
	for (int i=0;i<size;++i){
	a=*(my_str+i);
		cout <<(int)a<<"--";
	}
	cout <<endl;
}
int main(){
	str a,b;
	a.setstr();
	//a.low();
	cout <<a.getstr()<<endl;
	
return 1;
}