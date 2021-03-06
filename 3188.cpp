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
vector<int>arr;
int find(int x)
{
	if(arr[x] == x)
	return x;
	else return arr[x] = find(arr[x]);
}
void merge(int x,int y)
{
	arr[find(x)] = find(y);
}
void KRUSKAL(	priority_queue<pair<ll,pair<int,int> > >pq)
{
	ll ans =0;
	while(!pq.empty())
	{
		pair<ll,pair<int,int> > p = pq.top();
		pq.pop();
		if(find(p.second.first) != find(p.second.second))
		{
			merge(p.second.first,p.second.second);
			ans +=(-p.first);
		}
	}
	cout<<ans<<endl;
}
int main()
{
	int m,n;
	cin>>m>>n;
	priority_queue<pair<ll,pair<int,int> > >pq;
	for(int i =0;i<m;i++)
	arr.PB(i);
	for(int i =0;i<n;i++)
	{
		int x,y; ll z;
		cin>>x>>y>>z;
		pq.push(MP(-z,MP(x,y)));
	}
	KRUSKAL(pq);
	return 0;
}