#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>
#include <deque>
#include <assert.h>
#include <stack>
#include <list>
#include <set>
#include <map>

using namespace std;

/*******************************************************************\
|                       Md.Mahbubur Rahman                          |
|   	BANGLADESH UNIVERSITY OF BUSINESS & TECHNOLOGY(BUBT)	    |
|		 	    Deptartment of  CSE							        |
|    uva:mahbub07||devskil: mahbub07||codefoces:MAHBUBUR_RAHMAN     |
|                mail:mahbubabid8@gmail.com				            |
\*******************************************************************/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
typedef  vector<int> vi;
typedef  vector<ll> vll;
typedef  vector<string> vs;
typedef  set<int> si;
typedef  set<string> ss;
typedef  map<int,int> mii;
typedef  map<ll,ll> mll;
typedef  map<string,int> msi;
typedef  map<char,int> mci;
//----------------defines-----------------------
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define skip scanf("%*c");
#define ms(s, n) memset(s, n, sizeof(s))
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
#define For0(i,n) for(int i=0;i<(int)n;i++)
#define For1(i,n) for(int i=1;i<=(int)n;i++)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define Case(no) printf("Case %d: ",++no)
#define pb(b) push_back(b)
#define mp make_pair
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define sortArr(a,n) sort(a,a+n)
#define sortVec(a) sort(all(a))
#define endl '\n'
#define DIST(x1,y1, x2, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
//----------------functions-----------------------
ll multiplyfast(ll a, ll b, ll c){ if(b==0) return 0;ll x = multiplyfast(a , b/2, c)%c; if(!(b&1)){ return (x%c+x%c)%c;}else return ((a%c + (x+x)%c))%c; }
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=multiplyfast(res,a,mod)%mod;a=multiplyfast(res,a,mod)%mod;}return res;}
ll modInverse(ll a, ll m){return powmod(a,m-2,m);}
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
//----------------constants-----------------------
const int MOD = (int) 1e9 + 7;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
/*
1

4
2
1
8
1 2 1
1 3 1
2 1 1
2 4 1
3 1 1
3 4 1
4 2 1
4 3 1
*/
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

vector<node>edge[109];

int N,E,T;
int dijkstra(int s , vector<int> &dist)
{
	bool visit[109];
	ms(visit,0);
	int cont = 0;
	dist[s] = 0;
	//visit[s] = 1;
	priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
	
	
	pq.push(make_pair(dist[s], s));
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		if(visit[u] == 1) continue;
		visit[u] = 1;
		if(dist[u] <=T)cont++;
		
		for(int i = 0; i < edge[u].size() ; i++){
			int v = edge[u][i].v;
			int w = edge[u][i].weight;
			if(w+dist[u] < dist[v]){
				dist[v] = w+dist[u];
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	return cont;
}

int main() 
{
	int tc;
	//READ("in.txt");
	//WRITE("test.txt");
	
	cin >> tc;
	int ok = tc;
	while (tc) {
		if(ok > tc)cout << endl;
		
		for(int i = 0; i < 102; i++){
			//dist[i].clear();
			edge[i].clear();
		}

		cin >> N >> E >> T;
		int M;
		cin >> M;
		
		For1(i,M){
			int a,b,w;
			cin >> a >> b >> w;
			edge[b].push_back(node(b,a,w));
		}
		
		vector<int>dist(109,1e9);
		
		cout << dijkstra(E,dist)<< endl;
		tc--;
		
	}
	
	
	return 0;
}