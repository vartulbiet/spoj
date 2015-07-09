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
int arr[4] = {-1,1,0,0};
int brr[4] = {0,0,-1,1};
string BFS(int a,int b,int x,int y,int p,int r,int m,int n)
{
	int mouse[m][n];
	int cat[m][n];
	for(int i =0;i<m;i++)
		for(int j =0;j<n;j++)
		{
			mouse[i][j] = INF;
			cat[i][j] = INF;
		}
	queue< ii >q;
	q.push(MP(a,b));
	mouse[a][b] = 0;
	while(!q.empty())
	{
		ii x = q.front();
		q.pop();
		for(int i =0;i<4;i++)
		{
			if(x.first+arr[i]>=0 && x.first+arr[i]<m && x.second+brr[i]>=0 && x.second+brr[i]<m && mouse[x.first+arr[i]][x.second+brr[i]]>mouse[x.first][x.second]+1)
			{
				q.push(MP(x.first+arr[i],x.second+brr[i]));
				mouse[x.first+arr[i]][x.second+brr[i]]= mouse[x.first][x.second]+1;
			}
		}
	}
	q.push(MP(x,y));
	cat[x][y] = 0;
	while(!q.empty())
	{
		ii x = q.front();
		q.pop();
		for(int i =0;i<4;i++)
		{
			if(x.first+arr[i]>=0 && x.first+arr[i]<m && x.second+brr[i]>=0 && x.second+brr[i]<m && cat[x.first+arr[i]][x.second+brr[i]]>cat[x.first][x.second]+1)
			{
				q.push(MP(x.first+arr[i],x.second+brr[i]));
				cat[x.first+arr[i]][x.second+brr[i]]= cat[x.first][x.second]+1;
			}
		}
	}
	q.push(MP(p,r));
	cat[p][r] = 0;
	while(!q.empty())
	{
		ii x = q.front();
		q.pop();
		for(int i =0;i<4;i++)
		{
			if(x.first+arr[i]>=0 && x.first+arr[i]<m && x.second+brr[i]>=0 && x.second+brr[i]<m && cat[x.first+arr[i]][x.second+brr[i]]>cat[x.first][x.second]+1)
			{
				q.push(MP(x.first+arr[i],x.second+brr[i]));
				cat[x.first+arr[i]][x.second+brr[i]]= cat[x.first][x.second]+1;
			}
		}
	}
	for(int i =0;i<m;i++)
	{
		if(cat[i][0]>mouse[i][0])
			return "YES";
		if(cat[i][n-1]>mouse[i][n-1])
			return "YES";
	}
	for(int i =0;i<n;i++)
	{
		if(cat[0][i]>mouse[0][i])
			return "YES";
		if(cat[m-1][i]>mouse[m-1][i])
			return "YES";
	}
	return "NO";
}
int main()
{
	int m,n;
	cin>>m>>n;
	int k =0;
	cin>>k;
	while(k--)
	{
		int a,b,p,q,x,y;
		cin>>a>>b>>p>>q>>x>>y;
		cout<<BFS(a-1,b-1,p-1,q-1,x-1,y-1,m,n)<<endl;
	}
	return 0;
}