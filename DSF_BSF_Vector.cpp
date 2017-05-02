#include <iostream>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <cstdio>
#include <list>
using namespace std;
#define MAX 10000
int Node;
vector<int>Edges[MAX];

void addNode_Directed(int x,int y)
{
	Edges[x].push_back(y);
}
void addNode_Undirected(int x,int y)
{
	Edges[x].push_back(y);
	Edges[y].push_back(x);
}

void BSF(int s)
{
	bool *visited = new bool[Node];
	
	for(int i=0;i<Node;i++) visited[i] = false;
	
	list<int>quee;
	vector<int>::iterator it;
	
	visited[s] = true;
	quee.push_back(s);
	
	while(!quee.empty())
	{
		s = quee.front();
		cout<<s<<" ";
		quee.pop_front();
		
		for(it = Edges[s].begin() ; it!=Edges[s].end(); ++it){
			if(!visited[*it]){
				visited[*it] = true;
				quee.push_back(*it);
			}
		}
	}
	
	
}
void DFS_Sol(int s,bool visited[])
{
	visited[s] = true;
	cout<<s<<" ";
	
	vector<int>::iterator it;
	
	for(it = Edges[s].begin() ; it != Edges[s].end();++it){
		if(!visited[*it]){
			DFS_Sol(*it,visited);
		}
	}
	
}
void DSF(int s)
{
	bool *visited = new bool[Node];
	
	for(int i=0;i<Node;i++) visited[i] = false;
	
	DFS_Sol(s,visited);
	
}

int main() {

	addNode_Directed(0, 1);
	addNode_Directed(0, 2);
	addNode_Directed(1, 2);
	addNode_Directed(2, 0);
	addNode_Directed(2, 3);
	addNode_Directed(3, 3);
	
	BSF(2);
	cout<<endl;
	DSF(2);
}