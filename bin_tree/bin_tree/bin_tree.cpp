#include<iostream>
using namespace std;
struct crime
{
	crime(char *dt,crime *nxt):data(dt),next(nxt)
	{}
	char *data;
	crime *next;
};
class list_crime
{
public:
	list_crime();
	~list_crime();
	//void delall();
	void add(char *data){
		if (!head) {
		head=new crime(data,nullptr);
		return;
		}
	head=new crime(data,head);
	}
	void show(){
		if (head==nullptr) 
			cout <<"roor"<<endl;
		else{
		cout <<"------------------------"<<endl;
	crime *cur_cr=head;
		while (cur_cr){
	cout <<cur_cr->data<<endl;
	cur_cr=cur_cr->next;
	}	
cout <<"------------------------"<<endl;
		}
}
private:
crime *head;
int count;
};
list_crime::list_crime()
{
	head=nullptr;
	count=0;
}
list_crime::~list_crime()
{
	//delall();
	//потом допишу
}



struct node
{
	int num_avto;
	list_crime crime_data;
	node *left,*right,*parent;
	node(int val,char *dat,node* lft,node* rgt,node *prnt):num_avto(val),left(lft),right(rgt),parent(prnt)
	{
		crime_data.add(dat);
	}
	void show_data(){
	cout <<num_avto<<endl;
	this->crime_data.show();
	}
};
class tree
{
public:
	tree();
	~tree();
	void add(int val,char *data);
	void show(node *item);
	node * del(node *item);
	void find(node *item,int val);
	node *find_max(node *);
	node *find_min(node *);
	void find(node *item,int first,int last);
	node* getroot(){
	return root;
	
	}
private:
	node *root;
};
void tree::add(int val,char *data){
	node *new_list=new node(val,data,nullptr,nullptr,nullptr);
	node  *prn;
	node *prn1=nullptr;
	prn=root;
	while (prn!=nullptr)
	{
		prn1=prn;
		if (val==prn->num_avto){
			prn->crime_data.add(data);
			return;
		}
		else {
		if (val>prn->num_avto)
			prn=prn->right;
		else{ 
			prn=prn->left;
		}
		}
	}
	new_list->parent=prn1;
	if (prn1==0) root=new_list;
	else
	{
		if (val<prn1->num_avto)
			prn1->left=new_list;
		else 
			prn1->right=new_list;
	}
}
node *tree::del(node *item){
return 0;
}
void tree::find(node *tr,int val){
	while (tr!=0&&tr->num_avto!=val){
		if (tr->num_avto>val)
			tr=tr->left;
		else
			tr=tr->right;
	}
tr->show_data();
}
void tree::show(node *item){
if (item!=nullptr){
	cout <<"------------"<<endl;
cout <<"avto number "<<item->num_avto<<endl;
cout <<"crime"<<endl;
item->crime_data.show();
show(item->left);
show(item->right);
	 }
}
tree::tree()
{
	root=nullptr;
}
tree::~tree()
{
	
}
node *tree::find_max(node *item){
	while (item->right) item=item->right;
	return item;
}
node *tree::find_min(node *item){
	while (item->left) item=item->left;
	return item;
}
void tree::find(node *tr,int a,int b){
if (tr!=nullptr){
	cout <<"------------"<<endl;
	if (tr->num_avto>=a&&tr->num_avto<=b){
	cout <<"avto number "<<tr->num_avto<<endl;
cout <<"crime"<<endl;
tr->crime_data.show();
	}
find(tr->left,a,b);
find(tr->right,a,b);
	 }

}




int main(){
	tree a;
	a.add(1,"1-1-1");//добавить номер и данные
	a.add(2,"22-22");
	a.add(3,"3-3");
	a.add(12,"12-12");
	a.add(2,"test");
	a.add(3,"t");
	a.add(4,"4-4-4");
	//a.show(a.getroot());
	a.find(a.getroot(),2,5);//найти по номеру





}