#include <iostream>

using namespace std;

int main(){
	int num = 10;
	int* v1 = &num;
	int** v2 = &v1;
	cout<<"v1的值 "<<v1<<endl;
	cout<<"v2的值 "<<v2<<endl;
	cout<<"v1所指的位置的內容 "<<*v1<<endl;
	cout<<"v2所指的位置的內容 "<<*v2<<endl;
	*v1 = 20;
	cout<<"num值 "<<num<<endl;
	cout<<"v1所指的位置的內容 "<<*v1<<endl;
	return 0; 
} 
