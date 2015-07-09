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
vector<ll>store;
ll solve(vector<int>arr,int age,int s,int e)
{
	if(arr.size() == 0)
		return 0;
	if(arr.size() == 1)
		return age*arr[0];
	else
	{
		vector<int>temp = arr;
		temp.erase(temp.begin());
		ll u = arr[0]*age;
		if(store[s] == -1)
		{
			ll v = solve(temp,age+1,s+1,e);
			store[s] = v;
		}
			u += store[s];
		temp =arr;
		temp.erase(temp.begin()+temp.size()-1);
		ll x = arr[arr.size()-1]*age;
		if(store[e] == -1)
		{
			ll v = solve(temp,age+1,s,e-1);
			store[e] = v;
		}
			x += store[e];
		return max(u,x);
	}
}
int main()
{
	int n =0;
	cin>>n;
	vector<int>arr;
	while(n--)
	{
		int u =0;
		cin>>u;
		arr.PB(u);
		store.PB(-1);
	}
	cout<<solve(arr,1,0,arr.size()-1)<<endl;
	return 0;
}