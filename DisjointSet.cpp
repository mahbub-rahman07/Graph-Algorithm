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
int Arr[1009];
int size[1009];
int parent(int i)
{
	if(Arr[i] ==i ) return i;
	Arr[i] = parent(Arr[i]);
	return Arr[i];
}
void Union(int a,int b)
{
	int root_a = parent(a);
	int root_b = parent(b);
	Arr[root_a] = Arr[root_b];
}
bool find(int i,int j)
{
	return (parent(i) == parent(j));
}
void weight_union(int a,int b)
{
	int root_a = parent(a);
	int root_b = parent(b);
	
	if(size[root_a] < size[root_b]){
		Arr[root_a] = Arr[root_b];
		size[root_b] += size[root_a];
	}else{
		Arr[root_b] = Arr[root_a];
		size[root_a] += size[root_b];
	}
 }
int main() 
{
	int n,e;
	cin >> n >> e;
	
	// inisialize
	for(int i = 1; i <= n;i++){
		Arr[i] = i;
		size[i] = 1;
	}
	
	for(int i = 1; i <=e; i++){
		int x,y;
		cin >> x >> y;
		//Union(x,y);
		weight_union(x,y);
		vector<int> S(size,size+n);
		sort(S.begin(),S.end());
		for(int j = i; j <n;j++){
			cout << S[j] <<" ";
		}
		cout << endl;
		
	}
	
	return 0;
}