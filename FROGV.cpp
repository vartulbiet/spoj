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
vector<int>arr

int main()
{
	ll n,k,p;
	cin>>n>>k>>p;
	vector<int>arr;
	map<int,int>mymap;
	for(ll i =0;i<n;i++)
	{
		ll h =0;
		cin>>h;
		arr.push_back(h);
		mymap[h] = i;
	}
	int prev = mymap.begin()->first;
	for(std::map<int,int>::iterator it =mymap.begin();it!=mymap.end();it++)
	{
		int h = it->first;
		if(h-prev<=k)
		{
			mymap[h] = mymap[prev];
			prev = h;
		}
	}
	for(int i =0;i<p;i++)
	{
		int a,b;
		cin>>a>>b;
		if(mymap[arr[a-1]] == mymap[arr[b-1]])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}