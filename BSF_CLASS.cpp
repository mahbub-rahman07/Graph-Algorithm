#include <iostream>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <cstdio>
#include <list>
using namespace std;

class Graph{
	int Node;
	list<int> *edges;
public:
	Graph(int Node){       // constractor
		this->Node = Node;
		edges = new list<int>[Node];
	}
	void addEdg(int v,int w);
	void BSF(int s);

};

void Graph::addEdg(int v, int w)
{
	edges[v].push_back(w);
}
void Graph::BSF(int s)
{
	bool *visited = new bool[Node];
	
	for(int i=0;i<Node;i++)
		visited[i] = false;
	list<int>quee;
	
	visited[s] = true; // source Node is visited
	quee.push_back(s); // putting source Node (s) in Quee
	
	list<int>::iterator it; // for iteration 
	
	while( !quee.empty())
	{
		s = quee.front();
		cout<<s<<" "; // visited Node as result
		quee.pop_front(); // removeing visited Node
		
		for(it = edges[s].begin(); it != edges[s].end(); it++)
		{
			if(!visited[*it]){
				visited[*it] = true;
				quee.push_back(*it);
			}
		}
		
	}
	
}


int main() {
	
	Graph g(4);
	g.addEdg(0, 1);
	g.addEdg(0, 2);
	g.addEdg(1, 2);
	g.addEdg(2, 0);
	g.addEdg(2, 3);
	g.addEdg(3, 3);
	
	g.BSF(2);
}