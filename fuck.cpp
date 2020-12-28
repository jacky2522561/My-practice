#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	string numinput1,numinput2;
	vector<int> numlist1,numlist2,sum;
	
	cin>>numinput1>>numinput2;
	for(int i=0;i<numinput1.size();i++){
		numlist1.push_back(numinput1[i]-48);
	}
	for(int i=0;i<numinput2.size();i++){
		numlist2.push_back(numinput2[i]-48);
	}
	
	/*cout<<numinput1.size()<<endl;
	cout<<numinput2.size()<<endl;*/
	reverse(numlist1.begin(),numlist1.end());
	reverse(numlist2.begin(),numlist2.end());
	for(int i=0;i<numinput1.size()+numinput2.size();i++){
		sum.push_back(0);
	}
	
	/*for(int i=0;i<sum.size();i++){
		cout<<sum[i]<<endl;
	}*/
	//string *sum = new string[numinput1.size()*numinput2.size()];
	cout<< sum.size()<<endl;
	int carry;
	for(int i=0;i<numlist1.size();i++){
		carry = 0;                //i=99,j=999
		for(int j=0;j<numlist2.size();j++){
			sum[j+i]+=(numlist1[i]*numlist2[j]+carry)%10;
			carry=(numlist1[i]*numlist2[j]+carry)/10;
		}		
	}
	for(int i=sum.size()-1;i>=0;i--){
		cout<<sum[i];
	}
	/*cout<<endl;
	for(int i=0;i<numinput2.size();i++){
		cout<<numlist2[i];
	}*/
	sum.clear();
	return 0;
} 
/*no.  	 				index  0  num 24 
       9 9 9            index  1  num 27 
x        9 9            index  2  num 18  
-------------- 
     8 9 9 1
   8 9 9 1 0
--------------
   9 8 9 0 1*/      
