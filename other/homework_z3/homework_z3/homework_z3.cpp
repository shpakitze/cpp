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
	void delstr(){
		delete []my_str;
	}
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
struct node
{
	str data;
	node *next;
	node(str a,node *nxt):data(a),next(nxt)
	{}
};
class queue
{
public:
	queue();
	queue(const queue&);
	void delqueue();
	~queue();
	void add(str a);
	str exstract();
	int getcount(){
	return count;
	}
	bool isempty(){
	return count==0;
	}
	void show(){
		cout <<"--show queue"<<endl;
	node *cur=head;
	while (cur!=nullptr){
		str dat=cur->data;
		cout <<dat.getstr()<<endl;	
		cur=cur->next;
	}
		cout <<"-----------------"<<endl;
	}
	queue &operator=(const queue &a){
		cout <<"operator="<<endl;
		if (count!=0)
			{delqueue();	
		count=0;}
	
	node *cur=a.head;
	while(cur!=nullptr){
	this->add(cur->data);
	cur=cur->next;
	}
	return *this;
	}
private:
	node *head,*tail;
	int count;
};

queue::queue()
{
	head=tail=nullptr;
	count=0;
}
queue::queue(const queue &a)
{
	cout <<"copy"<<endl;
	head=tail=nullptr;
	count=0;
	node *cur=a.head;
	while (cur!=nullptr)
	{
	this->add(cur->data);
	cur=cur->next;
	}
	
}
void queue::add(str a){
	if (tail!=nullptr){
		tail->next=new node(a,nullptr);
		tail=tail->next;
		++count;
		}
	else{
tail=new node(a,nullptr);
head=tail;
++count;
}
}
str queue::exstract(){
	if (count) {
	node *temp=head;
	head=head->next;
	--count;
	return temp->data;
	delete temp;
	}
}
void queue::delqueue()
{
	
	while (head!=nullptr)
	{node *temp=head;
	head=head->next;
	delete temp;
	}
	head=tail=nullptr;
	count=0;
}
queue::~queue()
{
	delqueue();
}
int main(){
	str a;
	a.setstr();
	str b("bbb");
	str c("cccc");
	cout <<a.getstr()<<endl;
	cout <<b.getstr()<<endl;
	cout <<c.getstr()<<endl;
	queue _queue;
	_queue.add(a);
	_queue.add(b);
	_queue.add(c);
	_queue.show();
	_queue.exstract();
	_queue.show();
	queue _queue1;
	_queue1.add(a);
	_queue1=_queue;
_queue1.show();
return 1;
}