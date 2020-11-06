#include <iostream>

using namespace std;

int main(){
	int num;
	cout<<"需要幾個array空間 ";
	cin>> num;
	int *p = new int[num];
	cout<<"輸入所有值"<<endl; 
	for(int i = 0;i<num;i++){
		cin>>p[i];
	}
	for(int i = 0;i<num;i++){
		cout<<p[i]<<endl;
	}  
	delete [] p;
	return 0;
}
