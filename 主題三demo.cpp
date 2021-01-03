#include <iostream>
#include <stdio.h>
#include <deque>
#include <string>
#include <algorithm>
#include <fstream>

#define Max 52
#define Color 4

using namespace std;

ifstream filein;
ofstream fileout;

class GraphNode{
	public:
		char name;
		int self_color;
		int yet; //paint or unpaint?
		deque<char> adj;
		
		GraphNode(char name_){
			name=name_;
			yet=0; //paint=1,unpaint=0
		}
		void table(){
			cout<<"Node: "<<name<<"  Color: "<<self_color<<"   My neighber: ";
			fileout<<"Node: "<<name<<"  Color: "<<self_color<<"   My neighber: ";
			for(int i = 0; i<adj.size(); i++){
				cout<<adj[i];
				fileout<<adj[i];
				cout<<" ";
				fileout<<" ";
			}
			cout<<endl;
			fileout<<endl;
		}
		
};

bool cmp(GraphNode* a,GraphNode* b){       //set the condition of sorting
	return a->adj.size()>b->adj.size();
}

int main(){
	char ch;
	char* filename1;
	char* filename2;
	filename1 = new char[100];
	filename2 = new char[100];
	int numbers;
	int count = 0;
	string INPUT;
	
	deque<GraphNode*> NodeList;
	
	cout<<"請輸入讀取檔名(包含附檔名)"<<endl; 
	cin >> filename1;
	cout<<"請輸入存取檔名(包含附檔名)"<<endl; 
	cin >> filename2; 
	filein.open(filename1,ios::in);
	
	if(filein){
		while(filein.get(ch)){
//			if((int)ch >= 48 && (int)ch <= 57){
//				numbers = ch-48;
//			}
			if((int)ch >= 65 && (int)ch <= 90){
				INPUT.push_back(ch);
			}
			else if((int)ch >= 97 && (int)ch <= 122){
				INPUT.push_back(ch);
			}
		}
	}
	filein.close();
	
	for(int i=0;i<Max;i++){
		if(i<26){
			NodeList.push_back(new GraphNode((char)(i+65)));
		}
		else{
			NodeList.push_back(new GraphNode((char)(i+71)));
		}
	}
	
	while(INPUT.size()-count!=0){
		if((int)INPUT[count]-65>=0 && (int)INPUT[count]-65<=26)
			NodeList[((int)INPUT[count]-65)]->adj.push_back(INPUT[count+1]);
		if((int)INPUT[count+1]-65>=0 && (int)INPUT[count+1]-65<=26)
			NodeList[((int)INPUT[count+1]-65)]->adj.push_back(INPUT[count]);
		if((int)INPUT[count]-97>=0 && (int)INPUT[count]-97<=26)
			NodeList[((int)INPUT[count]-71)]->adj.push_back(INPUT[count+1]);
		if((int)INPUT[count+1]-97>=0 && (int)INPUT[count+1]-97<=26)
			NodeList[((int)INPUT[count+1]-71)]->adj.push_back(INPUT[count]);
		count+=2;
	}
	
	int NNNN=0;    //Nonzero_Neighbor_Node_Number
	
	for(int i=0;i<NodeList.size();i++){
		if(NodeList[i]->adj.size()!=0){
			NNNN++;
		}
	}
	
	sort(NodeList.begin(),NodeList.end(),cmp); //sort Node by their dgree;
	
	int palette[Color]={1,2,3,4};
	deque<char> painted_country;
	
	for(int index = 0;index<Color;index++){
		for(int i = 0;i<NNNN;i++){
			int paintORnot=0; 			//0 = can paint,   !0 = can't paint
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
	
	bool wrong = 0;
	for(int i=0;i<NNNN;i++){
		if(NodeList[i]->yet==0){
			wrong=1;
		}
	}
	
	fileout.open(filename2,ios::out);
	
	if(wrong){
		cout<<"學號: 408411477       姓名: 辛介宇"<<endl;
		cout<<"四色無法達成目的"<<endl;
		fileout<<"學號: 408411477       姓名: 辛介宇"<<endl;
		fileout<<"四色無法達成目的"<<endl;
	}
	else{
		cout<<"學號: 408411477       姓名: 辛介宇"<<endl; 
		fileout<<"學號: 408411477       姓名: 辛介宇"<<endl;
		for(int i=0;i<NodeList.size();i++){
			if(NodeList[i]->adj.size()!=0){
				NodeList[i]->table();
			}
		}
	}	
	
	fileout.close();
//	cout<<numbers<<endl;
//	cout<<INPUT<<endl;
//	cout<<INPUT.size()<<endl;

	return 0;
}
