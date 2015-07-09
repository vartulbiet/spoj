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
vector<vector<ii> >graph;
void init(int n)
{
	vector< ii >a;
	for(int i =0;i<n;i++)
		graph.PB(a);
}
int djkstra(int source,int sink)
{
	priority_queue< ii >pq;
	pq.push(MP(0,source));
	while(!pq.empty())
	{
		pair<int,int>a = pq.top();
		pq.pop();
		if(a.second == sink)
		{
			return -a.first;
		}
		else
		{
			for(int i =0 ;i<graph[a.second].size();i++)
			{
				pq.push(MP(-(graph[a.second][i].second+ abs(a.first)),graph[a.second][i].first));
			}
		}
	}
	return INF;
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
				graph[i].PB(MP(x-1,y));
				graph[x-1].PB(MP(i,y));
			}
		}
		int r =0;
		cin>>r;

		while(r--)
		{
			string x,y;
			cin>>x>>y;
			cout<<djkstra(mymap[x],mymap[y])<<endl;
		}
		graph.erase(graph.begin(),graph.end());
	}
	return 0;
}