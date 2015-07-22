#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <numeric>
#include <bitset>
#define REP(i, a, b) for ( int i = int(a); i <= int(b); i++ )
#define PB push_back
#define MP make_pair
#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define DFS_WHITE -1
#define DFS_BLACK 1
#define MAXN 1000
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define INF 1<<20
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;

long graph[111][111];
void init_graph(int n)
{
	for(int i =0 ; i< n ; i ++)
	{
		for(int j =0 ;j < n ;j++)
			graph[i][j] = INF;
		graph[i][i] = 0;
	}
}
void floyd_warshall(int n)
{
	for(int k = 0; k < n ; k++)
	{
		for(int i = 0; i < n ; i++)
		{
			for(int j = 0; j < n ; j++)
			{
				graph[i][j] = min(graph[i][j] , graph[i][k] + graph[k][j]);
			}
		}
	}
}
int main()
{
	int n;
	int e;
	int t;
	int c;
	cin>>n>>e>>t>>c;
	e--;
	init_graph(n);
	for(int i =0 ;i < c; i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		graph[x-1][y-1] = z;
	}

		for(int j =0 ;j < n ;j++)
			graph[j][j] = 0;
	floyd_warshall(n);
	int ans = 0;
	for(int i =0 ; i<n ; i++)
	{
		if(graph[i][e] <=t )
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}