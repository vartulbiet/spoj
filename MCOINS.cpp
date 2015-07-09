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
int k,l,m;
bool recurse(int val, bool player)
{
	if(val  == 0)
	{
		return !player;
	}
	if(val == 1 || val == k || val == l)
	{
		return player;
	}
	return recurse(val-1,!player) || recurse(val-k,!player) || recurse(val-l,!player);
}
int main()
{
	cin>>k>>l>>m;
	for(int i =0;i<m;i++)
	{
		int x =0;
		cin>>x;
		bool bt = recurse(x,true);
		if(bt == true)
			cout<<'A';
		else
			cout<<'B';
	}
	cout<<endl;
	return 0;
}