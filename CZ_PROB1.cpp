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
ull table[5][10000];
ull solve(int n,int k)
{
	for(int i =0;i<5;i++)
	{
		for(int j =0;j<10000;j++)
		table[i][j] =0;
	}
	
	for(int i=0;i<5;i++)
	table[i][0] =1;
	for(int i =1;i<=k;i++)
	{
		for(int j =1;j<=n;j++)
		{
			table[i][j]  =table[i-1][j];
			if(i<=j && table[i][j-i]>0)
			{
				table[i][j] +=(table[i][j-i]);
			}
			//cout<<table[i][j]<<" ";
		}
		//cout<<endl;
	}
	return table[k][n];
}
bool isPrime(int u)
{
	if(u==1)
	return false;
	if(u==2 ||u==3 ||u==5)
	return true;
	if(u%2==0 ||u%3==0 ||u%5==0)
	return false;
	int y = sqrt(u);
	for(int i =2;i<y+1;i++)
	{
		if(u%i ==0)
		return false;
	}
	return true;
}
int main()
{
	vector<int>arr;
	vector<bool>visited(10005);
	fill(visited.begin(),visited.end(),false);
	for(int i =1;i<100;i++)
	{
		for(int j =1;j<100;j++)
		{
			int x = i*i+j*j;
			if(x<10000 && !visited[x] && isPrime(x) ){
			arr.PB(x);visited[x] = true;//cout<<x<<" ";
			}
		}
	}
	sort(arr.begin(),arr.end());
	int n =0;
	cin>>n;
	while(n--)
	{
		int x,y;
		cin>>x>>y;
		int u = arr[x-1];
		//cout<<u<<endl;
		cout<<solve(u,y)<<endl;
	}
	return 0;
}