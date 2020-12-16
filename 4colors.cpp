#include <iostream>
#include <stdio.h>
//double-ended-queue
#include <deque>

#define Max 26
#define Color 4

using namespace std;

class GraphNode{
	private:
		char name;
	public:
		deque<int> color; //color
		int self_color;
		
		//for(int i)
		int notyet; //paint or unpaint?
		deque<char> adj;
		GraphNode(char name_){
			name=name_;
			notyet=1; //paint=0,unpaint=1
		}
		
		/*void paint(){
			self_color=color[i];
			color.pop_front();
		}*/
		
		void table(){
			cout<<"Node: "<<name<<"   My neighber: ";
			for(int i = 0; i<adj.size(); i++){
				cout<<adj[i];
				cout<<" ";
			}
			cout<<endl;
		}
		
};


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
		cout<<((int)Node1-65)<<" "<<((int)Node2-65)<<endl;
		if(int(Node1) != 122 && int(Node2) != 122){
			NodeList[((int)Node1-65)]->adj.push_back(Node2); 
			NodeList[((int)Node2-65)]->adj.push_back(Node1); 
		}
		cout<<Node1<<Node2<<endl;
		fflush(stdin);                  //清除上一個scanf快取 
	}while(Node1 != 'z' && Node2 != 'z');
	
	
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
	
	int temp = ^NodeList[i]->yet;
	for(int i=0;i<NodeList.size();i++){
		NodeList[i]->table();
	}
	
	return 0;
}
