#include <iostream>
using namespace std;
typedef double T; 
class matrix
{
public:
	matrix();
	~matrix();
	matrix(int m,int n);
	matrix(const matrix&s);
	void init();
	matrix &operator = (const matrix &);
	//matrix &operator + (const matrix &);
	friend matrix  operator + (const matrix &,const matrix &);
	friend matrix  operator - (const matrix &,const matrix &);
	friend matrix  operator - (const matrix &, T);
	friend matrix  operator - (T, const matrix &);
	friend matrix  operator * (const matrix &,const matrix &);
	friend matrix  operator * (const matrix &, T);
	friend matrix  operator * (T, const matrix &);
	friend matrix  operator / (matrix &, matrix &);
	friend matrix  operator / (const matrix &, T);
	friend matrix  operator / (T, const matrix &);
	friend bool operator ==(const matrix&, matrix &);
	friend bool operator !=(const matrix&, matrix &);
	friend ostream &operator<< (ostream& os,const matrix &);
	matrix  &operator +=(const matrix &);
	matrix  &operator -=(const matrix &);
	matrix  &operator *=(const matrix &);
	matrix  &operator /=(matrix &);
	matrix  &operator *=(T);
	matrix  &operator /=(T);
	matrix& transp();
T GetEl(int,int);
void SetEl(int,int,T);
void show();
bool isSquare();//kvadratnaya li
bool isDiagonal(); 
bool isZero();
bool isIdentity();
bool isSymmetric();
bool isUpTriangular();
bool isLowTriangular();
void obr();//obratnaz matriza
T norm();//norma
T det();//determinant
private:
int M;
int N;
T **arr;
};
void matrix::init(){
	for (int i=0;i<M;++i){
		for (int j=0;j<N;++j){
			arr[i][j]=rand()%10;
			}
		}
}
T matrix::det(){
matrix q=*this;
T determinant=1;
int exchanges=0;
      for(int i=0; i<N-1; ++i)
    { 
      { //проверка на ноль
            T maxValue=q.arr[i][i];
			if( maxValue == 0) return maxValue;
			}

        T value=q.arr[i][i];
        determinant *= value;

        for(int j=i+1; j<N; ++j)
        { //Вычитаю строку из всех последующих
            T k=q.arr[j][i]/value;
            q.arr[j][i] = 0;
            for(int c=i+1; c<N; ++c) q.arr[j][c] -= q.arr[i][c]*k;
        }
    }
    determinant *= q.arr[N-1][N-1];
    if(exchanges%2) return -determinant; else return determinant;
	}
