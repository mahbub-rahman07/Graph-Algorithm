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
int dist[1009][1009];
int weight[1009][1009];
void floyd_warshal(int n)
{
	for(int i = 1;i <=n; i++){
		for(int j = 1; j <= n; j++){
			dist[i][j] = i==j ? 0 : weight[i][j];
		}
	}
	for(int k = 1; k<=n; k++){
		for(int i = 1;i <=n; i++){
			for(int j = 1; j <= n; j++){
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	
}
int main() 
{
	
	int n,e;
	cin >> n >> e;
	for(int i = 1; i<= n; i++){
		for(int j = 1; j<=n; j++){
			weight[i][j] = 1e9;
		}
	}
	For1(i,e){
		int a,b,w;
		cin >> a >> b >> w;
		weight[a][b] = w;
	}
	
	floyd_warshal(n);
	for(int i = 2; i<= n; i++){
		cout << dist[1][i]<<" ";
	}
	cout << endl;
	
	return 0;
}