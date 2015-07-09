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
int LCS(vector<int>arr,vector<int>brr)
{
	int m = arr.size()+1;
	int n = brr.size()+1;
	int table[m][n];
	memset(table,0,sizeof(table));
	for(int i =1;i<m;i++)
	{
		for(int j =1;j<n;j++)
		{
			if(arr[i-1] == brr[j-1])
			{
				table[i][j] = table[i-1][j-1]+1;
			}
			else
				table[i][j] = max(table[i-1][j],table[i][j-1]);
		}
	}
	return table[m-1][n-1];
}
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		vector<int>source;
		int y =0;
		cin>>y;
		while(y != 0)
		{
			source.PB(y);
			cin>>y;
		}
		int r = 0;
		cin>>r;
		int ans =0;
		while(r != 0)
		{
			vector<int>brr;
			while(r!=0)
			{
				brr.PB(r);
				cin>>r;
			}
			ans = max(ans,LCS(source,brr));
			cin>>r;
		}
		cout<<ans<<endl;
	}
	return 0;
}