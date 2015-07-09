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
int main()
{
	int m;int n;
	cin>>m>>n;

	int **table =(int**)malloc(sizeof(int*)*m);
	for(int i =0;i<m;i++)
		table[i] = (int*)malloc(sizeof(int)*n);

	int **sum =(int**)malloc(sizeof(int*)*m);
	for(int i =0;i<m;i++)
		sum[i] = (int*)malloc(sizeof(int)*n);
	for(int i =0;i<m;i++)
	{
		for(int j =0;j<n;j++)
		{
			int y =0;
			cin>>y;
			table[i][j] = y;
		//	cout<<y<<" ";
		}
		//cout<<endl;
	}
	for(int i =0;i<n;i++)
		sum[m-1][i] = table[m-1][i];//cout<<"hi"<<endl;
	for(int i = m-2;i>=0;i--)
	{
		for(int j = 0;j<n;j++)
		{
			int ans = INF;
			if(j-1>=0)
				ans = min(ans,sum[i+1][j-1]);
			if(j+1<n)
				ans = min(ans,sum[i+1][j+1]);
			ans = min(ans,sum[i+1][j]);
			sum[i][j] = table[i][j] + ans;
		}
	}
	int ans =INF;
	for(int i =0;i<n;i++)
		ans= min(ans,sum[0][i]);
	cout<<ans<<endl;
	return 0;
}