T matrix::norm(){
	T n=0;
	for (int i=0;i<M;++i)
	for (int j=0;j<N;++j){
	n=n+(arr[i][j])*(arr[i][j]);
	}
	n=sqrt(n);
	return n;
}
bool matrix::isSquare(){
	if (M==N)
		return true;
	else
		return false;

}
void matrix::SetEl(int i,int j,T k){
	if ((i<N)||(j<M)) arr[i][j]=k;
	else
		cout <<"out of range"<<endl;
}
T matrix::GetEl(int i,int j){
	return arr[i][j];
}
matrix& matrix :: operator=(const matrix& mat){
	cout <<"oper ="<<endl;
	if (this==&mat) return *this;
	if ((mat.M==this->M)&&(mat.N==this->N)){
		for (int i=0;i<this->M;++i){
			for (int j=0;j<this->N;++j){
				this->arr[i][j]=mat.arr[i][j];
			}
		}
		return *this;
	} else
	{
for (int i=0;i<M;++i)
		delete[] arr[i];
	delete[] arr;
	M=mat.M;
	N=mat.N;
arr = new T*[M];
            for (int z=0; z<M; z++){
				arr[z] = new T[N];
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
	//M=5;
	//N=5;
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
	if ((m==0)||(n==0)) {cout <<"bad number(must be >0)"<<endl;M=0;N=0;arr=NULL;}
	else{
	M=m;
	N=n;
arr = new T*[M];
            for (int z=0; z<M; z++){
				arr[z] = new T[N];
			}
	}
}
matrix::matrix(const matrix& s){
	cout <<"copy const"<<endl;
	M=s.M;
	N=s.N;
arr = new T*[M];
            for (int z=0; z<M; z++){
				arr[z] = new T[N];
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
	cout <<"size"<<M<<"x"<<N<<endl;
	if ((M==0)&&(N==0)) {cout <<"empty"<<endl; return;}
	for (int i=0;i<M;++i){
		for (int j=0;j<N;++j){
			cout<<arr[i][j]<<" ";
		}
		cout <<endl;
	}

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
	if ((a.M!=b.M)||(a.M!=b.M)) {cout <<"bad size"<<endl; matrix x; return x;}

	matrix x(a.M,a.N);
	x.init();
for (int i=0;i<x.M;++i){
		for (int j=0;j<x.N;++j)
			x.arr[i][j]=a.arr[i][j]+b.arr[i][j];
}		
		return x;


};
matrix  operator * (const matrix &a,const matrix &b){
	cout <<"glob*"<<endl;
	if (a.M!=b.N)
	{cout <<"bad size"<<endl; matrix x; return x;}
	matrix x(a.M,b.N);
	x.init();
for (int i = 0;i<a.M;++i){
	for (int j = 0;j<b.N;++j){
		T R=0; 
		for (int k = 0;k<a.N;++k){
			R= R + a.arr[i][k]*b.arr[k][j];
		}
		x.arr[i][j]=R;
	}
}
		return x;


};
matrix  operator * (const matrix &mat,T a){
	matrix x=mat;
	for (int i=0;i<x.M;++i){
		for (int j=0;j<x.N;++j){
			x.arr[i][j]=a*mat.arr[i][j];
			//x.SetEl(i,j,a*x.GetEl(i,j));
		}
	}
	return x;
};
matrix  operator * (int a, const matrix &mat){
	return (mat*a);
}
matrix  operator - (const matrix &a,const matrix &b){
	matrix x=b*(-1);
	return a+x;
}
matrix& matrix::transp(){
	if (!isSquare()) {
			matrix temp(N,M);
			for (int i=0;i<M;++i){
				for (int j=0;j<N;++j){
					temp.arr[j][i]=arr[i][j];
				}
			}


		
	*this=temp;
	return *this;
	
	}
	else {
	for (int i=0;i<M;++i){
		for (int j=i;j<N;++j){
			T t=arr[i][j];
			arr[i][j]=arr[j][i];
			arr[j][i]=t;
		}
	}
	
return *this;
	}
};
matrix  operator / (const matrix &mat,T a){
	matrix x=mat;
	for (int i=0;i<x.M;++i){
		for (int j=0;j<x.N;++j){
			x.arr[i][j]=mat.arr[i][j]/a;
			//x.SetEl(i,j,a*x.GetEl(i,j));
		}
	}
	return x;
};
matrix  operator / (T a, const matrix &mat){
	return (mat/a);
}
void matrix::obr(){
	if (M!=N)
	{cout <<"bad size, must be MxM"<<endl; return;}
	T temp;
	matrix e(M,N);
     for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            e.arr[i][j] = 0.0;
            if (i == j)
                e.arr[i][j] = 1.0;
        }
    for (int k = 0; k < N; k++)
    {
        temp = arr[k][k];
         for (int j = 0; j < N; j++)
        {
            arr[k][j] /= temp;
            e.arr[k][j] /= temp;
        }
         for (int i = k + 1; i < N; i++)
        {
            temp = arr[i][k];
             for (int j = 0; j < N; j++)
            {
                arr[i][j] -= arr[k][j] * temp;
                e.arr[i][j] -= e.arr[k][j] * temp;
            }
        }
    }
     for (int k = N - 1; k > 0; k--)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            temp = arr[i][k];
             for (int j = 0; j < N; j++)
            {
                arr[i][j] -= arr[k][j] * temp;
                e.arr[i][j] -= e.arr[k][j] * temp;
            }
        }
    }
	*this=e;
}
matrix  operator / (matrix &a,matrix &b){
	if ((a.isSquare())&&(b.isSquare())) {
	matrix x=b;
	x.obr();
	return a*x;
	} else 
	{cout <<"mus be MxM"<<endl; matrix q; return q;}
}
matrix& matrix::operator +=(const matrix &a){
	matrix q=*this+a;
	*this=q;
	return *this;
}
matrix& matrix::operator -=(const matrix &a){
	matrix q=*this-a;
	*this=q;
	return *this;
}
matrix& matrix::operator *=(const matrix &a){
	matrix q=(*this)*a;
	*this=q;
	return *this;
}
matrix& matrix::operator /=(matrix &a){
	matrix q=(*this)/a;
	*this=q;
	return *this;
}
matrix& matrix::operator *=(T a){
	matrix q=(*this)*a;
	*this=q;
	return *this;
}
matrix& matrix::operator /=(T a){
	matrix q=(*this)/a;
	*this=q;
	return *this;
}
bool operator ==(const matrix &a, matrix &b){
	if ((a.M==b.M)&&(a.N==b.N)) {
	for (int i=0;i<a.M;++i){
		for(int j=0;j<a.N;++j){
			if (a.arr[i][j]!=b.arr[i][j]){ return false;}
		}
	}
	return true;
	}
	else
		return false;
}
bool operator !=(const matrix &a, matrix &b){
	return !(a==b);
}
matrix pow(const matrix&a, int b){
	matrix x=a;
	for (int i=1;i<b;++i){
	x=x*a;
	}
	return x;
}
bool matrix::isDiagonal(){
	if (!(this->isSquare())) return false;
	for (int i=0;i<M;++i){
	for (int j=0;j<N;++j){
		if ((i!=j)&&(arr[i][j]!=0)) return false;
	}
}
return true;
}
bool matrix::isZero(){
for (int i=0;i<M;++i)
	for (int j=0;j<N;++j){
		if (arr[i][j]!=0) return false;
	}
	return true;
}
bool matrix::isIdentity(){
if (!this->isSquare()) return false;
for (int i=0;i<M;++i)
	for (int j=0;j<N;++j){
		if ((i==j)&&(arr[i][j]!=1)) return false;
		if ((i!=j)&&(arr[i][j]!=0)) return false;
	}
	return true;
}
bool matrix::isSymmetric(){
matrix a=*this;
a.transp();
return a==*this;
}
bool matrix::isUpTriangular(){
	if (!this->isSquare()) return false;
	for (int j=0;j<M;++j)
		for (int i=j+1;i<M;++i){
			if (arr[i][j]!=0) return false;
		}
return true;
}
bool matrix::isLowTriangular(){
	if (!this->isSquare()) return false;
	for (int i=0;i<M;++i)
		for (int j=i+1;j<M;++j){
			if (arr[i][j]!=0) return false;
		}
return true;
}
ostream &operator<< (ostream& os,const matrix &a){
	os <<"size"<< a.M<<"x"<<a.N<<"\n";
	for (int i=0;i<a.M;++i){
		for (int j=0;j<a.N;++j){
		os << a.arr[i][j]<<" ";
		}
	os <<"\n";
	}
return os;
}
void main(){
matrix a(3,3),b(3,3);
a.init();
b.init();
a.show();
b.show();

cout <<a;
}