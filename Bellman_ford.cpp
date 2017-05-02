#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
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
void bellman_ford(int s,int n)
{
	dist[s] = 0;
	for(int i = 1; i < n ; i++){
		for(int u = 1; u <= n; u++){
			for(int j = 0; j < edge[u].size(); j++){
				int v = edge[u][j].v;
				int w = edge[u][j].weight;
				dist[v] = min(dist[v],w+dist[u]);
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
	
	bellman_ford(1, n);
	for(int i = 2; i<= n; i++){
		cout << dist[i]<<" ";
	}
	cout << endl;
	return 0;
}