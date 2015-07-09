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
int solve(string a,string b)
{
	int m = a.size();
	int n = b.size();
	//cout<<a<<b<<endl;cout<<m<<n<<endl;
	int table[m+2][n+2];
	for(int i =0;i<=m+1;i++)
		for(int j =0;j<=n+1;j++)
		{
			table[i][j] = 0;
		}
		table[0][0] = INF;
	for(int i =0;i<=m;i++)
		{table[i+1][0] = INF;table[i+1][1] =i;}
	for(int j =0;j<=n;j++)
		{table[0][j+1] = j;table[1][j+1] = j;}
	int D['z'+1];
	for(int i =0;i<='z';i++)
		D[i] = 0;
	//cout<<a<<b<<endl;cout<<m<<n<<endl;
	for(int i =1;i<=m;i++)
	{
		int x =0;
		for(int j =1;j<=n;j++)
		{
			int p = D[b[j-1]];
			int q =x;

			int c = 1;
			if(a[i-1] == b[j-1])
				{c =0;x =j;}
			table[i+1][j+1] = min(table[i][j]+c,min(table[i][j+1]+1,table[i+1][j]+1));
			
			table[i+1][j+1] = min(table[i+1][j+1],table[p][q]+i-1-p+j-1-q+1);
		}
		D[a[i-1]] = i;
	}
	return table[m+1][n+1];
}
int main()
{
	string a,b;
	cin>>a>>b;
	while(a!="*" && b!="*")
	{
		cout<<solve(a,b)<<endl;
		cin>>a>>b;
	}
	return 0;
}