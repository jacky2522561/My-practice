#include <iostream>

using namespace std;

int main(){
	int num = 10;
	int* v1 = &num;
	int** v2 = &v1;
	cout<<"v1���� "<<v1<<endl;
	cout<<"v2���� "<<v2<<endl;
	cout<<"v1�ҫ�����m�����e "<<*v1<<endl;
	cout<<"v2�ҫ�����m�����e "<<*v2<<endl;
	*v1 = 20;
	cout<<"num�� "<<num<<endl;
	cout<<"v1�ҫ�����m�����e "<<*v1<<endl;
	return 0; 
} 
