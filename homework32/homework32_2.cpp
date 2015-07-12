#include <iostream>
#include <iostream>
#include <string>
using namespace std;
class figure
{
public:
virtual double sq()=0;
};
class circle:public figure
{
public:
circle(int rad):radius(rad)
{}
double sq(){
return (3.14*radius*radius);
}
private:
	int radius;
};
class rectangle:public figure
{
public:
rectangle(int size1,int size2):a(size1),b(size2)
{}
double sq(){
return (a*b);
}
private:
	int a,b;
};


int main(){
	figure *fig[3]={new rectangle(10,2),new rectangle(11,11),new circle(10)};
	cout <<fig[1]->sq();
return 0;
}