#include <iostream>
using namespace std;
struct simpl_rec
{
	int t_number;
	char fio[40];
};
struct record
{
	int t_number;
	char *fio;
	record *next;
	record(int tel,char *ff,record *nxt):t_number(tel),fio(ff),next(nxt)
	{}
};
class list
{
public:
	list();
	~list();
	void add(int tel,char *f){
		if (head==nullptr){
			head=new record(tel,f,nullptr);
			return;
		}
	head=new record(tel,f,head);
	}
	void show(){
	record *cur=head;
	while(cur!=nullptr){
	cout <<"t-"<<cur->t_number<<" fio"<<cur->fio<<endl;
	cur=cur->next;
	}
	}
	void add_from_file(){
	FILE *f;
	f=fopen("test.dat","rb");
	simpl_rec a;
	while (fread(&a,sizeof(simpl_rec),1,f))
	{
		cout <<a.fio<<"---"<<a.t_number<<endl;
		add(a.t_number,a.fio);
	}
	fclose(f);
	
}
void write_to_file(){
FILE *ff;
ff=fopen("test.dat","wb");
simpl_rec a;
record *cur=head;
while(cur->next!=nullptr){
	strcpy(a.fio,cur->fio);
	//a.fio="ne rabotaet";
	a.t_number=cur->t_number;
	fwrite(&a,sizeof(simpl_rec),1,ff);
	cur=cur->next;
	}
fclose(ff);
	
	}
private:
record *head;
};

list::list()
{
	head=nullptr;
}

list::~list()
{

}
int main(){
	list a;
	a.add(111,"1dsdsdsd");
	a.add(22,"2d");
	a.add(333,"3d");
	a.add(343,"34");
	a.write_to_file();
	//a.add_from_file();
	a.show();
	getchar();
return 0;
}

