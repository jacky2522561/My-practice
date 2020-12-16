#include <iostream>
#include <stdio.h>
//double-ended-queue
#include <deque>

using namespace std;

class GraphNode{
	private:
		char name;
		//color

		//color
	public:
		deque<char> adj;
		int index;
		GraphNode(char name_){
			name=name_;
			index=0;
			//color
			
			//color
		}
		
		showname(){
			cout<<name<<endl;
		}
		
		/*void dump(){
			cout<<"Vertex:"<<name<<", I'm adjacent to:";
			for(int i = 0; i<adj.size(); i++){
				cout<<adj[i];
				cout<<" ";
			}
			cout<<endl;
		} */
};


int main(){
	deque<GraphNode*> NodeList;
	int NodeCounter = 0;
	char Node1,Node2;
	cout<<"(!!NOTICE!! If you want to stop input, Plz input '(z,z)')"<<endl;
	cout<<"Plz enter the pairs of country, ex:(A,B) (B,C) etc..: "<<endl;
	do{
		scanf("(%c,%c)",&Node1,&Node2);
		NodeList.push_back(new GraphNode(Node1));
		NodeCounter++;
		NodeList.push_back(new GraphNode(Node2));
		NodeCounter++;
		cout<<Node1<<Node2<<endl;
		fflush(stdin);                  //清除上一個scanf快取 
	}while(Node1 != 'z' && Node2 != 'z');
	
	delete NodeList[NodeList.size()-1];
	delete NodeList[NodeList.size()-2];
	
	
	for(int i = 0;i<NodeList.size();i++){
		NodeList[i]->showname();
	}
	
	
	return 0;
}
