#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>
#include <list>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define For0(i,n) for(int i=0;i<(int)n;i++)
#define For1(i,n) for(int i=1;i<=(int)n;i++)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
struct node{
	int u;
	int v;
	int weight;
	node(int _u,int _v,int _w){
		u = _u;
		v = _v;
		weight = _w;
	}
};
vector<int>dist(10009,1e9);
vector<node>edge[10009];

void dijkstra(int s)
{
	dist[s] = 0;
	priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
	
	
	pq.push(make_pair(dist[s], s));
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		for(int i = 0; i < edge[u].size() ; i++){
			int v = edge[u][i].v;
			int w = edge[u][i].weight;
			if(w+dist[u] < dist[v]){
				dist[v] = w+dist[u];
				pq.push(make_pair(dist[v], v));
			}
		}
	}
}

int main() 
{
	int n,e;
	cin >> n >> e;
	
	For1(i,e){
		int a,b,w;
		cin >> a >> b >> w;
		edge[a].push_back(node(a,b,w));
	}
	
	dijkstra(1);
	for(int i = 2; i<= n; i++){
		cout << dist[i]<<" ";
	}
	cout << endl;
	
	return 0;
}