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
vector<vi>graph;
void init(int n)
{
	vi a(n);
	for(int i =0;i<n;i++)
		graph.PB(a);
	for(int i =0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			graph[i][j] = INF;
		}
	}
}
void floyd_warshall(int n)
{
	for(int i = 0;i<n;i++)
	{
		for(int j =0;j<n;j++)
		{
			for(int k =0;k<n;k++)
			{
				graph[j][k] = min(graph[j][k],graph[j][i] + graph[i][k]);
			}
		}
	}
}

int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		int cities = 0;
		cin>>cities;
		map<string ,int>mymap;
		init(cities);
		for(int i =0;i<cities;i++)
		{
			string s;
			cin>>s;
			mymap[s] = i;
			int v = 0;
			cin>>v;
			while(v--)
			{
				int x,y;
				cin>>x>>y;
				graph[i][x-1]  = min(graph[i][x-1],y);
			}
		}
		floyd_warshall(cities);
		int r =0;
		cin>>r;

		while(r--)
		{
			string x,y;
			cin>>x>>y;
			cout<<graph[mymap[x]][mymap[y]]<<endl;
		}
		graph.erase(graph.begin(),graph.end());
	}
	return 0;
}