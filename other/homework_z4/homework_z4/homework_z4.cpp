#include <iostream>
using namespace std;
struct node
{
int value;
node *next;
node(int vl,node *nxt):value(vl),next(nxt)
{}
};
class list
{
public:
	list();
	~list();
	void add(int val){
	head=new node(val,head);
	}
bool empty(){
	return head==nullptr;
	}
void show(){
node *cur=head;
while (cur!=0)
{cout <<cur->value<<" ";
cur=cur->next;
}
cout<<endl;
}
void revers(){
node *cur=head;
node *newlist=nullptr;
node *q;
while (cur!=nullptr)
{q=cur;
cur=cur->next;
q->next=newlist;
newlist=q;
}
head=newlist;
}
private:
	node *head;
};

list::list()
{
	head=nullptr;
}
list::~list()
{
node *cur=head;
while (head!=nullptr){
	node *cur=head;
	head=head->next;
	delete cur;
}
}

int main(){
	list a;
	for (int i=0;i<10;i++){
	a.add(i);
	}
	a.show();
	a.revers();
	a.show();
}