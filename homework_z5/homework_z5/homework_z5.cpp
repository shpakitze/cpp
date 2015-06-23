#include <iostream>
using namespace std;
template <typename T>
struct node
{
	T data;
	node *prev;
	node *next;
	node(T dat,node* nxt,node *prv):data(dat),prev(prv),next(nxt)
	{}
};
template <typename T>
class list
{
public:
	list(){
	head=tail=nullptr;
	}
	//~list();
void add_head(T val){
	node<T> *temp=head;
	head=new node <T> (val,head,nullptr);
	if (temp!=nullptr) temp->prev=head; else tail=head;
	}
void add_tail(T val){
	node<T> *temp=tail;
	tail=new node <T> (val,nullptr,tail);
	if (temp!=nullptr) temp->next=tail; else head=tail;
	}

	void show_from_head(){
		node<T> *cur=head;
		while (cur!=nullptr)
		{
			cout <<cur->data<<" ";
			cur=cur->next;
		}
		cout <<endl;
	}
		void show_from_tail(){
		node<T> *cur=tail;
		while (cur!=nullptr)
		{
			cout <<cur->data<<" ";
			cur=cur->prev;
		}
		cout<<endl;
	}
private:
	node<T> *head,*tail;
};
int main(){
list <int> a;
a.add_head(1);
a.add_head(2);
a.add_head(3);
a.add_tail(10);
a.add_tail(11);
a.show_from_head();
a.show_from_tail();
return 1;
}