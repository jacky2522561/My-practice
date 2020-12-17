#include <iostream>
#include <stdio.h>
#include <deque>
#include <string>
#include <algorithm>
#include <iomanip>
 
#define Max 26
#define Color 4

using namespace std;

class GraphNode{
	public:
		char name;
		string self_color;
		int yet; //paint or unpaint?
		deque<char> adj;
		
		GraphNode(char name_){
			name=name_;
			yet=0; //paint=1,unpaint=0
		}
		void table(){
			cout<<"Node:"<<setw(2)<<name<<setw(10)<<"Color: "<<setw(7)<<self_color<<setw(17)<<"My neighber: ";
			for(int i = 0; i<adj.size(); i++){
				cout<<adj[i];
				cout<<" ";
			}
			cout<<endl;
		}
		
};

bool cmp(GraphNode* a,GraphNode* b){       //set the condition of sorting
	return a->adj.size()>b->adj.size();
}

int main(){
	deque<GraphNode*> NodeList;
	char Node1,Node2;
	
	for(int i=0;i<Max;i++){
		NodeList.push_back(new GraphNode((char)(i+65)));
	}
	
	cout<<"(!!NOTICE!! If you want to stop input, Plz input '(z,z)')"<<endl;
	cout<<"Plz enter the pairs of country, ex:(A,B) (B,C) etc..: "<<endl;
	do{
		scanf("(%c,%c)",&Node1,&Node2);
		if(int(Node1) != 122 && int(Node2) != 122){
			NodeList[((int)Node1-65)]->adj.push_back(Node2);
			NodeList[((int)Node2-65)]->adj.push_back(Node1);
		}
		fflush(stdin);                  //清除上一個scanf快取 
	}while(Node1 != 'z' && Node2 != 'z');
	
	int NNNN=0;    //Nonzero_Neighbor_Node_Number
	
	for(int i=0;i<NodeList.size();i++){
		if(NodeList[i]->adj.size()!=0){
			NNNN++;
		}
	}
	
	sort(NodeList.begin(),NodeList.end(),cmp); //sort Node by their dgree;
	
	string palette[Color]={"Red","Blue","yellow","Green"};
	deque<char> painted_country;
	
	for(int index = 0;index<Color;index++){
		for(int i = 0;i<NNNN;i++){
			int paintORnot=0; //0 = can paint,   !0 = can't paint
			if(NodeList[i]->yet==0){
				for(int j = 0;j<NodeList[i]->adj.size();j++){
					for(int k = 0;k<painted_country.size();k++){
						if(NodeList[i]->adj[j]==painted_country[k]){
							paintORnot++;
						}
					}
				}
				if(NodeList[i]->yet==0 && paintORnot==0){
					NodeList[i]->self_color=palette[index];
					painted_country.push_back(NodeList[i]->name);
					NodeList[i]->yet=1;
				}
			}
		}
		painted_country.clear();
	}
	
	bool right;
	for(int i=0;i<NNNN;i++){
		if(NodeList[i]->yet==0){
			right=0;
		}
		else right=1;
	}
	
	if(right){
		cout<<"----------------------------------------------------------------------"<<endl;
		for(int i=0;i<NodeList.size();i++){
			if(NodeList[i]->adj.size()!=0){
				NodeList[i]->table();
			}
		}
		cout<<"----------------------------------------------------------------------"<<endl;
		cout<<"We can solve the problem by "<<Color<<" colors!!!"<<endl;
		cout<<"Congratulations!!!"<<endl;
	}
	else{
		cout<<"----------------------------------------------------------------------"<<endl;
		cout<<"We can't solve the problem by "<<Color<<" colors!!!"<<endl;
		cout<<"Fail!! Try to add up more colors"<<endl;
	}

	return 0;
}
