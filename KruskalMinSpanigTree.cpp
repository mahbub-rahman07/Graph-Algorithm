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
typedef pair<long long, int> PII;

#define For0(i,n) for(int i=0;i<(int)n;i++)
#define For1(i,n) for(int i=1;i<=(int)n;i++)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

int Arr[100009];
pair<ll, pair<int, int> >Node[100009];

int parent(int i)
{
	if(Arr[i] == i) return i;
	Arr[i] = parent(Arr[i]);
	return Arr[i];
}
void Union(int a,int b)
{
	int root_a = parent(a);
	int root_b = parent(b);
	Arr[root_a] = Arr[root_b];
}
bool find(int a,int b)
{
	if(parent(a) == parent(b))
		return 1;
	return 0;
}

ll mst(int edges)
{
	int x,y;
	ll cost,mincost = 0;
	for(int i = 0; i < edges ; i++){
		x = Node[i].second.first;
		y = Node[i].second.second;
		cost = Node[i].first;
		if(find(x,y)==0){
			mincost += cost;
			Union(x, y);
		}
	}
	return mincost;
}

int main() 
{
	int n,e;
	cin >> n >> e;
	for(int i = 0; i< 10009; i++){
		Arr[i] = i;
	}
	For0(i,e){
		int a,b,w;
		cin >> a >> b >> w;
		Node[i] = make_pair(w, make_pair(a, b));
	}
	
	sort(Node,Node + e);
	ll mincost = mst(e);
	cout <<mincost<< endl;
	
	return 0;
}