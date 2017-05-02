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
int grid[15][15];
bool visit[15][15];
int row;
int col;
void floodfill(int i,int j)
{
	//cout <<i<<" "<<j<<endl;
	if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0){
		return ;
	}
	if(grid[i][j] == 1 && visit[i][j] == 0){
		visit[i][j] = 1;
		floodfill(i+1,j);
		floodfill(i-1,j);
		floodfill(i,j+1);
		floodfill(i,j-1);
	}
}
int main() 
{
	cin >> row >> col;
	
	for(int i  = 0; i<row; i++){
		for(int j = 0;j<col;j++){
			cin >> grid[i][j];
			
		}
	}
	//cout << visit[1][1]<<endl;
	floodfill(0, 0);
	
	if(visit[row-1][col-1] == 1){
		cout << "Yes"<<endl;
	}else{
		cout <<"No"<<endl;
	}
	
	return 0;
}