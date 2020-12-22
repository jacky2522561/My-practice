#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	string numinput1,numinput2;
	vector<int> numlist1,numlist2;
	
	cin>>numinput1>>numinput2;
	for(int i=0;i<numinput1.size();i++){
		numlist1.push_back(numinput1[i]-48);
	}
	for(int i=0;i<numinput2.size();i++){
		numlist2.push_back(numinput2[i]-48);
	}
	reverse(numlist1.begin(),numlist1.end());
	reverse(numlist2.begin(),numlist2.end());
	vector<int> sum
	/*for(int i=0;i<numinput1.size();i++){
		cout<<numlist1[i];
	}
	cout<<endl;
	for(int i=0;i<numinput2.size();i++){
		cout<<numlist2[i];
	}*/
	
	return 0;
} 
no.  	 				index  0  num 24 
       6 9 8            index  1  num 27 
x        9 3            index  2  num 18  
--------------          
