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
#define INF 1<<30
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
int vertex_cover(vector< vector<int> >graph,int root)
{
	if(root == INF)
		return 0;
	if(graph[root.size()] == 0)
		return 0;
	int inc =1;
	int exc = 0;
	for(int i =0 ; i< graph[root].size() ;i++)
	{
		inc += vertex_cover(graph,graph[root][i]);
	}
	for(int i =0 ; i< graph[root].size() ;i++)
	{
		int y = graph[root][i];
	}
}
int main()
{
	int n =0;
	cin>>n;
	vector< vector<int> >graph(n);
	int root = INF;
	for(int i =0 ;i < n ; i++)
	{
		int x, y;
		cin>>x,y;
		graph[x-1].PB(y-1);
		root = min(root,x-1);
	}
	cout<<vertex_cover(graph,root)<<endl;
	return 0;
}