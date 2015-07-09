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
ll maxl(ll a,ll b)
{
	if(a>b)
	return a;
	else return b;
}
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		int nodes;
		cin>>nodes;
		vector<ll>arr(nodes);
		for(int i =0;i<nodes;i++)
		arr[i] = 0;
		ll ans =0;
		map<pair<int,int>,bool >mymap;
		for(int i =1;i<nodes;i++)
		{
			int x,y;
			ll z;
			cin>>x>>y>>z;
			//cout<<x<<y<<z<<endl;;
			arr[x-1] = maxl(arr[x-1],z);
			arr[y-1] = maxl(arr[y-1],z);
			mymap[MP(x-1,y-1)] = true; 
			ans+=z;
		}
		
		for(int i =0;i<nodes;i++)
		{
			for(int j =i+1;j<nodes;j++)
			{
				if(mymap.find(MP(i,j)) !=mymap.end() || mymap.find(MP(j,i))!=mymap.end());
				else
				{
				ll temp =  maxl(arr[i],arr[j]);
				ans +=(temp+1);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}