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
#define MOD 1000000007
#define ll long long 
using namespace std;
int main()
{
	int u =0;
		cin>>u;
	while(u>0)
	{
		
		ll ans = 0;
		ans +=(u*5);
		if(u>1)
		{
		int c = 2;
		int x = 2;
		for(int i =2 ;i<u;i++)
		{
			x+=3;
			c+=x;
		}
		ans+=c;
	}
		cout<<ans<<endl;
		cin>>u;
	}
}