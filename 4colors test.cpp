#include <iostream>
#include <stdio.h>
//double-ended-queue
#include <deque>
#include <string>
#include <algorithm>

#define Max 26
#define Color 4

using namespace std;

class GraphNode{
	private:
		//string palette[Color]={"red","blue","yellow","green"};
	public:
		char name;
		//deque<string> color; //color
		//int NumsofNeighborNode;
		int self_color;
		int yet; //paint or unpaint?
		deque<char> adj;
		
		GraphNode(char name_){
			name=name_;
			yet=0; //paint=1,unpaint=0
			//NumsofNeighborNode=0;
		/*	for(int i=0;i<4;i++){
				color.push_back(palette[i]);
			}*/
		}
		
		void table(){
			cout<<"Node: "<<name<<"  Color: "<<self_color<<"   My neighber: ";
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

/*deque<string> color; //color

void repalette(){
	string palette[Color]={"red","blue","yellow","green"};
	for(int i=0;i<Color;i++){
		color.push_back(palette[i]);
	}
}*/

/*void dfs(int index){
	GraphNode* thisNode = NodeList[index];
	thisNode->self_color=thisNode->color[0];
	thisNode->color.pop_front();
	thisNode->yet=1;
	char nextNode;
	for(int i = 0; i<thisNode->adj.size();i++){
		nextNode=thisNode->adj[i];
		if(NodeList[(int)(nextNode)-65]->yet==0){
			dfs(nextNode);
		}
	}
}*/

int main(){
	deque<GraphNode*> NodeList;
	char Node1,Node2;
	//bool work;
	
	for(int i=0;i<Max;i++){
		NodeList.push_back(new GraphNode((char)(i+65)));
	}
	
	cout<<"(!!NOTICE!! If you want to stop input, Plz input '(z,z)')"<<endl;
	cout<<"Plz enter the pairs of country, ex:(A,B) (B,C) etc..: "<<endl;
	do{
		scanf("(%c,%c)",&Node1,&Node2);
		cout<<((int)Node1-65)<<" "<<((int)Node2-65)<<endl;
		if(int(Node1) != 122 && int(Node2) != 122){
			NodeList[((int)Node1-65)]->adj.push_back(Node2);
			NodeList[((int)Node2-65)]->adj.push_back(Node1);
		}
		cout<<Node1<<Node2<<endl;
		fflush(stdin);                  //清除上一個scanf快取 
	}while(Node1 != 'z' && Node2 != 'z');
	
	int NNNN=0;    //Nonzero_Neighbor_Node_Number
	
	for(int i=0;i<NodeList.size();i++){
		if(NodeList[i]->adj.size()!=0){
			NNNN++;
		}
	}
	
	sort(NodeList.begin(),NodeList.end(),cmp); //sort Node by their dgree;
	
	int color[Color]={0,1,2,3};
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
					NodeList[i]->self_color=color[index];
					painted_country.push_back(NodeList[i]->name);
					NodeList[i]->yet=1;
				}
			}
		}
		painted_country.clear();
	}
	
	/*for(int i = 0;i<NNNN;i++){
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
				NodeList[i]->self_color=color[index];
				painted_country.pop_back(NodeList[i]->name);
			}
		}
	}*/
	
	//for(int i=0;i<
	
	/*for(int i=0;i<NodeList.size();i++){                  
		if(NodeList[i]->adj.size()!=0){
		}
	}*/
	/*for(int i=0;i<sort_NodeList_by_Dgree.size();i++){
		
	}*/
	
	/*for(int i=0;i<NodeList.size();i++){                        //存每個Node的degree 
		if(NodeList[i]->adj.size()!=0){
			NodeList[i]->NumsofNeighborNode = NodeList[i]->adj.size();
		}
	}
	
	cout<<	NodeList[0]->NumsofNeighborNode<<endl;*/
	//cheacking
	/*for(int i=0;i<NodeList.size();i++){
		if(NodeList[i]->adj.size()>=Color)	work = 0;
		else	work = 1;
	}
	
	switch(work){
		case 0:
			cout<<"We can't paint all the countries by "<<Color<<" colors."<<endl;
			break;
		case 1: 
			
	}*/
	/*for(int i=0;i<NodeList.size();i++){
		int color_index=1;
		if(NodeList[i]->notyet){
			NodeList[i]->color=color_index++;
			for(int j=0;j<NodeList[i]->adj.size();j++){
				NodeList[i]->adj[j]=color_index++;
				NodeList[((int)(NodeList[i]->adj[j])-65)]->notyet=1; 
			}
			NodeList[i]->notyet=1; 
		}
		else{
			NodeList[i]->color;
			for(int j=0;j<NodeList[i]->adj.size();j++){
				NodeList[i]->adj[j]=color_index++;
				NodeList[((int)(NodeList[i]->adj[j])-65)]->notyet=1; 
			}
		}
	}*/
	/*for(int i=0;i<NodeList.size();i++){
		if(NodeList[i]->adj.size()!=0){
			repalette();
			
			NodeList[i]->self_color = color[0];
			NodeList[i]->yet = 1;
			color.pop_front();
			for(int j=0;j<NodeList[i]->adj.size();j++){
				NodeList[((int)(NodeList[i]->adj[j])-65)]->self_color = color[0];
				NodeList[((int)(NodeList[i]->adj[j])-65)]->yet = 1;
				color.pop_front();
			}
		}
	}*/
	bool right;
	for(int i=0;i<NNNN;i++){
		if(NodeList[i]->yet==0){
			right=0;
		}
		else right=1;
	}
	
	for(int i=0;i<NodeList.size();i++){
		if(NodeList[i]->adj.size()!=0){
			NodeList[i]->table();
		}
	}
	
	if(right){
		cout<<"We can solve the problem by "<<Color<<" colors!!!"<<endl;
		cout<<"Congratulations!!!"<<endl;
	}
	else{
		cout<<"We can't solve the problem by "<<Color<<" colors!!!"<<endl;
		cout<<"Fail!! Try to add up more colors"<<endl;
	}
	cout<<NodeList.size()<<endl;
	cout<<NNNN<<endl;
	NodeList[0]->self_color=5;
	cout<<NodeList[0]->self_color<<endl;
	cout<<NodeList[0]->yet<<endl;
	cout<<NodeList[0]->name<<endl;
	return 0;
	
}
