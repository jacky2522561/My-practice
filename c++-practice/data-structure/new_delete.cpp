#include <iostream>

using namespace std;

int main(){
	int num;
	cout<<"�ݭn�X��array�Ŷ� ";
	cin>> num;
	int *p = new int[num];
	cout<<"��J�Ҧ���"<<endl; 
	for(int i = 0;i<num;i++){
		cin>>p[i];
	}
	for(int i = 0;i<num;i++){
		cout<<p[i]<<endl;
	}  
	delete [] p;
	return 0;
}
