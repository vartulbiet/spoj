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
int n,k;
int s,d;
ull ans =0;
ull table[55][55];
ull recurse(int p,int pos)
{
	if(p ==0 && pos == d)
	{
		return 1;
	}
	if(p<=0)
	return 0;
	ull a,b;
	if(pos-1 !=0)
	{
		if(table[p-1][pos-1] ==-1)
			table[p-1][pos-1] = recurse(p-1,(pos-1));
		a = table[p-1][pos-1];
	}
	else
	{
		if(table[p-1][n] ==-1)
			table[p-1][n] = recurse(p-1,n);
		a = table[p-1][n];
	}
	if(pos+1>n)
	{
		if(table[p-1][1] ==-1)
			table[p-1][1] = recurse(p-1,1);
		b = table[p-1][1];
	}
	else
	{
		if(table[p-1][pos+1] ==-1)
			table[p-1][pos+1] = recurse(p-1,pos+1);
		b = table[p-1][pos+1];
	}
	return a+b;
}
int main()
{
	cin>>n>>k;
	while(n!=-1 ||k!=-1)
	{
		ans =0;
		cin>>s>>d;
		for(int i =0;i<55;i++)
		for(int j =0;j<55;j++)
		table[i][j] =-1;
		ans = recurse(k,s);
		cout<<ans<<endl;
		cin>>n>>k;
	}
	return 0;
}