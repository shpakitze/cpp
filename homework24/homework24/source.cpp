#include <iostream>
using namespace std;
class matrix
{
public:
	matrix();
	~matrix();
	matrix(int m,int n);
	matrix(const matrix&s);
	matrix &operator = (const matrix &);
	//matrix &operator + (const matrix &);
	friend matrix  operator + (const matrix &,const matrix &);
	friend matrix  operator * (const matrix &,const matrix &);
	friend matrix  operator * (const matrix &, int);
	friend matrix  operator * (int, const matrix &);
matrix& transp();
int GetEl(int,int);
void SetEl(int,int,int);
void show();
private:
int M;
int N;
int **arr;
};
void matrix::SetEl(int i,int j,int k){
	arr[i][j]=k;
}
int matrix::GetEl(int i,int j){
	return arr[i][j];
};
matrix& matrix :: operator=(const matrix& mat){
	cout <<"oper ="<<endl;
	if (this==&mat) return *this;
	if ((mat.M==this->M)&&(mat.N==this->N)){
		for (int i=0;i<this->M;++i){
			for (int j=0;j<this->N;++j){
				this->arr[i][j]=mat.arr[i][j];
			}
		}
	} else
	{
for (int i=0;i<M;++i)
		delete[] arr[i];
	delete[] arr;
	M=mat.M;
	N=mat.N;
arr = new int*[M];
            for (int z=0; z<M; z++){
				arr[z] = new int[N];
			}
	for (int i=0;i<M;++i){
		for (int j=0;j<N;++j){
			arr[i][j]=mat.arr[i][j];
			}
		}
		return *this;
	}
	
}
matrix::matrix()
{
	cout <<"basic const"<<endl;
	M=N=0;
	arr=NULL;
//	M=5;
//	N=5;
//arr = new int*[M];
//            for (int z=0; z<M; z++){
//				arr[z] = new int[M];
//			}
//	for (int i=0;i<M;++i){
//		for (int j=0;j<M;++j){
//			arr[i][j]=rand()%10;
//			}
//		}
}
matrix::matrix(int m,int n){
	cout <<"cons whith param"<<endl;
	M=m;
	N=n;
arr = new int*[M];
            for (int z=0; z<M; z++){
				arr[z] = new int[N];
			}
	for (int i=0;i<M;++i){
		for (int j=0;j<N;++j){
			arr[i][j]=rand()%10;
			}
		}
}
matrix::matrix(const matrix& s){
	cout <<"copy const"<<endl;
	M=s.M;
	N=s.N;
arr = new int*[M];
            for (int z=0; z<M; z++){
				arr[z] = new int[N];
			}
	for (int i=0;i<M;++i){
		for (int j=0;j<N;++j){
			arr[i][j]=s.arr[i][j];
			}
		}
}
matrix::~matrix()
{
	cout <<"--------------destr----------"<<endl;
	for (int i=0;i<M;++i)
		delete[] arr[i];
	delete[] arr;
}
void matrix::show(){
	cout<<"-------------------show-------"<<endl;
	for (int i=0;i<M;++i){
		for (int j=0;j<N;++j){
			cout<<arr[i][j]<<" ";
		}
		cout <<endl;
	}
cout<<"-------------------show-------"<<endl;
}
//matrix &matrix::operator+ (const matrix &mat){
//	cout <<"oper +"<<endl;
//	if ((this->N!=mat.N)||(this->M!=mat.M)) { cout <<"bad size"<<endl;} 
//	else{
//	for (int i=0;i<mat.M;++i){
//		for (int j=0;j<mat.N;++j)
//			this->arr[i][j]=this->arr[i][j]+mat.arr[i][j];
//	}
//	return *this;
//	};
//};
matrix  operator + (const matrix &a,const matrix &b){
	cout <<"glob+"<<endl;
	matrix x(a.M,a.N);
for (int i=0;i<x.M;++i){
		for (int j=0;j<x.N;++j)
			x.arr[i][j]=x.arr[i][j]+x.arr[i][j];
}		
		return x;


};
matrix  operator * (const matrix &a,const matrix &b){
	cout <<"glob*"<<endl;
	matrix x(a.M,b.N);
for (int i = 0;i<a.M;++i){
	for (int j = 0;j<b.N;++j){
		int R=0; 
		for (int k = 0;k<a.N;++k){
			R= R + a.arr[i][k]*b.arr[k][j];
		}
		x.arr[i][j]=R;
	}
}
		return x;


};
matrix  operator * (const matrix &mat,int a){
	matrix x=mat;
	for (int i=0;i<x.M;++i){
		for (int j=0;j<x.N;++j){
			x.arr[i][j]=a*mat.arr[i][j];
		}
	}
	return x;
};
matrix  operator * (int a, const matrix &mat){
	return (mat*a);
}
matrix& matrix::transp(){
	for (int i=0;i<M;++i){
		for (int j=i;j<N;++j){
			int t=arr[i][j];
			arr[i][j]=arr[j][i];
			arr[j][i]=t;
		}
	}
return *this;

};
void main(){
matrix a(2,2);
a.show();
a.SetEl(1,1,10);
a.show();
}