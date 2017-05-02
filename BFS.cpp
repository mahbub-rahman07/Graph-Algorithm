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
vector<int>v[10009];
bool visit[10009];
int level[10009];
int levelNode[10009];
void bsf(int s)
{
	queue<int>q;
	q.push(s);
	level[s] = 1;
	levelNode[ level[s] ]++;
	visit[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0; i < v[u].size() ; i++){
			if(visit[v[u][i]] == 0){
				level[ v[u][i] ] = level[u]+1;
				levelNode[ level[ v[u][i] ] ]++;
				q.push(v[u][i]);
				visit[ v[u][i] ] = 1;
			}
		}
	}
	
}
int main() 
{
	int n;
	cin >> n;
	
	for(int i = 1; i <n; i++){
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	for(int i = 1; i <= n; i++){
		if(visit[i] == 0){
			bsf(i);
		}
	}
	int p;
	cin >> p;
	cout << levelNode[p]<<endl; 
//	sort(level,level+n);
//	for(int i = 1; i<= n; i++){
//		cout <<i  <<" level "<<level[i]<<endl;
//	}
	
	return 0;
}