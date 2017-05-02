#include <iostream>
#include <vector>
#include <list>
#include <cstdio>
#include <cstring>
using namespace std;
class Graph{
	int Node;
	list<int>*edges;
public:
	Graph(int n){
		Node = n;
		edges = new list<int>[n];
	}
	void addEdge(int x,int y);
	void DFS();
	void DFS(int s);
	void DFS_sol(int s,bool *visited);
};

void Graph :: addEdge(int x,int y){
	edges[x].push_back(y);
}

void Graph::DFS_sol(int s, bool *visited)
{
	visited[s] =true;
	cout<<s<<" ";
	
	list<int>::iterator it;
	
	for( it=edges[s].begin(); it != edges[s].end();++it){
		if(!visited[*it]){
			DFS_sol(*it, visited);
			
		}
	}
	
}

void Graph::DFS(int s)
{
	bool *visited = new bool[Node];
	
	//memset(visited, false, sizeof(visited));
	for(int i=0;i<Node;i++) visited[i] = false;
	
	DFS_sol(s,visited);
}


void Graph::DFS()
{
	bool *visited = new bool[Node];
	
	//memset(visited, false, sizeof(visited));
	for(int i=0;i<Node;i++) visited[i] = false;
	
	for(int i=0;i<Node;i++){
		if(!visited[i])
			DFS_sol(i,visited);
	}
}


int main() {
	Graph g(4);
	
	g.addEdge(0,1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	
	g.DFS();
		
	return 0;
}