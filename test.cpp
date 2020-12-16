#include <iostream>
#include <stdio.h>
//double-ended-queue
#include <deque>

using namespace std;

class graph_node{
	public:
		int id;
		deque<int>adjacency;
		int discovered;
		
		graph_node(int _id){
			id=_id;
			discovered = 0;
		} 
		
		void dump(){
			cout<<"Vertex:"<<id<<", I'm adjacent to:";
			for(int i = 0; i<adjacency.size(); i++){
				cout<<adjacency[i];
			}
			cout<<endl;
		}
}; 

deque<graph_node*> Nodelist;

//dfs
void DFS(int vertex){
	graph_node *curr=Nodelist[vertex];
	curr->discovered=1;
	cout<<vertex;
	int next;
	for(int i=0;i<curr->adjacency.size();i++){
		next=curr->adjacency[i];
		if(Nodelist[next]->discovered==0){
			DFS(next);
		}
	}
}
int main(){
	int node_count,edge_count;
	cout<<"Enter no of vertices:";
	cin>>node_count;
	cout<<"Enter no of edges:";
	cin>>edge_count;
	
	for(int i = 0;i<node_count;i++){
		Nodelist.push_back(new graph_node(i));
	}
	
	cout<<"Enter "<<edge_count<<" pairs of verteices: "<<endl;
	for(int j = 0;j<edge_count;j++){
		int node1,node2;
		cin>>node1>>node2;
		Nodelist[node1]->adjacency.push_back(node2);
		Nodelist[node2]->adjacency.push_back(node1);
	}
	
	for(int i = 0;i< Nodelist.size();i++){
		Nodelist[i]->dump();
	}
	
	cout<<"DFS travel: ";
	DFS(0);
	cout<<endl;
	return 0;
}



