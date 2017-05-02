#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <cstdio>

using namespace std;
#define MAX 10000
vector<int>edges[MAX];
vector<int>cost[MAX];
	
vector<int> in[MAX];
vector<int>out[MAX];

int main() {
	
	int Node,Edge;
	int k=0,l=0;
	cout<<"Enter how many Nodes & Edges : "<<endl;
	cin>>Node>>Edge;
	
	for(int i=1;i<=Edge;i++){
		int x,y;
		cin>>x>>y;
	
		/**
			if undirected
			
			edges[x].push_back(y);
			edges[y].push_back(x);
		*/
		
		edges[x].push_back(y);
		
		in[y].push_back(k++);
		out[x].push_back(l++);
		
		int c;
		cout<<"enter cost : "<<endl;
		cin>>c;
		cost[x].push_back(c);
		
		
		
	}
//	int n;
//	cout<<"Enter Node : "<<endl;
//	cin>>n;
//	
//	cout<<"Node "<<n<<" is connented with : ";
//	
//	for(int i=0;i<edges[n].size();i++){
//		cout<<edges[n][i]<<" & cost is "<<cost[n][i]<<endl;
//	}
//	cout<<endl;
	
	int n;
	cin>>n;
	
	cout<<"indegree at Node "<<n<<" : "<<in[n].size()<<endl;
	cout<<"outdegree at Node "<<n<<" : "<<out[n].size()<<endl;
	
	return 0;
}