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
#define MOD 5000000
void do_DP(vector<int>arr,int k)
{
	int n = arr.size();
	pair<ll,ll> table[n+1][k+1];
	for(int i =0;i<=n;i++)
	{
		for(int j =0;j<=k;j++)
		{
		table[i][j].first =0;
		table[i][j].second =0;
		}
	}
	for(int i =0;i<=n;i++)
	{
		table[i][1].second = i;
		table[i][1].first =1;
	}
	for(int i =1;i<=n;i++)
	{
		for(int j = 2;j<=k;j++)
		{
			if(i>1)
			{
				if(arr[i-1] !=arr[i-2])
				{
					table[i][j].first = (table[i-1][j-1].second % MOD);
				}
				if(arr[i-2] == arr[i-1])
				{
					table[i][j].first = (table[i-1][j].first %MOD);
				}
				table[i][j].second = (table[i][j].first +table[i-1][j].second)%MOD;
			}
			else 
			table[i][j].second = (table[i-1][j-1].second%MOD +table[i-1][j].second%MOD)%MOD;
		}
	}/*
	for(int i =0;i<=n;i++)
	{
		for(int j =0;j<=k;j++)
		{
		cout<<table[i][j].second<<" ";
		}
		cout<<endl;
	}*/
	cout<<table[n][k].second<<endl;
}
int main()
{
	int m,n;
	cin>>m>>n;
	vector<int>arr(m);
	for(int i =0;i<m;i++)
	{
		cin>>arr[i];
	}
	//sort(arr.begin(),arr.end());
	do_DP(arr,n);
}