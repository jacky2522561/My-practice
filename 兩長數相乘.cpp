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
	reverse(numlist1.begin(),numlist1.end());
	reverse(numlist2.begin(),numlist2.end());
	for(int i=0;i<numinput1.size()+numinput2.size();i++){
		sum.push_back(0);
	}
	cout<< sum.size()<<endl;
	int carry,temp;
	for(int i=0;i<numlist1.size();i++){
		carry = 0;             
		for(int j=0;j<numlist2.size();j++){
			temp = numlist1[i]*numlist2[j]+carry+sum[j+i];
			sum[j+i] = temp%10;
			carry = temp/10;
			if(j==numlist2.size()-1){
				sum[j+i+1]=carry;
			}
		}		
	}
	if(sum[sum.size()-1]==0){
		sum.pop_back();
	}
	for(int i=sum.size()-1;i>=0;i--){
		cout<<sum[i];
	}
	sum.clear();
	return 0;
} 

