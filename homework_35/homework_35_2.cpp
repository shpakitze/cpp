#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<vector<int>> tab;
	tab.resize(9);
	for(int i=0;i<9;++i) {
		tab[i].resize(10);
	}
	for (int i=0;i<9;++i){
		for (int j=0;j<9;++j){
		tab[i][j]=(i+1)*(j+1);
		}
	}
	for (int i=0;i<9;++i){
		for (int j=0;j<9;++j){
			cout <<tab[i][j]<<" ";
		}
		cout <<endl;
	}


	return 0;
}