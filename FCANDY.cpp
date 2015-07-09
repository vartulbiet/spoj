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
int subset_sum(vector<int>arr,int n,int sum)
{
	int table[n+1][sum];
	for(int i =0;i<=n;i++)
	for(int j =0;j<sum;j++)
	table[i][j] = 0;
	for(int i =0;i<n+1;i++)
	table[i][0] = 1;
	for(int i =1;i<=n;i++)
	{
		for(int j =0;j<sum;j++)
		{
			table[i][j] = table[i-1][j];
			if(j>=arr[i-1] && table[i-1][j-arr[i-1]] ==1)
			table[i][j] =1;
		}
	}
	//cout<<sum<<endl;
	for(int j = sum-1;j>=0;j--)
	{
		if(table[n][j] == 1)
		{
		//cout<<j<<endl;
		return j;
		}
	}
}

int main()
{
	int n =0;
	cin>>n;
	vector<int>arr;
	int sum =0;
	for(int i =0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		sum +=(x*y);
		for(int j =0;j<x;j++)
		arr.PB(y);
	}
	sort(arr.begin(),arr.end());
	int y =subset_sum(arr,arr.size(),(sum/2)+1);
	cout<<sum - y-y<<endl;;
	return 0;
}